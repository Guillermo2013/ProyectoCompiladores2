%code requires {
 #include "ash.h"
}
%{
#include <stdio.h>


#define SZ 32
int yylex();
extern char* yytext;
extern int yylineno;
extern char *yyfilename;
void yyerror(const char *msg){
printf("Error : String(%s) Line %d : %s  file: %s caracter  \n",yytext,yylineno,msg,yyfilename);
}


	
#define YYERROR_VERBOSE 2
#define YYDEBUG 1
%}
%glr-parser
%expect 68

%union {
  Statement *statement_t;
  Expr *expr_t; 
  int int_t;
  char *string_t;
  char char_t;
}

%token TK_Op_add TK_Op_sub TK_Op_mul TK_Op_div TK_left_par TK_rigth_par TK_EOL TK_Error TK_EOF TK_ERROR TK_Asignacion TK_Dolar 
%token TK_NUMERO TK_Print TK_Separador  TK_Igual TK_Distinto TK_Menor TK_Mayor TK_MenorIgual TK_MayorIgual TK_IF TK_Else 
%token TK_left_llave TK_rigth_llave TK_VarNombre TK_While TK_left_corchete TK_rigth_corchete TK_Refenciacion TK_PuntoComma 
%token TK_Char TK_Int TK_Void TK_For TK_Scanf TK_String TK_CharLit TK_Modulo TK_Comma TK_AutoAdd TK_AutoSub TK_AutoMul TK_AutoDiv
%token TK_AsigOrBit TK_AsigCorIzq TK_AsigCorDer TK_Incremento TK_Decremento TK_CorrimientoIzq TK_CorrimientoDer TK_ExclPorBit TK_And TK_Or
%token TK_OPorBit TK_Interogaccion TK_Negarcion TK_Complemento TK_DosPuntos

%type <int_t> TK_NUMERO 
%type <expr_t> expr term factor add conditional corrimiento exprForBit unary andOr
%type <string_t> TK_VarNombre TK_String
%type <char_t> TK_CharLit
%type <statement_t> statement assign_statement print_statement if_statement statementList while_statement
%type <statement_t> BlockStatement producce_statement BlockStatementOrStatement for_statement for_assign

%%

inputs :opt_eols statementList opt_eols{  $2->exec();}
       |opt_eols 
;

statementList:statementList  opt_eols statement  {$$ = $1; ((BlockStatement*)$$)->addStatement($3);}
	     |statement { $$ = new BlockStatement(); ((BlockStatement*)$$)->addStatement($1);}
	     
;
statement : if_statement {$$ = $1;}
	  | while_statement {$$ = $1;}
	  | print_statement {$$ = $1;}
          | assign_statement TK_PuntoComma {$$ = $1;}
	  | producce_statement {$$ = $1;}
	  | for_statement {$$ = $1;}
;

for_statement: TK_For TK_left_par opt_eols for_assign opt_eols TK_PuntoComma opt_eols expr opt_eols TK_PuntoComma opt_eols expr opt_eols TK_rigth_par opt_eols BlockStatementOrStatement { $$ = new For_Statement($4,$8,$12,$16);};
;
for_assign : TK_VarNombre TK_Asignacion expr %dprec 2 { $$  = new AssignStatement($1,$3); }
	   |  %dprec 1 {$$ = NULL;}
;

if_statement :TK_IF TK_left_par expr TK_rigth_par eols BlockStatementOrStatement TK_EOL TK_Else TK_EOL BlockStatementOrStatement %dprec 1 {$$ = new If_Statement($3,$6,$10);}
             |TK_IF TK_left_par expr TK_rigth_par eols BlockStatementOrStatement %dprec 2 {$$ = new If_Statement($3,$6,NULL);}
	     
; 

while_statement : TK_While TK_left_par expr TK_rigth_par opt_eols BlockStatementOrStatement {$$ = new While_Statement($3,$6);}
;

BlockStatementOrStatement: statement { $$ = new BlockStatement(); ((BlockStatement*)$$)->addStatement($1);}
			 | BlockStatement { $$ = $1;}	
;
 
BlockStatement: TK_left_llave opt_eols statementList opt_eols TK_rigth_llave  { $$ = $3;}	
;

print_statement : TK_Print expr { $$ = new PrintStatement($2);}

;

producce_statement : TK_Void TK_VarNombre TK_left_par TK_rigth_par opt_eols BlockStatement {$$ = new Producer_Statement($2,$6);}
;

assign_statement : TK_VarNombre TK_Asignacion expr    {  $$  = new AssignStatement($1,$3);}
		 | TK_VarNombre TK_left_corchete  expr TK_rigth_corchete  TK_Asignacion expr   {$$ = NULL;}
		 | TK_Refenciacion TK_VarNombre TK_Asignacion expr  {  $$  = NULL;}
		 | TK_Op_mul TK_VarNombre TK_Asignacion expr {$$ = NULL;}
