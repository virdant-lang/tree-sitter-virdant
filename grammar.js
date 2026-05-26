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
        repeat($.doc_bang),
        repeat(choice($.import, $.item)),
      ),

    line_comment: ($) => token(seq("//", /[^\n]*/)),

    doc_comment: ($) => token(seq("///", /[^\n]*/)),

    doc_bang: ($) => token(seq("//!", /[^\n]*/)),

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
        $.fndef,
      ),

    // --- ModDef ---
    moddef: ($) =>
      seq(
        repeat($.doc_comment),
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
        repeat($.doc_comment),
        "struct",
        "type",
        field("name", $.ident),
        "{",
        repeat($.structdef_stmt),
        "}",
      ),

    structdef_stmt: ($) =>
      seq(
        repeat($.doc_comment),
        field("name", $.ident),
        ":",
        $.type,
      ),

    // --- UnionDef ---
    uniondef: ($) =>
      seq(
        repeat($.doc_comment),
        "union",
        "type",
        field("name", $.ident),
        "{",
        repeat($.uniondef_stmt),
        "}",
      ),

    uniondef_stmt: ($) =>
      seq(
        repeat($.doc_comment),
        field("name", $.ident),
        optional($._param_list),
      ),

    _param_list: ($) =>
      seq("(", optional(seq($.param, repeat(seq(",", $.param)))), ")"),

    param: ($) =>
      seq(
        repeat($.doc_comment),
        field("name", $.ident),
        ":",
        $.type,
      ),

    // --- EnumDef ---
    enumdef: ($) =>
      seq(
        repeat($.doc_comment),
        "enum",
        "type",
        field("name", $.ident),
        "width",
        $.nat,
        "{",
        repeat($.enumdef_stmt),
        "}",
      ),

    enumdef_stmt: ($) =>
      seq(
        repeat($.doc_comment),
        field("name", $.ident),
        "=",
        $._expr,
      ),

    // --- BuiltinDef ---
    builtindef: ($) =>
      seq(
        repeat($.doc_comment),
        "builtin",
        "type",
        field("name", $.ident),
        optional($._generics),
        "{",
        "}",
      ),

    _generics: ($) =>
      seq("[", $.ident, ":", $.ident, "]"),

    // --- SocketDef ---
    socketdef: ($) =>
      seq(
        repeat($.doc_comment),
        "socket",
        field("name", $.ident),
        "{",
        repeat($.socketdef_stmt),
        "}",
      ),

    socketdef_stmt: ($) =>
      seq(
        repeat($.doc_comment),
        choice("cosi", "soci"),
        $.ident,
        ":",
        $.type,
      ),

    // --- FnDef ---
    fndef: ($) =>
      seq(
        repeat($.doc_comment),
        "fn",
        field("name", $.ident),
        $._param_list,
        "->",
        $.type,
        "{",
        $._expr,
        "}",
      ),

    // ----- ModDef Statements -----
    _mod_stmt: ($) =>
      choice(
        $._component,
        $._driver,
        $.mod_instance,
        $._socket_stmt_mod,
        $._if_stmt,
        $._match_stmt,
        $._unused_stmt,
      ),

    _component: ($) =>
      seq(
        repeat($.doc_comment),
        choice(
          seq("incoming", $.ident, ":", $.type, optional($._on_clause), optional($._it_block)),
          seq("outgoing", optional(choice("wire", "reg")), $.ident, ":", $.type, optional($._on_clause), optional($._it_block)),
          seq(choice("wire", "reg"), $.ident, ":", $.type, optional($._on_clause), optional($._it_block)),
        ),
      ),

    _on_clause: ($) => seq("on", $._expr),

    _driver: ($) =>
      seq(
        choice(
          seq($.path, ":=", $._expr),
          seq($.path, "<=", $._expr),
          seq($.path, ":=:", $.path),
        ),
      ),

    mod_instance: ($) =>
      seq(
        repeat($.doc_comment),
        "mod",
        field("name", $.ident),
        "of",
        $._ofness,
        optional($._it_block),
      ),

    _it_block: ($) => $.mod_stmt_block,

    _socket_stmt_mod: ($) =>
      seq(
        repeat($.doc_comment),
        choice("client", "server"),
        "socket",
        $.ident,
        "of",
        $._ofness,
        optional($._it_block),
      ),

    _if_stmt: ($) =>
      seq(
        "if",
        $._expr,
        $.mod_stmt_block,
        repeat(seq("else", "if", $._expr, $.mod_stmt_block)),
        optional(seq("else", $.mod_stmt_block)),
      ),

    _match_stmt: ($) =>
      seq(
        "match",
        $._expr,
        "{",
        repeat($._match_arm),
        "}",
      ),

    _match_arm: ($) =>
      seq(
        choice(
          seq("case", $.pat, "=>", $.mod_stmt_block),
          seq("else", "=>", $.mod_stmt_block),
        ),
      ),

    _unused_stmt: ($) => seq("unused", $.path),

    mod_stmt_block: ($) =>
      seq("{", repeat($._mod_stmt), "}"),

    // ----- Type -----
    type: ($) =>
      seq(
        $._ofness,
        optional(choice(
          seq("[", $.nat, "]"),
          seq("[", $.type, "]"),
        )),
      ),

    _ofness: ($) =>
      choice(
        seq($.ident, "::", $.ident),
        $.ident,
      ),

    // ----- Expression -----
    _expr: ($) =>
      choice(
        $._expr_if,
        $._expr_match,
        $._expr_struct,
        $._expr_bin_op_logical,
      ),

    _expr_if: ($) =>
      seq(
        "if",
        $._expr,
        "{",
        $._expr,
        "}",
        repeat(seq("else", "if", $._expr, "{", $._expr, "}")),
        seq("else", "{", $._expr, "}"),
      ),

    _expr_match: ($) =>
      seq(
        "match",
        $._expr,
        "{",
        repeat($._expr_match_arm),
        "}",
      ),

    _expr_match_arm: ($) =>
      seq(
        choice(
          seq("case", $.pat, "=>", $._expr),
          seq("else", "=>", $._expr),
        ),
      ),

    // ----- Pattern -----
    pat: ($) =>
      choice(
        seq("#", field("name", $.ident)),
        seq("@", field("name", $.ident), optional(seq("(", optional(seq($.pat, repeat(seq(",", $.pat)), optional(","))), ")"))),
        $.word,
        $.nat,
        choice("true", "false"),
        $.ident,
        "dontcare",
      ),

    // ----- Struct expression -----
    _expr_struct: ($) =>
      seq("$", "{", optional(choice(
        seq($.assign, repeat(seq(",", $.assign)), optional(",")),
        seq($._expr, optional(",")),
      )), "}"),

    assign: ($) =>
      seq(field("name", $.ident), "=", $._expr),

    // ----- Binary operators (precedence climbing) -----
    _expr_bin_op_logical: ($) =>
      prec.left(
        choice(
          seq($._expr_bin_op_logical, choice("&&", "||", "^^"), $._expr_bin_op_compare),
          $._expr_bin_op_compare,
        ),
      ),

    _expr_bin_op_compare: ($) =>
      prec.left(
        choice(
          seq($._expr_bin_op_compare, choice("<", "<=", ">", ">=", "==", "!="), $._expr_bin_op_additive),
          $._expr_bin_op_additive,
        ),
      ),

    _expr_bin_op_additive: ($) =>
      prec.left(
        choice(
          seq($._expr_bin_op_additive, choice("+", "-", "&", "|", "^"), $._expr_un_op),
          $._expr_un_op,
        ),
      ),

    _expr_un_op: ($) =>
      prec.left(
        choice(
          seq(choice("-", "~", "!"), $._expr_un_op),
          $._expr_ascription,
        ),
      ),

    _expr_ascription: ($) =>
      seq($._expr_primary, optional(seq(":", $.type))),

    // ----- Expr Primary (function call, field access, indexing, constructor call) -----
    _expr_primary: ($) =>
      choice(
        seq($._ofness, "(", optional(seq($._expr, repeat(seq(",", $._expr)), optional(","))), ")"),
        prec.left(seq($._expr_primary, "->", $.ident)),
        prec.left(seq($._expr_primary, "[", "dyn", $._expr, "]")),
        prec.left(seq($._expr_primary, "[", $.nat, "..", $.nat, "]")),
        prec.left(seq($._expr_primary, "[", $.nat, "]")),
        seq("@", field("ctor", $.ident), "(", optional(seq($._expr, repeat(seq(",", $._expr)), optional(","))), ")"),
        $.expr_atom,
      ),

    // ----- Expr Atom (primary without call/index sugar) -----
    expr_atom: ($) =>
      choice(
        $.path,
        $.word,
        $.nat,
        choice("true", "false"),
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

    word: ($) =>
      token(
        choice(
          /[0-9]([_]?[0-9])*w[0-9]+/,
          /0b[0-1]([_]?[0-1])*w[0-9]+/,
          /0x[0-9a-fA-F]([_]?[0-9a-fA-F])*w[0-9]+/,
        ),
      ),

    str: ($) =>
      token(/"(?:[^"\\]|\\(?:t|n|r|0))*"/),
  },
});