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
    "mosi"
    "miso"
    "master"
    "slave"
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
] @keyword

(moddef name: (ident) @function)
(type) @type
(uniondef name: (ident) @type)
(structdef name: (ident) @type)
(enumdef name: (ident) @type)

(word) @number
(nat) @number
(str) @string
