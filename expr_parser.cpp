/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Skeleton implementation for Bison GLR parsers in C

   Copyright (C) 2002-2015 Free Software Foundation, Inc.

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

/* C GLR parser skeleton written by Paul Hilfinger.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "glr.c"

/* Pure parsers.  */
#define YYPURE 0






/* First part of user declarations.  */
#line 4 "expr.y" /* glr.c:240  */

#include <stdio.h>
#include <string.h>

#define SZ 32
int yylex();
extern char* yytext;
extern int yylineno;
extern char *yyfilename;
void yyerror(const char *msg){

printf("Error : String(%s) Line %d : %s  file: %s   \n",yytext,yylineno,msg,yyfilename);
}


	
#define YYERROR_VERBOSE 1
#define YYDEBUG 1

#line 74 "expr_parser.cpp" /* glr.c:240  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "tokens.h"

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Default (constant) value used for initialization for null
   right-hand sides.  Unlike the standard yacc.c template, here we set
   the default value of $$ to a zeroed-out value.  Since the default
   value is undefined, this behavior is technically correct.  */
static YYSTYPE yyval_default;

/* Copy the second part of user declarations.  */

#line 102 "expr_parser.cpp" /* glr.c:263  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

#ifndef YYFREE
# define YYFREE free
#endif
#ifndef YYMALLOC
# define YYMALLOC malloc
#endif
#ifndef YYREALLOC
# define YYREALLOC realloc
#endif

#define YYSIZEMAX ((size_t) -1)

#ifdef __cplusplus
   typedef bool yybool;
#else
   typedef unsigned char yybool;
#endif
#define yytrue 1
#define yyfalse 0

#ifndef YYSETJMP
# include <setjmp.h>
# define YYJMP_BUF jmp_buf
# define YYSETJMP(Env) setjmp (Env)
/* Pacify clang.  */
# define YYLONGJMP(Env, Val) (longjmp (Env, Val), YYASSERT (0))
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


#ifndef YYASSERT
# define YYASSERT(Condition) ((void) ((Condition) || (abort (), 0)))
#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   714

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  176
/* YYNRULES -- Number of states.  */
#define YYNSTATES  377
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 16
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYTRANSLATE(X) -- Bison symbol number corresponding to X.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   321

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,    58,    58,    61,    62,    64,    65,    68,    69,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      86,    88,    90,    92,    94,    95,    96,    97,   101,   103,
     104,   106,   108,   109,   113,   114,   116,   117,   120,   121,
     122,   125,   126,   131,   135,   136,   138,   139,   142,   143,
     145,   148,   149,   152,   153,   155,   158,   159,   162,   163,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   179,
     182,   183,   184,   185,   188,   189,   191,   193,   194,   197,
     198,   202,   205,   208,   209,   214,   215,   219,   220,   224,
     225,   230,   232,   234,   236,   242,   243,   244,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   261,
     262,   264,   265,   268,   269,   273,   274,   276,   278,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     294,   295,   298,   299,   300,   302,   303,   304,   305,   307,
     308,   309,   310,   311,   312,   313,   315,   316,   317,   319,
     320,   321,   324,   325,   326,   327,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   348,   349,   350,   351,   352,   353
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_Op_add", "TK_Op_sub", "TK_Op_mul",
  "TK_Op_div", "TK_left_par", "TK_rigth_par", "TK_EOL", "TK_Error",
  "TK_EOF", "TK_ERROR", "TK_Asignacion", "TK_Dolar", "TK_NUMERO",
  "TK_Print", "TK_Separador", "TK_Igual", "TK_Distinto", "TK_Menor",
  "TK_Mayor", "TK_MenorIgual", "TK_MayorIgual", "TK_IF", "TK_Else",
  "TK_left_llave", "TK_rigth_llave", "TK_VarNombre", "TK_While",
  "TK_left_corchete", "TK_rigth_corchete", "TK_Refenciacion",
  "TK_PuntoComma", "TK_Char", "TK_Int", "TK_Void", "TK_For", "TK_Scanf",
  "TK_String", "TK_CharLit", "TK_Modulo", "TK_Comma", "TK_AutoAdd",
  "TK_AutoSub", "TK_AutoMul", "TK_AutoDiv", "TK_AsigOrBit",
  "TK_AsigCorIzq", "TK_AsigCorDer", "TK_Incremento", "TK_Decremento",
  "TK_CorrimientoIzq", "TK_CorrimientoDer", "TK_ExclPorBit", "TK_And",
  "TK_Or", "TK_OPorBit", "TK_Interogaccion", "TK_Negarcion",
  "TK_Complemento", "TK_DosPuntos", "TK_AsigAndBit", "TK_AsigXorBit",
  "TK_AutoMod", "TK_Do", "TK_Return", "$accept", "inputs", "statementList",
  "declarationList", "inputStatement", "statement", "incremente_statement",
  "callFuncion_statement", "optionalParameter", "declaration_statement",
  "multideclarationImput", "multiDeclaration", "uniMultideclaration",
  "funcion_statement", "producce_statement", "optparametroList",
  "parametroList", "parametro", "optionalExpr", "optionalBlock",
  "BlockStatementFuncion", "inputStatementFuncion", "statementListFuncion",
  "statementFuncion", "return_statement", "optionalAssign", "Type",
  "for_statement", "for_assign", "if_statement", "while_statement",
  "doWhile_statement", "BlockStatementOrStatement", "print_statement",
  "scanf_statement", "arg_list", "assign_statement", "incrementopt",
  "opAssignStatement", "eols", "opt_eols", "ternario", "assignExpr",
  "opAssign", "expr", "andOr", "exprForBit", "conditional", "corrimiento",
  "add", "term", "unary", "factor", YY_NULLPTR
};
#endif

