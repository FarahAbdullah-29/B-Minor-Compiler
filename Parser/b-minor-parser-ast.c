/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "b-minor-parser.y" /* yacc.c:339  */

#include "ast_library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* The result of parsing (root of tree)
    starts with a declaration node.
    A B-Minor program is represented
    as a list of declarations. */
struct decl * parser_result = 0;

/* Error reporting function */
extern void yyerror(const char *);

/* Lexing function and lexeme from
    Flex-generated scanner */
extern int yylex();
extern char *yytext;

#line 87 "b-minor-parser-ast.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "tokens.h".  */
#ifndef YY_YY_TOKENS_H_INCLUDED
# define YY_YY_TOKENS_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOKEN_ARRAY = 258,
    TOKEN_BOOLEAN = 259,
    TOKEN_CHAR = 260,
    TOKEN_ELSE = 261,
    TOKEN_FALSE = 262,
    TOKEN_FOR = 263,
    TOKEN_FUNCTION = 264,
    TOKEN_IF = 265,
    TOKEN_INTEGER = 266,
    TOKEN_PRINT = 267,
    TOKEN_RETURN = 268,
    TOKEN_STRING = 269,
    TOKEN_TRUE = 270,
    TOKEN_VOID = 271,
    TOKEN_WHILE = 272,
    TOKEN_LITERAL_INT = 273,
    TOKEN_LITERAL_CHAR = 274,
    TOKEN_LITERAL_STRING = 275,
    TOKEN_IDENT = 276,
    TOKEN_POSTFIX_ADD = 277,
    TOKEN_POSTFIX_MINUS = 278,
    TOKEN_GREATER_EQUAL = 279,
    TOKEN_LESS_EQUAL = 280,
    TOKEN_EQUAL = 281,
    TOKEN_NOT_EQUAL = 282,
    TOKEN_NOT = 283,
    TOKEN_LOGICAL_AND = 284,
    TOKEN_LOGICAL_OR = 285,
    TOKEN_LPAREN = 286,
    TOKEN_RPAREN = 287,
    TOKEN_LBRACKET = 288,
    TOKEN_RBRACKET = 289,
    TOKEN_LBRACE = 290,
    TOKEN_RBRACE = 291,
    TOKEN_EXPONENTIATION = 292,
    TOKEN_MUL = 293,
    TOKEN_DIV = 294,
    TOKEN_MOD = 295,
    TOKEN_PLUS = 296,
    TOKEN_MINUS = 297,
    TOKEN_COMMA = 298,
    TOKEN_GREATER = 299,
    TOKEN_LESS = 300,
    TOKEN_ASSIGN = 301,
    TOKEN_COLON = 302,
    TOKEN_SEMI = 303,
    TOKEN_ERROR = 304,
    NO_ELSE = 305
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 75 "b-minor-parser.y" /* yacc.c:355  */

  struct decl *decl;
  struct stmt *stmt;
  struct expr *expr;
  struct type *type;
  struct param_list *param_list;
  char *name;
  int value;

