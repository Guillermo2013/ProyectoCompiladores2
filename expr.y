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
%type <statement_t> statementListFuncion statementFuncion BlockStatementFuncion return_statement declarationList incremente_statement
%type <statement_t> inputStatementFuncion inputStatement multiDeclaration uniMultideclaration multideclarationImput incrementopt
%type <exprlist_t> arg_list optionalParameter

%%

inputs :opt_eols  inputStatement opt_eols {$2->ValidateSemantic();}  
;

statementList:statementList  opt_eols statement %dprec 2 {$$ = $1; ((BlockStatement*)$$)->addStatement($3);}
	     |statement %dprec 1 { $$ = new BlockStatement(); ((BlockStatement*)$$)->addStatement($1);}
;
declarationList:declarationList  opt_eols declaration_statement TK_PuntoComma %dprec 2	 {$$ = $1; ((BlockStatement*)$$)->addStatement($3);}
	     |declaration_statement TK_PuntoComma %dprec 1 { $$ = new BlockStatement(); ((BlockStatement*)$$)->addStatement($1);}
;

inputStatement: declarationList opt_eols statementList %dprec 2 {$$ = $1; ((BlockStatement*)$$)->addStatement($3);}
		| statementList %dprec 1 {$$ = $1;}
;

statement : if_statement %dprec 1 {$$ = $1;}
	  | while_statement %dprec 2 {$$ = $1;}
	  | print_statement TK_PuntoComma %dprec 3 {$$ = $1;}
	  | scanf_statement TK_PuntoComma %dprec 4 {$$ = $1;}	
          | assign_statement TK_PuntoComma %dprec 5 {$$ = $1;}
	  | producce_statement %dprec 6 {$$ = $1;}
	  | for_statement %dprec 7 {$$ = $1;}
	  | doWhile_statement TK_PuntoComma %dprec 8 {$$ = $1;}
	  | funcion_statement %dprec 9{$$ =$1;}
	  | callFuncion_statement TK_PuntoComma %dprec 10{$$ = $1;}
	  | incremente_statement TK_PuntoComma %dprec 11 {$$ = $1;}
;


incremente_statement:TK_Incremento TK_VarNombre TK_left_corchete  expr TK_rigth_corchete {
			$$ = new PreIncrementoStatement(new VarNombreArrayExpr($2,$4));}
		    | TK_Decremento TK_VarNombre TK_left_corchete  expr TK_rigth_corchete  {
			$$ = new PreDecrementoStatement(new VarNombreArrayExpr($2,$4));}
		    |  TK_VarNombre TK_left_corchete  expr TK_rigth_corchete TK_Decremento  {
			$$ = new PosDecrementoStatement(new VarNombreArrayExpr($1,$3));}	
		    |  TK_VarNombre TK_left_corchete  expr TK_rigth_corchete TK_Incremento {
			$$ = new PosIncrementoStatement(new VarNombreArrayExpr($1,$3));}	
		    |  TK_VarNombre TK_Decremento {$$ = new PosDecrementoStatement(new VarNombreExpr($1));}	
		    |  TK_VarNombre TK_Incremento {$$ = new PosIncrementoStatement(new VarNombreExpr($1));}
		    |  TK_Decremento TK_VarNombre {$$ = new PreDecrementoStatement(new VarNombreExpr($2));}	
		    |  TK_Incremento TK_VarNombre {$$ = new PreIncrementoStatement(new VarNombreExpr($2));}	
;


callFuncion_statement : TK_VarNombre TK_left_par optionalParameter TK_rigth_par {$$ = new CallFuncionStatement($1,$3);}
;
optionalParameter:arg_list %dprec 2 {$$ = $1;}
		| %dprec 1 {$$ = NULL;}
