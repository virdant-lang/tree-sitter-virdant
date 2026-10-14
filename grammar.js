/**
 * @file Tree-sitter grammar for Virdant.
 *
 * Mirrors the LALRPOP grammar in `virdant/src/syntax/virdant.lalrpop`
 * (summarized in `GRAMMAR.txt`) and the Logos lexer in
 * `virdant/src/syntax/token.rs`.  Each rule is annotated with the
 * production(s) it corresponds to.
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

const PREC = {
  logical: 1,  // ExprBinOpLogical
  compare: 2,  // ExprBinOpCompare
  additive: 3, // ExprBinOpAdditive
};

/**
 * One or more `rule`s separated by commas (no trailing comma).
 *
 * @param {RuleOrLiteral} rule
 */
function sepBy1Comma(rule) {
  return seq(rule, repeat(seq(',', rule)));
}

/**
 * Zero or more `rule`s separated by commas, with an optional trailing comma.
 *
 * @param {RuleOrLiteral} rule
 */
function commaSepTrailing(rule) {
  return optional(seq(sepBy1Comma(rule), optional(',')));
}

/**
 * One or more `rule`s separated by commas, with an optional trailing comma.
 *
 * @param {RuleOrLiteral} rule
 */
function commaSep1Trailing(rule) {
  return seq(sepBy1Comma(rule), optional(','));
}

/**
 * `DocString? Annotations ...rest`
 *
 * @param {GrammarSymbols<string>} $
 * @param {RuleOrLiteral[]} rest
 */
function decorated($, ...rest) {
  return seq(
    optional(field('doc', $.doc_string)),
    repeat(field('annotation', $.annotation)),
    ...rest,
  );
}

/**
 * Arm bodies, shared by all four of `ModDefStmtWhenArm`,
 * `ModDefStmtMatchArm`, `ExprWhenArm`, and `ExprMatchArm`:
 *
 *     "=>" Expr | ModDefStmtBlock | <nested when> | <nested match>
 *
 * @param {GrammarSymbols<string>} $
 * @param {RuleOrLiteral} nestedWhen
 * @param {RuleOrLiteral} nestedMatch
 */
function armBody($, nestedWhen, nestedMatch) {
  return choice(
    seq('=>', field('value', $._expression)),
    field('body', choice($.block, nestedWhen, nestedMatch)),
  );
}