#define YYPACT_NINF -304
#define YYTABLE_NINF -58

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const short int yypact[] =
{
    -304,   107,   404,  -304,     7,  -304,    62,   104,   257,   129,
     116,  -304,  -304,   142,   191,   199,   159,   186,  -304,   131,
    -304,  -304,  -304,   185,   187,   210,  -304,  -304,    98,  -304,
    -304,  -304,   218,   222,   225,   233,   229,   232,   548,   548,
    -304,   548,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,
    -304,  -304,  -304,  -304,   548,   548,   625,   242,  -304,   255,
     239,   266,   203,   404,   404,   290,  -304,  -304,  -304,   300,
     138,  -304,  -304,  -304,  -304,  -304,  -304,   625,     4,    34,
     582,  -304,   452,   174,  -304,   189,   214,   548,   548,  -304,
    -304,   328,   230,    47,    70,   236,   307,    18,  -304,  -304,
     330,   292,  -304,   310,  -304,   343,   548,   256,   171,     8,
     548,   548,  -304,  -304,   109,  -304,  -304,   247,   320,   223,
     256,   519,   548,   315,   548,  -304,   548,   331,   650,   111,
     357,   548,  -304,   548,  -304,  -304,  -304,  -304,  -304,  -304,
    -304,  -304,  -304,  -304,  -304,  -304,   548,   342,   650,   345,
    -304,   350,  -304,  -304,  -304,   372,   585,   585,   585,   585,
     585,   585,   585,   585,   585,   585,   585,   548,   585,   585,
     585,   585,   585,   585,   585,  -304,   548,   603,  -304,  -304,
     381,   370,  -304,   172,   613,  -304,  -304,  -304,   548,   361,
     368,   404,   406,   420,    20,  -304,   256,   315,   427,   548,
    -304,  -304,   412,   177,  -304,  -304,    32,   429,   548,   282,
    -304,   436,   414,  -304,   438,   548,   448,   449,  -304,   326,
     216,    21,   217,   147,   295,   156,   304,   365,   403,   291,
     293,   296,   316,   327,   344,   400,   402,   407,    27,    55,
    -304,  -304,  -304,  -304,  -304,  -304,   548,   203,  -304,   256,
     432,   433,   548,    48,    35,  -304,  -304,  -304,   455,   457,
     459,  -304,  -304,   184,   460,   444,    24,   441,  -304,  -304,
    -304,  -304,  -304,  -304,  -304,   650,  -304,  -304,  -304,  -304,
    -304,   466,  -304,   548,  -304,   548,  -304,  -304,    69,  -304,
    -304,   548,   453,  -304,  -304,   366,   548,  -304,    69,  -304,
     315,   460,   548,  -304,   177,   548,   461,   454,  -304,  -304,
    -304,  -304,  -304,   458,  -304,   625,   524,  -304,   480,    69,
    -304,  -304,  -304,   463,  -304,  -304,   481,  -304,    10,  -304,
    -304,  -304,  -304,   460,   442,   474,   548,  -304,   472,  -304,
     144,  -304,   473,   181,  -304,  -304,  -304,   475,   476,   477,
     478,    61,  -304,  -304,  -304,    10,  -304,   180,   101,  -304,
     484,    86,  -304,  -304,  -304,  -304,  -304,   207,  -304,  -304,
     460,   524,  -304,   399,  -304,   203,  -304
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const unsigned char yydefact[] =
{
     112,     0,     0,     1,     0,   111,     0,     0,     0,     0,
       0,    75,    74,     0,     0,     0,     0,     0,   112,   112,
     112,   112,     4,     0,     0,     0,    17,    14,     0,    15,
       9,    10,     0,     0,     0,     0,    97,     0,     0,    30,
      98,     0,    99,   100,   101,   102,   104,   107,   108,    25,
      24,   105,   106,   103,     0,     0,     0,     0,   112,     0,
      27,    26,     0,     0,     0,     2,    19,    18,     6,     0,
      73,    16,    11,    12,    13,    95,    96,     0,     0,     0,
       0,   173,   171,     0,   174,     0,     0,     0,     0,   131,
     130,     0,   114,   134,   138,   145,   148,   151,   155,   170,
       0,    29,    90,     0,    91,     0,     0,    45,    78,     0,
       0,     0,   112,    83,     0,   112,     3,   112,     0,    73,
      45,     0,     0,    35,     0,    86,     0,     0,   158,   171,
       0,    30,   119,     0,   120,   121,   122,   123,   125,   128,
     129,   166,   168,   126,   127,   124,     0,     0,   160,     0,
     162,     0,   164,   156,   157,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    28,     0,     0,   112,    93,
       0,    44,    47,     0,     0,   112,    77,    88,     0,     0,
       0,     0,     0,     0,     0,     5,    45,    35,     0,     0,
      71,    70,     0,     0,    33,    94,     0,     0,     0,     0,
     176,     0,     0,   115,     0,     0,     0,     0,   110,     0,
       0,   171,     0,   132,   138,   133,   137,   136,   135,   139,
     140,   141,   142,   143,   144,     0,   146,   147,   149,   150,
     152,   153,   154,    89,    23,    22,     0,     0,   112,     0,
       0,    48,     0,     0,     0,    20,    21,   112,     0,     0,
       0,    32,   112,     0,    73,     0,    73,    34,    37,    85,
     159,   118,   167,   169,   172,   175,   161,   117,   163,   165,
     109,    80,   158,     0,   160,     0,    92,    81,     0,    46,
      49,    52,     0,   112,    87,     0,     0,   112,     0,    72,
      35,    73,     0,    40,     0,     0,     0,     0,   113,   112,
      54,    43,    53,     0,    51,     0,     0,    84,     0,     0,
      41,    31,    39,     0,    36,   116,     0,   175,     0,    50,
     112,    82,    42,    73,     0,     0,     0,   112,     0,   112,
     112,    59,     0,     0,    65,    60,    61,     0,     0,     0,
       0,     0,    38,    79,    69,     0,    67,     0,     0,    68,
       0,    73,    66,    62,    63,    64,   112,   112,    55,    58,
      73,     0,   112,     0,   112,     0,    76
};

  /* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -304,  -304,   -57,   163,  -304,     3,  -304,  -303,   382,   -60,
    -187,  -304,   221,  -304,  -304,  -111,  -304,   278,  -304,   -73,
    -304,  -304,   173,   182,  -304,  -118,     1,  -275,  -304,  -223,
    -208,  -186,  -211,  -165,  -163,  -115,   -95,  -304,   -50,  -304,
       0,  -304,  -304,  -126,   -24,  -304,   258,   117,   287,   250,
     259,   110,  -304
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const short int yydefgoto[] =
{
      -1,     1,    19,    20,    21,   113,    23,    24,   100,    25,
     204,   267,   268,    26,    27,   180,   181,   182,   313,   311,
     312,   339,   340,   341,   342,   123,   114,    29,   185,    30,
      31,    32,   115,    33,    34,   101,    35,    77,    54,   219,
      63,    89,    90,   146,   102,    92,    93,    94,    95,    96,
      97,    98,    99
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const short int yytable[] =
{
       2,   197,   208,    28,   118,    22,   106,   117,   281,   198,
     261,   206,   125,   186,    91,     4,   187,   103,    62,     5,
      64,    65,   215,   172,   173,   338,     6,   124,   131,     5,
     104,   105,   172,   173,     7,    36,   287,   121,   335,     9,
     269,   127,    10,   294,    11,    12,   126,    14,    15,   259,
     188,   283,   338,   344,   302,   338,   130,     5,   108,   174,
     172,   173,   128,   153,   154,    28,   116,    22,   174,    37,
       5,   141,   142,   254,   176,    18,   336,   176,     5,   158,
     344,   293,   179,   344,   263,   260,   189,   190,   161,   162,
     163,   164,   165,   166,   366,   309,   174,   201,   202,   121,
     205,   159,   310,    69,   160,   345,     4,     3,   183,   212,
       5,    38,   191,   321,   192,   194,   122,     6,   131,   209,
     346,   183,   213,   353,   132,     7,    70,   246,   167,   335,
       9,    -8,   345,    10,   257,   345,    55,   193,    14,    15,
      -8,   133,   347,   235,    56,   120,   300,   346,   303,   305,
     346,   121,   243,   -57,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   348,   376,   349,    18,   336,   122,   347,
      57,   -57,   347,   143,   144,   145,     4,   250,   247,   158,
       5,   147,   265,   322,   271,   253,   360,    60,   158,     5,
     348,   277,   349,   348,    22,   349,   149,   183,    58,   184,
     251,   159,   148,    10,   160,   266,    59,   368,     4,   361,
     159,   299,     5,   160,    61,   352,   -56,   150,    66,     6,
      67,   151,   286,   127,   147,   320,   176,     7,   292,   112,
     196,     8,     9,   350,   -56,    10,   121,    11,    12,    13,
      14,    15,   152,    68,   282,   284,   332,    -7,   288,   107,
     183,    71,   197,    16,    17,    72,    -7,   295,    73,   307,
     350,   308,   298,   350,    39,   246,    74,   314,    18,   110,
      40,    78,   318,   224,   224,   226,   227,   228,   323,    75,
      76,   325,   240,   241,   242,   156,   157,    41,   168,   169,
      11,    12,   330,   316,   109,   118,   111,   319,   116,     5,
      42,    43,    44,    45,    46,    47,    48,    49,    50,   328,
     170,   171,   354,   161,   162,   163,   164,   165,   166,    51,
      52,    53,   161,   162,   163,   164,   165,   166,   119,   343,
     351,     4,   272,   273,   176,   280,   155,   355,   175,   357,
     358,   177,     6,   168,   169,   168,   169,   372,   168,   169,
       7,   178,   112,   195,     8,     9,   343,   203,    10,   207,
      11,    12,    13,    14,    15,   210,   371,   358,   168,   169,
     214,     4,   373,   216,   375,     5,    16,    17,   217,   168,
     169,   218,     6,   161,   162,   163,   164,   165,   166,   248,
       7,    18,   255,   317,     8,     9,   168,   169,    10,   256,
      11,    12,    13,    14,    15,   170,   171,   374,     5,     4,
     170,   171,   249,     5,   223,   225,    16,    17,   236,   237,
       6,   161,   162,   163,   164,   165,   166,   120,     7,   238,
     239,    18,     8,     9,   258,   262,    10,   270,    11,    12,
      13,    14,    15,   264,   274,   275,   276,     4,   229,   230,
     231,   232,   233,   234,    16,    17,   278,   279,     6,   131,
     290,   285,   196,   291,   296,   132,     7,   297,   112,    18,
       8,     9,   301,   121,    10,   306,    11,    12,    13,    14,
      15,    39,   133,   304,   315,   327,   326,    40,   331,   329,
     334,   337,    16,    17,   333,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   252,   356,   359,    18,   362,   363,
     364,   365,   370,   211,   143,   144,   145,    42,    43,    44,
      45,    46,    47,    48,    79,   324,    80,   289,   367,    79,
       0,    80,     0,     5,    81,     0,    51,    52,    53,    81,
     369,     0,     0,     0,     0,   199,     0,    82,     0,     0,
       0,    83,    82,    79,     0,    80,    83,     0,   200,    84,
       0,     0,     0,    81,    84,     0,     0,     0,     0,    85,
      86,     0,     0,     0,    85,    86,    82,     0,    87,    88,
      83,     0,     0,    87,    88,     0,     0,    79,    84,    80,
     220,     0,    80,     0,     0,     0,     0,    81,    85,    86,
      81,     0,     0,     0,     0,     0,     0,    87,    88,     0,
     129,     0,     0,   221,    83,     0,    40,   222,     0,     0,
       0,     0,    84,     0,     0,    84,    40,     0,     0,     0,
       0,     0,    85,    86,     0,    85,    86,     0,    40,     0,
       0,    87,    88,   252,    87,    88,    42,    43,    44,    45,
      46,    47,    48,   244,   245,     0,    42,    43,    44,    45,
      46,    47,    48,   132,     0,    51,    52,    53,    42,    43,
      44,    45,    46,    47,    48,    51,    52,    53,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    51,    52,    53,
       0,     0,     0,   134,   135,   136,   137,   138,   139,   140,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   143,   144,   145
};

static const short int yycheck[] =
{
       0,   119,   128,     2,    64,     2,    56,    64,   219,   120,
     197,   126,     8,   108,    38,     5,     8,    41,    18,     9,
      20,    21,   148,     5,     6,   328,    16,    77,     7,     9,
      54,    55,     5,     6,    24,    28,   247,    13,    28,    29,
       8,     7,    32,     8,    34,    35,    42,    37,    38,    29,
      42,    30,   355,   328,    30,   358,    80,     9,    58,    41,
       5,     6,    28,    87,    88,    64,    63,    64,    41,     7,
       9,    50,    51,   188,    42,    65,    66,    42,     9,    32,
     355,    33,   106,   358,   199,   196,   110,   111,    18,    19,
      20,    21,    22,    23,    33,    26,    41,   121,   122,    13,
     124,    54,    33,     5,    57,   328,     5,     0,   107,   133,
       9,     7,   112,   300,     5,   115,    30,    16,     7,     8,
     328,   120,   146,   334,    13,    24,    28,   177,    58,    28,
      29,     0,   355,    32,   191,   358,     7,    28,    37,    38,
       9,    30,   328,   167,    28,     7,   264,   355,   266,   275,
     358,    13,   176,     9,    43,    44,    45,    46,    47,    48,
      49,    50,    51,   328,   375,   328,    65,    66,    30,   355,
      28,    27,   358,    62,    63,    64,     5,     5,   178,    32,
       9,     7,     5,   301,   208,   185,     5,    28,    32,     9,
     355,   215,   355,   358,   191,   358,     7,   196,     7,    28,
      28,    54,    28,    32,    57,    28,     7,    27,     5,    28,
      54,    27,     9,    57,    28,   333,     9,    28,    33,    16,
      33,     7,   246,     7,     7,   298,    42,    24,   252,    26,
       7,    28,    29,   328,    27,    32,    13,    34,    35,    36,
      37,    38,    28,    33,    28,    28,   319,     0,   248,     7,
     249,    33,   370,    50,    51,    33,     9,   257,    33,   283,
     355,   285,   262,   358,     7,   315,    33,   291,    65,    30,
      13,    39,   296,   156,   157,   158,   159,   160,   302,    50,
      51,   305,   172,   173,   174,    55,    56,    30,    52,    53,
      34,    35,   316,   293,    39,   355,    30,   297,   295,     9,
      43,    44,    45,    46,    47,    48,    49,    50,    51,   309,
       3,     4,   336,    18,    19,    20,    21,    22,    23,    62,
      63,    64,    18,    19,    20,    21,    22,    23,    28,   328,
     330,     5,    50,    51,    42,     9,     8,   337,     8,   339,
     340,    31,    16,    52,    53,    52,    53,   371,    52,    53,
      24,     8,    26,    33,    28,    29,   355,    42,    32,    28,
      34,    35,    36,    37,    38,     8,   366,   367,    52,    53,
      28,     5,   372,    28,   374,     9,    50,    51,    28,    52,
      53,     9,    16,    18,    19,    20,    21,    22,    23,     8,
      24,    65,    31,    27,    28,    29,    52,    53,    32,    31,
      34,    35,    36,    37,    38,     3,     4,     8,     9,     5,
       3,     4,    42,     9,   156,   157,    50,    51,   168,   169,
      16,    18,    19,    20,    21,    22,    23,     7,    24,   170,
     171,    65,    28,    29,    28,     8,    32,     8,    34,    35,
      36,    37,    38,    31,     8,    31,     8,     5,   161,   162,
     163,   164,   165,   166,    50,    51,     8,     8,    16,     7,
      28,    61,     7,    30,     7,    13,    24,     8,    26,    65,
      28,    29,    28,    13,    32,     9,    34,    35,    36,    37,
      38,     7,    30,    42,    31,    31,    25,    13,     8,    31,
       9,   328,    50,    51,    31,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    30,    33,    33,    65,    33,    33,
      33,    33,    28,   131,    62,    63,    64,    43,    44,    45,
      46,    47,    48,    49,     5,   304,     7,   249,   355,     5,
      -1,     7,    -1,     9,    15,    -1,    62,    63,    64,    15,
     358,    -1,    -1,    -1,    -1,    26,    -1,    28,    -1,    -1,
      -1,    32,    28,     5,    -1,     7,    32,    -1,    39,    40,
      -1,    -1,    -1,    15,    40,    -1,    -1,    -1,    -1,    50,
      51,    -1,    -1,    -1,    50,    51,    28,    -1,    59,    60,
      32,    -1,    -1,    59,    60,    -1,    -1,     5,    40,     7,
       5,    -1,     7,    -1,    -1,    -1,    -1,    15,    50,    51,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    -1,
      28,    -1,    -1,    28,    32,    -1,    13,    32,    -1,    -1,
      -1,    -1,    40,    -1,    -1,    40,    13,    -1,    -1,    -1,
      -1,    -1,    50,    51,    -1,    50,    51,    -1,    13,    -1,
      -1,    59,    60,    30,    59,    60,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    -1,    43,    44,    45,    46,
      47,    48,    49,    13,    -1,    62,    63,    64,    43,    44,
      45,    46,    47,    48,    49,    62,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    63,    64
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    68,   107,     0,     5,     9,    16,    24,    28,    29,
      32,    34,    35,    36,    37,    38,    50,    51,    65,    69,
      70,    71,    72,    73,    74,    76,    80,    81,    93,    94,
      96,    97,    98,   100,   101,   103,    28,     7,     7,     7,
      13,    30,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    62,    63,    64,   105,     7,    28,    28,     7,     7,
      28,    28,   107,   107,   107,   107,    33,    33,    33,     5,
      28,    33,    33,    33,    33,    50,    51,   104,    39,     5,
       7,    15,    28,    32,    40,    50,    51,    59,    60,   108,
     109,   111,   112,   113,   114,   115,   116,   117,   118,   119,
      75,   102,   111,   111,   111,   111,   105,     7,   107,    39,
      30,    30,    26,    72,    93,    99,    72,    69,    76,    28,
       7,    13,    30,    92,   105,     8,    42,     7,    28,    28,
     111,     7,    13,    30,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    62,    63,    64,   110,     7,    28,     7,
      28,     7,    28,   111,   111,     8,    55,    56,    32,    54,
      57,    18,    19,    20,    21,    22,    23,    58,    52,    53,
       3,     4,     5,     6,    41,     8,    42,    31,     8,   111,
      82,    83,    84,    93,    28,    95,   103,     8,    42,   111,
     111,   107,     5,    28,   107,    33,     7,    92,    82,    26,
      39,   111,   111,    42,    77,   111,   102,    28,   110,     8,
       8,    75,   111,   111,    28,   110,    28,    28,     9,   106,
       5,    28,    32,   113,   114,   113,   114,   114,   114,   115,
     115,   115,   115,   115,   115,   111,   116,   116,   117,   117,
     118,   118,   118,   111,    50,    51,   105,   107,     8,    42,
       5,    28,    30,   107,   102,    31,    31,    69,    28,    29,
      82,    77,     8,   102,    31,     5,    28,    78,    79,     8,
       8,   111,    50,    51,     8,    31,     8,   111,     8,     8,
       9,    99,    28,    30,    28,    61,   111,    99,   107,    84,
      28,    30,   111,    33,     8,   107,     7,     8,   107,    27,
      92,    28,    30,    92,    42,   110,     9,   111,   111,    26,
      33,    86,    87,    85,   111,    31,   107,    27,   111,   107,
      86,    77,    92,   111,    79,   111,    25,    31,   107,    31,
     111,     8,    86,    31,     9,    28,    66,    70,    74,    88,
      89,    90,    91,    93,    94,    96,    97,    98,   100,   101,
     103,   107,    92,    99,   111,   107,    33,   107,   107,    33,
       5,    28,    33,    33,    33,    33,    33,    89,    27,    90,
      28,   107,   111,   107,     8,   107,    99
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    67,    68,    69,    69,    70,    70,    71,    71,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      73,    73,    73,    73,    73,    73,    73,    73,    74,    75,
      75,    76,    76,    76,    77,    77,    78,    78,    79,    79,
      79,    80,    80,    81,    82,    82,    83,    83,    84,    84,
      84,    85,    85,    86,    86,    87,    88,    88,    89,    89,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    91,
      92,    92,    92,    92,    93,    93,    94,    95,    95,    96,
      96,    97,    98,    99,    99,   100,   100,   101,   101,   102,
     102,   103,   103,   103,   103,   104,   104,   104,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   106,
     106,   107,   107,   108,   108,   109,   109,   109,   109,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     111,   111,   112,   112,   112,   113,   113,   113,   113,   114,
     114,   114,   114,   114,   114,   114,   115,   115,   115,   116,
     116,   116,   117,   117,   117,   117,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   119,   119,   119,   119,   119,   119
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     3,     3,     1,     4,     2,     3,     1,     1,
       1,     2,     2,     2,     1,     1,     2,     1,     2,     2,
       5,     5,     5,     5,     2,     2,     2,     2,     4,     1,
       0,     7,     5,     4,     2,     0,     3,     1,     5,     3,
       2,     7,     8,     7,     1,     0,     3,     1,     2,     3,
       5,     1,     0,     1,     1,     5,     3,     1,     3,     1,
       1,     1,     2,     2,     2,     1,     2,     2,     2,     2,
       2,     2,     4,     0,     1,     1,    16,     1,     0,    10,
       6,     6,     8,     1,     5,     6,     4,     6,     4,     3,
       1,     3,     6,     4,     5,     1,     1,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     2,     0,     5,     1,     3,     6,     4,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     3,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     1,     2,     2,     2,     4,
       2,     4,     2,     4,     2,     4,     2,     4,     2,     4,
       1,     1,     4,     1,     1,     4,     3
};


/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
static const unsigned char yydprec[] =
{
       0,     0,     0,     2,     1,     2,     1,     2,     1,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       1,     0,     0,     0,     0,     0,     1,     2,     0,     0,
       0,     0,     0,     0,     2,     1,     2,     1,     0,     0,
       0,     2,     1,     2,     1,     0,     2,     1,     2,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     3,     2,     4,     0,     0,     0,     2,     1,     1,
       2,     0,     0,     1,     2,     2,     1,     1,     1,     2,
       2,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     2,     2,     3,     1,     2,     3,     4,     1,     1,
       2,     3,     4,     5,     6,     7,     1,     2,     3,     1,
       2,     3,     1,     2,     3,     4,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     0,     0,     0,     0,     0,     0
};

/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM.  */
static const unsigned char yymerger[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0
};

/* YYIMMEDIATE[RULE-NUM] -- True iff rule #RULE-NUM is not to be deferred, as
   in the case of predicates.  */
static const yybool yyimmediate[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const unsigned char yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    35,    37,     0,     0,     0,     0,     0,
       0,     0,   139,   141,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    39,
     145,   147,     0,     0,     0,     0,     0,     0,   143,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       0,     0,     0,     0,     0,     0,     0,     0,    13,    15,
      17,    19,    21,    23,     0,     0,   149,     0,     0,     0,
       0,     9,     0,     0,    11,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    45,
       0,     0,     0,     0,     0,     0,     0,     0,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   153,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    47,
      41,     0,     0,     0,     0,     0,     0,     0,    65,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    49,     0,     0,    51,     0,     0,     0,     0,     0,
      67,     0,     0,    69,     0,     0,   155,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    43,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     3,     5,     0,    27,    29,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      31,    33,     0,    53,    55,    57,    59,    61,    63,     0,
       0,     0,    71,    73,    75,    77,    79,    81,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   107,   109,   111,   113,     0,   115,   117,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   119,   121,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   123,
     125,     0,     0,    83,    85,    87,    89,    91,    93,     0,
       0,     0,     0,     0,     0,     0,   127,   129,     0,     0,
       0,     0,     0,     0,     0,   131,   133,     0,     0,     0,
     135,   137,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    95,    97,    99,   101,   103,   105,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   151,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short int yyconfl[] =
{
       0,   112,     0,   114,     0,   114,     0,   134,     0,   134,
       0,   134,     0,   138,     0,   138,     0,   138,     0,   138,
       0,   138,     0,   138,     0,   138,     0,   145,     0,   145,
       0,   148,     0,   148,     0,   151,     0,   151,     0,   151,
       0,    78,     0,   112,     0,   171,     0,   132,     0,   132,
       0,   132,     0,   138,     0,   138,     0,   138,     0,   138,
       0,   138,     0,   138,     0,   133,     0,   133,     0,   133,
       0,   137,     0,   137,     0,   137,     0,   137,     0,   137,
       0,   137,     0,   136,     0,   136,     0,   136,     0,   136,
       0,   136,     0,   136,     0,   135,     0,   135,     0,   135,
       0,   135,     0,   135,     0,   135,     0,   139,     0,   139,
       0,   140,     0,   140,     0,   141,     0,   141,     0,   142,
       0,   142,     0,   143,     0,   143,     0,   144,     0,   144,
       0,   146,     0,   146,     0,   147,     0,   147,     0,   149,
       0,   149,     0,   149,     0,   150,     0,   150,     0,   150,
       0,    80,     0,   112,     0,   112,     0
};

/* Error token number */
#define YYTERROR 1



YYSTYPE yylval;

int yynerrs;
int yychar;

static const int YYEOF = 0;
static const int YYEMPTY = -2;

typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;

#define YYCHK(YYE)                              \
  do {                                          \
    YYRESULTTAG yychk_flag = YYE;               \
    if (yychk_flag != yyok)                     \
      return yychk_flag;                        \
  } while (0)

#if YYDEBUG

# ifndef YYFPRINTF
#  define YYFPRINTF fprintf
# endif

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YYDPRINTF(Args)                        \
  do {                                          \
    if (yydebug)                                \
      YYFPRINTF Args;                           \
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

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                  \
  do {                                                                  \
    if (yydebug)                                                        \
      {                                                                 \
        YYFPRINTF (stderr, "%s ", Title);                               \
        yy_symbol_print (stderr, Type, Value);        \
        YYFPRINTF (stderr, "\n");                                       \
      }                                                                 \
  } while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;

struct yyGLRStack;
static void yypstack (struct yyGLRStack* yystackp, size_t yyk)
  YY_ATTRIBUTE_UNUSED;
static void yypdumpstack (struct yyGLRStack* yystackp)
  YY_ATTRIBUTE_UNUSED;

#else /* !YYDEBUG */

# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)

#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYMAXDEPTH * sizeof (GLRStackItem)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

/* Minimum number of free items on the stack allowed after an
   allocation.  This is to allow allocation and initialization
   to be completed by functions that call yyexpandGLRStack before the
   stack is expanded, thus insuring that all necessary pointers get
   properly redirected to new data.  */
#define YYHEADROOM 2

#ifndef YYSTACKEXPANDABLE
#  define YYSTACKEXPANDABLE 1
#endif

#if YYSTACKEXPANDABLE
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyexpandGLRStack (Yystack);                       \
  } while (0)
#else
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyMemoryExhausted (Yystack);                      \
  } while (0)
#endif


#if YYERROR_VERBOSE

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
static size_t
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      size_t yyn = 0;
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
    return strlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

#endif /* !YYERROR_VERBOSE */

/** State numbers, as in LALR(1) machine */
typedef int yyStateNum;

/** Rule numbers, as in LALR(1) machine */
typedef int yyRuleNum;

/** Grammar symbol */
typedef int yySymbol;

/** Item references, as in LALR(1) machine */
typedef short int yyItemNum;

typedef struct yyGLRState yyGLRState;
typedef struct yyGLRStateSet yyGLRStateSet;
typedef struct yySemanticOption yySemanticOption;
typedef union yyGLRStackItem yyGLRStackItem;
typedef struct yyGLRStack yyGLRStack;

struct yyGLRState {
  /** Type tag: always true.  */
  yybool yyisState;
  /** Type tag for yysemantics.  If true, yysval applies, otherwise
   *  yyfirstVal applies.  */
  yybool yyresolved;
  /** Number of corresponding LALR(1) machine state.  */
  yyStateNum yylrState;
  /** Preceding state in this stack */
  yyGLRState* yypred;
  /** Source position of the last token produced by my symbol */
  size_t yyposn;
  union {
    /** First in a chain of alternative reductions producing the
     *  non-terminal corresponding to this state, threaded through
     *  yynext.  */
    yySemanticOption* yyfirstVal;
    /** Semantic value for this state.  */
    YYSTYPE yysval;
  } yysemantics;
};

struct yyGLRStateSet {
  yyGLRState** yystates;
  /** During nondeterministic operation, yylookaheadNeeds tracks which
   *  stacks have actually needed the current lookahead.  During deterministic
   *  operation, yylookaheadNeeds[0] is not maintained since it would merely
   *  duplicate yychar != YYEMPTY.  */
  yybool* yylookaheadNeeds;
  size_t yysize, yycapacity;
};

struct yySemanticOption {
  /** Type tag: always false.  */
  yybool yyisState;
  /** Rule number for this reduction */
  yyRuleNum yyrule;
  /** The last RHS state in the list of states to be reduced.  */
  yyGLRState* yystate;
  /** The lookahead for this reduction.  */
  int yyrawchar;
  YYSTYPE yyval;
  /** Next sibling in chain of options.  To facilitate merging,
   *  options are chained in decreasing order by address.  */
  yySemanticOption* yynext;
};

/** Type of the items in the GLR stack.  The yyisState field
 *  indicates which item of the union is valid.  */
union yyGLRStackItem {
  yyGLRState yystate;
  yySemanticOption yyoption;
};

struct yyGLRStack {
  int yyerrState;


  YYJMP_BUF yyexception_buffer;
  yyGLRStackItem* yyitems;
  yyGLRStackItem* yynextFree;
  size_t yyspaceLeft;
  yyGLRState* yysplitPoint;
  yyGLRState* yylastDeleted;
  yyGLRStateSet yytops;
};

#if YYSTACKEXPANDABLE
static void yyexpandGLRStack (yyGLRStack* yystackp);
#endif

static _Noreturn void
yyFail (yyGLRStack* yystackp, const char* yymsg)
{
  if (yymsg != YY_NULLPTR)
    yyerror (yymsg);
  YYLONGJMP (yystackp->yyexception_buffer, 1);
}

static _Noreturn void
yyMemoryExhausted (yyGLRStack* yystackp)
{
  YYLONGJMP (yystackp->yyexception_buffer, 2);
}

#if YYDEBUG || YYERROR_VERBOSE
/** A printable representation of TOKEN.  */
static inline const char*
yytokenName (yySymbol yytoken)
{
  if (yytoken == YYEMPTY)
    return "";

  return yytname[yytoken];
}
#endif

/** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
 *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
 *  containing the pointer to the next state in the chain.  */
static void yyfillin (yyGLRStackItem *, int, int) YY_ATTRIBUTE_UNUSED;
static void
yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
{
  int i;
  yyGLRState *s = yyvsp[yylow0].yystate.yypred;
  for (i = yylow0-1; i >= yylow1; i -= 1)
    {
#if YYDEBUG
      yyvsp[i].yystate.yylrState = s->yylrState;
#endif
      yyvsp[i].yystate.yyresolved = s->yyresolved;
      if (s->yyresolved)
        yyvsp[i].yystate.yysemantics.yysval = s->yysemantics.yysval;
      else
        /* The effect of using yysval or yyloc (in an immediate rule) is
         * undefined.  */
        yyvsp[i].yystate.yysemantics.yyfirstVal = YY_NULLPTR;
      s = yyvsp[i].yystate.yypred = s->yypred;
    }
}

/* Do nothing if YYNORMAL or if *YYLOW <= YYLOW1.  Otherwise, fill in
 * YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
 * For convenience, always return YYLOW1.  */
static inline int yyfill (yyGLRStackItem *, int *, int, yybool)
     YY_ATTRIBUTE_UNUSED;
static inline int
yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
{
  if (!yynormal && yylow1 < *yylow)
    {
      yyfillin (yyvsp, *yylow, yylow1);
      *yylow = yylow1;
    }
  return yylow1;
}

/** Perform user action for rule number YYN, with RHS length YYRHSLEN,
 *  and top stack item YYVSP.  YYLVALP points to place to put semantic
 *  value ($$), and yylocp points to place for location information
 *  (@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
 *  yyerr for YYERROR, yyabort for YYABORT.  */
static YYRESULTTAG
yyuserAction (yyRuleNum yyn, size_t yyrhslen, yyGLRStackItem* yyvsp,
              yyGLRStack* yystackp,
              YYSTYPE* yyvalp)
{
  yybool yynormal YY_ATTRIBUTE_UNUSED = (yystackp->yysplitPoint == YY_NULLPTR);
  int yylow;
  YYUSE (yyvalp);
  YYUSE (yyrhslen);
# undef yyerrok
# define yyerrok (yystackp->yyerrState = 0)
# undef YYACCEPT
# define YYACCEPT return yyaccept
# undef YYABORT
# define YYABORT return yyabort
# undef YYERROR
# define YYERROR return yyerrok, yyerr
# undef YYRECOVERING
# define YYRECOVERING() (yystackp->yyerrState != 0)
# undef yyclearin
# define yyclearin (yychar = YYEMPTY)
# undef YYFILL
# define YYFILL(N) yyfill (yyvsp, &yylow, N, yynormal)
# undef YYBACKUP
# define YYBACKUP(Token, Value)                                              \
  return yyerror (YY_("syntax error: cannot back up")),     \
         yyerrok, yyerr

  yylow = 1;
  if (yyrhslen == 0)
    *yyvalp = yyval_default;
  else
    *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yysval;
  switch (yyn)
    {
        case 2:
#line 58 "expr.y" /* glr.c:816  */
    {(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t)->ValidateSemantic();}
#line 1273 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 3:
#line 61 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.statement_t); ((BlockStatement*)((*yyvalp).statement_t))->addStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t));}
#line 1279 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 4:
#line 62 "expr.y" /* glr.c:816  */
    { ((*yyvalp).statement_t) = new BlockStatement(); ((BlockStatement*)((*yyvalp).statement_t))->addStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t));}
#line 1285 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 5:
#line 64 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.statement_t); ((BlockStatement*)((*yyvalp).statement_t))->addStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t));}
#line 1291 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 6:
#line 65 "expr.y" /* glr.c:816  */
    { ((*yyvalp).statement_t) = new BlockStatement(); ((BlockStatement*)((*yyvalp).statement_t))->addStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t));}
