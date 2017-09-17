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
#include "ash.h"

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
Statement *input = NULL;

#line 76 "expr_parser.cpp" /* glr.c:240  */

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

#line 104 "expr_parser.cpp" /* glr.c:263  */

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
#define YYLAST   779

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  184
/* YYNRULES -- Number of states.  */
#define YYNSTATES  382
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 16
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYTRANSLATE(X) -- Bison symbol number corresponding to X.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   322

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
      65,    66,    67
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,    60,    60,    63,    64,    66,    67,    71,    72,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      91,    93,    95,    97,    99,   100,   101,   102,   106,   108,
     109,   111,   113,   114,   115,   118,   119,   121,   122,   125,
     126,   127,   130,   131,   136,   140,   141,   143,   144,   147,
     148,   150,   153,   154,   157,   158,   160,   161,   165,   166,
     169,   170,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   188,   189,   192,   193,   194,   195,   198,
     199,   201,   203,   204,   207,   208,   212,   215,   218,   219,
     224,   225,   231,   232,   237,   239,   241,   243,   249,   250,
     251,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   268,   269,   271,   272,   275,   276,   280,   281,
     283,   285,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   301,   302,   305,   306,   307,   309,   310,
     311,   312,   314,   315,   316,   317,   318,   319,   320,   322,
     323,   324,   326,   327,   328,   331,   332,   333,   334,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   353,   355,   357,   360,   364,   365,
     366,   367,   368,   369,   370
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
  "TK_Srand", "TK_left_llave", "TK_rigth_llave", "TK_VarNombre",
  "TK_While", "TK_left_corchete", "TK_rigth_corchete", "TK_Refenciacion",
  "TK_PuntoComma", "TK_Rand", "TK_Char", "TK_Int", "TK_Void", "TK_For",
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
  "arg_list", "assign_statement", "incrementopt", "opAssignStatement",
  "eols", "opt_eols", "ternario", "assignExpr", "opAssign", "expr",
  "andOr", "exprForBit", "conditional", "corrimiento", "add", "term",
  "unary", "factor", YY_NULLPTR
};
#endif