module.exports = grammar({
  name: 'virdant',

  // Logos skips `[ \n]+` and `//[^\n]*`.  We are slightly more lenient with
  // whitespace (tabs, CR) so that editors don't light up in red.
  extras: $ => [
    /\s/,
    $.comment,
  ],

  word: $ => $.identifier,

  supertypes: $ => [
    $._item,
    $._mod_stmt,
    $._expression,
    $._pattern,
  ],

  rules: {
    // =======================================================================
    // Package
    // =======================================================================

    // Package := DocBang? PackageStmt*
    // PackageStmt := PackageImport | Item
    source_file: $ => seq(
      optional(field('doc', $.package_doc)),
      repeat(choice($.import, $._item)),
    ),

    // DocBang := ("DocBang")+
    package_doc: $ => repeat1($.doc_bang),

    // PackageImport := "import" Ident
    import: $ => seq(
      'import',
      field('package', $.identifier),
    ),

    // DocString := ("DocComment")+
    doc_string: $ => repeat1($.doc_comment),

    // Annotation := "@" Ident "(" ArgList? ")" | "@" Ident
    annotation: $ => seq(
      '@',
      field('name', $.identifier),
      optional(field('arguments', $.arguments)),
    ),

    // =======================================================================
    // Items
    // =======================================================================

    // Item := ModDef | StructDef | UnionDef | EnumDef | BuiltinDef
    //       | SocketDef | PlatformDef
    _item: $ => choice(
      $.mod_def,
      $.struct_def,
      $.union_def,
      $.enum_def,
      $.builtin_def,
      $.socket_def,
      $.platform_def,
    ),

    // ModDef := DocString? Annotations "ext"? "export"? "mod" Ident
    //           ForClause? "{" ModDefStmt* "}"
    mod_def: $ => decorated($,
      optional(field('ext', 'ext')),
      optional(field('export', 'export')),
      'mod',
      field('name', $.identifier),
      optional(field('for', $.for_clause)),
      '{',
      repeat($._mod_stmt),
      '}',
    ),

    // ForClause := "for" Ofness
    for_clause: $ => seq(
      'for',
      field('platform', $.ofness),
    ),

    // StructDef := DocString? Annotations "struct" "type" Ident
    //              "{" StructDefStmt* "}"
    struct_def: $ => decorated($,
      'struct',
      'type',
      field('name', $.identifier),
      '{',
      repeat($.field_def),
      '}',
    ),

    // StructDefStmt := DocString? Annotations Ident ":" Type
    field_def: $ => decorated($,
      field('name', $.identifier),
      ':',
      field('type', $.type),
    ),

    // UnionDef := DocString? Annotations "union" "type" Ident
    //             "{" UnionDefStmt* "}"
    union_def: $ => decorated($,
      'union',
      'type',
      field('name', $.identifier),
      '{',
      repeat($.ctor_def),
      '}',
    ),

    // UnionDefStmt := DocString? Annotations Ident ParamList?
    ctor_def: $ => decorated($,
      field('name', $.identifier),
      optional(field('parameters', $.param_list)),
    ),

    // ParamList := "(" Params? ")"
    // Params := Param | Params "," Param
    param_list: $ => seq(
      '(',
      optional(sepBy1Comma($.param)),
      ')',
    ),

    // Param := DocString? Annotations Ident ":" Type
    param: $ => decorated($,
      field('name', $.identifier),
      ':',
      field('type', $.type),
    ),

    // EnumDef := DocString? Annotations "enum" "type" Ident
    //            "{" EnumDefStmt* "}"
    enum_def: $ => decorated($,
      'enum',
      'type',
      field('name', $.identifier),
      '{',
      repeat($.enumerant_def),
      '}',
    ),

    // EnumDefStmt := DocString? Annotations Ident "=" Expr
    enumerant_def: $ => decorated($,
      field('name', $.identifier),
      '=',
      field('value', $._expression),
    ),

    // BuiltinDef := DocString? Annotations "builtin" "type" Ident Generics?
    //               "{" "}"
    builtin_def: $ => decorated($,
      'builtin',
      'type',
      field('name', $.identifier),
      optional(field('generics', $.generics)),
      '{',
      '}',
    ),

    // Generics := "[" Ident ":" Kind "]"
    generics: $ => seq(
      '[',
      field('name', $.identifier),
      ':',
      field('kind', $.kind),
      ']',
    ),

    // Kind := Ident
    kind: $ => field('name', $.identifier),

    // SocketDef := DocString? Annotations "socket" Ident "{" SocketDefStmt* "}"
    socket_def: $ => decorated($,
      'socket',
      field('name', $.identifier),
      '{',
      repeat($.channel_def),
      '}',
    ),

    // SocketDefStmt := DocString? Annotations "cosi" Ident ":" Type
    //                | DocString? Annotations "soci" Ident ":" Type
    channel_def: $ => decorated($,
      field('direction', choice('cosi', 'soci')),
      field('name', $.identifier),
      ':',
      field('type', $.type),
    ),

    // PlatformDef := DocString? Annotations "platform" Ident
    //                "{" PlatformStmt* "}"
    // PlatformStmt := ModDefStmtComponent
    platform_def: $ => decorated($,
      'platform',
      field('name', $.identifier),
      '{',
      repeat($.component),
      '}',
    ),

    // =======================================================================
    // Module statements
    // =======================================================================

    // ModDefStmt := ModDefStmtComponent | ModDefStmtDriver
    //             | ModDefStmtInstance | ModDefStmtSocket | ModDefStmtWhen
    //             | ModDefStmtMatch | ModDefStmtUnused | ModDefStmtDependsOn
    _mod_stmt: $ => choice(
      $.component,
      $.driver,
      $.bidirectional_driver,
      $.mod_instance,
      $.socket_instance,
      $.when_statement,
      $.match_statement,
      $.unused_statement,
      $.dependson_statement,
    ),

    // ModDefStmtComponent :=
    //     DocString? Annotations "incoming"       Ident ":" Type OnClause? ItBlock?
    //   | DocString? Annotations "outgoing"       Ident ":" Type OnClause? ItBlock?
    //   | DocString? Annotations "outgoing" "wire" Ident ":" Type OnClause? ItBlock?
    //   | DocString? Annotations "outgoing" "reg"  Ident ":" Type OnClause? ItBlock?
    //   | DocString? Annotations "wire"           Ident ":" Type OnClause? ItBlock?
    //   | DocString? Annotations "reg"            Ident ":" Type OnClause? ItBlock?
    component: $ => decorated($,
      choice(
        'incoming',
        seq('outgoing', optional(choice('wire', 'reg'))),
        'wire',
        'reg',
      ),
      field('name', $.identifier),
      ':',
      field('type', $.type),
      optional(field('on', $.on_clause)),
      optional(field('body', $.block)),
    ),

    // OnClause := "on" Expr
    on_clause: $ => seq(
      'on',
      field('clock', $._expression),
    ),

    // ModDefStmtDriver := Path ":=" Expr | Path "<=" Expr
    driver: $ => seq(
      field('target', $.path),
      field('operator', choice(':=', '<=')),
      field('value', $._expression),
    ),

    // ModDefStmtDriver := Path ":=:" Path
    bidirectional_driver: $ => seq(
      field('left', $.path),
      ':=:',
      field('right', $.path),
    ),

    // ModDefStmtInstance := DocString? Annotations "mod" Ident "of" Ofness
    //                       ItBlock?
    mod_instance: $ => decorated($,
      'mod',
      field('name', $.identifier),
      'of',
      field('module', $.ofness),
      optional(field('body', $.block)),
    ),

    // ModDefStmtSocket :=
    //     DocString? Annotations "client" "socket" Ident "of" Ofness ItBlock?
    //   | DocString? Annotations "server" "socket" Ident "of" Ofness ItBlock?
    socket_instance: $ => decorated($,
      field('role', choice('client', 'server')),
      'socket',
      field('name', $.identifier),
      'of',
      field('socket', $.ofness),
      optional(field('body', $.block)),
    ),

    // ModDefStmtWhen := "when" "{" ModDefStmtWhenArm* "}"
    when_statement: $ => seq(
      'when',
      '{',
      repeat(alias($._when_statement_arm, $.when_arm)),
      '}',
    ),

    // ModDefStmtWhenArm :=
    //     "case" Expr ("=>" Expr | ModDefStmtBlock | ModDefStmtWhen | ModDefStmtMatch)
    //   | "else"      ("=>" Expr | ModDefStmtBlock | ModDefStmtWhen | ModDefStmtMatch)
    _when_statement_arm: $ => seq(
      choice(seq('case', field('condition', $._expression)), 'else'),
      armBody($, $.when_statement, $.match_statement),
    ),

    // ModDefStmtMatch := "match" Expr "{" ModDefStmtMatchArm* "}"
    match_statement: $ => seq(
      'match',
      field('subject', $._expression),
      '{',
      repeat(alias($._match_statement_arm, $.match_arm)),
      '}',
    ),

    // ModDefStmtMatchArm :=
    //     "case" Pat ("=>" Expr | ModDefStmtBlock | ModDefStmtWhen | ModDefStmtMatch)
    //   | "else"     ("=>" Expr | ModDefStmtBlock | ModDefStmtWhen | ModDefStmtMatch)
    _match_statement_arm: $ => seq(
      choice(seq('case', field('pattern', $._pattern)), 'else'),
      armBody($, $.when_statement, $.match_statement),
    ),

    // ModDefStmtUnused := "unused" Path
    unused_statement: $ => seq(
      'unused',
      field('path', $.path),
    ),

    // ModDefStmtDependsOn := Path "dependson" Path
    dependson_statement: $ => seq(
      field('left', $.path),
      'dependson',
      field('right', $.path),
    ),

    // ModDefStmtBlock := "{" ModDefStmt* "}"
    // ItBlock := ModDefStmtBlock
    block: $ => seq(
      '{',
      repeat($._mod_stmt),
      '}',
    ),

    // =======================================================================
    // Types
    // =======================================================================

    // Type := Ofness GenericsParams?
    type: $ => seq(
      field('name', $.ofness),
      optional(field('arguments', $.generic_args)),
    ),

    // GenericsParams := "[" Nat "]" | "[" Type "]"
    generic_args: $ => seq(
      '[',
      field('argument', choice($.nat_literal, $.type)),
      ']',
    ),

    // Ofness := Ident | Ident "::" Ident
    ofness: $ => choice(
      field('name', $.identifier),
      seq(
        field('package', $.identifier),
        '::',
        field('name', $.identifier),
      ),
    ),

    // =======================================================================
    // Expressions
    // =======================================================================

    // Expr := ExprWhen | ExprMatch | ExprStruct | ExprBinOpLogical
    _expression: $ => choice(
      $.when_expression,
      $.match_expression,
      $.struct_expression,
      $._operand,
    ),

    // ExprBinOpLogical / ExprBinOpCompare / ExprBinOpAdditive / ExprUnOp
    //
    // Note: `when`, `match`, and `${ ... }` can not appear as an operand
    // without parentheses.
    _operand: $ => choice(
      $.binary_expression,
      $._unary_operand,
    ),

    // ExprUnOp := UnOp ExprUnOp | ExprAscription
    _unary_operand: $ => choice(
      $.unary_expression,
      $.ascription_expression,
      $._primary_expression,
    ),

    // ExprBinOpLogical  := ExprBinOpLogical  BinOpLogical  ExprBinOpCompare
    // ExprBinOpCompare  := ExprBinOpCompare  BinOpCompare  ExprBinOpAdditive
    // ExprBinOpAdditive := ExprBinOpAdditive BinOpAdditive ExprUnOp
    binary_expression: $ => {
      const table = [
        [PREC.logical, choice('&&', '||', '^^')],
        [PREC.compare, choice('<', '<=', '>', '>=', '==', '!=')],
        [PREC.additive, choice('+', '-', '&', '|', '^')],
      ];
      return choice(...table.map(([precedence, operator]) =>
        prec.left(/** @type {number} */ (precedence), seq(
          field('left', $._operand),
          field('operator', /** @type {Rule} */ (operator)),
          field('right', $._operand),
        )),
      ));
    },

    // ExprUnOp := UnOp ExprUnOp
    // UnOp := "-" | "~" | "!"
    unary_expression: $ => seq(
      field('operator', choice('-', '~', '!')),
      field('operand', $._unary_operand),
    ),

    // ExprAscription := ExprPrimary ":" Type
    ascription_expression: $ => seq(
      field('value', $._primary_expression),
      ':',
      field('type', $.type),
    ),

    // ExprPrimary := Ofness "(" ArgList? ")"
    //              | ExprPrimary "->" Ident
    //              | ExprPrimary "[" "dyn" Expr "]"
    //              | ExprPrimary "[" Index "]"
    //              | ExprPrimary "[" Index ".." Index "]"
    //              | "@" Ident "(" ArgList? ")"
    //              | ExprAtom
    _primary_expression: $ => choice(
      $.call_expression,
      $.field_expression,
      $.dyn_index_expression,
      $.index_expression,
      $.slice_expression,
      $.ctor_expression,
      $._atom,
    ),

    // ExprPrimary := Ofness "(" ArgList? ")"
    call_expression: $ => seq(
      field('function', $.ofness),
      field('arguments', $.arguments),
    ),

    // ExprPrimary := ExprPrimary "->" Ident
    field_expression: $ => seq(
      field('value', $._primary_expression),
      '->',
      field('field', $.identifier),
    ),

    // ExprPrimary := ExprPrimary "[" "dyn" Expr "]"
    dyn_index_expression: $ => seq(
      field('value', $._primary_expression),
      '[',
      'dyn',
      field('index', $._expression),
      ']',
    ),

    // ExprPrimary := ExprPrimary "[" Index "]"
    // Index := "Nat"
    index_expression: $ => seq(
      field('value', $._primary_expression),
      '[',
      field('index', $.nat_literal),
      ']',
    ),

    // ExprPrimary := ExprPrimary "[" Index ".." Index "]"
    slice_expression: $ => seq(
      field('value', $._primary_expression),
      '[',
      field('high', $.nat_literal),
      '..',
      field('low', $.nat_literal),
      ']',
    ),

    // ExprPrimary := "@" Ident "(" ArgList? ")"
    // ExprAtom    := "@" Ident
    ctor_expression: $ => seq(
      '@',
      field('name', $.identifier),
      optional(field('arguments', $.arguments)),
    ),

    // "(" ArgList? ")"
    // ArgList := (Expr ",")+ Expr ","? | Expr ","?
    arguments: $ => seq(
      '(',
      commaSepTrailing($._expression),
      ')',
    ),

    // ExprAtom := Path | WordLit | BitLit | "Str" | "#" Ident | "@" Ident
    //           | "?" | "dontcare" | "(" Expr ")"
    _atom: $ => choice(
      $.path,
      $.nat_literal,
      $.word_literal,
      $.bit_literal,
      $.string_literal,
      $.enumerant_expression,
      $.hole,
      $.dontcare,
      $.parenthesized_expression,
    ),

    // ExprAtom := "#" Ident
    enumerant_expression: $ => seq(
      '#',
      field('name', $.identifier),
    ),

    // ExprAtom := "?"
    hole: _ => '?',

    // ExprAtom := "dontcare"
    // Pat      := "dontcare"
    dontcare: _ => 'dontcare',

    // ExprAtom := "(" Expr ")"
    parenthesized_expression: $ => seq(
      '(',
      field('expression', $._expression),
      ')',
    ),

    // ExprStruct := "$" "{" AssignList "}"
    // AssignList := (Assign ",")* Assign ","? | Expr ","? | <empty>
    struct_expression: $ => seq(
      '$',
      '{',
      optional(choice(
        commaSep1Trailing($.assign),
        seq(field('value', $._expression), optional(',')),
      )),
      '}',
    ),

    // Assign := Ident "=" Expr
    assign: $ => seq(
      field('name', $.identifier),
      '=',
      field('value', $._expression),
    ),

    // ExprWhen := "when" "{" ExprWhenArm* "}"
    when_expression: $ => seq(
      'when',
      '{',
      repeat(alias($._when_expression_arm, $.when_arm)),
      '}',
    ),

    // ExprWhenArm :=
    //     "case" Expr ("=>" Expr | ModDefStmtBlock | ExprWhen | ExprMatch)
    //   | "else"      ("=>" Expr | ModDefStmtBlock | ExprWhen | ExprMatch)
    _when_expression_arm: $ => seq(
      choice(seq('case', field('condition', $._expression)), 'else'),
      armBody($, $.when_expression, $.match_expression),
    ),

    // ExprMatch := "match" Expr "{" ExprMatchArm* "}"
    match_expression: $ => seq(
      'match',
      field('subject', $._expression),
      '{',
      repeat(alias($._match_expression_arm, $.match_arm)),
      '}',
    ),

    // ExprMatchArm :=
    //     "case" Pat ("=>" Expr | ModDefStmtBlock | ExprWhen | ExprMatch)
    //   | "else"     ("=>" Expr | ModDefStmtBlock | ExprWhen | ExprMatch)
    _match_expression_arm: $ => seq(
      choice(seq('case', field('pattern', $._pattern)), 'else'),
      armBody($, $.when_expression, $.match_expression),
    ),

    // Path := Ident ("." Ident)* | "it" ("." Ident)*
    path: $ => seq(
      choice($.identifier, $.it),
      repeat(seq('.', $.identifier)),
    ),

    it: _ => 'it',

    // =======================================================================
    // Patterns
    // =======================================================================

    // Pat := "#" Ident | "@" Ident | "@" Ident "(" PatList ")" | WordLit
    //      | BitLit | Ident | "dontcare"
    _pattern: $ => choice(
      $.enumerant_pattern,
      $.ctor_pattern,
      $.nat_literal,
      $.word_literal,
      $.bit_literal,
      $.binding_pattern,
      $.dontcare,
    ),

    // Pat := "#" Ident
    enumerant_pattern: $ => seq(
      '#',
      field('name', $.identifier),
    ),

    // Pat := "@" Ident | "@" Ident "(" PatList ")"
    ctor_pattern: $ => seq(
      '@',
      field('name', $.identifier),
      optional(field('arguments', $.pattern_list)),
    ),

    // "(" PatList ")"
    // PatList := (Pat ",")+ Pat ","? | Pat ","? | <empty>
    pattern_list: $ => seq(
      '(',
      commaSepTrailing($._pattern),
      ')',
    ),

    // Pat := Ident
    binding_pattern: $ => field('name', $.identifier),

    // =======================================================================
    // Literals & tokens
    // =======================================================================

    // BitLit := "true" | "false"
    bit_literal: _ => choice('true', 'false'),

    // "Nat": decimal, binary, or hex.  Single underscores may separate digits.
    nat_literal: _ => token(choice(
      /[0-9](_?[0-9])*/,
      /0b[01](_?[01])*/,
      /0x[0-9a-fA-F](_?[0-9a-fA-F])*/,
    )),

    // "Word": a Nat with a `w<width>` suffix (no underscores in the width).
    word_literal: _ => token(choice(
      /[0-9](_?[0-9])*w[0-9]+/,
      /0b[01](_?[01])*w[0-9]+/,
      /0x[0-9a-fA-F](_?[0-9a-fA-F])*w[0-9]+/,
    )),

    // "Str" := "([^"\\]|\\t|\\n|\\r|\\0)*"
    string_literal: $ => seq(
      '"',
      repeat(choice(
        $.string_content,
        $.escape_sequence,
      )),
      token.immediate('"'),
    ),

    string_content: _ => token.immediate(prec(1, /[^"\\]+/)),

    escape_sequence: _ => token.immediate(/\\[tnr0]/),

    // "Ident"
    identifier: _ => /[_a-zA-Z][_a-zA-Z0-9]*/,

    // "DocComment"
    doc_comment: _ => token(prec(1, /\/\/>[^\n]*/)),

    // "DocBang"
    doc_bang: _ => token(prec(1, /\/\/![^\n]*/)),

    // Skipped by the lexer: `//[^\n]*`.
    //
    // Doc comments (`//>`, `//!`) in positions where the compiler does not
    // accept them fall back to being ordinary comments here.
    comment: _ => token(/\/\/[^\n]*/),
  },
});