#line 1297 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 7:
#line 68 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.statement_t); ((BlockStatement*)((*yyvalp).statement_t))->addStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t));}
#line 1303 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 8:
#line 69 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t);}
#line 1309 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 9:
#line 72 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t);}
#line 1315 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 10:
#line 73 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t);}
#line 1321 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 11:
#line 74 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t);}
#line 1327 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 12:
#line 75 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t);}
#line 1333 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 13:
#line 76 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t);}
#line 1339 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 14:
#line 77 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t);}
#line 1345 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 15:
#line 78 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t);}
#line 1351 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 16:
#line 79 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t);}
#line 1357 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 17:
#line 80 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) =(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t);}
#line 1363 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 18:
#line 81 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t);}
#line 1369 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 19:
#line 82 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t);}
#line 1375 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 20:
#line 86 "expr.y" /* glr.c:816  */
    {
			((*yyvalp).statement_t) = new PreIncrementoStatement(new VarNombreArrayExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.expr_t)));}
#line 1382 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 21:
#line 88 "expr.y" /* glr.c:816  */
    {
			((*yyvalp).statement_t) = new PreDecrementoStatement(new VarNombreArrayExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.expr_t)));}
#line 1389 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 22:
#line 90 "expr.y" /* glr.c:816  */
    {
			((*yyvalp).statement_t) = new PosDecrementoStatement(new VarNombreArrayExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t)));}
