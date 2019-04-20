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
#line 1 "parser.y" /* yacc.c:339  */

#include <stdio.h>
#include <list>
extern "C" void yyerror(char *s);
extern int yylex(void);
extern int yylineno;
Symbol_Table *local_symbol_table = new Symbol_Table();
Symbol_Table *global_symbol_table = new Symbol_Table();

int glob_scop = 1;
string present_procedure_name;

Data_Type sample_data_type;


#line 82 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTEGER_NUMBER = 258,
    BBNUM = 259,
    DOUBLE_NUMBER = 260,
    NAME = 261,
    RETURN = 262,
    INTEGER = 263,
    FLOAT = 264,
    ASSIGN = 265,
    VOID = 266,
    UMINUS = 267,
    WHILE = 268,
    GREATER_THAN = 269,
    NOT_EQUAL = 270,
    LESS_THAN = 271,
    LESS_THAN_EQUAL = 272,
    EQUAL = 273,
    GREATER_THAN_EQUAL = 274,
    IF = 275,
    ELSE = 276,
    DO = 277,
    AND = 278,
    OR = 279,
    NOT = 280,
    PRINT = 281
  };
#endif
/* Tokens.  */
#define INTEGER_NUMBER 258
#define BBNUM 259
#define DOUBLE_NUMBER 260
#define NAME 261
#define RETURN 262
#define INTEGER 263
#define FLOAT 264
#define ASSIGN 265
#define VOID 266
#define UMINUS 267
#define WHILE 268
#define GREATER_THAN 269
#define NOT_EQUAL 270
#define LESS_THAN 271
#define LESS_THAN_EQUAL 272
#define EQUAL 273
#define GREATER_THAN_EQUAL 274
#define IF 275
#define ELSE 276
#define DO 277
#define AND 278
#define OR 279
#define NOT 280
#define PRINT 281

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
#line 17 "parser.y" /* yacc.c:355  */
union YYSTYPE
{
#line 18 "parser.y" /* yacc.c:355  */
   int integer_value;
    double double_value;
    std::string * string_value;
    list<Ast *> * ast_list;
    Ast * ast;
    Symbol_Table * symbol_table;
    Symbol_Table_Entry * symbol_entry;
    Basic_Block * basic_block;
    Procedure * procedure;
    list<Procedure*> * procedure_list;
    Data_Type data_type;

#line 187 "y.tab.c" /* yacc.c:355  */
};
#line 17 "parser.y" /* yacc.c:355  */
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 204 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   241

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  148

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   282

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
      34,    35,    31,    29,    39,    30,     2,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    28,    38,
       2,     2,     2,    27,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    37,     2,     2,     2,     2,
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
      25,    26,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    58,    58,    68,    70,    72,    75,    78,    83,    81,
     118,   129,   142,   146,   153,   164,   170,   175,   181,   188,
     193,   199,   217,   232,   245,   260,   266,   272,   279,   287,
     292,   298,   312,   328,   332,   339,   344,   349,   354,   359,
     364,   369,   374,   380,   386,   393,   400,   407,   414,   421,
     427,   433,   440,   446,   455,   471,   476,   482,   488,   497,
     504,   512,   519,   525,   531,   537,   542,   548,   554,   560,
     566,   572,   578,   585,   603,   608
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER_NUMBER", "BBNUM",
  "DOUBLE_NUMBER", "NAME", "RETURN", "INTEGER", "FLOAT", "ASSIGN", "VOID",
  "UMINUS", "WHILE", "GREATER_THAN", "NOT_EQUAL", "LESS_THAN",
  "LESS_THAN_EQUAL", "EQUAL", "GREATER_THAN_EQUAL", "IF", "ELSE", "DO",
  "AND", "OR", "NOT", "PRINT", "'?'", "':'", "'+'", "'-'", "'*'", "'/'",
  "\"then\"", "'('", "')'", "'{'", "'}'", "';'", "','", "$accept",
  "program", "total_code", "function_definition_list",
  "function_definition", "$@1", "function_declaration",
  "func_def_decl_args_list", "function_call", "func_call_args_list",
  "func_call_args_list1", "func_arg", "type_var_list", "type_list",
  "return_type", "variable_declaration_list", "variable_declaration",
  "variable_list", "statement_list", "single_stmt", "assignment_statement",
  "expression", "variable", "constant", "if_stmt", "while_stmt",
  "do_while_stmt", "print_stmt", "logical_expr", "relational_expr",
  "sequence_list", "return_stmt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    63,    58,    43,
      45,    42,    47,   282,    40,    41,   123,   125,    59,    44
};
# endif

