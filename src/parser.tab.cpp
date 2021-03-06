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

#line 67 "src/parser.tab.cpp" /* yacc.c:339  */

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
   by #include "parser.tab.hpp".  */
#ifndef YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
# define YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/parser.y" /* yacc.c:355  */

  #include "ast.hpp"
  #include <iostream>
  #include <cassert>
  #include <string>
  using namespace std;
  extern const Base *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated STATEMENTLIST can call them.
  //ARGS :
  //| T_NUMINT T_VARIABLE T_LBRACKET ARGS T_RBRACKET T_LCURLY STATEMENTLIST T_RCURLY {}
  /*  | T_NUMINT T_VARIABLE T_SEMICOLON {printf("In match");$$ = new Int(*$2) ;}
    | T_NUMINT T_LBRACKET T_VARIABLE T_RBRACKET T_SEMICOLON {printf("In match");$$ = new Variable(*$3);}


    | COND T_LBRACKET T_NUMINT T_VARIABLE T_RBRACKET {$$ = new Param(*$4)
    |T_NUMINT T_VARIABLE T_EQUAL EXPR T_SEMICOLON {printf("In match");$$ = new Int(*$2) ;}*/
  int yylex(void);
  void yyerror(const char *);

#line 120 "src/parser.tab.cpp" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_COMMAR = 258,
    T_NEWLINE = 259,
    T_RETURN = 260,
    T_MODULO = 261,
    T_GREATERTHAN = 262,
    T_LESSTHAN = 263,
    T_NOT = 264,
    T_WHILE = 265,
    T_ELSE = 266,
    T_FOR = 267,
    T_QUESTIONM = 268,
    T_COLON = 269,
    T_TIMES = 270,
    T_PLUS = 271,
    T_DIVIDE = 272,
    T_MINUS = 273,
    T_LBRACKET = 274,
    T_RBRACKET = 275,
    T_LOG = 276,
    T_EXP = 277,
    T_SQRT = 278,
    T_NUMBER = 279,
    T_VARIABLE = 280,
    T_LCURLY = 281,
    T_RCURLY = 282,
    T_NUMINT = 283,
    T_SEMICOLON = 284,
    T_IF = 285,
    T_EQUAL = 286,
    T_MUL_ASSIGN = 287,
    T_DIV_ASSIGN = 288,
    T_MOD_ASSIGN = 289,
    T_ADD_ASSIGN = 290,
    T_SUB_ASSIGN = 291,
    T_LEFT_ASSIGN = 292,
    T_RIGHT_ASSIGN = 293,
    T_AND_ASSIGN = 294,
    T_XOR_ASSIGN = 295,
    T_OR_ASSIGN = 296,
    T_LE_OP = 297,
    T_GE_OP = 298,
    T_EQ_OP = 299,
    T_NE_OP = 300,
    T_RIGHT_OP = 301,
    T_LEFT_OP = 302,
    T_INC_OP = 303,
    T_DEC_OP = 304,
    T_PTR_OP = 305,
    T_AND_OP = 306,
    T_OR_OP = 307,
    T_CHAR = 308,
    T_QUOTE = 309
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 26 "src/parser.y" /* yacc.c:355  */


  double number;
  std::string *string;


  paramList *paramlistPtr;
  astList *listPtr;
   Declaration *DecPtr;
   Statement *statePtr;

   FunctionDef *Funct;

   astList *topPtr;
   Param *paramPtr;


   Base *basePtr;
   ifLoop *ifPtr;
  Argument *argPtr;
  ArgumentList * argListPtr;
  FunctionCall *funcCallPtr;
  DeclarationList *decList;
  Comp *comPtr;