;
declaration_statement: Type TK_VarNombre TK_left_corchete  expr TK_rigth_corchete optionalAssign multideclarationImput {
			$$ = new DecArrayStatement($1,$2,$4,$6,$7);}	
	              |Type TK_Op_mul TK_VarNombre optionalAssign multideclarationImput {$$ = new DecApuntadorStatement($1,$3,$4,$5);}
 		      |Type TK_VarNombre optionalAssign multideclarationImput {$$ = new DecVariableStatement($1,$2,$3,$4);}
		      
; 

multideclarationImput:TK_Comma multiDeclaration {$$ = $2;}
			| { $$ = NULL;}
;
multiDeclaration: multiDeclaration TK_Comma uniMultideclaration %dprec 1 {$$ = $1; ((BlockStatement*)$$)->addStatement($3);}
		|  uniMultideclaration %dprec 2 {$$ = new BlockStatement(); ((BlockStatement*)$$)->addStatement($1);}

;
uniMultideclaration  :TK_VarNombre TK_left_corchete  expr TK_rigth_corchete optionalAssign {$$ = new DecArrayStatement(NULL,$1,$3,$5,NULL);}	
	             | TK_Op_mul TK_VarNombre optionalAssign {$$ = new DecApuntadorStatement(NULL,$2,$3,NULL);}
 		     | TK_VarNombre optionalAssign {$$ = new DecVariableStatement(NULL,$1,$2,NULL);}
 
;
funcion_statement:Type TK_VarNombre TK_left_par optparametroList TK_rigth_par opt_eols optionalBlock {$$ = new Funcion_Statement($1,$2,$4,$7);}
		 |Type TK_Op_mul TK_VarNombre TK_left_par optparametroList TK_rigth_par opt_eols optionalBlock {if($1 == "int")
		  $$ = new Funcion_Statement("int*",$3,$5,$8);else $$ = new Funcion_Statement("char*",$3,$5,$8);}	
		  
;

producce_statement : TK_Void TK_VarNombre TK_left_par optparametroList TK_rigth_par opt_eols optionalBlock {
			$$ = new Producer_Statement($2,$4,$7);}
;

optparametroList : parametroList %dprec 2 { $$ = $1;}
		 | %dprec 1 {$$ = NULL;}
;
parametroList:parametroList TK_Comma parametro %dprec 2 {$$ = $1; ((Parametros*)$$)->addParametro($3);}
	     |parametro %dprec 1 { $$ = new Parametros();((Parametros*)$$)->addParametro($1);}
;

parametro: Type TK_VarNombre { $$ = new Parametro($1,new DecVariableStatement($1,$2,NULL,NULL));}
	 | Type TK_Op_mul TK_VarNombre { const char * tipo = $1 == "int"? "int*":"char*"; 
	   $$ = new Parametro(tipo, new DecApuntadorStatement($1,$3,NULL,NULL)); }
	 | Type TK_VarNombre TK_left_corchete optionalExpr TK_rigth_corchete  { const char * tipo = $1 == "int"? "int[]":"char[]";
           $$ = new Parametro(tipo,new DecArrayStatement($1,$2,$4,NULL,NULL)); }
;
optionalExpr:expr %dprec 2 {$$ = $1;}
	     | %dprec 1 {$$ = new NumberExpr(0);}
;

optionalBlock:BlockStatementFuncion %dprec 2 {$$ = $1;}
	     |TK_PuntoComma %dprec 1 {$$ = NULL;}
;
BlockStatementFuncion : TK_left_llave opt_eols inputStatementFuncion opt_eols TK_rigth_llave  { $$ = $3;}
;

inputStatementFuncion :declarationList 	opt_eols statementListFuncion %dprec 2 {$$ = $1; ((BlockStatement*)$$)->addStatement($3);}
		      |statementListFuncion %dprec 1 {$$ = $1;}
		      
;
statementListFuncion:statementListFuncion  opt_eols statementFuncion %dprec 2 {$$ = $1; ((BlockStatement*)$$)->addStatement($3);}	    
	            |statementFuncion %dprec 1{ $$ = new BlockStatement(); ((BlockStatement*)$$)->addStatement($1);}
