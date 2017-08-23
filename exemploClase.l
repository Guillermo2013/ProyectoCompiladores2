%option noyywrap
%option yylineno
%x commentMultLine
%x include
%x includeM
%x stringState
%x charState
%{
#include <stdio.h>
#include "tokens.h" 
#include "ash.h"
typedef struct include_stack{
 struct include_stack *prev;
 FILE *f;
 int lineno;
 char *filename;
 YY_BUFFER_STATE bs;
} include_stack_t;

include_stack_t *inc_stack = NULL;
char *yyfilename;
int pop_file();
int push_file(char *filename);
int  validateChar();
%}
%%
[ \t]   { /*nada */} 
"//".*\n {return TK_EOL;}
"#"[ \t]*"include"[ \t]*\" { BEGIN(include);} 
"#"[ \t]*"include"[ \t]*< { BEGIN(includeM);} 
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
"^="    { return TK_AsigOrBit;}
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
"while" { return TK_While;}
\"      { BEGIN(stringState);}
\'      { BEGIN(charState);}
"0x"[0-9a-fA-F]+ { yylval.int_t =(int)strtol(yytext, NULL, 16); return TK_NUMERO;}
"0"[0-8]+ { yylval.int_t =(int)strtol(yytext, NULL, 8); return TK_NUMERO;}
[0-9]+ { yylval.int_t = atoi(yytext); return TK_NUMERO;}
[a-zA-Z_][a-zA-Z0-9_]* {  yylval.string_t = strdup(yytext); return TK_VarNombre; }
.	{ return TK_Error;}
<INITIAL><<EOF>> { if(pop_file() != 0 ) yyterminate(); }



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
<charState>[\"] { if(validateChar()==1)
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
<include>[^\"\n]+ { 
			{
				int c;
				int cerrado = 0;
				while((c = yyinput()) != '\n'){						
					if(c != 34 && c != 32){
					  fprintf(stderr,"line %d Error :include no more expression \n",yylineno);
					 yyterminate();		
					}
									
				}
				if(cerrado == 0){ 
					 fprintf(stderr,"line %d Error :include without end \n",yylineno);
					 yyterminate();
				}
				yylineno++;
				if(push_file(yytext) != 0)
					yyterminate();	
			}
			BEGIN(INITIAL);
		  }
<includeM>[^>\n]+ { 
			{
				int c;
				int cerrado = 0;
				while((c = yyinput()) != '\n'){						
									
					if(c != 62 && c != 32){
					 fprintf(stderr,"line %d Error :include no more expression \n",yylineno);
					 yyterminate();		
					}		
					cerrado = 1;		
				}
				if(cerrado == 0){ 
					 fprintf(stderr,"line %d Error :include without end \n",yylineno);
					 yyterminate();
				}
				yylineno++;
				if(push_file(yytext) != 0)
					yyterminate();	
			}
			BEGIN(INITIAL);
		  }


<commentMultLine>"*/" { BEGIN(INITIAL);}
<commentMultLine>.|\n { /*nada */ }
<commentMultLine><<EOF>> { printf("line: %d Block comment without end \n",yylineno); yyterminate(); return 0;}
%%
int push_file (char *filename ){
	FILE *f  = fopen(filename,"r");
       if(f == NULL){
		fprintf(stderr,"file %s no found",filename);
		return 1;
	}
	
	include_stack_t *is = (include_stack_t*)malloc(sizeof(include_stack_t));
	if(is == NULL){
		fprintf(stderr,"out memory");
		return 1;
	}
	is->f = f;
	is->lineno = yylineno;
        is->filename = yyfilename; 
        is->bs = yy_create_buffer(f,YY_BUF_SIZE);
        is->prev = inc_stack;
        inc_stack = is;
        yyfilename = filename;
        yylineno = 1;
        yy_switch_to_buffer(is->bs);
	return 0;
}
int pop_file(){
        include_stack_t * prev_is = inc_stack->prev;
	fclose(inc_stack->f);
	yy_delete_buffer(inc_stack->bs);
	yylineno = inc_stack->lineno;
	yyfilename = inc_stack->filename;
	free(inc_stack);
	if(prev_is == NULL) return 1;
        yy_switch_to_buffer(prev_is->bs);
	inc_stack = prev_is;
	return 0;
}
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