#line 1396 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 23:
#line 92 "expr.y" /* glr.c:816  */
    {
			((*yyvalp).statement_t) = new PosIncrementoStatement(new VarNombreArrayExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t)));}
#line 1403 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 24:
#line 94 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new PosDecrementoStatement(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.string_t)));}
#line 1409 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 25:
#line 95 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new PosIncrementoStatement(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.string_t)));}
#line 1415 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 26:
#line 96 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new PreDecrementoStatement(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.string_t)));}
#line 1421 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 27:
#line 97 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new PreIncrementoStatement(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.string_t)));}
#line 1427 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 28:
#line 101 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new CallFuncionStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.exprlist_t));}
#line 1433 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 29:
#line 103 "expr.y" /* glr.c:816  */
    {((*yyvalp).exprlist_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.exprlist_t);}
#line 1439 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 30:
#line 104 "expr.y" /* glr.c:816  */
    {((*yyvalp).exprlist_t) = NULL;}
#line 1445 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 31:
#line 106 "expr.y" /* glr.c:816  */
    {
			((*yyvalp).statement_t) = new DecArrayStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t));}
#line 1452 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 32:
#line 108 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new DecApuntadorStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t));}
#line 1458 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 33:
#line 109 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new DecVariableStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t));}
#line 1464 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 34:
#line 113 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t);}
#line 1470 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 35:
#line 114 "expr.y" /* glr.c:816  */
    { ((*yyvalp).statement_t) = NULL;}
#line 1476 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 36:
#line 116 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.statement_t); ((BlockStatement*)((*yyvalp).statement_t))->addStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t));}
#line 1482 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 37:
#line 117 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new BlockStatement(); ((BlockStatement*)((*yyvalp).statement_t))->addStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t));}
#line 1488 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 38:
#line 120 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new DecArrayStatement(NULL,(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t),NULL);}
#line 1494 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 39:
#line 121 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new DecApuntadorStatement(NULL,(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t),NULL);}
#line 1500 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 40:
#line 122 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new DecVariableStatement(NULL,(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t),NULL);}
#line 1506 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 41:
#line 125 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new Funcion_Statement((((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t));}
#line 1512 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 42:
#line 126 "expr.y" /* glr.c:816  */
    {if((((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval.string_t) == "int")
		  ((*yyvalp).statement_t) = new Funcion_Statement("int*",(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t));else ((*yyvalp).statement_t) = new Funcion_Statement("char*",(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t));}
#line 1519 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 43:
#line 131 "expr.y" /* glr.c:816  */
    {
			((*yyvalp).statement_t) = new Producer_Statement((((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t));}
#line 1526 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 44:
#line 135 "expr.y" /* glr.c:816  */
    { ((*yyvalp).expr_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t);}
#line 1532 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 45:
#line 136 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = NULL;}
#line 1538 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 46:
#line 138 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t); ((Parametros*)((*yyvalp).expr_t))->addParametro((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.parametro_t));}
#line 1544 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 47:
#line 139 "expr.y" /* glr.c:816  */
    { ((*yyvalp).expr_t) = new Parametros();((Parametros*)((*yyvalp).expr_t))->addParametro((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.parametro_t));}
#line 1550 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 48:
#line 142 "expr.y" /* glr.c:816  */
    { ((*yyvalp).parametro_t) = new Parametro((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.string_t),new DecVariableStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.string_t),NULL,NULL));}
#line 1556 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 49:
#line 143 "expr.y" /* glr.c:816  */
    { const char * tipo = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.string_t) == "int"? "int*":"char*"; 
	   ((*yyvalp).parametro_t) = new Parametro(tipo, new DecApuntadorStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.string_t),NULL,NULL)); }
#line 1563 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 50:
#line 145 "expr.y" /* glr.c:816  */
    { const char * tipo = (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.string_t) == "int"? "int[]":"char[]";
           ((*yyvalp).parametro_t) = new Parametro(tipo,new DecArrayStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.expr_t),NULL,NULL)); }
#line 1570 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 51:
#line 148 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t);}
#line 1576 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 52:
#line 149 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new NumberExpr(0);}
#line 1582 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 53:
#line 152 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t);}
#line 1588 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 54:
#line 153 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = NULL;}
#line 1594 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 55:
#line 155 "expr.y" /* glr.c:816  */
    { ((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.statement_t);}
#line 1600 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 56:
#line 158 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.statement_t); ((BlockStatement*)((*yyvalp).statement_t))->addStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t));}
#line 1606 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 57:
#line 159 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t);}
#line 1612 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 58:
#line 162 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.statement_t); ((BlockStatement*)((*yyvalp).statement_t))->addStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t));}
#line 1618 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 59:
#line 163 "expr.y" /* glr.c:816  */
    { ((*yyvalp).statement_t) = new BlockStatement(); ((BlockStatement*)((*yyvalp).statement_t))->addStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t));}
#line 1624 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 60:
#line 166 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t);}
#line 1630 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 61:
#line 167 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t);}
#line 1636 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 62:
#line 168 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t);}
#line 1642 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 63:
#line 169 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t);}
#line 1648 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 64:
#line 170 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t);}
#line 1654 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 65:
#line 171 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t);}
#line 1660 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 66:
#line 172 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t);}
#line 1666 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 67:
#line 173 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t);}
#line 1672 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 68:
#line 174 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t);}
#line 1678 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 69:
#line 179 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new Return_Statement((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t));}
#line 1684 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 70:
#line 182 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t);}
#line 1690 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 71:
#line 183 "expr.y" /* glr.c:816  */
    { ((*yyvalp).expr_t) = new StringExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.string_t));}
#line 1696 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 72:
#line 184 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new ArrayExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.exprlist_t));}
#line 1702 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 73:
#line 185 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = NULL;}
#line 1708 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 74:
#line 188 "expr.y" /* glr.c:816  */
    { ((*yyvalp).string_t) = "int"; }
#line 1714 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 75:
#line 189 "expr.y" /* glr.c:816  */
    {  ((*yyvalp).string_t) =  "char"; }
#line 1720 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 76:
#line 191 "expr.y" /* glr.c:816  */
    { ((*yyvalp).statement_t) = new For_Statement((((yyGLRStackItem const *)yyvsp)[YYFILL (-12)].yystate.yysemantics.yysval.statement_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t));}
#line 1726 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 77:
#line 193 "expr.y" /* glr.c:816  */
    { ((*yyvalp).statement_t)  = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t); }
#line 1732 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 78:
#line 194 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = NULL;}
#line 1738 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 79:
#line 197 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new If_Statement((((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.statement_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t));}
#line 1744 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 80:
#line 198 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new If_Statement((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t),NULL);}
#line 1750 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 81:
#line 202 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new While_Statement((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t));}
#line 1756 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 82:
#line 205 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new DoWhile_Statement((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.statement_t));}
#line 1762 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 83:
#line 208 "expr.y" /* glr.c:816  */
    { ((*yyvalp).statement_t) = new BlockStatement(); ((BlockStatement*)((*yyvalp).statement_t))->addStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t));}
#line 1768 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 84:
#line 209 "expr.y" /* glr.c:816  */
    { ((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.statement_t);}
#line 1774 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 85:
#line 214 "expr.y" /* glr.c:816  */
    { ((*yyvalp).statement_t) = new PrintStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.exprlist_t));}
#line 1780 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 86:
#line 215 "expr.y" /* glr.c:816  */
    { ((*yyvalp).statement_t) = new PrintStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.string_t),NULL);}
#line 1786 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 87:
#line 219 "expr.y" /* glr.c:816  */
    { ((*yyvalp).statement_t) = new ScanfStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.exprlist_t));}
#line 1792 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 88:
#line 220 "expr.y" /* glr.c:816  */
    { ((*yyvalp).statement_t) = new ScanfStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.string_t),NULL);}
#line 1798 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 89:
#line 224 "expr.y" /* glr.c:816  */
    { ((*yyvalp).exprlist_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.exprlist_t);((*yyvalp).exprlist_t)->push_back((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t)); }
#line 1804 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 90:
#line 225 "expr.y" /* glr.c:816  */
    { ((*yyvalp).exprlist_t) = new ExprList; ((*yyvalp).exprlist_t)->push_back((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t)); }
#line 1810 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 91:
#line 230 "expr.y" /* glr.c:816  */
    { ((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t); ((AssignStatement*)((*yyvalp).statement_t))->nombre = new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.string_t));
		 ((AssignStatement*)((*yyvalp).statement_t))->expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t);}
#line 1817 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 92:
#line 232 "expr.y" /* glr.c:816  */
    { 
                 ((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t);((AssignStatement*)((*yyvalp).statement_t))->nombre = new VarNombreArrayExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.expr_t)); ((AssignStatement*)((*yyvalp).statement_t))->expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t); }
#line 1824 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 93:
#line 234 "expr.y" /* glr.c:816  */
    { 
	    	 ((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t); ((AssignStatement*)((*yyvalp).statement_t))->nombre = new ReferenciaExpr(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.string_t))); ((AssignStatement*)((*yyvalp).statement_t))->expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t); }
#line 1831 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 94:
#line 236 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new BlockStatement(); 
		((AssignStatement*)(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t))->nombre = new DesferenciaExpr(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.string_t))); ((AssignStatement*)(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t))->expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t);
		((BlockStatement*)((*yyvalp).statement_t))->addStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.statement_t)); if((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.statement_t) !=NULL){ ((PreIncrementoStatement*)(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.statement_t))->expr1 = new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.string_t)); 
		((BlockStatement*)((*yyvalp).statement_t))->addStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t));} }
#line 1840 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 95:
#line 242 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new PosIncrementoStatement(NULL); }
#line 1846 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 96:
#line 243 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new PosDecrementoStatement(NULL);}
#line 1852 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 97:
#line 244 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = NULL;}
#line 1858 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 98:
#line 248 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new AsignarStatement(NULL,NULL);}
#line 1864 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 99:
#line 249 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new MasIgualStatement(NULL,NULL); }
#line 1870 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 100:
#line 250 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new MenosIgualStatement(NULL,NULL);}
#line 1876 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 101:
#line 251 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new MultIgualStatement(NULL,NULL);}
#line 1882 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 102:
#line 252 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new DivIgualStatement(NULL,NULL);}
#line 1888 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 103:
#line 253 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new ModIgualStatement(NULL,NULL);}
#line 1894 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 104:
#line 254 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new OrBitIgualStatement(NULL,NULL);}
#line 1900 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 105:
#line 255 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new AndBitIgualStatement(NULL,NULL);}
#line 1906 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 106:
#line 256 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new XorBitIgualStatement(NULL,NULL);}
#line 1912 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 107:
#line 257 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new AsigCorIzqIgualStatement(NULL,NULL);}
#line 1918 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 108:
#line 258 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new AsigCorDerIgualStatement(NULL,NULL);}
#line 1924 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 113:
#line 268 "expr.y" /* glr.c:816  */
    { ((*yyvalp).expr_t) = new TernarioExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t)); }
#line 1930 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 114:
#line 269 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t);}
#line 1936 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 115:
#line 273 "expr.y" /* glr.c:816  */
    { ((*yyvalp).expr_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.expr_t); ((AssignExpr*)((*yyvalp).expr_t))->nombre = new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.string_t)); ((AssignExpr*)((*yyvalp).expr_t))->expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t); }
#line 1942 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 116:
#line 274 "expr.y" /* glr.c:816  */
    { 
            ((*yyvalp).expr_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.expr_t);((AssignExpr*)((*yyvalp).expr_t))->nombre = new VarNombreArrayExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.expr_t)); ((AssignExpr*)((*yyvalp).expr_t))->expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t); }
#line 1949 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 117:
#line 276 "expr.y" /* glr.c:816  */
    { 
	    ((*yyvalp).expr_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.expr_t); ((AssignExpr*)((*yyvalp).expr_t))->nombre = new ReferenciaExpr(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.string_t))); ((AssignExpr*)((*yyvalp).expr_t))->expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.expr_t); }
