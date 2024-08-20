#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 246
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 115
#define ALIAS_COUNT 0
#define TOKEN_COUNT 58
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 12
#define MAX_ALIAS_SEQUENCE_LENGTH 10
#define PRODUCTION_ID_COUNT 12

enum ts_symbol_identifiers {
  anon_sym_import = 1,
  anon_sym_SEMI = 2,
  anon_sym_pub = 3,
  anon_sym_ext = 4,
  anon_sym_mod = 5,
  anon_sym_LBRACE = 6,
  anon_sym_RBRACE = 7,
  anon_sym_builtin = 8,
  anon_sym_type = 9,
  anon_sym_struct = 10,
  anon_sym_COLON = 11,
  anon_sym_union = 12,
  anon_sym_enum = 13,
  anon_sym_width = 14,
  anon_sym_EQ = 15,
  anon_sym_fn = 16,
  anon_sym_LPAREN = 17,
  anon_sym_RPAREN = 18,
  anon_sym_DASH_GT = 19,
  anon_sym_socket = 20,
  anon_sym_mosi = 21,
  anon_sym_miso = 22,
  anon_sym_COMMA = 23,
  anon_sym_implicit = 24,
  anon_sym_incoming = 25,
  anon_sym_outgoing = 26,
  anon_sym_wire = 27,
  anon_sym_reg = 28,
  anon_sym_on = 29,
  anon_sym_of = 30,
  anon_sym_master = 31,
  anon_sym_slave = 32,
  sym_direct = 33,
  sym_latched = 34,
  anon_sym_if = 35,
  anon_sym_else = 36,
  anon_sym_match = 37,
  anon_sym_EQ_GT = 38,
  anon_sym_LBRACK = 39,
  anon_sym_RBRACK = 40,
  anon_sym_DOT_DOT = 41,
  anon_sym_true = 42,
  anon_sym_false = 43,
  sym_type_clock = 44,
  anon_sym_Word = 45,
  sym_type_bit = 46,
  sym_path = 47,
  aux_sym_word_token1 = 48,
  aux_sym_word_token2 = 49,
  aux_sym_word_token3 = 50,
  sym_nat = 51,
  sym_enumerant = 52,
  sym_ctor = 53,
  sym_qualident = 54,
  sym_ident = 55,
  sym_comment_line = 56,
  sym_comment_block = 57,
  sym_package = 58,
  sym_package_import = 59,
  sym_item = 60,
  sym_moddef = 61,
  sym_builtindef = 62,
  sym_structdef = 63,
  sym_field = 64,
  sym_uniondef = 65,
  sym_enumdef = 66,
  sym_enumdef_statement = 67,
  sym_fndef = 68,
  sym_alt = 69,
  sym_socketdef = 70,
  sym_channel = 71,
  sym_channeldir = 72,
  sym__decl = 73,
  sym__component = 74,
  sym_implicit = 75,
  sym_incoming = 76,
  sym_outgoing = 77,
  sym_wire = 78,
  sym_reg = 79,
  sym_socket = 80,
  sym_socket_role = 81,
  sym_connect = 82,
  sym_submodule = 83,
  sym_connect_type = 84,
  sym_expr = 85,
  sym_expr_if = 86,
  sym_expr_match = 87,
  sym_match_arm = 88,
  sym_pat = 89,
  sym_patlist = 90,
  sym_expr_call = 91,
  sym_expr_idx = 92,
  sym_expr_lit = 93,
  sym_expr_reference = 94,
  sym_word_lit = 95,
  sym_bool = 96,
  sym__expr_list = 97,
  sym_param_list = 98,
  sym_arg = 99,
  sym_type = 100,
  sym_type_word = 101,
  sym_word = 102,
  aux_sym_package_repeat1 = 103,
  aux_sym_package_repeat2 = 104,
  aux_sym_moddef_repeat1 = 105,
  aux_sym_structdef_repeat1 = 106,
  aux_sym_uniondef_repeat1 = 107,
  aux_sym_enumdef_repeat1 = 108,
  aux_sym_socketdef_repeat1 = 109,
  aux_sym_expr_if_repeat1 = 110,
  aux_sym_expr_match_repeat1 = 111,
  aux_sym_patlist_repeat1 = 112,
  aux_sym__expr_list_repeat1 = 113,
  aux_sym_param_list_repeat1 = 114,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_import] = "import",
  [anon_sym_SEMI] = ";",
  [anon_sym_pub] = "pub",
  [anon_sym_ext] = "ext",
  [anon_sym_mod] = "mod",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_builtin] = "builtin",
  [anon_sym_type] = "type",
  [anon_sym_struct] = "struct",
  [anon_sym_COLON] = ":",
  [anon_sym_union] = "union",
  [anon_sym_enum] = "enum",
  [anon_sym_width] = "width",
  [anon_sym_EQ] = "=",
  [anon_sym_fn] = "fn",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_DASH_GT] = "->",
  [anon_sym_socket] = "socket",
  [anon_sym_mosi] = "mosi",
  [anon_sym_miso] = "miso",
  [anon_sym_COMMA] = ",",
  [anon_sym_implicit] = "implicit",
  [anon_sym_incoming] = "incoming",
  [anon_sym_outgoing] = "outgoing",
  [anon_sym_wire] = "wire",
  [anon_sym_reg] = "reg",
  [anon_sym_on] = "on",
  [anon_sym_of] = "of",
  [anon_sym_master] = "master",
  [anon_sym_slave] = "slave",
  [sym_direct] = "direct",
  [sym_latched] = "latched",
  [anon_sym_if] = "if",
  [anon_sym_else] = "else",
  [anon_sym_match] = "match",
  [anon_sym_EQ_GT] = "=>",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [anon_sym_DOT_DOT] = "..",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [sym_type_clock] = "type_clock",
  [anon_sym_Word] = "Word",
  [sym_type_bit] = "type_bit",
  [sym_path] = "path",
  [aux_sym_word_token1] = "word_token1",
  [aux_sym_word_token2] = "word_token2",
  [aux_sym_word_token3] = "word_token3",
  [sym_nat] = "nat",
  [sym_enumerant] = "enumerant",
  [sym_ctor] = "ctor",
  [sym_qualident] = "qualident",
  [sym_ident] = "ident",
  [sym_comment_line] = "comment_line",
  [sym_comment_block] = "comment_block",
  [sym_package] = "package",
  [sym_package_import] = "package_import",
  [sym_item] = "item",
  [sym_moddef] = "moddef",
  [sym_builtindef] = "builtindef",
  [sym_structdef] = "structdef",
  [sym_field] = "field",
  [sym_uniondef] = "uniondef",
  [sym_enumdef] = "enumdef",
  [sym_enumdef_statement] = "enumdef_statement",
  [sym_fndef] = "fndef",
  [sym_alt] = "alt",
  [sym_socketdef] = "socketdef",
  [sym_channel] = "channel",
  [sym_channeldir] = "channeldir",
  [sym__decl] = "_decl",
  [sym__component] = "_component",
  [sym_implicit] = "implicit",
  [sym_incoming] = "incoming",
  [sym_outgoing] = "outgoing",
  [sym_wire] = "wire",
  [sym_reg] = "reg",
  [sym_socket] = "socket",
  [sym_socket_role] = "socket_role",
  [sym_connect] = "connect",
  [sym_submodule] = "submodule",
  [sym_connect_type] = "connect_type",
  [sym_expr] = "expr",
  [sym_expr_if] = "expr_if",
  [sym_expr_match] = "expr_match",
  [sym_match_arm] = "match_arm",
  [sym_pat] = "pat",
  [sym_patlist] = "patlist",
  [sym_expr_call] = "expr_call",
  [sym_expr_idx] = "expr_idx",
  [sym_expr_lit] = "expr_lit",
  [sym_expr_reference] = "expr_reference",
  [sym_word_lit] = "word_lit",
  [sym_bool] = "bool",
  [sym__expr_list] = "_expr_list",
  [sym_param_list] = "param_list",
  [sym_arg] = "arg",
  [sym_type] = "type",
  [sym_type_word] = "type_word",
  [sym_word] = "word",
  [aux_sym_package_repeat1] = "package_repeat1",
  [aux_sym_package_repeat2] = "package_repeat2",
  [aux_sym_moddef_repeat1] = "moddef_repeat1",
  [aux_sym_structdef_repeat1] = "structdef_repeat1",
  [aux_sym_uniondef_repeat1] = "uniondef_repeat1",
  [aux_sym_enumdef_repeat1] = "enumdef_repeat1",
  [aux_sym_socketdef_repeat1] = "socketdef_repeat1",
  [aux_sym_expr_if_repeat1] = "expr_if_repeat1",
  [aux_sym_expr_match_repeat1] = "expr_match_repeat1",
  [aux_sym_patlist_repeat1] = "patlist_repeat1",
  [aux_sym__expr_list_repeat1] = "_expr_list_repeat1",
  [aux_sym_param_list_repeat1] = "param_list_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_import] = anon_sym_import,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_pub] = anon_sym_pub,
  [anon_sym_ext] = anon_sym_ext,
  [anon_sym_mod] = anon_sym_mod,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_builtin] = anon_sym_builtin,
  [anon_sym_type] = anon_sym_type,
  [anon_sym_struct] = anon_sym_struct,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_union] = anon_sym_union,
  [anon_sym_enum] = anon_sym_enum,
  [anon_sym_width] = anon_sym_width,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_fn] = anon_sym_fn,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_DASH_GT] = anon_sym_DASH_GT,
  [anon_sym_socket] = anon_sym_socket,
  [anon_sym_mosi] = anon_sym_mosi,
  [anon_sym_miso] = anon_sym_miso,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_implicit] = anon_sym_implicit,
  [anon_sym_incoming] = anon_sym_incoming,
  [anon_sym_outgoing] = anon_sym_outgoing,
  [anon_sym_wire] = anon_sym_wire,
  [anon_sym_reg] = anon_sym_reg,
  [anon_sym_on] = anon_sym_on,
  [anon_sym_of] = anon_sym_of,
  [anon_sym_master] = anon_sym_master,
  [anon_sym_slave] = anon_sym_slave,
  [sym_direct] = sym_direct,
  [sym_latched] = sym_latched,
  [anon_sym_if] = anon_sym_if,
  [anon_sym_else] = anon_sym_else,
  [anon_sym_match] = anon_sym_match,
  [anon_sym_EQ_GT] = anon_sym_EQ_GT,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_DOT_DOT] = anon_sym_DOT_DOT,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [sym_type_clock] = sym_type_clock,
  [anon_sym_Word] = anon_sym_Word,
  [sym_type_bit] = sym_type_bit,
  [sym_path] = sym_path,
  [aux_sym_word_token1] = aux_sym_word_token1,
  [aux_sym_word_token2] = aux_sym_word_token2,
  [aux_sym_word_token3] = aux_sym_word_token3,
  [sym_nat] = sym_nat,
  [sym_enumerant] = sym_enumerant,
  [sym_ctor] = sym_ctor,
  [sym_qualident] = sym_qualident,
  [sym_ident] = sym_ident,
  [sym_comment_line] = sym_comment_line,
  [sym_comment_block] = sym_comment_block,
  [sym_package] = sym_package,
  [sym_package_import] = sym_package_import,
  [sym_item] = sym_item,
  [sym_moddef] = sym_moddef,
  [sym_builtindef] = sym_builtindef,
  [sym_structdef] = sym_structdef,
  [sym_field] = sym_field,
  [sym_uniondef] = sym_uniondef,
  [sym_enumdef] = sym_enumdef,
  [sym_enumdef_statement] = sym_enumdef_statement,
  [sym_fndef] = sym_fndef,
  [sym_alt] = sym_alt,
  [sym_socketdef] = sym_socketdef,
  [sym_channel] = sym_channel,
  [sym_channeldir] = sym_channeldir,
  [sym__decl] = sym__decl,
  [sym__component] = sym__component,
  [sym_implicit] = sym_implicit,
  [sym_incoming] = sym_incoming,
  [sym_outgoing] = sym_outgoing,
  [sym_wire] = sym_wire,
  [sym_reg] = sym_reg,
  [sym_socket] = sym_socket,
  [sym_socket_role] = sym_socket_role,
  [sym_connect] = sym_connect,
  [sym_submodule] = sym_submodule,
  [sym_connect_type] = sym_connect_type,
  [sym_expr] = sym_expr,
  [sym_expr_if] = sym_expr_if,
  [sym_expr_match] = sym_expr_match,
  [sym_match_arm] = sym_match_arm,
  [sym_pat] = sym_pat,
  [sym_patlist] = sym_patlist,
  [sym_expr_call] = sym_expr_call,
  [sym_expr_idx] = sym_expr_idx,
  [sym_expr_lit] = sym_expr_lit,
  [sym_expr_reference] = sym_expr_reference,
  [sym_word_lit] = sym_word_lit,
  [sym_bool] = sym_bool,
  [sym__expr_list] = sym__expr_list,
  [sym_param_list] = sym_param_list,
  [sym_arg] = sym_arg,
  [sym_type] = sym_type,
  [sym_type_word] = sym_type_word,
  [sym_word] = sym_word,
  [aux_sym_package_repeat1] = aux_sym_package_repeat1,
  [aux_sym_package_repeat2] = aux_sym_package_repeat2,
  [aux_sym_moddef_repeat1] = aux_sym_moddef_repeat1,
  [aux_sym_structdef_repeat1] = aux_sym_structdef_repeat1,
  [aux_sym_uniondef_repeat1] = aux_sym_uniondef_repeat1,
  [aux_sym_enumdef_repeat1] = aux_sym_enumdef_repeat1,
  [aux_sym_socketdef_repeat1] = aux_sym_socketdef_repeat1,
  [aux_sym_expr_if_repeat1] = aux_sym_expr_if_repeat1,
  [aux_sym_expr_match_repeat1] = aux_sym_expr_match_repeat1,
  [aux_sym_patlist_repeat1] = aux_sym_patlist_repeat1,
  [aux_sym__expr_list_repeat1] = aux_sym__expr_list_repeat1,
  [aux_sym_param_list_repeat1] = aux_sym_param_list_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_import] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_pub] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ext] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_mod] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_builtin] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_type] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_struct] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_union] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_enum] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_width] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_fn] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_socket] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_mosi] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_miso] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_implicit] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_incoming] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_outgoing] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_wire] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_reg] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_on] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_of] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_master] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_slave] = {
    .visible = true,
    .named = false,
  },
  [sym_direct] = {
    .visible = true,
    .named = true,
  },
  [sym_latched] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_if] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_else] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_match] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT_DOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_true] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_false] = {
    .visible = true,
    .named = false,
  },
  [sym_type_clock] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_Word] = {
    .visible = true,
    .named = false,
  },
  [sym_type_bit] = {
    .visible = true,
    .named = true,
  },
  [sym_path] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_word_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_word_token2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_word_token3] = {
    .visible = false,
    .named = false,
  },
  [sym_nat] = {
    .visible = true,
    .named = true,
  },
  [sym_enumerant] = {
    .visible = true,
    .named = true,
  },
  [sym_ctor] = {
    .visible = true,
    .named = true,
  },
  [sym_qualident] = {
    .visible = true,
    .named = true,
  },
  [sym_ident] = {
    .visible = true,
    .named = true,
  },
  [sym_comment_line] = {
    .visible = true,
    .named = true,
  },
  [sym_comment_block] = {
    .visible = true,
    .named = true,
  },
  [sym_package] = {
    .visible = true,
    .named = true,
  },
  [sym_package_import] = {
    .visible = true,
    .named = true,
  },
  [sym_item] = {
    .visible = true,
    .named = true,
  },
  [sym_moddef] = {
    .visible = true,
    .named = true,
  },
  [sym_builtindef] = {
    .visible = true,
    .named = true,
  },
  [sym_structdef] = {
    .visible = true,
    .named = true,
  },
  [sym_field] = {
    .visible = true,
    .named = true,
  },
  [sym_uniondef] = {
    .visible = true,
    .named = true,
  },
  [sym_enumdef] = {
    .visible = true,
    .named = true,
  },
  [sym_enumdef_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_fndef] = {
    .visible = true,
    .named = true,
  },
  [sym_alt] = {
    .visible = true,
    .named = true,
  },
  [sym_socketdef] = {
    .visible = true,
    .named = true,
  },
  [sym_channel] = {
    .visible = true,
    .named = true,
  },
  [sym_channeldir] = {
    .visible = true,
    .named = true,
  },
  [sym__decl] = {
    .visible = false,
    .named = true,
  },
  [sym__component] = {
    .visible = false,
    .named = true,
  },
  [sym_implicit] = {
    .visible = true,
    .named = true,
  },
  [sym_incoming] = {
    .visible = true,
    .named = true,
  },
  [sym_outgoing] = {
    .visible = true,
    .named = true,
  },
  [sym_wire] = {
    .visible = true,
    .named = true,
  },
  [sym_reg] = {
    .visible = true,
    .named = true,
  },
  [sym_socket] = {
    .visible = true,
    .named = true,
  },
  [sym_socket_role] = {
    .visible = true,
    .named = true,
  },
  [sym_connect] = {
    .visible = true,
    .named = true,
  },
  [sym_submodule] = {
    .visible = true,
    .named = true,
  },
  [sym_connect_type] = {
    .visible = true,
    .named = true,
  },
  [sym_expr] = {
    .visible = true,
    .named = true,
  },
  [sym_expr_if] = {
    .visible = true,
    .named = true,
  },
  [sym_expr_match] = {
    .visible = true,
    .named = true,
  },
  [sym_match_arm] = {
    .visible = true,
    .named = true,
  },
  [sym_pat] = {
    .visible = true,
    .named = true,
  },
  [sym_patlist] = {
    .visible = true,
    .named = true,
  },
  [sym_expr_call] = {
    .visible = true,
    .named = true,
  },
  [sym_expr_idx] = {
    .visible = true,
    .named = true,
  },
  [sym_expr_lit] = {
    .visible = true,
    .named = true,
  },
  [sym_expr_reference] = {
    .visible = true,
    .named = true,
  },
  [sym_word_lit] = {
    .visible = true,
    .named = true,
  },
  [sym_bool] = {
    .visible = true,
    .named = true,
  },
  [sym__expr_list] = {
    .visible = false,
    .named = true,
  },
  [sym_param_list] = {
    .visible = true,
    .named = true,
  },
  [sym_arg] = {
    .visible = true,
    .named = true,
  },
  [sym_type] = {
    .visible = true,
    .named = true,
  },
  [sym_type_word] = {
    .visible = true,
    .named = true,
  },
  [sym_word] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_package_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_package_repeat2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_moddef_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_structdef_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_uniondef_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_enumdef_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_socketdef_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_expr_if_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_expr_match_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_patlist_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__expr_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_param_list_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_args = 1,
  field_connect_type = 2,
  field_expr = 3,
  field_method = 4,
  field_module = 5,
  field_name = 6,
  field_on = 7,
  field_role = 8,
  field_socketdef = 9,
  field_subject = 10,
  field_target = 11,
  field_type = 12,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_args] = "args",
  [field_connect_type] = "connect_type",
  [field_expr] = "expr",
  [field_method] = "method",
  [field_module] = "module",
  [field_name] = "name",
  [field_on] = "on",
  [field_role] = "role",
  [field_socketdef] = "socketdef",
  [field_subject] = "subject",
  [field_target] = "target",
  [field_type] = "type",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 1},
  [4] = {.index = 3, .length = 3},
  [5] = {.index = 6, .length = 2},
  [6] = {.index = 8, .length = 2},
  [7] = {.index = 10, .length = 3},
  [8] = {.index = 13, .length = 3},
  [9] = {.index = 16, .length = 1},
  [10] = {.index = 17, .length = 2},
  [11] = {.index = 19, .length = 3},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_name, 1},
  [1] =
    {field_name, 2},
  [2] =
    {field_name, 3},
  [3] =
    {field_connect_type, 1},
    {field_expr, 2},
    {field_target, 0},
  [6] =
    {field_module, 3},
    {field_name, 1},
  [8] =
    {field_name, 1},
    {field_type, 3},
  [10] =
    {field_name, 1},
    {field_on, 4},
    {field_type, 3},
  [13] =
    {field_name, 2},
    {field_role, 0},
    {field_socketdef, 4},
  [16] =
    {field_args, 2},
  [17] =
    {field_method, 2},
    {field_subject, 0},
  [19] =
    {field_args, 4},
    {field_method, 2},
    {field_subject, 0},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 81,
  [82] = 82,
  [83] = 83,
  [84] = 84,
  [85] = 85,
  [86] = 86,
  [87] = 87,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 91,
  [92] = 92,
  [93] = 93,
  [94] = 94,
  [95] = 95,
  [96] = 96,
  [97] = 97,
  [98] = 98,
  [99] = 99,
  [100] = 100,
  [101] = 101,
  [102] = 102,
  [103] = 103,
  [104] = 104,
  [105] = 105,
  [106] = 106,
  [107] = 107,
  [108] = 108,
  [109] = 109,
  [110] = 110,
  [111] = 111,
  [112] = 112,
  [113] = 113,
  [114] = 114,
  [115] = 115,
  [116] = 116,
  [117] = 117,
  [118] = 118,
  [119] = 119,
  [120] = 120,
  [121] = 121,
  [122] = 122,
  [123] = 123,
  [124] = 124,
  [125] = 125,
  [126] = 126,
  [127] = 127,
  [128] = 128,
  [129] = 129,
  [130] = 130,
  [131] = 131,
  [132] = 132,
  [133] = 133,
  [134] = 134,
  [135] = 135,
  [136] = 136,
  [137] = 137,
  [138] = 138,
  [139] = 139,
  [140] = 140,
  [141] = 141,
  [142] = 142,
  [143] = 143,
  [144] = 144,
  [145] = 145,
  [146] = 146,
  [147] = 147,
  [148] = 148,
  [149] = 149,
  [150] = 150,
  [151] = 151,
  [152] = 152,
  [153] = 153,
  [154] = 154,
  [155] = 155,
  [156] = 156,
  [157] = 157,
  [158] = 158,
  [159] = 159,
  [160] = 160,
  [161] = 161,
  [162] = 162,
  [163] = 163,
  [164] = 164,
  [165] = 165,
  [166] = 166,
  [167] = 167,
  [168] = 168,
  [169] = 169,
  [170] = 170,
  [171] = 171,
  [172] = 172,
  [173] = 173,
  [174] = 174,
  [175] = 175,
  [176] = 176,
  [177] = 177,
  [178] = 178,
  [179] = 179,
  [180] = 180,
  [181] = 181,
  [182] = 182,
  [183] = 183,
  [184] = 184,
  [185] = 185,
  [186] = 186,
  [187] = 187,
  [188] = 188,
  [189] = 189,
  [190] = 190,
  [191] = 191,
  [192] = 192,
  [193] = 193,
  [194] = 194,
  [195] = 195,
  [196] = 196,
  [197] = 197,
  [198] = 198,
  [199] = 199,
  [200] = 200,
  [201] = 201,
  [202] = 202,
  [203] = 203,
  [204] = 204,
  [205] = 205,
  [206] = 206,
  [207] = 207,
  [208] = 208,
  [209] = 209,
  [210] = 210,
  [211] = 211,
  [212] = 212,
  [213] = 213,
  [214] = 214,
  [215] = 215,
  [216] = 216,
  [217] = 217,
  [218] = 218,
  [219] = 219,
  [220] = 220,
  [221] = 221,
  [222] = 222,
  [223] = 223,
  [224] = 224,
  [225] = 225,
  [226] = 226,
  [227] = 227,
  [228] = 228,
  [229] = 229,
  [230] = 230,
  [231] = 231,
  [232] = 232,
  [233] = 233,
  [234] = 234,
  [235] = 235,
  [236] = 236,
  [237] = 237,
  [238] = 238,
  [239] = 239,
  [240] = 240,
  [241] = 241,
  [242] = 242,
  [243] = 243,
  [244] = 244,
  [245] = 245,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(114);
      ADVANCE_MAP(
        '#', 110,
        '(', 134,
        ')', 135,
        ',', 140,
        '-', 15,
        '.', 8,
        '/', 5,
        '0', 233,
        ':', 127,
        ';', 116,
        '<', 14,
        '=', 132,
        '@', 111,
        'B', 47,
        'C', 61,
        'W', 72,
        '[', 167,
        ']', 168,
        'b', 101,
        'e', 59,
        'f', 19,
        'i', 39,
        'm', 17,
        'o', 40,
        'p', 99,
        'r', 30,
        's', 60,
        't', 82,
        'u', 70,
        'w', 48,
        '{', 121,
        '}', 122,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(234);
      END_STATE();
    case 1:
      ADVANCE_MAP(
        '#', 110,
        '(', 134,
        ')', 135,
        ',', 140,
        '-', 15,
        '/', 5,
        '0', 233,
        ':', 126,
        ';', 116,
        '=', 16,
        '@', 111,
        '[', 167,
        'f', 180,
        'i', 194,
        'm', 181,
        't', 216,
        '{', 121,
        '}', 122,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(234);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 2:
      if (lookahead == '#') ADVANCE(110);
      if (lookahead == ')') ADVANCE(135);
      if (lookahead == '/') ADVANCE(5);
      if (lookahead == '@') ADVANCE(111);
      if (lookahead == 'e') ADVANCE(251);
      if (lookahead == '}') ADVANCE(122);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(253);
      END_STATE();
    case 3:
      if (lookahead == ')') ADVANCE(135);
      if (lookahead == ',') ADVANCE(140);
      if (lookahead == '/') ADVANCE(5);
      if (lookahead == ';') ADVANCE(116);
      if (lookahead == 'o') ADVANCE(210);
      if (lookahead == '{') ADVANCE(121);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 4:
      if (lookahead == ')') ADVANCE(135);
      if (lookahead == '/') ADVANCE(5);
      if (lookahead == '}') ADVANCE(122);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(4);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(253);
      END_STATE();
    case 5:
      if (lookahead == '*') ADVANCE(7);
      if (lookahead == '/') ADVANCE(254);
      END_STATE();
    case 6:
      if (lookahead == '*') ADVANCE(6);
      if (lookahead == '/') ADVANCE(255);
      if (lookahead != 0) ADVANCE(7);
      END_STATE();
    case 7:
      if (lookahead == '*') ADVANCE(6);
      if (lookahead != 0) ADVANCE(7);
      END_STATE();
    case 8:
      if (lookahead == '.') ADVANCE(169);
      END_STATE();
    case 9:
      ADVANCE_MAP(
        '/', 5,
        ':', 13,
        '<', 14,
        '=', 131,
        'i', 208,
        'm', 183,
        'o', 226,
        'r', 190,
        's', 207,
        'w', 201,
        '}', 122,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(9);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(236);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 10:
      if (lookahead == '/') ADVANCE(5);
      if (lookahead == 'B') ADVANCE(241);
      if (lookahead == 'C') ADVANCE(243);
      if (lookahead == 'W') ADVANCE(244);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(10);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(248);
      END_STATE();
    case 11:
      if (lookahead == '/') ADVANCE(5);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(11);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(248);
      END_STATE();
    case 12:
      if (lookahead == ':') ADVANCE(113);
      END_STATE();
    case 13:
      if (lookahead == '=') ADVANCE(158);
      END_STATE();
    case 14:
      if (lookahead == '=') ADVANCE(159);
      END_STATE();
    case 15:
      if (lookahead == '>') ADVANCE(136);
      END_STATE();
    case 16:
      if (lookahead == '>') ADVANCE(166);
      END_STATE();
    case 17:
      if (lookahead == 'a') ADVANCE(87);
      if (lookahead == 'i') ADVANCE(86);
      if (lookahead == 'o') ADVANCE(27);
      END_STATE();
    case 18:
      if (lookahead == 'a') ADVANCE(104);
      END_STATE();
    case 19:
      if (lookahead == 'a') ADVANCE(64);
      if (lookahead == 'n') ADVANCE(133);
      END_STATE();
    case 20:
      if (lookahead == 'b') ADVANCE(117);
      END_STATE();
    case 21:
      if (lookahead == 'c') ADVANCE(58);
      END_STATE();
    case 22:
      if (lookahead == 'c') ADVANCE(45);
      END_STATE();
    case 23:
      if (lookahead == 'c') ADVANCE(57);
      END_STATE();
    case 24:
      if (lookahead == 'c') ADVANCE(75);
      END_STATE();
    case 25:
      if (lookahead == 'c') ADVANCE(93);
      END_STATE();
    case 26:
      if (lookahead == 'c') ADVANCE(56);
      END_STATE();
    case 27:
      if (lookahead == 'd') ADVANCE(119);
      if (lookahead == 's') ADVANCE(49);
      END_STATE();
    case 28:
      if (lookahead == 'd') ADVANCE(176);
      END_STATE();
    case 29:
      if (lookahead == 'd') ADVANCE(96);
      if (lookahead == 'r') ADVANCE(34);
      END_STATE();
    case 30:
      if (lookahead == 'e') ADVANCE(41);
      END_STATE();
    case 31:
      if (lookahead == 'e') ADVANCE(162);
      END_STATE();
    case 32:
      if (lookahead == 'e') ADVANCE(170);
      END_STATE();
    case 33:
      if (lookahead == 'e') ADVANCE(124);
      END_STATE();
    case 34:
      if (lookahead == 'e') ADVANCE(147);
      END_STATE();
    case 35:
      if (lookahead == 'e') ADVANCE(172);
      END_STATE();
    case 36:
      if (lookahead == 'e') ADVANCE(156);
      END_STATE();
    case 37:
      if (lookahead == 'e') ADVANCE(81);
      END_STATE();
    case 38:
      if (lookahead == 'e') ADVANCE(92);
      END_STATE();
    case 39:
      if (lookahead == 'f') ADVANCE(160);
      if (lookahead == 'm') ADVANCE(78);
      if (lookahead == 'n') ADVANCE(24);
      END_STATE();
    case 40:
      if (lookahead == 'f') ADVANCE(153);
      if (lookahead == 'n') ADVANCE(151);
      if (lookahead == 'u') ADVANCE(95);
      END_STATE();
    case 41:
      if (lookahead == 'g') ADVANCE(149);
      END_STATE();
    case 42:
      if (lookahead == 'g') ADVANCE(143);
      END_STATE();
    case 43:
      if (lookahead == 'g') ADVANCE(145);
      END_STATE();
    case 44:
      if (lookahead == 'g') ADVANCE(77);
      END_STATE();
    case 45:
      if (lookahead == 'h') ADVANCE(164);
      END_STATE();
    case 46:
      if (lookahead == 'h') ADVANCE(130);
      END_STATE();
    case 47:
      if (lookahead == 'i') ADVANCE(89);
      END_STATE();
    case 48:
      if (lookahead == 'i') ADVANCE(29);
      END_STATE();
    case 49:
      if (lookahead == 'i') ADVANCE(138);
      END_STATE();
    case 50:
      if (lookahead == 'i') ADVANCE(63);
      END_STATE();
    case 51:
      if (lookahead == 'i') ADVANCE(68);
      END_STATE();
    case 52:
      if (lookahead == 'i') ADVANCE(69);
      END_STATE();
    case 53:
      if (lookahead == 'i') ADVANCE(74);
      END_STATE();
    case 54:
      if (lookahead == 'i') ADVANCE(71);
      END_STATE();
    case 55:
      if (lookahead == 'i') ADVANCE(26);
      END_STATE();
    case 56:
      if (lookahead == 'i') ADVANCE(94);
      END_STATE();
    case 57:
      if (lookahead == 'k') ADVANCE(174);
      END_STATE();
    case 58:
      if (lookahead == 'k') ADVANCE(38);
      END_STATE();
    case 59:
      if (lookahead == 'l') ADVANCE(85);
      if (lookahead == 'n') ADVANCE(100);
      if (lookahead == 'x') ADVANCE(90);
      END_STATE();
    case 60:
      if (lookahead == 'l') ADVANCE(18);
      if (lookahead == 'o') ADVANCE(21);
      if (lookahead == 't') ADVANCE(83);
      END_STATE();
    case 61:
      if (lookahead == 'l') ADVANCE(76);
      END_STATE();
    case 62:
      if (lookahead == 'l') ADVANCE(55);
      if (lookahead == 'o') ADVANCE(84);
      END_STATE();
    case 63:
      if (lookahead == 'l') ADVANCE(97);
      END_STATE();
    case 64:
      if (lookahead == 'l') ADVANCE(88);
      END_STATE();
    case 65:
      if (lookahead == 'm') ADVANCE(129);
      END_STATE();
    case 66:
      if (lookahead == 'm') ADVANCE(52);
      END_STATE();
    case 67:
      if (lookahead == 'n') ADVANCE(128);
      END_STATE();
    case 68:
      if (lookahead == 'n') ADVANCE(123);
      END_STATE();
    case 69:
      if (lookahead == 'n') ADVANCE(42);
      END_STATE();
    case 70:
      if (lookahead == 'n') ADVANCE(53);
      END_STATE();
    case 71:
      if (lookahead == 'n') ADVANCE(43);
      END_STATE();
    case 72:
      if (lookahead == 'o') ADVANCE(80);
      END_STATE();
    case 73:
      if (lookahead == 'o') ADVANCE(139);
      END_STATE();
    case 74:
      if (lookahead == 'o') ADVANCE(67);
      END_STATE();
    case 75:
      if (lookahead == 'o') ADVANCE(66);
      END_STATE();
    case 76:
      if (lookahead == 'o') ADVANCE(23);
      END_STATE();
    case 77:
      if (lookahead == 'o') ADVANCE(54);
      END_STATE();
    case 78:
      if (lookahead == 'p') ADVANCE(62);
      END_STATE();
    case 79:
      if (lookahead == 'p') ADVANCE(33);
      END_STATE();
    case 80:
      if (lookahead == 'r') ADVANCE(28);
      END_STATE();
    case 81:
      if (lookahead == 'r') ADVANCE(154);
      END_STATE();
    case 82:
      if (lookahead == 'r') ADVANCE(102);
      if (lookahead == 'y') ADVANCE(79);
      END_STATE();
    case 83:
      if (lookahead == 'r') ADVANCE(103);
      END_STATE();
    case 84:
      if (lookahead == 'r') ADVANCE(91);
      END_STATE();
    case 85:
      if (lookahead == 's') ADVANCE(31);
      END_STATE();
    case 86:
      if (lookahead == 's') ADVANCE(73);
      END_STATE();
    case 87:
      if (lookahead == 's') ADVANCE(98);
      if (lookahead == 't') ADVANCE(22);
      END_STATE();
    case 88:
      if (lookahead == 's') ADVANCE(35);
      END_STATE();
    case 89:
      if (lookahead == 't') ADVANCE(178);
      END_STATE();
    case 90:
      if (lookahead == 't') ADVANCE(118);
      END_STATE();
    case 91:
      if (lookahead == 't') ADVANCE(115);
      END_STATE();
    case 92:
      if (lookahead == 't') ADVANCE(137);
      END_STATE();
    case 93:
      if (lookahead == 't') ADVANCE(125);
      END_STATE();
    case 94:
      if (lookahead == 't') ADVANCE(141);
      END_STATE();
    case 95:
      if (lookahead == 't') ADVANCE(44);
      END_STATE();
    case 96:
      if (lookahead == 't') ADVANCE(46);
      END_STATE();
    case 97:
      if (lookahead == 't') ADVANCE(51);
      END_STATE();
    case 98:
      if (lookahead == 't') ADVANCE(37);
      END_STATE();
    case 99:
      if (lookahead == 'u') ADVANCE(20);
      END_STATE();
    case 100:
      if (lookahead == 'u') ADVANCE(65);
      END_STATE();
    case 101:
      if (lookahead == 'u') ADVANCE(50);
      END_STATE();
    case 102:
      if (lookahead == 'u') ADVANCE(32);
      END_STATE();
    case 103:
      if (lookahead == 'u') ADVANCE(25);
      END_STATE();
    case 104:
      if (lookahead == 'v') ADVANCE(36);
      END_STATE();
    case 105:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(229);
      END_STATE();
    case 106:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(235);
      END_STATE();
    case 107:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(230);
      END_STATE();
    case 108:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(232);
      END_STATE();
    case 109:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(231);
      END_STATE();
    case 110:
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(237);
      END_STATE();
    case 111:
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 112:
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 113:
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(anon_sym_import);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(anon_sym_pub);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(anon_sym_ext);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_mod);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(anon_sym_mod);
      if (lookahead == '.') ADVANCE(112);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(anon_sym_builtin);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(anon_sym_type);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(anon_sym_struct);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == '=') ADVANCE(158);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(anon_sym_union);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(anon_sym_enum);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(anon_sym_width);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '>') ADVANCE(166);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(anon_sym_fn);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(anon_sym_socket);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(anon_sym_mosi);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(anon_sym_miso);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(anon_sym_implicit);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(anon_sym_implicit);
      if (lookahead == '.') ADVANCE(112);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(anon_sym_incoming);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(anon_sym_incoming);
      if (lookahead == '.') ADVANCE(112);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(anon_sym_outgoing);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(anon_sym_outgoing);
      if (lookahead == '.') ADVANCE(112);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(anon_sym_wire);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(anon_sym_wire);
      if (lookahead == '.') ADVANCE(112);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(anon_sym_reg);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(anon_sym_reg);
      if (lookahead == '.') ADVANCE(112);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(anon_sym_on);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(anon_sym_on);
      if (lookahead == '.') ADVANCE(112);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(anon_sym_of);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(anon_sym_master);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(anon_sym_master);
      if (lookahead == '.') ADVANCE(112);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(anon_sym_slave);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(anon_sym_slave);
      if (lookahead == '.') ADVANCE(112);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(sym_direct);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(sym_latched);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(anon_sym_if);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(anon_sym_if);
      if (lookahead == '.') ADVANCE(112);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(anon_sym_else);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(anon_sym_else);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(253);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(anon_sym_match);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(anon_sym_match);
      if (lookahead == '.') ADVANCE(112);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(anon_sym_EQ_GT);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(anon_sym_DOT_DOT);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(anon_sym_true);
      if (lookahead == '.') ADVANCE(112);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(anon_sym_false);
      if (lookahead == '.') ADVANCE(112);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(sym_type_clock);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(sym_type_clock);
      if (lookahead == ':') ADVANCE(12);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(248);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(anon_sym_Word);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(anon_sym_Word);
      if (lookahead == ':') ADVANCE(12);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(248);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(sym_type_bit);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(sym_type_bit);
      if (lookahead == ':') ADVANCE(12);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(248);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'a') ADVANCE(205);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'a') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'a') ADVANCE(227);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'a') ADVANCE(220);
      if (lookahead == 'o') ADVANCE(187);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'c') ADVANCE(199);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'c') ADVANCE(213);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'c') ADVANCE(203);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'd') ADVANCE(120);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'e') ADVANCE(171);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'e') ADVANCE(173);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'e') ADVANCE(195);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'e') ADVANCE(148);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'e') ADVANCE(157);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'e') ADVANCE(217);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'f') ADVANCE(161);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'g') ADVANCE(150);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'g') ADVANCE(144);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'g') ADVANCE(146);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'g') ADVANCE(214);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'h') ADVANCE(165);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'i') ADVANCE(211);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'i') ADVANCE(218);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'i') ADVANCE(186);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'i') ADVANCE(222);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'i') ADVANCE(212);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'l') ADVANCE(219);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'l') ADVANCE(202);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'l') ADVANCE(182);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'm') ADVANCE(215);
      if (lookahead == 'n') ADVANCE(185);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'm') ADVANCE(200);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'n') ADVANCE(152);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'n') ADVANCE(196);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'n') ADVANCE(197);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'o') ADVANCE(209);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'o') ADVANCE(204);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'p') ADVANCE(206);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'r') ADVANCE(225);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'r') ADVANCE(155);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'r') ADVANCE(191);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 's') ADVANCE(189);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 's') ADVANCE(224);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 't') ADVANCE(184);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 't') ADVANCE(142);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 't') ADVANCE(198);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 't') ADVANCE(193);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'u') ADVANCE(188);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'u') ADVANCE(223);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (lookahead == 'v') ADVANCE(192);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(sym_path);
      if (lookahead == '.') ADVANCE(112);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(aux_sym_word_token1);
      if (lookahead == 'w') ADVANCE(107);
      if (lookahead == '0' ||
          lookahead == '1' ||
          lookahead == '_') ADVANCE(229);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(aux_sym_word_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(230);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(aux_sym_word_token2);
      if (lookahead == 'w') ADVANCE(108);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(231);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(aux_sym_word_token2);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(232);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(aux_sym_word_token3);
      if (lookahead == 'b') ADVANCE(105);
      if (lookahead == 'w') ADVANCE(106);
      if (lookahead == 'x') ADVANCE(109);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(234);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(aux_sym_word_token3);
      if (lookahead == 'w') ADVANCE(106);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(234);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(aux_sym_word_token3);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(235);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(sym_nat);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(236);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(sym_enumerant);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(237);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(sym_ctor);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(sym_qualident);
      if (lookahead == ':') ADVANCE(12);
      if (lookahead == 'c') ADVANCE(242);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(248);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(sym_qualident);
      if (lookahead == ':') ADVANCE(12);
      if (lookahead == 'd') ADVANCE(177);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(248);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(sym_qualident);
      if (lookahead == ':') ADVANCE(12);
      if (lookahead == 'i') ADVANCE(247);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(248);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(sym_qualident);
      if (lookahead == ':') ADVANCE(12);
      if (lookahead == 'k') ADVANCE(175);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(248);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(sym_qualident);
      if (lookahead == ':') ADVANCE(12);
      if (lookahead == 'l') ADVANCE(245);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(248);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym_qualident);
      if (lookahead == ':') ADVANCE(12);
      if (lookahead == 'o') ADVANCE(246);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(248);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(sym_qualident);
      if (lookahead == ':') ADVANCE(12);
      if (lookahead == 'o') ADVANCE(239);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(248);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(sym_qualident);
      if (lookahead == ':') ADVANCE(12);
      if (lookahead == 'r') ADVANCE(240);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(248);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(sym_qualident);
      if (lookahead == ':') ADVANCE(12);
      if (lookahead == 't') ADVANCE(179);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(248);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(sym_qualident);
      if (lookahead == ':') ADVANCE(12);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(248);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(sym_qualident);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'e') ADVANCE(163);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(253);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'l') ADVANCE(252);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(253);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 's') ADVANCE(250);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(253);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(sym_ident);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(253);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(sym_comment_line);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(254);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(sym_comment_block);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 1},
  [3] = {.lex_state = 1},
  [4] = {.lex_state = 1},
  [5] = {.lex_state = 1},
  [6] = {.lex_state = 1},
  [7] = {.lex_state = 9},
  [8] = {.lex_state = 9},
  [9] = {.lex_state = 1},
  [10] = {.lex_state = 1},
  [11] = {.lex_state = 1},
  [12] = {.lex_state = 1},
  [13] = {.lex_state = 1},
  [14] = {.lex_state = 9},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 1},
  [17] = {.lex_state = 1},
  [18] = {.lex_state = 9},
  [19] = {.lex_state = 1},
  [20] = {.lex_state = 1},
  [21] = {.lex_state = 9},
  [22] = {.lex_state = 1},
  [23] = {.lex_state = 1},
  [24] = {.lex_state = 9},
  [25] = {.lex_state = 9},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 1},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 9},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 2},
  [52] = {.lex_state = 2},
  [53] = {.lex_state = 1},
  [54] = {.lex_state = 1},
  [55] = {.lex_state = 2},
  [56] = {.lex_state = 1},
  [57] = {.lex_state = 2},
  [58] = {.lex_state = 1},
  [59] = {.lex_state = 1},
  [60] = {.lex_state = 1},
  [61] = {.lex_state = 1},
  [62] = {.lex_state = 1},
  [63] = {.lex_state = 1},
  [64] = {.lex_state = 1},
  [65] = {.lex_state = 2},
  [66] = {.lex_state = 1},
  [67] = {.lex_state = 1},
  [68] = {.lex_state = 1},
  [69] = {.lex_state = 1},
  [70] = {.lex_state = 1},
  [71] = {.lex_state = 1},
  [72] = {.lex_state = 1},
  [73] = {.lex_state = 1},
  [74] = {.lex_state = 1},
  [75] = {.lex_state = 2},
  [76] = {.lex_state = 10},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 10},
  [79] = {.lex_state = 10},
  [80] = {.lex_state = 2},
  [81] = {.lex_state = 10},
  [82] = {.lex_state = 0},
  [83] = {.lex_state = 2},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 3},
  [86] = {.lex_state = 3},
  [87] = {.lex_state = 10},
  [88] = {.lex_state = 10},
  [89] = {.lex_state = 10},
  [90] = {.lex_state = 10},
  [91] = {.lex_state = 10},
  [92] = {.lex_state = 10},
  [93] = {.lex_state = 10},
  [94] = {.lex_state = 0},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 2},
  [97] = {.lex_state = 2},
  [98] = {.lex_state = 4},
  [99] = {.lex_state = 4},
  [100] = {.lex_state = 4},
  [101] = {.lex_state = 0},
  [102] = {.lex_state = 4},
  [103] = {.lex_state = 4},
  [104] = {.lex_state = 4},
  [105] = {.lex_state = 4},
  [106] = {.lex_state = 4},
  [107] = {.lex_state = 4},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 4},
  [110] = {.lex_state = 4},
  [111] = {.lex_state = 1},
  [112] = {.lex_state = 0},
  [113] = {.lex_state = 0},
  [114] = {.lex_state = 0},
  [115] = {.lex_state = 0},
  [116] = {.lex_state = 0},
  [117] = {.lex_state = 4},
  [118] = {.lex_state = 0},
  [119] = {.lex_state = 0},
  [120] = {.lex_state = 0},
  [121] = {.lex_state = 0},
  [122] = {.lex_state = 0},
  [123] = {.lex_state = 1},
  [124] = {.lex_state = 0},
  [125] = {.lex_state = 9},
  [126] = {.lex_state = 0},
  [127] = {.lex_state = 1},
  [128] = {.lex_state = 0},
  [129] = {.lex_state = 0},
  [130] = {.lex_state = 4},
  [131] = {.lex_state = 0},
  [132] = {.lex_state = 1},
  [133] = {.lex_state = 0},
  [134] = {.lex_state = 0},
  [135] = {.lex_state = 0},
  [136] = {.lex_state = 4},
  [137] = {.lex_state = 0},
  [138] = {.lex_state = 0},
  [139] = {.lex_state = 3},
  [140] = {.lex_state = 0},
  [141] = {.lex_state = 4},
  [142] = {.lex_state = 4},
  [143] = {.lex_state = 0},
  [144] = {.lex_state = 0},
  [145] = {.lex_state = 4},
  [146] = {.lex_state = 0},
  [147] = {.lex_state = 0},
  [148] = {.lex_state = 0},
  [149] = {.lex_state = 4},
  [150] = {.lex_state = 0},
  [151] = {.lex_state = 4},
  [152] = {.lex_state = 0},
  [153] = {.lex_state = 1},
  [154] = {.lex_state = 0},
  [155] = {.lex_state = 0},
  [156] = {.lex_state = 0},
  [157] = {.lex_state = 1},
  [158] = {.lex_state = 9},
  [159] = {.lex_state = 0},
  [160] = {.lex_state = 9},
  [161] = {.lex_state = 4},
  [162] = {.lex_state = 0},
  [163] = {.lex_state = 0},
  [164] = {.lex_state = 0},
  [165] = {.lex_state = 0},
  [166] = {.lex_state = 4},
  [167] = {.lex_state = 0},
  [168] = {.lex_state = 1},
  [169] = {.lex_state = 0},
  [170] = {.lex_state = 9},
  [171] = {.lex_state = 0},
  [172] = {.lex_state = 0},
  [173] = {.lex_state = 0},
  [174] = {.lex_state = 0},
  [175] = {.lex_state = 0},
  [176] = {.lex_state = 0},
  [177] = {.lex_state = 0},
  [178] = {.lex_state = 0},
  [179] = {.lex_state = 0},
  [180] = {.lex_state = 4},
  [181] = {.lex_state = 4},
  [182] = {.lex_state = 0},
  [183] = {.lex_state = 0},
  [184] = {.lex_state = 1},
  [185] = {.lex_state = 4},
  [186] = {.lex_state = 0},
  [187] = {.lex_state = 4},
  [188] = {.lex_state = 4},
  [189] = {.lex_state = 4},
  [190] = {.lex_state = 4},
  [191] = {.lex_state = 0},
  [192] = {.lex_state = 9},
  [193] = {.lex_state = 1},
  [194] = {.lex_state = 0},
  [195] = {.lex_state = 0},
  [196] = {.lex_state = 0},
  [197] = {.lex_state = 1},
  [198] = {.lex_state = 9},
  [199] = {.lex_state = 0},
  [200] = {.lex_state = 0},
  [201] = {.lex_state = 0},
  [202] = {.lex_state = 0},
  [203] = {.lex_state = 4},
  [204] = {.lex_state = 0},
  [205] = {.lex_state = 0},
  [206] = {.lex_state = 4},
  [207] = {.lex_state = 0},
  [208] = {.lex_state = 4},
  [209] = {.lex_state = 0},
  [210] = {.lex_state = 0},
  [211] = {.lex_state = 0},
  [212] = {.lex_state = 4},
  [213] = {.lex_state = 0},
  [214] = {.lex_state = 0},
  [215] = {.lex_state = 0},
  [216] = {.lex_state = 1},
  [217] = {.lex_state = 1},
  [218] = {.lex_state = 0},
  [219] = {.lex_state = 4},
  [220] = {.lex_state = 4},
  [221] = {.lex_state = 0},
  [222] = {.lex_state = 4},
  [223] = {.lex_state = 0},
  [224] = {.lex_state = 0},
  [225] = {.lex_state = 0},
  [226] = {.lex_state = 4},
  [227] = {.lex_state = 0},
  [228] = {.lex_state = 0},
  [229] = {.lex_state = 4},
  [230] = {.lex_state = 0},
  [231] = {.lex_state = 4},
  [232] = {.lex_state = 0},
  [233] = {.lex_state = 0},
  [234] = {.lex_state = 0},
  [235] = {.lex_state = 0},
  [236] = {.lex_state = 0},
  [237] = {.lex_state = 0},
  [238] = {.lex_state = 11},
  [239] = {.lex_state = 0},
  [240] = {.lex_state = 1},
  [241] = {.lex_state = 4},
  [242] = {.lex_state = 0},
  [243] = {.lex_state = 0},
  [244] = {.lex_state = 0},
  [245] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_import] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_pub] = ACTIONS(1),
    [anon_sym_ext] = ACTIONS(1),
    [anon_sym_mod] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_builtin] = ACTIONS(1),
    [anon_sym_type] = ACTIONS(1),
    [anon_sym_struct] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_union] = ACTIONS(1),
    [anon_sym_enum] = ACTIONS(1),
    [anon_sym_width] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_fn] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_DASH_GT] = ACTIONS(1),
    [anon_sym_socket] = ACTIONS(1),
    [anon_sym_mosi] = ACTIONS(1),
    [anon_sym_miso] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_implicit] = ACTIONS(1),
    [anon_sym_incoming] = ACTIONS(1),
    [anon_sym_outgoing] = ACTIONS(1),
    [anon_sym_wire] = ACTIONS(1),
    [anon_sym_reg] = ACTIONS(1),
    [anon_sym_on] = ACTIONS(1),
    [anon_sym_of] = ACTIONS(1),
    [anon_sym_master] = ACTIONS(1),
    [anon_sym_slave] = ACTIONS(1),
    [sym_direct] = ACTIONS(1),
    [sym_latched] = ACTIONS(1),
    [anon_sym_if] = ACTIONS(1),
    [anon_sym_else] = ACTIONS(1),
    [anon_sym_match] = ACTIONS(1),
    [anon_sym_EQ_GT] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_DOT_DOT] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [sym_type_clock] = ACTIONS(1),
    [anon_sym_Word] = ACTIONS(1),
    [sym_type_bit] = ACTIONS(1),
    [aux_sym_word_token1] = ACTIONS(1),
    [aux_sym_word_token2] = ACTIONS(1),
    [aux_sym_word_token3] = ACTIONS(1),
    [sym_nat] = ACTIONS(1),
    [sym_enumerant] = ACTIONS(1),
    [sym_ctor] = ACTIONS(1),
    [sym_comment_line] = ACTIONS(3),
    [sym_comment_block] = ACTIONS(3),
  },
  [1] = {
    [sym_package] = STATE(225),
    [sym_package_import] = STATE(15),
    [sym_item] = STATE(28),
    [sym_moddef] = STATE(44),
    [sym_builtindef] = STATE(44),
    [sym_structdef] = STATE(44),
    [sym_uniondef] = STATE(44),
    [sym_enumdef] = STATE(44),
    [sym_fndef] = STATE(44),
    [sym_socketdef] = STATE(44),
    [aux_sym_package_repeat1] = STATE(15),
    [aux_sym_package_repeat2] = STATE(28),
    [ts_builtin_sym_end] = ACTIONS(5),
    [anon_sym_import] = ACTIONS(7),
    [anon_sym_pub] = ACTIONS(9),
    [anon_sym_ext] = ACTIONS(11),
    [anon_sym_mod] = ACTIONS(13),
    [anon_sym_builtin] = ACTIONS(15),
    [anon_sym_struct] = ACTIONS(17),
    [anon_sym_union] = ACTIONS(19),
    [anon_sym_enum] = ACTIONS(21),
    [anon_sym_fn] = ACTIONS(23),
    [anon_sym_socket] = ACTIONS(25),
    [sym_comment_line] = ACTIONS(3),
    [sym_comment_block] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 17,
    ACTIONS(27), 1,
      anon_sym_LPAREN,
    ACTIONS(29), 1,
      anon_sym_RPAREN,
    ACTIONS(31), 1,
      anon_sym_if,
    ACTIONS(33), 1,
      anon_sym_match,
    ACTIONS(37), 1,
      sym_path,
    ACTIONS(41), 1,
      aux_sym_word_token3,
    ACTIONS(43), 1,
      sym_nat,
    ACTIONS(45), 1,
      sym_enumerant,
    ACTIONS(47), 1,
      sym_ctor,
    STATE(62), 1,
      sym_word,
    STATE(95), 1,
      sym_expr,
    STATE(172), 1,
      sym__expr_list,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(35), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(39), 2,
      aux_sym_word_token1,
      aux_sym_word_token2,
    STATE(56), 2,
      sym_word_lit,
      sym_bool,
    STATE(54), 6,
      sym_expr_if,
      sym_expr_match,
      sym_expr_call,
      sym_expr_idx,
      sym_expr_lit,
      sym_expr_reference,
  [61] = 17,
    ACTIONS(27), 1,
      anon_sym_LPAREN,
    ACTIONS(31), 1,
      anon_sym_if,
    ACTIONS(33), 1,
      anon_sym_match,
    ACTIONS(37), 1,
      sym_path,
    ACTIONS(41), 1,
      aux_sym_word_token3,
    ACTIONS(43), 1,
      sym_nat,
    ACTIONS(45), 1,
      sym_enumerant,
    ACTIONS(47), 1,
      sym_ctor,
    ACTIONS(49), 1,
      anon_sym_RPAREN,
    STATE(62), 1,
      sym_word,
    STATE(95), 1,
      sym_expr,
    STATE(209), 1,
      sym__expr_list,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(35), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(39), 2,
      aux_sym_word_token1,
      aux_sym_word_token2,
    STATE(56), 2,
      sym_word_lit,
      sym_bool,
    STATE(54), 6,
      sym_expr_if,
      sym_expr_match,
      sym_expr_call,
      sym_expr_idx,
      sym_expr_lit,
      sym_expr_reference,
  [122] = 16,
    ACTIONS(27), 1,
      anon_sym_LPAREN,
    ACTIONS(31), 1,
      anon_sym_if,
    ACTIONS(33), 1,
      anon_sym_match,
    ACTIONS(37), 1,
      sym_path,
    ACTIONS(41), 1,
      aux_sym_word_token3,
    ACTIONS(43), 1,
      sym_nat,
    ACTIONS(45), 1,
      sym_enumerant,
    ACTIONS(47), 1,
      sym_ctor,
    ACTIONS(51), 1,
      anon_sym_RPAREN,
    STATE(62), 1,
      sym_word,
    STATE(108), 1,
      sym_expr,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(35), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(39), 2,
      aux_sym_word_token1,
      aux_sym_word_token2,
    STATE(56), 2,
      sym_word_lit,
      sym_bool,
    STATE(54), 6,
      sym_expr_if,
      sym_expr_match,
      sym_expr_call,
      sym_expr_idx,
      sym_expr_lit,
      sym_expr_reference,
  [180] = 16,
    ACTIONS(27), 1,
      anon_sym_LPAREN,
    ACTIONS(31), 1,
      anon_sym_if,
    ACTIONS(33), 1,
      anon_sym_match,
    ACTIONS(37), 1,
      sym_path,
    ACTIONS(41), 1,
      aux_sym_word_token3,
    ACTIONS(43), 1,
      sym_nat,
    ACTIONS(45), 1,
      sym_enumerant,
    ACTIONS(47), 1,
      sym_ctor,
    ACTIONS(53), 1,
      anon_sym_RPAREN,
    STATE(62), 1,
      sym_word,
    STATE(108), 1,
      sym_expr,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(35), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(39), 2,
      aux_sym_word_token1,
      aux_sym_word_token2,
    STATE(56), 2,
      sym_word_lit,
      sym_bool,
    STATE(54), 6,
      sym_expr_if,
      sym_expr_match,
      sym_expr_call,
      sym_expr_idx,
      sym_expr_lit,
      sym_expr_reference,
  [238] = 15,
    ACTIONS(27), 1,
      anon_sym_LPAREN,
    ACTIONS(31), 1,
      anon_sym_if,
    ACTIONS(33), 1,
      anon_sym_match,
    ACTIONS(37), 1,
      sym_path,
    ACTIONS(41), 1,
      aux_sym_word_token3,
    ACTIONS(43), 1,
      sym_nat,
    ACTIONS(45), 1,
      sym_enumerant,
    ACTIONS(47), 1,
      sym_ctor,
    STATE(62), 1,
      sym_word,
    STATE(131), 1,
      sym_expr,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(35), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(39), 2,
      aux_sym_word_token1,
      aux_sym_word_token2,
    STATE(56), 2,
      sym_word_lit,
      sym_bool,
    STATE(54), 6,
      sym_expr_if,
      sym_expr_match,
      sym_expr_call,
      sym_expr_idx,
      sym_expr_lit,
      sym_expr_reference,
  [293] = 13,
    ACTIONS(55), 1,
      anon_sym_mod,
    ACTIONS(58), 1,
      anon_sym_RBRACE,
    ACTIONS(60), 1,
      anon_sym_implicit,
    ACTIONS(63), 1,
      anon_sym_incoming,
    ACTIONS(66), 1,
      anon_sym_outgoing,
    ACTIONS(69), 1,
      anon_sym_wire,
    ACTIONS(72), 1,
      anon_sym_reg,
    ACTIONS(78), 1,
      sym_path,
    STATE(7), 1,
      aux_sym_moddef_repeat1,
    STATE(176), 1,
      sym_socket_role,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(75), 2,
      anon_sym_master,
      anon_sym_slave,
    STATE(177), 10,
      sym__decl,
      sym__component,
      sym_implicit,
      sym_incoming,
      sym_outgoing,
      sym_wire,
      sym_reg,
      sym_socket,
      sym_connect,
      sym_submodule,
  [344] = 13,
    ACTIONS(81), 1,
      anon_sym_mod,
    ACTIONS(83), 1,
      anon_sym_RBRACE,
    ACTIONS(85), 1,
      anon_sym_implicit,
    ACTIONS(87), 1,
      anon_sym_incoming,
    ACTIONS(89), 1,
      anon_sym_outgoing,
    ACTIONS(91), 1,
      anon_sym_wire,
    ACTIONS(93), 1,
      anon_sym_reg,
    ACTIONS(97), 1,
      sym_path,
    STATE(7), 1,
      aux_sym_moddef_repeat1,
    STATE(176), 1,
      sym_socket_role,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(95), 2,
      anon_sym_master,
      anon_sym_slave,
    STATE(177), 10,
      sym__decl,
      sym__component,
      sym_implicit,
      sym_incoming,
      sym_outgoing,
      sym_wire,
      sym_reg,
      sym_socket,
      sym_connect,
      sym_submodule,
  [395] = 15,
    ACTIONS(27), 1,
      anon_sym_LPAREN,
    ACTIONS(31), 1,
      anon_sym_if,
    ACTIONS(33), 1,
      anon_sym_match,
    ACTIONS(37), 1,
      sym_path,
    ACTIONS(41), 1,
      aux_sym_word_token3,
    ACTIONS(43), 1,
      sym_nat,
    ACTIONS(45), 1,
      sym_enumerant,
    ACTIONS(47), 1,
      sym_ctor,
    STATE(62), 1,
      sym_word,
    STATE(122), 1,
      sym_expr,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(35), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(39), 2,
      aux_sym_word_token1,
      aux_sym_word_token2,
    STATE(56), 2,
      sym_word_lit,
      sym_bool,
    STATE(54), 6,
      sym_expr_if,
      sym_expr_match,
      sym_expr_call,
      sym_expr_idx,
      sym_expr_lit,
      sym_expr_reference,
  [450] = 15,
    ACTIONS(27), 1,
      anon_sym_LPAREN,
    ACTIONS(31), 1,
      anon_sym_if,
    ACTIONS(33), 1,
      anon_sym_match,
    ACTIONS(37), 1,
      sym_path,
    ACTIONS(41), 1,
      aux_sym_word_token3,
    ACTIONS(43), 1,
      sym_nat,
    ACTIONS(45), 1,
      sym_enumerant,
    ACTIONS(47), 1,
      sym_ctor,
    STATE(62), 1,
      sym_word,
    STATE(114), 1,
      sym_expr,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(35), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(39), 2,
      aux_sym_word_token1,
      aux_sym_word_token2,
    STATE(56), 2,
      sym_word_lit,
      sym_bool,
    STATE(54), 6,
      sym_expr_if,
      sym_expr_match,
      sym_expr_call,
      sym_expr_idx,
      sym_expr_lit,
      sym_expr_reference,
  [505] = 15,
    ACTIONS(27), 1,
      anon_sym_LPAREN,
    ACTIONS(31), 1,
      anon_sym_if,
    ACTIONS(33), 1,
      anon_sym_match,
    ACTIONS(37), 1,
      sym_path,
    ACTIONS(41), 1,
      aux_sym_word_token3,
    ACTIONS(43), 1,
      sym_nat,
    ACTIONS(45), 1,
      sym_enumerant,
    ACTIONS(47), 1,
      sym_ctor,
    STATE(62), 1,
      sym_word,
    STATE(120), 1,
      sym_expr,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(35), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(39), 2,
      aux_sym_word_token1,
      aux_sym_word_token2,
    STATE(56), 2,
      sym_word_lit,
      sym_bool,
    STATE(54), 6,
      sym_expr_if,
      sym_expr_match,
      sym_expr_call,
      sym_expr_idx,
      sym_expr_lit,
      sym_expr_reference,
  [560] = 15,
    ACTIONS(27), 1,
      anon_sym_LPAREN,
    ACTIONS(31), 1,
      anon_sym_if,
    ACTIONS(33), 1,
      anon_sym_match,
    ACTIONS(37), 1,
      sym_path,
    ACTIONS(41), 1,
      aux_sym_word_token3,
    ACTIONS(43), 1,
      sym_nat,
    ACTIONS(45), 1,
      sym_enumerant,
    ACTIONS(47), 1,
      sym_ctor,
    STATE(62), 1,
      sym_word,
    STATE(121), 1,
      sym_expr,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(35), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(39), 2,
      aux_sym_word_token1,
      aux_sym_word_token2,
    STATE(56), 2,
      sym_word_lit,
      sym_bool,
    STATE(54), 6,
      sym_expr_if,
      sym_expr_match,
      sym_expr_call,
      sym_expr_idx,
      sym_expr_lit,
      sym_expr_reference,
  [615] = 15,
    ACTIONS(27), 1,
      anon_sym_LPAREN,
    ACTIONS(31), 1,
      anon_sym_if,
    ACTIONS(33), 1,
      anon_sym_match,
    ACTIONS(37), 1,
      sym_path,
    ACTIONS(41), 1,
      aux_sym_word_token3,
    ACTIONS(43), 1,
      sym_nat,
    ACTIONS(45), 1,
      sym_enumerant,
    ACTIONS(47), 1,
      sym_ctor,
    STATE(62), 1,
      sym_word,
    STATE(134), 1,
      sym_expr,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(35), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(39), 2,
      aux_sym_word_token1,
      aux_sym_word_token2,
    STATE(56), 2,
      sym_word_lit,
      sym_bool,
    STATE(54), 6,
      sym_expr_if,
      sym_expr_match,
      sym_expr_call,
      sym_expr_idx,
      sym_expr_lit,
      sym_expr_reference,
  [670] = 13,
    ACTIONS(81), 1,
      anon_sym_mod,
    ACTIONS(85), 1,
      anon_sym_implicit,
    ACTIONS(87), 1,
      anon_sym_incoming,
    ACTIONS(89), 1,
      anon_sym_outgoing,
    ACTIONS(91), 1,
      anon_sym_wire,
    ACTIONS(93), 1,
      anon_sym_reg,
    ACTIONS(97), 1,
      sym_path,
    ACTIONS(99), 1,
      anon_sym_RBRACE,
    STATE(7), 1,
      aux_sym_moddef_repeat1,
    STATE(176), 1,
      sym_socket_role,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(95), 2,
      anon_sym_master,
      anon_sym_slave,
    STATE(177), 10,
      sym__decl,
      sym__component,
      sym_implicit,
      sym_incoming,
      sym_outgoing,
      sym_wire,
      sym_reg,
      sym_socket,
      sym_connect,
      sym_submodule,
  [721] = 15,
    ACTIONS(7), 1,
      anon_sym_import,
    ACTIONS(9), 1,
      anon_sym_pub,
    ACTIONS(11), 1,
      anon_sym_ext,
    ACTIONS(13), 1,
      anon_sym_mod,
    ACTIONS(15), 1,
      anon_sym_builtin,
    ACTIONS(17), 1,
      anon_sym_struct,
    ACTIONS(19), 1,
      anon_sym_union,
    ACTIONS(21), 1,
      anon_sym_enum,
    ACTIONS(23), 1,
      anon_sym_fn,
    ACTIONS(25), 1,
      anon_sym_socket,
    ACTIONS(101), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    STATE(26), 2,
      sym_item,
      aux_sym_package_repeat2,
    STATE(29), 2,
      sym_package_import,
      aux_sym_package_repeat1,
    STATE(44), 7,
      sym_moddef,
      sym_builtindef,
      sym_structdef,
      sym_uniondef,
      sym_enumdef,
      sym_fndef,
      sym_socketdef,
  [776] = 15,
    ACTIONS(27), 1,
      anon_sym_LPAREN,
    ACTIONS(31), 1,
      anon_sym_if,
    ACTIONS(33), 1,
      anon_sym_match,
    ACTIONS(37), 1,
      sym_path,
    ACTIONS(41), 1,
      aux_sym_word_token3,
    ACTIONS(43), 1,
      sym_nat,
    ACTIONS(45), 1,
      sym_enumerant,
    ACTIONS(47), 1,
      sym_ctor,
    STATE(62), 1,
      sym_word,
    STATE(115), 1,
      sym_expr,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(35), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(39), 2,
      aux_sym_word_token1,
      aux_sym_word_token2,
    STATE(56), 2,
      sym_word_lit,
      sym_bool,
    STATE(54), 6,
      sym_expr_if,
      sym_expr_match,
      sym_expr_call,
      sym_expr_idx,
      sym_expr_lit,
      sym_expr_reference,
  [831] = 15,
    ACTIONS(27), 1,
      anon_sym_LPAREN,
    ACTIONS(31), 1,
      anon_sym_if,
    ACTIONS(33), 1,
      anon_sym_match,
    ACTIONS(37), 1,
      sym_path,
    ACTIONS(41), 1,
      aux_sym_word_token3,
    ACTIONS(43), 1,
      sym_nat,
    ACTIONS(45), 1,
      sym_enumerant,
    ACTIONS(47), 1,
      sym_ctor,
    STATE(62), 1,
      sym_word,
    STATE(108), 1,
      sym_expr,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(35), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(39), 2,
      aux_sym_word_token1,
      aux_sym_word_token2,
    STATE(56), 2,
      sym_word_lit,
      sym_bool,
    STATE(54), 6,
      sym_expr_if,
      sym_expr_match,
      sym_expr_call,
      sym_expr_idx,
      sym_expr_lit,
      sym_expr_reference,
  [886] = 13,
    ACTIONS(81), 1,
      anon_sym_mod,
    ACTIONS(85), 1,
      anon_sym_implicit,
    ACTIONS(87), 1,
      anon_sym_incoming,
    ACTIONS(89), 1,
      anon_sym_outgoing,
    ACTIONS(91), 1,
      anon_sym_wire,
    ACTIONS(93), 1,
      anon_sym_reg,
    ACTIONS(97), 1,
      sym_path,
    ACTIONS(103), 1,
      anon_sym_RBRACE,
    STATE(21), 1,
      aux_sym_moddef_repeat1,
    STATE(176), 1,
      sym_socket_role,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(95), 2,
      anon_sym_master,
      anon_sym_slave,
    STATE(177), 10,
      sym__decl,
      sym__component,
      sym_implicit,
      sym_incoming,
      sym_outgoing,
      sym_wire,
      sym_reg,
      sym_socket,
      sym_connect,
      sym_submodule,
  [937] = 15,
    ACTIONS(27), 1,
      anon_sym_LPAREN,
    ACTIONS(31), 1,
      anon_sym_if,
    ACTIONS(33), 1,
      anon_sym_match,
    ACTIONS(37), 1,
      sym_path,
    ACTIONS(41), 1,
      aux_sym_word_token3,
    ACTIONS(43), 1,
      sym_nat,
    ACTIONS(45), 1,
      sym_enumerant,
    ACTIONS(47), 1,
      sym_ctor,
    STATE(62), 1,
      sym_word,
    STATE(126), 1,
      sym_expr,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(35), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(39), 2,
      aux_sym_word_token1,
      aux_sym_word_token2,
    STATE(56), 2,
      sym_word_lit,
      sym_bool,
    STATE(54), 6,
      sym_expr_if,
      sym_expr_match,
      sym_expr_call,
      sym_expr_idx,
      sym_expr_lit,
      sym_expr_reference,
  [992] = 15,
    ACTIONS(27), 1,
      anon_sym_LPAREN,
    ACTIONS(31), 1,
      anon_sym_if,
    ACTIONS(33), 1,
      anon_sym_match,
    ACTIONS(37), 1,
      sym_path,
    ACTIONS(41), 1,
      aux_sym_word_token3,
    ACTIONS(43), 1,
      sym_nat,
    ACTIONS(45), 1,
      sym_enumerant,
    ACTIONS(47), 1,
      sym_ctor,
    STATE(62), 1,
      sym_word,
    STATE(133), 1,
      sym_expr,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(35), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(39), 2,
      aux_sym_word_token1,
      aux_sym_word_token2,
    STATE(56), 2,
      sym_word_lit,
      sym_bool,
    STATE(54), 6,
      sym_expr_if,
      sym_expr_match,
      sym_expr_call,
      sym_expr_idx,
      sym_expr_lit,
      sym_expr_reference,
  [1047] = 13,
    ACTIONS(81), 1,
      anon_sym_mod,
    ACTIONS(85), 1,
      anon_sym_implicit,
    ACTIONS(87), 1,
      anon_sym_incoming,
    ACTIONS(89), 1,
      anon_sym_outgoing,
    ACTIONS(91), 1,
      anon_sym_wire,
    ACTIONS(93), 1,
      anon_sym_reg,
    ACTIONS(97), 1,
      sym_path,
    ACTIONS(105), 1,
      anon_sym_RBRACE,
    STATE(7), 1,
      aux_sym_moddef_repeat1,
    STATE(176), 1,
      sym_socket_role,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(95), 2,
      anon_sym_master,
      anon_sym_slave,
    STATE(177), 10,
      sym__decl,
      sym__component,
      sym_implicit,
      sym_incoming,
      sym_outgoing,
      sym_wire,
      sym_reg,
      sym_socket,
      sym_connect,
      sym_submodule,
  [1098] = 15,
    ACTIONS(27), 1,
      anon_sym_LPAREN,
    ACTIONS(31), 1,
      anon_sym_if,
    ACTIONS(33), 1,
      anon_sym_match,
    ACTIONS(37), 1,
      sym_path,
    ACTIONS(41), 1,
      aux_sym_word_token3,
    ACTIONS(43), 1,
      sym_nat,
    ACTIONS(45), 1,
      sym_enumerant,
    ACTIONS(47), 1,
      sym_ctor,
    STATE(62), 1,
      sym_word,
    STATE(101), 1,
      sym_expr,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(35), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(39), 2,
      aux_sym_word_token1,
      aux_sym_word_token2,
    STATE(56), 2,
      sym_word_lit,
      sym_bool,
    STATE(54), 6,
      sym_expr_if,
      sym_expr_match,
      sym_expr_call,
      sym_expr_idx,
      sym_expr_lit,
      sym_expr_reference,
  [1153] = 15,
    ACTIONS(27), 1,
      anon_sym_LPAREN,
    ACTIONS(31), 1,
      anon_sym_if,
    ACTIONS(33), 1,
      anon_sym_match,
    ACTIONS(37), 1,
      sym_path,
    ACTIONS(41), 1,
      aux_sym_word_token3,
    ACTIONS(43), 1,
      sym_nat,
    ACTIONS(45), 1,
      sym_enumerant,
    ACTIONS(47), 1,
      sym_ctor,
    STATE(62), 1,
      sym_word,
    STATE(111), 1,
      sym_expr,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(35), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(39), 2,
      aux_sym_word_token1,
      aux_sym_word_token2,
    STATE(56), 2,
      sym_word_lit,
      sym_bool,
    STATE(54), 6,
      sym_expr_if,
      sym_expr_match,
      sym_expr_call,
      sym_expr_idx,
      sym_expr_lit,
      sym_expr_reference,
  [1208] = 13,
    ACTIONS(81), 1,
      anon_sym_mod,
    ACTIONS(85), 1,
      anon_sym_implicit,
    ACTIONS(87), 1,
      anon_sym_incoming,
    ACTIONS(89), 1,
      anon_sym_outgoing,
    ACTIONS(91), 1,
      anon_sym_wire,
    ACTIONS(93), 1,
      anon_sym_reg,
    ACTIONS(97), 1,
      sym_path,
    ACTIONS(107), 1,
      anon_sym_RBRACE,
    STATE(8), 1,
      aux_sym_moddef_repeat1,
    STATE(176), 1,
      sym_socket_role,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(95), 2,
      anon_sym_master,
      anon_sym_slave,
    STATE(177), 10,
      sym__decl,
      sym__component,
      sym_implicit,
      sym_incoming,
      sym_outgoing,
      sym_wire,
      sym_reg,
      sym_socket,
      sym_connect,
      sym_submodule,
  [1259] = 13,
    ACTIONS(81), 1,
      anon_sym_mod,
    ACTIONS(85), 1,
      anon_sym_implicit,
    ACTIONS(87), 1,
      anon_sym_incoming,
    ACTIONS(89), 1,
      anon_sym_outgoing,
    ACTIONS(91), 1,
      anon_sym_wire,
    ACTIONS(93), 1,
      anon_sym_reg,
    ACTIONS(97), 1,
      sym_path,
    ACTIONS(109), 1,
      anon_sym_RBRACE,
    STATE(14), 1,
      aux_sym_moddef_repeat1,
    STATE(176), 1,
      sym_socket_role,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(95), 2,
      anon_sym_master,
      anon_sym_slave,
    STATE(177), 10,
      sym__decl,
      sym__component,
      sym_implicit,
      sym_incoming,
      sym_outgoing,
      sym_wire,
      sym_reg,
      sym_socket,
      sym_connect,
      sym_submodule,
  [1310] = 13,
    ACTIONS(9), 1,
      anon_sym_pub,
    ACTIONS(11), 1,
      anon_sym_ext,
    ACTIONS(13), 1,
      anon_sym_mod,
    ACTIONS(15), 1,
      anon_sym_builtin,
    ACTIONS(17), 1,
      anon_sym_struct,
    ACTIONS(19), 1,
      anon_sym_union,
    ACTIONS(21), 1,
      anon_sym_enum,
    ACTIONS(23), 1,
      anon_sym_fn,
    ACTIONS(25), 1,
      anon_sym_socket,
    ACTIONS(111), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    STATE(27), 2,
      sym_item,
      aux_sym_package_repeat2,
    STATE(44), 7,
      sym_moddef,
      sym_builtindef,
      sym_structdef,
      sym_uniondef,
      sym_enumdef,
      sym_fndef,
      sym_socketdef,
  [1358] = 13,
    ACTIONS(113), 1,
      ts_builtin_sym_end,
    ACTIONS(115), 1,
      anon_sym_pub,
    ACTIONS(118), 1,
      anon_sym_ext,
    ACTIONS(121), 1,
      anon_sym_mod,
    ACTIONS(124), 1,
      anon_sym_builtin,
    ACTIONS(127), 1,
      anon_sym_struct,
    ACTIONS(130), 1,
      anon_sym_union,
    ACTIONS(133), 1,
      anon_sym_enum,
    ACTIONS(136), 1,
      anon_sym_fn,
    ACTIONS(139), 1,
      anon_sym_socket,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    STATE(27), 2,
      sym_item,
      aux_sym_package_repeat2,
    STATE(44), 7,
      sym_moddef,
      sym_builtindef,
      sym_structdef,
      sym_uniondef,
      sym_enumdef,
      sym_fndef,
      sym_socketdef,
  [1406] = 13,
    ACTIONS(9), 1,
      anon_sym_pub,
    ACTIONS(11), 1,
      anon_sym_ext,
    ACTIONS(13), 1,
      anon_sym_mod,
    ACTIONS(15), 1,
      anon_sym_builtin,
    ACTIONS(17), 1,
      anon_sym_struct,
    ACTIONS(19), 1,
      anon_sym_union,
    ACTIONS(21), 1,
      anon_sym_enum,
    ACTIONS(23), 1,
      anon_sym_fn,
    ACTIONS(25), 1,
      anon_sym_socket,
    ACTIONS(101), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    STATE(27), 2,
      sym_item,
      aux_sym_package_repeat2,
    STATE(44), 7,
      sym_moddef,
      sym_builtindef,
      sym_structdef,
      sym_uniondef,
      sym_enumdef,
      sym_fndef,
      sym_socketdef,
  [1454] = 4,
    ACTIONS(144), 1,
      anon_sym_import,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    STATE(29), 2,
      sym_package_import,
      aux_sym_package_repeat1,
    ACTIONS(142), 10,
      ts_builtin_sym_end,
      anon_sym_pub,
      anon_sym_ext,
      anon_sym_mod,
      anon_sym_builtin,
      anon_sym_struct,
      anon_sym_union,
      anon_sym_enum,
      anon_sym_fn,
      anon_sym_socket,
  [1478] = 3,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(147), 5,
      anon_sym_LPAREN,
      aux_sym_word_token1,
      aux_sym_word_token2,
      sym_enumerant,
      sym_ctor,
    ACTIONS(149), 7,
      anon_sym_if,
      anon_sym_match,
      anon_sym_true,
      anon_sym_false,
      sym_path,
      aux_sym_word_token3,
      sym_nat,
  [1499] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(151), 11,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_pub,
      anon_sym_ext,
      anon_sym_mod,
      anon_sym_builtin,
      anon_sym_struct,
      anon_sym_union,
      anon_sym_enum,
      anon_sym_fn,
      anon_sym_socket,
  [1517] = 3,
    ACTIONS(58), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(153), 9,
      anon_sym_mod,
      anon_sym_implicit,
      anon_sym_incoming,
      anon_sym_outgoing,
      anon_sym_wire,
      anon_sym_reg,
      anon_sym_master,
      anon_sym_slave,
      sym_path,
  [1536] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(155), 10,
      ts_builtin_sym_end,
      anon_sym_pub,
      anon_sym_ext,
      anon_sym_mod,
      anon_sym_builtin,
      anon_sym_struct,
      anon_sym_union,
      anon_sym_enum,
      anon_sym_fn,
      anon_sym_socket,
  [1553] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(157), 10,
      ts_builtin_sym_end,
      anon_sym_pub,
      anon_sym_ext,
      anon_sym_mod,
      anon_sym_builtin,
      anon_sym_struct,
      anon_sym_union,
      anon_sym_enum,
      anon_sym_fn,
      anon_sym_socket,
  [1570] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(159), 10,
      ts_builtin_sym_end,
      anon_sym_pub,
      anon_sym_ext,
      anon_sym_mod,
      anon_sym_builtin,
      anon_sym_struct,
      anon_sym_union,
      anon_sym_enum,
      anon_sym_fn,
      anon_sym_socket,
  [1587] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(161), 10,
      ts_builtin_sym_end,
      anon_sym_pub,
      anon_sym_ext,
      anon_sym_mod,
      anon_sym_builtin,
      anon_sym_struct,
      anon_sym_union,
      anon_sym_enum,
      anon_sym_fn,
      anon_sym_socket,
  [1604] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(163), 10,
      ts_builtin_sym_end,
      anon_sym_pub,
      anon_sym_ext,
      anon_sym_mod,
      anon_sym_builtin,
      anon_sym_struct,
      anon_sym_union,
      anon_sym_enum,
      anon_sym_fn,
      anon_sym_socket,
  [1621] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(165), 10,
      ts_builtin_sym_end,
      anon_sym_pub,
      anon_sym_ext,
      anon_sym_mod,
      anon_sym_builtin,
      anon_sym_struct,
      anon_sym_union,
      anon_sym_enum,
      anon_sym_fn,
      anon_sym_socket,
  [1638] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(167), 10,
      ts_builtin_sym_end,
      anon_sym_pub,
      anon_sym_ext,
      anon_sym_mod,
      anon_sym_builtin,
      anon_sym_struct,
      anon_sym_union,
      anon_sym_enum,
      anon_sym_fn,
      anon_sym_socket,
  [1655] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(169), 10,
      ts_builtin_sym_end,
      anon_sym_pub,
      anon_sym_ext,
      anon_sym_mod,
      anon_sym_builtin,
      anon_sym_struct,
      anon_sym_union,
      anon_sym_enum,
      anon_sym_fn,
      anon_sym_socket,
  [1672] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(171), 10,
      ts_builtin_sym_end,
      anon_sym_pub,
      anon_sym_ext,
      anon_sym_mod,
      anon_sym_builtin,
      anon_sym_struct,
      anon_sym_union,
      anon_sym_enum,
      anon_sym_fn,
      anon_sym_socket,
  [1689] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(173), 10,
      ts_builtin_sym_end,
      anon_sym_pub,
      anon_sym_ext,
      anon_sym_mod,
      anon_sym_builtin,
      anon_sym_struct,
      anon_sym_union,
      anon_sym_enum,
      anon_sym_fn,
      anon_sym_socket,
  [1706] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(175), 10,
      ts_builtin_sym_end,
      anon_sym_pub,
      anon_sym_ext,
      anon_sym_mod,
      anon_sym_builtin,
      anon_sym_struct,
      anon_sym_union,
      anon_sym_enum,
      anon_sym_fn,
      anon_sym_socket,
  [1723] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(177), 10,
      ts_builtin_sym_end,
      anon_sym_pub,
      anon_sym_ext,
      anon_sym_mod,
      anon_sym_builtin,
      anon_sym_struct,
      anon_sym_union,
      anon_sym_enum,
      anon_sym_fn,
      anon_sym_socket,
  [1740] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(179), 10,
      ts_builtin_sym_end,
      anon_sym_pub,
      anon_sym_ext,
      anon_sym_mod,
      anon_sym_builtin,
      anon_sym_struct,
      anon_sym_union,
      anon_sym_enum,
      anon_sym_fn,
      anon_sym_socket,
  [1757] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(181), 10,
      ts_builtin_sym_end,
      anon_sym_pub,
      anon_sym_ext,
      anon_sym_mod,
      anon_sym_builtin,
      anon_sym_struct,
      anon_sym_union,
      anon_sym_enum,
      anon_sym_fn,
      anon_sym_socket,
  [1774] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(183), 10,
      ts_builtin_sym_end,
      anon_sym_pub,
      anon_sym_ext,
      anon_sym_mod,
      anon_sym_builtin,
      anon_sym_struct,
      anon_sym_union,
      anon_sym_enum,
      anon_sym_fn,
      anon_sym_socket,
  [1791] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(185), 10,
      ts_builtin_sym_end,
      anon_sym_pub,
      anon_sym_ext,
      anon_sym_mod,
      anon_sym_builtin,
      anon_sym_struct,
      anon_sym_union,
      anon_sym_enum,
      anon_sym_fn,
      anon_sym_socket,
  [1808] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(187), 10,
      ts_builtin_sym_end,
      anon_sym_pub,
      anon_sym_ext,
      anon_sym_mod,
      anon_sym_builtin,
      anon_sym_struct,
      anon_sym_union,
      anon_sym_enum,
      anon_sym_fn,
      anon_sym_socket,
  [1825] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(189), 10,
      ts_builtin_sym_end,
      anon_sym_pub,
      anon_sym_ext,
      anon_sym_mod,
      anon_sym_builtin,
      anon_sym_struct,
      anon_sym_union,
      anon_sym_enum,
      anon_sym_fn,
      anon_sym_socket,
  [1842] = 7,
    ACTIONS(191), 1,
      anon_sym_RBRACE,
    ACTIONS(195), 1,
      sym_enumerant,
    ACTIONS(197), 1,
      sym_ctor,
    STATE(184), 1,
      sym_pat,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(193), 2,
      anon_sym_else,
      sym_ident,
    STATE(52), 2,
      sym_match_arm,
      aux_sym_expr_match_repeat1,
  [1867] = 7,
    ACTIONS(199), 1,
      anon_sym_RBRACE,
    ACTIONS(204), 1,
      sym_enumerant,
    ACTIONS(207), 1,
      sym_ctor,
    STATE(184), 1,
      sym_pat,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(201), 2,
      anon_sym_else,
      sym_ident,
    STATE(52), 2,
      sym_match_arm,
      aux_sym_expr_match_repeat1,
  [1892] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(210), 8,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COLON,
      anon_sym_RPAREN,
      anon_sym_DASH_GT,
      anon_sym_COMMA,
      anon_sym_LBRACK,
  [1907] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(212), 8,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COLON,
      anon_sym_RPAREN,
      anon_sym_DASH_GT,
      anon_sym_COMMA,
      anon_sym_LBRACK,
  [1922] = 7,
    ACTIONS(195), 1,
      sym_enumerant,
    ACTIONS(197), 1,
      sym_ctor,
    ACTIONS(214), 1,
      anon_sym_RBRACE,
    STATE(184), 1,
      sym_pat,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(193), 2,
      anon_sym_else,
      sym_ident,
    STATE(52), 2,
      sym_match_arm,
      aux_sym_expr_match_repeat1,
  [1947] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(216), 8,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COLON,
      anon_sym_RPAREN,
      anon_sym_DASH_GT,
      anon_sym_COMMA,
      anon_sym_LBRACK,
  [1962] = 7,
    ACTIONS(195), 1,
      sym_enumerant,
    ACTIONS(197), 1,
      sym_ctor,
    ACTIONS(218), 1,
      anon_sym_RBRACE,
    STATE(184), 1,
      sym_pat,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(193), 2,
      anon_sym_else,
      sym_ident,
    STATE(55), 2,
      sym_match_arm,
      aux_sym_expr_match_repeat1,
  [1987] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(220), 8,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COLON,
      anon_sym_RPAREN,
      anon_sym_DASH_GT,
      anon_sym_COMMA,
      anon_sym_LBRACK,
  [2002] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(222), 8,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COLON,
      anon_sym_RPAREN,
      anon_sym_DASH_GT,
      anon_sym_COMMA,
      anon_sym_LBRACK,
  [2017] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(224), 8,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COLON,
      anon_sym_RPAREN,
      anon_sym_DASH_GT,
      anon_sym_COMMA,
      anon_sym_LBRACK,
  [2032] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(226), 8,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COLON,
      anon_sym_RPAREN,
      anon_sym_DASH_GT,
      anon_sym_COMMA,
      anon_sym_LBRACK,
  [2047] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(228), 8,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COLON,
      anon_sym_RPAREN,
      anon_sym_DASH_GT,
      anon_sym_COMMA,
      anon_sym_LBRACK,
  [2062] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(230), 8,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COLON,
      anon_sym_RPAREN,
      anon_sym_DASH_GT,
      anon_sym_COMMA,
      anon_sym_LBRACK,
  [2077] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(232), 8,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COLON,
      anon_sym_RPAREN,
      anon_sym_DASH_GT,
      anon_sym_COMMA,
      anon_sym_LBRACK,
  [2092] = 7,
    ACTIONS(195), 1,
      sym_enumerant,
    ACTIONS(197), 1,
      sym_ctor,
    ACTIONS(234), 1,
      anon_sym_RBRACE,
    STATE(184), 1,
      sym_pat,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(193), 2,
      anon_sym_else,
      sym_ident,
    STATE(51), 2,
      sym_match_arm,
      aux_sym_expr_match_repeat1,
  [2117] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(236), 8,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COLON,
      anon_sym_RPAREN,
      anon_sym_DASH_GT,
      anon_sym_COMMA,
      anon_sym_LBRACK,
  [2132] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(238), 8,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COLON,
      anon_sym_RPAREN,
      anon_sym_DASH_GT,
      anon_sym_COMMA,
      anon_sym_LBRACK,
  [2147] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(240), 8,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COLON,
      anon_sym_RPAREN,
      anon_sym_DASH_GT,
      anon_sym_COMMA,
      anon_sym_LBRACK,
  [2162] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(242), 8,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COLON,
      anon_sym_RPAREN,
      anon_sym_DASH_GT,
      anon_sym_COMMA,
      anon_sym_LBRACK,
  [2177] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(244), 8,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COLON,
      anon_sym_RPAREN,
      anon_sym_DASH_GT,
      anon_sym_COMMA,
      anon_sym_LBRACK,
  [2192] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(246), 8,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COLON,
      anon_sym_RPAREN,
      anon_sym_DASH_GT,
      anon_sym_COMMA,
      anon_sym_LBRACK,
  [2207] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(248), 8,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COLON,
      anon_sym_RPAREN,
      anon_sym_DASH_GT,
      anon_sym_COMMA,
      anon_sym_LBRACK,
  [2222] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(250), 8,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COLON,
      anon_sym_RPAREN,
      anon_sym_DASH_GT,
      anon_sym_COMMA,
      anon_sym_LBRACK,
  [2237] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(252), 8,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COLON,
      anon_sym_RPAREN,
      anon_sym_DASH_GT,
      anon_sym_COMMA,
      anon_sym_LBRACK,
  [2252] = 7,
    ACTIONS(195), 1,
      sym_enumerant,
    ACTIONS(197), 1,
      sym_ctor,
    ACTIONS(254), 1,
      anon_sym_RPAREN,
    STATE(128), 1,
      sym_pat,
    STATE(218), 1,
      sym_patlist,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(193), 2,
      anon_sym_else,
      sym_ident,
  [2276] = 5,
    ACTIONS(258), 1,
      anon_sym_Word,
    STATE(85), 1,
      sym_type_word,
    STATE(186), 1,
      sym_type,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(256), 3,
      sym_type_clock,
      sym_type_bit,
      sym_qualident,
  [2295] = 5,
    ACTIONS(260), 1,
      anon_sym_RBRACE,
    STATE(161), 1,
      sym_channeldir,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(262), 2,
      anon_sym_mosi,
      anon_sym_miso,
    STATE(82), 2,
      sym_channel,
      aux_sym_socketdef_repeat1,
  [2314] = 5,
    ACTIONS(258), 1,
      anon_sym_Word,
    STATE(85), 1,
      sym_type_word,
    STATE(163), 1,
      sym_type,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(256), 3,
      sym_type_clock,
      sym_type_bit,
      sym_qualident,
  [2333] = 5,
    ACTIONS(258), 1,
      anon_sym_Word,
    STATE(85), 1,
      sym_type_word,
    STATE(162), 1,
      sym_type,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(256), 3,
      sym_type_clock,
      sym_type_bit,
      sym_qualident,
  [2352] = 6,
    ACTIONS(195), 1,
      sym_enumerant,
    ACTIONS(197), 1,
      sym_ctor,
    ACTIONS(264), 1,
      anon_sym_RPAREN,
    STATE(147), 1,
      sym_pat,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(193), 2,
      anon_sym_else,
      sym_ident,
  [2373] = 5,
    ACTIONS(258), 1,
      anon_sym_Word,
    STATE(85), 1,
      sym_type_word,
    STATE(213), 1,
      sym_type,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(256), 3,
      sym_type_clock,
      sym_type_bit,
      sym_qualident,
  [2392] = 5,
    ACTIONS(266), 1,
      anon_sym_RBRACE,
    STATE(161), 1,
      sym_channeldir,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(262), 2,
      anon_sym_mosi,
      anon_sym_miso,
    STATE(94), 2,
      sym_channel,
      aux_sym_socketdef_repeat1,
  [2411] = 6,
    ACTIONS(195), 1,
      sym_enumerant,
    ACTIONS(197), 1,
      sym_ctor,
    ACTIONS(268), 1,
      anon_sym_RPAREN,
    STATE(147), 1,
      sym_pat,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(193), 2,
      anon_sym_else,
      sym_ident,
  [2432] = 6,
    ACTIONS(41), 1,
      aux_sym_word_token3,
    ACTIONS(43), 1,
      sym_nat,
    STATE(62), 1,
      sym_word,
    STATE(194), 1,
      sym_word_lit,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(39), 2,
      aux_sym_word_token1,
      aux_sym_word_token2,
  [2453] = 3,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(272), 2,
      anon_sym_on,
      sym_path,
    ACTIONS(270), 4,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [2468] = 3,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(276), 2,
      anon_sym_on,
      sym_path,
    ACTIONS(274), 4,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [2483] = 5,
    ACTIONS(258), 1,
      anon_sym_Word,
    STATE(85), 1,
      sym_type_word,
    STATE(211), 1,
      sym_type,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(256), 3,
      sym_type_clock,
      sym_type_bit,
      sym_qualident,
  [2502] = 5,
    ACTIONS(258), 1,
      anon_sym_Word,
    STATE(85), 1,
      sym_type_word,
    STATE(227), 1,
      sym_type,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(256), 3,
      sym_type_clock,
      sym_type_bit,
      sym_qualident,
  [2521] = 5,
    ACTIONS(258), 1,
      anon_sym_Word,
    STATE(85), 1,
      sym_type_word,
    STATE(144), 1,
      sym_type,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(256), 3,
      sym_type_clock,
      sym_type_bit,
      sym_qualident,
  [2540] = 5,
    ACTIONS(258), 1,
      anon_sym_Word,
    STATE(85), 1,
      sym_type_word,
    STATE(139), 1,
      sym_type,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(256), 3,
      sym_type_clock,
      sym_type_bit,
      sym_qualident,
  [2559] = 5,
    ACTIONS(258), 1,
      anon_sym_Word,
    STATE(85), 1,
      sym_type_word,
    STATE(154), 1,
      sym_type,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(256), 3,
      sym_type_clock,
      sym_type_bit,
      sym_qualident,
  [2578] = 5,
    ACTIONS(258), 1,
      anon_sym_Word,
    STATE(85), 1,
      sym_type_word,
    STATE(199), 1,
      sym_type,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(256), 3,
      sym_type_clock,
      sym_type_bit,
      sym_qualident,
  [2597] = 5,
    ACTIONS(258), 1,
      anon_sym_Word,
    STATE(85), 1,
      sym_type_word,
    STATE(207), 1,
      sym_type,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(256), 3,
      sym_type_clock,
      sym_type_bit,
      sym_qualident,
  [2616] = 5,
    ACTIONS(278), 1,
      anon_sym_RBRACE,
    STATE(161), 1,
      sym_channeldir,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(280), 2,
      anon_sym_mosi,
      anon_sym_miso,
    STATE(94), 2,
      sym_channel,
      aux_sym_socketdef_repeat1,
  [2635] = 6,
    ACTIONS(283), 1,
      anon_sym_RPAREN,
    ACTIONS(285), 1,
      anon_sym_DASH_GT,
    ACTIONS(287), 1,
      anon_sym_COMMA,
    ACTIONS(289), 1,
      anon_sym_LBRACK,
    STATE(129), 1,
      aux_sym__expr_list_repeat1,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [2655] = 5,
    ACTIONS(195), 1,
      sym_enumerant,
    ACTIONS(197), 1,
      sym_ctor,
    STATE(147), 1,
      sym_pat,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(193), 2,
      anon_sym_else,
      sym_ident,
  [2673] = 3,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(293), 2,
      anon_sym_else,
      sym_ident,
    ACTIONS(291), 3,
      anon_sym_RBRACE,
      sym_enumerant,
      sym_ctor,
  [2687] = 4,
    ACTIONS(295), 1,
      anon_sym_RBRACE,
    ACTIONS(297), 1,
      sym_ident,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    STATE(98), 2,
      sym_alt,
      aux_sym_uniondef_repeat1,
  [2702] = 5,
    ACTIONS(300), 1,
      anon_sym_RPAREN,
    ACTIONS(302), 1,
      sym_ident,
    STATE(112), 1,
      sym_arg,
    STATE(156), 1,
      sym_param_list,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [2719] = 4,
    ACTIONS(304), 1,
      anon_sym_RBRACE,
    ACTIONS(306), 1,
      sym_ident,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    STATE(100), 2,
      sym_enumdef_statement,
      aux_sym_enumdef_repeat1,
  [2734] = 5,
    ACTIONS(285), 1,
      anon_sym_DASH_GT,
    ACTIONS(289), 1,
      anon_sym_LBRACK,
    ACTIONS(309), 1,
      anon_sym_RBRACE,
    STATE(137), 1,
      aux_sym_expr_if_repeat1,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [2751] = 4,
    ACTIONS(311), 1,
      anon_sym_RBRACE,
    ACTIONS(313), 1,
      sym_ident,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    STATE(100), 2,
      sym_enumdef_statement,
      aux_sym_enumdef_repeat1,
  [2766] = 4,
    ACTIONS(315), 1,
      anon_sym_RBRACE,
    ACTIONS(317), 1,
      sym_ident,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    STATE(103), 2,
      sym_field,
      aux_sym_structdef_repeat1,
  [2781] = 4,
    ACTIONS(320), 1,
      anon_sym_RBRACE,
    ACTIONS(322), 1,
      sym_ident,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    STATE(110), 2,
      sym_field,
      aux_sym_structdef_repeat1,
  [2796] = 4,
    ACTIONS(313), 1,
      sym_ident,
    ACTIONS(324), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    STATE(102), 2,
      sym_enumdef_statement,
      aux_sym_enumdef_repeat1,
  [2811] = 5,
    ACTIONS(302), 1,
      sym_ident,
    ACTIONS(326), 1,
      anon_sym_RPAREN,
    STATE(112), 1,
      sym_arg,
    STATE(167), 1,
      sym_param_list,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [2828] = 4,
    ACTIONS(328), 1,
      anon_sym_RBRACE,
    ACTIONS(330), 1,
      sym_ident,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    STATE(109), 2,
      sym_alt,
      aux_sym_uniondef_repeat1,
  [2843] = 4,
    ACTIONS(285), 1,
      anon_sym_DASH_GT,
    ACTIONS(289), 1,
      anon_sym_LBRACK,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(332), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [2858] = 4,
    ACTIONS(330), 1,
      sym_ident,
    ACTIONS(334), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    STATE(98), 2,
      sym_alt,
      aux_sym_uniondef_repeat1,
  [2873] = 4,
    ACTIONS(322), 1,
      sym_ident,
    ACTIONS(336), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    STATE(103), 2,
      sym_field,
      aux_sym_structdef_repeat1,
  [2888] = 5,
    ACTIONS(285), 1,
      anon_sym_DASH_GT,
    ACTIONS(289), 1,
      anon_sym_LBRACK,
    ACTIONS(338), 1,
      anon_sym_LBRACE,
    ACTIONS(340), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [2905] = 4,
    ACTIONS(342), 1,
      anon_sym_RPAREN,
    ACTIONS(344), 1,
      anon_sym_COMMA,
    STATE(118), 1,
      aux_sym_param_list_repeat1,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [2919] = 4,
    ACTIONS(346), 1,
      anon_sym_RPAREN,
    ACTIONS(348), 1,
      anon_sym_COMMA,
    STATE(113), 1,
      aux_sym_param_list_repeat1,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [2933] = 4,
    ACTIONS(285), 1,
      anon_sym_DASH_GT,
    ACTIONS(289), 1,
      anon_sym_LBRACK,
    ACTIONS(351), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [2947] = 4,
    ACTIONS(285), 1,
      anon_sym_DASH_GT,
    ACTIONS(289), 1,
      anon_sym_LBRACK,
    ACTIONS(353), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [2961] = 4,
    ACTIONS(355), 1,
      anon_sym_RPAREN,
    ACTIONS(357), 1,
      anon_sym_COMMA,
    STATE(116), 1,
      aux_sym_patlist_repeat1,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [2975] = 4,
    ACTIONS(302), 1,
      sym_ident,
    ACTIONS(360), 1,
      anon_sym_RPAREN,
    STATE(143), 1,
      sym_arg,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [2989] = 4,
    ACTIONS(360), 1,
      anon_sym_RPAREN,
    ACTIONS(362), 1,
      anon_sym_COMMA,
    STATE(113), 1,
      aux_sym_param_list_repeat1,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3003] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(364), 3,
      anon_sym_RBRACE,
      anon_sym_mosi,
      anon_sym_miso,
  [3013] = 4,
    ACTIONS(285), 1,
      anon_sym_DASH_GT,
    ACTIONS(289), 1,
      anon_sym_LBRACK,
    ACTIONS(366), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3027] = 4,
    ACTIONS(285), 1,
      anon_sym_DASH_GT,
    ACTIONS(289), 1,
      anon_sym_LBRACK,
    ACTIONS(368), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3041] = 4,
    ACTIONS(285), 1,
      anon_sym_DASH_GT,
    ACTIONS(289), 1,
      anon_sym_LBRACK,
    ACTIONS(370), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3055] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(372), 3,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_EQ_GT,
  [3065] = 4,
    ACTIONS(268), 1,
      anon_sym_RPAREN,
    ACTIONS(374), 1,
      anon_sym_COMMA,
    STATE(116), 1,
      aux_sym_patlist_repeat1,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3079] = 3,
    STATE(9), 1,
      sym_connect_type,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(376), 2,
      sym_direct,
      sym_latched,
  [3091] = 4,
    ACTIONS(285), 1,
      anon_sym_DASH_GT,
    ACTIONS(289), 1,
      anon_sym_LBRACK,
    ACTIONS(378), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3105] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(380), 3,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_EQ_GT,
  [3115] = 4,
    ACTIONS(382), 1,
      anon_sym_RPAREN,
    ACTIONS(384), 1,
      anon_sym_COMMA,
    STATE(124), 1,
      aux_sym_patlist_repeat1,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3129] = 4,
    ACTIONS(51), 1,
      anon_sym_RPAREN,
    ACTIONS(386), 1,
      anon_sym_COMMA,
    STATE(135), 1,
      aux_sym__expr_list_repeat1,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3143] = 4,
    ACTIONS(302), 1,
      sym_ident,
    ACTIONS(388), 1,
      anon_sym_RPAREN,
    STATE(143), 1,
      sym_arg,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3157] = 4,
    ACTIONS(285), 1,
      anon_sym_DASH_GT,
    ACTIONS(289), 1,
      anon_sym_LBRACK,
    ACTIONS(390), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3171] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(392), 3,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_EQ_GT,
  [3181] = 4,
    ACTIONS(285), 1,
      anon_sym_DASH_GT,
    ACTIONS(289), 1,
      anon_sym_LBRACK,
    ACTIONS(394), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3195] = 4,
    ACTIONS(285), 1,
      anon_sym_DASH_GT,
    ACTIONS(289), 1,
      anon_sym_LBRACK,
    ACTIONS(396), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3209] = 4,
    ACTIONS(332), 1,
      anon_sym_RPAREN,
    ACTIONS(398), 1,
      anon_sym_COMMA,
    STATE(135), 1,
      aux_sym__expr_list_repeat1,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3223] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(401), 2,
      anon_sym_RBRACE,
      sym_ident,
  [3232] = 3,
    ACTIONS(403), 1,
      anon_sym_RBRACE,
    STATE(140), 1,
      aux_sym_expr_if_repeat1,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3243] = 3,
    ACTIONS(405), 1,
      anon_sym_LBRACE,
    ACTIONS(407), 1,
      anon_sym_if,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3254] = 3,
    ACTIONS(409), 1,
      anon_sym_on,
    ACTIONS(411), 1,
      sym_path,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3265] = 3,
    ACTIONS(413), 1,
      anon_sym_RBRACE,
    STATE(140), 1,
      aux_sym_expr_if_repeat1,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3276] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(416), 2,
      anon_sym_RBRACE,
      sym_ident,
  [3285] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(418), 2,
      anon_sym_RBRACE,
      sym_ident,
  [3294] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(346), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [3303] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(420), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [3312] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(422), 2,
      anon_sym_RBRACE,
      sym_ident,
  [3321] = 3,
    ACTIONS(407), 1,
      anon_sym_if,
    ACTIONS(424), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3332] = 2,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
    ACTIONS(355), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [3341] = 3,
    ACTIONS(426), 1,
      anon_sym_RBRACK,
    ACTIONS(428), 1,
      anon_sym_DOT_DOT,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3352] = 3,
    ACTIONS(302), 1,
      sym_ident,
    STATE(143), 1,
      sym_arg,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3363] = 3,
    ACTIONS(430), 1,
      anon_sym_ext,
    ACTIONS(432), 1,
      anon_sym_mod,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3374] = 2,
    ACTIONS(434), 1,
      sym_ident,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3382] = 2,
    ACTIONS(436), 1,
      anon_sym_else,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3390] = 2,
    ACTIONS(438), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3398] = 2,
    ACTIONS(440), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3406] = 2,
    ACTIONS(442), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3414] = 2,
    ACTIONS(444), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3422] = 2,
    ACTIONS(446), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3430] = 2,
    ACTIONS(448), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3438] = 2,
    ACTIONS(450), 1,
      anon_sym_of,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3446] = 2,
    ACTIONS(452), 1,
      sym_nat,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3454] = 2,
    ACTIONS(454), 1,
      sym_ident,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3462] = 2,
    ACTIONS(456), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3470] = 2,
    ACTIONS(458), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3478] = 2,
    ACTIONS(460), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3486] = 2,
    ACTIONS(462), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3494] = 2,
    ACTIONS(464), 1,
      sym_ident,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3502] = 2,
    ACTIONS(466), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3510] = 2,
    ACTIONS(468), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3518] = 2,
    ACTIONS(470), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3526] = 2,
    ACTIONS(472), 1,
      sym_nat,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3534] = 2,
    ACTIONS(474), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3542] = 2,
    ACTIONS(476), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3550] = 2,
    ACTIONS(478), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3558] = 2,
    ACTIONS(480), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3566] = 2,
    ACTIONS(482), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3574] = 2,
    ACTIONS(484), 1,
      anon_sym_socket,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3582] = 2,
    ACTIONS(486), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3590] = 2,
    ACTIONS(488), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3598] = 2,
    ACTIONS(490), 1,
      anon_sym_socket,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3606] = 2,
    ACTIONS(492), 1,
      sym_ident,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3614] = 2,
    ACTIONS(494), 1,
      sym_ident,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3622] = 2,
    ACTIONS(496), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3630] = 2,
    ACTIONS(498), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3638] = 2,
    ACTIONS(500), 1,
      anon_sym_EQ_GT,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3646] = 2,
    ACTIONS(502), 1,
      sym_ident,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3654] = 2,
    ACTIONS(504), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3662] = 2,
    ACTIONS(506), 1,
      sym_ident,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3670] = 2,
    ACTIONS(508), 1,
      sym_ident,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3678] = 2,
    ACTIONS(510), 1,
      sym_ident,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3686] = 2,
    ACTIONS(512), 1,
      sym_ident,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3694] = 2,
    ACTIONS(514), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3702] = 2,
    ACTIONS(516), 1,
      sym_nat,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3710] = 2,
    ACTIONS(518), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3718] = 2,
    ACTIONS(520), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3726] = 2,
    ACTIONS(522), 1,
      anon_sym_width,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3734] = 2,
    ACTIONS(524), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3742] = 2,
    ACTIONS(526), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3750] = 2,
    ACTIONS(528), 1,
      sym_nat,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3758] = 2,
    ACTIONS(530), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3766] = 2,
    ACTIONS(532), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3774] = 2,
    ACTIONS(534), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3782] = 2,
    ACTIONS(536), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3790] = 2,
    ACTIONS(538), 1,
      sym_ident,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3798] = 2,
    ACTIONS(540), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3806] = 2,
    ACTIONS(542), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3814] = 2,
    ACTIONS(544), 1,
      sym_ident,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3822] = 2,
    ACTIONS(546), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3830] = 2,
    ACTIONS(548), 1,
      sym_ident,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3838] = 2,
    ACTIONS(550), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3846] = 2,
    ACTIONS(552), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3854] = 2,
    ACTIONS(554), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3862] = 2,
    ACTIONS(556), 1,
      sym_ident,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3870] = 2,
    ACTIONS(558), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3878] = 2,
    ACTIONS(560), 1,
      anon_sym_else,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3886] = 2,
    ACTIONS(562), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3894] = 2,
    ACTIONS(564), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3902] = 2,
    ACTIONS(566), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3910] = 2,
    ACTIONS(568), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3918] = 2,
    ACTIONS(570), 1,
      sym_ident,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3926] = 2,
    ACTIONS(572), 1,
      sym_ident,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3934] = 2,
    ACTIONS(574), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3942] = 2,
    ACTIONS(576), 1,
      sym_ident,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3950] = 2,
    ACTIONS(578), 1,
      anon_sym_mod,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3958] = 2,
    ACTIONS(580), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3966] = 2,
    ACTIONS(582), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3974] = 2,
    ACTIONS(584), 1,
      sym_ident,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3982] = 2,
    ACTIONS(586), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3990] = 2,
    ACTIONS(588), 1,
      anon_sym_else,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [3998] = 2,
    ACTIONS(590), 1,
      sym_ident,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [4006] = 2,
    ACTIONS(592), 1,
      anon_sym_LBRACK,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [4014] = 2,
    ACTIONS(594), 1,
      sym_ident,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [4022] = 2,
    ACTIONS(596), 1,
      anon_sym_type,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [4030] = 2,
    ACTIONS(598), 1,
      anon_sym_type,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [4038] = 2,
    ACTIONS(600), 1,
      anon_sym_of,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [4046] = 2,
    ACTIONS(602), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [4054] = 2,
    ACTIONS(604), 1,
      anon_sym_type,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [4062] = 2,
    ACTIONS(407), 1,
      anon_sym_if,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [4070] = 2,
    ACTIONS(606), 1,
      sym_qualident,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [4078] = 2,
    ACTIONS(608), 1,
      anon_sym_type,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [4086] = 2,
    ACTIONS(610), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [4094] = 2,
    ACTIONS(612), 1,
      sym_ident,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [4102] = 2,
    ACTIONS(614), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [4110] = 2,
    ACTIONS(616), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [4118] = 2,
    ACTIONS(432), 1,
      anon_sym_mod,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
  [4126] = 2,
    ACTIONS(618), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_comment_line,
      sym_comment_block,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 61,
  [SMALL_STATE(4)] = 122,
  [SMALL_STATE(5)] = 180,
  [SMALL_STATE(6)] = 238,
  [SMALL_STATE(7)] = 293,
  [SMALL_STATE(8)] = 344,
  [SMALL_STATE(9)] = 395,
  [SMALL_STATE(10)] = 450,
  [SMALL_STATE(11)] = 505,
  [SMALL_STATE(12)] = 560,
  [SMALL_STATE(13)] = 615,
  [SMALL_STATE(14)] = 670,
  [SMALL_STATE(15)] = 721,
  [SMALL_STATE(16)] = 776,
  [SMALL_STATE(17)] = 831,
  [SMALL_STATE(18)] = 886,
  [SMALL_STATE(19)] = 937,
  [SMALL_STATE(20)] = 992,
  [SMALL_STATE(21)] = 1047,
  [SMALL_STATE(22)] = 1098,
  [SMALL_STATE(23)] = 1153,
  [SMALL_STATE(24)] = 1208,
  [SMALL_STATE(25)] = 1259,
  [SMALL_STATE(26)] = 1310,
  [SMALL_STATE(27)] = 1358,
  [SMALL_STATE(28)] = 1406,
  [SMALL_STATE(29)] = 1454,
  [SMALL_STATE(30)] = 1478,
  [SMALL_STATE(31)] = 1499,
  [SMALL_STATE(32)] = 1517,
  [SMALL_STATE(33)] = 1536,
  [SMALL_STATE(34)] = 1553,
  [SMALL_STATE(35)] = 1570,
  [SMALL_STATE(36)] = 1587,
  [SMALL_STATE(37)] = 1604,
  [SMALL_STATE(38)] = 1621,
  [SMALL_STATE(39)] = 1638,
  [SMALL_STATE(40)] = 1655,
  [SMALL_STATE(41)] = 1672,
  [SMALL_STATE(42)] = 1689,
  [SMALL_STATE(43)] = 1706,
  [SMALL_STATE(44)] = 1723,
  [SMALL_STATE(45)] = 1740,
  [SMALL_STATE(46)] = 1757,
  [SMALL_STATE(47)] = 1774,
  [SMALL_STATE(48)] = 1791,
  [SMALL_STATE(49)] = 1808,
  [SMALL_STATE(50)] = 1825,
  [SMALL_STATE(51)] = 1842,
  [SMALL_STATE(52)] = 1867,
  [SMALL_STATE(53)] = 1892,
  [SMALL_STATE(54)] = 1907,
  [SMALL_STATE(55)] = 1922,
  [SMALL_STATE(56)] = 1947,
  [SMALL_STATE(57)] = 1962,
  [SMALL_STATE(58)] = 1987,
  [SMALL_STATE(59)] = 2002,
  [SMALL_STATE(60)] = 2017,
  [SMALL_STATE(61)] = 2032,
  [SMALL_STATE(62)] = 2047,
  [SMALL_STATE(63)] = 2062,
  [SMALL_STATE(64)] = 2077,
  [SMALL_STATE(65)] = 2092,
  [SMALL_STATE(66)] = 2117,
  [SMALL_STATE(67)] = 2132,
  [SMALL_STATE(68)] = 2147,
  [SMALL_STATE(69)] = 2162,
  [SMALL_STATE(70)] = 2177,
  [SMALL_STATE(71)] = 2192,
  [SMALL_STATE(72)] = 2207,
  [SMALL_STATE(73)] = 2222,
  [SMALL_STATE(74)] = 2237,
  [SMALL_STATE(75)] = 2252,
  [SMALL_STATE(76)] = 2276,
  [SMALL_STATE(77)] = 2295,
  [SMALL_STATE(78)] = 2314,
  [SMALL_STATE(79)] = 2333,
  [SMALL_STATE(80)] = 2352,
  [SMALL_STATE(81)] = 2373,
  [SMALL_STATE(82)] = 2392,
  [SMALL_STATE(83)] = 2411,
  [SMALL_STATE(84)] = 2432,
  [SMALL_STATE(85)] = 2453,
  [SMALL_STATE(86)] = 2468,
  [SMALL_STATE(87)] = 2483,
  [SMALL_STATE(88)] = 2502,
  [SMALL_STATE(89)] = 2521,
  [SMALL_STATE(90)] = 2540,
  [SMALL_STATE(91)] = 2559,
  [SMALL_STATE(92)] = 2578,
  [SMALL_STATE(93)] = 2597,
  [SMALL_STATE(94)] = 2616,
  [SMALL_STATE(95)] = 2635,
  [SMALL_STATE(96)] = 2655,
  [SMALL_STATE(97)] = 2673,
  [SMALL_STATE(98)] = 2687,
  [SMALL_STATE(99)] = 2702,
  [SMALL_STATE(100)] = 2719,
  [SMALL_STATE(101)] = 2734,
  [SMALL_STATE(102)] = 2751,
  [SMALL_STATE(103)] = 2766,
  [SMALL_STATE(104)] = 2781,
  [SMALL_STATE(105)] = 2796,
  [SMALL_STATE(106)] = 2811,
  [SMALL_STATE(107)] = 2828,
  [SMALL_STATE(108)] = 2843,
  [SMALL_STATE(109)] = 2858,
  [SMALL_STATE(110)] = 2873,
  [SMALL_STATE(111)] = 2888,
  [SMALL_STATE(112)] = 2905,
  [SMALL_STATE(113)] = 2919,
  [SMALL_STATE(114)] = 2933,
  [SMALL_STATE(115)] = 2947,
  [SMALL_STATE(116)] = 2961,
  [SMALL_STATE(117)] = 2975,
  [SMALL_STATE(118)] = 2989,
  [SMALL_STATE(119)] = 3003,
  [SMALL_STATE(120)] = 3013,
  [SMALL_STATE(121)] = 3027,
  [SMALL_STATE(122)] = 3041,
  [SMALL_STATE(123)] = 3055,
  [SMALL_STATE(124)] = 3065,
  [SMALL_STATE(125)] = 3079,
  [SMALL_STATE(126)] = 3091,
  [SMALL_STATE(127)] = 3105,
  [SMALL_STATE(128)] = 3115,
  [SMALL_STATE(129)] = 3129,
  [SMALL_STATE(130)] = 3143,
  [SMALL_STATE(131)] = 3157,
  [SMALL_STATE(132)] = 3171,
  [SMALL_STATE(133)] = 3181,
  [SMALL_STATE(134)] = 3195,
  [SMALL_STATE(135)] = 3209,
  [SMALL_STATE(136)] = 3223,
  [SMALL_STATE(137)] = 3232,
  [SMALL_STATE(138)] = 3243,
  [SMALL_STATE(139)] = 3254,
  [SMALL_STATE(140)] = 3265,
  [SMALL_STATE(141)] = 3276,
  [SMALL_STATE(142)] = 3285,
  [SMALL_STATE(143)] = 3294,
  [SMALL_STATE(144)] = 3303,
  [SMALL_STATE(145)] = 3312,
  [SMALL_STATE(146)] = 3321,
  [SMALL_STATE(147)] = 3332,
  [SMALL_STATE(148)] = 3341,
  [SMALL_STATE(149)] = 3352,
  [SMALL_STATE(150)] = 3363,
  [SMALL_STATE(151)] = 3374,
  [SMALL_STATE(152)] = 3382,
  [SMALL_STATE(153)] = 3390,
  [SMALL_STATE(154)] = 3398,
  [SMALL_STATE(155)] = 3406,
  [SMALL_STATE(156)] = 3414,
  [SMALL_STATE(157)] = 3422,
  [SMALL_STATE(158)] = 3430,
  [SMALL_STATE(159)] = 3438,
  [SMALL_STATE(160)] = 3446,
  [SMALL_STATE(161)] = 3454,
  [SMALL_STATE(162)] = 3462,
  [SMALL_STATE(163)] = 3470,
  [SMALL_STATE(164)] = 3478,
  [SMALL_STATE(165)] = 3486,
  [SMALL_STATE(166)] = 3494,
  [SMALL_STATE(167)] = 3502,
  [SMALL_STATE(168)] = 3510,
  [SMALL_STATE(169)] = 3518,
  [SMALL_STATE(170)] = 3526,
  [SMALL_STATE(171)] = 3534,
  [SMALL_STATE(172)] = 3542,
  [SMALL_STATE(173)] = 3550,
  [SMALL_STATE(174)] = 3558,
  [SMALL_STATE(175)] = 3566,
  [SMALL_STATE(176)] = 3574,
  [SMALL_STATE(177)] = 3582,
  [SMALL_STATE(178)] = 3590,
  [SMALL_STATE(179)] = 3598,
  [SMALL_STATE(180)] = 3606,
  [SMALL_STATE(181)] = 3614,
  [SMALL_STATE(182)] = 3622,
  [SMALL_STATE(183)] = 3630,
  [SMALL_STATE(184)] = 3638,
  [SMALL_STATE(185)] = 3646,
  [SMALL_STATE(186)] = 3654,
  [SMALL_STATE(187)] = 3662,
  [SMALL_STATE(188)] = 3670,
  [SMALL_STATE(189)] = 3678,
  [SMALL_STATE(190)] = 3686,
  [SMALL_STATE(191)] = 3694,
  [SMALL_STATE(192)] = 3702,
  [SMALL_STATE(193)] = 3710,
  [SMALL_STATE(194)] = 3718,
  [SMALL_STATE(195)] = 3726,
  [SMALL_STATE(196)] = 3734,
  [SMALL_STATE(197)] = 3742,
  [SMALL_STATE(198)] = 3750,
  [SMALL_STATE(199)] = 3758,
  [SMALL_STATE(200)] = 3766,
  [SMALL_STATE(201)] = 3774,
  [SMALL_STATE(202)] = 3782,
  [SMALL_STATE(203)] = 3790,
  [SMALL_STATE(204)] = 3798,
  [SMALL_STATE(205)] = 3806,
  [SMALL_STATE(206)] = 3814,
  [SMALL_STATE(207)] = 3822,
  [SMALL_STATE(208)] = 3830,
  [SMALL_STATE(209)] = 3838,
  [SMALL_STATE(210)] = 3846,
  [SMALL_STATE(211)] = 3854,
  [SMALL_STATE(212)] = 3862,
  [SMALL_STATE(213)] = 3870,
  [SMALL_STATE(214)] = 3878,
  [SMALL_STATE(215)] = 3886,
  [SMALL_STATE(216)] = 3894,
  [SMALL_STATE(217)] = 3902,
  [SMALL_STATE(218)] = 3910,
  [SMALL_STATE(219)] = 3918,
  [SMALL_STATE(220)] = 3926,
  [SMALL_STATE(221)] = 3934,
  [SMALL_STATE(222)] = 3942,
  [SMALL_STATE(223)] = 3950,
  [SMALL_STATE(224)] = 3958,
  [SMALL_STATE(225)] = 3966,
  [SMALL_STATE(226)] = 3974,
  [SMALL_STATE(227)] = 3982,
  [SMALL_STATE(228)] = 3990,
  [SMALL_STATE(229)] = 3998,
  [SMALL_STATE(230)] = 4006,
  [SMALL_STATE(231)] = 4014,
  [SMALL_STATE(232)] = 4022,
  [SMALL_STATE(233)] = 4030,
  [SMALL_STATE(234)] = 4038,
  [SMALL_STATE(235)] = 4046,
  [SMALL_STATE(236)] = 4054,
  [SMALL_STATE(237)] = 4062,
  [SMALL_STATE(238)] = 4070,
  [SMALL_STATE(239)] = 4078,
  [SMALL_STATE(240)] = 4086,
  [SMALL_STATE(241)] = 4094,
  [SMALL_STATE(242)] = 4102,
  [SMALL_STATE(243)] = 4110,
  [SMALL_STATE(244)] = 4118,
  [SMALL_STATE(245)] = 4126,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(231),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(150),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(244),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(241),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(239),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(236),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(233),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(232),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(229),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(226),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(70),
  [37] = {.entry = {.count = 1, .reusable = false}}, SHIFT(71),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [41] = {.entry = {.count = 1, .reusable = false}}, SHIFT(73),
  [43] = {.entry = {.count = 1, .reusable = false}}, SHIFT(62),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(235),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expr_list, 2, 0, 0),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expr_list, 3, 0, 0),
  [55] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_moddef_repeat1, 2, 0, 0), SHIFT_REPEAT(190),
  [58] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_moddef_repeat1, 2, 0, 0),
  [60] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_moddef_repeat1, 2, 0, 0), SHIFT_REPEAT(189),
  [63] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_moddef_repeat1, 2, 0, 0), SHIFT_REPEAT(187),
  [66] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_moddef_repeat1, 2, 0, 0), SHIFT_REPEAT(185),
  [69] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_moddef_repeat1, 2, 0, 0), SHIFT_REPEAT(181),
  [72] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_moddef_repeat1, 2, 0, 0), SHIFT_REPEAT(180),
  [75] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_moddef_repeat1, 2, 0, 0), SHIFT_REPEAT(179),
  [78] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_moddef_repeat1, 2, 0, 0), SHIFT_REPEAT(125),
  [81] = {.entry = {.count = 1, .reusable = false}}, SHIFT(190),
  [83] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [85] = {.entry = {.count = 1, .reusable = false}}, SHIFT(189),
  [87] = {.entry = {.count = 1, .reusable = false}}, SHIFT(187),
  [89] = {.entry = {.count = 1, .reusable = false}}, SHIFT(185),
  [91] = {.entry = {.count = 1, .reusable = false}}, SHIFT(181),
  [93] = {.entry = {.count = 1, .reusable = false}}, SHIFT(180),
  [95] = {.entry = {.count = 1, .reusable = false}}, SHIFT(179),
  [97] = {.entry = {.count = 1, .reusable = false}}, SHIFT(125),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package, 1, 0, 0),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package, 2, 0, 0),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_package_repeat2, 2, 0, 0),
  [115] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_package_repeat2, 2, 0, 0), SHIFT_REPEAT(150),
  [118] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_package_repeat2, 2, 0, 0), SHIFT_REPEAT(244),
  [121] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_package_repeat2, 2, 0, 0), SHIFT_REPEAT(241),
  [124] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_package_repeat2, 2, 0, 0), SHIFT_REPEAT(239),
  [127] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_package_repeat2, 2, 0, 0), SHIFT_REPEAT(236),
  [130] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_package_repeat2, 2, 0, 0), SHIFT_REPEAT(233),
  [133] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_package_repeat2, 2, 0, 0), SHIFT_REPEAT(232),
  [136] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_package_repeat2, 2, 0, 0), SHIFT_REPEAT(229),
  [139] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_package_repeat2, 2, 0, 0), SHIFT_REPEAT(226),
  [142] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_package_repeat1, 2, 0, 0),
  [144] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_package_repeat1, 2, 0, 0), SHIFT_REPEAT(231),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_connect_type, 1, 0, 0),
  [149] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_connect_type, 1, 0, 0),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_import, 3, 0, 0),
  [153] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_moddef_repeat1, 2, 0, 0),
  [155] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_socketdef, 4, 0, 1),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fndef, 9, 0, 1),
  [159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_moddef, 5, 0, 2),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_moddef, 5, 0, 1),
  [163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_structdef, 5, 0, 2),
  [165] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_moddef, 6, 0, 2),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fndef, 10, 0, 1),
  [169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enumdef, 7, 0, 2),
  [171] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_moddef, 4, 0, 1),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_builtindef, 5, 0, 2),
  [175] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uniondef, 6, 0, 2),
  [177] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_item, 1, 0, 0),
  [179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_moddef, 6, 0, 3),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enumdef, 8, 0, 2),
  [183] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_socketdef, 5, 0, 1),
  [185] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_structdef, 6, 0, 2),
  [187] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_moddef, 7, 0, 3),
  [189] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uniondef, 5, 0, 2),
  [191] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [193] = {.entry = {.count = 1, .reusable = false}}, SHIFT(127),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [197] = {.entry = {.count = 1, .reusable = true}}, SHIFT(183),
  [199] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_expr_match_repeat1, 2, 0, 0),
  [201] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_expr_match_repeat1, 2, 0, 0), SHIFT_REPEAT(127),
  [204] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_expr_match_repeat1, 2, 0, 0), SHIFT_REPEAT(127),
  [207] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_expr_match_repeat1, 2, 0, 0), SHIFT_REPEAT(183),
  [210] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expr_call, 3, 0, 0),
  [212] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expr, 1, 0, 0),
  [214] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [216] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expr_lit, 1, 0, 0),
  [218] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [220] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expr_match, 4, 0, 0),
  [222] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expr, 3, 0, 0),
  [224] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expr_if, 10, 0, 0),
  [226] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expr_idx, 4, 0, 0),
  [228] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_word_lit, 1, 0, 0),
  [230] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expr_match, 5, 0, 0),
  [232] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expr_call, 4, 0, 9),
  [234] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [236] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expr_call, 5, 0, 10),
  [238] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expr_match, 6, 0, 0),
  [240] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expr_call, 6, 0, 11),
  [242] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expr_idx, 6, 0, 0),
  [244] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool, 1, 0, 0),
  [246] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expr_reference, 1, 0, 0),
  [248] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expr_match, 7, 0, 0),
  [250] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_word, 1, 0, 0),
  [252] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expr_if, 9, 0, 0),
  [254] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [256] = {.entry = {.count = 1, .reusable = false}}, SHIFT(85),
  [258] = {.entry = {.count = 1, .reusable = false}}, SHIFT(230),
  [260] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [264] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_patlist, 3, 0, 0),
  [266] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [268] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_patlist, 2, 0, 0),
  [270] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1, 0, 0),
  [272] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type, 1, 0, 0),
  [274] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_word, 4, 0, 0),
  [276] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_word, 4, 0, 0),
  [278] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_socketdef_repeat1, 2, 0, 0),
  [280] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_socketdef_repeat1, 2, 0, 0), SHIFT_REPEAT(166),
  [283] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expr_list, 1, 0, 0),
  [285] = {.entry = {.count = 1, .reusable = true}}, SHIFT(188),
  [287] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [289] = {.entry = {.count = 1, .reusable = true}}, SHIFT(198),
  [291] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_match_arm, 4, 0, 0),
  [293] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_match_arm, 4, 0, 0),
  [295] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_uniondef_repeat1, 2, 0, 0),
  [297] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_uniondef_repeat1, 2, 0, 0), SHIFT_REPEAT(182),
  [300] = {.entry = {.count = 1, .reusable = true}}, SHIFT(155),
  [302] = {.entry = {.count = 1, .reusable = true}}, SHIFT(168),
  [304] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_enumdef_repeat1, 2, 0, 0),
  [306] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_enumdef_repeat1, 2, 0, 0), SHIFT_REPEAT(158),
  [309] = {.entry = {.count = 1, .reusable = true}}, SHIFT(152),
  [311] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [313] = {.entry = {.count = 1, .reusable = true}}, SHIFT(158),
  [315] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_structdef_repeat1, 2, 0, 0),
  [317] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_structdef_repeat1, 2, 0, 0), SHIFT_REPEAT(153),
  [320] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [322] = {.entry = {.count = 1, .reusable = true}}, SHIFT(153),
  [324] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [326] = {.entry = {.count = 1, .reusable = true}}, SHIFT(169),
  [328] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [330] = {.entry = {.count = 1, .reusable = true}}, SHIFT(182),
  [332] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__expr_list_repeat1, 2, 0, 0),
  [334] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [336] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [338] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [340] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [342] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_param_list, 1, 0, 0),
  [344] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [346] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_param_list_repeat1, 2, 0, 0),
  [348] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_param_list_repeat1, 2, 0, 0), SHIFT_REPEAT(149),
  [351] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [353] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [355] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_patlist_repeat1, 2, 0, 0),
  [357] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_patlist_repeat1, 2, 0, 0), SHIFT_REPEAT(96),
  [360] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_param_list, 2, 0, 0),
  [362] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [364] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_channel, 5, 0, 0),
  [366] = {.entry = {.count = 1, .reusable = true}}, SHIFT(242),
  [368] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [370] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_connect, 3, 0, 4),
  [372] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pat, 4, 0, 0),
  [374] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [376] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [378] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [380] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pat, 1, 0, 0),
  [382] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_patlist, 1, 0, 0),
  [384] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [386] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [388] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_param_list, 3, 0, 0),
  [390] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [392] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pat, 3, 0, 0),
  [394] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [396] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [398] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__expr_list_repeat1, 2, 0, 0), SHIFT_REPEAT(17),
  [401] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enumdef_statement, 4, 0, 0),
  [403] = {.entry = {.count = 1, .reusable = true}}, SHIFT(214),
  [405] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [407] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [409] = {.entry = {.count = 1, .reusable = false}}, SHIFT(164),
  [411] = {.entry = {.count = 1, .reusable = false}}, SHIFT(165),
  [413] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_expr_if_repeat1, 2, 0, 0), SHIFT_REPEAT(228),
  [416] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_field, 4, 0, 0),
  [418] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_alt, 5, 0, 0),
  [420] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg, 3, 0, 0),
  [422] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_alt, 4, 0, 0),
  [424] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [426] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [428] = {.entry = {.count = 1, .reusable = true}}, SHIFT(192),
  [430] = {.entry = {.count = 1, .reusable = true}}, SHIFT(223),
  [432] = {.entry = {.count = 1, .reusable = true}}, SHIFT(222),
  [434] = {.entry = {.count = 1, .reusable = true}}, SHIFT(174),
  [436] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [438] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [440] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [442] = {.entry = {.count = 1, .reusable = true}}, SHIFT(145),
  [444] = {.entry = {.count = 1, .reusable = true}}, SHIFT(175),
  [446] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [448] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [450] = {.entry = {.count = 1, .reusable = true}}, SHIFT(238),
  [452] = {.entry = {.count = 1, .reusable = true}}, SHIFT(178),
  [454] = {.entry = {.count = 1, .reusable = true}}, SHIFT(240),
  [456] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [458] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [460] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_reg, 5, 0, 6),
  [462] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_reg, 5, 0, 7),
  [464] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_channeldir, 1, 0, 0),
  [466] = {.entry = {.count = 1, .reusable = true}}, SHIFT(243),
  [468] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [470] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [472] = {.entry = {.count = 1, .reusable = true}}, SHIFT(245),
  [474] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [476] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [478] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [480] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_socket, 5, 0, 8),
  [482] = {.entry = {.count = 1, .reusable = true}}, SHIFT(142),
  [484] = {.entry = {.count = 1, .reusable = true}}, SHIFT(219),
  [486] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [488] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [490] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_socket_role, 1, 0, 0),
  [492] = {.entry = {.count = 1, .reusable = true}}, SHIFT(217),
  [494] = {.entry = {.count = 1, .reusable = true}}, SHIFT(216),
  [496] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [498] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [500] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [502] = {.entry = {.count = 1, .reusable = true}}, SHIFT(197),
  [504] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [506] = {.entry = {.count = 1, .reusable = true}}, SHIFT(193),
  [508] = {.entry = {.count = 1, .reusable = true}}, SHIFT(173),
  [510] = {.entry = {.count = 1, .reusable = true}}, SHIFT(157),
  [512] = {.entry = {.count = 1, .reusable = true}}, SHIFT(159),
  [514] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [516] = {.entry = {.count = 1, .reusable = true}}, SHIFT(210),
  [518] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [520] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
  [522] = {.entry = {.count = 1, .reusable = true}}, SHIFT(170),
  [524] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [526] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [528] = {.entry = {.count = 1, .reusable = true}}, SHIFT(148),
  [530] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_wire, 4, 0, 6),
  [532] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [534] = {.entry = {.count = 1, .reusable = true}}, SHIFT(171),
  [536] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [538] = {.entry = {.count = 1, .reusable = true}}, SHIFT(191),
  [540] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [542] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [544] = {.entry = {.count = 1, .reusable = true}}, SHIFT(195),
  [546] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_outgoing, 4, 0, 6),
  [548] = {.entry = {.count = 1, .reusable = true}}, SHIFT(196),
  [550] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [552] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [554] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_incoming, 4, 0, 6),
  [556] = {.entry = {.count = 1, .reusable = true}}, SHIFT(200),
  [558] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_implicit, 4, 0, 6),
  [560] = {.entry = {.count = 1, .reusable = true}}, SHIFT(146),
  [562] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_submodule, 4, 0, 5),
  [564] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [566] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [568] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [570] = {.entry = {.count = 1, .reusable = true}}, SHIFT(234),
  [572] = {.entry = {.count = 1, .reusable = true}}, SHIFT(201),
  [574] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [576] = {.entry = {.count = 1, .reusable = true}}, SHIFT(202),
  [578] = {.entry = {.count = 1, .reusable = true}}, SHIFT(203),
  [580] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [582] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [584] = {.entry = {.count = 1, .reusable = true}}, SHIFT(204),
  [586] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [588] = {.entry = {.count = 1, .reusable = true}}, SHIFT(237),
  [590] = {.entry = {.count = 1, .reusable = true}}, SHIFT(205),
  [592] = {.entry = {.count = 1, .reusable = true}}, SHIFT(160),
  [594] = {.entry = {.count = 1, .reusable = true}}, SHIFT(224),
  [596] = {.entry = {.count = 1, .reusable = true}}, SHIFT(206),
  [598] = {.entry = {.count = 1, .reusable = true}}, SHIFT(208),
  [600] = {.entry = {.count = 1, .reusable = true}}, SHIFT(151),
  [602] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [604] = {.entry = {.count = 1, .reusable = true}}, SHIFT(212),
  [606] = {.entry = {.count = 1, .reusable = true}}, SHIFT(215),
  [608] = {.entry = {.count = 1, .reusable = true}}, SHIFT(220),
  [610] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [612] = {.entry = {.count = 1, .reusable = true}}, SHIFT(221),
  [614] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_expr_if_repeat1, 5, 0, 0),
  [616] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [618] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_virdant(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