#define YYPACT_NINF -301
#define YYTABLE_NINF -60

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const short int yypact[] =
{
    -301,    30,   451,  -301,     4,  -301,    47,   103,     6,   484,
     117,    38,  -301,  -301,   176,   178,   185,   198,  -301,   172,
    -301,  -301,  -301,   169,   196,   204,  -301,  -301,    83,  -301,
    -301,  -301,   208,   228,   233,   168,   240,   600,  -301,   600,
    -301,   600,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,   600,   600,   651,   180,  -301,   181,
     205,   202,   451,   451,   273,  -301,  -301,  -301,   257,   158,
    -301,  -301,  -301,  -301,  -301,   651,    14,     9,   621,  -301,
     507,    42,  -301,  -301,    43,   146,   600,   600,  -301,  -301,
     286,   177,    63,    25,   156,   218,    26,  -301,  -301,   292,
     274,  -301,   280,  -301,   316,   600,   188,   104,   600,   600,
     293,  -301,   600,   295,   297,  -301,  -301,   301,  -301,  -301,
    -301,   302,  -301,   310,   311,  -301,    98,   182,   312,   183,
     188,   558,   600,   305,   600,  -301,   600,   309,   714,   461,
     342,   600,  -301,   600,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,   600,   322,   714,   323,
     326,   329,   328,  -301,  -301,   351,   642,   642,   642,   642,
     642,   642,   642,   642,   642,   642,   642,   600,   642,   642,
     642,   642,   642,   642,   642,  -301,   600,   200,  -301,  -301,
     358,   321,  -301,   139,   673,  -301,  -301,   335,   336,  -301,
     110,  -301,  -301,  -301,  -301,  -301,   164,  -301,  -301,   344,
     369,  -301,   188,   305,   367,   600,  -301,  -301,   346,   140,
    -301,  -301,    34,   373,   600,   219,  -301,   376,   355,  -301,
     380,   600,   382,   600,   383,   600,  -301,   356,   157,    10,
     163,    73,   238,    97,   379,   409,   443,   224,   231,   243,
     245,   249,   251,   331,   269,   307,    50,    60,  -301,  -301,
    -301,  -301,  -301,  -301,   600,   202,  -301,   188,   375,   374,
     600,   108,  -301,  -301,  -301,  -301,   165,  -301,   149,   399,
     402,   404,  -301,  -301,   113,   397,   385,    22,   372,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,   661,  -301,  -301,  -301,
     386,  -301,   389,  -301,   410,  -301,   600,  -301,   600,  -301,
    -301,    74,  -301,  -301,   600,   401,  -301,   110,   170,   387,
     405,   153,   600,  -301,    74,  -301,   305,   397,   600,  -301,
     140,  -301,  -301,   600,  -301,  -301,   411,   408,  -301,  -301,
    -301,  -301,  -301,   412,  -301,   651,   571,   171,  -301,  -301,
     397,   429,    74,  -301,  -301,  -301,   415,  -301,  -301,   432,
     256,   304,  -301,  -301,  -301,  -301,   397,   419,  -301,  -301,
     123,  -301,  -301,   174,  -301,  -301,   571,  -301,   306,  -301,
     202,  -301
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const unsigned char yydefact[] =
{
     115,     0,    34,     1,     0,   114,     0,     0,     0,     0,
       0,     0,    80,    79,     0,     0,     0,     0,   115,   115,
     115,   115,     4,     0,     0,     0,    16,    13,     0,    14,
       9,    10,     0,     0,     0,   100,     0,     0,    19,    30,
     101,     0,   102,   103,   104,   105,   107,   110,   111,    25,
      24,   108,   109,   106,     0,     0,     0,     0,   115,    27,
      26,     0,     0,    34,     2,    18,    17,     6,     0,    78,
      15,    11,    12,    98,    99,     0,     0,     0,     0,   180,
     178,     0,   184,   181,     0,     0,     0,     0,   134,   133,
       0,   117,   137,   141,   148,   151,   154,   158,   177,     0,
      29,    93,     0,    94,     0,     0,    46,    83,     0,     0,
       0,   115,    74,     0,     0,    66,    88,     0,    67,    62,
      63,     0,   115,     0,     0,     3,     0,   115,     0,    78,
      46,     0,     0,    36,     0,    91,     0,     0,   161,   178,
       0,    30,   122,     0,   123,   124,   125,   126,   128,   131,
     132,   169,   171,   129,   130,   127,     0,     0,   163,     0,
     165,     0,   167,   159,   160,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    28,     0,     0,   115,    96,
       0,    45,    48,     0,     0,   115,    82,     0,     0,    71,
      34,    73,    70,    69,    72,    68,     0,    64,    65,     0,
       0,     5,    46,    36,     0,     0,    76,    75,     0,     0,
      33,    97,     0,     0,     0,     0,   183,     0,     0,   118,
       0,     0,     0,     0,     0,     0,   113,     0,     0,   178,
       0,   135,   141,   136,   140,   139,   138,   142,   143,   144,
     145,   146,   147,     0,   149,   150,   152,   153,   155,   156,
     157,    92,    23,    22,     0,     0,   115,     0,     0,    49,
       0,     0,    20,    21,   115,   115,   115,    61,     0,     0,
       0,     0,    32,   115,     0,    78,     0,    78,    35,    38,
      90,   162,   121,   170,   172,   179,   182,   164,   120,   166,
       0,   168,     0,   112,    85,   161,     0,   163,     0,    95,
      86,     0,    47,    50,    53,     0,   115,    34,     0,     0,
       0,    78,     0,   115,     0,    77,    36,    78,     0,    41,
       0,   176,   175,     0,   173,   174,     0,     0,   116,   115,
      55,    44,    54,     0,    52,     0,     0,   115,    89,    60,
      78,     0,     0,    42,    31,    40,     0,    37,   119,     0,
     182,    34,    51,   115,    87,    43,    78,     0,    57,   115,
       0,    39,    84,     0,   115,    56,     0,   115,     0,   115,
       0,    81
};

  /* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -301,  -301,   388,   440,  -301,   393,    11,    13,   318,   -62,
    -206,  -301,   120,  -301,    17,  -119,  -301,   206,  -301,  -300,
    -301,   111,   159,  -194,  -301,  -127,     1,    24,  -301,    27,
      32,    35,  -229,    37,  -124,     7,  -301,   -52,  -301,     0,
    -301,  -301,  -133,   -27,  -301,   155,   122,   368,   147,   173,
      33,  -301
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const short int yydefgoto[] =
{
      -1,     1,    19,   274,    21,    22,   113,   114,    99,    25,
     220,   288,   289,    26,   115,   190,   191,   192,   343,   341,
     342,   275,   276,   116,   117,   133,   193,   118,   195,   119,
     120,   121,   122,   123,   100,   124,    75,    54,   237,    62,
      88,    89,   156,   101,    91,    92,    93,    94,    95,    96,
      97,    98
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const short int yytable[] =
{
       2,   128,   213,    28,   105,   224,   277,   282,   304,    34,
      90,   214,   222,    23,   102,    24,   137,   141,    61,    27,
      63,    64,   135,   134,   353,   231,    29,   103,   104,    30,
       3,   182,   183,    35,    31,   131,   310,    32,   138,    33,
      38,   306,   290,   171,   172,   173,   174,   175,   176,   157,
     159,   140,   365,   328,    36,   182,   183,   136,   107,   163,
     164,   151,   152,   126,    28,   182,   183,    56,   184,    34,
      34,   158,   160,    23,    23,    24,    24,   186,   189,    27,
      27,   197,   198,     5,   177,   201,    29,    29,    68,    30,
      30,   284,   184,   281,    31,    31,   168,    32,    32,    33,
      33,   339,   184,   209,   217,   218,   168,   221,   340,     4,
      37,   200,    69,     5,   196,     4,   228,     5,   169,     5,
     354,   170,   206,   277,    55,   349,     6,   210,   169,   229,
     168,   170,     5,   194,     7,   264,   110,    11,   372,     9,
      10,   325,   316,    11,   268,   286,    12,    13,    14,    15,
     253,   381,   169,   161,   320,   170,   186,   374,   326,   261,
     329,    16,    17,   333,   137,   130,   131,   277,   269,   287,
     157,   131,    -8,     5,   -59,   162,    18,   112,   321,     5,
     -58,    -8,    -7,     5,   132,    58,   305,   106,   265,   132,
     212,    -7,   307,   -59,   279,   271,   131,   292,   348,   -58,
     355,   278,   375,    65,   298,    57,   300,     4,   302,   178,
     179,     5,   108,    40,    59,   258,   259,   260,     6,    73,
      74,   180,   181,   213,    12,    13,     7,    60,   110,   111,
      66,     9,    10,   166,   167,    11,   109,   309,    67,   371,
      14,    15,    70,   315,    42,    43,    44,    45,    46,    47,
      48,   262,   263,    16,    17,   128,   171,   172,   173,   174,
     175,   176,    71,    51,    52,    53,   311,    72,    18,   112,
     293,   294,   180,   181,   317,   318,   319,   178,   179,   337,
      76,   338,     5,   324,   178,   179,   129,   344,   242,   242,
     244,   245,   246,   264,   165,   351,   178,   179,   178,   179,
     185,   356,   178,   179,   178,   179,   358,   331,   332,     4,
     180,   181,   187,     5,   379,     5,   346,   186,   278,   363,
       6,   241,   243,   352,   188,   254,   255,   199,     7,   202,
     110,   203,   368,     9,    10,   204,   205,    11,   223,   361,
      12,    13,    14,    15,   207,   208,   211,   319,   219,   377,
     226,   230,   232,   256,   257,    16,    17,   233,   234,   235,
     236,     4,   278,   370,   267,   303,   266,   272,   273,   373,
      18,   112,     6,   280,   376,   283,   130,   378,   285,   380,
       7,   291,   110,   111,   295,     9,    10,   296,   297,    11,
     299,   301,     4,   308,    14,    15,     5,   171,   172,   173,
     174,   175,   176,     6,   313,   314,   322,    16,    17,   212,
     131,     7,   323,   110,   327,   330,     9,    10,   334,   336,
      11,   335,    18,   112,     4,    14,    15,   171,   172,   173,
     174,   175,   176,   345,   350,     6,   359,   364,    16,    17,
     360,   367,    20,     7,   362,   110,   111,   366,     9,    10,
     357,   127,    11,    18,   112,   125,     4,    14,    15,   227,
       5,   171,   172,   173,   174,   175,   176,     6,   141,   225,
      16,    17,   369,   312,   142,     7,   347,     8,     0,     0,
       9,    10,     0,     0,    11,    18,   112,    12,    13,    14,
      15,    39,   143,     0,     0,     0,     0,    40,     0,     0,
       0,     0,    16,    17,     0,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   141,    41,     0,    18,     0,     0,
     142,     0,     0,     0,   153,   154,   155,     0,    42,    43,
      44,    45,    46,    47,    48,    49,    50,     0,   143,   247,
     248,   249,   250,   251,   252,     0,     0,    51,    52,    53,
       0,   144,   145,   146,   147,   148,   149,   150,   151,   152,
       0,     0,     0,    77,     0,    78,     0,     0,     0,     0,
     153,   154,   155,    79,     0,     0,    77,     0,    78,     0,
       5,     0,     0,     0,     0,   215,    79,    80,     0,     0,
       0,    81,     0,    82,     0,     0,     0,     0,   216,    83,
      80,     0,     0,     0,    81,    77,    82,    78,     0,    84,
      85,     0,    83,     0,     0,    79,     0,     0,    86,    87,
       0,     0,    84,    85,     0,     0,    77,     0,    78,    80,
       0,    86,    87,    81,     0,    82,    79,     0,     0,     0,
       0,    83,     0,     0,     0,     0,     0,   238,     0,    78,
     139,    84,    85,     0,    81,     0,    82,    79,     0,     0,
      86,    87,    83,     0,    40,     0,     0,     0,     0,     0,
       0,   239,    84,    85,   142,   240,     0,    82,     0,     0,
       0,    86,    87,    83,     0,     0,    40,     0,     0,     0,
       0,     0,     0,    84,    85,    42,    43,    44,    45,    46,
      47,    48,    86,    87,   270,   144,   145,   146,   147,   148,
     149,   150,   331,   332,    51,    52,    53,    42,    43,    44,
      45,    46,    47,    48,   153,   154,   155,   142,     0,     0,
       0,     0,     0,     0,     0,     0,    51,    52,    53,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   144,   145,
     146,   147,   148,   149,   150,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   153,   154,   155
};

static const short int yycheck[] =
{
       0,    63,   129,     2,    56,   138,   200,   213,   237,     2,
      37,   130,   136,     2,    41,     2,     7,     7,    18,     2,
      20,    21,     8,    75,   324,   158,     2,    54,    55,     2,
       0,     5,     6,    29,     2,    13,   265,     2,    29,     2,
      34,    31,     8,    18,    19,    20,    21,    22,    23,     7,
       7,    78,   352,    31,     7,     5,     6,    43,    58,    86,
      87,    51,    52,    62,    63,     5,     6,    29,    42,    62,
      63,    29,    29,    62,    63,    62,    63,    43,   105,    62,
      63,   108,   109,     9,    59,   112,    62,    63,     5,    62,
      63,   215,    42,   212,    62,    63,    33,    62,    63,    62,
      63,    27,    42,     5,   131,   132,    33,   134,    34,     5,
       7,   111,    29,     9,   107,     5,   143,     9,    55,     9,
     326,    58,   122,   317,     7,   319,    16,    29,    55,   156,
      33,    58,     9,    29,    24,   187,    26,    33,   367,    29,
      30,    28,    34,    33,     5,     5,    36,    37,    38,    39,
     177,   380,    55,     7,     5,    58,    43,    34,   285,   186,
     287,    51,    52,   296,     7,     7,    13,   361,    29,    29,
       7,    13,     0,     9,     9,    29,    66,    67,    29,     9,
       9,     9,     0,     9,    31,     7,    29,     7,   188,    31,
       7,     9,    29,    28,    30,   195,    13,   224,    28,    28,
     327,   200,    28,    34,   231,    29,   233,     5,   235,    53,
      54,     9,    31,    13,    29,   182,   183,   184,    16,    51,
      52,     3,     4,   350,    36,    37,    24,    29,    26,    27,
      34,    29,    30,    56,    57,    33,    31,   264,    34,   366,
      38,    39,    34,   270,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    51,    52,   317,    18,    19,    20,    21,
      22,    23,    34,    63,    64,    65,   266,    34,    66,    67,
      51,    52,     3,     4,   274,   275,   276,    53,    54,   306,
      40,   308,     9,   283,    53,    54,    29,   314,   166,   167,
     168,   169,   170,   345,     8,   322,    53,    54,    53,    54,
       8,   328,    53,    54,    53,    54,   333,    51,    52,     5,
       3,     4,    32,     9,     8,     9,   316,    43,   317,   346,
      16,   166,   167,   323,     8,   178,   179,    34,    24,    34,
      26,    34,    28,    29,    30,    34,    34,    33,    29,   339,
      36,    37,    38,    39,    34,    34,    34,   347,    43,   376,
       8,    29,    29,   180,   181,    51,    52,    31,    29,    31,
       9,     5,   361,   363,    43,     9,     8,    32,    32,   369,
      66,    67,    16,    29,   374,     8,     7,   377,    32,   379,
      24,     8,    26,    27,     8,    29,    30,    32,     8,    33,
       8,     8,     5,    62,    38,    39,     9,    18,    19,    20,
      21,    22,    23,    16,    29,    31,     7,    51,    52,     7,
      13,    24,     8,    26,    29,    43,    29,    30,    32,     9,
      33,    32,    66,    67,     5,    38,    39,    18,    19,    20,
      21,    22,    23,    32,    29,    16,    25,     8,    51,    52,
      32,     9,     2,    24,    32,    26,    27,    32,    29,    30,
     330,    63,    33,    66,    67,    62,     5,    38,    39,   141,
       9,    18,    19,    20,    21,    22,    23,    16,     7,     8,
      51,    52,   361,   267,    13,    24,   317,    26,    -1,    -1,
      29,    30,    -1,    -1,    33,    66,    67,    36,    37,    38,
      39,     7,    31,    -1,    -1,    -1,    -1,    13,    -1,    -1,
      -1,    -1,    51,    52,    -1,    44,    45,    46,    47,    48,
      49,    50,    51,    52,     7,    31,    -1,    66,    -1,    -1,
      13,    -1,    -1,    -1,    63,    64,    65,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    31,   171,
     172,   173,   174,   175,   176,    -1,    -1,    63,    64,    65,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    -1,    -1,     5,    -1,     7,    -1,    -1,    -1,    -1,
      63,    64,    65,    15,    -1,    -1,     5,    -1,     7,    -1,
       9,    -1,    -1,    -1,    -1,    27,    15,    29,    -1,    -1,
      -1,    33,    -1,    35,    -1,    -1,    -1,    -1,    40,    41,
      29,    -1,    -1,    -1,    33,     5,    35,     7,    -1,    51,
      52,    -1,    41,    -1,    -1,    15,    -1,    -1,    60,    61,
      -1,    -1,    51,    52,    -1,    -1,     5,    -1,     7,    29,
      -1,    60,    61,    33,    -1,    35,    15,    -1,    -1,    -1,
      -1,    41,    -1,    -1,    -1,    -1,    -1,     5,    -1,     7,
      29,    51,    52,    -1,    33,    -1,    35,    15,    -1,    -1,
      60,    61,    41,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    51,    52,    13,    33,    -1,    35,    -1,    -1,
      -1,    60,    61,    41,    -1,    -1,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    44,    45,    46,    47,    48,
      49,    50,    60,    61,    31,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    63,    64,    65,    44,    45,    46,
      47,    48,    49,    50,    63,    64,    65,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    69,   107,     0,     5,     9,    16,    24,    26,    29,
      30,    33,    36,    37,    38,    39,    51,    52,    66,    70,
      71,    72,    73,    74,    75,    77,    81,    82,    94,    95,
      97,    98,    99,   101,   103,    29,     7,     7,    34,     7,
      13,    31,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    63,    64,    65,   105,     7,    29,    29,     7,    29,
      29,   107,   107,   107,   107,    34,    34,    34,     5,    29,
      34,    34,    34,    51,    52,   104,    40,     5,     7,    15,
      29,    33,    35,    41,    51,    52,    60,    61,   108,   109,
     111,   112,   113,   114,   115,   116,   117,   118,   119,    76,
     102,   111,   111,   111,   111,   105,     7,   107,    31,    31,
      26,    27,    67,    74,    75,    82,    91,    92,    95,    97,
      98,    99,   100,   101,   103,    73,    94,    70,    77,    29,
       7,    13,    31,    93,   105,     8,    43,     7,    29,    29,
     111,     7,    13,    31,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    63,    64,    65,   110,     7,    29,     7,
      29,     7,    29,   111,   111,     8,    56,    57,    33,    55,
      58,    18,    19,    20,    21,    22,    23,    59,    53,    54,
       3,     4,     5,     6,    42,     8,    43,    32,     8,   111,
      83,    84,    85,    94,    29,    96,   103,   111,   111,    34,
     107,   111,    34,    34,    34,    34,   107,    34,    34,     5,
      29,    34,     7,    93,    83,    27,    40,   111,   111,    43,
      78,   111,   102,    29,   110,     8,     8,    76,   111,   111,
      29,   110,    29,    31,    29,    31,     9,   106,     5,    29,
      33,   113,   114,   113,   114,   114,   114,   115,   115,   115,
     115,   115,   115,   111,   116,   116,   117,   117,   118,   118,
     118,   111,    51,    52,   105,   107,     8,    43,     5,    29,
      31,   107,    32,    32,    71,    89,    90,    91,    94,    30,
      29,    83,    78,     8,   102,    32,     5,    29,    79,    80,
       8,     8,   111,    51,    52,     8,    32,     8,   111,     8,
     111,     8,   111,     9,   100,    29,    31,    29,    62,   111,
     100,   107,    85,    29,    31,   111,    34,   107,   107,   107,
       5,    29,     7,     8,   107,    28,    93,    29,    31,    93,
      43,    51,    52,   110,    32,    32,     9,   111,   111,    27,
      34,    87,    88,    86,   111,    32,   107,    90,    28,    91,
      29,   111,   107,    87,    78,    93,   111,    80,   111,    25,
      32,   107,    32,   111,     8,    87,    32,     9,    28,    89,
     107,    93,   100,   107,    34,    28,   107,   111,   107,     8,
     107,   100
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    68,    69,    70,    70,    71,    71,    72,    72,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      74,    74,    74,    74,    74,    74,    74,    74,    75,    76,
      76,    77,    77,    77,    77,    78,    78,    79,    79,    80,
      80,    80,    81,    81,    82,    83,    83,    84,    84,    85,
      85,    85,    86,    86,    87,    87,    88,    88,    89,    89,
      90,    90,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    92,    92,    93,    93,    93,    93,    94,
      94,    95,    96,    96,    97,    97,    98,    99,   100,   100,
     101,   101,   102,   102,   103,   103,   103,   103,   104,   104,
     104,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   106,   106,   107,   107,   108,   108,   109,   109,
     109,   109,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   111,   111,   112,   112,   112,   113,   113,
     113,   113,   114,   114,   114,   114,   114,   114,   114,   115,
     115,   115,   116,   116,   116,   117,   117,   117,   117,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   119,   119,
     119,   119,   119,   119,   119
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     3,     3,     1,     4,     2,     3,     1,     1,
       1,     2,     2,     1,     1,     2,     1,     2,     2,     2,
       5,     5,     5,     5,     2,     2,     2,     2,     4,     1,
       0,     7,     5,     4,     0,     2,     0,     3,     1,     5,
       3,     2,     7,     8,     7,     1,     0,     3,     1,     2,
       3,     5,     1,     0,     1,     1,     5,     3,     3,     1,
       3,     1,     1,     1,     2,     2,     1,     1,     2,     2,
       2,     2,     2,     2,     1,     2,     2,     4,     0,     1,
       1,    16,     1,     0,    10,     6,     6,     8,     1,     5,
       6,     4,     3,     1,     3,     6,     4,     5,     1,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     2,     0,     5,     1,     3,     6,
       4,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     1,     3,     3,
       3,     1,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     2,
       2,     2,     4,     2,     4,     2,     4,     2,     4,     2,
       4,     2,     4,     5,     5,     5,     5,     1,     1,     4,
       1,     1,     4,     3,     1
};


/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
static const unsigned char yydprec[] =
{
       0,     0,     0,     2,     1,     1,     2,     2,     1,     1,
       2,     3,     5,     6,     7,     8,     9,    10,    11,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       1,     0,     0,     0,     0,     0,     0,     1,     2,     0,
       0,     0,     0,     0,     0,     2,     1,     2,     1,     0,
       0,     0,     2,     1,     2,     1,     1,     2,     2,     1,
       2,     1,     1,     2,     3,     5,     6,     7,     8,    10,
      11,    12,    13,     0,     0,     1,     3,     2,     4,     0,
       0,     0,     2,     1,     1,     2,     0,     0,     1,     2,
       2,     1,     2,     2,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     1,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     2,     3,     1,     2,     3,
       4,     1,     1,     2,     3,     4,     5,     6,     7,     1,
       2,     3,     1,     2,     3,     1,     2,     3,     4,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,     0,     0,     0,     0,    15,     0,     0,
       0,     0,     0,     0,     0
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const unsigned char yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    35,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,    15,    17,    19,    21,    23,     0,
       0,     0,     0,     0,     0,   139,   141,     0,     0,     0,
       0,     0,     0,     0,     0,   145,   147,     0,    39,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    25,     0,     0,     0,     0,     0,
       0,     0,   143,     0,     0,     0,     7,     0,     0,     0,
       0,     0,   149,     0,     0,     0,    47,     0,     0,     0,
       0,     0,     0,    41,     0,     0,     0,     0,     9,     0,
       0,    11,     0,     0,     0,     0,     0,     0,    49,     0,
      65,    51,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    67,     0,     0,    69,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   151,     0,     0,     0,     0,     0,
     155,     1,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    43,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
      29,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    31,    33,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     3,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,    55,    57,    59,
      61,    63,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   131,   133,     0,     0,     0,   107,   109,     0,
       0,     0,     0,     0,   111,   113,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   115,   117,   119,   121,
       0,     0,   123,   125,   127,   129,     0,     0,     0,     0,
     135,   137,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    71,    73,    75,
      77,    79,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   153,
       0,     0,     0,     0,     0,     0,     0,    83,    85,    87,
      89,    91,    93,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    95,    97,    99,   101,   103,   105,     0,     0,    45,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short int yyconfl[] =
{
       0,   115,     0,   117,     0,   117,     0,   137,     0,   137,
       0,   137,     0,   141,     0,   141,     0,   141,     0,   141,
       0,   141,     0,   141,     0,   141,     0,   148,     0,   148,
       0,   151,     0,   151,     0,   154,     0,   154,     0,   154,
       0,    83,     0,   115,     0,   178,     0,   135,     0,   135,
       0,   135,     0,   141,     0,   141,     0,   141,     0,   141,
       0,   141,     0,   141,     0,   136,     0,   136,     0,   136,
       0,   140,     0,   140,     0,   140,     0,   140,     0,   140,
       0,   140,     0,   139,     0,   139,     0,   139,     0,   139,
       0,   139,     0,   139,     0,   138,     0,   138,     0,   138,
       0,   138,     0,   138,     0,   138,     0,   142,     0,   142,
       0,   143,     0,   143,     0,   144,     0,   144,     0,   145,
       0,   145,     0,   146,     0,   146,     0,   147,     0,   147,
       0,   149,     0,   149,     0,   150,     0,   150,     0,   152,
       0,   152,     0,   152,     0,   153,     0,   153,     0,   153,
       0,   115,     0,    85,     0,   115,     0
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
#line 60 "expr.y" /* glr.c:816  */
    { input = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t);}