#define YYPACT_NINF -63

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-63)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     131,   -63,   -63,   -63,     2,   -63,   131,   -63,   131,    -1,
     131,   -63,   -63,     6,   -63,   -19,   -15,   -63,    -5,   131,
     -63,    30,   131,    14,    25,    -4,    59,   -63,    34,    59,
       5,   131,    36,   131,   -63,    40,   -63,   -63,    66,   -63,
     -63,   -63,   -63,   131,    73,   -63,    55,   -63,    46,     8,
      50,    51,   109,    80,   -63,   -63,   -63,   -63,   -63,    85,
     -63,   -63,   -63,   -63,   -63,   -63,   153,   -63,   -63,   -63,
      96,    96,    96,   -63,   132,   -63,   -63,    -2,   -63,    96,
      96,    84,    62,    83,   107,    69,   -63,    67,   -63,   -63,
     209,   -63,   -63,   182,    43,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,   -63,    96,    96,    96,   101,
     130,    74,   -63,   -63,   -63,   157,    76,   153,   -63,   -63,
     209,   209,   209,   209,   209,   209,    16,    16,   -63,   -63,
     -63,    88,   190,   109,   109,    96,   -63,   -63,   -63,    96,
     -63,    86,   155,   209,   109,    79,   -63,   -63
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    25,    26,    27,     0,     2,     5,     7,     0,     0,
       0,     1,     6,     0,     4,    31,     0,     3,     0,    12,
      30,     0,    12,     0,    13,     0,    24,    32,     0,     0,
       0,     0,     0,     0,    22,     0,     8,    10,     0,    11,
      23,    29,    21,    33,     0,    28,     0,    31,    54,     0,
       0,     0,     0,     0,    33,     9,    41,    34,    35,     0,
      36,    37,    38,    40,    39,    42,    16,    55,    56,    54,
       0,     0,     0,    75,     0,    49,    50,     0,    66,     0,
       0,     0,     0,     0,     0,     0,    15,    18,    19,    20,
       0,    64,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    74,     0,     0,     0,     0,
       0,     0,    61,    73,    44,     0,     0,     0,    51,    65,
      69,    72,    67,    68,    71,    70,    47,    48,    45,    46,
      62,    63,     0,     0,     0,     0,    43,    14,    17,     0,
      59,    57,     0,    53,     0,     0,    58,    60
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -63,   -63,    24,   -63,   112,   -63,   -63,   105,    39,   -63,
      17,   -63,   -63,   -63,    -3,   -63,    90,   -63,    89,   -51,
     -63,   -45,   -46,   -57,   -63,   -63,   -63,   -63,   -62,   -63,
     -63,   -63
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    41,     8,    23,    56,    85,
      86,    87,    24,    25,     9,    43,    10,    16,    46,    57,
      58,    90,    75,    76,    60,    61,    62,    63,    77,    78,
      64,    65
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      59,    81,    11,    13,    74,    15,    59,    82,    91,    89,
      94,    67,    18,    68,    69,    19,    26,   109,   110,    29,
      88,   106,   107,    20,    21,   108,    92,    93,    38,    22,
      40,    32,    14,    70,    17,    33,    27,    59,    71,   115,
      44,    36,    72,    37,   130,   131,    73,   103,   104,    30,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
      89,    48,    49,   132,    31,    34,   106,   107,    50,    35,
     108,    88,    42,   142,    39,    51,    36,    52,   119,    47,
      66,    53,   140,   141,    79,    80,    69,    59,    59,    48,
      49,    54,    55,   146,   143,    84,    50,   111,    59,    67,
     112,    68,    69,    51,   116,    52,   117,   144,   135,    53,
      67,   106,    68,    48,   137,    48,    49,   147,    12,    54,
     113,    70,    50,   114,   106,   107,    71,    28,   108,    51,
      72,    52,    70,    45,   138,    53,   133,    71,     0,     1,
       2,    72,     3,    83,     0,    54,    95,    96,    97,    98,
      99,   100,     0,   106,   107,     0,    67,   108,    68,    69,
       0,   101,   102,   103,   104,   134,     0,     0,     0,     0,
     105,    95,    96,    97,    98,    99,   100,     0,   106,   107,
       0,     0,   108,     0,     0,     0,   101,   102,   103,   104,
     145,     0,     0,     0,     0,   136,    95,    96,    97,    98,
      99,   100,     0,     0,    95,    96,    97,    98,    99,   100,
       0,   101,   102,   103,   104,     0,     0,   118,   139,   101,
     102,   103,   104,    95,    96,    97,    98,    99,   100,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104
};

