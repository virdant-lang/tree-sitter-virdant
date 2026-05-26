[
    "enum"
    "width"
    "builtin"
    "fn"
    "socket"
    "import"
    "ext"
    "export"
    "mod"
    "union"
    "struct"
    "type"
    "cosi"
    "ciso"
    "client"
    "server"
    "if"
    "else"
    "match"
    "case"
    "incoming"
    "outgoing"
    "wire"
    "reg"
    "on"
    "of"
    "true"
    "false"
    "dontcare"
] @keyword

(moddef name: (ident) @function)
(type) @type
(uniondef name: (ident) @type)
(structdef name: (ident) @type)
(enumdef name: (ident) @type)

(word) @number
(nat) @number
(str) @string

; "it" in paths - special implicit variable
(path "it" @variable.builtin)

; Constructors - highlight the entire constructor node including @ and ctor name
(expr_atom ctor: (ident) @constructor)
(expr_primary ctor: (ident) @constructor)
"@" @constructor

; Enumerants - highlight the same as constructors
(expr_atom enumerant: (ident) @constructor)
"#" @constructor
(pat
  "#" @constructor
  name: (ident) @constructor)