#line 1302 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 3:
#line 63 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.statement_t); ((BlockStatement*)((*yyvalp).statement_t))->addStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t));}
#line 1308 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 4:
#line 64 "expr.y" /* glr.c:816  */
    { ((*yyvalp).statement_t) = new BlockStatement(); ((BlockStatement*)((*yyvalp).statement_t))->addStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t));}
#line 1314 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 5:
#line 66 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.statement_t); ((BlockStatement*)((*yyvalp).statement_t))->addStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t));}
#line 1320 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 6:
#line 67 "expr.y" /* glr.c:816  */
    { ((*yyvalp).statement_t) = new BlockStatement(); ((BlockStatement*)((*yyvalp).statement_t))->addStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t));}
#line 1326 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 7:
#line 71 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.statement_t); ((BlockStatement*)((*yyvalp).statement_t))->addStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t));}
#line 1332 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 8:
#line 72 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t);}
#line 1338 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 9:
#line 75 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t);}
#line 1344 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 10:
#line 76 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t);}
#line 1350 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 11:
#line 77 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t);}
#line 1356 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 12:
#line 78 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t);}
#line 1362 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 13:
#line 79 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t);}
#line 1368 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 14:
#line 80 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t);}
#line 1374 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 15:
#line 81 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t);}
#line 1380 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 16:
#line 82 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) =(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t);}
#line 1386 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 17:
#line 83 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t);}
#line 1392 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 18:
#line 84 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t);}
#line 1398 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 19:
#line 85 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new SrandStatement();}
#line 1404 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 20:
#line 91 "expr.y" /* glr.c:816  */
    {
			((*yyvalp).statement_t) = new PreIncrementoStatement(new VarNombreArrayExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.expr_t)));}