static const yytype_int16 yycheck[] =
{
      46,    52,     0,     6,    49,     6,    52,    53,    70,    66,
      72,     3,     6,     5,     6,    34,    19,    79,    80,    22,
      66,    23,    24,    38,    39,    27,    71,    72,    31,    34,
      33,    35,     8,    25,    10,    39,     6,    83,    30,    84,
      43,    36,    34,    38,   106,   107,    38,    31,    32,    35,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     117,     6,     7,   108,    39,     6,    23,    24,    13,    35,
      27,   117,     6,   135,    38,    20,    36,    22,    35,     6,
      34,    26,   133,   134,    34,    34,     6,   133,   134,     6,
       7,    36,    37,   144,   139,    10,    13,    13,   144,     3,
      38,     5,     6,    20,    35,    22,    39,    21,    34,    26,
       3,    23,     5,     6,    38,     6,     7,    38,     6,    36,
      37,    25,    13,    84,    23,    24,    30,    22,    27,    20,
      34,    22,    25,    43,   117,    26,    35,    30,    -1,     8,
       9,    34,    11,    54,    -1,    36,    14,    15,    16,    17,
      18,    19,    -1,    23,    24,    -1,     3,    27,     5,     6,
      -1,    29,    30,    31,    32,    35,    -1,    -1,    -1,    -1,
      38,    14,    15,    16,    17,    18,    19,    -1,    23,    24,
      -1,    -1,    27,    -1,    -1,    -1,    29,    30,    31,    32,
      35,    -1,    -1,    -1,    -1,    38,    14,    15,    16,    17,
      18,    19,    -1,    -1,    14,    15,    16,    17,    18,    19,
      -1,    29,    30,    31,    32,    -1,    -1,    35,    28,    29,
      30,    31,    32,    14,    15,    16,    17,    18,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      31,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,     9,    11,    41,    42,    43,    44,    46,    54,
      56,     0,    44,    54,    42,     6,    57,    42,     6,    34,
      38,    39,    34,    47,    52,    53,    54,     6,    47,    54,
      35,    39,    35,    39,     6,    35,    36,    38,    54,    38,
      54,    45,     6,    55,    54,    56,    58,     6,     6,     7,
      13,    20,    22,    26,    36,    37,    48,    59,    60,    62,
      64,    65,    66,    67,    70,    71,    34,     3,     5,     6,
      25,    30,    34,    38,    61,    62,    63,    68,    69,    34,
      34,    59,    62,    58,    10,    49,    50,    51,    62,    63,
      61,    68,    61,    61,    68,    14,    15,    16,    17,    18,
      19,    29,    30,    31,    32,    38,    23,    24,    27,    68,
      68,    13,    38,    37,    48,    61,    35,    39,    35,    35,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      68,    68,    61,    35,    35,    34,    38,    38,    50,    28,
      59,    59,    68,    61,    21,    35,    59,    38
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    42,    43,    43,    45,    44,
      46,    46,    47,    47,    48,    49,    49,    50,    50,    51,
      51,    52,    52,    53,    53,    54,    54,    54,    55,    55,
      56,    57,    57,    58,    58,    59,    59,    59,    59,    59,
      59,    59,    59,    60,    60,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    62,    63,    63,    64,    64,    65,
      66,    67,    68,    68,    68,    68,    68,    69,    69,    69,
      69,    69,    69,    70,    71,    71
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     2,     1,     0,    10,
       6,     6,     0,     1,     5,     1,     0,     3,     1,     1,
       1,     4,     2,     3,     1,     1,     1,     1,     2,     0,
       3,     1,     3,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     3,     3,     3,     3,     3,     1,
       1,     3,     2,     5,     1,     1,     1,     5,     7,     5,
       7,     3,     3,     3,     2,     3,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     2
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
#line 59 "parser.y" /* yacc.c:1646  */
    {
                    program_object.set_global_table(*global_symbol_table);
                    if(!program_object.is_procedure_exists("main") || (program_object.get_procedure_prototype("main")->get_return_type() != void_data_type)){
                        cerr << "cs316: Error : Line: " <<  yylineno << ": Main should be defined and it's type should be void\n";
                        exit(0);
                    }
                    cout << "exit\n";
                }
#line 1412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 83 "parser.y" /* yacc.c:1646  */
    {
                                if(*((yyvsp[-4].string_value)) != "main")
                                    *((yyvsp[-4].string_value)) = *((yyvsp[-4].string_value)) + "_";
                                glob_scop = 0;
                                present_procedure_name = *((yyvsp[-4].string_value));
                            }
#line 1423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 92 "parser.y" /* yacc.c:1646  */
    {
                                Procedure* proc;

                                if(program_object.is_procedure_exists(*((yyvsp[-8].string_value)))){
                                    proc = program_object.get_procedure_prototype(*((yyvsp[-8].string_value)));
                                    if(proc->get_return_type() != (yyvsp[-9].data_type)){
                                        cerr << "cs316: Error : Line: " <<  yylineno << ": return type in declaration and definition not matching\n";
                                        exit(0);
                                    }
                                    proc->set_local_list(*local_symbol_table);
                                    proc->set_ast_list(*((yyvsp[-1].ast_list)));
                                    proc->set_formal_param_list(*((yyvsp[-6].symbol_table)));
                                }
                                else{
                                    proc = new Procedure((yyvsp[-9].data_type), *((yyvsp[-8].string_value)), yylineno);
                                    proc->set_local_list(*local_symbol_table);
                                    proc->set_ast_list(*((yyvsp[-1].ast_list)));
                                    proc->set_formal_param_list(*((yyvsp[-6].symbol_table)));
                                    program_object.set_proc_to_map(*((yyvsp[-8].string_value)), proc);
                                }

                                local_symbol_table = new Symbol_Table();
                            }
#line 1451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 119 "parser.y" /* yacc.c:1646  */
    {
                                if(*((yyvsp[-4].string_value)) != "main")
                                    *((yyvsp[-4].string_value)) = *((yyvsp[-4].string_value)) + "_";

                                Procedure* proc = new Procedure((yyvsp[-5].data_type), *((yyvsp[-4].string_value)), yylineno);
                                proc->set_local_list(*local_symbol_table);
                                // proc->set_formal_param_list(*($4));
                                program_object.set_proc_to_map(*((yyvsp[-4].string_value)), proc);
                            }
#line 1465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 130 "parser.y" /* yacc.c:1646  */
    {
                                if(*((yyvsp[-4].string_value)) != "main")
                                    *((yyvsp[-4].string_value)) = *((yyvsp[-4].string_value)) + "_";

                                Procedure* proc = new Procedure((yyvsp[-5].data_type), *((yyvsp[-4].string_value)), yylineno);
                                proc->set_local_list(*local_symbol_table);
                                // proc->set_formal_param_list(*($4));
                                program_object.set_proc_to_map(*((yyvsp[-4].string_value)), proc);
                            }
#line 1479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 142 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.symbol_table) = new Symbol_Table();
                    }