#line 1956 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 118:
#line 278 "expr.y" /* glr.c:816  */
    { 
	    ((*yyvalp).expr_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.expr_t); ((AssignExpr*)((*yyvalp).expr_t))->nombre = new DesferenciaExpr(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.string_t))); ((AssignExpr*)((*yyvalp).expr_t))->expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.expr_t); }
#line 1963 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 119:
#line 281 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new AsignarExpr(NULL,NULL);}
#line 1969 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 120:
#line 282 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new MasIgualExpr(NULL,NULL); }
#line 1975 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 121:
#line 283 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new MenosIgualExpr(NULL,NULL);}
#line 1981 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 122:
#line 284 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new MultIgualExpr(NULL,NULL);}
#line 1987 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 123:
#line 285 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new DivIgualExpr(NULL,NULL);}
#line 1993 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 124:
#line 286 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new ModIgualExpr(NULL,NULL);}
#line 1999 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 125:
#line 287 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new OrBitIgualExpr(NULL,NULL);}
#line 2005 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 126:
#line 288 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new AndBitIgualExpr(NULL,NULL);}
#line 2011 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 127:
#line 289 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new XorBitIgualExpr(NULL,NULL);}
#line 2017 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 128:
#line 290 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new AsigCorIzqIgualExpr(NULL,NULL);}
#line 2023 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 129:
#line 291 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new AsigCorDerIgualExpr(NULL,NULL);}
#line 2029 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 130:
#line 294 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t);}
#line 2035 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 131:
#line 295 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t);}
#line 2041 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 132:
#line 298 "expr.y" /* glr.c:816  */
    { ((*yyvalp).expr_t) = new AndExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t)); }
#line 2047 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 133:
#line 299 "expr.y" /* glr.c:816  */
    { ((*yyvalp).expr_t) = new OrExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t)); }
#line 2053 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 134:
#line 300 "expr.y" /* glr.c:816  */
    { ((*yyvalp).expr_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t);}
#line 2059 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 135:
#line 302 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new OPorBitExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t));}
#line 2065 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 136:
#line 303 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new ExclPorBitExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t));}
#line 2071 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 137:
#line 304 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new YPorBitExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t));}
#line 2077 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 138:
#line 305 "expr.y" /* glr.c:816  */
    { ((*yyvalp).expr_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t);}
#line 2083 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 139:
#line 307 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new IgualExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t));}
#line 2089 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 140:
#line 308 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new DistintoExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t));}
#line 2095 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 141:
#line 309 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new MenorExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t));}
#line 2101 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 142:
#line 310 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new MayorExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t));}
#line 2107 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 143:
#line 311 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new MenorIgualExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t));}
#line 2113 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 144:
#line 312 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new MayorIgualExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t));}
#line 2119 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 145:
#line 313 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t);}
#line 2125 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 146:
#line 315 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new CorrimientoIzqExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t));}
#line 2131 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 147:
#line 316 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new CorrimientoDerExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t));}
#line 2137 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 148:
#line 317 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t);}
#line 2143 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 149:
#line 319 "expr.y" /* glr.c:816  */
    { ((*yyvalp).expr_t) = new AddExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t));}
#line 2149 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 150:
#line 320 "expr.y" /* glr.c:816  */
    { ((*yyvalp).expr_t) = new SubExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t));}
#line 2155 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 151:
#line 321 "expr.y" /* glr.c:816  */
    { ((*yyvalp).expr_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t);}
#line 2161 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 152:
#line 324 "expr.y" /* glr.c:816  */
    { ((*yyvalp).expr_t) = new MultExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t));}
#line 2167 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 153:
#line 325 "expr.y" /* glr.c:816  */
    { ((*yyvalp).expr_t) = new DivExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t));}
#line 2173 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 154:
#line 326 "expr.y" /* glr.c:816  */
    { ((*yyvalp).expr_t) = new ModExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t));}
#line 2179 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 155:
#line 327 "expr.y" /* glr.c:816  */
    { ((*yyvalp).expr_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t);}
#line 2185 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 156:
#line 330 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new NegacionExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t));}
#line 2191 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 157:
#line 331 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new ComplementoExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t));}
#line 2197 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 158:
#line 332 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new DesferenciaExpr(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.string_t)));}
#line 2203 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 159:
#line 333 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new DesferenciaExpr(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.string_t)));}
#line 2209 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 160:
#line 334 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new ReferenciaExpr(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.string_t)));}
#line 2215 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 161:
#line 335 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new ReferenciaExpr(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.string_t)));}
#line 2221 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 162:
#line 336 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new PreIncrementoExpr(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.string_t)));}
#line 2227 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 163:
#line 337 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new PreIncrementoExpr(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.string_t)));}
#line 2233 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 164:
#line 338 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new PreDecrementoExpr(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.string_t)));}
#line 2239 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 165:
#line 339 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new PreDecrementoExpr(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.string_t)));}
#line 2245 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 166:
#line 340 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new PosIncrementoExpr(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.string_t)));}
#line 2251 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 167:
#line 341 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new PosIncrementoExpr(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.string_t)));}
#line 2257 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 168:
#line 342 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new PosDecrementoExpr(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.string_t)));}
#line 2263 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 169:
#line 343 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new PosDecrementoExpr(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.string_t)));}
#line 2269 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 170:
#line 344 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t);}
#line 2275 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 171:
#line 348 "expr.y" /* glr.c:816  */
    {  ((*yyvalp).expr_t) = new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.string_t));}
#line 2281 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 172:
#line 349 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new FuncionExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.exprlist_t));}
#line 2287 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 173:
#line 350 "expr.y" /* glr.c:816  */
    { ((*yyvalp).expr_t) = new NumberExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.int_t));}
#line 2293 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 174:
#line 351 "expr.y" /* glr.c:816  */
    { ((*yyvalp).expr_t) = new CharExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.char_t));}
#line 2299 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 175:
#line 352 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t)  = new VarNombreArrayExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.expr_t));}
#line 2305 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 176:
#line 353 "expr.y" /* glr.c:816  */
    { ((*yyvalp).expr_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.expr_t);}
#line 2311 "expr_parser.cpp" /* glr.c:816  */
    break;


#line 2315 "expr_parser.cpp" /* glr.c:816  */
      default: break;
    }

  return yyok;
# undef yyerrok
# undef YYABORT
# undef YYACCEPT
# undef YYERROR
# undef YYBACKUP
# undef yyclearin
# undef YYRECOVERING
}


static void
yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
{
  YYUSE (yy0);
  YYUSE (yy1);

  switch (yyn)
    {

      default: break;
    }
}

                              /* Bison grammar-table manipulation.  */

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

/** Number of symbols composing the right hand side of rule #RULE.  */
static inline int
yyrhsLength (yyRuleNum yyrule)
{
  return yyr2[yyrule];
}

static void
yydestroyGLRState (char const *yymsg, yyGLRState *yys)
{
  if (yys->yyresolved)
    yydestruct (yymsg, yystos[yys->yylrState],
                &yys->yysemantics.yysval);
  else
    {
#if YYDEBUG
      if (yydebug)
        {
          if (yys->yysemantics.yyfirstVal)
            YYFPRINTF (stderr, "%s unresolved", yymsg);
          else
            YYFPRINTF (stderr, "%s incomplete", yymsg);
          YY_SYMBOL_PRINT ("", yystos[yys->yylrState], YY_NULLPTR, &yys->yyloc);
        }
#endif

      if (yys->yysemantics.yyfirstVal)
        {
          yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
          yyGLRState *yyrh;
          int yyn;
          for (yyrh = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
               yyn > 0;
               yyrh = yyrh->yypred, yyn -= 1)
            yydestroyGLRState (yymsg, yyrh);
        }
    }
}

/** Left-hand-side symbol for rule #YYRULE.  */
static inline yySymbol
yylhsNonterm (yyRuleNum yyrule)
{
  return yyr1[yyrule];
}

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-304)))

/** True iff LR state YYSTATE has only a default reduction (regardless
 *  of token).  */
static inline yybool
yyisDefaultedState (yyStateNum yystate)
{
  return yypact_value_is_default (yypact[yystate]);
}

/** The default reduction for YYSTATE, assuming it has one.  */
static inline yyRuleNum
yydefaultAction (yyStateNum yystate)
{
  return yydefact[yystate];
}

#define yytable_value_is_error(Yytable_value) \
  0

/** Set *YYACTION to the action to take in YYSTATE on seeing YYTOKEN.
 *  Result R means
 *    R < 0:  Reduce on rule -R.
 *    R = 0:  Error.
 *    R > 0:  Shift to state R.
 *  Set *YYCONFLICTS to a pointer into yyconfl to a 0-terminated list
 *  of conflicting reductions.
 */
static inline void
yygetLRActions (yyStateNum yystate, int yytoken,
                int* yyaction, const short int** yyconflicts)
{
  int yyindex = yypact[yystate] + yytoken;
  if (yypact_value_is_default (yypact[yystate])
      || yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
    {
      *yyaction = -yydefact[yystate];
      *yyconflicts = yyconfl;
    }
  else if (! yytable_value_is_error (yytable[yyindex]))
    {
      *yyaction = yytable[yyindex];
      *yyconflicts = yyconfl + yyconflp[yyindex];
    }
  else
    {
      *yyaction = 0;
      *yyconflicts = yyconfl + yyconflp[yyindex];
    }
}

/** Compute post-reduction state.
 * \param yystate   the current state
 * \param yysym     the nonterminal to push on the stack
 */
static inline yyStateNum
yyLRgotoState (yyStateNum yystate, yySymbol yysym)
{
  int yyr = yypgoto[yysym - YYNTOKENS] + yystate;
  if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
    return yytable[yyr];
  else
    return yydefgoto[yysym - YYNTOKENS];
}

static inline yybool
yyisShiftAction (int yyaction)
{
  return 0 < yyaction;
}

static inline yybool
yyisErrorAction (int yyaction)
{
  return yyaction == 0;
}

                                /* GLRStates */

/** Return a fresh GLRStackItem in YYSTACKP.  The item is an LR state
 *  if YYISSTATE, and otherwise a semantic option.  Callers should call
 *  YY_RESERVE_GLRSTACK afterwards to make sure there is sufficient
 *  headroom.  */

static inline yyGLRStackItem*
yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
{
  yyGLRStackItem* yynewItem = yystackp->yynextFree;
  yystackp->yyspaceLeft -= 1;
  yystackp->yynextFree += 1;
  yynewItem->yystate.yyisState = yyisState;
  return yynewItem;
}

/** Add a new semantic action that will execute the action for rule
 *  YYRULE on the semantic values in YYRHS to the list of
 *  alternative actions for YYSTATE.  Assumes that YYRHS comes from
 *  stack #YYK of *YYSTACKP. */
static void
yyaddDeferredAction (yyGLRStack* yystackp, size_t yyk, yyGLRState* yystate,
                     yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yySemanticOption* yynewOption =
    &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
  YYASSERT (!yynewOption->yyisState);
  yynewOption->yystate = yyrhs;
  yynewOption->yyrule = yyrule;
  if (yystackp->yytops.yylookaheadNeeds[yyk])
    {
      yynewOption->yyrawchar = yychar;
      yynewOption->yyval = yylval;
    }
  else
    yynewOption->yyrawchar = YYEMPTY;
  yynewOption->yynext = yystate->yysemantics.yyfirstVal;
  yystate->yysemantics.yyfirstVal = yynewOption;

  YY_RESERVE_GLRSTACK (yystackp);
}

                                /* GLRStacks */

/** Initialize YYSET to a singleton set containing an empty stack.  */
static yybool
yyinitStateSet (yyGLRStateSet* yyset)
{
  yyset->yysize = 1;
  yyset->yycapacity = 16;
  yyset->yystates = (yyGLRState**) YYMALLOC (16 * sizeof yyset->yystates[0]);
  if (! yyset->yystates)
    return yyfalse;
  yyset->yystates[0] = YY_NULLPTR;
  yyset->yylookaheadNeeds =
    (yybool*) YYMALLOC (16 * sizeof yyset->yylookaheadNeeds[0]);
  if (! yyset->yylookaheadNeeds)
    {
      YYFREE (yyset->yystates);
      return yyfalse;
    }
  return yytrue;
}

static void yyfreeStateSet (yyGLRStateSet* yyset)
{
  YYFREE (yyset->yystates);
  YYFREE (yyset->yylookaheadNeeds);
}

/** Initialize *YYSTACKP to a single empty stack, with total maximum
 *  capacity for all stacks of YYSIZE.  */
static yybool
yyinitGLRStack (yyGLRStack* yystackp, size_t yysize)
{
  yystackp->yyerrState = 0;
  yynerrs = 0;
  yystackp->yyspaceLeft = yysize;
  yystackp->yyitems =
    (yyGLRStackItem*) YYMALLOC (yysize * sizeof yystackp->yynextFree[0]);
  if (!yystackp->yyitems)
    return yyfalse;
  yystackp->yynextFree = yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;
  return yyinitStateSet (&yystackp->yytops);
}


#if YYSTACKEXPANDABLE
# define YYRELOC(YYFROMITEMS,YYTOITEMS,YYX,YYTYPE) \
  &((YYTOITEMS) - ((YYFROMITEMS) - (yyGLRStackItem*) (YYX)))->YYTYPE

/** If *YYSTACKP is expandable, extend it.  WARNING: Pointers into the
    stack from outside should be considered invalid after this call.
    We always expand when there are 1 or fewer items left AFTER an
    allocation, so that we can avoid having external pointers exist
    across an allocation.  */
static void
yyexpandGLRStack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yynewItems;
  yyGLRStackItem* yyp0, *yyp1;
  size_t yynewSize;
  size_t yyn;
  size_t yysize = yystackp->yynextFree - yystackp->yyitems;
  if (YYMAXDEPTH - YYHEADROOM < yysize)
    yyMemoryExhausted (yystackp);
  yynewSize = 2*yysize;
  if (YYMAXDEPTH < yynewSize)
    yynewSize = YYMAXDEPTH;
  yynewItems = (yyGLRStackItem*) YYMALLOC (yynewSize * sizeof yynewItems[0]);
  if (! yynewItems)
    yyMemoryExhausted (yystackp);
  for (yyp0 = yystackp->yyitems, yyp1 = yynewItems, yyn = yysize;
       0 < yyn;
       yyn -= 1, yyp0 += 1, yyp1 += 1)
    {
      *yyp1 = *yyp0;
      if (*(yybool *) yyp0)
        {
          yyGLRState* yys0 = &yyp0->yystate;
          yyGLRState* yys1 = &yyp1->yystate;
          if (yys0->yypred != YY_NULLPTR)
            yys1->yypred =
              YYRELOC (yyp0, yyp1, yys0->yypred, yystate);
          if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != YY_NULLPTR)
            yys1->yysemantics.yyfirstVal =
              YYRELOC (yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
        }
      else
        {
          yySemanticOption* yyv0 = &yyp0->yyoption;
          yySemanticOption* yyv1 = &yyp1->yyoption;
          if (yyv0->yystate != YY_NULLPTR)
            yyv1->yystate = YYRELOC (yyp0, yyp1, yyv0->yystate, yystate);
          if (yyv0->yynext != YY_NULLPTR)
            yyv1->yynext = YYRELOC (yyp0, yyp1, yyv0->yynext, yyoption);
        }
    }
  if (yystackp->yysplitPoint != YY_NULLPTR)
    yystackp->yysplitPoint = YYRELOC (yystackp->yyitems, yynewItems,
                                      yystackp->yysplitPoint, yystate);

  for (yyn = 0; yyn < yystackp->yytops.yysize; yyn += 1)
    if (yystackp->yytops.yystates[yyn] != YY_NULLPTR)
      yystackp->yytops.yystates[yyn] =
        YYRELOC (yystackp->yyitems, yynewItems,
                 yystackp->yytops.yystates[yyn], yystate);
  YYFREE (yystackp->yyitems);
  yystackp->yyitems = yynewItems;
  yystackp->yynextFree = yynewItems + yysize;
  yystackp->yyspaceLeft = yynewSize - yysize;
}
#endif