#line 188 "b-minor-parser-ast.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TOKENS_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 205 "b-minor-parser-ast.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   193

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  168

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    95,    95,    99,   100,   104,   105,   109,   110,   111,
     112,   116,   120,   124,   125,   129,   130,   134,   138,   139,
     143,   144,   148,   149,   153,   154,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   170,   171,   175,   179,   180,
     184,   185,   189,   193,   194,   198,   202,   203,   207,   208,
     212,   213,   214,   218,   219,   220,   221,   225,   226,   230,
     231,   232,   233,   234,   235,   236,   240,   244,   249,   250,
     254,   258,   262,   266,   267,   271,   272,   276,   277,   281,
     282,   283,   287,   288,   289,   290,   291,   295,   296,   297,
     298,   302,   303,   307,   308,   309,   310,   311,   312,   316,
     317
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_ARRAY", "TOKEN_BOOLEAN",
  "TOKEN_CHAR", "TOKEN_ELSE", "TOKEN_FALSE", "TOKEN_FOR", "TOKEN_FUNCTION",
  "TOKEN_IF", "TOKEN_INTEGER", "TOKEN_PRINT", "TOKEN_RETURN",
  "TOKEN_STRING", "TOKEN_TRUE", "TOKEN_VOID", "TOKEN_WHILE",
  "TOKEN_LITERAL_INT", "TOKEN_LITERAL_CHAR", "TOKEN_LITERAL_STRING",
  "TOKEN_IDENT", "TOKEN_POSTFIX_ADD", "TOKEN_POSTFIX_MINUS",
  "TOKEN_GREATER_EQUAL", "TOKEN_LESS_EQUAL", "TOKEN_EQUAL",
  "TOKEN_NOT_EQUAL", "TOKEN_NOT", "TOKEN_LOGICAL_AND", "TOKEN_LOGICAL_OR",
  "TOKEN_LPAREN", "TOKEN_RPAREN", "TOKEN_LBRACKET", "TOKEN_RBRACKET",
  "TOKEN_LBRACE", "TOKEN_RBRACE", "TOKEN_EXPONENTIATION", "TOKEN_MUL",
  "TOKEN_DIV", "TOKEN_MOD", "TOKEN_PLUS", "TOKEN_MINUS", "TOKEN_COMMA",
  "TOKEN_GREATER", "TOKEN_LESS", "TOKEN_ASSIGN", "TOKEN_COLON",
  "TOKEN_SEMI", "TOKEN_ERROR", "NO_ELSE", "$accept", "program", "globals",
  "global", "var_decl", "length", "array_init", "val_list",
  "function_decl", "function_def", "params", "param_list", "param",
  "stmts", "stmt", "stmt_block", "function_call", "args", "arg_list",
  "arg", "assignment", "identifier", "expr", "lo_expr", "pm_expr", "term",
  "expon", "factor", "not", "array_element", "if_stmt", "for_stmt",
  "return_stmt", "print_stmt", "postfix", "opt_assignment", "opt_expr",
  "opt_increment", "literal", "atomic_type", "return_type",
  "relational_op", "logical_op", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

#define YYPACT_NINF -124

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-124)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -14,  -124,    14,  -124,   -14,   -31,  -124,   -26,  -124,  -124,
    -124,   108,    -1,  -124,  -124,    38,  -124,  -124,    -2,    29,
    -124,  -124,    19,    20,  -124,    31,   -14,  -124,  -124,  -124,
    -124,  -124,    20,    20,    20,  -124,    42,    80,    59,   103,
     110,    41,  -124,  -124,  -124,  -124,    86,    56,  -124,    73,
      52,    80,    98,    80,    20,    20,  -124,  -124,    20,  -124,
    -124,  -124,  -124,  -124,  -124,    20,    20,    20,    20,    20,
      20,    20,    75,    50,   -14,   120,  -124,    94,  -124,    97,
      80,    -5,    59,   103,   110,   110,    41,    41,    41,  -124,
     107,   112,  -124,  -124,   100,  -124,  -124,    20,  -124,    87,
    -124,    10,  -124,  -124,   124,  -124,   118,   119,   130,   133,
      20,    20,  -124,   115,   129,    45,  -124,   121,   122,    46,
     125,  -124,  -124,   126,   127,   128,    86,  -124,    87,   -14,
      20,  -124,    80,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
      20,   132,    20,  -124,  -124,  -124,  -124,  -124,  -124,   -18,
     131,   109,    80,    80,    20,    45,    80,   134,   161,   -14,
      45,  -124,    49,  -124,   136,  -124,    45,  -124
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    45,     0,     2,     4,     0,     6,     0,     1,     3,
       5,     0,     0,    87,    89,     0,    88,    90,     7,     0,
      92,    91,     0,     0,    11,     0,    19,    83,    82,    84,
      85,    86,     0,     0,     0,    65,    61,     8,    47,    49,
      52,    56,    58,    63,    64,    62,     0,     0,    18,    20,
       0,    66,     0,    59,    39,     0,    99,   100,     0,    96,
      98,    93,    94,    95,    97,     0,     0,     0,     0,     0,
       0,     0,     9,     0,     0,     0,    60,     0,    38,    40,
      42,     0,    46,    48,    50,    51,    53,    54,    55,    57,
       0,     0,    15,    21,     0,    22,    37,     0,    67,     0,
      10,     0,    16,    17,     0,    41,     0,    13,     0,     0,
      39,     0,    36,     0,     0,    24,    33,     0,     0,     0,
       0,    31,    32,     0,     0,     0,     0,    12,     0,    76,
       0,    72,    71,    27,    35,    25,    26,    28,    73,    74,
       0,     0,     0,    34,    30,    29,    23,    14,    75,     0,
       0,     0,    43,    44,    78,     0,    77,     0,    68,    81,
       0,    79,     0,    80,     0,    69,     0,    70
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -124,  -124,   168,  -124,     9,  -124,  -124,    53,  -124,  -124,
    -124,    99,  -124,    62,   -79,    89,   -96,    68,    88,  -124,
    -123,     0,   -22,   135,   123,    90,    83,   113,  -124,   -99,
    -124,  -124,  -124,  -124,    24,  -124,  -124,  -124,   -91,   -12,
    -124,  -124,  -124
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,   113,    25,   100,   106,     6,   102,
      47,    48,    49,   114,   115,   116,    35,    77,    78,    79,
     118,    36,    80,    38,    39,    40,    41,    42,    43,    44,
     121,   122,   123,   124,   125,   150,   157,   164,    45,    18,
      22,    65,    58
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       7,    37,   120,    21,     7,   117,   148,     1,   107,     5,
      51,    52,    53,     5,     8,    55,   120,    10,   108,   117,
     109,    11,   110,   111,    56,    57,    50,    27,   140,    98,
     120,     1,    19,    81,    72,    28,   161,   107,    29,    30,
      31,     1,    13,    14,    23,   101,   112,    24,    32,    16,
      26,    33,    17,   108,    20,   109,   120,   110,   111,   117,
     120,   120,    34,    95,   117,    46,     1,   120,   138,   139,
     117,   138,   139,    54,    50,    55,   158,    54,    71,    55,
     101,   165,    55,    59,    60,    61,    62,   167,    73,   132,
      13,    14,   140,   141,    27,   140,    91,    16,    92,    75,
      17,   119,    28,    63,    64,    29,    30,    31,   151,    56,
      57,    12,    13,    14,   146,   119,    74,    15,   152,    16,
     153,    90,    17,    94,    13,    14,    96,    56,    57,   149,
      76,    16,   156,   104,    17,    12,    13,    14,    56,    57,
      97,   155,    99,    16,    66,    67,    17,   101,    68,    69,
      70,    86,    87,    88,   127,   119,    84,    85,   126,   162,
     119,   129,   128,   133,   130,   134,   119,   160,   166,   136,
     137,   142,     9,    93,   143,   144,   145,   135,   131,   154,
     103,   147,   159,   163,    89,   105,     0,     0,    83,     0,
       0,     0,     0,    82
};

