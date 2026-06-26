module.exports = grammar({
  name: 'virdant',

  extras: $ => [
    /\s/,
    $.doc_comment,
    $.doc_bang,
    $.line_comment,
  ],

  word: $ => $.ident,

  conflicts: $ => [
    [$.expr, $.path],
    [$.expr, $.type],
    [$.ofness, $.path],
    [$.expr, $.pat],
    [$.assign, $.expr],
    [$.call_expr, $.expr_atom],
    [$.ctor_call_expr, $.expr_atom],
    [$.pat, $.path],
    [$.expr_atom, $.pat],
    [$.expr, $.pat],
    [$.type],
    [$.ctor_call_expr, $.pat],
  ],

  rules: {
    // Package = DocBang? PackageStmt*
    // PackageStmt = PackageImport | Item
    // (error productions skipped)
    package: $ => repeat(choice(
      $.import,
      $.moddef,
      $.structdef,
      $.uniondef,
      $.enumdef,
      $.builtindef,
      $.socketdef,
    )),

    // ---- Annotations ----
    // Annotation = "@" Ident "(" Nat ")" | "@" Ident "(" Str ")" | "@" Ident
    annotation: $ => choice(
      seq(
        '@',
        field('name', $.ident),
        '(',
        field('value', $.nat),
        ')',
      ),
      seq(
        '@',
        field('name', $.ident),
        '(',
        field('value', $.str),
        ')',
      ),
      seq(
        '@',
        field('name', $.ident),
      ),
    ),

    // ---- Comments (extras) ----
    // Logos skips //[^\n]*, but //> and //! are separate tokens.
    // line_comment regex excludes //> and //! to avoid overlap.
    doc_comment: $ => /\/\/>[^\n]*/,
    doc_bang: $ => /\/\/![^\n]*/,
    line_comment: $ => /\/\/([^>!\n][^\n]*)?/,

    // ---- Literals ----

    ident: $ => /[_a-zA-Z][_a-zA-Z0-9]*/,

    nat: $ => choice(
      /[0-9](_?[0-9])*/,
      /0b[0-1](_?[0-1])*/,
      /0x[0-9a-fA-F](_?[0-9a-fA-F])*/,
    ),

    word: $ => choice(
      /[0-9](_?[0-9])*w[0-9]+/,
      /0b[0-1](_?[0-1])*w[0-9]+/,
      /0x[0-9a-fA-F](_?[0-9a-fA-F])*w[0-9]+/,
    ),

    str: $ => /"([^"\\]|\\t|\\n|\\r|\\0)*"/,

    // ---- Import ----
    // PackageImport = "import" Ident

    import: $ => seq(
      'import',
      field('name', $.ident),
    ),

    // ---- Module definition ----
    // ModDef = DocString? Annotations "ext"? "export"? "mod" Ident "{" ModDefStmt* "}"

    moddef: $ => seq(
      repeat($.annotation),
      optional('ext'),
      optional('export'),
      'mod',
      field('name', $.ident),
      '{',
      repeat(choice(
        $.component_incoming,
        $.component_outgoing,
        $.component_local,
        $.driver,
        $.latched_driver,
        $.bidirectional_driver,
        $.mod_instance,
        $.socket_instance,
        $.when_block,
        $.match_block,
        $.unused_stmt,
      )),
      '}',
    ),

    // ---- Struct definition ----
    // StructDef = DocString? Annotations "struct" "type" Ident "{" StructDefStmt* "}"

    structdef: $ => seq(
      repeat($.annotation),
      'struct',
      'type',
      field('name', $.ident),
      '{',
      repeat($.structdef_stmt),
      '}',
    ),

    // StructDefStmt = DocString? Annotations Ident ":" Type
    structdef_stmt: $ => seq(
      repeat($.annotation),
      field('name', $.ident),
      ':',
      field('type', $.type),
    ),

    // ---- Union definition ----
    // UnionDef = DocString? Annotations "union" "type" Ident "{" UnionDefStmt* "}"

    uniondef: $ => seq(
      repeat($.annotation),
      'union',
      'type',
      field('name', $.ident),
      '{',
      repeat($.uniondef_stmt),
      '}',
    ),

    // UnionDefStmt = DocString? Annotations Ident ParamList?
    uniondef_stmt: $ => seq(
      repeat($.annotation),
      field('name', $.ident),
      optional($.param_list),
    ),

    // ---- Enum definition ----
    // EnumDef = DocString? Annotations "enum" "type" Ident "{" EnumDefStmt* "}"

    enumdef: $ => seq(
      repeat($.annotation),
      'enum',
      'type',
      field('name', $.ident),
      '{',
      repeat($.enumdef_stmt),
      '}',
    ),

    // EnumDefStmt = DocString? Annotations Ident "=" Expr
    enumdef_stmt: $ => seq(
      repeat($.annotation),
      field('name', $.ident),
      '=',
      field('value', $.expr),
    ),

    // ---- Builtin definition ----
    // BuiltinDef = DocString? Annotations "builtin" "type" Ident Generics? "{" "}"

    builtindef: $ => seq(
      repeat($.annotation),
      'builtin',
      'type',
      field('name', $.ident),
      optional($.generics),
      '{',
      '}',
    ),

    // ---- Socket definition ----
    // SocketDef = DocString? Annotations "socket" Ident "{" SocketDefStmt* "}"

    socketdef: $ => seq(
      repeat($.annotation),
      'socket',
      field('name', $.ident),
      '{',
      repeat($.socketdef_stmt),
      '}',
    ),

    // SocketDefStmt = DocString? Annotations ("cosi"|"soci") Ident ":" Type
    socketdef_stmt: $ => seq(
      repeat($.annotation),
      choice('cosi', 'soci'),
      field('name', $.ident),
      ':',
      field('type', $.type),
    ),

    // ---- Param list ----
    // ParamList = "(" Params? ")"
    // Params = Param ("," Param)*
    // (no trailing comma)

    param_list: $ => seq(
      '(',
      optional(seq(
        $.param,
        repeat(seq(',', $.param)),
      )),
      ')',
    ),

    // Param = DocString? Annotations Ident ":" Type
    param: $ => seq(
      repeat($.annotation),
      field('name', $.ident),
      ':',
      field('type', $.type),
    ),

    // ---- Generics ----
    // Generics = "[" Ident ":" Kind "]"
    // GenericsParams = "[" Nat "]" | "[" Type "]"

    generics: $ => seq(
      '[',
      field('name', $.ident),
      ':',
      field('kind', $.kind),
      ']',
    ),

    kind: $ => field('name', $.ident),

    generics_params: $ => choice(
      seq('[', field('value', $.nat), ']'),
      seq('[', field('type', $.type), ']'),
    ),

    // ---- Type ----
    // Type = Ofness GenericsParams?

    type: $ => seq(
      field('name', $.ofness),
      optional(field('generics', $.generics_params)),
    ),

    // ---- Ofness ----
    // Ofness = Ident | Ident "::" Ident

    ofness: $ => choice(
      field('name', $.ident),
      seq(
        field('package', $.ident),
        '::',
        field('name', $.ident),
      ),
    ),

    // ---- Components ----
    // ModDefStmtComponent has 6 variants:
    //   "incoming" Ident ":" Type OnClause? ItBlock?
    //   "outgoing" Ident ":" Type OnClause? ItBlock?
    //   "outgoing" "wire" Ident ":" Type OnClause? ItBlock?
    //   "outgoing" "reg" Ident ":" Type OnClause? ItBlock?
    //   "wire" Ident ":" Type OnClause? ItBlock?
    //   "reg" Ident ":" Type OnClause? ItBlock?

    component_incoming: $ => seq(
      repeat($.annotation),
      'incoming',
      field('name', $.ident),
      ':',
      field('type', $.type),
      optional(seq('on', field('clock', $.expr))),
      optional(field('body', $.block)),
    ),

    component_outgoing: $ => seq(
      repeat($.annotation),
      'outgoing',
      optional(choice('wire', 'reg')),
      field('name', $.ident),
      ':',
      field('type', $.type),
      optional(seq('on', field('clock', $.expr))),
      optional(field('body', $.block)),
    ),

    component_local: $ => choice(
      seq(
        repeat($.annotation),
        'wire',
        field('name', $.ident),
        ':',
        field('type', $.type),
        optional(seq('on', field('clock', $.expr))),
        optional(field('body', $.block)),
      ),
      seq(
        repeat($.annotation),
        'reg',
        field('name', $.ident),
        ':',
        field('type', $.type),
        optional(seq('on', field('clock', $.expr))),
        optional(field('body', $.block)),
      ),
    ),

    // ---- Drivers ----
    // ModDefStmtDriver:
    //   Path ":=" Expr  (continuous)
    //   Path "<=" Expr  (latched)
    //   Path ":=:" Path (bidirectional)

    driver: $ => seq(
      field('target', $.path),
      ':=',
      field('value', $.expr),
    ),

    latched_driver: $ => seq(
      field('target', $.path),
      '<=',
      field('value', $.expr),
    ),

    bidirectional_driver: $ => seq(
      field('left', $.path),
      ':=:',
      field('right', $.path),
    ),

    // ---- Module instance ----
    // ModDefStmtInstance = DocString? Annotations "mod" Ident "of" Ofness ItBlock?

    mod_instance: $ => seq(
      repeat($.annotation),
      'mod',
      field('name', $.ident),
      'of',
      field('module', $.ofness),
      optional(field('body', $.block)),
    ),

    // ---- Socket instance ----
    // ModDefStmtSocket = DocString? Annotations ("client"|"server") "socket" Ident "of" Ofness ItBlock?

    socket_instance: $ => seq(
      repeat($.annotation),
      choice('client', 'server'),
      'socket',
      field('name', $.ident),
      'of',
      field('socket', $.ofness),
      optional(field('body', $.block)),
    ),

    // ---- When (statement and expression) ----
    // ModDefStmtWhen = "when" "{" ModDefStmtWhenArm* "}"
    // ExprWhen = "when" "{" ExprWhenArm* "}"
    // (structurally identical, merged into when_block)

    when_block: $ => seq(
      'when',
      '{',
      repeat(choice(
        $.case_arm,
        $.else_arm,
      )),
      '}',
    ),

    // ---- Match (statement and expression) ----
    // ModDefStmtMatch = "match" Expr "{" ModDefStmtMatchArm* "}"
    // ExprMatch = "match" Expr "{" ExprMatchArm* "}"
    // (structurally identical, merged into match_block)

    match_block: $ => seq(
      'match',
      field('value', $.expr),
      '{',
      repeat(choice(
        $.case_arm,
        $.else_arm,
      )),
      '}',
    ),

    // When arms use Expr after "case".
    // Match arms use Pat after "case".
    // Both use the same body alternatives.
    // case_arm = "case" (Expr|Pat) body
    // else_arm = "else" body
    // body = "=>" Expr | ModDefStmtBlock | When | Match

    case_arm: $ => seq(
      'case',
      field('condition', choice($.expr, $.pat)),
      choice(
        seq('=>', field('value', $.expr)),
        field('value', $.block),
        field('value', $.when_block),
        field('value', $.match_block),
      ),
    ),

    else_arm: $ => seq(
      'else',
      choice(
        seq('=>', field('value', $.expr)),
        field('value', $.block),
        field('value', $.when_block),
        field('value', $.match_block),
      ),
    ),

    // ---- Unused ----
    // ModDefStmtUnused = "unused" Path

    unused_stmt: $ => seq(
      'unused',
      field('path', $.path),
    ),

    // ---- Block ----
    // ModDefStmtBlock = "{" ModDefStmt* "}"
    // ItBlock = ModDefStmtBlock

    block: $ => seq(
      '{',
      repeat(choice(
        $.component_incoming,
        $.component_outgoing,
        $.component_local,
        $.driver,
        $.latched_driver,
        $.bidirectional_driver,
        $.mod_instance,
        $.socket_instance,
        $.when_block,
        $.match_block,
        $.unused_stmt,
      )),
      '}',
    ),

    // ---- Expressions ----
    // Expr = ExprWhen | ExprMatch | ExprStruct | ExprBinOpLogical
    // ExprBinOpLogical -> ExprBinOpCompare -> ExprBinOpAdditive
    //   -> ExprUnOp -> ExprAscription -> ExprPrimary -> ExprAtom

    expr: $ => choice(
      $.when_block,
      $.match_block,
      $.struct_expr,
      $.binary_expr,
      $.unary_expr,
      $.ascription_expr,
      $.call_expr,
      $.field_expr,
      $.index_expr,
      $.index_range_expr,
      $.index_dyn_expr,
      $.ctor_call_expr,
      $.expr_atom,
    ),

    // Binary operators.
    // All logical ops at same precedence (left-assoc).
    // All comparison ops at same precedence (left-assoc).
    // All additive ops at same precedence (left-assoc).
    binary_expr: $ => choice(
      prec.left(1, seq(
        field('left', $.expr),
        field('op', choice('&&', '||', '^^')),
        field('right', $.expr),
      )),
      prec.left(2, seq(
        field('left', $.expr),
        field('op', choice('==', '!=', '<', '<=', '>', '>=')),
        field('right', $.expr),
      )),
      prec.left(3, seq(
        field('left', $.expr),
        field('op', choice('+', '-', '&', '|', '^')),
        field('right', $.expr),
      )),
    ),

    // ExprUnOp = UnOp ExprUnOp | ExprAscription
    // UnOp = "-" | "~" | "!"
    unary_expr: $ => prec.right(4, seq(
      field('op', choice('-', '~', '!')),
      field('operand', $.expr),
    )),

    // ExprAscription = ExprPrimary ":" Type | ExprPrimary
    ascription_expr: $ => prec.left(5, seq(
      field('value', $.expr),
      ':',
      field('type', $.type),
    )),

    // ExprPrimary:
    //   Ofness "(" ArgList ")"     (function call)
    //   ExprPrimary "->" Ident      (field access)
    //   ExprPrimary "[" "dyn" Expr "]"  (dynamic index)
    //   ExprPrimary "[" Index "]"   (static index)
    //   ExprPrimary "[" Index ".." Index "]"  (range index)
    //   "@" Ident "(" ArgList ")"   (ctor call with args)
    //   ExprAtom

    call_expr: $ => seq(
      field('func', $.ofness),
      '(',
      optional($.arg_list),
      ')',
    ),

    field_expr: $ => prec.left(6, seq(
      field('value', $.expr),
      '->',
      field('field', $.ident),
    )),

    index_expr: $ => prec.left(6, seq(
      field('value', $.expr),
      '[',
      field('index', $.nat),
      ']',
    )),

    index_range_expr: $ => prec.left(6, seq(
      field('value', $.expr),
      '[',
      field('high', $.nat),
      '..',
      field('low', $.nat),
      ']',
    )),

    index_dyn_expr: $ => prec.left(6, seq(
      field('value', $.expr),
      '[',
      'dyn',
      field('index', $.expr),
      ']',
    )),

    ctor_call_expr: $ => seq(
      '@',
      field('ctor', $.ident),
      '(',
      optional($.arg_list),
      ')',
    ),

    // ExprStruct = "$" "{" AssignList "}"
    struct_expr: $ => seq(
      '$',
      '{',
      optional($.assign_list),
      '}',
    ),

    // ExprAtom:
    //   Path | WordLit | BitLit | "Str" | "#" Ident
    //   "@" Ident | "?" | "dontcare" | "(" Expr ")"
    // WordLit = Nat | Word
    // BitLit = "true" | "false"
    expr_atom: $ => choice(
      field('reference', $.path),
      field('literal', $.word),
      field('literal', $.nat),
      field('literal', $.str),
      seq('#', field('enumerant', $.ident)),
      seq('@', field('ctor', $.ident)),
      '?',
      'dontcare',
      'true',
      'false',
      seq('(', field('value', $.expr), ')'),
    ),

    // ArgList = (Expr ",")+ Expr ","? | Expr ","? | empty
    arg_list: $ => seq(
      $.expr,
      repeat(seq(',', $.expr)),
      optional(','),
    ),

    // AssignList = (Assign ",")* Assign ","? | Expr ","? | empty
    assign_list: $ => seq(
      choice($.assign, $.expr),
      repeat(seq(',', choice($.assign, $.expr))),
      optional(','),
    ),

    // Assign = Ident "=" Expr
    assign: $ => seq(
      field('name', $.ident),
      '=',
      field('value', $.expr),
    ),

    // ---- Patterns ----
    // Pat = "#" Ident | "@" Ident | "@" Ident "(" PatList ")" | WordLit | BitLit | Ident | "dontcare"

    pat: $ => choice(
      seq('#', field('name', $.ident)),
      seq('@', field('name', $.ident), '(', optional($.pat_list), ')'),
      seq('@', field('name', $.ident)),
      field('literal', $.word),
      field('literal', $.nat),
      'true',
      'false',
      field('name', $.ident),
      'dontcare',
    ),

    // PatList = (Pat ",")+ Pat ","? | Pat ","? | empty
    pat_list: $ => seq(
      $.pat,
      repeat(seq(',', $.pat)),
      optional(','),
    ),

    // ---- Path ----
    // Path = Ident ("." Ident)* | "it" ("." Ident)*

    path: $ => choice(
      seq(
        field('name', $.ident),
        repeat(seq('.', field('name', $.ident))),
      ),
      seq(
        'it',
        repeat(seq('.', field('name', $.ident))),
      ),
    ),
  },
});