#line 1487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 147 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.symbol_table) = (yyvsp[0].symbol_table);
                    }
#line 1495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 154 "parser.y" /* yacc.c:1646  */
    {
                        if(*((yyvsp[-4].string_value)) != "main")
                            *((yyvsp[-4].string_value))= *((yyvsp[-4].string_value)) + "_";
                        Call_Ast * call_ast = new Call_Ast(*((yyvsp[-4].string_value)), yylineno);  // TODO:
                        call_ast->set_actual_param_list(*((yyvsp[-2].ast_list)));
                        call_ast->check_actual_formal_param(program_object.get_procedure_prototype(*((yyvsp[-4].string_value)))->get_formal_param_list());
                        (yyval.ast) = call_ast;
                    }
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 165 "parser.y" /* yacc.c:1646  */
    {
                            (yyval.ast_list) = (yyvsp[0].ast_list);                            
                        }
#line 1516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 170 "parser.y" /* yacc.c:1646  */
    {
                            (yyval.ast_list) = new list<Ast*>;
                        }
#line 1524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 176 "parser.y" /* yacc.c:1646  */
    {
                                (yyvsp[0].ast_list)->push_back((yyvsp[-2].ast));
                                (yyval.ast_list) = (yyvsp[0].ast_list);                                
                            }
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 182 "parser.y" /* yacc.c:1646  */
    {
                                (yyval.ast_list) = new list<Ast*>;
                                (yyval.ast_list)->push_back((yyvsp[0].ast));
                            }
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 189 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.ast) = (yyvsp[0].ast);
                }
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 194 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.ast) = (yyvsp[0].ast);
                }
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 200 "parser.y" /* yacc.c:1646  */
    {
                        *((yyvsp[0].string_value)) = *((yyvsp[0].string_value)) + "_";
                        if((yyvsp[-1].data_type) == void_data_type){
                            cerr << "cs316: Error : Line: " <<  yylineno << ": Argument variable cannot be void data type\n";
                            exit(0);
                        }

                        if((yyvsp[-3].symbol_table)->variable_in_symbol_list_check(*((yyvsp[0].string_value)))){
                            cerr << "cs316: Error : Line: " <<  yylineno << ": Variable is declared twice\n";                            
                            exit(0);
                        }

                        Symbol_Table_Entry * sym = new Symbol_Table_Entry(*((yyvsp[0].string_value)), (yyvsp[-1].data_type), yylineno);
                        (yyvsp[-3].symbol_table)->push_symbol(sym);
                        (yyval.symbol_table) = (yyvsp[-3].symbol_table);
                    }
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 218 "parser.y" /* yacc.c:1646  */
    {
                        *((yyvsp[0].string_value)) = *((yyvsp[0].string_value)) + "_";
                        if((yyvsp[-1].data_type) == void_data_type){
                            cerr << "cs316: Error : Line: " <<  yylineno << ": Argument variable cannot be void data type\n";                            
                            exit(0);
                        }

                        (yyval.symbol_table) = new Symbol_Table();
                        Symbol_Table_Entry * sym = new Symbol_Table_Entry(*((yyvsp[0].string_value)), (yyvsp[-1].data_type), yylineno);
                        (yyval.symbol_table)->push_symbol(sym);
                    }
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 233 "parser.y" /* yacc.c:1646  */
    {
                    if((yyvsp[0].data_type) == void_data_type){
                        cerr << "cs316: Error : Line: " <<  yylineno << ": Argument cannot be void data type\n";
                        exit(0);
                    }
                    
                    string dummy_string = "dummy";
                    Symbol_Table_Entry * sym = new Symbol_Table_Entry(dummy_string, (yyvsp[0].data_type), yylineno);
                    (yyvsp[-2].symbol_table)->push_symbol(sym);
                    (yyval.symbol_table) = (yyvsp[-2].symbol_table);
                }
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 246 "parser.y" /* yacc.c:1646  */
    {
                    if((yyvsp[0].data_type) == void_data_type){
                        cerr << "cs316: Error : Line: " <<  yylineno << ": Argument cannot be void data type\n";
                        exit(0);
                    }

                    (yyval.symbol_table) = new Symbol_Table();
                    string dummy_string = "dummy";
                    Symbol_Table_Entry * sym = new Symbol_Table_Entry(dummy_string, (yyvsp[0].data_type), yylineno);
                    (yyval.symbol_table)->push_symbol(sym);
                }
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 261 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.data_type) = int_data_type;
                        sample_data_type = int_data_type;
                    }
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 267 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.data_type) = double_data_type;
                        sample_data_type = double_data_type;
                    }
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 273 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.data_type) = void_data_type;
                        sample_data_type = void_data_type;
                    }
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 281 "parser.y" /* yacc.c:1646  */
    {
                                    (yyvsp[-1].symbol_table)->append_list(*((yyvsp[0].symbol_table)), yylineno);
                                    (yyval.symbol_table) = (yyvsp[-1].symbol_table);
                                }
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 287 "parser.y" /* yacc.c:1646  */
    {
                                    (yyval.symbol_table) = new Symbol_Table();
                                }
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 293 "parser.y" /* yacc.c:1646  */
    {
                                (yyval.symbol_table) = (yyvsp[-1].symbol_table);
                            }
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 299 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.symbol_table) = new Symbol_Table();
                        string s = *((yyvsp[0].string_value))+"_";
                        Symbol_Table_Entry * sym = new Symbol_Table_Entry(s, sample_data_type, yylineno);
                        (yyval.symbol_table)->push_symbol(sym);
                        if(glob_scop == 1){
                            global_symbol_table->push_symbol(sym);
                        }
                        else{
                            local_symbol_table->push_symbol(sym);
                        }
                    }
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 313 "parser.y" /* yacc.c:1646  */
    {
                        string s = *((yyvsp[0].string_value)) + "_";
                        Symbol_Table_Entry * sym = new Symbol_Table_Entry(s, sample_data_type, yylineno);
                        (yyvsp[-2].symbol_table)->push_symbol(sym);
                        (yyval.symbol_table) = (yyvsp[-2].symbol_table);
                        if(glob_scop == 1){
                            global_symbol_table->push_symbol(sym);
                        }
                        else{
                            local_symbol_table->push_symbol(sym);
                        }
                    }
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 328 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.ast_list) = new list<Ast*>;
                    }
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 333 "parser.y" /* yacc.c:1646  */
    {
                        (yyvsp[-1].ast_list)->push_back((yyvsp[0].ast));
                        (yyval.ast_list) = (yyvsp[-1].ast_list);
                    }
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 340 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.ast) = (yyvsp[0].ast);
                    }
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 345 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.ast) = (yyvsp[0].ast);
                    }
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 350 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.ast) = (yyvsp[0].ast);
                    }
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 355 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.ast) = (yyvsp[0].ast);
                    }
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 360 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.ast) = (yyvsp[0].ast);
                    }
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 365 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.ast) = (yyvsp[0].ast);
                    }
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 370 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.ast) = (yyvsp[0].ast);
                    }
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 375 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.ast) = (yyvsp[0].ast);
                    }
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 381 "parser.y" /* yacc.c:1646  */
    {
                                (yyval.ast) = new Assignment_Ast((yyvsp[-3].ast), (yyvsp[-1].ast), yylineno);
                                (yyval.ast)->check_ast();
                            }
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 387 "parser.y" /* yacc.c:1646  */
    {
                                (yyval.ast) = new Assignment_Ast((yyvsp[-2].ast), (yyvsp[0].ast), yylineno);
                                (yyval.ast)->check_ast();
                            }
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 394 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.ast) = new Mult_Ast((yyvsp[-2].ast), (yyvsp[0].ast), yylineno);
                    (yyval.ast)->set_data_type((yyvsp[-2].ast)->get_data_type());
                    (yyval.ast)->check_ast();
                }
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 401 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.ast) = new Divide_Ast((yyvsp[-2].ast), (yyvsp[0].ast), yylineno);
                    (yyval.ast)->set_data_type((yyvsp[-2].ast)->get_data_type());
                    (yyval.ast)->check_ast();
                }
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 408 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.ast) = new Plus_Ast((yyvsp[-2].ast), (yyvsp[0].ast), yylineno);
                    (yyval.ast)->set_data_type((yyvsp[-2].ast)->get_data_type());
                    (yyval.ast)->check_ast();
                }
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 415 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.ast) = new Minus_Ast((yyvsp[-2].ast), (yyvsp[0].ast), yylineno);
                    (yyval.ast)->set_data_type((yyvsp[-2].ast)->get_data_type());
                    (yyval.ast)->check_ast();
                }
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 422 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.ast) = (yyvsp[0].ast);
                    (yyval.ast)->set_data_type((yyvsp[0].ast)->get_data_type());
                }
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 428 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.ast) = (yyvsp[0].ast);
                    (yyval.ast)->set_data_type((yyvsp[0].ast)->get_data_type());
                }
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 434 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.ast) = (yyvsp[-1].ast);
                    (yyval.ast)->set_data_type((yyvsp[-1].ast)->get_data_type());
                }
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 441 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.ast) = new UMinus_Ast((yyvsp[0].ast), NULL, yylineno);
                    (yyval.ast)->set_data_type((yyvsp[0].ast)->get_data_type());
                }
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 447 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.ast) = new Conditional_Expression_Ast((yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast), yylineno);
                    (yyval.ast)->set_data_type((yyvsp[-2].ast)->get_data_type());
                    (yyval.ast)->check_ast();
                }
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 456 "parser.y" /* yacc.c:1646  */
    {
                    string s = *((yyvsp[0].string_value)) + "_";
                    if(local_symbol_table->variable_in_symbol_list_check(s)){
                        (yyval.ast) = new Name_Ast(s, local_symbol_table->get_symbol_table_entry(s), yylineno);
                    }
                    else if(global_symbol_table->variable_in_symbol_list_check(s)){
                        (yyval.ast) = new Name_Ast(s, global_symbol_table->get_symbol_table_entry(s), yylineno);
                    }
                    else{
                        cerr << "cs316: Error : Line: " <<  yylineno << ": Variable has not been declared\n";
                        exit(0);
                    }
                }
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 472 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.ast) = new Number_Ast<int> ((yyvsp[0].integer_value), int_data_type, yylineno);
                }
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 477 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.ast) = new Number_Ast<double> ((yyvsp[0].double_value), double_data_type, yylineno);
                }
