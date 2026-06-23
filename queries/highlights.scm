; ---------------------------------------------------------------------------
; Keywords
; ---------------------------------------------------------------------------
[
  "enum"
  "unused"
  "builtin"
  "socket"
  "import"
  "ext"
  "export"
  "mod"
  "union"
  "struct"
  "type"
  "cosi"
  "soci"
  "client"
  "server"
  "when"
  "else"
  "match"
  "case"
  "incoming"
  "outgoing"
  "wire"
  "reg"
  "on"
  "of"
  "dyn"
  "it"
] @keyword

; ---------------------------------------------------------------------------
; Boolean and dontcare literals
; ---------------------------------------------------------------------------
[
  "true"
  "false"
  "dontcare"
] @number

; ---------------------------------------------------------------------------
; Hole operator
; ---------------------------------------------------------------------------
"?" @punctuation.special

; ---------------------------------------------------------------------------
; Number literals
; ---------------------------------------------------------------------------
(word) @number
(nat) @number

; ---------------------------------------------------------------------------
; String literals
; ---------------------------------------------------------------------------
(str) @string

; ---------------------------------------------------------------------------
; Comments
; ---------------------------------------------------------------------------
(line_comment) @comment
(doc_comment) @comment.documentation
(doc_bang) @comment.documentation

; ---------------------------------------------------------------------------
; Type names
; ---------------------------------------------------------------------------
(type) @type
(moddef name: (ident) @type)
(uniondef name: (ident) @type)
(structdef name: (ident) @type)
(enumdef name: (ident) @type)
(builtindef name: (ident) @type)
(socketdef name: (ident) @type)
(generics name: (ident) @type.definition)
(kind name: (ident) @type)
(call_expr func: (ofness name: (ident) @type))
(call_expr func: (ofness package: (ident) @type))

; ---------------------------------------------------------------------------
; Enum variant names / constants
; ---------------------------------------------------------------------------
(enumdef_stmt name: (ident) @constant)
(expr_atom enumerant: (ident) @constant)


; ---------------------------------------------------------------------------
; Union constructors
; ---------------------------------------------------------------------------
(expr_atom ctor: (ident) @constructor)
(ctor_call_expr ctor: (ident) @constructor)
(uniondef_stmt name: (ident) @constructor)

; ---------------------------------------------------------------------------
; Pattern constructors / enumerants
; ---------------------------------------------------------------------------
[
  "#"
  "@"
] @operator

; Pattern #Ident - enum constant ref
(pat "#" (ident) @constant)

; Pattern @Ident or @Ident(...) - constructor match
(pat "@" (ident) @constructor)

; Pattern bare ident - variable binding
(pat (ident) @variable)

; ---------------------------------------------------------------------------
; Path identifiers
; ---------------------------------------------------------------------------
(path "it" @keyword)
(path (ident) @variable)

; ---------------------------------------------------------------------------
; Parameters
; ---------------------------------------------------------------------------
(param name: (ident) @variable.parameter)

; ---------------------------------------------------------------------------
; Struct member fields
; ---------------------------------------------------------------------------
(structdef_stmt name: (ident) @property)
(assign name: (ident) @property)
(field_expr field: (ident) @property)

; ---------------------------------------------------------------------------
; Import package names
; ---------------------------------------------------------------------------
(import name: (ident) @type)

; ---------------------------------------------------------------------------
; Module and socket instance ofness
; ---------------------------------------------------------------------------
(mod_instance module: (ofness) @type)
(socket_instance socket: (ofness) @type)

; ---------------------------------------------------------------------------
; Module and socket instance names
; ---------------------------------------------------------------------------
(mod_instance name: (ident) @variable)
(socket_instance name: (ident) @variable)

; ---------------------------------------------------------------------------
; Component names
; ---------------------------------------------------------------------------
(component_incoming name: (ident) @variable)
(component_outgoing name: (ident) @variable)
(component_local name: (ident) @variable)

; ---------------------------------------------------------------------------
; Socket channel names
; ---------------------------------------------------------------------------
(socketdef_stmt name: (ident) @property)

; ---------------------------------------------------------------------------
; Operators
; ---------------------------------------------------------------------------
[
  ":="
  "<="
  ":=:"
  "&&"
  "||"
  "^^"
  "=="
  "!="
  "<"
  ">"
  ">="
  "+"
  "-"
  "&"
  "|"
  "^"
  "~"
  "!"
  "->"
  "=>"
  "="
  ":"
  "::"
  "."
  ".."
] @operator

; ---------------------------------------------------------------------------
; Punctuation
; ---------------------------------------------------------------------------
[
  "("
  ")"
  "{"
  "}"
  "["
  "]"
  ","
  "$"
] @punctuation.bracket