#line 213 "src/parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 230 "src/parser.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   290

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  179

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    77,    77,    79,    80,    81,    82,    88,    90,    91,
      92,    93,    95,    97,    99,   101,   103,   105,   114,   115,
     116,   118,   119,   120,   124,   125,   126,   127,   130,   144,
     145,   146,   147,   148,   150,   151,   152,   167,   168,   169,
     170,   171,   172,   174,   177,   178,   179,   180,   182,   190,
     191,   193,   194,   196,   201,   203,   206,   207,   212,   213,
     214,   220,   221,   222,   225,   226,   227,   228,   229,   231,
     234,   235,   239,   240,   243,   244,   246,   247,   252,   253,
     254,   255,   256,   257,   260,   261,   263,   264,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_COMMAR", "T_NEWLINE", "T_RETURN",
  "T_MODULO", "T_GREATERTHAN", "T_LESSTHAN", "T_NOT", "T_WHILE", "T_ELSE",
  "T_FOR", "T_QUESTIONM", "T_COLON", "T_TIMES", "T_PLUS", "T_DIVIDE",
  "T_MINUS", "T_LBRACKET", "T_RBRACKET", "T_LOG", "T_EXP", "T_SQRT",
  "T_NUMBER", "T_VARIABLE", "T_LCURLY", "T_RCURLY", "T_NUMINT",
  "T_SEMICOLON", "T_IF", "T_EQUAL", "T_MUL_ASSIGN", "T_DIV_ASSIGN",
  "T_MOD_ASSIGN", "T_ADD_ASSIGN", "T_SUB_ASSIGN", "T_LEFT_ASSIGN",
  "T_RIGHT_ASSIGN", "T_AND_ASSIGN", "T_XOR_ASSIGN", "T_OR_ASSIGN",
  "T_LE_OP", "T_GE_OP", "T_EQ_OP", "T_NE_OP", "T_RIGHT_OP", "T_LEFT_OP",
  "T_INC_OP", "T_DEC_OP", "T_PTR_OP", "T_AND_OP", "T_OR_OP", "T_CHAR",
  "T_QUOTE", "$accept", "ROOT", "BASE", "FUNCTIONLIST", "FUNCTION",
  "PARAMLIST", "PARAM", "ALLSTATE", "STATEMENTLIST", "STATEMENT", "IFLOOP",
  "WHILE", "FORLOOP", "FUNCTIONCALL", "ARGUMENTLIST", "ARGUMENT",
  "DECLARATIONLIST", "DECLARATION", "EXPR", "TERM", "FACTOR", "TYPE",
  "COMPARE", "COMPARETERM", "COMPARITORS", "COND_OP", "CON_OPANDOR",
  "INCDEC", "ASSIGNMENT_OP", YY_NULLPTR
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
     305,   306,   307,   308,   309
};
# endif