#line 1411 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 21:
#line 93 "expr.y" /* glr.c:816  */
    {
			((*yyvalp).statement_t) = new PreDecrementoStatement(new VarNombreArrayExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.expr_t)));}
#line 1418 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 22:
#line 95 "expr.y" /* glr.c:816  */
    {
			((*yyvalp).statement_t) = new PosDecrementoStatement(new VarNombreArrayExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t)));}
#line 1425 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 23:
#line 97 "expr.y" /* glr.c:816  */
    {
			((*yyvalp).statement_t) = new PosIncrementoStatement(new VarNombreArrayExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t)));}
#line 1432 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 24:
#line 99 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new PosDecrementoStatement(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.string_t)));}
#line 1438 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 25:
#line 100 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new PosIncrementoStatement(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.string_t)));}
#line 1444 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 26:
#line 101 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new PreDecrementoStatement(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.string_t)));}
#line 1450 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 27:
#line 102 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new PreIncrementoStatement(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.string_t)));}
#line 1456 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 28:
#line 106 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new CallFuncionStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.exprlist_t));}
#line 1462 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 29:
#line 108 "expr.y" /* glr.c:816  */
    {((*yyvalp).exprlist_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.exprlist_t);}
#line 1468 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 30:
#line 109 "expr.y" /* glr.c:816  */
    {((*yyvalp).exprlist_t) = new ExprList ;}
