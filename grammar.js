/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: "virdant",

  extras: $ => [
    $.comment_line,
    $.comment_block,
    /\s/,
  ],

  rules: {
    package: $ => repeat($._package_stmt),

    _package_stmt: $ => choice(
      $.package_import,
      $.item,
    ),

    package_import: $ => seq("import", $.ident),

    item: $ => choice(
      $.moddef,
      $.structdef,
      $.uniondef,
      $.enumdef,
      $.builtindef,
      $.socketdef,
      $.fndef,
    ),

    moddef: $ => seq(
      optional("ext"), optional("export"), "mod", field("name", $.ident), "{",
      repeat($._moddef_stmt),
      "}"
    ),

    structdef: $ => seq(
      "struct", "type", field("name", $.ident), "{",
      repeat($.structdef_stmt),
      "}"
    ),

    structdef_stmt: $ => seq(field("name", $.ident), ":", $.type),

    uniondef: $ => seq(
      "union", "type", field("name", $.ident), "{",
      repeat($.uniondef_stmt),
      "}"
    ),

    uniondef_stmt: $ => seq(field("name", $.ident), optional($.paramlist)),

    paramlist: $ => seq("(", optional($.params), ")"),

    params: $ => seq($.param, repeat(seq(",", $.param))),

    param: $ => seq(field("name", $.ident), ":", $.type),

    generics_params: $ => seq("[", $.nat, "]"),

    generics: $ => seq("[", $.ident, ":", $.kind, "]"),

    enumdef: $ => seq(
      "enum", "type", field("name", $.ident), "width", field("width", $.width), "{",
      repeat($.enumdef_stmt),
      "}"
    ),

    enumdef_stmt: $ => seq(field("name", $.ident), "=", $.expr),

    builtindef: $ => seq(
      "builtin", "type", field("name", $.ident), optional($.generics), "{",
      "}"
    ),

    socketdef: $ => seq(
      "socket", field("name", $.ident), "{",
      repeat($.socketdef_stmt),
      "}"
    ),

    socketdef_stmt: $ => choice(
      seq("mosi", field("name", $.ident), ":", $.type),
      seq("miso", field("name", $.ident), ":", $.type),
    ),

    fndef: $ => seq(
      "fn", field("name", $.ident), field("paramlist", $.paramlist), "->", $.type, "{",
      $.expr,
      "}"
    ),

    _moddef_stmt: $ => choice(
      $._moddef_stmt_component,
      $._moddef_stmt_driver,
      $._moddef_stmt_instance,
      $._moddef_stmt_socket,
      $.moddef_stmt_if,
      $.moddef_stmt_match,
    ),

    _moddef_stmt_component: $ => choice(
      seq("incoming", field("name", $.ident), ":", field("type", $.type), field("on", optional($.on_clause))),
      seq("outgoing", field("name", $.ident), ":", field("type", $.type), field("on", optional($.on_clause))),
      seq("wire", field("name", $.ident), ":", field("type", $.type), field("on", optional($.on_clause))),
      seq("reg", field("name", $.ident), ":", field("type", $.type), field("on", optional($.on_clause))),
    ),

    on_clause: $ => seq("on", $.expr),

    _moddef_stmt_driver: $ => choice(
      seq(field("lhs", $.path), ":=", field("rhs", $.expr)),
      seq(field("lhs", $.path), "<=", field("rhs", $.expr)),
      seq(field("lhs", $.path), ":=:", field("rhs", $.path)),
    ),

    _moddef_stmt_instance: $ => seq(
      "mod", field("name", $.ident), "of", field("ofness", $.ofness), optional($.it_block),
    ),

    it_block: $ => $.moddef_stmt_block,

    _moddef_stmt_socket: $ => choice(
      seq("master", "socket", field("name", $.ident), "of", field("ofness", $.ofness)),
      seq("slave", "socket", field("name", $.ident), "of", field("ofness", $.ofness)),
    ),

    moddef_stmt_if: $ => seq(
      $.moddef_stmt_if_start,
      repeat($.moddef_stmt_if_middle),
      optional($.moddef_stmt_if_end),
    ),

    moddef_stmt_if_start: $ => seq("if", $.expr, $.moddef_stmt_block),

    moddef_stmt_if_middle: $ => seq("else", "if", $.expr, $.moddef_stmt_block),

    moddef_stmt_if_end: $ => seq("else", $.moddef_stmt_block),

    moddef_stmt_match: $ => seq(
      "match", $.expr, "{",
      repeat($.moddef_stmt_match_arm),
      "}"
    ),

    moddef_stmt_match_arm: $ => choice(
      seq("case", $.pat, "=>", $.moddef_stmt_block),
      seq("else", "=>", $.moddef_stmt_block),
    ),

    moddef_stmt_block: $ => seq("{", repeat($._moddef_stmt), "}"),

    kind: $ => field("name", $.ident),

    type: $ => seq(field("ofness", $.ofness), field("generics", optional($.generics_params))),

    expr: $ => choice(
      $.expr_if,
      $.expr_match,
      $.expr_struct,
      $.expr_bin_op_logical,
    ),

    expr_if: $ => seq(
      $.expr_if_start,
      repeat($.expr_if_middle),
      $.expr_if_end,
    ),

    expr_if_start: $ => seq("if", $.expr, "{", $.expr, "}"),

    expr_if_middle: $ => seq("else", "if", $.expr, "{", $.expr, "}"),

    expr_if_end: $ => seq("else", "{", $.expr, "}"),

    expr_match: $ => seq(
      "match", $.expr, "{",
      repeat($.expr_match_arm),
      "}"
    ),

    expr_match_arm: $ => choice(
      seq("case", $.pat, "=>", $.expr),
      seq("else", "=>", $.expr),
    ),

    pat: $ => choice(
      seq("#", field("name", $.ident)),
      seq("@", field("name", $.ident)),
      seq("@", field("name", $.ident), "(", field("args", optional($.arglist)), ")"),
    ),

    expr_struct: $ => seq("$", "{", field("assigns", optional($.assign_list)), "}"),

    assign_list: $ => choice(
      seq(repeat1(seq($.assign, ",")), $.assign, optional(",")),
      seq($.assign, optional(",")),
      seq($.expr, optional(",")),
    ),

    assign: $ => seq(field("name", $.ident), "=", $.expr),

    expr_bin_op_logical: $ => choice(
      seq(field("lhs", $.expr_bin_op_logical), field("op", choice("&&", "||", "^^")), field("rhs", $.expr_bin_op_compare)),
      $.expr_bin_op_compare,
    ),

    expr_bin_op_compare: $ => choice(
      seq(field("lhs", $.expr_bin_op_compare), field("op", choice("<", "<=", ">", ">=", "==", "!=")), field("rhs", $.expr_bin_op_additive)),
      $.expr_bin_op_additive,
    ),

    expr_bin_op_additive: $ => choice(
      seq(field("lhs", $.expr_bin_op_additive), field("op", choice("+", "-", "&", "|", "^")), field("rhs", $.expr_un_op)),
      $.expr_un_op,
    ),

    expr_un_op: $ => choice(
      seq(field("op", choice("-", "~", "!")), field("rhs", $.expr_un_op)),
      $.expr_ascription,
    ),

    expr_ascription: $ => choice(
      seq(field("e", $.expr_primary), ":", field("typ", $.type)),
      $.expr_primary,
    ),

    expr_primary: $ => choice(
      seq(field("ofness", $.ofness), "(", field("args", optional($.arglist)), ")"),
      seq(field("e", $.expr_primary), "->", field("method", $.ident), "(", field("arglist", optional($.arglist)), ")"),
      seq(field("e", $.expr_primary), "->", field("field", $.ident)),
      seq(field("e", $.expr_primary), "[", field("index", $.index), "]"),
      seq(field("e", $.expr_primary), "[", field("index_hi", $.index), "..", field("index_lo", $.index), "]"),
      seq("@", field("ctor", $.ident), "(", field("args", optional($.arglist)), ")"),
      $.expr_atom,
    ),

    expr_atom: $ => choice(
      $.path,
      $.word_lit,
      "true",
      "false",
      $.str,
      seq("#", field("enumerant", $.ident)),
      seq("@", field("ctor", $.ident)),
      "?",
      seq("(", $.expr, ")"),
    ),

    arglist: $ => seq($.expr, repeat(seq(",", $.expr)), optional(",")),

    ofness: $ => choice(
      field("name", $.ident),
      seq(field("package", $.ident), "::", field("name", $.ident)),
    ),

    path: $ => seq(repeat(seq($.ident, ".")), $.ident),

    index: $ => $.nat,

    width: $ => $.nat,

    word_lit: $ => choice($.nat, $.word),

    ident: $ => /[_A-Za-z][_A-Za-z0-9]*/,

    nat: $ => /[0-9][_0-9]*/,

    str: $ => /"[^"]*"/,

    word: $ => choice(
      /0b[0-1][_0-1]*(w[0-9]+)?/,
      /0x[0-9A-Fa-f][_0-9A-Fa-f]*(w[0-9]+)?/,
      /[0-9][_0-9]*(w[0-9]+)?/,
    ),

    comment_line: _ => token(seq('//', /[^\n]*/)),

    comment_block: _ => token(
      seq(
        '/*',
        /[^*]*\*+([^/*][^*]*\*+)*/,
        '/',
      ),
    ),
  }
});