#define YYPACT_NINF -115

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-115)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     204,    14,  -115,    16,  -115,  -115,    18,    19,  -115,   177,
     -21,  -115,    46,  -115,  -115,     2,   201,   136,  -115,   235,
     -40,    22,  -115,    -8,    47,    65,   230,    87,  -115,  -115,
    -115,  -115,   111,    82,  -115,  -115,  -115,   177,   101,  -115,
    -115,  -115,   162,    14,    14,  -115,    14,    14,  -115,    76,
    -115,   140,  -115,  -115,    39,   215,   106,   144,    46,  -115,
    -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
    -115,    14,   144,   132,  -115,  -115,   111,  -115,     8,  -115,
      14,   136,   136,  -115,  -115,    14,  -115,   145,  -115,   149,
     144,   206,   146,    -7,   196,  -115,   144,   148,   140,   163,
      12,  -115,   114,   115,  -115,   159,   227,  -115,  -115,  -115,
     192,    49,  -115,  -115,  -115,  -115,  -115,  -115,    14,   170,
      45,  -115,  -115,   144,   144,   119,   180,   175,   216,    55,
      46,   220,  -115,  -115,  -115,   140,    85,   177,   161,   177,
     196,  -115,   111,   177,    97,  -115,   179,  -115,   127,  -115,
     191,   200,  -115,   232,   226,   236,   245,  -115,  -115,   246,
    -115,  -115,   248,  -115,   249,   265,  -115,   177,   137,   251,
     253,  -115,   254,   167,  -115,  -115,  -115,   255,  -115
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    64,    65,    70,    71,     0,     0,     2,     3,
       8,    69,     5,    54,     6,     0,     0,    58,    63,     0,
       0,     0,     1,     0,     0,     0,     0,     0,    86,    87,
       9,     4,    22,    24,    34,    35,    36,    23,     0,    11,
       7,    55,     0,     0,     0,    66,     0,     0,    50,     0,
      51,    53,    68,    67,    65,     0,     0,     0,     0,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      31,     0,     0,    26,    25,    10,    21,    30,     0,    56,
       0,    59,    60,    61,    62,     0,    49,     0,    29,     0,
       0,     0,    63,     0,    72,    75,     0,     0,    28,    63,
       0,    27,    16,     0,    18,     0,     0,    52,    32,    33,
       0,     0,    80,    81,    82,    83,    78,    79,     0,     0,
       0,    84,    85,     0,     0,     0,     0,     0,     0,     0,
       0,    17,    20,    57,    77,    76,     0,     0,     0,    23,
      73,    74,     0,     0,     0,    14,     0,    19,     0,    47,
       0,     0,    45,     0,     0,    38,     0,    13,    15,     0,
      46,    44,     0,    43,     0,    37,    12,     0,     0,     0,
       0,    42,     0,     0,    48,    41,    40,     0,    39
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -115,  -115,  -115,  -115,    80,  -115,   153,  -114,   -34,   -28,
    -115,  -115,  -115,  -115,  -115,   199,   120,   -11,     1,   100,
       5,     0,   -65,   164,   166,   -84,  -115,    -5,  -115
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    10,   103,   104,    31,    32,    33,
      34,    35,    36,    11,    49,    50,   139,    13,    91,    17,
      18,    97,    93,    94,    95,   118,   123,    38,    71
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      15,    41,    16,    76,    73,    14,   138,   100,    39,    15,
     124,     1,    15,   120,    52,   146,     2,    54,    56,    22,
      51,    70,   150,   151,    55,   111,    41,    42,   102,   154,
     156,   125,   128,     1,   159,    19,     4,    15,     2,     3,
      28,    29,    20,    21,   121,   122,     6,    96,    73,    87,
      23,    83,    84,   170,   172,    24,   124,    25,    19,   177,
      23,     5,    92,   121,   122,    24,    57,    25,     6,   134,
      26,   137,    98,     4,     4,    27,    53,    99,   105,    85,
      26,   106,   145,     4,    58,    27,    51,    28,    29,    30,
      23,   110,    40,    28,    29,    24,    86,    25,     5,     5,
     121,   122,    23,    28,    29,    76,    72,    24,     5,    25,
      26,    74,   149,     4,   153,    27,    23,    75,   130,   135,
      12,    24,    26,    25,   155,     4,    77,    27,    41,    37,
     105,    89,    23,    28,    29,   131,    26,    24,     5,    25,
     129,    27,    23,    81,    82,    28,    29,    24,   142,    25,
       5,    46,    26,    47,   158,     4,    43,    27,    44,    28,
      29,   101,    26,    90,   171,     4,   119,    27,     2,     3,
     121,   122,    23,   126,   108,    28,    29,    24,   109,    25,
       5,    78,    23,   127,   132,    28,    29,    24,   152,    25,
       5,    79,    26,    80,   176,     4,   136,    27,     6,   112,
     113,   143,    26,   112,   113,     4,   157,    27,    43,    79,
      44,    80,    45,   112,   113,    28,    29,    43,   160,    44,
       5,    45,    43,     1,    44,    28,    29,   161,     2,     3,
       5,    43,     4,    44,   114,   115,   116,   117,   114,   115,
     116,   117,   144,    43,    88,    44,   148,   164,   114,   115,
     116,   117,   162,   163,     1,    48,   133,     5,     6,     2,
       3,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,   165,   166,   167,   168,   169,   173,    28,    29,
     174,   175,   178,   147,   107,     0,     0,   140,     0,     6,
     141
};

