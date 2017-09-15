%option noyywrap
%option yylineno
%x commentMultLine
%x stringState
%x charState
%{
#include <stdio.h>
#include "tokens.h" 
#include "ash.h"
int  validateChar();
%}
%%
[ \t]   { /*nada */} 
"//".*\n {return TK_EOL;}
#.*\n   { return TK_EOL;}
"/*" 	{ BEGIN(commentMultLine);}
"\n"+	{ return TK_EOL;}
"+"	{ return TK_Op_add;}
"-"	{ return TK_Op_sub;}
"*"	{ return TK_Op_mul;}
"/"	{ return TK_Op_div;}
"("	{ return TK_left_par;}
")"	{ return TK_rigth_par;}
"{"     { return TK_left_llave;}
"}"     { return TK_rigth_llave;}
"["     { return TK_left_corchete;}
"]"     { return TK_rigth_corchete;}
"&"  	{ return TK_Refenciacion;}
"?"  	{ return TK_Interogaccion;}
"!"  	{ return TK_Negarcion;}
":"  	{ return TK_DosPuntos;}
"~"  	{ return TK_Complemento;}
"%"  	{ return TK_Modulo;}
"="  	{ return TK_Asignacion;}
"=="    { return TK_Igual;}
"<"     { return TK_Menor;}
">"     { return TK_Mayor;}
"!="    { return TK_Distinto;}
"<="    { return TK_MenorIgual;}
">="    { return TK_MayorIgual;}
";"     { return TK_PuntoComma;}
","     { return TK_Comma;}
"+="    { return TK_AutoAdd;}
"-="    { return TK_AutoSub;}
"*="    { return TK_AutoMul;}
"/="    { return TK_AutoDiv;}
"%="    { return TK_AutoMod;}
"|="    { return TK_AsigOrBit;}
"&="    { return TK_AsigAndBit;}
"^="    { return TK_AsigXorBit;}
"<<="   { return TK_AsigCorIzq;}
">>="   { return TK_AsigCorDer;}
"++"    { return TK_Incremento;}
"--"    { return TK_Decremento;}
"<<"    { return TK_CorrimientoIzq;}
">>"    { return TK_CorrimientoDer;}
"^"     { return TK_ExclPorBit;}
"|"     { return TK_OPorBit;}
"&&"    { return TK_And;}
"||"    { return TK_Or;}
"char"  { return TK_Char;}
"int"   { return TK_Int;}
"void"  { return TK_Void;}
"for"   { return TK_For;}
"if"    { return TK_IF;}
"else"  { return TK_Else;}
"printf" { return TK_Print;}
"scanf" { return TK_Scanf;}
"return" { return TK_Return;}
"while" { return TK_While;}
"do" { return TK_Do;}
\"      { BEGIN(stringState);}
\'      { BEGIN(charState);}
"0x"[0-9a-fA-F]+ { yylval.int_t =(int)strtol(yytext, NULL, 16); return TK_NUMERO;}
"0"[0-8]+ { yylval.int_t =(int)strtol(yytext, NULL, 8); return TK_NUMERO;}
[0-9]+ { yylval.int_t = atoi(yytext); return TK_NUMERO;}
[a-zA-Z_][a-zA-Z0-9_]* {  yylval.string_t = strdup(yytext); return TK_VarNombre; }
.	{ return TK_Error;}
<INITIAL><<EOF>> { yyterminate(); }



<charState>.|[^\'] {
				int c;
				
				while((c = yyinput()) != 39 ){						
					if(c != atoi("\n") ){
				
				 fprintf(stderr,"line %d Error :char no accepted \n",yylineno);
					 yyterminate();
				   	}					
				}
			 yylval.char_t = yytext[0];
			 BEGIN(INITIAL);
			return TK_CharLit; 
		}

<charState>\\n { if(validateChar()==1)
		  yyterminate();
		  yylval.char_t = '\n';
      		  BEGIN(INITIAL);
		  return TK_CharLit; 
		}
<charState>\\t { if(validateChar()==1)
		  yyterminate();
		  yylval.char_t = '\t';
      		  BEGIN(INITIAL);
		  return TK_CharLit; 
		}
<charState>\\r { if(validateChar()==1)
		  yyterminate();
		  yylval.char_t = '\r';
      		  BEGIN(INITIAL);
		  return TK_CharLit; 
		}
<charState>\\a { if(validateChar()==1)
		  yyterminate();
		  yylval.char_t = '\a';
      		  BEGIN(INITIAL);
		  return TK_CharLit; 
		}
<charState>\\b { if(validateChar()==1)
		  yyterminate();
		  yylval.char_t = '\b';
      		  BEGIN(INITIAL);
		  return TK_CharLit; 
		}
<charState>'\"' { if(validateChar()==1)
		  yyterminate();
		  yylval.char_t = '\"';
      		  BEGIN(INITIAL);
		  return TK_CharLit; 
		}
<charState>\\' { if(validateChar()==1)
		  yyterminate();
		  yylval.char_t = '\'';
      		  BEGIN(INITIAL);
		  return TK_CharLit; 
		}
<stringState>[^\"\n]+ {
				int c;
				int cerado = 0;
				while((c = yyinput()) != 34 ){						
					if(c != atoi("\n") ){
					 fprintf(stderr,"line %d Error :string without end \n",yylineno);
					 yyterminate();
				   	}					
				}
			 yylval.string_t = strdup(yytext);
			 BEGIN(INITIAL);
			return TK_String;
			
		      } 

<commentMultLine>"*/" { BEGIN(INITIAL);}
<commentMultLine>.|\n { /*nada */ }
<commentMultLine><<EOF>> { printf("line: %d Block comment without end \n",yylineno); yyterminate(); return 0;}
%%

int validateChar(){
	int c;
	while((c = yyinput()) != 39 ){						
		if(c != atoi("\n") ){
		fprintf(stderr,"line %d Error :char no accepted \n",yylineno);
		 return 1;
		}					
	}
return 0;
}