#line 1932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 484 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.ast) = new Selection_Statement_Ast((yyvsp[-2].ast), (yyvsp[0].ast), NULL, yylineno);
                }
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 492 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.ast) = new Selection_Statement_Ast((yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast), yylineno);
                }
#line 1948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 499 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.ast) = new Iteration_Statement_Ast((yyvsp[-2].ast), (yyvsp[0].ast), yylineno, false);
                    }
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 507 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.ast) = new Iteration_Statement_Ast((yyvsp[-2].ast), (yyvsp[-5].ast), yylineno, true);
                    }
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 513 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.ast) = new Print_Ast((yyvsp[-1].ast), yylineno);
                }
#line 1972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 520 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.ast) = new Logical_Expr_Ast((yyvsp[-2].ast), _logical_and, (yyvsp[0].ast), yylineno);
                        (yyval.ast)->check_ast();
                    }
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 526 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.ast) = new Logical_Expr_Ast((yyvsp[-2].ast), _logical_or, (yyvsp[0].ast), yylineno);
                        (yyval.ast)->check_ast();
                    }
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 532 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.ast) = new Logical_Expr_Ast(NULL, _logical_not, (yyvsp[0].ast), yylineno);
                        (yyval.ast)->check_ast();
                    }
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 538 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.ast) = (yyvsp[-1].ast);
                    }