static void
yyfreeGLRStack (yyGLRStack* yystackp)
{
  YYFREE (yystackp->yyitems);
  yyfreeStateSet (&yystackp->yytops);
}

/** Assuming that YYS is a GLRState somewhere on *YYSTACKP, update the
 *  splitpoint of *YYSTACKP, if needed, so that it is at least as deep as
 *  YYS.  */
static inline void
yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
{
  if (yystackp->yysplitPoint != YY_NULLPTR && yystackp->yysplitPoint > yys)
    yystackp->yysplitPoint = yys;
}

/** Invalidate stack #YYK in *YYSTACKP.  */
static inline void
yymarkStackDeleted (yyGLRStack* yystackp, size_t yyk)
{
  if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    yystackp->yylastDeleted = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yystates[yyk] = YY_NULLPTR;
}

/** Undelete the last stack in *YYSTACKP that was marked as deleted.  Can
    only be done once after a deletion, and only when all other stacks have
    been deleted.  */
static void
yyundeleteLastStack (yyGLRStack* yystackp)
{
  if (yystackp->yylastDeleted == YY_NULLPTR || yystackp->yytops.yysize != 0)
    return;
  yystackp->yytops.yystates[0] = yystackp->yylastDeleted;
  yystackp->yytops.yysize = 1;
  YYDPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
  yystackp->yylastDeleted = YY_NULLPTR;
}

static inline void
yyremoveDeletes (yyGLRStack* yystackp)
{
  size_t yyi, yyj;
  yyi = yyj = 0;
  while (yyj < yystackp->yytops.yysize)
    {
      if (yystackp->yytops.yystates[yyi] == YY_NULLPTR)
        {
          if (yyi == yyj)
            {
              YYDPRINTF ((stderr, "Removing dead stacks.\n"));
            }
          yystackp->yytops.yysize -= 1;
        }
      else
        {
          yystackp->yytops.yystates[yyj] = yystackp->yytops.yystates[yyi];
          /* In the current implementation, it's unnecessary to copy
             yystackp->yytops.yylookaheadNeeds[yyi] since, after
             yyremoveDeletes returns, the parser immediately either enters
             deterministic operation or shifts a token.  However, it doesn't
             hurt, and the code might evolve to need it.  */
          yystackp->yytops.yylookaheadNeeds[yyj] =
            yystackp->yytops.yylookaheadNeeds[yyi];
          if (yyj != yyi)
            {
              YYDPRINTF ((stderr, "Rename stack %lu -> %lu.\n",
                          (unsigned long int) yyi, (unsigned long int) yyj));
            }
          yyj += 1;
        }
      yyi += 1;
    }
}

/** Shift to a new state on stack #YYK of *YYSTACKP, corresponding to LR
 * state YYLRSTATE, at input position YYPOSN, with (resolved) semantic
 * value *YYVALP and source location *YYLOCP.  */
static inline void
yyglrShift (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
            size_t yyposn,
            YYSTYPE* yyvalp)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yytrue;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yysval = *yyvalp;
  yystackp->yytops.yystates[yyk] = yynewState;

  YY_RESERVE_GLRSTACK (yystackp);
}

/** Shift stack #YYK of *YYSTACKP, to a new state corresponding to LR
 *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
 *  semantic value of YYRHS under the action for YYRULE.  */
static inline void
yyglrShiftDefer (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
                 size_t yyposn, yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;
  YYASSERT (yynewState->yyisState);

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yyfalse;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyfirstVal = YY_NULLPTR;
  yystackp->yytops.yystates[yyk] = yynewState;

  /* Invokes YY_RESERVE_GLRSTACK.  */
  yyaddDeferredAction (yystackp, yyk, yynewState, yyrhs, yyrule);
}

#if !YYDEBUG
# define YY_REDUCE_PRINT(Args)
#else
# define YY_REDUCE_PRINT(Args)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print Args;               \
} while (0)

/*----------------------------------------------------------------------.
| Report that stack #YYK of *YYSTACKP is going to be reduced by YYRULE. |
`----------------------------------------------------------------------*/

static inline void
yy_reduce_print (int yynormal, yyGLRStackItem* yyvsp, size_t yyk,
                 yyRuleNum yyrule)
{
  int yynrhs = yyrhsLength (yyrule);
  int yyi;
  YYFPRINTF (stderr, "Reducing stack %lu by rule %d (line %lu):\n",
             (unsigned long int) yyk, yyrule - 1,
             (unsigned long int) yyrline[yyrule]);
  if (! yynormal)
    yyfillin (yyvsp, 1, -yynrhs);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyvsp[yyi - yynrhs + 1].yystate.yylrState],
                       &yyvsp[yyi - yynrhs + 1].yystate.yysemantics.yysval
                                              );
      if (!yyvsp[yyi - yynrhs + 1].yystate.yyresolved)
        YYFPRINTF (stderr, " (unresolved)");
      YYFPRINTF (stderr, "\n");
    }
}
#endif

/** Pop the symbols consumed by reduction #YYRULE from the top of stack
 *  #YYK of *YYSTACKP, and perform the appropriate semantic action on their
 *  semantic values.  Assumes that all ambiguities in semantic values
 *  have been previously resolved.  Set *YYVALP to the resulting value,
 *  and *YYLOCP to the computed location (if any).  Return value is as
 *  for userAction.  */
static inline YYRESULTTAG
yydoAction (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
            YYSTYPE* yyvalp)
{
  int yynrhs = yyrhsLength (yyrule);

  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      /* Standard special case: single stack.  */
      yyGLRStackItem* yyrhs = (yyGLRStackItem*) yystackp->yytops.yystates[yyk];
      YYASSERT (yyk == 0);
      yystackp->yynextFree -= yynrhs;
      yystackp->yyspaceLeft += yynrhs;
      yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
      YY_REDUCE_PRINT ((1, yyrhs, yyk, yyrule));
      return yyuserAction (yyrule, yynrhs, yyrhs, yystackp,
                           yyvalp);
    }
  else
    {
      int yyi;
      yyGLRState* yys;
      yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
      yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
        = yystackp->yytops.yystates[yyk];
      for (yyi = 0; yyi < yynrhs; yyi += 1)
        {
          yys = yys->yypred;
          YYASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yystackp->yytops.yystates[yyk] = yys;
      YY_REDUCE_PRINT ((0, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1, yyk, yyrule));
      return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyvalp);
    }
}

/** Pop items off stack #YYK of *YYSTACKP according to grammar rule YYRULE,
 *  and push back on the resulting nonterminal symbol.  Perform the
 *  semantic action associated with YYRULE and store its value with the
 *  newly pushed state, if YYFORCEEVAL or if *YYSTACKP is currently
 *  unambiguous.  Otherwise, store the deferred semantic action with
 *  the new state.  If the new state would have an identical input
 *  position, LR state, and predecessor to an existing state on the stack,
 *  it is identified with that existing state, eliminating stack #YYK from
 *  *YYSTACKP.  In this case, the semantic value is
 *  added to the options for the existing state's semantic value.
 */
static inline YYRESULTTAG
yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
             yybool yyforceEval)
{
  size_t yyposn = yystackp->yytops.yystates[yyk]->yyposn;

  if (yyforceEval || yystackp->yysplitPoint == YY_NULLPTR)
    {
      YYSTYPE yysval;

      YYRESULTTAG yyflag = yydoAction (yystackp, yyk, yyrule, &yysval);
      if (yyflag == yyerr && yystackp->yysplitPoint != YY_NULLPTR)
        {
          YYDPRINTF ((stderr, "Parse on stack %lu rejected by rule #%d.\n",
                     (unsigned long int) yyk, yyrule - 1));
        }
      if (yyflag != yyok)
        return yyflag;
      YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyrule], &yysval, &yyloc);
      yyglrShift (yystackp, yyk,
                  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
                                 yylhsNonterm (yyrule)),
                  yyposn, &yysval);
    }
  else
    {
      size_t yyi;
      int yyn;
      yyGLRState* yys, *yys0 = yystackp->yytops.yystates[yyk];
      yyStateNum yynewLRState;

      for (yys = yystackp->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
           0 < yyn; yyn -= 1)
        {
          yys = yys->yypred;
          YYASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
      YYDPRINTF ((stderr,
                  "Reduced stack %lu by rule #%d; action deferred.  "
                  "Now in state %d.\n",
                  (unsigned long int) yyk, yyrule - 1, yynewLRState));
      for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
        if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULLPTR)
          {
            yyGLRState *yysplit = yystackp->yysplitPoint;
            yyGLRState *yyp = yystackp->yytops.yystates[yyi];
            while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn)
              {
                if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
                  {
                    yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
                    yymarkStackDeleted (yystackp, yyk);
                    YYDPRINTF ((stderr, "Merging stack %lu into stack %lu.\n",
                                (unsigned long int) yyk,
                                (unsigned long int) yyi));
                    return yyok;
                  }
                yyp = yyp->yypred;
              }
          }
      yystackp->yytops.yystates[yyk] = yys;
      yyglrShiftDefer (yystackp, yyk, yynewLRState, yyposn, yys0, yyrule);
    }
  return yyok;
}

static size_t
yysplitStack (yyGLRStack* yystackp, size_t yyk)
{
  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      YYASSERT (yyk == 0);
      yystackp->yysplitPoint = yystackp->yytops.yystates[yyk];
    }
  if (yystackp->yytops.yysize >= yystackp->yytops.yycapacity)
    {
      yyGLRState** yynewStates;
      yybool* yynewLookaheadNeeds;

      yynewStates = YY_NULLPTR;

      if (yystackp->yytops.yycapacity
          > (YYSIZEMAX / (2 * sizeof yynewStates[0])))
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yycapacity *= 2;

      yynewStates =
        (yyGLRState**) YYREALLOC (yystackp->yytops.yystates,
                                  (yystackp->yytops.yycapacity
                                   * sizeof yynewStates[0]));
      if (yynewStates == YY_NULLPTR)
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yystates = yynewStates;

      yynewLookaheadNeeds =
        (yybool*) YYREALLOC (yystackp->yytops.yylookaheadNeeds,
                             (yystackp->yytops.yycapacity
                              * sizeof yynewLookaheadNeeds[0]));
      if (yynewLookaheadNeeds == YY_NULLPTR)
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
    }
  yystackp->yytops.yystates[yystackp->yytops.yysize]
    = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yylookaheadNeeds[yystackp->yytops.yysize]
    = yystackp->yytops.yylookaheadNeeds[yyk];
  yystackp->yytops.yysize += 1;
  return yystackp->yytops.yysize-1;
}

/** True iff YYY0 and YYY1 represent identical options at the top level.
 *  That is, they represent the same rule applied to RHS symbols
 *  that produce the same terminal symbols.  */
static yybool
yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  if (yyy0->yyrule == yyy1->yyrule)
    {
      yyGLRState *yys0, *yys1;
      int yyn;
      for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
           yyn = yyrhsLength (yyy0->yyrule);
           yyn > 0;
           yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
        if (yys0->yyposn != yys1->yyposn)
          return yyfalse;
      return yytrue;
    }
  else
    return yyfalse;
}