#line 1474 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 31:
#line 111 "expr.y" /* glr.c:816  */
    {
			((*yyvalp).statement_t) = new DecArrayStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t));}
#line 1481 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 32:
#line 113 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new DecApuntadorStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t));}
#line 1487 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 33:
#line 114 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new DecVariableStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t));}
#line 1493 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 34:
#line 115 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t)  = new BlockStatement(); }
#line 1499 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 35:
#line 118 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t);}
#line 1505 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 36:
#line 119 "expr.y" /* glr.c:816  */
    { ((*yyvalp).statement_t) = NULL;}
#line 1511 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 37:
#line 121 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.statement_t); ((BlockStatement*)((*yyvalp).statement_t))->addStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t));}
#line 1517 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 38:
#line 122 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new BlockStatement(); ((BlockStatement*)((*yyvalp).statement_t))->addStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t));}
#line 1523 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 39:
#line 125 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new DecArrayStatement(NULL,(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t),NULL);}
#line 1529 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 40:
#line 126 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new DecApuntadorStatement(NULL,(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t),NULL);}
#line 1535 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 41:
#line 127 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new DecVariableStatement(NULL,(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t),NULL);}
#line 1541 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 42:
#line 130 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new Funcion_Statement((((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t));}
#line 1547 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 43:
#line 131 "expr.y" /* glr.c:816  */
    {if((((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval.string_t) == "int")
		  ((*yyvalp).statement_t) = new Funcion_Statement("int*",(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t));else ((*yyvalp).statement_t) = new Funcion_Statement("char*",(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t));}
#line 1554 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 44:
#line 136 "expr.y" /* glr.c:816  */
    {
			((*yyvalp).statement_t) = new Producer_Statement((((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t));}
#line 1561 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 45:
#line 140 "expr.y" /* glr.c:816  */
    { ((*yyvalp).expr_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t);}
#line 1567 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 46:
#line 141 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new Parametros();}
#line 1573 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 47:
#line 143 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t); ((Parametros*)((*yyvalp).expr_t))->addParametro((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.parametro_t));}
#line 1579 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 48:
#line 144 "expr.y" /* glr.c:816  */
    { ((*yyvalp).expr_t) = new Parametros();((Parametros*)((*yyvalp).expr_t))->addParametro((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.parametro_t));}
#line 1585 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 49:
#line 147 "expr.y" /* glr.c:816  */
    { ((*yyvalp).parametro_t) = new Parametro((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.string_t),new DecVariableStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.string_t),NULL,NULL));}
#line 1591 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 50:
#line 148 "expr.y" /* glr.c:816  */
    { const char * tipo = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.string_t) == "int"? "int*":"char*"; 
	   ((*yyvalp).parametro_t) = new Parametro(tipo, new DecApuntadorStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.string_t),NULL,NULL)); }