;
eols:eols TK_EOL
     |TK_EOL 
;
opt_eols:opt_eols TK_EOL 
	|
;
expr:andOr TK_Interogaccion expr TK_DosPuntos expr  %dprec 2 { $$ = new TernarioExpr($1,$3,$5);}
    |andOr  %dprec 1 {$$ = $1;}
;
andOr:andOr TK_And exprForBit %dprec 2 { $$ = new AndExpr($1,$3); }
    |andOr TK_Or exprForBit %dprec 3 { $$ = new OrExpr($1,$3); }
    |exprForBit %dprec 1 { $$ = $1;}
;	
exprForBit : exprForBit TK_OPorBit conditional %dprec 2 {$$ = new OPorBitExpr($1,$3);}
	    | exprForBit TK_ExclPorBit conditional %dprec 3 {$$ = new ExclPorBitExpr($1,$3);}
	    | exprForBit TK_Refenciacion conditional %dprec 4 {$$ = new YPorBitExpr($1,$3);}
	    | conditional %dprec 1 { $$ = $1;}
;
conditional: conditional TK_Igual corrimiento  {$$ = new IgualExpr($1,$3);}
	     |conditional TK_Distinto corrimiento  {$$ = new DistintoExpr($1,$3);}
	     |conditional TK_Menor corrimiento  {$$ = new MenorExpr($1,$3);}
	     |conditional TK_Mayor corrimiento  {$$ = new MayorExpr($1,$3);}
	     |conditional TK_MenorIgual corrimiento  {$$ = new MenorIgualExpr($1,$3);}
	     |conditional TK_MayorIgual corrimiento  {$$ = new MayorIgualExpr($1,$3);}
	     |corrimiento  {$$ = $1;}
;
corrimiento: corrimiento TK_CorrimientoIzq add {$$ = new CorrimientoIzqExpr($1,$3);}
	    |corrimiento TK_CorrimientoDer add {$$ = new CorrimientoDerExpr($1,$3);}
            |add {$$ = $1;}
;
add :  add TK_Op_add term { $$ = new AddExpr($1,$3);}
      | add TK_Op_sub term { $$ = new SubExpr($1,$3);}
      | term { $$ = $1;}
;

term :  term TK_Op_mul unary { $$ = new MultExpr($1,$3);}
      | term TK_Op_div unary { $$ = new DivExpr($1,$3);}
      | term TK_Modulo unary { $$ = new ModExpr($1,$3);}
      | unary { $$ = $1;}
;

unary : TK_Negarcion expr {$$ = new NegacionExpr($2);}
      | TK_Complemento expr {$$ = new ComplementoExpr($2);}
      | TK_Op_mul TK_VarNombre {$$ = new DesferenciaExpr(new VarNombreExpr($2));}
      | TK_Op_mul TK_left_par TK_VarNombre TK_rigth_par {$$ = new DesferenciaExpr(new VarNombreExpr($3));}
      | TK_Refenciacion TK_VarNombre {$$ = new ReferenciaExpr(new VarNombreExpr($2));}
      | TK_Refenciacion TK_left_par TK_VarNombre TK_rigth_par {$$ = new ReferenciaExpr(new VarNombreExpr($3));}
      | TK_Incremento TK_VarNombre {$$ = new PreIncrementoExpr(new VarNombreExpr($2));}
      | TK_Incremento TK_left_par TK_VarNombre TK_rigth_par {$$ = new PreIncrementoExpr(new VarNombreExpr($3));}
      | TK_Decremento TK_VarNombre {$$ = new PreDecrementoExpr(new VarNombreExpr($2));}
      | TK_Decremento TK_left_par TK_VarNombre TK_rigth_par {$$ = new PreDecrementoExpr(new VarNombreExpr($3));}
      | TK_VarNombre TK_Incremento {$$ = new PosIncrementoExpr(new VarNombreExpr($1));}
      | TK_left_par TK_VarNombre TK_rigth_par TK_Incremento {$$ = new PosIncrementoExpr(new VarNombreExpr($2));}
      | TK_VarNombre TK_Decremento {$$ = new PosDecrementoExpr(new VarNombreExpr($1));}
      | TK_left_par TK_VarNombre TK_rigth_par TK_Decremento {$$ = new PosDecrementoExpr(new VarNombreExpr($2));}
      | factor {$$ = $1;}

;
	
factor: TK_VarNombre {  $$ = new VarNombreExpr($1);}
       | TK_NUMERO { $$ = new NumberExpr($1);}
       | TK_String { $$ = new StringExpr($1);}
       | TK_CharLit { $$ = new CharExpr($1);}
       | TK_left_par expr TK_rigth_par { $$ = $2;}      
;
