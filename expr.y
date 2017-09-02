%code requires {
 #include "ash.h"
}
%{
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
%}
%glr-parser
%expect 74

%union {
  Statement *statement_t;
  Expr *expr_t; 
  int int_t;
  char *string_t;
  char char_t;
  ExprList *exprlist_t;
  Parametro *parametro_t;
}

%token TK_Op_add TK_Op_sub TK_Op_mul TK_Op_div TK_left_par TK_rigth_par TK_EOL TK_Error TK_EOF TK_ERROR TK_Asignacion TK_Dolar 
%token TK_NUMERO TK_Print TK_Separador  TK_Igual TK_Distinto TK_Menor TK_Mayor TK_MenorIgual TK_MayorIgual TK_IF TK_Else 
%token TK_left_llave TK_rigth_llave TK_VarNombre TK_While TK_left_corchete TK_rigth_corchete TK_Refenciacion TK_PuntoComma 
%token TK_Char TK_Int TK_Void TK_For TK_Scanf TK_String TK_CharLit TK_Modulo TK_Comma TK_AutoAdd TK_AutoSub TK_AutoMul TK_AutoDiv
%token TK_AsigOrBit TK_AsigCorIzq TK_AsigCorDer TK_Incremento TK_Decremento TK_CorrimientoIzq TK_CorrimientoDer TK_ExclPorBit TK_And TK_Or
%token TK_OPorBit TK_Interogaccion TK_Negarcion TK_Complemento TK_DosPuntos TK_AsigAndBit TK_AsigXorBit TK_AutoMod TK_Do TK_Return

%type <int_t> TK_NUMERO 
%type <expr_t> expr term factor add conditional corrimiento exprForBit unary andOr ternario assignExpr opAssign optionalAssign parametroList 
%type <expr_t> optparametroList optionalExpr
%type <parametro_t>  parametro
%type <string_t> TK_VarNombre TK_String Type
%type <char_t> TK_CharLit
%type <statement_t> statement assign_statement print_statement if_statement statementList while_statement scanf_statement 
%type <statement_t>  producce_statement BlockStatementOrStatement for_statement for_assign opAssignStatement  
%type <statement_t> doWhile_statement declaration_statement funcion_statement callFuncion_statement optionalBlock
%type <statement_t> statementListFuncion statementFuncion BlockStatementFuncion return_statement
%type <exprlist_t> arg_list optionalParameter

%%

inputs :opt_eols statementList opt_eols {$2->ValidateSemantic();}
       |opt_eols 
;

statementList:statementList  opt_eols statement  {$$ = $1; ((BlockStatement*)$$)->addStatement($3);}
	     |statement { $$ = new BlockStatement(); ((BlockStatement*)$$)->addStatement($1);}
	     
;
statement : if_statement {$$ = $1;}
	  | while_statement {$$ = $1;}
	  | print_statement TK_PuntoComma {$$ = $1;}
	  | scanf_statement TK_PuntoComma	
          | assign_statement TK_PuntoComma {$$ = $1;}
	  | producce_statement {$$ = $1;}
	  | for_statement {$$ = $1;}
	  | doWhile_statement TK_PuntoComma {$$ = $1;}
	  | declaration_statement TK_PuntoComma {$$ = $1;}
	  | funcion_statement {$$ =$1;}
	  | callFuncion_statement TK_PuntoComma{$$ = $1;}
;


callFuncion_statement : TK_VarNombre TK_left_par optionalParameter TK_rigth_par {$$ = new CallFuncionStatement($1,$3);}
;
optionalParameter:arg_list {$$ = $1;}
		| {$$ = NULL;}
;
declaration_statement: Type TK_VarNombre TK_left_corchete  expr TK_rigth_corchete optionalAssign {$$ = new DecArrayStatement($1,$2,$4,$6);}	
	              |Type TK_Op_mul TK_VarNombre optionalAssign {$$ = new DecApuntadorStatement($1,$3,$4);}
 		      |Type TK_VarNombre optionalAssign {$$ = new DecVariableStatement($1,$2,$3);}
		      
; 
funcion_statement:Type TK_VarNombre TK_left_par optparametroList TK_rigth_par opt_eols optionalBlock {$$ = new Funcion_Statement($1,$2,$4,$7);}
		 |Type TK_Op_mul TK_VarNombre TK_left_par optparametroList TK_rigth_par opt_eols optionalBlock {if($1 == "int")
		  $$ = new Funcion_Statement("int*",$3,$5,$8);else $$ = new Funcion_Statement("char*",$3,$5,$8);}	
		  
;

producce_statement : TK_Void TK_VarNombre TK_left_par optparametroList TK_rigth_par opt_eols optionalBlock {
			$$ = new Producer_Statement($2,$4,$7);}
;

optparametroList : parametroList { $$ = $1;}
		 | {$$ = NULL;}