#line 2007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 543 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.ast) = (yyvsp[0].ast);
                    }
#line 2015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 549 "parser.y" /* yacc.c:1646  */
    {
                            (yyval.ast) = new Relational_Expr_Ast((yyvsp[-2].ast), less_than, (yyvsp[0].ast), yylineno);
                            (yyval.ast)->check_ast();
                        }
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 555 "parser.y" /* yacc.c:1646  */
    {
                            (yyval.ast) = new Relational_Expr_Ast((yyvsp[-2].ast), less_equalto, (yyvsp[0].ast), yylineno);
                            (yyval.ast)->check_ast();
                        }
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 561 "parser.y" /* yacc.c:1646  */
    {
                            (yyval.ast) = new Relational_Expr_Ast((yyvsp[-2].ast), greater_than, (yyvsp[0].ast), yylineno);
                            (yyval.ast)->check_ast();                            
                        }
#line 2042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 567 "parser.y" /* yacc.c:1646  */
    {
                            (yyval.ast) = new Relational_Expr_Ast((yyvsp[-2].ast), greater_equalto, (yyvsp[0].ast), yylineno);
                            (yyval.ast)->check_ast();                            
                        }
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 573 "parser.y" /* yacc.c:1646  */
    {
                            (yyval.ast) = new Relational_Expr_Ast((yyvsp[-2].ast), equalto, (yyvsp[0].ast), yylineno);
                            (yyval.ast)->check_ast();
                        }