/** Assuming identicalOptions (YYY0,YYY1), destructively merge the
 *  alternative semantic values for the RHS-symbols of YYY1 and YYY0.  */
static void
yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  yyGLRState *yys0, *yys1;
  int yyn;
  for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
       yyn = yyrhsLength (yyy0->yyrule);
       yyn > 0;
       yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
    {
      if (yys0 == yys1)
        break;
      else if (yys0->yyresolved)
        {
          yys1->yyresolved = yytrue;
          yys1->yysemantics.yysval = yys0->yysemantics.yysval;
        }
      else if (yys1->yyresolved)
        {
          yys0->yyresolved = yytrue;
          yys0->yysemantics.yysval = yys1->yysemantics.yysval;
        }
      else
        {
          yySemanticOption** yyz0p = &yys0->yysemantics.yyfirstVal;
          yySemanticOption* yyz1 = yys1->yysemantics.yyfirstVal;
          while (yytrue)
            {
              if (yyz1 == *yyz0p || yyz1 == YY_NULLPTR)
                break;
              else if (*yyz0p == YY_NULLPTR)
                {
                  *yyz0p = yyz1;
                  break;
                }
              else if (*yyz0p < yyz1)
                {
                  yySemanticOption* yyz = *yyz0p;
                  *yyz0p = yyz1;
                  yyz1 = yyz1->yynext;
                  (*yyz0p)->yynext = yyz;
                }
              yyz0p = &(*yyz0p)->yynext;
            }
          yys1->yysemantics.yyfirstVal = yys0->yysemantics.yyfirstVal;
        }
    }
}

/** Y0 and Y1 represent two possible actions to take in a given
 *  parsing state; return 0 if no combination is possible,
 *  1 if user-mergeable, 2 if Y0 is preferred, 3 if Y1 is preferred.  */
static int
yypreference (yySemanticOption* y0, yySemanticOption* y1)
{
  yyRuleNum r0 = y0->yyrule, r1 = y1->yyrule;
  int p0 = yydprec[r0], p1 = yydprec[r1];

  if (p0 == p1)
    {
      if (yymerger[r0] == 0 || yymerger[r0] != yymerger[r1])
        return 0;
      else
        return 1;
    }
  if (p0 == 0 || p1 == 0)
    return 0;
  if (p0 < p1)
    return 3;
  if (p1 < p0)
    return 2;
  return 0;
}

static YYRESULTTAG yyresolveValue (yyGLRState* yys,
                                   yyGLRStack* yystackp);


/** Resolve the previous YYN states starting at and including state YYS
 *  on *YYSTACKP. If result != yyok, some states may have been left
 *  unresolved possibly with empty semantic option chains.  Regardless
 *  of whether result = yyok, each state has been left with consistent
 *  data so that yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveStates (yyGLRState* yys, int yyn,
                 yyGLRStack* yystackp)
{
  if (0 < yyn)
    {
      YYASSERT (yys->yypred);
      YYCHK (yyresolveStates (yys->yypred, yyn-1, yystackp));
      if (! yys->yyresolved)
        YYCHK (yyresolveValue (yys, yystackp));
    }
  return yyok;
}

/** Resolve the states for the RHS of YYOPT on *YYSTACKP, perform its
 *  user action, and return the semantic value and location in *YYVALP
 *  and *YYLOCP.  Regardless of whether result = yyok, all RHS states
 *  have been destroyed (assuming the user action destroys all RHS
 *  semantic values if invoked).  */
static YYRESULTTAG
yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
                 YYSTYPE* yyvalp)
{
  yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
  int yynrhs = yyrhsLength (yyopt->yyrule);
  YYRESULTTAG yyflag =
    yyresolveStates (yyopt->yystate, yynrhs, yystackp);
  if (yyflag != yyok)
    {
      yyGLRState *yys;
      for (yys = yyopt->yystate; yynrhs > 0; yys = yys->yypred, yynrhs -= 1)
        yydestroyGLRState ("Cleanup: popping", yys);
      return yyflag;
    }

  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;
  {
    int yychar_current = yychar;
    YYSTYPE yylval_current = yylval;
    yychar = yyopt->yyrawchar;
    yylval = yyopt->yyval;
    yyflag = yyuserAction (yyopt->yyrule, yynrhs,
                           yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyvalp);
    yychar = yychar_current;
    yylval = yylval_current;
  }
  return yyflag;
}

#if YYDEBUG
static void
yyreportTree (yySemanticOption* yyx, int yyindent)
{
  int yynrhs = yyrhsLength (yyx->yyrule);
  int yyi;
  yyGLRState* yys;
  yyGLRState* yystates[1 + YYMAXRHS];
  yyGLRState yyleftmost_state;

  for (yyi = yynrhs, yys = yyx->yystate; 0 < yyi; yyi -= 1, yys = yys->yypred)
    yystates[yyi] = yys;
  if (yys == YY_NULLPTR)
    {
      yyleftmost_state.yyposn = 0;
      yystates[0] = &yyleftmost_state;
    }
  else
    yystates[0] = yys;

  if (yyx->yystate->yyposn < yys->yyposn + 1)
    YYFPRINTF (stderr, "%*s%s -> <Rule %d, empty>\n",
               yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
               yyx->yyrule - 1);
  else
    YYFPRINTF (stderr, "%*s%s -> <Rule %d, tokens %lu .. %lu>\n",
               yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
               yyx->yyrule - 1, (unsigned long int) (yys->yyposn + 1),
               (unsigned long int) yyx->yystate->yyposn);
  for (yyi = 1; yyi <= yynrhs; yyi += 1)
    {
      if (yystates[yyi]->yyresolved)
        {
          if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
            YYFPRINTF (stderr, "%*s%s <empty>\n", yyindent+2, "",
                       yytokenName (yystos[yystates[yyi]->yylrState]));
          else
            YYFPRINTF (stderr, "%*s%s <tokens %lu .. %lu>\n", yyindent+2, "",
                       yytokenName (yystos[yystates[yyi]->yylrState]),
                       (unsigned long int) (yystates[yyi-1]->yyposn + 1),
                       (unsigned long int) yystates[yyi]->yyposn);
        }
      else
        yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
    }
}
#endif

static YYRESULTTAG
yyreportAmbiguity (yySemanticOption* yyx0,
                   yySemanticOption* yyx1)
{
  YYUSE (yyx0);
  YYUSE (yyx1);

#if YYDEBUG
  YYFPRINTF (stderr, "Ambiguity detected.\n");
  YYFPRINTF (stderr, "Option 1,\n");
  yyreportTree (yyx0, 2);
  YYFPRINTF (stderr, "\nOption 2,\n");
  yyreportTree (yyx1, 2);
  YYFPRINTF (stderr, "\n");
#endif

  yyerror (YY_("syntax is ambiguous"));
  return yyabort;
}

/** Resolve the ambiguity represented in state YYS in *YYSTACKP,
 *  perform the indicated actions, and set the semantic value of YYS.
 *  If result != yyok, the chain of semantic options in YYS has been
 *  cleared instead or it has been left unmodified except that
 *  redundant options may have been removed.  Regardless of whether
 *  result = yyok, YYS has been left with consistent data so that
 *  yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp)
{
  yySemanticOption* yyoptionList = yys->yysemantics.yyfirstVal;
  yySemanticOption* yybest = yyoptionList;
  yySemanticOption** yypp;
  yybool yymerge = yyfalse;
  YYSTYPE yysval;
  YYRESULTTAG yyflag;

  for (yypp = &yyoptionList->yynext; *yypp != YY_NULLPTR; )
    {
      yySemanticOption* yyp = *yypp;

      if (yyidenticalOptions (yybest, yyp))
        {
          yymergeOptionSets (yybest, yyp);
          *yypp = yyp->yynext;
        }
      else
        {
          switch (yypreference (yybest, yyp))
            {
            case 0:
              return yyreportAmbiguity (yybest, yyp);
              break;
            case 1:
              yymerge = yytrue;
              break;
            case 2:
              break;
            case 3:
              yybest = yyp;
              yymerge = yyfalse;
              break;
            default:
              /* This cannot happen so it is not worth a YYASSERT (yyfalse),
                 but some compilers complain if the default case is
                 omitted.  */
              break;
            }
          yypp = &yyp->yynext;
        }
    }

  if (yymerge)
    {
      yySemanticOption* yyp;
      int yyprec = yydprec[yybest->yyrule];
      yyflag = yyresolveAction (yybest, yystackp, &yysval);
      if (yyflag == yyok)
        for (yyp = yybest->yynext; yyp != YY_NULLPTR; yyp = yyp->yynext)
          {
            if (yyprec == yydprec[yyp->yyrule])
              {
                YYSTYPE yysval_other;
                yyflag = yyresolveAction (yyp, yystackp, &yysval_other);
                if (yyflag != yyok)
                  {
                    yydestruct ("Cleanup: discarding incompletely merged value for",
                                yystos[yys->yylrState],
                                &yysval);
                    break;
                  }
                yyuserMerge (yymerger[yyp->yyrule], &yysval, &yysval_other);
              }
          }
    }
  else
    yyflag = yyresolveAction (yybest, yystackp, &yysval);

  if (yyflag == yyok)
    {
      yys->yyresolved = yytrue;
      yys->yysemantics.yysval = yysval;
    }
  else
    yys->yysemantics.yyfirstVal = YY_NULLPTR;
  return yyflag;
}

static YYRESULTTAG
yyresolveStack (yyGLRStack* yystackp)
{
  if (yystackp->yysplitPoint != YY_NULLPTR)
    {
      yyGLRState* yys;
      int yyn;

      for (yyn = 0, yys = yystackp->yytops.yystates[0];
           yys != yystackp->yysplitPoint;
           yys = yys->yypred, yyn += 1)
        continue;
      YYCHK (yyresolveStates (yystackp->yytops.yystates[0], yyn, yystackp
                             ));
    }
  return yyok;
}

static void
yycompressStack (yyGLRStack* yystackp)
{
  yyGLRState* yyp, *yyq, *yyr;

  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == YY_NULLPTR)
    return;

  for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = YY_NULLPTR;
       yyp != yystackp->yysplitPoint;
       yyr = yyp, yyp = yyq, yyq = yyp->yypred)
    yyp->yypred = yyr;

  yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
  yystackp->yynextFree = ((yyGLRStackItem*) yystackp->yysplitPoint) + 1;
  yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;

  while (yyr != YY_NULLPTR)
    {
      yystackp->yynextFree->yystate = *yyr;
      yyr = yyr->yypred;
      yystackp->yynextFree->yystate.yypred = &yystackp->yynextFree[-1].yystate;
      yystackp->yytops.yystates[0] = &yystackp->yynextFree->yystate;
      yystackp->yynextFree += 1;
      yystackp->yyspaceLeft -= 1;
    }
}

static YYRESULTTAG
yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
                   size_t yyposn)
{
  while (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    {
      yyStateNum yystate = yystackp->yytops.yystates[yyk]->yylrState;
      YYDPRINTF ((stderr, "Stack %lu Entering state %d\n",
                  (unsigned long int) yyk, yystate));

      YYASSERT (yystate != YYFINAL);

      if (yyisDefaultedState (yystate))
        {
          YYRESULTTAG yyflag;
          yyRuleNum yyrule = yydefaultAction (yystate);
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, "Stack %lu dies.\n",
                          (unsigned long int) yyk));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          yyflag = yyglrReduce (yystackp, yyk, yyrule, yyimmediate[yyrule]);
          if (yyflag == yyerr)
            {
              YYDPRINTF ((stderr,
                          "Stack %lu dies "
                          "(predicate failure or explicit user error).\n",
                          (unsigned long int) yyk));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          if (yyflag != yyok)
            return yyflag;
        }
      else
        {
          yySymbol yytoken;
          int yyaction;
          const short int* yyconflicts;

          yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;
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

          yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);

          while (*yyconflicts != 0)
            {
              YYRESULTTAG yyflag;
              size_t yynewStack = yysplitStack (yystackp, yyk);
              YYDPRINTF ((stderr, "Splitting off stack %lu from %lu.\n",
                          (unsigned long int) yynewStack,
                          (unsigned long int) yyk));
              yyflag = yyglrReduce (yystackp, yynewStack,
                                    *yyconflicts,
                                    yyimmediate[*yyconflicts]);
              if (yyflag == yyok)
                YYCHK (yyprocessOneStack (yystackp, yynewStack,
                                          yyposn));
              else if (yyflag == yyerr)
                {
                  YYDPRINTF ((stderr, "Stack %lu dies.\n",
                              (unsigned long int) yynewStack));
                  yymarkStackDeleted (yystackp, yynewStack);
                }
              else
                return yyflag;
              yyconflicts += 1;
            }

          if (yyisShiftAction (yyaction))
            break;
          else if (yyisErrorAction (yyaction))
            {
              YYDPRINTF ((stderr, "Stack %lu dies.\n",
                          (unsigned long int) yyk));
              yymarkStackDeleted (yystackp, yyk);
              break;
            }
          else
            {
              YYRESULTTAG yyflag = yyglrReduce (yystackp, yyk, -yyaction,
                                                yyimmediate[-yyaction]);
              if (yyflag == yyerr)
                {
                  YYDPRINTF ((stderr,
                              "Stack %lu dies "
                              "(predicate failure or explicit user error).\n",
                              (unsigned long int) yyk));
                  yymarkStackDeleted (yystackp, yyk);
                  break;
                }
              else if (yyflag != yyok)
                return yyflag;
            }
        }
    }
  return yyok;
}