#line 1598 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 51:
#line 150 "expr.y" /* glr.c:816  */
    { const char * tipo = (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.string_t) == "int"? "int[]":"char[]";
           ((*yyvalp).parametro_t) = new Parametro(tipo,new DecArrayStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.expr_t),NULL,NULL)); }
#line 1605 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 52:
#line 153 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t);}
#line 1611 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 53:
#line 154 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new NumberExpr(0);}
#line 1617 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 54:
#line 157 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t);}
#line 1623 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 55:
#line 158 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = NULL;}
#line 1629 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 56:
#line 160 "expr.y" /* glr.c:816  */
    { ((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.statement_t);}
#line 1635 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 57:
#line 161 "expr.y" /* glr.c:816  */
    { ((*yyvalp).statement_t) = NULL;}
#line 1641 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 58:
#line 165 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.statement_t); ((BlockStatement*)((*yyvalp).statement_t))->addStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t));}
#line 1647 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 59:
#line 166 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t);}
#line 1653 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 60:
#line 169 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.statement_t); ((BlockStatement*)((*yyvalp).statement_t))->addStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t));}
#line 1659 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 61:
#line 170 "expr.y" /* glr.c:816  */
    { ((*yyvalp).statement_t) = new BlockStatement(); ((BlockStatement*)((*yyvalp).statement_t))->addStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t));}
#line 1665 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 62:
#line 173 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t);}
#line 1671 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 63:
#line 174 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t);}
#line 1677 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 64:
#line 175 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t);}
#line 1683 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 65:
#line 176 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t);}
#line 1689 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 66:
#line 177 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t);}
#line 1695 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 67:
#line 178 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t);}
#line 1701 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 68:
#line 179 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t);}
#line 1707 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 69:
#line 180 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t);}
#line 1713 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 70:
#line 181 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t);}
#line 1719 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 71:
#line 182 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new SrandStatement();}
#line 1725 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 72:
#line 183 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t);}
#line 1731 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 73:
#line 188 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new Return_Statement((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t));}
#line 1737 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 74:
#line 189 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new Return_Statement(NULL);}
#line 1743 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 75:
#line 192 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t);}
#line 1749 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 76:
#line 193 "expr.y" /* glr.c:816  */
    { ((*yyvalp).expr_t) = new StringExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.string_t));}
#line 1755 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 77:
#line 194 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new ArrayExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.exprlist_t));}
#line 1761 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 78:
#line 195 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = NULL;}
#line 1767 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 79:
#line 198 "expr.y" /* glr.c:816  */
    { ((*yyvalp).string_t) = "int"; }
#line 1773 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 80:
#line 199 "expr.y" /* glr.c:816  */
    {  ((*yyvalp).string_t) =  "char"; }
#line 1779 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 81:
#line 201 "expr.y" /* glr.c:816  */
    { ((*yyvalp).statement_t) = new For_Statement((((yyGLRStackItem const *)yyvsp)[YYFILL (-12)].yystate.yysemantics.yysval.statement_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t));}
#line 1785 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 82:
#line 203 "expr.y" /* glr.c:816  */
    { ((*yyvalp).statement_t)  = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t); }