#line 2060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 579 "parser.y" /* yacc.c:1646  */
    {
                            (yyval.ast) = new Relational_Expr_Ast((yyvsp[-2].ast), not_equalto, (yyvsp[0].ast), yylineno);
                            (yyval.ast)->check_ast();
                        }
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 588 "parser.y" /* yacc.c:1646  */
    {
                        if ((yyvsp[-1].ast_list)->empty())
                        {
                            cerr << "cs316: Error : Line: " <<  yylineno << ": Block of statements cannot be empty (Invariant at line 404, file parser.y).\n";
                            exit(0);
                        }
                        Sequence_Ast * seq_ast_body = new Sequence_Ast(yylineno);
                        for (std::list<Ast*>::iterator it = (yyvsp[-1].ast_list)->begin(); it != (yyvsp[-1].ast_list)->end(); ++it)
                        {
                            seq_ast_body->ast_push_back(*it);
                        }

                        (yyval.ast) = seq_ast_body;
                    }
#line 2088 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 604 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.ast) = new Return_Ast((yyvsp[-1].ast), present_procedure_name, yylineno); //TODO: check 2nd argument - procedure name
                }
#line 2096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 609 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.ast) = new Return_Ast(NULL, present_procedure_name, yylineno);
                }
#line 2104 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2108 "y.tab.c" /* yacc.c:1646  */
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