;
parametroList:parametroList TK_Comma parametro {$$ = $1; ((Parametros*)$$)->addParametro($3);}
	     |parametro { $$ = new Parametros();((Parametros*)$$)->addParametro($1);}
;

parametro: Type TK_VarNombre { $$ = new Parametro($1,new DecVariableStatement($1,$2,NULL));}
	 | Type TK_Op_mul TK_VarNombre { const char * tipo = $1 == "int"? "int*":"char*"; 
	   $$ = new Parametro(tipo, new DecApuntadorStatement($1,$3,NULL)); }
	 | Type TK_VarNombre TK_left_corchete optionalExpr TK_rigth_corchete  { const char * tipo = $1 == "int"? "int[]":"char[]";
           $$ = new Parametro(tipo,new DecArrayStatement($1,$2,$4,NULL)); }
;
optionalExpr:expr {$$ = $1;}
	     | {$$ = new NumberExpr(0);}
;

optionalBlock:BlockStatementFuncion {$$ = $1;}
	     |TK_PuntoComma {$$ = NULL;}
;
BlockStatementFuncion : TK_left_llave opt_eols statementListFuncion opt_eols TK_rigth_llave  { $$ = $3;}
;

statementListFuncion:statementListFuncion  opt_eols statementFuncion  {$$ = $1; ((BlockStatement*)$$)->addStatement($3);}	    
			 |statementFuncion { $$ = new BlockStatement(); ((BlockStatement*)$$)->addStatement($1);}
;

statementFuncion : if_statement {$$ = $1;}
	  | while_statement {$$ = $1;}
	  | print_statement TK_PuntoComma {$$ = $1;}
	  | scanf_statement TK_PuntoComma	
          | assign_statement TK_PuntoComma {$$ = $1;}
	  | for_statement {$$ = $1;}
	  | doWhile_statement TK_PuntoComma {$$ = $1;}
	  | declaration_statement TK_PuntoComma {$$ = $1;}
	  | callFuncion_statement TK_PuntoComma{$$ = $1;}
	  | return_statement TK_PuntoComma {$$ = $1;}
;


return_statement :TK_Return expr {$$ = new Return_Statement($2);}
	
;
optionalAssign :TK_Asignacion expr %dprec 1 {$$ = $2;}
		|TK_Asignacion TK_String %dprec 3 { $$ = new StringExpr($2);}
		|TK_Asignacion TK_left_llave arg_list TK_rigth_llave %dprec 2 {$$ = new ArrayExpr($3);}		
		| %dprec 4 {$$ = NULL;}
;

Type: TK_Int { $$ = "int"; }
     |TK_Char  {  $$ =  "char"; }
;
for_statement: TK_For TK_left_par opt_eols for_assign opt_eols TK_PuntoComma opt_eols expr opt_eols TK_PuntoComma opt_eols expr opt_eols TK_rigth_par opt_eols BlockStatementOrStatement { $$ = new For_Statement($4,$8,$12,$16);};
;
for_assign : assign_statement %dprec 2 { $$  = $1; }
	   |  %dprec 1 {$$ = NULL;}
;

if_statement :TK_IF TK_left_par expr TK_rigth_par eols BlockStatementOrStatement TK_EOL TK_Else TK_EOL BlockStatementOrStatement %dprec 1 {$$ = new If_Statement($3,$6,$10);}
             |TK_IF TK_left_par expr TK_rigth_par eols BlockStatementOrStatement %dprec 2 {$$ = new If_Statement($3,$6,NULL);}
	     
; 

while_statement : TK_While TK_left_par expr TK_rigth_par opt_eols BlockStatementOrStatement {$$ = new While_Statement($3,$6);}
;

doWhile_statement  : TK_Do opt_eols BlockStatementOrStatement opt_eols TK_While TK_left_par expr TK_rigth_par  {$$ = new DoWhile_Statement($7,$3);}
;

BlockStatementOrStatement: statement { $$ = new BlockStatement(); ((BlockStatement*)$$)->addStatement($1);}
			 |  TK_left_llave opt_eols statementList opt_eols TK_rigth_llave  { $$ = $3;}	
;
 

	
print_statement : TK_Print TK_left_par TK_String TK_Comma arg_list TK_rigth_par { $$ = new PrintStatement($3,$5);}
		|TK_Print TK_left_par TK_String TK_rigth_par { $$ = new PrintStatement($3,NULL);}
		
;

scanf_statement :TK_Scanf TK_left_par TK_String TK_Comma arg_list TK_rigth_par { $$ = new ScanfStatement($3,$5);}
		|TK_Scanf TK_left_par TK_String TK_rigth_par { $$ = new ScanfStatement($3,NULL);}		
;


arg_list: arg_list TK_Comma expr { $$ = $1;$$->push_back($3); }
	| expr { $$ = new ExprList; $$->push_back($1); }
;