;

statementFuncion : if_statement {$$ = $1;}
	  | while_statement {$$ = $1;}
	  | print_statement TK_PuntoComma {$$ = $1;}
	  | scanf_statement TK_PuntoComma {$$ = $1;}	 
          | assign_statement TK_PuntoComma {$$ = $1;}
	  | for_statement {$$ = $1;}
	  | doWhile_statement TK_PuntoComma {$$ = $1;}
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

BlockStatementOrStatement: statement %dprec 1 { $$ = new BlockStatement(); ((BlockStatement*)$$)->addStatement($1);}
			 |  TK_left_llave opt_eols statementList opt_eols TK_rigth_llave %dprec 2 { $$ = $3;}	
;
 

	 
print_statement : TK_Print TK_left_par TK_String TK_Comma arg_list TK_rigth_par %dprec 2 { $$ = new PrintStatement($3,$5);}
		|TK_Print TK_left_par TK_String TK_rigth_par %dprec 1 { $$ = new PrintStatement($3,NULL);}
		
;

scanf_statement :TK_Scanf TK_left_par TK_String TK_Comma arg_list TK_rigth_par %dprec 1 { $$ = new ScanfStatement($3,$5);}
		|TK_Scanf TK_left_par TK_String TK_rigth_par %dprec 1 { $$ = new ScanfStatement($3,NULL);}		
;


arg_list: arg_list TK_Comma expr %dprec 2 { $$ = $1;$$->push_back($3); }
	| expr %dprec 2 { $$ = new ExprList; $$->push_back($1); }
;



assign_statement : TK_VarNombre  opAssignStatement expr { $$ = $2; ((AssignStatement*)$$)->nombre = new VarNombreExpr($1);
		 ((AssignStatement*)$$)->expr1 = $3;}
		 | TK_VarNombre TK_left_corchete  expr TK_rigth_corchete opAssignStatement expr{ 
                 $$ = $5;((AssignStatement*)$$)->nombre = new VarNombreArrayExpr($1,$3); ((AssignStatement*)$$)->expr1 = $6; }
		 | TK_Refenciacion TK_VarNombre opAssignStatement expr  { 
	    	 $$ = $3; ((AssignStatement*)$$)->nombre = new ReferenciaExpr(new VarNombreExpr($2)); ((AssignStatement*)$$)->expr1 = $4; }
		 | TK_Op_mul TK_VarNombre incrementopt opAssignStatement expr  {$$ = new BlockStatement(); 
		((AssignStatement*)$4)->nombre = new DesferenciaExpr(new VarNombreExpr($2)); ((AssignStatement*)$4)->expr1 = $5;
		((BlockStatement*)$$)->addStatement($3); if($3 !=NULL){ ((PreIncrementoStatement*)$3)->expr1 = new VarNombreExpr($2); 
		((BlockStatement*)$$)->addStatement($4);} }
;

incrementopt :TK_Incremento {$$ = new PosIncrementoStatement(NULL); }
	    |TK_Decremento {$$ = new PosDecrementoStatement(NULL);}
	    | {$$ = NULL;}
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

ternario:conditional TK_Interogaccion expr TK_DosPuntos expr %dprec 2 { $$ = new TernarioExpr($1,$3,$5); }
        |andOr  %dprec 1 {$$ = $1;}
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

expr : assignExpr  %dprec 1 {$$ = $1;}
	|ternario  %dprec 2 {$$ = $1;}
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
conditional: conditional TK_Igual corrimiento %dprec 1 {$$ = new IgualExpr($1,$3);}
	     |conditional TK_Distinto corrimiento %dprec 2 {$$ = new DistintoExpr($1,$3);}
	     |conditional TK_Menor corrimiento %dprec 3 {$$ = new MenorExpr($1,$3);}
	     |conditional TK_Mayor corrimiento %dprec 4 {$$ = new MayorExpr($1,$3);}
	     |conditional TK_MenorIgual corrimiento %dprec 5 {$$ = new MenorIgualExpr($1,$3);}
	     |conditional TK_MayorIgual corrimiento %dprec 6 {$$ = new MayorIgualExpr($1,$3);}
	     |corrimiento  %dprec 7{$$ = $1;}