#line 1791 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 83:
#line 204 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = NULL;}
#line 1797 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 84:
#line 207 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new If_Statement((((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.statement_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t));}
#line 1803 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 85:
#line 208 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new If_Statement((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t),NULL);}
#line 1809 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 86:
#line 212 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new While_Statement((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t));}
#line 1815 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 87:
#line 215 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new DoWhile_Statement((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.statement_t));}
#line 1821 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 88:
#line 218 "expr.y" /* glr.c:816  */
    { ((*yyvalp).statement_t) = new BlockStatement(); ((BlockStatement*)((*yyvalp).statement_t))->addStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.statement_t));}
#line 1827 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 89:
#line 219 "expr.y" /* glr.c:816  */
    { ((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.statement_t);}
#line 1833 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 90:
#line 224 "expr.y" /* glr.c:816  */
    { ((*yyvalp).statement_t) = new PrintStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.exprlist_t));}
#line 1839 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 91:
#line 225 "expr.y" /* glr.c:816  */
    { ((*yyvalp).statement_t) = new PrintSoloStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.string_t));}
#line 1845 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 92:
#line 231 "expr.y" /* glr.c:816  */
    { ((*yyvalp).exprlist_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.exprlist_t);((*yyvalp).exprlist_t)->push_back((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t)); }
#line 1851 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 93:
#line 232 "expr.y" /* glr.c:816  */
    { ((*yyvalp).exprlist_t) = new ExprList; ((*yyvalp).exprlist_t)->push_back((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t)); }
#line 1857 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 94:
#line 237 "expr.y" /* glr.c:816  */
    { ((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t); ((AssignStatement*)((*yyvalp).statement_t))->nombre = new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.string_t));
		 ((AssignStatement*)((*yyvalp).statement_t))->expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t);}
#line 1864 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 95:
#line 239 "expr.y" /* glr.c:816  */
    { 
                 ((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t);((AssignStatement*)((*yyvalp).statement_t))->nombre = new VarNombreArrayExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.expr_t)); ((AssignStatement*)((*yyvalp).statement_t))->expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t); }
#line 1871 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 96:
#line 241 "expr.y" /* glr.c:816  */
    { 
	    	 ((*yyvalp).statement_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t); ((AssignStatement*)((*yyvalp).statement_t))->nombre = new ReferenciaExpr(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.string_t))); ((AssignStatement*)((*yyvalp).statement_t))->expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t); }
#line 1878 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 97:
#line 243 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new BlockStatement(); 
		((AssignStatement*)(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t))->nombre = new DesferenciaExpr(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.string_t))); ((AssignStatement*)(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t))->expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t);
		((BlockStatement*)((*yyvalp).statement_t))->addStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.statement_t)); if((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.statement_t) !=NULL){ ((PreIncrementoStatement*)(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.statement_t))->expr1 = new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.string_t)); 
		((BlockStatement*)((*yyvalp).statement_t))->addStatement((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.statement_t));} }
#line 1887 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 98:
#line 249 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new PosIncrementoStatement(NULL); }
#line 1893 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 99:
#line 250 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new PosDecrementoStatement(NULL);}
#line 1899 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 100:
#line 251 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = NULL;}
#line 1905 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 101:
#line 255 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new AsignarStatement(NULL,NULL);}
#line 1911 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 102:
#line 256 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new MasIgualStatement(NULL,NULL); }
#line 1917 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 103:
#line 257 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new MenosIgualStatement(NULL,NULL);}
#line 1923 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 104:
#line 258 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new MultIgualStatement(NULL,NULL);}
#line 1929 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 105:
#line 259 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new DivIgualStatement(NULL,NULL);}
#line 1935 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 106:
#line 260 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new ModIgualStatement(NULL,NULL);}
#line 1941 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 107:
#line 261 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new OrBitIgualStatement(NULL,NULL);}
#line 1947 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 108:
#line 262 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new AndBitIgualStatement(NULL,NULL);}
#line 1953 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 109:
#line 263 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new XorBitIgualStatement(NULL,NULL);}
#line 1959 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 110:
#line 264 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new AsigCorIzqIgualStatement(NULL,NULL);}
#line 1965 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 111:
#line 265 "expr.y" /* glr.c:816  */
    {((*yyvalp).statement_t) = new AsigCorDerIgualStatement(NULL,NULL);}
#line 1971 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 116:
#line 275 "expr.y" /* glr.c:816  */
    { ((*yyvalp).expr_t) = new TernarioExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t)); }
#line 1977 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 117:
#line 276 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t);}
#line 1983 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 118:
#line 280 "expr.y" /* glr.c:816  */
    { ((*yyvalp).expr_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.expr_t); ((AssignExpr*)((*yyvalp).expr_t))->nombre = new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.string_t)); ((AssignExpr*)((*yyvalp).expr_t))->expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t); }
#line 1989 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 119:
#line 281 "expr.y" /* glr.c:816  */
    { 
            ((*yyvalp).expr_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.expr_t);((AssignExpr*)((*yyvalp).expr_t))->nombre = new VarNombreArrayExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.expr_t)); ((AssignExpr*)((*yyvalp).expr_t))->expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t); }
#line 1996 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 120:
#line 283 "expr.y" /* glr.c:816  */
    { 
	    ((*yyvalp).expr_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.expr_t); ((AssignExpr*)((*yyvalp).expr_t))->nombre = new ReferenciaExpr(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.string_t))); ((AssignExpr*)((*yyvalp).expr_t))->expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.expr_t); }
#line 2003 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 121:
#line 285 "expr.y" /* glr.c:816  */
    { 
	    ((*yyvalp).expr_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.expr_t); ((AssignExpr*)((*yyvalp).expr_t))->nombre = new DesferenciaExpr(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.string_t))); ((AssignExpr*)((*yyvalp).expr_t))->expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.expr_t); }
#line 2010 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 122:
#line 288 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new AsignarExpr(NULL,NULL);}
#line 2016 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 123:
#line 289 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new MasIgualExpr(NULL,NULL); }
#line 2022 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 124:
#line 290 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new MenosIgualExpr(NULL,NULL);}
#line 2028 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 125:
#line 291 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new MultIgualExpr(NULL,NULL);}
#line 2034 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 126:
#line 292 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new DivIgualExpr(NULL,NULL);}
#line 2040 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 127:
#line 293 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new ModIgualExpr(NULL,NULL);}
#line 2046 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 128:
#line 294 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new OrBitIgualExpr(NULL,NULL);}
#line 2052 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 129:
#line 295 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new AndBitIgualExpr(NULL,NULL);}
#line 2058 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 130:
#line 296 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new XorBitIgualExpr(NULL,NULL);}
#line 2064 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 131:
#line 297 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new AsigCorIzqIgualExpr(NULL,NULL);}
#line 2070 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 132:
#line 298 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new AsigCorDerIgualExpr(NULL,NULL);}
#line 2076 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 133:
#line 301 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t);}
#line 2082 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 134:
#line 302 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t);}
#line 2088 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 135:
#line 305 "expr.y" /* glr.c:816  */
    { ((*yyvalp).expr_t) = new AndExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t)); }
