; Virdant highlights
;
; Ordering follows the Neovim convention: general captures come first and
; more specific captures later override them.

; ---------------------------------------------------------------------------
; Identifiers (fallback)
; ---------------------------------------------------------------------------

(identifier) @variable

; Every segment of a path after the first is a member access: `a.b.c`
(path
  "."
  .
  (identifier) @variable.member)

(it) @variable.builtin

; ---------------------------------------------------------------------------
; Comments
; ---------------------------------------------------------------------------

(comment) @comment @spell

(doc_comment) @comment.documentation @spell

(doc_bang) @comment.documentation @spell

; ---------------------------------------------------------------------------
; Keywords
; ---------------------------------------------------------------------------

"import" @keyword.import

[
  "mod"
  "socket"
  "platform"
  "of"
  "on"
  "for"
  "unused"
  "dependson"
] @keyword

[
  "struct"
  "union"
  "enum"
  "builtin"
  "type"
] @keyword.type

[
  "ext"
  "export"
  "incoming"
  "outgoing"
  "wire"
  "reg"
  "client"
  "server"
  "cosi"
  "soci"
  "dyn"
] @keyword.modifier

[
  "when"
  "match"
  "case"
  "else"
] @keyword.conditional

; ---------------------------------------------------------------------------
; Literals
; ---------------------------------------------------------------------------

[
  (nat_literal)
  (word_literal)
] @number

(bit_literal) @boolean

(string_literal) @string

(escape_sequence) @string.escape

[
  (dontcare)
  (hole)
] @constant.builtin

; ---------------------------------------------------------------------------
; Packages / modules
; ---------------------------------------------------------------------------

(import
  package: (identifier) @module)

(ofness
  package: (identifier) @module)

; ---------------------------------------------------------------------------
; Type definitions
; ---------------------------------------------------------------------------

(mod_def
  name: (identifier) @type.definition)

(struct_def
  name: (identifier) @type.definition)

(union_def
  name: (identifier) @type.definition)

(enum_def
  name: (identifier) @type.definition)

(builtin_def
  name: (identifier) @type.definition)

(socket_def
  name: (identifier) @type.definition)

(platform_def
  name: (identifier) @type.definition)

; `builtin type Word[n : Nat] {}`
(generics
  name: (identifier) @variable.parameter)

(kind
  name: (identifier) @type.builtin)

; ---------------------------------------------------------------------------
; Type references
; ---------------------------------------------------------------------------

(type
  name: (ofness
    name: (identifier) @type))

; Types defined in the standard library (`lib/builtin.vir`)
(type
  name: (ofness
    !package
    name: (identifier) @type.builtin)
  (#any-of? @type.builtin "Bit" "Word" "Clock" "Reset" "Valid"))

(mod_instance
  module: (ofness
    name: (identifier) @type))

(socket_instance
  socket: (ofness
    name: (identifier) @type))

(for_clause
  platform: (ofness
    name: (identifier) @type))

; ---------------------------------------------------------------------------
; Declarations
; ---------------------------------------------------------------------------

; Ports, wires, and registers
(component
  name: (identifier) @variable)

; Submodule and socket instances
(mod_instance
  name: (identifier) @variable)

(socket_instance
  name: (identifier) @variable)

; Constructor parameters
(param
  name: (identifier) @variable.parameter)

; Struct fields and socket channels
(field_def
  name: (identifier) @variable.member)

(channel_def
  name: (identifier) @variable.member)

; ---------------------------------------------------------------------------
; Expressions
; ---------------------------------------------------------------------------

; `foo(x)`, `pkg::foo(x)`
(call_expression
  function: (ofness
    name: (identifier) @function.call))

; `x->field`
(field_expression
  field: (identifier) @variable.member)

; `${ field = value }`
(assign
  name: (identifier) @variable.member)

; ---------------------------------------------------------------------------
; Union constructors: `Ctor(...)`, `@Ctor(...)`
; ---------------------------------------------------------------------------

(ctor_def
  name: (identifier) @constructor)

(ctor_expression
  "@" @constructor
  name: (identifier) @constructor)

(ctor_pattern
  "@" @constructor
  name: (identifier) @constructor)

; ---------------------------------------------------------------------------
; Enumerants: `Name = value`, `#Name`
; ---------------------------------------------------------------------------

(enumerant_def
  name: (identifier) @constant)

(enumerant_expression
  "#" @constant
  name: (identifier) @constant)

(enumerant_pattern
  "#" @constant
  name: (identifier) @constant)

; ---------------------------------------------------------------------------
; Patterns
; ---------------------------------------------------------------------------

(binding_pattern
  name: (identifier) @variable)

; ---------------------------------------------------------------------------
; Annotations: `@name`, `@name(args)`
; ---------------------------------------------------------------------------

(annotation
  "@" @attribute
  name: (identifier) @attribute)

; ---------------------------------------------------------------------------
; Operators
; ---------------------------------------------------------------------------

[
  ; drivers
  ":="
  "<="
  ":=:"
  ; logical
  "&&"
  "||"
  "^^"
  ; comparison
  "<"
  ">"
  ">="
  "=="
  "!="
  ; additive
  "+"
  "-"
  "&"
  "|"
  "^"
  ; unary
  "~"
  "!"
  ; misc
  "->"
  "=>"
  "="
  ".."
] @operator

; ---------------------------------------------------------------------------
; Punctuation
; ---------------------------------------------------------------------------

[
  "("
  ")"
  "["
  "]"
  "{"
  "}"
] @punctuation.bracket

[
  ","
  ":"
  "::"
  "."
] @punctuation.delimiter

"$" @punctuation.special
