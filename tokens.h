/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Skeleton interface for Bison GLR parsers in C

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

#ifndef YY_YY_TOKENS_H_INCLUDED
# define YY_YY_TOKENS_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "expr.y" /* glr.c:197  */

 #include "ash.h"

#line 48 "tokens.h" /* glr.c:197  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_Op_add = 258,
    TK_Op_sub = 259,
    TK_Op_mul = 260,
    TK_Op_div = 261,
    TK_left_par = 262,
    TK_rigth_par = 263,
    TK_EOL = 264,
    TK_Error = 265,
    TK_EOF = 266,
    TK_ERROR = 267,
    TK_Asignacion = 268,
    TK_Dolar = 269,
    TK_NUMERO = 270,
    TK_Print = 271,
    TK_Separador = 272,
    TK_Igual = 273,
    TK_Distinto = 274,
    TK_Menor = 275,
    TK_Mayor = 276,
    TK_MenorIgual = 277,
    TK_MayorIgual = 278,
    TK_IF = 279,
    TK_Else = 280,
    TK_left_llave = 281,
    TK_rigth_llave = 282,
    TK_VarNombre = 283,
    TK_While = 284,
    TK_left_corchete = 285,
    TK_rigth_corchete = 286,
    TK_Refenciacion = 287,
    TK_PuntoComma = 288,
    TK_Char = 289,
    TK_Int = 290,
    TK_Void = 291,
    TK_For = 292,
    TK_Scanf = 293,
    TK_String = 294,
    TK_CharLit = 295,
    TK_Modulo = 296,
    TK_Comma = 297,
    TK_AutoAdd = 298,
    TK_AutoSub = 299,
    TK_AutoMul = 300,
    TK_AutoDiv = 301,
    TK_AsigOrBit = 302,
    TK_AsigCorIzq = 303,
    TK_AsigCorDer = 304,
    TK_Incremento = 305,
    TK_Decremento = 306,
    TK_CorrimientoIzq = 307,
    TK_CorrimientoDer = 308,
    TK_ExclPorBit = 309,
    TK_And = 310,
    TK_Or = 311,
    TK_OPorBit = 312,
    TK_Interogaccion = 313,
    TK_Negarcion = 314,
    TK_Complemento = 315,
    TK_DosPuntos = 316,
    TK_AsigAndBit = 317,
    TK_AsigXorBit = 318,
    TK_AutoMod = 319,
    TK_Do = 320,
    TK_Return = 321
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 25 "expr.y" /* glr.c:197  */

  Statement *statement_t;
  Expr *expr_t; 
  int int_t;
  char *string_t;
  char char_t;
  ExprList *exprlist_t;
  Parametro *parametro_t;

#line 137 "tokens.h" /* glr.c:197  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TOKENS_H_INCLUDED  */