#line 2094 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 136:
#line 306 "expr.y" /* glr.c:816  */
    { ((*yyvalp).expr_t) = new OrExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t)); }
#line 2100 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 137:
#line 307 "expr.y" /* glr.c:816  */
    { ((*yyvalp).expr_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t);}
#line 2106 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 138:
#line 309 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new OPorBitExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t));}
#line 2112 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 139:
#line 310 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new ExclPorBitExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t));}
#line 2118 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 140:
#line 311 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new YPorBitExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t));}
#line 2124 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 141:
#line 312 "expr.y" /* glr.c:816  */
    { ((*yyvalp).expr_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t);}
#line 2130 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 142:
#line 314 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new IgualExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t));}
#line 2136 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 143:
#line 315 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new DistintoExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t));}
#line 2142 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 144:
#line 316 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new MenorExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t));}
#line 2148 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 145:
#line 317 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new MayorExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t));}
#line 2154 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 146:
#line 318 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new MenorIgualExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t));}
#line 2160 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 147:
#line 319 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new MayorIgualExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t));}
#line 2166 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 148:
#line 320 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t);}
#line 2172 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 149:
#line 322 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new CorrimientoIzqExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t));}
#line 2178 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 150:
#line 323 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new CorrimientoDerExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t));}
#line 2184 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 151:
#line 324 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t);}
#line 2190 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 152:
#line 326 "expr.y" /* glr.c:816  */
    { ((*yyvalp).expr_t) = new AddExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t));}
#line 2196 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 153:
#line 327 "expr.y" /* glr.c:816  */
    { ((*yyvalp).expr_t) = new SubExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t));}
#line 2202 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 154:
#line 328 "expr.y" /* glr.c:816  */
    { ((*yyvalp).expr_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t);}
#line 2208 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 155:
#line 331 "expr.y" /* glr.c:816  */
    { ((*yyvalp).expr_t) = new MultExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t));}
#line 2214 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 156:
#line 332 "expr.y" /* glr.c:816  */
    { ((*yyvalp).expr_t) = new DivExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t));}
#line 2220 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 157:
#line 333 "expr.y" /* glr.c:816  */
    { ((*yyvalp).expr_t) = new ModExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t));}
#line 2226 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 158:
#line 334 "expr.y" /* glr.c:816  */
    { ((*yyvalp).expr_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t);}
#line 2232 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 159:
#line 337 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new NegacionExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t));}
#line 2238 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 160:
#line 338 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new ComplementoExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t));}
#line 2244 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 161:
#line 339 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new DesferenciaExpr(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.string_t)));}
#line 2250 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 162:
#line 340 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new DesferenciaExpr(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.string_t)));}
#line 2256 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 163:
#line 341 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new ReferenciaExpr(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.string_t)));}
#line 2262 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 164:
#line 342 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new ReferenciaExpr(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.string_t)));}
#line 2268 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 165:
#line 343 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new PreIncrementoExpr(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.string_t)));}
#line 2274 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 166:
#line 344 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new PreIncrementoExpr(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.string_t)));}
#line 2280 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 167:
#line 345 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new PreDecrementoExpr(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.string_t)));}
#line 2286 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 168:
#line 346 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new PreDecrementoExpr(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.string_t)));}
#line 2292 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 169:
#line 347 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new PosIncrementoExpr(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.string_t)));}
#line 2298 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 170:
#line 348 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new PosIncrementoExpr(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.string_t)));}
#line 2304 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 171:
#line 349 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new PosDecrementoExpr(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.string_t)));}
#line 2310 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 172:
#line 350 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new PosDecrementoExpr(new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.string_t)));}
#line 2316 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 173:
#line 351 "expr.y" /* glr.c:816  */
    {
			((*yyvalp).expr_t) = new PreIncrementoExpr(new VarNombreArrayExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.expr_t)));}
#line 2323 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 174:
#line 353 "expr.y" /* glr.c:816  */
    {
			((*yyvalp).expr_t) = new PreDecrementoExpr(new VarNombreArrayExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.expr_t)));}
#line 2330 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 175:
#line 355 "expr.y" /* glr.c:816  */
    {
			((*yyvalp).expr_t) = new PosDecrementoExpr(new VarNombreArrayExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t)));}
#line 2337 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 176:
#line 357 "expr.y" /* glr.c:816  */
    {
			((*yyvalp).expr_t) = new PosIncrementoExpr(new VarNombreArrayExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.expr_t)));}
#line 2344 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 177:
#line 360 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.expr_t);}
#line 2350 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 178:
#line 364 "expr.y" /* glr.c:816  */
    {  ((*yyvalp).expr_t) = new VarNombreExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.string_t));}
#line 2356 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 179:
#line 365 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new FuncionExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.exprlist_t));}
#line 2362 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 180:
#line 366 "expr.y" /* glr.c:816  */
    { ((*yyvalp).expr_t) = new NumberExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.int_t));}
#line 2368 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 181:
#line 367 "expr.y" /* glr.c:816  */
    { ((*yyvalp).expr_t) = new CharExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.char_t));}
#line 2374 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 182:
#line 368 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t)  = new VarNombreArrayExpr((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.string_t),(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.expr_t));}
#line 2380 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 183:
#line 369 "expr.y" /* glr.c:816  */
    { ((*yyvalp).expr_t) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.expr_t);}
#line 2386 "expr_parser.cpp" /* glr.c:816  */
    break;

  case 184:
#line 370 "expr.y" /* glr.c:816  */
    {((*yyvalp).expr_t) = new RandExpr();}
#line 2392 "expr_parser.cpp" /* glr.c:816  */
    break;


#line 2396 "expr_parser.cpp" /* glr.c:816  */
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
  (!!((Yystate) == (-301)))

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