static void
yyreportSyntaxError (yyGLRStack* yystackp)
{
  if (yystackp->yyerrState != 0)
    return;
#if ! YYERROR_VERBOSE
  yyerror (YY_("syntax error"));
#else
  {
  yySymbol yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);
  size_t yysize0 = yytnamerr (YY_NULLPTR, yytokenName (yytoken));
  size_t yysize = yysize0;
  yybool yysize_overflow = yyfalse;
  char* yymsg = YY_NULLPTR;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected").  */
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
      int yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
      yyarg[yycount++] = yytokenName (yytoken);
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for this
             state because they are default actions.  */
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
                yyarg[yycount++] = yytokenName (yyx);
                {
                  size_t yysz = yysize + yytnamerr (YY_NULLPTR, yytokenName (yyx));
                  yysize_overflow |= yysz < yysize;
                  yysize = yysz;
                }
              }
        }
    }

  switch (yycount)
    {
#define YYCASE_(N, S)                   \
      case N:                           \
        yyformat = S;                   \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  {
    size_t yysz = yysize + strlen (yyformat);
    yysize_overflow |= yysz < yysize;
    yysize = yysz;
  }

  if (!yysize_overflow)
    yymsg = (char *) YYMALLOC (yysize);

  if (yymsg)
    {
      char *yyp = yymsg;
      int yyi = 0;
      while ((*yyp = *yyformat))
        {
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
      yyerror (yymsg);
      YYFREE (yymsg);
    }
  else
    {
      yyerror (YY_("syntax error"));
      yyMemoryExhausted (yystackp);
    }
  }
#endif /* YYERROR_VERBOSE */
  yynerrs += 1;
}

/* Recover from a syntax error on *YYSTACKP, assuming that *YYSTACKP->YYTOKENP,
   yylval, and yylloc are the syntactic category, semantic value, and location
   of the lookahead.  */
static void
yyrecoverSyntaxError (yyGLRStack* yystackp)
{
  size_t yyk;
  int yyj;

  if (yystackp->yyerrState == 3)
    /* We just shifted the error token and (perhaps) took some
       reductions.  Skip tokens until we can proceed.  */
    while (yytrue)
      {
        yySymbol yytoken;
        if (yychar == YYEOF)
          yyFail (yystackp, YY_NULLPTR);
        if (yychar != YYEMPTY)
          {
            yytoken = YYTRANSLATE (yychar);
            yydestruct ("Error: discarding",
                        yytoken, &yylval);
          }
        YYDPRINTF ((stderr, "Reading a token: "));
        yychar = yylex ();
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
        yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
        if (yypact_value_is_default (yyj))
          return;
        yyj += yytoken;
        if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != yytoken)
          {
            if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0)
              return;
          }
        else if (! yytable_value_is_error (yytable[yyj]))
          return;
      }

  /* Reduce to one stack.  */
  for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
    if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
      break;
  if (yyk >= yystackp->yytops.yysize)
    yyFail (yystackp, YY_NULLPTR);
  for (yyk += 1; yyk < yystackp->yytops.yysize; yyk += 1)
    yymarkStackDeleted (yystackp, yyk);
  yyremoveDeletes (yystackp);
  yycompressStack (yystackp);

  /* Now pop stack until we find a state that shifts the error token.  */
  yystackp->yyerrState = 3;
  while (yystackp->yytops.yystates[0] != YY_NULLPTR)
    {
      yyGLRState *yys = yystackp->yytops.yystates[0];
      yyj = yypact[yys->yylrState];
      if (! yypact_value_is_default (yyj))
        {
          yyj += YYTERROR;
          if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYTERROR
              && yyisShiftAction (yytable[yyj]))
            {
              /* Shift the error token.  */
              YY_SYMBOL_PRINT ("Shifting", yystos[yytable[yyj]],
                               &yylval, &yyerrloc);
              yyglrShift (yystackp, 0, yytable[yyj],
                          yys->yyposn, &yylval);
              yys = yystackp->yytops.yystates[0];
              break;
            }
        }
      if (yys->yypred != YY_NULLPTR)
        yydestroyGLRState ("Error: popping", yys);
      yystackp->yytops.yystates[0] = yys->yypred;
      yystackp->yynextFree -= 1;
      yystackp->yyspaceLeft += 1;
    }
  if (yystackp->yytops.yystates[0] == YY_NULLPTR)
    yyFail (yystackp, YY_NULLPTR);
}

#define YYCHK1(YYE)                                                          \
  do {                                                                       \
    switch (YYE) {                                                           \
    case yyok:                                                               \
      break;                                                                 \
    case yyabort:                                                            \
      goto yyabortlab;                                                       \
    case yyaccept:                                                           \
      goto yyacceptlab;                                                      \
    case yyerr:                                                              \
      goto yyuser_error;                                                     \
    default:                                                                 \
      goto yybuglab;                                                         \
    }                                                                        \
  } while (0)

/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
  int yyresult;
  yyGLRStack yystack;
  yyGLRStack* const yystackp = &yystack;
  size_t yyposn;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY;
  yylval = yyval_default;

  if (! yyinitGLRStack (yystackp, YYINITDEPTH))
    goto yyexhaustedlab;
  switch (YYSETJMP (yystack.yyexception_buffer))
    {
    case 0: break;
    case 1: goto yyabortlab;
    case 2: goto yyexhaustedlab;
    default: goto yybuglab;
    }
  yyglrShift (&yystack, 0, 0, 0, &yylval);
  yyposn = 0;

  while (yytrue)
    {
      /* For efficiency, we have two loops, the first of which is
         specialized to deterministic operation (single stack, no
         potential ambiguity).  */
      /* Standard mode */
      while (yytrue)
        {
          yyRuleNum yyrule;
          int yyaction;
          const short int* yyconflicts;

          yyStateNum yystate = yystack.yytops.yystates[0]->yylrState;
          YYDPRINTF ((stderr, "Entering state %d\n", yystate));
          if (yystate == YYFINAL)
            goto yyacceptlab;
          if (yyisDefaultedState (yystate))
            {
              yyrule = yydefaultAction (yystate);
              if (yyrule == 0)
                {

                  yyreportSyntaxError (&yystack);
                  goto yyuser_error;
                }
              YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue));
            }
          else
            {
              yySymbol yytoken;
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

              yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);
              if (*yyconflicts != 0)
                break;
              if (yyisShiftAction (yyaction))
                {
                  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
                  yychar = YYEMPTY;
                  yyposn += 1;
                  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval);
                  if (0 < yystack.yyerrState)
                    yystack.yyerrState -= 1;
                }
              else if (yyisErrorAction (yyaction))
                {

                  yyreportSyntaxError (&yystack);
                  goto yyuser_error;
                }
              else
                YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue));
            }
        }

      while (yytrue)
        {
          yySymbol yytoken_to_shift;
          size_t yys;

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;

          /* yyprocessOneStack returns one of three things:

              - An error flag.  If the caller is yyprocessOneStack, it
                immediately returns as well.  When the caller is finally
                yyparse, it jumps to an error label via YYCHK1.

              - yyok, but yyprocessOneStack has invoked yymarkStackDeleted
                (&yystack, yys), which sets the top state of yys to NULL.  Thus,
                yyparse's following invocation of yyremoveDeletes will remove
                the stack.

              - yyok, when ready to shift a token.

             Except in the first case, yyparse will invoke yyremoveDeletes and
             then shift the next token onto all remaining stacks.  This
             synchronization of the shift (that is, after all preceding
             reductions on all stacks) helps prevent double destructor calls
             on yylval in the event of memory exhaustion.  */

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn));
          yyremoveDeletes (&yystack);
          if (yystack.yytops.yysize == 0)
            {
              yyundeleteLastStack (&yystack);
              if (yystack.yytops.yysize == 0)
                yyFail (&yystack, YY_("syntax error"));
              YYCHK1 (yyresolveStack (&yystack));
              YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));

              yyreportSyntaxError (&yystack);
              goto yyuser_error;
            }

          /* If any yyglrShift call fails, it will fail after shifting.  Thus,
             a copy of yylval will already be on stack 0 in the event of a
             failure in the following loop.  Thus, yychar is set to YYEMPTY
             before the loop to make sure the user destructor for yylval isn't
             called twice.  */
          yytoken_to_shift = YYTRANSLATE (yychar);
          yychar = YYEMPTY;
          yyposn += 1;
          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            {
              int yyaction;
              const short int* yyconflicts;
              yyStateNum yystate = yystack.yytops.yystates[yys]->yylrState;
              yygetLRActions (yystate, yytoken_to_shift, &yyaction,
                              &yyconflicts);
              /* Note that yyconflicts were handled by yyprocessOneStack.  */
              YYDPRINTF ((stderr, "On stack %lu, ", (unsigned long int) yys));
              YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
              yyglrShift (&yystack, yys, yyaction, yyposn,
                          &yylval);
              YYDPRINTF ((stderr, "Stack %lu now in state #%d\n",
                          (unsigned long int) yys,
                          yystack.yytops.yystates[yys]->yylrState));
            }

          if (yystack.yytops.yysize == 1)
            {
              YYCHK1 (yyresolveStack (&yystack));
              YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yycompressStack (&yystack);
              break;
            }
        }
      continue;
    yyuser_error:
      yyrecoverSyntaxError (&yystack);
      yyposn = yystack.yytops.yystates[0]->yyposn;
    }

 yyacceptlab:
  yyresult = 0;
  goto yyreturn;

 yybuglab:
  YYASSERT (yyfalse);
  goto yyabortlab;

 yyabortlab:
  yyresult = 1;
  goto yyreturn;

 yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;

 yyreturn:
  if (yychar != YYEMPTY)
    yydestruct ("Cleanup: discarding lookahead",
                YYTRANSLATE (yychar), &yylval);

  /* If the stack is well-formed, pop the stack until it is empty,
     destroying its entries as we go.  But free the stack regardless
     of whether it is well-formed.  */
  if (yystack.yyitems)
    {
      yyGLRState** yystates = yystack.yytops.yystates;
      if (yystates)
        {
          size_t yysize = yystack.yytops.yysize;
          size_t yyk;
          for (yyk = 0; yyk < yysize; yyk += 1)
            if (yystates[yyk])
              {
                while (yystates[yyk])
                  {
                    yyGLRState *yys = yystates[yyk];
                  if (yys->yypred != YY_NULLPTR)
                      yydestroyGLRState ("Cleanup: popping", yys);
                    yystates[yyk] = yys->yypred;
                    yystack.yynextFree -= 1;
                    yystack.yyspaceLeft += 1;
                  }
                break;
              }
        }
      yyfreeGLRStack (&yystack);
    }

  return yyresult;
}

/* DEBUGGING ONLY */
#if YYDEBUG
static void
yy_yypstack (yyGLRState* yys)
{
  if (yys->yypred)
    {
      yy_yypstack (yys->yypred);
      YYFPRINTF (stderr, " -> ");
    }
  YYFPRINTF (stderr, "%d@%lu", yys->yylrState,
             (unsigned long int) yys->yyposn);
}

static void
yypstates (yyGLRState* yyst)
{
  if (yyst == YY_NULLPTR)
    YYFPRINTF (stderr, "<null>");
  else
    yy_yypstack (yyst);
  YYFPRINTF (stderr, "\n");
}

static void
yypstack (yyGLRStack* yystackp, size_t yyk)
{
  yypstates (yystackp->yytops.yystates[yyk]);
}

#define YYINDEX(YYX)                                                         \
    ((YYX) == YY_NULLPTR ? -1 : (yyGLRStackItem*) (YYX) - yystackp->yyitems)


static void
yypdumpstack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yyp;
  size_t yyi;
  for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1)
    {
      YYFPRINTF (stderr, "%3lu. ",
                 (unsigned long int) (yyp - yystackp->yyitems));
      if (*(yybool *) yyp)
        {
          YYASSERT (yyp->yystate.yyisState);
          YYASSERT (yyp->yyoption.yyisState);
          YYFPRINTF (stderr, "Res: %d, LR State: %d, posn: %lu, pred: %ld",
                     yyp->yystate.yyresolved, yyp->yystate.yylrState,
                     (unsigned long int) yyp->yystate.yyposn,
                     (long int) YYINDEX (yyp->yystate.yypred));
          if (! yyp->yystate.yyresolved)
            YYFPRINTF (stderr, ", firstVal: %ld",
                       (long int) YYINDEX (yyp->yystate
                                             .yysemantics.yyfirstVal));
        }
      else
        {
          YYASSERT (!yyp->yystate.yyisState);
          YYASSERT (!yyp->yyoption.yyisState);
          YYFPRINTF (stderr, "Option. rule: %d, state: %ld, next: %ld",
                     yyp->yyoption.yyrule - 1,
                     (long int) YYINDEX (yyp->yyoption.yystate),
                     (long int) YYINDEX (yyp->yyoption.yynext));
        }
      YYFPRINTF (stderr, "\n");
    }
  YYFPRINTF (stderr, "Tops:");
  for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
    YYFPRINTF (stderr, "%lu: %ld; ", (unsigned long int) yyi,
               (long int) YYINDEX (yystackp->yytops.yystates[yyi]));
  YYFPRINTF (stderr, "\n");
}
#endif

#undef yylval
#undef yychar
#undef yynerrs