;
corrimiento: corrimiento TK_CorrimientoIzq add %dprec 1 {$$ = new CorrimientoIzqExpr($1,$3);}
	    |corrimiento TK_CorrimientoDer add %dprec 2 {$$ = new CorrimientoDerExpr($1,$3);}
            |add %dprec 3 {$$ = $1;}
;
add :  add TK_Op_add term %dprec 1 { $$ = new AddExpr($1,$3);}
      | add TK_Op_sub term %dprec 2 { $$ = new SubExpr($1,$3);}
      | term %dprec 3 { $$ = $1;}
;

term :  term TK_Op_mul unary %dprec 1 { $$ = new MultExpr($1,$3);}
      | term TK_Op_div unary %dprec 2 { $$ = new DivExpr($1,$3);}
      | term TK_Modulo unary %dprec 3 { $$ = new ModExpr($1,$3);}
      | unary %dprec 4 { $$ = $1;}
;

unary : TK_Negarcion expr %dprec 1 {$$ = new NegacionExpr($2);}
      | TK_Complemento expr %dprec 2 {$$ = new ComplementoExpr($2);}
      | TK_Op_mul TK_VarNombre %dprec 3 {$$ = new DesferenciaExpr(new VarNombreExpr($2));}
      | TK_Op_mul TK_left_par TK_VarNombre TK_rigth_par %dprec 4 {$$ = new DesferenciaExpr(new VarNombreExpr($3));}
      | TK_Refenciacion TK_VarNombre %dprec 5 {$$ = new ReferenciaExpr(new VarNombreExpr($2));}
      | TK_Refenciacion TK_left_par TK_VarNombre TK_rigth_par %dprec 6 {$$ = new ReferenciaExpr(new VarNombreExpr($3));}
      | TK_Incremento TK_VarNombre %dprec 7 {$$ = new PreIncrementoExpr(new VarNombreExpr($2));}
      | TK_Incremento TK_left_par TK_VarNombre TK_rigth_par %dprec 8 {$$ = new PreIncrementoExpr(new VarNombreExpr($3));}
      | TK_Decremento TK_VarNombre %dprec 9 {$$ = new PreDecrementoExpr(new VarNombreExpr($2));}
      | TK_Decremento TK_left_par TK_VarNombre TK_rigth_par %dprec 10 {$$ = new PreDecrementoExpr(new VarNombreExpr($3));}
      | TK_VarNombre TK_Incremento %dprec 11 {$$ = new PosIncrementoExpr(new VarNombreExpr($1));}
      | TK_left_par TK_VarNombre TK_rigth_par TK_Incremento %dprec 12 {$$ = new PosIncrementoExpr(new VarNombreExpr($2));}
      | TK_VarNombre TK_Decremento %dprec 13 {$$ = new PosDecrementoExpr(new VarNombreExpr($1));}
      | TK_left_par TK_VarNombre TK_rigth_par TK_Decremento %dprec 14 {$$ = new PosDecrementoExpr(new VarNombreExpr($2));}
      | factor %dprec 15{$$ = $1;}

;
	
factor: TK_VarNombre {  $$ = new VarNombreExpr($1);}
       | TK_VarNombre TK_left_par optionalParameter TK_rigth_par {$$ = new FuncionExpr($1,$3);}
       | TK_NUMERO { $$ = new NumberExpr($1);}
       | TK_CharLit { $$ = new CharExpr($1);}
       | TK_VarNombre TK_left_corchete  expr TK_rigth_corchete {$$  = new VarNombreArrayExpr($1,$3);}
       | TK_left_par expr TK_rigth_par { $$ = $2;}      
;