assign_statement : TK_VarNombre opAssignStatement expr { $$ = $2; ((AssignStatement*)$$)->nombre = new VarNombreExpr($1);
		 ((AssignStatement*)$$)->expr1 = $3;}
		 | TK_VarNombre TK_left_corchete  expr TK_rigth_corchete  opAssignStatement expr{ 
                 $$ = $5;((AssignStatement*)$$)->nombre = new VarNombreArrayExpr($1,$3); ((AssignStatement*)$$)->expr1 = $6; }
		 | TK_Refenciacion TK_VarNombre opAssignStatement expr  { 
	    	 $$ = $3; ((AssignStatement*)$$)->nombre = new ReferenciaExpr(new VarNombreExpr($2)); ((AssignStatement*)$$)->expr1 = $4; }
		 | TK_Op_mul TK_VarNombre opAssignStatement expr  { 
	    	 $$ = $3; ((AssignStatement*)$$)->nombre = new DesferenciaExpr(new VarNombreExpr($2)); ((AssignStatement*)$$)->expr1 = $4; }
;
	
opAssignStatement : TK_Asignacion {$$ = new AsignarStatement(NULL,NULL);}
	 | TK_AutoAdd {$$ = new MasIgualStatement(NULL,NULL); }
	 | TK_AutoSub {$$ = new MenosIgualStatement(NULL,NULL);}
 	 | TK_AutoMul {$$ = new MultIgualStatement(NULL,NULL);}
	 | TK_AutoDiv {$$ = new DivIgualStatement(NULL,NULL);}
	 | TK_AutoMod {$$ = new ModIgualStatement(NULL,NULL);}
	 | TK_AsigOrBit {$$ = new OrBitIgualStatement(NULL,NULL);}
	 | TK_AsigAndBit {$$ = new AndBitIgualStatement(NULL,NULL);}
	 | TK_AsigXorBit {$$ = new XorBitIgualStatement(NULL,NULL);}
	 | TK_AsigCorIzq {$$ = new AsigCorIzqIgualStatement(NULL,NULL);}
	 | TK_AsigCorDer {$$ = new AsigCorDerIgualStatement(NULL,NULL);}
;

eols:eols TK_EOL
     |TK_EOL 
;
opt_eols:opt_eols TK_EOL 
	|
;

ternario:conditional TK_Interogaccion expr TK_DosPuntos expr { $$ = new TernarioExpr($1,$3,$5); }
        |andOr  {$$ = $1;}
;


assignExpr : TK_VarNombre opAssign expr { $$ = $2; ((AssignExpr*)$$)->nombre = new VarNombreExpr($1); ((AssignExpr*)$$)->expr1 = $3; }
	    | TK_VarNombre TK_left_corchete  expr TK_rigth_corchete  opAssign expr { 
            $$ = $5;((AssignExpr*)$$)->nombre = new VarNombreArrayExpr($1,$3); ((AssignExpr*)$$)->expr1 = $6; }
	    | TK_Refenciacion TK_VarNombre opAssign expr  { 
	    $$ = $3; ((AssignExpr*)$$)->nombre = new ReferenciaExpr(new VarNombreExpr($2)); ((AssignExpr*)$$)->expr1 = $3; }
	    | TK_Op_mul TK_VarNombre opAssign expr  { 
	    $$ = $3; ((AssignExpr*)$$)->nombre = new DesferenciaExpr(new VarNombreExpr($2)); ((AssignExpr*)$$)->expr1 = $3; }
;
opAssign : TK_Asignacion {$$ = new AsignarExpr(NULL,NULL);}
	 | TK_AutoAdd {$$ = new MasIgualExpr(NULL,NULL); }
	 | TK_AutoSub {$$ = new MenosIgualExpr(NULL,NULL);}
 	 | TK_AutoMul {$$ = new MultIgualExpr(NULL,NULL);}
	 | TK_AutoDiv {$$ = new DivIgualExpr(NULL,NULL);}
	 | TK_AutoMod {$$ = new ModIgualExpr(NULL,NULL);}
	 | TK_AsigOrBit {$$ = new OrBitIgualExpr(NULL,NULL);}
	 | TK_AsigAndBit {$$ = new AndBitIgualExpr(NULL,NULL);}
	 | TK_AsigXorBit {$$ = new XorBitIgualExpr(NULL,NULL);}
	 | TK_AsigCorIzq {$$ = new AsigCorIzqIgualExpr(NULL,NULL);}
	 | TK_AsigCorDer {$$ = new AsigCorDerIgualExpr(NULL,NULL);}
;

expr : assignExpr  {$$ = $1;}
	|ternario  {$$ = $1;}
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
       | TK_VarNombre TK_left_par optionalParameter TK_rigth_par {$$ = new FuncionExpr($1,$3);}
       | TK_NUMERO { $$ = new NumberExpr($1);}
       | TK_CharLit { $$ = new CharExpr($1);}
       | TK_VarNombre TK_left_corchete  expr TK_rigth_corchete {$$  = new VarNombreArrayExpr($1,$3);}
       | TK_left_par expr TK_rigth_par { $$ = $2;}      
;
