/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: "virdant",

  extras: ($) => [/\s+/, $.line_comment],

  word: ($) => $.ident,

  rules: {
    // ----- Top-level -----
    source_file: ($) =>
      seq(
        optional($.doc_bang),
        repeat(choice($.import, $.item)),
      ),

    line_comment: ($) => token(seq("//", /[^\n]*/)),

    doc_comment: ($) => token(seq("///>", /[^\n]*/)),

    doc_bang: ($) => token(seq("//!>", /[^\n]*/)),

    import: ($) =>
      seq("import", $.ident),

    // ----- Items -----
    item: ($) =>
      choice(
        $.moddef,
        $.structdef,
        $.uniondef,
        $.enumdef,
        $.builtindef,
        $.socketdef,
      ),

    // --- ModDef ---
    moddef: ($) =>
      seq(
        optional($.doc_string),
        optional("ext"),
        optional("export"),
        "mod",
        field("name", $.ident),
        "{",
        repeat($._mod_stmt),
        "}",
      ),

    // --- StructDef ---
    structdef: ($) =>
      seq(
        optional($.doc_string),
        "struct",
        "type",
        field("name", $.ident),
        "{",
        repeat($.structdef_stmt),
        "}",
      ),

    structdef_stmt: ($) =>
      seq(
        optional($.doc_string),
        field("name", $.ident),
        ":",
        $.type,
      ),

    // --- UnionDef ---
    uniondef: ($) =>
      seq(
        optional($.doc_string),
        "union",
        "type",
        field("name", $.ident),
        "{",
        repeat($.uniondef_stmt),
        "}",
      ),

    uniondef_stmt: ($) =>
      seq(
        optional($.doc_string),
        field("name", $.ident),
        optional($._param_list),
      ),

    _param_list: ($) =>
      seq("(", optional($.params), ")"),

    params: ($) =>
      seq($.param, repeat(seq(",", $.param))),

    param: ($) =>
      seq(
        optional($.doc_string),
        field("name", $.ident),
        ":",
        $.type,
      ),

    // --- EnumDef ---
    enumdef: ($) =>
      seq(
        optional($.doc_string),
        "enum",
        "type",
        field("name", $.ident),
        "width",
        $.width,
        "{",
        repeat($.enumdef_stmt),
        "}",
      ),

    enumdef_stmt: ($) =>
      seq(
        optional($.doc_string),
        field("name", $.ident),
        "=",
        $._expr,
      ),

    // --- BuiltinDef ---
    builtindef: ($) =>
      seq(
        optional($.doc_string),
        "builtin",
        "type",
        field("name", $.ident),
        optional($._generics),
        "{",
        "}",
      ),

    _generics: ($) =>
      seq("[", $.ident, ":", $.kind, "]"),

    kind: ($) => $.ident,

    // --- SocketDef ---
    socketdef: ($) =>
      seq(
        optional($.doc_string),
        "socket",
        field("name", $.ident),
        "{",
        repeat($.socketdef_stmt),
        "}",
      ),

    socketdef_stmt: ($) =>
      seq(
        optional($.doc_string),
        choice("cosi", "soci"),
        field("name", $.ident),
        ":",
        $.type,
      ),

    doc_string: ($) => repeat1($.doc_comment),

    // ----- ModDef Statements -----
    _mod_stmt: ($) =>
      choice(
        $._component,
        $._driver,
        $.mod_instance,
        $._socket_stmt_mod,
        $.mod_when_stmt,
        $.mod_match_stmt,
        $._unused_stmt,
      ),

    _component: ($) =>
      choice(
        $.component_incoming,
        $.component_outgoing,
        $.component_local,
      ),

    component_incoming: ($) =>
      seq(
        optional($.doc_string),
        "incoming",
        field("name", $.ident),
        ":",
        field("type", $.type),
        optional(field("on", $._on_clause)),
        optional(field("body", $._it_block)),
      ),

    component_outgoing: ($) =>
      seq(
        optional($.doc_string),
        "outgoing",
        optional(field("storage", choice("wire", "reg"))),
        field("name", $.ident),
        ":",
        field("type", $.type),
        optional(field("on", $._on_clause)),
        optional(field("body", $._it_block)),
      ),

    component_local: ($) =>
      seq(
        optional($.doc_string),
        field("storage", choice("wire", "reg")),
        field("name", $.ident),
        ":",
        field("type", $.type),
        optional(field("on", $._on_clause)),
        optional(field("body", $._it_block)),
      ),

    _on_clause: ($) => seq("on", $._expr),

    _driver: ($) =>
      choice(
        $.driver_continuous,
        $.driver_latched,
        $.driver_bidirectional,
      ),

    driver_continuous: ($) =>
      seq(field("lhs", $.path), ":=", field("rhs", $._expr)),

    driver_latched: ($) =>
      seq(field("lhs", $.path), "<=", field("rhs", $._expr)),

    driver_bidirectional: ($) =>
      seq(field("lhs", $.path), ":=:", field("rhs", $.path)),

    mod_instance: ($) =>
      seq(
        optional($.doc_string),
        "mod",
        field("name", $.ident),
        "of",
        $._ofness,
        optional($._it_block),
      ),

    _it_block: ($) => $.mod_stmt_block,

    _socket_stmt_mod: ($) =>
      $.socket_instance,

    socket_instance: ($) =>
      seq(
        optional($.doc_string),
        field("role", choice("client", "server")),
        "socket",
        field("name", $.ident),
        "of",
        field("of", $._ofness),
        optional(field("body", $._it_block)),
      ),

    mod_when_stmt: ($) =>
      seq(
        "when",
        "{",
        repeat($.mod_when_arm),
        "}",
      ),

    mod_when_arm: ($) =>
      choice(
        seq("case", $._expr, "=>", $._expr),
        seq("case", $._expr, $.mod_stmt_block),
        seq("case", $._expr, $.mod_when_stmt),
        seq("case", $._expr, $.mod_match_stmt),
        seq("else", "=>", $._expr),
        seq("else", $.mod_stmt_block),
        seq("else", $.mod_when_stmt),
        seq("else", $.mod_match_stmt),
      ),

    mod_match_stmt: ($) =>
      seq(
        "match",
        $._expr,
        "{",
        repeat($.mod_match_arm),
        "}",
      ),

    mod_match_arm: ($) =>
      choice(
        seq("case", $.pat, "=>", $._expr),
        seq("case", $.pat, $.mod_stmt_block),
        seq("case", $.pat, $.mod_when_stmt),
        seq("case", $.pat, $.mod_match_stmt),
        seq("else", "=>", $._expr),
        seq("else", $.mod_stmt_block),
        seq("else", $.mod_when_stmt),
        seq("else", $.mod_match_stmt),
      ),

    _unused_stmt: ($) => $.unused_stmt,

    unused_stmt: ($) => seq("unused", field("path", $.path)),

    mod_stmt_block: ($) =>
      seq("{", repeat($._mod_stmt), "}"),

    // ----- Type -----
    type: ($) =>
      seq(
        $._ofness,
        optional($._generics_params),
      ),

    _generics_params: ($) =>
      choice(
        seq("[", $.nat, "]"),
        seq("[", $.type, "]"),
      ),

    _ofness: ($) =>
      choice(
        seq($.ident, "::", $.ident),
        $.ident,
      ),

    // ----- Expression -----
    _expr: ($) =>
      choice(
        $.expr_when,
        $.expr_match,
        $.expr_struct,
        $._expr_bin_op_logical,
      ),

    expr_when: ($) =>
      seq(
        "when",
        "{",
        repeat($.expr_when_arm),
        "}",
      ),

    expr_when_arm: ($) =>
      choice(
        seq("case", $._expr, "=>", $._expr),
        seq("case", $._expr, $.mod_stmt_block),
        seq("case", $._expr, $.expr_when),
        seq("case", $._expr, $.expr_match),
        seq("else", "=>", $._expr),
        seq("else", $.mod_stmt_block),
        seq("else", $.expr_when),
        seq("else", $.expr_match),
      ),

    expr_match: ($) =>
      seq(
        "match",
        $._expr,
        "{",
        repeat($.expr_match_arm),
        "}",
      ),

    expr_match_arm: ($) =>
      choice(
        seq("case", $.pat, "=>", $._expr),
        seq("case", $.pat, $.mod_stmt_block),
        seq("case", $.pat, $.expr_when),
        seq("case", $.pat, $.expr_match),
        seq("else", "=>", $._expr),
        seq("else", $.mod_stmt_block),
        seq("else", $.expr_when),
        seq("else", $.expr_match),
      ),

    // ----- Pattern -----
    pat: ($) =>
      choice(
        seq("#", field("name", $.ident)),
        seq("@", field("name", $.ident)),
        seq("@", field("name", $.ident), "(", optional($.pat_list), ")"),
        $.word_lit,
        $.bit_lit,
        $.ident,
        "dontcare",
      ),

    pat_list: ($) =>
      choice(
        seq(repeat1(seq($.pat, ",")), $.pat, optional(",")),
        seq($.pat, optional(",")),
      ),

    // ----- Struct expression -----
    expr_struct: ($) =>
      seq("$", "{", optional($.assign_list), "}"),

    assign_list: ($) =>
      choice(
        seq(repeat(seq($.assign, ",")), $.assign, optional(",")),
        seq($._expr, optional(",")),
      ),

    assign: ($) =>
      seq(field("name", $.ident), "=", $._expr),

    // ----- Binary operators (precedence climbing) -----
    _expr_bin_op_logical: ($) =>
      choice(
        $.expr_bin_op_logical,
        $._expr_bin_op_compare,
      ),

    expr_bin_op_logical: ($) =>
      prec.left(1, seq(
        field("lhs", $._expr_bin_op_logical),
        field("op", choice("&&", "||", "^^")),
        field("rhs", $._expr_bin_op_compare),
      )),

    _expr_bin_op_compare: ($) =>
      choice(
        $.expr_bin_op_compare,
        $._expr_bin_op_additive,
      ),

    expr_bin_op_compare: ($) =>
      prec.left(2, seq(
        field("lhs", $._expr_bin_op_compare),
        field("op", choice("<", "<=", ">", ">=", "==", "!=")),
        field("rhs", $._expr_bin_op_additive),
      )),

    _expr_bin_op_additive: ($) =>
      choice(
        $.expr_bin_op,
        $._expr_un_op,
      ),

    expr_bin_op: ($) =>
      prec.left(3, seq(
        field("lhs", $._expr_bin_op_additive),
        field("op", choice("+", "-", "&", "|", "^")),
        field("rhs", $._expr_un_op),
      )),

    _expr_un_op: ($) =>
      choice(
        prec.right(4, seq(choice("-", "~", "!"), $._expr_un_op)),
        $._expr_ascription,
      ),

    _expr_ascription: ($) =>
      choice(
        prec(5, seq($._expr_primary, ":", $.type)),
        $._expr_primary,
      ),

    // ----- Expr Primary (function call, field access, indexing, constructor call) -----
    _expr_primary: ($) =>
      choice(
        $.expr_call,
        $.expr_field,
        $.expr_index_dyn,
        $.expr_index,
        $.expr_index_range,
        $.expr_ctor_call,
        $.expr_atom,
      ),

    expr_call: ($) =>
      seq(
        field("func", $._ofness),
        "(",
        optional($.arg_list),
        ")",
      ),

    expr_field: ($) =>
      prec.left(8, seq(
        field("expr", $._expr_primary),
        "->",
        field("field", $.ident),
      )),

    expr_index_dyn: ($) =>
      prec.left(7, seq(
        field("expr", $._expr_primary),
        "[",
        "dyn",
        field("index", $._expr),
        "]",
      )),

    expr_index: ($) =>
      prec.left(7, seq(
        field("expr", $._expr_primary),
        "[",
        field("index", $.index),
        "]",
      )),

    expr_index_range: ($) =>
      prec.left(7, seq(
        field("expr", $._expr_primary),
        "[",
        field("high", $.index),
        "..",
        field("low", $.index),
        "]",
      )),

    expr_ctor_call: ($) =>
      seq(
        "@",
        field("ctor", $.ident),
        "(",
        optional($.arg_list),
        ")",
      ),

    arg_list: ($) =>
      choice(
        seq(repeat1(seq($._expr, ",")), $._expr, optional(",")),
        seq($._expr, optional(",")),
      ),

    // ----- Expr Atom (primary without call/index sugar) -----
    expr_atom: ($) =>
      choice(
        $.path,
        $.word_lit,
        $.bit_lit,
        $.str,
        seq("#", field("enumerant", $.ident)),
        seq("@", field("ctor", $.ident)),
        "?",
        "dontcare",
        seq("(", $._expr, ")"),
      ),

    // ----- Path -----
    path: ($) =>
      seq(
        choice("it", $.ident),
        repeat(seq(".", $.ident)),
      ),

    // ----- Terminals -----
    ident: ($) => /[_a-zA-Z][_a-zA-Z0-9]*/,

    nat: ($) =>
      token(
        choice(
          /[0-9]([_]?[0-9])*/,
          /0b[0-1]([_]?[0-1])*/,
          /0x[0-9a-fA-F]([_]?[0-9a-fA-F])*/,
        ),
      ),

    word_lit: ($) =>
      choice(
        $.nat,
        $.word,
      ),

    word: ($) =>
      token(
        choice(
          /[0-9]([_]?[0-9])*w[0-9]+/,
          /0b[0-1]([_]?[0-1])*w[0-9]+/,
          /0x[0-9a-fA-F]([_]?[0-9a-fA-F])*w[0-9]+/,
        ),
      ),

    bit_lit: ($) =>
      choice("true", "false"),

    str: ($) =>
      token(/"(?:[^"\\]|\\(?:t|n|r|0))*"/),

    index: ($) => $.nat,

    width: ($) => $.nat,
  },
});