static const yytype_int16 yycheck[] =
{
       0,    12,     1,    37,    32,     0,   120,    72,    29,     9,
      94,    19,    12,    20,    54,   129,    24,    25,    23,     0,
      19,    26,   136,   137,    23,    90,    37,    25,    20,   143,
     144,    96,    20,    19,   148,    19,    28,    37,    24,    25,
      48,    49,    24,    25,    51,    52,    54,    58,    76,    54,
       5,    46,    47,   167,   168,    10,   140,    12,    19,   173,
       5,    53,    57,    51,    52,    10,    19,    12,    54,    20,
      25,    26,    71,    28,    28,    30,    54,    72,    78,     3,
      25,    80,    27,    28,    19,    30,    85,    48,    49,     9,
       5,    90,    12,    48,    49,    10,    20,    12,    53,    53,
      51,    52,     5,    48,    49,   139,    19,    10,    53,    12,
      25,    29,    27,    28,   142,    30,     5,    37,     3,   118,
       0,    10,    25,    12,    27,    28,    25,    30,   139,     9,
     130,    25,     5,    48,    49,    20,    25,    10,    53,    12,
      26,    30,     5,    43,    44,    48,    49,    10,    29,    12,
      53,    15,    25,    17,    27,    28,    16,    30,    18,    48,
      49,    29,    25,    19,    27,    28,    20,    30,    24,    25,
      51,    52,     5,    25,    29,    48,    49,    10,    29,    12,
      53,    19,     5,    20,    25,    48,    49,    10,    27,    12,
      53,    29,    25,    31,    27,    28,    26,    30,    54,     7,
       8,    26,    25,     7,     8,    28,    27,    30,    16,    29,
      18,    31,    20,     7,     8,    48,    49,    16,    27,    18,
      53,    20,    16,    19,    18,    48,    49,    27,    24,    25,
      53,    16,    28,    18,    42,    43,    44,    45,    42,    43,
      44,    45,    26,    16,    29,    18,    26,    11,    42,    43,
      44,    45,    20,    27,    19,    20,    29,    53,    54,    24,
      25,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    27,    27,    26,    26,    11,    26,    48,    49,
      27,    27,    27,   130,    85,    -1,    -1,   123,    -1,    54,
     124
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    19,    24,    25,    28,    53,    54,    56,    57,    58,
      59,    68,    71,    72,    75,    76,    73,    74,    75,    19,
      24,    25,     0,     5,    10,    12,    25,    30,    48,    49,
      59,    62,    63,    64,    65,    66,    67,    71,    82,    29,
      59,    72,    25,    16,    18,    20,    15,    17,    20,    69,
      70,    73,    54,    54,    25,    73,    82,    19,    19,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      82,    83,    19,    64,    29,    59,    63,    25,    19,    29,
      31,    74,    74,    75,    75,     3,    20,    82,    29,    25,
      19,    73,    75,    77,    78,    79,    72,    76,    73,    75,
      77,    29,    20,    60,    61,    76,    73,    70,    29,    29,
      73,    77,     7,     8,    42,    43,    44,    45,    80,    20,
      20,    51,    52,    81,    80,    77,    25,    20,    20,    26,
       3,    20,    25,    29,    20,    73,    26,    26,    62,    71,
      78,    79,    29,    26,    26,    27,    62,    61,    26,    27,
      62,    62,    27,    64,    62,    27,    62,    27,    27,    62,
      27,    27,    20,    27,    11,    27,    27,    26,    26,    11,
      62,    27,    62,    26,    27,    27,    27,    62,    27
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    57,    57,    57,    57,    58,    58,    58,
      58,    58,    59,    59,    59,    59,    59,    59,    60,    60,
      61,    62,    62,    62,    63,    63,    63,    63,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    65,    65,    65,
      65,    65,    65,    65,    66,    66,    66,    66,    67,    68,
      68,    69,    69,    70,    71,    71,    72,    72,    73,    73,
      73,    74,    74,    74,    75,    75,    75,    75,    75,    75,
      76,    76,    77,    77,    78,    78,    79,    79,    80,    80,
      80,    80,    80,    80,    81,    81,    82,    82,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     2,     1,     2,
       3,     2,     8,     7,     6,     7,     4,     5,     1,     3,
       2,     2,     1,     1,     1,     2,     2,     3,     3,     3,
       2,     2,     4,     4,     1,     1,     1,     7,     6,    11,
      10,    10,     9,     7,     7,     6,     7,     6,    10,     4,
       3,     1,     3,     1,     1,     2,     3,     5,     1,     3,
       3,     3,     3,     1,     1,     1,     3,     3,     3,     1,
       1,     1,     1,     3,     3,     1,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
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
#line 77 "src/parser.y" /* yacc.c:1646  */
    { g_root = (yyvsp[0].basePtr); }
#line 1459 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 79 "src/parser.y" /* yacc.c:1646  */
    { (yyval.basePtr) = new astList();(yyval.basePtr)->addList((yyvsp[0].listPtr)); }
#line 1465 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 80 "src/parser.y" /* yacc.c:1646  */
    { (yyval.basePtr)->addList((yyvsp[0].listPtr));}
#line 1471 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 81 "src/parser.y" /* yacc.c:1646  */
    { (yyval.basePtr) = new astList();(yyval.basePtr)->addList((yyvsp[0].decList));}
#line 1477 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 82 "src/parser.y" /* yacc.c:1646  */
    { (yyval.basePtr) = new astList(); (yyval.basePtr)->addList((yyvsp[0].basePtr));}
#line 1483 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 88 "src/parser.y" /* yacc.c:1646  */
    { (yyval.listPtr) = new astList(); (yyval.listPtr) -> addList((yyvsp[-1].decList));(yyval.listPtr) -> addList((yyvsp[0].basePtr));}
#line 1489 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 90 "src/parser.y" /* yacc.c:1646  */
    {(yyval.listPtr) = new astList(); (yyval.listPtr) -> addList((yyvsp[0].basePtr));}
#line 1495 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 91 "src/parser.y" /* yacc.c:1646  */
    { (yyval.listPtr)->addList((yyvsp[0].basePtr));}
#line 1501 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 92 "src/parser.y" /* yacc.c:1646  */
    {(yyval.listPtr)->addList((yyvsp[-1].decList));(yyval.listPtr)->addList((yyvsp[0].basePtr)); }
#line 1507 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 93 "src/parser.y" /* yacc.c:1646  */
    {(yyval.listPtr) = new astList(); (yyval.listPtr)->addList((yyvsp[-1].basePtr));}
#line 1513 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 96 "src/parser.y" /* yacc.c:1646  */
    {(yyval.basePtr) = new FunctionDef(*(yyvsp[-7].string),*(yyvsp[-6].string),(yyvsp[-4].paramlistPtr),(yyvsp[-1].listPtr));}
#line 1519 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 98 "src/parser.y" /* yacc.c:1646  */
    {(yyval.basePtr) = new FunctionDef(*(yyvsp[-6].string),*(yyvsp[-5].string),NULL,(yyvsp[-1].listPtr)); }
#line 1525 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 100 "src/parser.y" /* yacc.c:1646  */
    {(yyval.basePtr) = new FunctionDef(*(yyvsp[-5].string),*(yyvsp[-4].string),NULL,NULL);}
#line 1531 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 102 "src/parser.y" /* yacc.c:1646  */
    {(yyval.basePtr) = new FunctionDef(*(yyvsp[-6].string),*(yyvsp[-5].string),(yyvsp[-3].paramlistPtr),NULL);}
#line 1537 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 104 "src/parser.y" /* yacc.c:1646  */
    {(yyval.basePtr) = new astList();}
#line 1543 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 106 "src/parser.y" /* yacc.c:1646  */
    {(yyval.basePtr) = new astList();}
#line 1549 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 114 "src/parser.y" /* yacc.c:1646  */
    { (yyval.paramlistPtr) = new paramList(); (yyval.paramlistPtr) -> addList((yyvsp[0].paramPtr));}
#line 1555 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 115 "src/parser.y" /* yacc.c:1646  */
    { (yyval.paramlistPtr) ->addList((yyvsp[0].paramPtr));}
#line 1561 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 116 "src/parser.y" /* yacc.c:1646  */
    { (yyval.paramPtr) = new Param(*(yyvsp[-1].string),*(yyvsp[0].string));}
#line 1567 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 118 "src/parser.y" /* yacc.c:1646  */
    { (yyval.listPtr) = new astList();(yyval.listPtr)->addList((yyvsp[-1].decList)); (yyval.listPtr)->addList((yyvsp[0].listPtr));}
#line 1573 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 119 "src/parser.y" /* yacc.c:1646  */
    { (yyval.listPtr) = new astList();(yyval.listPtr)->addList((yyvsp[0].listPtr));}
#line 1579 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 120 "src/parser.y" /* yacc.c:1646  */
    { (yyval.listPtr) = new astList();(yyval.listPtr)->addList((yyvsp[0].decList));}
#line 1585 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 124 "src/parser.y" /* yacc.c:1646  */
    {(yyval.listPtr) = new astList();(yyval.listPtr) ->addList((yyvsp[0].basePtr));}
#line 1591 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 125 "src/parser.y" /* yacc.c:1646  */
    {(yyval.listPtr) = new astList();(yyval.listPtr) ->addList((yyvsp[-1].basePtr));}
#line 1597 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 126 "src/parser.y" /* yacc.c:1646  */
    { (yyval.listPtr) -> addList((yyvsp[0].basePtr));}
#line 1603 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 127 "src/parser.y" /* yacc.c:1646  */
    { (yyval.listPtr) -> addList((yyvsp[-1].basePtr));}
#line 1609 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 130 "src/parser.y" /* yacc.c:1646  */
    {
  if (*(yyvsp[-1].string) == "=") {(yyval.basePtr) = new Statement(*(yyvsp[-2].string),*(yyvsp[-1].string),(yyvsp[0].basePtr),false); }
  else {
          Base* var = new Variable(*(yyvsp[-2].string));
          Base* temp = (yyvsp[0].basePtr); // if conditions not met (+/-*)
          if (*(yyvsp[-1].string) == "+=") {  temp = new AddOperator(var,(yyvsp[0].basePtr)); }
          else if (*(yyvsp[-1].string) == "-=") { temp = new SubOperator(var,(yyvsp[0].basePtr)); }
          else if (*(yyvsp[-1].string) == "*=") {  temp = new MulOperator(var,(yyvsp[0].basePtr)); }
          else if (*(yyvsp[-1].string) == "/=") { temp = new DivOperator(var,(yyvsp[0].basePtr)); }

          (yyval.basePtr) = new Statement (*(yyvsp[-2].string),*(yyvsp[-1].string),temp,true); // new statement
  }

}
#line 1628 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 144 "src/parser.y" /* yacc.c:1646  */
    { (yyval.basePtr) = new Statement("","",(yyvsp[-1].basePtr),true); }
#line 1634 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 145 "src/parser.y" /* yacc.c:1646  */
    {(yyval.basePtr) = new Statement(*(yyvsp[0].string),*(yyvsp[-1].string),NULL,false);}
#line 1640 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 146 "src/parser.y" /* yacc.c:1646  */
    {(yyval.basePtr) = new Statement(*(yyvsp[-1].string),*(yyvsp[0].string),NULL,false);}
#line 1646 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 147 "src/parser.y" /* yacc.c:1646  */
    {(yyval.basePtr) = new Statement(*(yyvsp[-2].string),*(yyvsp[-1].string),NULL,true);}
#line 1652 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 148 "src/parser.y" /* yacc.c:1646  */
    {(yyval.basePtr) = new Statement(*(yyvsp[-1].string),*(yyvsp[-2].string),NULL,true);}
#line 1658 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 150 "src/parser.y" /* yacc.c:1646  */
    { (yyval.basePtr)= (yyvsp[0].basePtr);}
#line 1664 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 151 "src/parser.y" /* yacc.c:1646  */
    { (yyval.basePtr) = (yyvsp[0].basePtr);}
#line 1670 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 152 "src/parser.y" /* yacc.c:1646  */
    {(yyval.basePtr)=(yyvsp[0].basePtr);}
#line 1676 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 167 "src/parser.y" /* yacc.c:1646  */
    {(yyval.basePtr) = new ifLoop ((yyvsp[-4].basePtr),(yyvsp[-1].listPtr),"if");}
#line 1682 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 168 "src/parser.y" /* yacc.c:1646  */
    { (yyval.basePtr) = new ifLoop ((yyvsp[-3].basePtr),NULL,"if");}
#line 1688 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 169 "src/parser.y" /* yacc.c:1646  */
    {(yyval.basePtr) = new ifelseLoop ((yyvsp[-8].basePtr),(yyvsp[-5].listPtr),(yyvsp[-1].listPtr),"ifelse");}
#line 1694 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 170 "src/parser.y" /* yacc.c:1646  */
    {(yyval.basePtr) = new ifelseLoop ((yyvsp[-7].basePtr),(yyvsp[-4].listPtr),NULL,"ifelse");}
#line 1700 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 171 "src/parser.y" /* yacc.c:1646  */
    {(yyval.basePtr) = new ifelseLoop ((yyvsp[-7].basePtr),NULL,(yyvsp[-1].listPtr),"ifelse");}
#line 1706 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 172 "src/parser.y" /* yacc.c:1646  */
    {(yyval.basePtr) = new ifelseLoop ((yyvsp[-6].basePtr),NULL,NULL,"ifelse");}
#line 1712 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 174 "src/parser.y" /* yacc.c:1646  */
    {(yyval.basePtr) = new ifLoop ((yyvsp[-4].basePtr),(yyvsp[-1].listPtr),"iffactor");}
#line 1718 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 177 "src/parser.y" /* yacc.c:1646  */
    {(yyval.basePtr) = new ifLoop ((yyvsp[-4].basePtr),(yyvsp[-1].listPtr),"while");}
#line 1724 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 178 "src/parser.y" /* yacc.c:1646  */
    {(yyval.basePtr) = new ifLoop ((yyvsp[-3].basePtr),NULL,"while");}
#line 1730 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 179 "src/parser.y" /* yacc.c:1646  */
    {(yyval.basePtr) = new ifLoop ((yyvsp[-4].basePtr),(yyvsp[-1].listPtr),"whilefactor");}
#line 1736 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 180 "src/parser.y" /* yacc.c:1646  */
    {(yyval.basePtr) = new ifLoop ((yyvsp[-3].basePtr),NULL,"whilefactor");}
#line 1742 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 183 "src/parser.y" /* yacc.c:1646  */
    {

(yyval.basePtr) = new forLoop((yyvsp[-6].basePtr),(yyvsp[-1].listPtr),(yyvsp[-7].basePtr),(yyvsp[-4].basePtr),"for");

}
#line 1752 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 190 "src/parser.y" /* yacc.c:1646  */
    {(yyval.basePtr) = new FunctionCall(*(yyvsp[-3].string),(yyvsp[-1].argListPtr));}
#line 1758 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 191 "src/parser.y" /* yacc.c:1646  */
    {(yyval.basePtr) = new FunctionCall(*(yyvsp[-2].string),NULL);}
#line 1764 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 193 "src/parser.y" /* yacc.c:1646  */
    { (yyval.argListPtr) = new ArgumentList(); (yyval.argListPtr) -> addList((yyvsp[0].argPtr));}
#line 1770 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 194 "src/parser.y" /* yacc.c:1646  */
    { (yyval.argListPtr) ->addList((yyvsp[0].argPtr));}
#line 1776 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 196 "src/parser.y" /* yacc.c:1646  */
    { (yyval.argPtr) = new Argument((yyvsp[0].basePtr));}
#line 1782 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 201 "src/parser.y" /* yacc.c:1646  */
    {(yyval.decList) = new DeclarationList(); (yyval.decList) -> addList((yyvsp[0].basePtr));}
#line 1788 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 203 "src/parser.y" /* yacc.c:1646  */
    {(yyval.decList) -> addList((yyvsp[0].basePtr));}
#line 1794 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 206 "src/parser.y" /* yacc.c:1646  */
    {  (yyval.basePtr) = new Declaration (*(yyvsp[-2].string),*(yyvsp[-1].string),NULL);  }
#line 1800 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 207 "src/parser.y" /* yacc.c:1646  */
    {
  (yyval.basePtr) = new Declaration (*(yyvsp[-4].string),*(yyvsp[-3].string),(yyvsp[-1].basePtr));
}
#line 1808 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 212 "src/parser.y" /* yacc.c:1646  */
    { (yyval.basePtr) =(yyvsp[0].basePtr); }
#line 1814 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 213 "src/parser.y" /* yacc.c:1646  */
    {  (yyval.basePtr) = new AddOperator((yyvsp[-2].basePtr),(yyvsp[0].basePtr)); }
#line 1820 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 214 "src/parser.y" /* yacc.c:1646  */
    {  (yyval.basePtr)= new SubOperator((yyvsp[-2].basePtr),(yyvsp[0].basePtr));}
#line 1826 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 220 "src/parser.y" /* yacc.c:1646  */
    { (yyval.basePtr) = new MulOperator((yyvsp[-2].basePtr),(yyvsp[0].basePtr));}
#line 1832 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 221 "src/parser.y" /* yacc.c:1646  */
    { (yyval.basePtr) = new DivOperator((yyvsp[-2].basePtr),(yyvsp[0].basePtr));}
#line 1838 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 222 "src/parser.y" /* yacc.c:1646  */
    { (yyval.basePtr) = (yyvsp[0].basePtr); }
#line 1844 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 225 "src/parser.y" /* yacc.c:1646  */
    {(yyval.basePtr)= new Number ((yyvsp[0].number)); }
#line 1850 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 226 "src/parser.y" /* yacc.c:1646  */
    {(yyval.basePtr) = new Variable (*(yyvsp[0].string));}
#line 1856 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 227 "src/parser.y" /* yacc.c:1646  */
    { (yyval.basePtr) = (yyvsp[-1].basePtr); }
#line 1862 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 228 "src/parser.y" /* yacc.c:1646  */
    {(yyval.basePtr) = new Char(*(yyvsp[-1].string));}
#line 1868 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 229 "src/parser.y" /* yacc.c:1646  */
    {
        string s =std::to_string((yyvsp[-1].number));(yyval.basePtr) = new Char(s);}
#line 1875 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 231 "src/parser.y" /* yacc.c:1646  */
    {(yyval.basePtr) =(yyvsp[0].basePtr);}
#line 1881 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 234 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string ("int");}
#line 1887 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 235 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string ("char");}
#line 1893 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 239 "src/parser.y" /* yacc.c:1646  */
    { (yyval.basePtr) = (yyvsp[0].basePtr);}
#line 1899 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 240 "src/parser.y" /* yacc.c:1646  */
    {(yyval.basePtr) = new Comp((yyvsp[-2].basePtr),(yyvsp[0].basePtr),*(yyvsp[-1].string));}
#line 1905 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 243 "src/parser.y" /* yacc.c:1646  */
    {(yyval.basePtr) = new Comp((yyvsp[-2].basePtr),(yyvsp[0].basePtr),*(yyvsp[-1].string));}
#line 1911 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 244 "src/parser.y" /* yacc.c:1646  */
    { (yyval.basePtr) = (yyvsp[0].basePtr);}
#line 1917 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 246 "src/parser.y" /* yacc.c:1646  */
    {(yyval.basePtr) = new Comp((yyvsp[-2].basePtr),(yyvsp[0].basePtr),*(yyvsp[-1].string));}
#line 1923 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 247 "src/parser.y" /* yacc.c:1646  */
    { (yyval.basePtr) = (yyvsp[-1].basePtr);}
#line 1929 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 252 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string ("==");}
#line 1935 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 253 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string ("!=");}
#line 1941 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 254 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string (">");}
#line 1947 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 255 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string ("<");}
#line 1953 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 256 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string ("<=");}
#line 1959 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 257 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string (">=");}
#line 1965 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 260 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string ("&&");}
#line 1971 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 261 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string ("||");}
#line 1977 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 263 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string ("++");}
#line 1983 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 264 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string ("--");}
#line 1989 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 268 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string ("=");}
#line 1995 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 269 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string ("*=");}
#line 2001 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 270 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string ("/=");}
#line 2007 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 271 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string ("%=");}
#line 2013 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 272 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string ("+=");}
#line 2019 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 273 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string ("-=");}
#line 2025 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 274 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string ("<<=");}
#line 2031 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 275 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string (">>=");}
#line 2037 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 276 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string ("&=");}
#line 2043 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 277 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string ("^=");}
#line 2049 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 278 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string ("|=");}
#line 2055 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2059 "src/parser.tab.cpp" /* yacc.c:1646  */
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
#line 280 "src/parser.y" /* yacc.c:1906  */


const Base *g_root; // Definition of variable (to match declaration earlier)

const Base *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