static const yytype_int16 yycheck[] =
{
       0,    23,   101,    15,     4,   101,   129,    21,    99,     0,
      32,    33,    34,     4,     0,    33,   115,    48,     8,   115,
      10,    47,    12,    13,    29,    30,    26,     7,    46,    34,
     129,    21,    33,    55,    46,    15,   159,   128,    18,    19,
      20,    21,     4,     5,    46,    35,    36,    18,    28,    11,
      31,    31,    14,     8,    16,    10,   155,    12,    13,   155,
     159,   160,    42,    75,   160,    34,    21,   166,    22,    23,
     166,    22,    23,    31,    74,    33,   155,    31,    37,    33,
      35,   160,    33,    24,    25,    26,    27,   166,    32,   111,
       4,     5,    46,    47,     7,    46,    46,    11,    48,    47,
      14,   101,    15,    44,    45,    18,    19,    20,   130,    29,
      30,     3,     4,     5,   126,   115,    43,     9,   140,    11,
     142,    46,    14,     3,     4,     5,    32,    29,    30,   129,
      32,    11,   154,    33,    14,     3,     4,     5,    29,    30,
      43,    32,    35,    11,    41,    42,    14,    35,    38,    39,
      40,    68,    69,    70,    36,   155,    66,    67,    34,   159,
     160,    31,    43,    48,    31,    36,   166,     6,    32,    48,
      48,    46,     4,    74,    48,    48,    48,   115,   110,    48,
      91,   128,    48,   159,    71,    97,    -1,    -1,    65,    -1,
      -1,    -1,    -1,    58
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    21,    52,    53,    54,    55,    59,    72,     0,    53,
      48,    47,     3,     4,     5,     9,    11,    14,    90,    33,
      16,    90,    91,    46,    18,    56,    31,     7,    15,    18,
      19,    20,    28,    31,    42,    67,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    89,    34,    61,    62,    63,
      72,    73,    73,    73,    31,    33,    29,    30,    93,    24,
      25,    26,    27,    44,    45,    92,    41,    42,    38,    39,
      40,    37,    90,    32,    43,    47,    32,    68,    69,    70,
      73,    73,    74,    75,    76,    76,    77,    77,    77,    78,
      46,    46,    48,    62,     3,    90,    32,    43,    34,    35,
      57,    35,    60,    66,    33,    69,    58,    89,     8,    10,
      12,    13,    36,    55,    64,    65,    66,    67,    71,    72,
      80,    81,    82,    83,    84,    85,    34,    36,    43,    31,
      31,    68,    73,    48,    36,    64,    48,    48,    22,    23,
      46,    47,    46,    48,    48,    48,    90,    58,    71,    72,
      86,    73,    73,    73,    48,    32,    73,    87,    65,    48,
       6,    71,    72,    85,    88,    65,    32,    65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    55,    55,    55,
      55,    56,    57,    58,    58,    59,    59,    60,    61,    61,
      62,    62,    63,    63,    64,    64,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    66,    66,    67,    68,    68,
      69,    69,    70,    71,    71,    72,    73,    73,    74,    74,
      75,    75,    75,    76,    76,    76,    76,    77,    77,    78,
      78,    78,    78,    78,    78,    78,    79,    80,    81,    81,
      82,    83,    84,    85,    85,    86,    86,    87,    87,    88,
      88,    88,    89,    89,    89,    89,    89,    90,    90,    90,
      90,    91,    91,    92,    92,    92,    92,    92,    92,    93,
      93
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     3,     5,     7,
       9,     1,     3,     1,     3,     8,     9,     1,     1,     0,
       1,     3,     3,     6,     1,     2,     2,     2,     2,     2,
       2,     1,     1,     1,     2,     3,     2,     4,     1,     0,
       1,     3,     1,     3,     3,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     1,     3,     1,     2,
       3,     1,     1,     1,     1,     1,     2,     4,     5,     7,
       9,     2,     2,     2,     2,     1,     0,     1,     0,     1,
       1,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 95 "b-minor-parser.y" /* yacc.c:1646  */
    { parser_result = (yyvsp[0].decl); printf(">=================>program: globals\n"); }
#line 1423 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 3:
#line 99 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.decl) = (yyvsp[-1].decl); (yyvsp[-1].decl)->next = (yyvsp[0].decl); printf(">=================>globals: global\n");}
#line 1429 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 4:
#line 100 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.decl) = 0; printf(">=================>globals: epsilon\n"); }
#line 1435 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 5:
#line 104 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.decl) = (yyvsp[-1].decl); printf(">=================>global: var_decl\n");}
#line 1441 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 6:
#line 105 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.decl) = (yyvsp[0].decl); printf(">=================>global: function decl\n"); }
#line 1447 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 7:
#line 109 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.decl) = decl_create((yyvsp[-2].name), (yyvsp[0].type), 0, 0, 0); printf(">==t10===============>var_decl: declaration only %s\n", (yyvsp[-2].name)); }
#line 1453 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 8:
#line 110 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.decl) = decl_create((yyvsp[-4].name), (yyvsp[-2].type), (yyvsp[0].expr), 0, 0); printf(">==t11===============>var_decl: declare and initialize %s\n", (yyvsp[-4].name)); }
#line 1459 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 9:
#line 111 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.decl) = decl_create((yyvsp[-6].name), (yyvsp[0].type), 0, 0, 0); printf(">==t12===============>var_decl: declare array %s [%d]\n", (yyvsp[-6].name), (yyvsp[-2].value)); }
#line 1465 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 10:
#line 112 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.decl) = decl_create((yyvsp[-8].name), (yyvsp[-2].type), (yyvsp[0].expr), 0, 0); printf(">==t14===============>var_decl: declare and initialize array %s [%d] \n", (yyvsp[-8].name), (yyvsp[-4].value)); }
#line 1471 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 11:
#line 116 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.value) = atoi(yytext); printf(">=================>length: %d\n", (yyval.value)); }
#line 1477 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 12:
#line 120 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr); printf(">==t===============>array inititialization\n"); }
#line 1483 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 13:
#line 124 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);printf(">==t13===============>value for list\n"); }
#line 1489 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 14:
#line 125 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-2].expr); (yyvsp[-2].expr)->left = (yyvsp[0].expr); printf(">==t11===============>value list addition\n"); }
#line 1495 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 15:
#line 129 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.decl) = decl_create((yyvsp[-7].name),type_create(TYPE_FUNCTION,(yyvsp[-4].type),(yyvsp[-2].param_list)),0,0,0); printf(">==tf===============>function decl\n"); }
#line 1501 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 16:
#line 130 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.decl) = decl_create((yyvsp[-8].name),type_create(TYPE_FUNCTION,(yyvsp[-5].type),(yyvsp[-3].param_list)),0,(yyvsp[0].stmt),0); printf(">==tfn===============>function decl and def\n"); }
#line 1507 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 17:
#line 134 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); printf(">==t17===============>function def\n"); }
#line 1513 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 18:
#line 138 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.param_list) = (yyvsp[0].param_list); printf(">==t14===============>params\n"); }
#line 1519 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 19:
#line 139 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.param_list) = 0; printf(">==t15===============>params: epsilon\n"); }
#line 1525 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 20:
#line 143 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.param_list) = (yyvsp[0].param_list); printf(">==t3===============>param_list: param\n"); }
#line 1531 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 21:
#line 144 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.param_list) = (yyvsp[-2].param_list); (yyvsp[-2].param_list)->next = (yyvsp[0].param_list); printf(">==t4===============>param_list: multiple params\n"); }
#line 1537 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 22:
#line 148 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.param_list) = (yyval.param_list) = param_list_create((yyvsp[-2].name),(yyvsp[0].type),0); printf(">==y10===============>param %s\n", (yyvsp[-2].name)); }
#line 1543 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 23:
#line 149 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.param_list) = param_list_create((yyvsp[-5].name),(yyvsp[0].type),0); printf(">==UNSUPPORTED_FEATURE===============>param (array): %s\n", (yyvsp[-5].name)); }
#line 1549 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 24:
#line 153 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); printf(">==t16===============>stmt in stmts\n"); }
#line 1555 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 25:
#line 154 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[-1].stmt); (yyvsp[-1].stmt)->next= (yyvsp[0].stmt); printf(">==t18===============>multiple stmts\n"); }
#line 1561 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 26:
#line 158 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_EXPR,0,0,(yyvsp[-1].expr),0,0,0,0); printf(">==t15===============>stmt: function call\n"); }
#line 1567 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 27:
#line 159 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_DECL,(yyvsp[-1].decl),0,0,0,0,0,0); printf(">==t12===============>stmt: variable declaration\n"); }
#line 1573 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 28:
#line 160 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_EXPR,0,0,(yyvsp[-1].expr),0,0,0,0); printf(">==tt===============>stmt: assignment\n"); }
#line 1579 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 29:
#line 161 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(0,0,0,(yyvsp[-1].expr),0,0,0,0); printf(">==t12==============>stmt: postfix\n"); }
#line 1585 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 30:
#line 162 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[-1].stmt); printf(">==t24===============>print statement\n"); }
#line 1591 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 31:
#line 163 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); printf(">==iff===============>stmt: if matched\n"); }
#line 1597 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 32:
#line 164 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); printf(">==forr===============>stmt: for\n"); }
#line 1603 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 33:
#line 165 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_BLOCK,0,0,0,0,(yyvsp[0].stmt),0,0); printf(">==t11===============>stmt: block\n"); }
#line 1609 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 34:
#line 166 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[-1].stmt); printf(">==t19===============>stmt: return\n"); }
#line 1615 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 35:
#line 170 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[-1].stmt); printf(">==t20===============>statement block\n"); }
#line 1621 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 36:
#line 171 "b-minor-parser.y" /* yacc.c:1646  */
    { printf(">==empty_block===============>empty statement block\n"); }
#line 1627 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 37:
#line 175 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_FUNCTIONCALL,expr_create_name((yyvsp[-3].name)),(yyvsp[-1].expr)); printf(">==t13===============>function call %s\n", (yyvsp[-3].name)); }
#line 1633 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 38:
#line 179 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); printf(">==t10===============>args: argument list\n"); }
#line 1639 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 39:
#line 180 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = 0; printf(">==t11===============>args: epsilon\n"); }
#line 1645 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 40:
#line 184 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); printf(">==t12===============>arg_list: arg\n"); }
#line 1651 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 41:
#line 185 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-2].expr); (yyvsp[-2].expr)->left = (yyvsp[0].expr); printf(">==t13===============>arg_list: list of args\n"); }
#line 1657 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 42:
#line 189 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); printf(">==t17===============>arg: expr\n"); }
#line 1663 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 43:
#line 193 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_ASSIGN,expr_create_name((yyvsp[-2].name)),(yyvsp[0].expr)); printf(">==t13===============>assignment: non-array\n"); }
#line 1669 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 44:
#line 194 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_ASSIGN,(yyvsp[-2].expr),(yyvsp[0].expr)); printf(">==t15===============>assignment: array element\n"); }
#line 1675 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 45:
#line 198 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.name) = strdup(yytext); printf(">=================>identifier %s\n", yytext); }
#line 1681 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 46:
#line 202 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = expr_create((yyvsp[-1].value),(yyvsp[-2].expr),(yyvsp[0].expr)); printf(">==t19===============>expr: logical_op\n"); }
#line 1687 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 47:
#line 203 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); printf(">==t20===============>expr: lo_expr\n"); }
#line 1693 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 48:
#line 207 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = expr_create((yyvsp[-1].value),(yyvsp[-2].expr),(yyvsp[0].expr)); printf(">==t12===============>lo_expr: relational_op\n"); }
#line 1699 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 49:
#line 208 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); printf(">==t15===============>lo_expr: pm_expr\n"); }
#line 1705 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 50:
#line 212 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_ADD,(yyvsp[-2].expr),(yyvsp[0].expr)); printf(">==t+===============>pm_expr: addition\n"); }
#line 1711 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 51:
#line 213 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_SUB,(yyvsp[-2].expr),(yyvsp[0].expr)); printf(">==t-===============>pm_expr: subtraction\n");}
#line 1717 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 52:
#line 214 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); printf(">==tt===============>pm_expr: term\n"); }
#line 1723 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 53:
#line 218 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_MUL,(yyvsp[-2].expr),(yyvsp[0].expr)); printf(">==tm===============>term: multiplication\n"); }
#line 1729 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 54:
#line 219 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_DIV,(yyvsp[-2].expr),(yyvsp[0].expr)); printf(">==td===============>term: division\n"); }
#line 1735 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 55:
#line 220 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_MODULUS,(yyvsp[-2].expr),(yyvsp[0].expr)); printf(">==t10===============>term: modulus\n"); }
#line 1741 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 56:
#line 221 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); printf(">==t11===============>term: expon\n"); }
#line 1747 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 57:
#line 225 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_EXPONENTIATION,(yyvsp[-2].expr),(yyvsp[0].expr)); printf(">==t17===============>expon: exponentiation\n"); }
#line 1753 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 58:
#line 226 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); printf(">==t18===============>expon: factor\n");  }
#line 1759 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 59:
#line 230 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_SUB,(yyvsp[0].expr),0); printf(">==t20===============>factor: negate\n");}
#line 1765 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 60:
#line 231 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr); printf(">==t12===============>factor: parenthesized expression\n"); }
#line 1771 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 61:
#line 232 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_name((yyvsp[0].name)); printf(">==t16===============>factor: identifier\n"); }
#line 1777 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 62:
#line 233 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); printf(">==t18===============>factor: literal\n"); }
#line 1783 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 63:
#line 234 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); printf(">==t15===============>factor: not\n");}
#line 1789 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 64:
#line 235 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); printf(">==t11===============>factor: array element\n"); }
#line 1795 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 65:
#line 236 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);printf(">==t10===============>factor: function call\n"); }
#line 1801 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 66:
#line 240 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_NOT,(yyvsp[0].expr),0); printf(">==t13===============>not\n"); }
#line 1807 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 67:
#line 244 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_SUBSCRIPT,expr_create_name((yyvsp[-3].name)),(yyvsp[-1].expr)); printf(">==t11===============>element of array %s\n", (yyvsp[-3].name)); }
#line 1813 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 68:
#line 249 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_IF_ELSE,0,0,(yyvsp[-2].expr),0,(yyvsp[0].stmt),0,0); printf(">==t15===============>if without else\n"); }
#line 1819 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 69:
#line 250 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_IF_ELSE,0,0,(yyvsp[-4].expr),0,(yyvsp[-2].stmt),(yyvsp[0].stmt),0); printf(">==t18===============>if with else\n"); }
#line 1825 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 70:
#line 254 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_FOR,0,(yyvsp[-6].expr),(yyvsp[-4].expr),(yyvsp[-2].expr),(yyvsp[0].stmt),0,0);  printf(">==t20===============>for statement\n"); }
#line 1831 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 71:
#line 258 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_RETURN,0,0,(yyvsp[0].expr),0,0,0,0); printf(">==t11===============>return\n"); }
#line 1837 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 72:
#line 262 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_PRINT,0,0,(yyvsp[0].expr),0,0,0,0); printf(">==t19===============>print statement\n"); }
#line 1843 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 73:
#line 266 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_INCREMENT,expr_create_name((yyvsp[-1].name)),0); printf(">==t17===============>postfix increment\n"); }
#line 1849 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 74:
#line 267 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_DECREMENT,expr_create_name((yyvsp[-1].name)),0); printf(">==t14===============>postfix decrement\n"); }
#line 1855 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 75:
#line 271 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); printf(">==t10===============>opt_assignment: assignment\n"); }
#line 1861 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 76:
#line 272 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = 0; printf(">==t11===============>opt_assignment epsilon \n"); }
#line 1867 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 77:
#line 276 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); printf(">==t12===============>opt_expr: expr\n"); }
#line 1873 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 78:
#line 277 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = 0; printf(">==t14===============>opt_expr: epsilon\n"); }
#line 1879 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 79:
#line 281 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); printf(">==t15===============>opt_increment: assignment\n"); }
#line 1885 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 80:
#line 282 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); printf(">==t16===============>opt_increment: postfix\n"); }
#line 1891 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 81:
#line 283 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = 0; printf(">==t18===============>opt_increment epsilon\n"); }
#line 1897 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 82:
#line 287 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_boolean_literal(1); printf(">==t11===============>Boolean literal (true)\n"); }
#line 1903 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 83:
#line 288 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_boolean_literal(0); printf(">==t10==============>Boolean literal (false)\n"); }
#line 1909 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 84:
#line 289 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_integer_literal(atoi(yytext)); printf(">==t12===============>Integer literal %s\n", yytext); }
#line 1915 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 85:
#line 290 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_char_literal(yytext[1]); printf(">==t13===============>Character literal %s\n", yytext);  }
#line 1921 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 86:
#line 291 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_string_literal(yytext); printf(">==t14===============>String literal %s\n", yytext);  }
#line 1927 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 87:
#line 295 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_BOOLEAN,0,0); printf(">==t18===============>Boolean type created\n"); }
#line 1933 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 88:
#line 296 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_INTEGER,0,0); printf(">==t19===============>Integer type created\n"); }
#line 1939 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 89:
#line 297 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_CHARACTER,0,0); printf(">==t20===============>Character type created\n"); }
#line 1945 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 90:
#line 298 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_STRING,0,0); printf(">==t11===============>String type created\n"); }
#line 1951 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 91:
#line 302 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); printf(">==tr===============>return_type: atomic_type\n"); }
#line 1957 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 92:
#line 303 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_VOID,0,0); printf(">==tv===============>return_type: void created\n"); }
#line 1963 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 93:
#line 307 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.value) = EXPR_EQUAL; printf(">==teq===============>relational_op: equal\n"); }
#line 1969 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 94:
#line 308 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.value) = EXPR_NOT_EQUAL; printf(">==tnq===============>relational_op: not equal\n"); }
#line 1975 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 95:
#line 309 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.value) = EXPR_GREATER_THAN; printf(">==tg===============>relational_op: greater\n"); }
#line 1981 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 96:
#line 310 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.value) = EXPR_GREATER_EQUAL; printf(">==tge===============>relational_op: greater equal\n"); }
#line 1987 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 97:
#line 311 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.value) = EXPR_LESS_THAN; printf(">==tl===============>relational_op: less\n"); }
#line 1993 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 98:
#line 312 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.value) = EXPR_LESS_EQUAL; printf(">==tle===============>relational_op: less equal\n"); }
#line 1999 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 99:
#line 316 "b-minor-parser.y" /* yacc.c:1646  */
    { (yyval.value) = EXPR_AND; printf(">==tand===============>logical_op: and\n"); }
#line 2005 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;

  case 100:
#line 317 "b-minor-parser.y" /* yacc.c:1646  */
    {  (yyval.value) = EXPR_OR; printf(">==tor===============>logical_op: or\n"); }
#line 2011 "b-minor-parser-ast.c" /* yacc.c:1646  */
    break;


#line 2015 "b-minor-parser-ast.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 319 "b-minor-parser.y" /* yacc.c:1906  */


/* Display an error message in the console */
void yyerror(char const *s) {
   fprintf(stderr, "%s\n", s);
}
