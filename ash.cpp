	#include "ash.h"
#include <stdio.h>

#include <stdlib.h>
#include <string>
#include <sstream>

typedef pair<char *, int> elemento;
StackContenido *stack = new StackContenido();


map<string, bool> TemporalesMaps ({
		{"$t0", false}, 
		{"$t1", false}, 
		{"$t2", false}, 
		{"$t3", false},
		{"$t4", false},
		{"$t5", false},
		{"$t6", false},
		{"$t7", false},
		{"$t8", false},
		{"$t9", false}

});
int cantidadLTE =0;
int cantidadGTE =0;
int cantidadEQ =0;
int cantidadInput =0;
int cantidadIf =0;
int cantidadWhile =0;
int cantidadDoWhile =0;
int cantidadFor =0;
int cantidadMsg =0;
int cantidadOr =0;
int cantidadAnd = 0;
int cantidadternario = 0;
int cantidadNegacion = 0;
int cantidadFunciones = 0;
bool enFuncion = false;
int sp_val = 4;
string salvar = " ";
string guardar = " ";
string data="#include \"screen.h\"\n #include \"system.h\"\n.global clean\n.data\n";


string NewTemp() {
		std::map<string, bool>::iterator it=TemporalesMaps.begin();
		while (it!=TemporalesMaps.end()){
				if(!it->second) {
						TemporalesMaps[it->first] = true;
						if(it->first.empty())
							return NewTemp();
						return it->first;
				}
	it++;
		 }
}

void freeTemp(string temporal) {
		if(TemporalesMaps[temporal])
				TemporalesMaps[temporal] = false;
}

vector<string> split(char *phrase){
    vector<string> list;
    string s = string(phrase);
    int pos = 0;
    string token;
    while ((pos = s.find("%d")) != string::npos || (pos = s.find("%c")) != string::npos) {
        token = s.substr(0, pos);
        list.push_back(token);
        s.erase(0, pos + 2);
    }
    list.push_back(s);
    return list;
}


void DesferenciaExpr::generalCodigo(CodigoGenerado * codigo){}
void ReferenciaExpr::generalCodigo(CodigoGenerado * codigo){}
void Parametros::generalCodigo(CodigoGenerado * codigo){}
void Parametro::generalCodigo(CodigoGenerado * codigo){}
void ArrayExpr::generalCodigo(CodigoGenerado * codigo){}

Tipo* ArrayExpr :: ValidateSemantic(){
	ExprList::iterator it = value->begin();
		Expr * primero = *it;
		while (it != value->end()) {
			Expr * st = *it;
			 if(!st->ValidateSemantic()->isA(primero->ValidateSemantic()->getKind())||st->ValidateSemantic()->isA(arrayTipo)||
				st->ValidateSemantic()->isA(apuntadorTipo)){
				 cout<< "Error : arreglo de diferentes tipos linea o un apuntado o un arreglo " << yylineno <<  endl;
				 exit(0);
			 }
			 it++;
		}
		return new ArrayTipo(primero->ValidateSemantic());
}

Tipo* TernarioExpr :: ValidateSemantic(){
	
	if(!expr1->ValidateSemantic()->isA(expr2->ValidateSemantic()->getKind())){
				 cout<< "Error : expresiones diferentes ternario linea " << yylineno <<  endl;
				 exit(0);
		}

		return expr1->ValidateSemantic();
}

Tipo* VarNombreExpr:: ValidateSemantic(){
	list<TablaSimbolos*>::iterator it = stack->Stack.begin();
	while (it != stack->Stack.end()) {
		TablaSimbolos * st = *it;
		 if(st->VariableExist(index)){
				return st->GetVariable(index);
		 }
		 it++;
	}
	cout<< "Error : variable no existe "<< index << " linea "<< yylineno<<endl;
 exit(0);
}
Tipo* VarNombreArrayExpr :: ValidateSemantic(){
	
	if(!expr1->ValidateSemantic()->isA(intTipo))
	{
		cout<< "Error : la expresion tiene que se un int linea " <<yylineno << endl;
	exit(0);
	}
	list<TablaSimbolos*>::iterator it = stack->Stack.begin();
	while (it != stack->Stack.end()) {
		TablaSimbolos * st = *it;
		 if(st->VariableExist(index)){
				if(st->GetVariable(index)->isA(arrayTipo)){
					return ((ArrayTipo*)st->GetVariable(index))->tipoArray;
				}else{
					cout<< "Error : la variable no es un arreglo linea "<< index << yylineno <<  endl;
					exit(0);
				}
		 }
		 it++;
	}
	cout<< "Error : variable no existe   "<<index <<" linea "<< yylineno << endl;
	exit(0);
}

#define IMPLEMENT_BINARY_COMP_SEMANTIC(name) \
	Tipo* name##Expr::ValidateSemantic(){ \
	return new IntTipo(); \
}

IMPLEMENT_BINARY_COMP_SEMANTIC(Igual);
IMPLEMENT_BINARY_COMP_SEMANTIC(Distinto);
IMPLEMENT_BINARY_COMP_SEMANTIC(Mayor);
IMPLEMENT_BINARY_COMP_SEMANTIC(Menor);
IMPLEMENT_BINARY_COMP_SEMANTIC(MayorIgual);
IMPLEMENT_BINARY_COMP_SEMANTIC(MenorIgual);


#define IMPLEMENT_BINARY_EXPR_SEMANTIC(name) \
	Tipo* name##Expr::ValidateSemantic(){ \
		Tipo * valor = expr1->ValidateSemantic();\
	if(valor->isA(arrayTipo) || expr2->ValidateSemantic()->isA(arrayTipo)||\
		valor->isA(procedimientoTipo) || expr2->ValidateSemantic()->isA(procedimientoTipo)){\
		cout<< "Error : no se puede realizar operaciones con arreglos o con funciones void linea "<< yylineno <<  endl;\
		exit(0);\
	}\
	return valor; \
}

IMPLEMENT_BINARY_EXPR_SEMANTIC(Add);
IMPLEMENT_BINARY_EXPR_SEMANTIC(Sub);
IMPLEMENT_BINARY_EXPR_SEMANTIC(Mult);
IMPLEMENT_BINARY_EXPR_SEMANTIC(Div);
IMPLEMENT_BINARY_EXPR_SEMANTIC(Or);
IMPLEMENT_BINARY_EXPR_SEMANTIC(And);
IMPLEMENT_BINARY_EXPR_SEMANTIC(Mod);
IMPLEMENT_BINARY_EXPR_SEMANTIC(CorrimientoIzq);
IMPLEMENT_BINARY_EXPR_SEMANTIC(CorrimientoDer);
IMPLEMENT_BINARY_EXPR_SEMANTIC(OPorBit);
IMPLEMENT_BINARY_EXPR_SEMANTIC(ExclPorBit);
IMPLEMENT_BINARY_EXPR_SEMANTIC(YPorBit);

#define IMPLEMENT_BINARY_EXPR_SEMANTIC2(name) \
	Tipo* name##Expr::ValidateSemantic(){ \
		Tipo * valor = nombre->ValidateSemantic();\
	if(valor->isA(arrayTipo) || expr1->ValidateSemantic()->isA(arrayTipo)||\
		valor->isA(procedimientoTipo) || expr1->ValidateSemantic()->isA(procedimientoTipo)){\
		cout<< "Error : no se puede realizar operaciones con arreglos o con funciones void linea "<< yylineno <<  endl;\
		exit(0);\
	}\
	return valor; \
}
IMPLEMENT_BINARY_EXPR_SEMANTIC2(MasIgual);
IMPLEMENT_BINARY_EXPR_SEMANTIC2(MenosIgual);
IMPLEMENT_BINARY_EXPR_SEMANTIC2(MultIgual);
IMPLEMENT_BINARY_EXPR_SEMANTIC2(DivIgual);
IMPLEMENT_BINARY_EXPR_SEMANTIC2(ModIgual);
IMPLEMENT_BINARY_EXPR_SEMANTIC2(OrBitIgual);
IMPLEMENT_BINARY_EXPR_SEMANTIC2(AndBitIgual);
IMPLEMENT_BINARY_EXPR_SEMANTIC2(XorBitIgual);
IMPLEMENT_BINARY_EXPR_SEMANTIC2(AsigCorIzqIgual);
IMPLEMENT_BINARY_EXPR_SEMANTIC2(AsigCorDerIgual);


Tipo* DesferenciaExpr :: ValidateSemantic(){
	Tipo * tipo = expr1->ValidateSemantic();
		if(tipo->isA(apuntadorTipo))
			return ((ApuntadorTipo*)tipo)->tipoApuntador;
		else if(tipo->isA(arrayTipo))
			return ((ArrayTipo*)tipo)->tipoArray; 
		cout<< "Error : la variable no es un apuntador linea " << yylineno << endl;\
		exit(0);\

}
#define IMPLEMENT_BINARY_INC_SEMANTIC(name) \
	Tipo* name##Expr::ValidateSemantic(){ \
		Tipo * valor = expr1->ValidateSemantic();\
	if(valor->isA(funcionTipo) || expr1->ValidateSemantic()->isA(funcionTipo)||\
		valor->isA(procedimientoTipo) || expr1->ValidateSemantic()->isA(procedimientoTipo)){\
		cout<< "Error : no se puede realizar operaciones con  funciones  linea " << yylineno << endl;\
		exit(0);\
	}\
	return valor; }

IMPLEMENT_BINARY_INC_SEMANTIC(PreIncremento);
IMPLEMENT_BINARY_INC_SEMANTIC(PreDecremento);
IMPLEMENT_BINARY_INC_SEMANTIC(PosIncremento);
IMPLEMENT_BINARY_INC_SEMANTIC(PosDecremento);



Tipo* NegacionExpr :: ValidateSemantic(){

	 Tipo * valor = expr1->ValidateSemantic();
	if(valor->isA(procedimientoTipo) || expr1->ValidateSemantic()->isA(procedimientoTipo)){
		cout<< "Error : no se puede realizar operaciones con  funciones void linea "<< yylineno <<  endl;
		exit(0);
	}
	return valor; 
}
Tipo* ComplementoExpr :: ValidateSemantic(){
	
	 Tipo * valor = expr1->ValidateSemantic();
	if(valor->isA(arrayTipo) || expr1->ValidateSemantic()->isA(arrayTipo)||
		valor->isA(procedimientoTipo) || expr1->ValidateSemantic()->isA(procedimientoTipo)){
		cout<< "Error : no se puede realizar operaciones con  funciones void y arrays linea "<< yylineno <<  endl;
		exit(0);
	}
	return valor;
}
Tipo* AsignarExpr :: ValidateSemantic(){
	Tipo *v1 = nombre->ValidateSemantic();
	Tipo *v2 = expr1->ValidateSemantic();

	if(v1->isA(arrayTipo) || v2->isA(arrayTipo)||
		v1->isA(procedimientoTipo) || v2->isA(procedimientoTipo)){
		cout<< "Error : no se puede realizar operaciones con arreglos o con funciones void linea "<< yylineno <<  endl;\
		exit(0);
	 }
	 return v2;
}

Tipo* ReferenciaExpr :: ValidateSemantic(){
		Tipo *v1 = expr1->ValidateSemantic();
		return new IntTipo();

}

#define IMPLEMENT_ASSIGN_STATEMENT_SEMANTIC(name) \
	void name##Statement::ValidateSemantic(){ \
		Tipo * valor = nombre->ValidateSemantic();\
		Tipo * valor2 = expr1->ValidateSemantic();\
	if(valor->isA(arrayTipo) || valor2->isA(arrayTipo)||\
		valor->isA(procedimientoTipo) || valor2->isA(procedimientoTipo)){\
		cout<< "Error : no se puede realizar operaciones con arreglos o con funciones void linea "<< yylineno <<  endl;\
		exit(0);\
	 }\
}

IMPLEMENT_ASSIGN_STATEMENT_SEMANTIC(Asignar);
IMPLEMENT_ASSIGN_STATEMENT_SEMANTIC(MasIgual);
IMPLEMENT_ASSIGN_STATEMENT_SEMANTIC(MenosIgual);
IMPLEMENT_ASSIGN_STATEMENT_SEMANTIC(MultIgual);
IMPLEMENT_ASSIGN_STATEMENT_SEMANTIC(DivIgual);
IMPLEMENT_ASSIGN_STATEMENT_SEMANTIC(ModIgual);
IMPLEMENT_ASSIGN_STATEMENT_SEMANTIC(OrBitIgual);
IMPLEMENT_ASSIGN_STATEMENT_SEMANTIC(AndBitIgual);
IMPLEMENT_ASSIGN_STATEMENT_SEMANTIC(XorBitIgual);
IMPLEMENT_ASSIGN_STATEMENT_SEMANTIC(AsigCorIzqIgual);
IMPLEMENT_ASSIGN_STATEMENT_SEMANTIC(AsigCorDerIgual);

#define IMPLEMENT_INOUT_STATEMENT_SEMANTIC(name) \
void name##Statement :: ValidateSemantic(){\
	ExprList::iterator it = lista->begin();\
		while (it != lista->end()) {\
			Expr * st = *it;\
			 st->ValidateSemantic();\
			 it++;\
		}\
}
IMPLEMENT_INOUT_STATEMENT_SEMANTIC(Print);

void If_Statement :: ValidateSemantic(){
	if( expr->ValidateSemantic()->isA(arrayTipo)||  expr->ValidateSemantic()->isA(procedimientoTipo)){
		cout<< "Error : no se puede realizar operaciones con arreglos o con funciones void linea "<< yylineno <<  endl;
		exit(0);
	 }
	 if(stack->Stack.empty())
		stack->Stack.push_back(new TablaSimbolos());
	stack->Stack.push_back(new TablaSimbolos());
	if(ifStatement != NULL)
	ifStatement->ValidateSemantic();
	 stack->Stack.pop_back();
		stack->Stack.push_back(new TablaSimbolos());
	if(elseStatement != NULL)
	elseStatement->ValidateSemantic();
	stack->Stack.pop_back();
}
void While_Statement :: ValidateSemantic(){
	if( expr->ValidateSemantic()->isA(arrayTipo)||  expr->ValidateSemantic()->isA(procedimientoTipo)){
		cout<< "Error : no se puede realizar operaciones con arreglos o con funciones void linea "<< yylineno <<  endl;
		exit(0);
	 }
	 if(stack->Stack.empty())
		stack->Stack.push_back(new TablaSimbolos());
	stack->Stack.push_back(new TablaSimbolos());
	if(whileStatement != NULL)
	whileStatement->ValidateSemantic();
	 stack->Stack.pop_back();
}

void DoWhile_Statement :: ValidateSemantic(){
	if( expr->ValidateSemantic()->isA(arrayTipo)||  expr->ValidateSemantic()->isA(procedimientoTipo)){
		cout<< "Error : no se puede realizar operaciones con arreglos o con funciones void linea "<< yylineno <<  endl;
		exit(0);
	 }
	 if(stack->Stack.empty())
		stack->Stack.push_back(new TablaSimbolos());
 stack->Stack.push_back(new TablaSimbolos());
	if(DowhileStatement != NULL)
	DowhileStatement->ValidateSemantic();
	 stack->Stack.pop_back();
}

void BlockStatement :: ValidateSemantic(){
	list<Statement*>::iterator it = listStatement.begin();
		while (it != listStatement.end()) {
			Statement * st = *it;
			if(*it != NULL)
			 st->ValidateSemantic();
			 it++;
		}
}

void For_Statement :: ValidateSemantic(){
	inicializacion->ValidateSemantic();
	 if( condicional->ValidateSemantic()->isA(arrayTipo)||  condicional->ValidateSemantic()->isA(procedimientoTipo)||
		incremento->ValidateSemantic()->isA(arrayTipo)||  incremento->ValidateSemantic()->isA(procedimientoTipo)){
		cout<< "Error : no se puede realizar operaciones con arreglos o con funciones void linea "<< yylineno <<  endl;
		exit(0);
	 }

	 if(stack->Stack.empty())
		stack->Stack.push_back(new TablaSimbolos());
	 stack->Stack.push_back(new TablaSimbolos());
	if(ForStatement != NULL)
	ForStatement->ValidateSemantic();
	 stack->Stack.pop_back();
}


void DecArrayStatement :: ValidateSemantic(){

	if(stack->Stack.empty())
		stack->Stack.push_back(new TablaSimbolos());

	list<TablaSimbolos*>::iterator it = stack->Stack.begin();
	while (it != stack->Stack.end()) {
		TablaSimbolos * st = *it;
		 if(st->VariableExist(nombre)){
				 cout<< "Error : variable  existe "<< nombre <<" linea "<< yylineno << endl;
				exit(0);       
		 }
		 it++;
	}
 if( tam->ValidateSemantic()->isA(arrayTipo)|| tam->ValidateSemantic()->isA(procedimientoTipo)){
		cout<< "Error : no se puede reservar tamaño con arreglos o con funciones void linea "<< yylineno <<  endl;
		exit(0);
	 }
	 if(inicializar != NULL){
		if( !inicializar->ValidateSemantic()->isA(arrayTipo)){
			cout<< "Error : el arreglo no se inicializa de esa manera {expr} linea "<< yylineno <<  endl;
			exit(0);
		 }  
	 }
	 if(type == "int")
		 stack->Stack.back()->DeclareVariable(nombre,new ArrayTipo(new IntTipo()));
	 else
			stack->Stack.back()->DeclareVariable(nombre,new ArrayTipo(new CharTipo()));
		 if(multideclatation !=NULL){
	list<Statement*> multi = ((BlockStatement*)multideclatation)->listStatement;
	list<Statement*>::iterator it = multi.begin();
	 while (it != multi.end()) {
			Statement * st = *it;
			((DecVariableStatement*)st)->type = this->type;
			st->ValidateSemantic();
		it++;
		}
	 }
}
void DecApuntadorStatement :: ValidateSemantic(){

	if(stack->Stack.empty())
		stack->Stack.push_back(new TablaSimbolos());

	list<TablaSimbolos*>::iterator it = stack->Stack.begin();
	while (it != stack->Stack.end()) {
		TablaSimbolos * st = *it;
		 if(st->VariableExist(nombre)){
				cout<< "Error : variable  existe "<< nombre <<" linea "<< yylineno << endl;
				exit(0);       
		 }
		 it++;
	}

	if(inicializar != NULL){
		Tipo * v1 = inicializar->ValidateSemantic();
		if( v1->isA(procedimientoTipo)){
			cout<< "Error : no se puede asignar funciones tipo void o string a int "<< yylineno <<  endl;
			exit(0);
		 }
		 
	 }
	 if(type == "int")
		 stack->Stack.back()->DeclareVariable(nombre,new ApuntadorTipo(new IntTipo()));
	 else
			stack->Stack.back()->DeclareVariable(nombre,new ApuntadorTipo(new CharTipo()));
	 if(multideclatation !=NULL){
	list<Statement*> multi = ((BlockStatement*)multideclatation)->listStatement;
	list<Statement*>::iterator it = multi.begin();
	 while (it != multi.end()) {
			Statement * st = *it;
			((DecVariableStatement*)st)->type = this->type;
			st->ValidateSemantic();
		it++;
		}
	 }
}

void DecVariableStatement :: ValidateSemantic(){

	if(stack->Stack.empty())
		stack->Stack.push_back(new TablaSimbolos());

	list<TablaSimbolos*>::iterator it = stack->Stack.begin();
	while (it != stack->Stack.end()) {
		TablaSimbolos * st = *it;
		 if(st->VariableExist(nombre)){
				cout<< "Error : variable  existe "<< nombre <<" linea "<< yylineno << endl;
				
				exit(0);       
		 }
		 it++;
	}
	if(inicializar != NULL){
		Tipo *v1 = inicializar->ValidateSemantic();
	if(v1->isA(procedimientoTipo)
		||v1->isA(apuntadorTipo)
		||v1->isA(arrayTipo)
		||v1->isA(stringTipo)){
		cout<< "Error : no se puede asignar asignar tipo arreglo o funcion void o un string linea "<< yylineno <<  endl;
		exit(0);
	 }
 }
	 if(type == "int")
		 stack->Stack.back()->DeclareVariable(nombre,new IntTipo());
	 else
			stack->Stack.back()->DeclareVariable(nombre,new CharTipo()); 
	
 if(multideclatation !=NULL){
	list<Statement*> multi = ((BlockStatement*)multideclatation)->listStatement;
	list<Statement*>::iterator it = multi.begin();
	 while (it != multi.end()) {
			Statement * st = *it;
			((DecVariableStatement*)st)->type = this->type;
			st->ValidateSemantic();
			it++;
		}
	 } 
} 

void Funcion_Statement :: ValidateSemantic(){

	if(stack->Stack.empty())
		stack->Stack.push_back(new TablaSimbolos());

	list<TablaSimbolos*>::iterator it = stack->Stack.begin();
	while (it != stack->Stack.end()) {
		TablaSimbolos * st = *it;
		 if(st->VariableExist(nombre)){
				cout<< "Error : ya existe la funcion "<< nombre <<" linea "<< yylineno << endl;
			
				exit(0);       
		 }
		 it++;
	}
	
	list< Tipo* > *parametrosTipos = new list<Tipo*>;
	if(parametros != NULL){
	 
		list<Parametro*>::iterator it2 = ((Parametros*)parametros)->listParametro.begin();
		while (it2 != ((Parametros*)parametros)->listParametro.end()) {
		 
			parametrosTipos->push_back(((Parametro*)*it2)->ValidateSemantic());
			 it2++;
		}
	}

	 if(strcmp(type,"int")== 0)
		 stack->Stack.back()->DeclareVariable(nombre,new FuncionTipo(new IntTipo(),parametrosTipos));
	 else if(strcmp(type,"char")== 0)
			stack->Stack.back()->DeclareVariable(nombre,new FuncionTipo(new CharTipo(),parametrosTipos));
	 else if (strcmp(type,"int*")== 0)
			stack->Stack.back()->DeclareVariable(nombre,new FuncionTipo(new ApuntadorTipo(new IntTipo()),parametrosTipos));
	 else if(strcmp(type,"char*")==0 )
		stack->Stack.back()->DeclareVariable(nombre,new FuncionTipo(new ApuntadorTipo(new CharTipo()),parametrosTipos)); 

 stack->Stack.push_back(new TablaSimbolos());
	if(funcionStatement != NULL)
		funcionStatement->ValidateSemantic();
 stack->Stack.pop_back();
} 

void Producer_Statement :: ValidateSemantic(){

	if(stack->Stack.empty())
		stack->Stack.push_back(new TablaSimbolos());

	list<TablaSimbolos*>::iterator it = stack->Stack.begin();
	
	while (it != stack->Stack.end()) {
		TablaSimbolos * st = *it;
		 if(st->VariableExist(nombre)){
				 cout<< "Error : ya existe la funcion "<< nombre <<" linea" <<yylineno << endl;
				exit(0);       
		 }
		 it++;
	}
	
 list< Tipo* > *parametrosTipos = new list<Tipo*>;
	if(parametros != NULL){
	 
		list<Parametro*>::iterator it2 = ((Parametros*)parametros)->listParametro.begin();
		while (it2 != ((Parametros*)parametros)->listParametro.end()) {
		 
			parametrosTipos->push_back(((Parametro*)*it2)->ValidateSemantic());
			 it2++;
		}
	}
		 stack->Stack.back()->DeclareVariable(nombre,new ProcedimientoTipo(parametrosTipos));
	
	 stack->Stack.push_back(new TablaSimbolos());
	 if(producerStatement != NULL)
		producerStatement->ValidateSemantic();
	stack->Stack.pop_back();
}

Tipo* FuncionExpr :: ValidateSemantic(){
 list<TablaSimbolos*>::iterator it = stack->Stack.begin();
	bool exite = false;
	Tipo * tipo;
	while (it != stack->Stack.end()) {
		TablaSimbolos * st = *it;
		 if(st->VariableExist(nombre)){
			tipo = st->GetVariable(nombre); 
			if(!tipo->isA(funcionTipo)){
				cout<< "Error : no se puede usar la variable como una funcion "<< nombre <<" linea " <<yylineno << endl;
				exit(0);
			}
			exite = true;
		 }
		 it++;
		}
		 if(exite == false){
			 cout<< "Error : no existe la funcion  "<< nombre <<" linea" <<yylineno << endl;
				exit(0);
		 }
		/*if(parametros == NULL && ((FuncionTipo*)tipo)->parametros != NULL){
			 cout<< "Error :  parametros en la funcion "<< nombre <<" linea " <<yylineno << endl;
				exit(0);
		}else if(parametros->size() != ((FuncionTipo*)tipo)->parametros->size()){
			 cout<< "Error : demasiados o faltan parametros en la funcion a "<< nombre <<" linea " <<yylineno << endl;
				exit(0);
		}else if(parametros->size()>0){
		list<Expr*>::iterator itExpr = parametros->begin();
		list<Tipo*>::iterator itTipo =  ((FuncionTipo*)tipo)->parametros->begin();
		while(itExpr != parametros->end() && itTipo != ((FuncionTipo*)tipo)->parametros->end()){
			Expr * exprV1 = *itExpr;
			Tipo * tipoV1 = *itTipo;
			if((tipoV1->isA(charTipo) && exprV1->ValidateSemantic()->isA(intTipo))||
				(tipoV1->isA(intTipo) && exprV1->ValidateSemantic()->isA(charTipo)))
					;

			else if(!exprV1->ValidateSemantic()->isA(tipoV1->getKind())){
				cout<< "Error : no se puede enviar este tipo de parametros "<< nombre <<" linea " <<yylineno << endl;
				cout<<tipoV1->getKind()<<endl;
				cout<<exprV1->ValidateSemantic()->getKind()<<endl;
				exit(0);

			}
			itExpr++;
			itTipo++;
		}
	}*/
	return ((FuncionTipo*)tipo)->retorno;
}
void CallFuncionStatement :: ValidateSemantic(){
 list<TablaSimbolos*>::iterator it = stack->Stack.begin();
	bool exite = false;
	Tipo * tipo;

	while (it != stack->Stack.end()) {
		TablaSimbolos * st = *it;
		 if(st->VariableExist(nombre)){
			tipo = st->GetVariable(nombre); 
			if(!tipo->isA(funcionTipo)&&!tipo->isA(procedimientoTipo)){
				cout<< "Error : no se puede usar la variable como una funcion "<< nombre <<" linea " <<yylineno << endl;
				exit(0);
			}
			exite = true;
		 }
		 it++;
		}
		/* if(exite == false){
			 cout<< "Error : no existe la funcion  "<< nombre <<" linea" <<yylineno << endl;
				exit(0);
		 }
         if(parametros == NULL && ((FuncionTipo*)tipo)->parametros != NULL){
			 cout<< "Error :  parametros en la funcion "<< nombre <<" linea " <<yylineno << endl;
				exit(0);
		}else if(parametros->size() != ((FuncionTipo*)tipo)->parametros->size()){
			 cout<< "Error : demasiados o faltan parametros en la funcion a "<< nombre <<" linea " <<yylineno << endl;
				exit(0);
		}else if(parametros->size()>0){
		list<Expr*>::iterator itExpr = parametros->begin();
		list<Tipo*>::iterator itTipo =  ((FuncionTipo*)tipo)->parametros->begin();
		while(itExpr != parametros->end() && itTipo != ((FuncionTipo*)tipo)->parametros->end()){
			Expr * exprV1 = *itExpr;
			Tipo * tipoV1 = *itTipo;
			if((tipoV1->isA(charTipo) && exprV1->ValidateSemantic()->isA(intTipo))||
				(tipoV1->isA(intTipo) && exprV1->ValidateSemantic()->isA(charTipo)))
					;

			else if(!exprV1->ValidateSemantic()->isA(tipoV1->getKind())){
				cout<< "Error : no se puede enviar este tipo de parametros "<< nombre <<" linea " <<yylineno << endl;
				cout<<tipoV1->getKind()<<endl;
				cout<<exprV1->ValidateSemantic()->getKind()<<endl;
				exit(0);

			}
			itExpr++;
			itTipo++;
		}
	}*/
}


Tipo * Parametro :: ValidateSemantic(){
	declaracion->ValidateSemantic();
	if(strcmp(type,"int")==0)
		return new IntTipo();
	else if (strcmp(type,"char")==0)
		return new CharTipo();
	else if(strcmp(type,"int*")==0)
		return new ApuntadorTipo(new IntTipo());
	else if(strcmp(type,"char*")==0)
		return new ApuntadorTipo(new CharTipo());
	else if (strcmp(type,"int[]")==0)
		return  new ArrayTipo(new IntTipo());
	else if(strcmp(type,"char[]")==0)
		return new ArrayTipo(new CharTipo());
	
}
#define IMPLEMENT_INC_Statement_SEMANTIC(name) \
	void name##Statement::ValidateSemantic(){ \
		Tipo * valor = expr1->ValidateSemantic();\
	if(valor->isA(funcionTipo) || expr1->ValidateSemantic()->isA(funcionTipo)||\
		valor->isA(procedimientoTipo) || expr1->ValidateSemantic()->isA(procedimientoTipo)){\
		cout<< "Error : no se puede realizar operaciones con  funciones  linea " << yylineno << endl;\
		exit(0);\
	}\
	 }

	 IMPLEMENT_INC_Statement_SEMANTIC(PreIncremento);
IMPLEMENT_INC_Statement_SEMANTIC(PreDecremento);
IMPLEMENT_INC_Statement_SEMANTIC(PosIncremento);
IMPLEMENT_INC_Statement_SEMANTIC(PosDecremento);

//--------generar codigo----
void NumberExpr:: generalCodigo(CodigoGenerado * codigo)
{
	
	string TemporalActual = NewTemp();
	codigo->codigo = "li " + TemporalActual + ", " + to_string(value) +"\n";
		codigo->temporal = TemporalActual;

}

void CharExpr:: generalCodigo(CodigoGenerado * codigo)
{
	
	string TemporalActual = NewTemp();
	codigo->codigo = "li " + TemporalActual + ", " + value +"\n";
		codigo->temporal = TemporalActual;

}

void RandExpr:: generalCodigo(CodigoGenerado * codigo)
{
	string codigoCall;
	string TemporalActual = NewTemp();
	codigoCall += "jal rand \n";
	codigoCall += "move "+TemporalActual+ ", "+"$v0 \n";
	codigo->codigo = codigoCall;
	codigo->temporal = TemporalActual;

}
void FuncionExpr:: generalCodigo(CodigoGenerado * codigo)
{
	
	string codigoFuncion =" "; 

	if(parametros != NULL){
		ExprList::iterator pos = parametros->begin();
		int posInt = 0;
		while(pos != parametros->end())
		{
			CodigoGenerado *codigoParametro = new CodigoGenerado();
				(*pos)->generalCodigo(codigoParametro);
				codigoFuncion += codigoParametro->codigo;
			codigoFuncion += "move $a"+to_string(posInt++)+", ";
			codigoFuncion += codigoParametro->temporal+" \n";
			freeTemp(codigoParametro->temporal);
			pos++;
		}
		
	}
	codigoFuncion += "jal ";
	codigoFuncion += string(nombre) +" \n";
	string TemporalActual = NewTemp();
 codigoFuncion += "move "+TemporalActual+", $v0\n";
	codigo->codigo += codigoFuncion;
	codigo->temporal = TemporalActual;   
}
void VarNombreExpr:: generalCodigo(CodigoGenerado * codigo)
{
	
	string TemporalActual = NewTemp();
	codigo->codigo = "lw " + TemporalActual + ", " + index +"\n";
		codigo->temporal = TemporalActual;
}


void VarNombreArrayExpr:: generalCodigo(CodigoGenerado * codigo)
{
	
	CodigoGenerado * codigoValorArray = new CodigoGenerado();
	string TemporalActual = NewTemp();
	codigo->codigo = "la " + TemporalActual + ", " + index +"\n";
	expr1->generalCodigo(codigoValorArray);
	codigo->codigo += codigoValorArray->codigo;
	codigo->codigo += "sll "+codigoValorArray->temporal+", "+codigoValorArray->temporal+", 2\n";
	codigo->codigo += "add "+TemporalActual+", "+codigoValorArray->temporal+", "+TemporalActual+"\n"; 
	codigo->codigo += "lw "+TemporalActual+", ("+TemporalActual+")\n";
  freeTemp(codigoValorArray->temporal);
	codigo->temporal = TemporalActual;
	delete codigoValorArray;
}

void AddExpr::generalCodigo(CodigoGenerado * codigo)
{
	CodigoGenerado *codigo1 = new CodigoGenerado();
	CodigoGenerado *codigo2 = new CodigoGenerado();

		expr1->generalCodigo(codigo1);
	expr2->generalCodigo(codigo2);
	
	freeTemp(codigo1->temporal);
	freeTemp(codigo2->temporal);
	
	string TemporalActual = NewTemp();
	string codigoAdd;

	if(expr1->isA(NUM_EXPR)){

		codigoAdd = codigo2->codigo;
		stringstream strs;
			strs <<((NumberExpr*)expr1)->value;
		codigoAdd += "addi " + TemporalActual + ", " + codigo2->temporal + ", " +  strs.str() + "\n";

	}else if(expr2->isA(NUM_EXPR)){
		codigoAdd = codigo1->codigo;
		stringstream strs;
			strs <<((NumberExpr*)expr2)->value;
		codigoAdd += "addi " + TemporalActual + ", " + codigo1->temporal + ", " +  strs.str() + "\n";
	}else{
		codigoAdd = codigo1->codigo + codigo2->codigo;
		codigoAdd += "add " + TemporalActual + ", " + codigo1->temporal + ", " + codigo2->temporal + "\n";
	}
	codigo->codigo = codigoAdd;
	codigo->temporal = TemporalActual;
	 
}


void SubExpr:: generalCodigo(CodigoGenerado * codigo)
{
	CodigoGenerado *codigo1 = new CodigoGenerado();
	CodigoGenerado *codigo2 = new CodigoGenerado();

		expr1->generalCodigo(codigo1);
	expr2->generalCodigo(codigo2);
	
	freeTemp(codigo1->temporal);
	freeTemp(codigo2->temporal);
	
	string TemporalActual = NewTemp();
	string codigoSub;

	if(expr1->isA(NUM_EXPR)){
		stringstream strs;
			strs <<((NumberExpr*)expr1)->value;
		codigoSub = codigo2->codigo;
		codigoSub += "addi " + TemporalActual + ", " + codigo2->temporal + ", -" +  strs.str() + "\n";

	}else if(expr2->isA(NUM_EXPR)){
		stringstream strs;
			strs <<((NumberExpr*)expr2)->value;
		codigoSub = codigo1->codigo;
		codigoSub += "addi " + TemporalActual + ", " + codigo1->temporal + ", -" +   strs.str() + "\n";
	}else{
		codigoSub = codigo1->codigo + codigo2->codigo;
		codigoSub += "sub " + TemporalActual + ", " + codigo1->temporal + ", " + codigo2->temporal + "\n";
	}
	codigo->codigo = codigoSub;
	codigo->temporal = TemporalActual;
	 
}


void MultExpr:: generalCodigo(CodigoGenerado * codigo)
{
	CodigoGenerado *codigo1 = new CodigoGenerado();
	CodigoGenerado *codigo2 = new CodigoGenerado();

		expr1->generalCodigo(codigo1);
	expr2->generalCodigo(codigo2);
	
	freeTemp(codigo1->temporal);
	freeTemp(codigo2->temporal);
	
	string TemporalActual = NewTemp();
	string codigoMult = codigo1->codigo + codigo2->codigo;

	codigoMult += " move $a0, " +codigo1->temporal+ "\n" +"move $a1, " +codigo2->temporal+ "\n" +"jal mult \n";
	codigoMult += "move "+TemporalActual+", $v0 \n"; 

		codigo->codigo = codigoMult;
	codigo->temporal = TemporalActual;
	 
}


void DivExpr:: generalCodigo(CodigoGenerado * codigo)
{
	CodigoGenerado *codigo1 = new CodigoGenerado();
	CodigoGenerado *codigo2 = new CodigoGenerado();

		expr1->generalCodigo(codigo1);
	expr2->generalCodigo(codigo2);
	
	freeTemp(codigo1->temporal);
	freeTemp(codigo2->temporal);
	
	string TemporalActual = NewTemp();
	string codigoDiv = codigo1->codigo + codigo2->codigo;

	codigoDiv += " move $a0, " +codigo1->temporal+ "\n" +"move $a1, " +codigo2->temporal+ "\n" +"jal divide \n";
	codigoDiv += "move "+TemporalActual+", $t1 \n"; 

		codigo->codigo = codigoDiv;
	codigo->temporal = TemporalActual;
	 
}

void ModExpr:: generalCodigo(CodigoGenerado * codigo)
{
	CodigoGenerado *codigo1 = new CodigoGenerado();
	CodigoGenerado *codigo2 = new CodigoGenerado();

		expr1->generalCodigo(codigo1);
	expr2->generalCodigo(codigo2);
	
	freeTemp(codigo1->temporal);
	freeTemp(codigo2->temporal);
	
	string TemporalActual = NewTemp();
	string codigoMod = codigo1->codigo + codigo2->codigo;

	codigoMod += " move $a0, " +codigo1->temporal+ "\n" +"move $a1, " +codigo2->temporal+ "\n" +"jal divide \n";
	codigoMod += "move "+TemporalActual+", $a0 \n"; 
		codigo->codigo = codigoMod;
	codigo->temporal = TemporalActual;
	 
}
void StringExpr::generalCodigo(CodigoGenerado * codigo){
	

	data += " msg"+to_string(cantidadMsg)+":.asciz \""+value+"\" \n";
	string codigoString;
	string TemporalActual = NewTemp();
	
	codigoString += "la "+ TemporalActual +", msg"+to_string(cantidadMsg++)+"\n";
	
		codigo->codigo = codigoString;
	codigo->temporal = TemporalActual;
	
}

void MenorExpr:: generalCodigo(CodigoGenerado * codigo)
{
	CodigoGenerado *codigo1 = new CodigoGenerado();
	CodigoGenerado *codigo2 = new CodigoGenerado();

		expr1->generalCodigo(codigo1);
	expr2->generalCodigo(codigo2);
	
	freeTemp(codigo1->temporal);
	freeTemp(codigo2->temporal);
	
	string TemporalActual = NewTemp();
	string codigoLT;

	if(expr1->isA(NUM_EXPR)){

		codigoLT = codigo2->codigo;
		stringstream strs;
			strs <<((NumberExpr*)expr1)->value;
		codigoLT += "slti " + TemporalActual + ", " + codigo2->temporal + ", " +   strs.str() + "\n";

	}else if(expr2->isA(NUM_EXPR)){
		stringstream strs;
			strs <<((NumberExpr*)expr2)->value;
		codigoLT = codigo1->codigo;
		codigoLT += "slti " + TemporalActual + ", " + codigo1->temporal + ", " +   strs.str() + "\n";
	}else{
		codigoLT = codigo1->codigo + codigo2->codigo;
		codigoLT += "slt " + TemporalActual + ", " + codigo1->temporal + ", " + codigo2->temporal + "\n";
	}
	codigo->codigo = codigoLT;
	codigo->temporal = TemporalActual;
	 
}





void MayorExpr:: generalCodigo(CodigoGenerado * codigo)
{
	CodigoGenerado *codigo1 = new CodigoGenerado();
	CodigoGenerado *codigo2 = new CodigoGenerado();

		expr1->generalCodigo(codigo1);
	expr2->generalCodigo(codigo2);
	
	freeTemp(codigo1->temporal);
	freeTemp(codigo2->temporal);
	
	string TemporalActual = NewTemp();
	string codigoGT;

	codigoGT = codigo1->codigo + codigo2->codigo;
	codigoGT += "slt " + TemporalActual + ", " + codigo2->temporal + ", " + codigo1->temporal + "\n";
	
	codigo->codigo = codigoGT;
	codigo->temporal = TemporalActual;
	 
}

void MayorIgualExpr:: generalCodigo(CodigoGenerado * codigo)
{
	CodigoGenerado *codigo1 = new CodigoGenerado();
	CodigoGenerado *codigo2 = new CodigoGenerado();

		expr1->generalCodigo(codigo1);
	expr2->generalCodigo(codigo2);
	
	freeTemp(codigo1->temporal);
	freeTemp(codigo2->temporal);
	
	string TemporalActual = NewTemp();
	string codigoGTE;

	

	codigoGTE = codigo1->codigo + codigo2->codigo;
	codigoGTE += "beq " +codigo1->temporal + ", " + codigo2->temporal + ", igualGTE"+to_string(cantidadGTE)+" \n";
	codigoGTE += "sub " + TemporalActual + ", " + codigo1->temporal + ", " + codigo2->temporal + "\n";
	codigoGTE += "slt " + TemporalActual + ", $zero, " + TemporalActual + " \n" ;
	codigoGTE += "bne " +TemporalActual + ", $zero , igualGTE" +to_string(cantidadGTE)+" \n";;
	codigoGTE += "li " +TemporalActual + ", 0 \n";
	codigoGTE += "j finGTE"+to_string(cantidadGTE)+" \n";
	codigoGTE += "igualGTE"+to_string(cantidadGTE)+": \n";
	codigoGTE += "li " +TemporalActual + ", 1 \n";
	codigoGTE += "finGTE"+to_string(cantidadGTE++)+": \n";
	codigo->codigo = codigoGTE;
	codigo->temporal = TemporalActual;
	 
}

void MenorIgualExpr:: generalCodigo(CodigoGenerado * codigo)
{
	CodigoGenerado *codigo1 = new CodigoGenerado();
	CodigoGenerado *codigo2 = new CodigoGenerado();

		expr1->generalCodigo(codigo1);
	expr2->generalCodigo(codigo2);
	
	freeTemp(codigo1->temporal);
	freeTemp(codigo2->temporal);
	
	string TemporalActual = NewTemp();
	string codigoLTE;

	

	codigoLTE = codigo1->codigo + codigo2->codigo;
	codigoLTE += "beq " +codigo1->temporal + ", " + codigo2->temporal + ", igualLTE"+to_string(cantidadLTE)+" \n";
	codigoLTE += "sub " + TemporalActual + ", " + codigo2->temporal + ", " + codigo1->temporal + "\n";
	codigoLTE += "slt " + TemporalActual + ", $zero, " + TemporalActual + " \n" ;
	codigoLTE += "bne " +TemporalActual + ", $zero, igualLTE"+to_string(cantidadLTE)+" \n";
	codigoLTE += "li " +TemporalActual + ", 0 \n";
	codigoLTE += "j finLTE"+to_string(cantidadLTE)+" \n";
	codigoLTE += "igualLTE"+to_string(cantidadLTE)+": \n";
	codigoLTE += "li " +TemporalActual + ", 1 \n";
	codigoLTE += "finLTE"+to_string(cantidadLTE++)+": \n";
	codigo->codigo = codigoLTE;
	codigo->temporal = TemporalActual;
	 
}

void DistintoExpr:: generalCodigo(CodigoGenerado * codigo)
{
	
	CodigoGenerado *codigo1 = new CodigoGenerado();
	CodigoGenerado *codigo2 = new CodigoGenerado();

		expr1->generalCodigo(codigo1);
	expr2->generalCodigo(codigo2);
	
	freeTemp(codigo1->temporal);
	freeTemp(codigo2->temporal);
	
	string TemporalActual = NewTemp();
	string codigoNE;
	
	codigoNE = codigo1->codigo + codigo2->codigo;
	codigoNE += "xor " + TemporalActual + ", " + codigo2->temporal + ", " + codigo1->temporal + "\n";
	codigoNE += "slt " + TemporalActual + ", $zero, " + TemporalActual + " \n" ;
	
	codigo->codigo = codigoNE;
	codigo->temporal = TemporalActual;
	 
}


void IgualExpr :: generalCodigo(CodigoGenerado * codigo)
{
	
	CodigoGenerado *codigo1 = new CodigoGenerado();
	CodigoGenerado *codigo2 = new CodigoGenerado();

		expr1->generalCodigo(codigo1);
	expr2->generalCodigo(codigo2);
	
	freeTemp(codigo1->temporal);
	freeTemp(codigo2->temporal);
	
	string TemporalActual = NewTemp();
	string codigoEQ;
	
	codigoEQ = codigo1->codigo + codigo2->codigo;
	codigoEQ += "beq " +codigo1->temporal + ", " + codigo2->temporal + ", igualEQ"+to_string(cantidadEQ)+" \n";
	codigoEQ += "li " +TemporalActual + ",0 \n";
	codigoEQ += "j finEQ"+to_string(cantidadEQ)+" \n";
	codigoEQ += "igualEQ"+to_string(cantidadEQ)+": \n";
	codigoEQ += "li " +TemporalActual + ",1 \n";
	codigoEQ += "finEQ"+to_string(cantidadEQ++)+": \n";
		
	
	codigo->codigo = codigoEQ;
	codigo->temporal = TemporalActual;
	 
}

void OPorBitExpr :: generalCodigo(CodigoGenerado * codigo)
{

	CodigoGenerado *codigo1 = new CodigoGenerado();
	CodigoGenerado *codigo2 = new CodigoGenerado();

	expr1->generalCodigo(codigo1);
	expr2->generalCodigo(codigo2);
	
	freeTemp(codigo1->temporal);
	freeTemp(codigo2->temporal);
	
	string TemporalActual = NewTemp();
	string codigoOr;

	if(expr1->isA(NUM_EXPR)){
		stringstream strs;
			strs <<((NumberExpr*)expr1)->value;
		codigoOr = codigo2->codigo;
		codigoOr += "ori " + TemporalActual + ", " + codigo2->temporal + ", -" +  strs.str() + "\n";

	}else if(expr2->isA(NUM_EXPR)){
		stringstream strs;
			strs <<((NumberExpr*)expr2)->value;
		codigoOr = codigo1->codigo;
		codigoOr += "ori " + TemporalActual + ", " + codigo1->temporal + ", -" +   strs.str() + "\n";
	}else{
		codigoOr = codigo1->codigo + codigo2->codigo;
		codigoOr += "or " + TemporalActual + ", " + codigo1->temporal + ", " + codigo2->temporal + "\n";
	}
	codigo->codigo = codigoOr;
	codigo->temporal = TemporalActual;
	 
}

void ExclPorBitExpr :: generalCodigo(CodigoGenerado * codigo)
{

	CodigoGenerado *codigo1 = new CodigoGenerado();
	CodigoGenerado *codigo2 = new CodigoGenerado();

	expr1->generalCodigo(codigo1);
	expr2->generalCodigo(codigo2);
	
	freeTemp(codigo1->temporal);
	freeTemp(codigo2->temporal);
	
	string TemporalActual = NewTemp();
	string codigoOr;

	codigoOr = codigo1->codigo + codigo2->codigo;
		codigoOr += "xor " + TemporalActual + ", " + codigo1->temporal + ", " + codigo2->temporal + "\n";
	
	codigo->codigo = codigoOr;
	codigo->temporal = TemporalActual;
	 
}
void OrExpr :: generalCodigo(CodigoGenerado * codigo)
{

	CodigoGenerado *codigo1 = new CodigoGenerado();
	CodigoGenerado *codigo2 = new CodigoGenerado();

	expr1->generalCodigo(codigo1);
	expr2->generalCodigo(codigo2);
	
	freeTemp(codigo1->temporal);
	freeTemp(codigo2->temporal);
	
	string TemporalActual = NewTemp();
	string codigoOr;

	codigoOr = codigo1->codigo + codigo2->codigo;
	codigoOr += "bne "+codigo1->temporal+", $zero"+".OrUno"+to_string(cantidadOr) +"\n";
	codigoOr += "bne "+codigo2->temporal+", $zero"+".OrUno"+to_string(cantidadOr) +"\n";
	codigoOr +=  "move "+TemporalActual+", $zero \n j endOr"+to_string(cantidadOr) + "\n";
	codigoOr += ".OrUno:\n li "+TemporalActual+" , 1 \n j endOr"+to_string(cantidadOr)+"\n";
	codigoOr += "endOr"+to_string(cantidadOr++)+":";
	codigo->codigo = codigoOr;
	codigo->temporal = TemporalActual;
	 
}
void AndExpr :: generalCodigo(CodigoGenerado * codigo)
{

	CodigoGenerado *codigo1 = new CodigoGenerado();
	CodigoGenerado *codigo2 = new CodigoGenerado();

	expr1->generalCodigo(codigo1);
	expr2->generalCodigo(codigo2);
	
	freeTemp(codigo1->temporal);
	freeTemp(codigo2->temporal);
	
	string TemporalActual = NewTemp();
	string codigoOr;

	codigoOr = codigo1->codigo + codigo2->codigo;
	codigoOr += "slt "+codigo1->temporal+", $zero, "+codigo1->temporal+"\n";
	codigoOr += "slt "+codigo1->temporal+", $zero, "+codigo1->temporal+"\n";
	codigoOr += "beq "+codigo2->temporal+", "+codigo1->temporal + ".AndUno"+to_string(cantidadAnd) +"\n";
	codigoOr +=  "move "+TemporalActual+", $zero \n j endAnd"+to_string(cantidadAnd) + "\n";
	codigoOr += ".AndUno:\n li "+TemporalActual+" , 1 \n j endAnd"+to_string(cantidadAnd)+"\n";
	codigoOr += "endAnd"+to_string(cantidadOr++)+":";
	codigo->codigo = codigoOr;
	codigo->temporal = TemporalActual;
	 
}

void TernarioExpr:: generalCodigo(CodigoGenerado * codigo){
   string codigoTernario;  
	CodigoGenerado *codigoCond = new CodigoGenerado();
	CodigoGenerado *codigoTrue = new CodigoGenerado();
	CodigoGenerado *codigoFalse = new CodigoGenerado();
	
	condicion->generalCodigo(codigoCond);
	expr1->generalCodigo(codigoTrue);
	expr2->generalCodigo(codigoFalse);
	
	string TemporalActual = NewTemp();
	freeTemp(codigoCond->temporal);
	freeTemp(codigoTrue->temporal);
	freeTemp(codigoFalse->temporal);

	codigoTernario = "ternario"+to_string(cantidadternario)+": \n";
	codigoTernario += "\t" + codigoCond->codigo;
	codigoTernario += "\t beqz "+codigoCond->temporal+", .elseternario"+to_string(cantidadternario)+" \n";
	codigoTernario += codigoTrue->codigo;
	codigoTernario += "move "+TemporalActual +", "+codigoTrue->temporal+"\n"; 
	codigoTernario += "\t j .endTernario"+to_string(cantidadternario)+" \n";
	codigoTernario +=".elseternario"+to_string(cantidadternario)+":\n";
	codigoTernario += codigoFalse->codigo;
	codigoTernario += "move "+TemporalActual +", "+codigoTrue->temporal+"\n";
	codigoTernario += "\t j .endTernario"+to_string(cantidadternario)+" \n";  
	codigoTernario += ".endTernario"+to_string(cantidadternario++)+": \n";
		
	delete codigoCond;
	delete codigoTrue;
	delete codigoFalse;
	codigo->codigo += codigoTernario;
	codigo->temporal = TemporalActual;


}
void YPorBitExpr :: generalCodigo(CodigoGenerado * codigo)
{

	CodigoGenerado *codigo1 = new CodigoGenerado();
	CodigoGenerado *codigo2 = new CodigoGenerado();

	expr1->generalCodigo(codigo1);
	expr2->generalCodigo(codigo2);
	
	freeTemp(codigo1->temporal);
	freeTemp(codigo2->temporal);
	
	string TemporalActual = NewTemp();
	string codigoOr;

	if(expr1->isA(NUM_EXPR)){
		stringstream strs;
			strs <<((NumberExpr*)expr1)->value;
		codigoOr = codigo2->codigo;
		codigoOr += "andi " + TemporalActual + ", " + codigo2->temporal + ", -" +  strs.str() + "\n";

	}else if(expr2->isA(NUM_EXPR)){
		stringstream strs;
			strs <<((NumberExpr*)expr2)->value;
		codigoOr = codigo1->codigo;
		codigoOr += "andi " + TemporalActual + ", " + codigo1->temporal + ", -" +   strs.str() + "\n";
	}else{
		codigoOr = codigo1->codigo + codigo2->codigo;
		codigoOr += "and " + TemporalActual + ", " + codigo1->temporal + ", " + codigo2->temporal + "\n";
	}
	codigo->codigo = codigoOr;
	codigo->temporal = TemporalActual;
	 
}
void CorrimientoIzqExpr :: generalCodigo(CodigoGenerado * codigo)
{

	CodigoGenerado *codigo1 = new CodigoGenerado();
	CodigoGenerado *codigo2 = new CodigoGenerado();

	expr1->generalCodigo(codigo1);
	expr2->generalCodigo(codigo2);
	
	freeTemp(codigo1->temporal);
	freeTemp(codigo2->temporal);
	
	string TemporalActual = NewTemp();
	string codigoOr;
	
		codigoOr = codigo1->codigo + codigo2->codigo;
		codigoOr += "sll " + TemporalActual + ", " + codigo1->temporal + ", " + codigo2->temporal + "\n";
	
	codigo->codigo = codigoOr;
	codigo->temporal = TemporalActual;
	 
}
void CorrimientoDerExpr :: generalCodigo(CodigoGenerado * codigo)
{

	CodigoGenerado *codigo1 = new CodigoGenerado();
	CodigoGenerado *codigo2 = new CodigoGenerado();

	expr1->generalCodigo(codigo1);
	expr2->generalCodigo(codigo2);
	
	freeTemp(codigo1->temporal);
	freeTemp(codigo2->temporal);
	
	string TemporalActual = NewTemp();
	string codigoOr;
	
		codigoOr = codigo1->codigo + codigo2->codigo;
		codigoOr += "srl " + TemporalActual + ", " + codigo1->temporal + ", " + codigo2->temporal + "\n";
	
	codigo->codigo = codigoOr;
	codigo->temporal = TemporalActual;
	 
}

void PreIncrementoExpr::generalCodigo(CodigoGenerado * codigo){
	string codigoIncre; 
	CodigoGenerado *codigoValor = new CodigoGenerado();

	expr1->generalCodigo(codigoValor);


	string TemporalActual = NewTemp();
	codigoIncre = codigoValor->codigo;
	codigoIncre += "addi "+TemporalActual +", "+codigoValor->temporal+", 1 \n";
	if(expr1->isA(ID_EXPR)){
		string id = ((VarNombreExpr*)expr1)->index;
		codigoIncre += "sw "+TemporalActual +", "+id +"\n";
		
	}else if(expr1->isA(ARRAYNOMBRE_EXPR))
	{
		CodigoGenerado *codigoValorArray = new CodigoGenerado();
		((VarNombreArrayExpr*)expr1)->expr1->generalCodigo(codigoValorArray);
		string TemporalActual2 = NewTemp();
		codigoIncre += codigoValorArray->codigo;
		codigoIncre += "sll "+codigoValorArray->temporal+", "+codigoValorArray->temporal+", 2\n";
		codigoIncre += "la "+TemporalActual2 +", "+((VarNombreArrayExpr*)expr1)->index;
		codigoIncre += "\n add "+TemporalActual2 +", "+TemporalActual2 +", "+codigoValorArray->temporal+"\n"; 
		codigoIncre += "sw "+TemporalActual +", ("+ TemporalActual2+")\n";
		freeTemp(TemporalActual2);
		freeTemp(codigoValorArray->temporal);
	}
	freeTemp(codigoValor->temporal);

	codigo->codigo = codigoIncre ;
	codigo->temporal += TemporalActual ;
}
void PreDecrementoExpr::generalCodigo(CodigoGenerado * codigo){
	string codigoIncre; 
	CodigoGenerado *codigoValor = new CodigoGenerado();

	expr1->generalCodigo(codigoValor);
	
	string TemporalActual = NewTemp();
	codigoIncre = codigoValor->codigo;
	codigoIncre += "addi "+TemporalActual +", "+codigoValor->temporal+", -1 \n";
	if(expr1->isA(ID_EXPR)){
		string id = ((VarNombreExpr*)expr1)->index;
		codigoIncre += "sw "+TemporalActual +", "+id +"\n";
		
	}else if(expr1->isA(ARRAYNOMBRE_EXPR))
	{
		CodigoGenerado *codigoValorArray = new CodigoGenerado();
		((VarNombreArrayExpr*)expr1)->expr1->generalCodigo(codigoValorArray);
		string TemporalActual2 = NewTemp();
		codigoIncre += codigoValorArray->codigo;
		codigoIncre += "sll "+codigoValorArray->temporal+", "+codigoValorArray->temporal+", 2\n";
		codigoIncre += "la "+TemporalActual2 +", "+((VarNombreArrayExpr*)expr1)->index;
		codigoIncre += "\n add "+TemporalActual2 +", "+TemporalActual2 +", "+codigoValorArray->temporal+"\n"; 
		codigoIncre += "sw "+TemporalActual +", ("+ TemporalActual2+")\n";
		freeTemp(TemporalActual2);
		freeTemp(codigoValorArray->temporal);
	}

	freeTemp(codigoValor->temporal);
	codigo->codigo = codigoIncre ;
	codigo->temporal += TemporalActual ;
}


void PosIncrementoExpr::generalCodigo(CodigoGenerado * codigo){
	string codigoIncre; 
	CodigoGenerado *codigoValor = new CodigoGenerado();

	expr1->generalCodigo(codigoValor);
	
	string TemporalActual = NewTemp();
	codigoIncre = codigoValor->codigo;
	codigoIncre += "addi "+TemporalActual +", "+codigoValor->temporal+", 1 \n";
	if(expr1->isA(ID_EXPR)){
		string id = ((VarNombreExpr*)expr1)->index;
		codigoIncre += "sw "+TemporalActual +", "+id +"\n";
		
	}else if(expr1->isA(ARRAYNOMBRE_EXPR))
	{
		CodigoGenerado *codigoValorArray = new CodigoGenerado();
		((VarNombreArrayExpr*)expr1)->expr1->generalCodigo(codigoValorArray);
		string TemporalActual2 = NewTemp();
		codigoIncre += codigoValorArray->codigo;
		codigoIncre += "sll "+codigoValorArray->temporal+", "+codigoValorArray->temporal+", 2\n";
		codigoIncre += "la "+TemporalActual2 +", "+((VarNombreArrayExpr*)expr1)->index;
		codigoIncre += "\n add "+TemporalActual2 +", "+TemporalActual2 +", "+codigoValorArray->temporal+"\n"; 
		codigoIncre += "sw "+TemporalActual +", ("+ TemporalActual2+")\n";
		freeTemp(TemporalActual2);
		freeTemp(codigoValorArray->temporal);
	}

	freeTemp(TemporalActual);
	codigo->codigo = codigoIncre;
	codigo->temporal = codigoValor->temporal;
}
void PosDecrementoExpr::generalCodigo(CodigoGenerado * codigo){
	string codigoIncre; 

	CodigoGenerado *codigoValor = new CodigoGenerado();

	expr1->generalCodigo(codigoValor);
	string TemporalActual = NewTemp();
	codigoIncre = codigoValor->codigo;
	codigoIncre += "addi "+TemporalActual +", "+codigoValor->temporal+", -1 \n";
	if(expr1->isA(ID_EXPR)){
		string id = ((VarNombreExpr*)expr1)->index;
		codigoIncre += "sw "+TemporalActual +", "+id +"\n";
		
	}else if(expr1->isA(ARRAYNOMBRE_EXPR))
	{
		CodigoGenerado *codigoValorArray = new CodigoGenerado();
		((VarNombreArrayExpr*)expr1)->expr1->generalCodigo(codigoValorArray);
		string TemporalActual2 = NewTemp();
		codigoIncre += codigoValorArray->codigo;
		codigoIncre += "sll "+codigoValorArray->temporal+", "+codigoValorArray->temporal+", 2\n";
		codigoIncre += "la "+TemporalActual2 +", "+((VarNombreArrayExpr*)expr1)->index;
		codigoIncre += "\n add "+TemporalActual2 +", "+TemporalActual2 +", "+codigoValorArray->temporal+"\n"; 
		codigoIncre += "sw "+TemporalActual +", ("+ TemporalActual2+")\n";
		freeTemp(TemporalActual2);
		freeTemp(codigoValorArray->temporal);
	}
	freeTemp(TemporalActual);
	
	codigo->codigo = codigoIncre ;
	codigo->temporal = codigoValor->temporal;
}

void ComplementoExpr::generalCodigo(CodigoGenerado * codigo){

	CodigoGenerado *codigo1 = new CodigoGenerado();
	
	expr1->generalCodigo(codigo1);
	
	freeTemp(codigo1->temporal);
	
	string TemporalActual = NewTemp();
	string codigoComplemento;
	
		codigoComplemento = codigo1->codigo ;
		codigoComplemento += "nor " + TemporalActual + ", " + codigo1->temporal + ", " + codigo1->temporal + "\n";
	
	codigo->codigo = codigoComplemento;
	codigo->temporal = TemporalActual;
}

void NegacionExpr ::generalCodigo(CodigoGenerado * codigo){

	CodigoGenerado *codigo1 = new CodigoGenerado();

	expr1->generalCodigo(codigo1);
	
	freeTemp(codigo1->temporal);
	
	string TemporalActual = NewTemp();
	string codigoNegacion;
	
		codigoNegacion = codigo1->codigo ;
		codigoNegacion += "beqz " + codigo1->temporal + ", .negacionUno"+to_string(cantidadNegacion)+ "\n";
		codigoNegacion += "li "+TemporalActual +", 0\n ";
		codigoNegacion += "j .endNegacion"+to_string(cantidadNegacion)+"\n";
		codigoNegacion += ".negacionUno"+to_string(cantidadNegacion)+"\n";
		codigoNegacion += "li "+TemporalActual +", 1\n ";
		codigoNegacion += ".endNegacion"+to_string(cantidadNegacion++)+":\n";
	codigo->codigo = codigoNegacion;
	codigo->temporal = TemporalActual;
}




void AsignarExpr::generalCodigo(CodigoGenerado * codigo){
	
	CodigoGenerado *codigo1 = new CodigoGenerado();
	
	expr1->generalCodigo(codigo1);

	freeTemp(codigo1->temporal);
	
	string codigoAssign;
	codigoAssign = codigo1->codigo; 
	if(nombre->isA(ID_EXPR)){
    
		codigoAssign += "sw " + codigo1->temporal + ", " + ((VarNombreExpr*)nombre)->index +"\n";
	}else if(nombre->isA(ARRAYNOMBRE_EXPR)){
		CodigoGenerado *codigoValorArray = new CodigoGenerado();
		string TemporalActual = NewTemp();
		((VarNombreArrayExpr*)nombre)->expr1->generalCodigo(codigoValorArray);
		codigoAssign += codigoValorArray->codigo;
		codigoAssign += "sll "+codigoValorArray->temporal+", "+codigoValorArray->temporal+", 2\n";
		codigoAssign += "la "+TemporalActual+ ", "+ ((VarNombreArrayExpr*)nombre)->index +"\n";
		freeTemp(codigoValorArray->temporal);
		codigoAssign += "add "+TemporalActual+", "+TemporalActual+", "+codigoValorArray->temporal+"\n";
		codigoAssign += "sw "+codigo1->temporal+", ("+TemporalActual+") \n ";
		
		freeTemp(TemporalActual);
	}
	

	codigo->codigo += codigoAssign;
	codigo->temporal = codigo1->temporal;
	delete codigo1;
	
}


void MasIgualExpr::generalCodigo(CodigoGenerado * codigo){
	
	CodigoGenerado *codigo1 = new CodigoGenerado();
	
	expr1->generalCodigo(codigo1);
	string codigoAssign;
	codigoAssign = codigo1->codigo; 
	if(nombre->isA(ID_EXPR)){
    string TemporalActual = NewTemp();
    codigoAssign += "lw "+ TemporalActual +", "+ ((VarNombreExpr*)nombre)->index +"\n";
    codigoAssign += "add "+codigo1->temporal +", "+codigo1->temporal+", "+TemporalActual+"\n";
		codigoAssign += "sw " + codigo1->temporal + ", " + ((VarNombreExpr*)nombre)->index +"\n";
		freeTemp(TemporalActual);
	}else if(nombre->isA(ARRAYNOMBRE_EXPR)){
		CodigoGenerado *codigoValorArray = new CodigoGenerado();
		string TemporalActual = NewTemp();
		string TemporalActual2 = NewTemp();
		((VarNombreArrayExpr*)nombre)->expr1->generalCodigo(codigoValorArray);
		codigoAssign += codigoValorArray->codigo;
		codigoAssign += "la "+TemporalActual+ ", "+ ((VarNombreArrayExpr*)nombre)->index +"\n";
		freeTemp(codigoValorArray->temporal);
		codigoAssign += "add "+TemporalActual+", "+TemporalActual+", "+codigoValorArray->temporal+"\n";
		codigoAssign += "lw "+TemporalActual2+", "+"("+TemporalActual+")\n";
		codigoAssign += "add"+codigo1->temporal +", "+codigo1->temporal+", "+TemporalActual2+"\n";
		codigoAssign += "sw "+codigo1->temporal+", ("+TemporalActual+") \n ";
		freeTemp(TemporalActual2);
		freeTemp(TemporalActual);
	}


	codigo->codigo = codigoAssign;
	codigo->temporal = codigo1->temporal;
	delete codigo1;
	
}

void MenosIgualExpr::generalCodigo(CodigoGenerado * codigo){
	
	CodigoGenerado *codigo1 = new CodigoGenerado();
	
	expr1->generalCodigo(codigo1);
	string codigoAssign;
	codigoAssign = codigo1->codigo; 
	if(nombre->isA(ID_EXPR)){
    string TemporalActual = NewTemp();
    codigoAssign += "lw "+ TemporalActual +", "+ ((VarNombreExpr*)nombre)->index +"\n";
    codigoAssign += "sub "+codigo1->temporal +", "+codigo1->temporal+", "+TemporalActual+"\n";
		codigoAssign += "sw " + codigo1->temporal + ", " + ((VarNombreExpr*)nombre)->index +"\n";
		freeTemp(TemporalActual);
	}else if(nombre->isA(ARRAYNOMBRE_EXPR)){
		CodigoGenerado *codigoValorArray = new CodigoGenerado();
		string TemporalActual = NewTemp();
		string TemporalActual2 = NewTemp();
		((VarNombreArrayExpr*)nombre)->expr1->generalCodigo(codigoValorArray);
		codigoAssign += codigoValorArray->codigo;
		codigoAssign += "sll "+codigoValorArray->temporal+", "+codigoValorArray->temporal+", 2\n";
		codigoAssign += "la "+TemporalActual+ ", "+ ((VarNombreArrayExpr*)nombre)->index +"\n";
		freeTemp(codigoValorArray->temporal);
		codigoAssign += "add "+TemporalActual+", "+TemporalActual+", "+codigoValorArray->temporal+"\n";
		codigoAssign += "lw "+TemporalActual2+", "+"("+TemporalActual+")\n";
		codigoAssign += "sub "+codigo1->temporal +", "+TemporalActual2+", "+codigo1->temporal+"\n";
		codigoAssign += "sw "+codigo1->temporal+", ("+TemporalActual+") \n ";
		freeTemp(TemporalActual2);
		freeTemp(TemporalActual);
	}


	codigo->codigo = codigoAssign;
	codigo->temporal = codigo1->temporal;
	delete codigo1;
	
}

void OrBitIgualExpr::generalCodigo(CodigoGenerado * codigo){
	
	CodigoGenerado *codigo1 = new CodigoGenerado();
	
	expr1->generalCodigo(codigo1);
	string codigoAssign;
	codigoAssign = codigo1->codigo; 
	if(nombre->isA(ID_EXPR)){
    string TemporalActual = NewTemp();
    codigoAssign += "lw "+ TemporalActual +", "+ ((VarNombreExpr*)nombre)->index +"\n";
    codigoAssign += "or "+codigo1->temporal +", "+codigo1->temporal+", "+TemporalActual+"\n";
		codigoAssign += "sw " + codigo1->temporal + ", " + ((VarNombreExpr*)nombre)->index +"\n";
		freeTemp(TemporalActual);
	}else if(nombre->isA(ARRAYNOMBRE_EXPR)){
		CodigoGenerado *codigoValorArray = new CodigoGenerado();
		string TemporalActual = NewTemp();
		string TemporalActual2 = NewTemp();
		((VarNombreArrayExpr*)nombre)->expr1->generalCodigo(codigoValorArray);
		codigoAssign += codigoValorArray->codigo;
		codigoAssign += "sll "+codigoValorArray->temporal+", "+codigoValorArray->temporal+", 2\n";
		codigoAssign += "la "+TemporalActual+ ", "+ ((VarNombreArrayExpr*)nombre)->index +"\n";
		freeTemp(codigoValorArray->temporal);
		codigoAssign += "add "+TemporalActual+", "+TemporalActual+", "+codigoValorArray->temporal+"\n";
		codigoAssign += "lw "+TemporalActual2+", "+"("+TemporalActual+")\n";
		codigoAssign += "or "+codigo1->temporal +", "+codigo1->temporal+", "+TemporalActual2+"\n";
		codigoAssign += "sw "+codigo1->temporal+", ("+TemporalActual+") \n ";
		freeTemp(TemporalActual2);
		freeTemp(TemporalActual);
	}


	codigo->codigo = codigoAssign;
	codigo->temporal = codigo1->temporal;
	delete codigo1;
	
}

void AndBitIgualExpr::generalCodigo(CodigoGenerado * codigo){
	
	CodigoGenerado *codigo1 = new CodigoGenerado();
	
	expr1->generalCodigo(codigo1);
	string codigoAssign;
	codigoAssign = codigo1->codigo; 
	if(nombre->isA(ID_EXPR)){
    string TemporalActual = NewTemp();
    codigoAssign += "lw "+ TemporalActual +", "+ ((VarNombreExpr*)nombre)->index +"\n";
    codigoAssign += "or "+codigo1->temporal +", "+codigo1->temporal+", "+TemporalActual+"\n";
		codigoAssign += "sw " + codigo1->temporal + ", " + ((VarNombreExpr*)nombre)->index +"\n";
		freeTemp(TemporalActual);
	}else if(nombre->isA(ARRAYNOMBRE_EXPR)){
		CodigoGenerado *codigoValorArray = new CodigoGenerado();
		string TemporalActual = NewTemp();
		string TemporalActual2 = NewTemp();
		((VarNombreArrayExpr*)nombre)->expr1->generalCodigo(codigoValorArray);
		codigoAssign += codigoValorArray->codigo;
		codigoAssign += "sll "+codigoValorArray->temporal+", "+codigoValorArray->temporal+", 2\n";
		codigoAssign += "la "+TemporalActual+ ", "+ ((VarNombreArrayExpr*)nombre)->index +"\n";
		freeTemp(codigoValorArray->temporal);
		codigoAssign += "add "+TemporalActual+", "+TemporalActual+", "+codigoValorArray->temporal+"\n";
		codigoAssign += "lw "+TemporalActual2+", "+"("+TemporalActual+")\n";
		codigoAssign += "or "+codigo1->temporal +", "+codigo1->temporal+", "+TemporalActual2+"\n";
		codigoAssign += "sw "+codigo1->temporal+", ("+TemporalActual+") \n ";
		freeTemp(TemporalActual2);
		freeTemp(TemporalActual);
	}


	codigo->codigo = codigoAssign;
	codigo->temporal = codigo1->temporal;
	delete codigo1;
	
}

void XorBitIgualExpr::generalCodigo(CodigoGenerado * codigo){
	
	CodigoGenerado *codigo1 = new CodigoGenerado();
	
	expr1->generalCodigo(codigo1);
	string codigoAssign;
	codigoAssign = codigo1->codigo; 
	if(nombre->isA(ID_EXPR)){
    string TemporalActual = NewTemp();
    codigoAssign += "lw "+ TemporalActual +", "+ ((VarNombreExpr*)nombre)->index +"\n";
    codigoAssign += "xor "+codigo1->temporal +", "+codigo1->temporal+", "+TemporalActual+"\n";
		codigoAssign += "sw " + codigo1->temporal + ", " + ((VarNombreExpr*)nombre)->index +"\n";
		freeTemp(TemporalActual);
	}else if(nombre->isA(ARRAYNOMBRE_EXPR)){
		CodigoGenerado *codigoValorArray = new CodigoGenerado();
		string TemporalActual = NewTemp();
		string TemporalActual2 = NewTemp();
		((VarNombreArrayExpr*)nombre)->expr1->generalCodigo(codigoValorArray);
		codigoAssign += codigoValorArray->codigo;
		codigoAssign += "sll "+codigoValorArray->temporal+", "+codigoValorArray->temporal+", 2\n";
		codigoAssign += "la "+TemporalActual+ ", "+ ((VarNombreArrayExpr*)nombre)->index +"\n";
		freeTemp(codigoValorArray->temporal);
		codigoAssign += "add "+TemporalActual+", "+TemporalActual+", "+codigoValorArray->temporal+"\n";
		codigoAssign += "lw "+TemporalActual2+", "+"("+TemporalActual+")\n";
		codigoAssign += "xor "+codigo1->temporal +", "+codigo1->temporal+", "+TemporalActual2+"\n";
		codigoAssign += "sw "+codigo1->temporal+", ("+TemporalActual+") \n ";
		freeTemp(TemporalActual2);
		freeTemp(TemporalActual);
	}
	codigo->codigo = codigoAssign;
	codigo->temporal = codigo1->temporal;
	delete codigo1;
}

void AsigCorIzqIgualExpr::generalCodigo(CodigoGenerado * codigo){
	
	CodigoGenerado *codigo1 = new CodigoGenerado();
	
	expr1->generalCodigo(codigo1);
	string codigoAssign;
	codigoAssign = codigo1->codigo; 
	if(nombre->isA(ID_EXPR)){
    string TemporalActual = NewTemp();
    codigoAssign += "lw "+ TemporalActual +", "+ ((VarNombreExpr*)nombre)->index +"\n";
    codigoAssign += "sll "+codigo1->temporal +", "+TemporalActual+", "+codigo1->temporal+"\n";
		codigoAssign += "sw " + codigo1->temporal + ", " + ((VarNombreExpr*)nombre)->index +"\n";
		freeTemp(TemporalActual);
	}else if(nombre->isA(ARRAYNOMBRE_EXPR)){
		CodigoGenerado *codigoValorArray = new CodigoGenerado();
		string TemporalActual = NewTemp();
		string TemporalActual2 = NewTemp();
		((VarNombreArrayExpr*)nombre)->expr1->generalCodigo(codigoValorArray);
		codigoAssign += codigoValorArray->codigo;
		codigoAssign += "sll "+codigoValorArray->temporal+", "+codigoValorArray->temporal+", 2\n";
		codigoAssign += "la "+TemporalActual+ ", "+ ((VarNombreArrayExpr*)nombre)->index +"\n";
		freeTemp(codigoValorArray->temporal);
		codigoAssign += "add "+TemporalActual+", "+TemporalActual+", "+codigoValorArray->temporal+"\n";
		codigoAssign += "lw "+TemporalActual2+", "+"("+TemporalActual+")\n";
		codigoAssign += "sll "+codigo1->temporal +", "+TemporalActual2+", "+codigo1->temporal+"\n";
		codigoAssign += "sw "+codigo1->temporal+", ("+TemporalActual+") \n ";
		freeTemp(TemporalActual2);
		freeTemp(TemporalActual);
	}
	codigo->codigo = codigoAssign;
	codigo->temporal = codigo1->temporal;
	delete codigo1;	
}

void AsigCorDerIgualExpr::generalCodigo(CodigoGenerado * codigo){
	
	CodigoGenerado *codigo1 = new CodigoGenerado();
	
	expr1->generalCodigo(codigo1);
	string codigoAssign;
	codigoAssign = codigo1->codigo; 
	if(nombre->isA(ID_EXPR)){
    string TemporalActual = NewTemp();
    codigoAssign += "lw "+ TemporalActual +", "+ ((VarNombreExpr*)nombre)->index +"\n";
    codigoAssign += "srl "+codigo1->temporal +", "+TemporalActual+", "+codigo1->temporal+"\n";
		codigoAssign += "sw " + codigo1->temporal + ", " + ((VarNombreExpr*)nombre)->index +"\n";
		freeTemp(TemporalActual);
	}else if(nombre->isA(ARRAYNOMBRE_EXPR)){
		CodigoGenerado *codigoValorArray = new CodigoGenerado();
		string TemporalActual = NewTemp();
		string TemporalActual2 = NewTemp();
		((VarNombreArrayExpr*)nombre)->expr1->generalCodigo(codigoValorArray);
		codigoAssign += codigoValorArray->codigo;
		codigoAssign += "sll "+codigoValorArray->temporal+", "+codigoValorArray->temporal+", 2\n";
		codigoAssign += "la "+TemporalActual+ ", "+ ((VarNombreArrayExpr*)nombre)->index +"\n";
		freeTemp(codigoValorArray->temporal);
		codigoAssign += "add "+TemporalActual+", "+TemporalActual+", "+codigoValorArray->temporal+"\n";
		codigoAssign += "lw "+TemporalActual2+", "+"("+TemporalActual+")\n";
		codigoAssign += "srl "+codigo1->temporal +", "+TemporalActual2+", "+codigo1->temporal+"\n";
		codigoAssign += "sw "+codigo1->temporal+", ("+TemporalActual+") \n ";
		
		freeTemp(TemporalActual);
		freeTemp(TemporalActual2);
	}
	codigo->codigo = codigoAssign;
	codigo->temporal = codigo1->temporal;
	delete codigo1;
}



void MultIgualExpr::generalCodigo(CodigoGenerado * codigo){
	
	CodigoGenerado *codigo1 = new CodigoGenerado();
	
	expr1->generalCodigo(codigo1);
	string codigoAssign;
	codigoAssign = codigo1->codigo; 
	if(nombre->isA(ID_EXPR)){
    string TemporalActual = NewTemp();
    codigoAssign += "lw "+ TemporalActual +", "+ ((VarNombreExpr*)nombre)->index +"\n";
    codigoAssign += "move $a0, "+TemporalActual+"\n";
    codigoAssign += "move $a1, "+codigo1->temporal+"\n";
    codigoAssign += "jal mult\n sw $v0, ";
		codigoAssign += ((VarNombreExpr*)nombre)->index;
		codigoAssign += "\n move "+codigo1->temporal+", $v0\n";
		freeTemp(TemporalActual);
	}else if(nombre->isA(ARRAYNOMBRE_EXPR)){
		CodigoGenerado *codigoValorArray = new CodigoGenerado();
		string TemporalActual = NewTemp();
		string TemporalActual2 = NewTemp();
		((VarNombreArrayExpr*)nombre)->expr1->generalCodigo(codigoValorArray);
		codigoAssign += codigoValorArray->codigo;
		codigoAssign += "sll "+codigoValorArray->temporal+", "+codigoValorArray->temporal+", 2\n";
		codigoAssign += "la "+TemporalActual+ ", "+ ((VarNombreArrayExpr*)nombre)->index +"\n";
		freeTemp(codigoValorArray->temporal);
		codigoAssign += "add "+TemporalActual+", "+TemporalActual+", "+codigoValorArray->temporal+"\n";
		codigoAssign += "lw "+TemporalActual2+", "+"("+TemporalActual+")\n";
		codigoAssign += "move $a0, "+TemporalActual2+"\n";
		codigoAssign += "move $a1, "+codigo1->temporal+"\n";
		codigoAssign += "move $s0, "+TemporalActual+"\n";
		codigoAssign += "jal mult\n";
		codigoAssign += "sw $v0, ($s0) \n ";
		codigoAssign += "move "+codigo1->temporal+", $v0\n";
		freeTemp(TemporalActual);
		freeTemp(TemporalActual2);
	}
	freeTemp(codigo1->temporal);
	codigo->codigo += codigoAssign;
	codigo->temporal = codigo1->temporal;
	delete codigo1;	
}

void DivIgualExpr::generalCodigo(CodigoGenerado * codigo){
	
	CodigoGenerado *codigo1 = new CodigoGenerado();
	
	expr1->generalCodigo(codigo1);
	string codigoAssign;
	codigoAssign = codigo1->codigo; 
	if(nombre->isA(ID_EXPR)){
    string TemporalActual = NewTemp();
    codigoAssign += "lw "+ TemporalActual +", "+ ((VarNombreExpr*)nombre)->index +"\n";
    codigoAssign += "move $a0, "+TemporalActual+"\n";
    codigoAssign += "move $a1, "+codigo1->temporal+"\n";
    codigoAssign += "jal divide\n sw $t1,";
		codigoAssign += ((VarNombreExpr*)nombre)->index;
		codigoAssign += "\n move "+codigo1->temporal+", $t1\n";
		freeTemp(TemporalActual);
	}else if(nombre->isA(ARRAYNOMBRE_EXPR)){
		CodigoGenerado *codigoValorArray = new CodigoGenerado();
		string TemporalActual = NewTemp();
		string TemporalActual2 = NewTemp();
		((VarNombreArrayExpr*)nombre)->expr1->generalCodigo(codigoValorArray);
		codigoAssign += codigoValorArray->codigo;
		codigoAssign += "sll "+codigoValorArray->temporal+", "+codigoValorArray->temporal+", 2\n";
		codigoAssign += "la "+TemporalActual+ ", "+ ((VarNombreArrayExpr*)nombre)->index +"\n";
		freeTemp(codigoValorArray->temporal);
		codigoAssign += "add "+TemporalActual+", "+TemporalActual+", "+codigoValorArray->temporal+"\n";
		codigoAssign += "lw "+TemporalActual2+", "+"("+TemporalActual+")\n";
		codigoAssign += "move $a0, "+TemporalActual2+"\n";
		codigoAssign += "move $a1, "+codigo1->temporal+"\n";
		codigoAssign += "move $s0, "+TemporalActual+"\n";
		codigoAssign += "jal divide\n";
		codigoAssign += "sw $t1, ($s0) \n ";
		codigoAssign += "move "+codigo1->temporal+", $t1\n";
		freeTemp(TemporalActual);
		freeTemp(TemporalActual2);
	}
	freeTemp(codigo1->temporal);
	codigo->codigo += codigoAssign;
	codigo->temporal = codigo1->temporal;
	delete codigo1;	
}


void ModIgualExpr::generalCodigo(CodigoGenerado * codigo){
	
	CodigoGenerado *codigo1 = new CodigoGenerado();
	
	expr1->generalCodigo(codigo1);
	string codigoAssign;
	codigoAssign = codigo1->codigo; 
	if(nombre->isA(ID_EXPR)){
    string TemporalActual = NewTemp();
    codigoAssign += "lw "+ TemporalActual +", "+ ((VarNombreExpr*)nombre)->index +"\n";
    codigoAssign += "move $a0, "+TemporalActual+"\n";
    codigoAssign += "move $a1, "+codigo1->temporal+"\n";
    codigoAssign += "jal divide\n sw $a0,";
		codigoAssign += ((VarNombreExpr*)nombre)->index;
		codigoAssign += "\n move "+codigo1->temporal+", $t1\n";
		freeTemp(TemporalActual);
	}else if(nombre->isA(ARRAYNOMBRE_EXPR)){
		CodigoGenerado *codigoValorArray = new CodigoGenerado();
		string TemporalActual = NewTemp();
		string TemporalActual2 = NewTemp();
		((VarNombreArrayExpr*)nombre)->expr1->generalCodigo(codigoValorArray);
		codigoAssign += codigoValorArray->codigo;
		codigoAssign += "sll "+codigoValorArray->temporal+", "+codigoValorArray->temporal+", 2\n";
		codigoAssign += "la "+TemporalActual+ ", "+ ((VarNombreArrayExpr*)nombre)->index +"\n";
		freeTemp(codigoValorArray->temporal);
		codigoAssign += "add "+TemporalActual+", "+TemporalActual+", "+codigoValorArray->temporal+"\n";
		codigoAssign += "lw "+TemporalActual2+", "+"("+TemporalActual+")\n";
		codigoAssign += "move $a0, "+TemporalActual2+"\n";
		codigoAssign += "move $a1, "+codigo1->temporal+"\n";
		codigoAssign += "move $s0, "+TemporalActual+"\n";
		codigoAssign += "jal divide\n";
		codigoAssign += "sw $a0, ($s0) \n ";
		codigoAssign += "move "+codigo1->temporal+", $t1\n";
		freeTemp(TemporalActual);
		freeTemp(TemporalActual2);
	}
	freeTemp(codigo1->temporal);
	codigo->codigo += codigoAssign;
	codigo->temporal = codigo1->temporal;
	delete codigo1;	
}




void ModIgualStatement::generalCodigo(CodigoGenerado * codigo){
	
	CodigoGenerado *codigo1 = new CodigoGenerado();
	
	expr1->generalCodigo(codigo1);
	string codigoAssign;
	codigoAssign = codigo1->codigo; 
	if(nombre->isA(ID_EXPR)){
    string TemporalActual = NewTemp();
    codigoAssign += "lw "+ TemporalActual +", "+ ((VarNombreExpr*)nombre)->index +"\n";
    codigoAssign += "move $a0, "+TemporalActual+"\n";
    codigoAssign += "move $a1, "+codigo1->temporal+"\n";
    codigoAssign += "jal divide\n sw $a0, ";
		codigoAssign += ((VarNombreExpr*)nombre)->index;
		codigoAssign += "\n";
		freeTemp(TemporalActual);
	}else if(nombre->isA(ARRAYNOMBRE_EXPR)){
		CodigoGenerado *codigoValorArray = new CodigoGenerado();
		string TemporalActual = NewTemp();
		string TemporalActual2 = NewTemp();
		((VarNombreArrayExpr*)nombre)->expr1->generalCodigo(codigoValorArray);
		codigoAssign += codigoValorArray->codigo;
		codigoAssign += "sll "+codigoValorArray->temporal+", "+codigoValorArray->temporal+", 2\n";
		codigoAssign += "la "+TemporalActual+ ", "+ ((VarNombreArrayExpr*)nombre)->index +"\n";
		freeTemp(codigoValorArray->temporal);
		codigoAssign += "add "+TemporalActual+", "+TemporalActual+", "+codigoValorArray->temporal+"\n";
		codigoAssign += "lw "+TemporalActual2+", "+"("+TemporalActual+")\n";
		codigoAssign += "move $a0, "+TemporalActual2+"\n";
		codigoAssign += "move $a1, "+codigo1->temporal+"\n";
		codigoAssign += "move $s0, "+TemporalActual+"\n";
		codigoAssign += "jal divide\n";
		codigoAssign += "sw $a0, ($s0) \n ";
		freeTemp(TemporalActual2);
		freeTemp(TemporalActual);
	}
	freeTemp(codigo1->temporal);
	codigo->codigo += codigoAssign;
	delete codigo1;	
}

void DivIgualStatement::generalCodigo(CodigoGenerado * codigo){
	
	CodigoGenerado *codigo1 = new CodigoGenerado();
	
	expr1->generalCodigo(codigo1);
	string codigoAssign;
	codigoAssign = codigo1->codigo; 
	if(nombre->isA(ID_EXPR)){
    string TemporalActual = NewTemp();
    codigoAssign += "lw "+ TemporalActual +", "+ ((VarNombreExpr*)nombre)->index +"\n";
    codigoAssign += "move $a0, "+TemporalActual+"\n";
    codigoAssign += "move $a1, "+codigo1->temporal+"\n";
    codigoAssign += "jal divide\n sw $t1, ";
		codigoAssign += ((VarNombreExpr*)nombre)->index;
		codigoAssign += "\n";
		freeTemp(TemporalActual);
	}else if(nombre->isA(ARRAYNOMBRE_EXPR)){
		CodigoGenerado *codigoValorArray = new CodigoGenerado();
		string TemporalActual = NewTemp();
		string TemporalActual2 = NewTemp();
		((VarNombreArrayExpr*)nombre)->expr1->generalCodigo(codigoValorArray);
		codigoAssign += codigoValorArray->codigo;
		codigoAssign += "sll "+codigoValorArray->temporal+", "+codigoValorArray->temporal+", 2\n";
		codigoAssign += "la "+TemporalActual+ ", "+ ((VarNombreArrayExpr*)nombre)->index +"\n";
		freeTemp(codigoValorArray->temporal);
		codigoAssign += "add "+TemporalActual+", "+TemporalActual+", "+codigoValorArray->temporal+"\n";
		codigoAssign += "lw "+TemporalActual2+", "+"("+TemporalActual+")\n";
		codigoAssign += "move $a0, "+TemporalActual2+"\n";
		codigoAssign += "move $a1, "+codigo1->temporal+"\n";
		codigoAssign += "move $s0, "+TemporalActual+"\n";
		codigoAssign += "jal divide\n";
		codigoAssign += "sw $t1, ($s0) \n ";
		freeTemp(TemporalActual2);
		freeTemp(TemporalActual);
	}
	freeTemp(codigo1->temporal);
	codigo->codigo += codigoAssign;
	delete codigo1;	
}


void MultIgualStatement::generalCodigo(CodigoGenerado * codigo){
	
	CodigoGenerado *codigo1 = new CodigoGenerado();
	
	expr1->generalCodigo(codigo1);
	string codigoAssign;
	codigoAssign = codigo1->codigo; 
	if(nombre->isA(ID_EXPR)){
    string TemporalActual = NewTemp();
    codigoAssign += "lw "+ TemporalActual +", "+ ((VarNombreExpr*)nombre)->index +"\n";
    codigoAssign += "move $a0, "+TemporalActual+"\n";
    codigoAssign += "move $a1, "+codigo1->temporal+"\n";
    codigoAssign += "jal mult\n sw $v0, ";
		codigoAssign +=  + ((VarNombreExpr*)nombre)->index ;
		codigoAssign += "\n";
		freeTemp(TemporalActual);
	}else if(nombre->isA(ARRAYNOMBRE_EXPR)){
		CodigoGenerado *codigoValorArray = new CodigoGenerado();
		string TemporalActual = NewTemp();
		string TemporalActual2 = NewTemp();
		((VarNombreArrayExpr*)nombre)->expr1->generalCodigo(codigoValorArray);
		codigoAssign += codigoValorArray->codigo;
		codigoAssign += "sll "+codigoValorArray->temporal+", "+codigoValorArray->temporal+", 2\n";
		codigoAssign += "la "+TemporalActual+ ", "+ ((VarNombreArrayExpr*)nombre)->index +"\n";
		freeTemp(codigoValorArray->temporal);
		codigoAssign += "sll "+codigoValorArray->temporal+", "+codigoValorArray->temporal+", 2\n";
		codigoAssign += "add "+TemporalActual+", "+TemporalActual+", "+codigoValorArray->temporal+"\n";
		codigoAssign += "lw "+TemporalActual2+", "+"("+TemporalActual+")\n";
		codigoAssign += "move $a0, "+TemporalActual2+"\n";
		codigoAssign += "move $a1, "+codigo1->temporal+"\n";
		codigoAssign += "move $s0, "+TemporalActual+"\n";
		codigoAssign += "jal mult\n";
		codigoAssign += "sw $v0, ($s0) \n ";
		freeTemp(TemporalActual2);
		freeTemp(TemporalActual);
	}
	freeTemp(codigo1->temporal);
	codigo->codigo += codigoAssign;
	delete codigo1;	
}


void AsigCorDerIgualStatement::generalCodigo(CodigoGenerado * codigo){
	
	CodigoGenerado *codigo1 = new CodigoGenerado();
	
	expr1->generalCodigo(codigo1);
	string codigoAssign = codigo1->codigo; 
	if(nombre->isA(ID_EXPR)){
    string TemporalActual = NewTemp();
    codigoAssign += "lw "+ TemporalActual +", "+ ((VarNombreExpr*)nombre)->index +"\n";
    codigoAssign += "srl "+codigo1->temporal +", "+TemporalActual+", "+codigo1->temporal+"\n";
		codigoAssign += "sw " + codigo1->temporal + ", " + ((VarNombreExpr*)nombre)->index +"\n";
		freeTemp(TemporalActual);
	}else if(nombre->isA(ARRAYNOMBRE_EXPR)){
		CodigoGenerado *codigoValorArray = new CodigoGenerado();
		string TemporalActual = NewTemp();
		string TemporalActual2 = NewTemp();
		((VarNombreArrayExpr*)nombre)->expr1->generalCodigo(codigoValorArray);
		codigoAssign += codigoValorArray->codigo;
		codigoAssign += "sll "+codigoValorArray->temporal+", "+codigoValorArray->temporal+", 2\n";
		codigoAssign += "la "+TemporalActual+ ", "+ ((VarNombreArrayExpr*)nombre)->index +"\n";
		freeTemp(codigoValorArray->temporal);
		codigoAssign += "add "+TemporalActual+", "+TemporalActual+", "+codigoValorArray->temporal+"\n";
		codigoAssign += "lw "+TemporalActual2+", "+"("+TemporalActual+")\n";
		codigoAssign += "srl "+codigo1->temporal +", "+TemporalActual2+", "+codigo1->temporal+"\n";
		codigoAssign += "sw "+codigo1->temporal+", ("+TemporalActual+") \n ";
		freeTemp(TemporalActual2);
		freeTemp(TemporalActual);
	}
	freeTemp(codigo1->temporal);
	codigo->codigo += codigoAssign;
	delete codigo1;	
}

void AsigCorIzqIgualStatement::generalCodigo(CodigoGenerado * codigo){

	CodigoGenerado *codigo1 = new CodigoGenerado();
	expr1->generalCodigo(codigo1);
	string codigoAssign;
	codigoAssign = codigo1->codigo; 
	if(nombre->isA(ID_EXPR)){
    string TemporalActual = NewTemp();
    codigoAssign += "lw "+ TemporalActual +", "+ ((VarNombreExpr*)nombre)->index +"\n";
    codigoAssign += "sll "+codigo1->temporal +", "+TemporalActual+", "+codigo1->temporal+"\n";
		codigoAssign += "sw " + codigo1->temporal + ", " + ((VarNombreExpr*)nombre)->index +"\n";
		freeTemp(TemporalActual);
	}else if(nombre->isA(ARRAYNOMBRE_EXPR)){
		CodigoGenerado *codigoValorArray = new CodigoGenerado();
		string TemporalActual = NewTemp();
		string TemporalActual2 = NewTemp();
		((VarNombreArrayExpr*)nombre)->expr1->generalCodigo(codigoValorArray);
		codigoAssign += codigoValorArray->codigo;
		codigoAssign += "sll "+codigoValorArray->temporal+", "+codigoValorArray->temporal+", 2\n";
		codigoAssign += "la "+TemporalActual+ ", "+ ((VarNombreArrayExpr*)nombre)->index +"\n";
		freeTemp(codigoValorArray->temporal);
		codigoAssign += "add "+TemporalActual+", "+TemporalActual+", "+codigoValorArray->temporal+"\n";
		codigoAssign += "lw "+TemporalActual2+", "+"("+TemporalActual+")\n";
		codigoAssign += "sll "+codigo1->temporal +", "+TemporalActual2+", "+codigo1->temporal+"\n";
		codigoAssign += "sw "+codigo1->temporal+", ("+TemporalActual+") \n ";
		freeTemp(TemporalActual2);
		freeTemp(TemporalActual);
	}
	freeTemp(codigo1->temporal);
	codigo->codigo += codigoAssign;
	delete codigo1;
}

void XorBitIgualStatement::generalCodigo(CodigoGenerado * codigo){
	
	CodigoGenerado *codigo1 = new CodigoGenerado();
	
	expr1->generalCodigo(codigo1);
	string codigoAssign = codigo1->codigo; 

	if(nombre->isA(ID_EXPR)){
    string TemporalActual = NewTemp();
    codigoAssign += "lw "+ TemporalActual +", "+ ((VarNombreExpr*)nombre)->index +"\n";
    codigoAssign += "xor "+codigo1->temporal +", "+codigo1->temporal+", "+TemporalActual+"\n";
		codigoAssign += "sw " + codigo1->temporal + ", " + ((VarNombreExpr*)nombre)->index +"\n";
		freeTemp(TemporalActual);
	}else if(nombre->isA(ARRAYNOMBRE_EXPR)){
		CodigoGenerado *codigoValorArray = new CodigoGenerado();
		string TemporalActual = NewTemp();
		string TemporalActual2 = NewTemp();
		((VarNombreArrayExpr*)nombre)->expr1->generalCodigo(codigoValorArray);
		codigoAssign += codigoValorArray->codigo;
		codigoAssign += "sll "+codigoValorArray->temporal+", "+codigoValorArray->temporal+", 2\n";
		codigoAssign += "la "+TemporalActual+ ", "+ ((VarNombreArrayExpr*)nombre)->index +"\n";
		freeTemp(codigoValorArray->temporal);
		codigoAssign += "add "+TemporalActual+", "+TemporalActual+", "+codigoValorArray->temporal+"\n";
		codigoAssign += "lw "+TemporalActual2+", "+"("+TemporalActual+")\n";
		codigoAssign += "xor "+codigo1->temporal +", "+codigo1->temporal+", "+TemporalActual2+"\n";
		codigoAssign += "sw "+codigo1->temporal+", ("+TemporalActual+") \n ";
		freeTemp(TemporalActual);
		freeTemp(TemporalActual2);
	}
	freeTemp(codigo1->temporal);
	codigo->codigo += codigoAssign;
	delete codigo1;	
}

void AndBitIgualStatement::generalCodigo(CodigoGenerado * codigo){
	
	CodigoGenerado *codigo1 = new CodigoGenerado();
	
	expr1->generalCodigo(codigo1);
	string codigoAssign;
	codigoAssign = codigo1->codigo; 
	if(nombre->isA(ID_EXPR)){
    string TemporalActual = NewTemp();
    codigoAssign += "lw "+ TemporalActual +", "+ ((VarNombreExpr*)nombre)->index +"\n";
    codigoAssign += "and "+codigo1->temporal +", "+codigo1->temporal+", "+TemporalActual+"\n";
		codigoAssign += "sw " + codigo1->temporal + ", " + ((VarNombreExpr*)nombre)->index +"\n";
		freeTemp(TemporalActual);
	}else if(nombre->isA(ARRAYNOMBRE_EXPR)){
		CodigoGenerado *codigoValorArray = new CodigoGenerado();
		string TemporalActual = NewTemp();
		string TemporalActual2 = NewTemp();
		((VarNombreArrayExpr*)nombre)->expr1->generalCodigo(codigoValorArray);
		codigoAssign += codigoValorArray->codigo;
		codigoAssign += "sll "+codigoValorArray->temporal+", "+codigoValorArray->temporal+", 2\n";
		codigoAssign += "la "+TemporalActual+ ", "+ ((VarNombreArrayExpr*)nombre)->index +"\n";
		freeTemp(codigoValorArray->temporal);
			codigoAssign += "add "+TemporalActual+", "+TemporalActual+", "+codigoValorArray->temporal+"\n";
		codigoAssign += "lw "+TemporalActual2+", "+"("+TemporalActual+")\n";
		codigoAssign += "and "+codigo1->temporal +", "+codigo1->temporal+", "+TemporalActual2+"\n";
		codigoAssign += "sw "+codigo1->temporal+", ("+TemporalActual+") \n ";
		freeTemp(TemporalActual);
		freeTemp(TemporalActual2);
	}
	freeTemp(codigo1->temporal);
	codigo->codigo += codigoAssign;
	delete codigo1;	
}

void OrBitIgualStatement::generalCodigo(CodigoGenerado * codigo){
	
	CodigoGenerado *codigo1 = new CodigoGenerado();
	
	expr1->generalCodigo(codigo1);
	string codigoAssign;
	codigoAssign = codigo1->codigo; 
	if(nombre->isA(ID_EXPR)){
    string TemporalActual = NewTemp();
    codigoAssign += "lw "+ TemporalActual +", "+ ((VarNombreExpr*)nombre)->index +"\n";
    codigoAssign += "or "+codigo1->temporal +", "+codigo1->temporal+", "+TemporalActual+"\n";
		codigoAssign += "sw " + codigo1->temporal + ", " + ((VarNombreExpr*)nombre)->index +"\n";
		freeTemp(TemporalActual);
	}else if(nombre->isA(ARRAYNOMBRE_EXPR)){
		CodigoGenerado *codigoValorArray = new CodigoGenerado();
		string TemporalActual = NewTemp();
		string TemporalActual2 = NewTemp();
		((VarNombreArrayExpr*)nombre)->expr1->generalCodigo(codigoValorArray);
		codigoAssign += codigoValorArray->codigo;
		codigoAssign += "sll "+codigoValorArray->temporal+", "+codigoValorArray->temporal+", 2\n";
		codigoAssign += "la "+TemporalActual+ ", "+ ((VarNombreArrayExpr*)nombre)->index +"\n";
		freeTemp(codigoValorArray->temporal);
		codigoAssign += "add "+TemporalActual+", "+TemporalActual+", "+codigoValorArray->temporal+"\n";
		codigoAssign += "lw "+TemporalActual2+", "+"("+TemporalActual+")\n";
		codigoAssign += "or "+codigo1->temporal +", "+codigo1->temporal+", "+TemporalActual2+"\n";
		codigoAssign += "sw "+codigo1->temporal+", ("+TemporalActual+") \n ";
		freeTemp(TemporalActual2);
		freeTemp(TemporalActual);
	}
	freeTemp(codigo1->temporal);
	codigo->codigo += codigoAssign;
	delete codigo1;
}


void MenosIgualStatement::generalCodigo(CodigoGenerado * codigo){
	
	CodigoGenerado *codigo1 = new CodigoGenerado();
	
	expr1->generalCodigo(codigo1);
	string codigoAssign;
	codigoAssign = codigo1->codigo; 
	if(nombre->isA(ID_EXPR)){
    string TemporalActual = NewTemp();
    codigoAssign += "lw "+ TemporalActual +", "+ ((VarNombreExpr*)nombre)->index +"\n";
    codigoAssign += "sub "+codigo1->temporal +", "+codigo1->temporal+", "+TemporalActual+"\n";
		codigoAssign += "sw " + codigo1->temporal + ", " + ((VarNombreExpr*)nombre)->index +"\n";
		freeTemp(TemporalActual);
	}else if(nombre->isA(ARRAYNOMBRE_EXPR)){
		CodigoGenerado *codigoValorArray = new CodigoGenerado();
		string TemporalActual = NewTemp();
		string TemporalActual2 = NewTemp();
		((VarNombreArrayExpr*)nombre)->expr1->generalCodigo(codigoValorArray);
		codigoAssign += codigoValorArray->codigo;
		codigoAssign += "sll "+codigoValorArray->temporal+", "+codigoValorArray->temporal+", 2\n";
		codigoAssign += "la "+TemporalActual+ ", "+ ((VarNombreArrayExpr*)nombre)->index +"\n";
		freeTemp(codigoValorArray->temporal);
		codigoAssign += "add "+TemporalActual+", "+TemporalActual+", "+codigoValorArray->temporal+"\n";
		codigoAssign += "lw "+TemporalActual2+", "+"("+TemporalActual+")\n";
		codigoAssign += "sub "+codigo1->temporal +", "+TemporalActual2+", "+codigo1->temporal+"\n";
		codigoAssign += "sw "+codigo1->temporal+", ("+TemporalActual+") \n ";
		freeTemp(TemporalActual2);
		freeTemp(TemporalActual);
	}
	freeTemp(codigo1->temporal);
	codigo->codigo += codigoAssign;
	delete codigo1;
}

void MasIgualStatement::generalCodigo(CodigoGenerado * codigo){
	
	CodigoGenerado *codigo1 = new CodigoGenerado();
	
	expr1->generalCodigo(codigo1);
	string codigoAssign;
	codigoAssign = codigo1->codigo+"\n"; 
	if(nombre->isA(ID_EXPR)){
    string TemporalActual = NewTemp();
    codigoAssign += "lw "+ TemporalActual +", "+ ((VarNombreExpr*)nombre)->index +"\n";
    codigoAssign += "add "+codigo1->temporal +", "+codigo1->temporal+", "+TemporalActual+"\n";
		codigoAssign += "sw " + codigo1->temporal + ", " + ((VarNombreExpr*)nombre)->index +"\n";
		freeTemp(TemporalActual);
	}else if(nombre->isA(ARRAYNOMBRE_EXPR)){
		CodigoGenerado *codigoValorArray = new CodigoGenerado();
		string TemporalActual = NewTemp();
		string TemporalActual2 = NewTemp();
		((VarNombreArrayExpr*)nombre)->expr1->generalCodigo(codigoValorArray);
		codigoAssign += codigoValorArray->codigo;
		codigoAssign += "sll "+codigoValorArray->temporal+", "+codigoValorArray->temporal+", 2\n";
		codigoAssign += "la "+TemporalActual+ ", "+ ((VarNombreArrayExpr*)nombre)->index +"\n";
		freeTemp(codigoValorArray->temporal);
		codigoAssign += "add "+TemporalActual+", "+TemporalActual+", "+codigoValorArray->temporal+"\n";
		codigoAssign += "lw "+TemporalActual2+", "+"("+TemporalActual+")\n";
		codigoAssign += "add "+codigo1->temporal +", "+codigo1->temporal+", "+TemporalActual2+"\n";
		codigoAssign += "sw "+codigo1->temporal+", ("+TemporalActual+") \n ";
		freeTemp(TemporalActual);
		freeTemp(TemporalActual2);
	}
	freeTemp(codigo1->temporal);
	codigo->codigo += codigoAssign;
	delete codigo1;
}

void AsignarStatement::generalCodigo(CodigoGenerado * codigo){
	
	CodigoGenerado *codigo1 = new CodigoGenerado();
	
	expr1->generalCodigo(codigo1);
	string codigoAssign;
	codigoAssign = codigo1->codigo; 
	if(nombre->isA(ID_EXPR)){
    
		codigoAssign += "sw " + codigo1->temporal + ", " + ((VarNombreExpr*)nombre)->index +"\n";
	}else if(nombre->isA(ARRAYNOMBRE_EXPR)){
		CodigoGenerado *codigoValorArray = new CodigoGenerado();
		string TemporalActual = NewTemp();
		((VarNombreArrayExpr*)nombre)->expr1->generalCodigo(codigoValorArray);
		codigoAssign += codigoValorArray->codigo;
		codigoAssign += "sll "+codigoValorArray->temporal+", "+codigoValorArray->temporal+", 2\n";
		codigoAssign += "la "+TemporalActual+ ", "+ ((VarNombreArrayExpr*)nombre)->index +"\n";
		freeTemp(codigoValorArray->temporal);
		codigoAssign += "sll "+codigoValorArray->temporal+", "+codigoValorArray->temporal+", 2\n";
		codigoAssign += "add "+TemporalActual+", "+TemporalActual+", "+codigoValorArray->temporal+"\n";
		codigoAssign += "sw "+codigo1->temporal+", ("+TemporalActual+") \n ";
		freeTemp(TemporalActual);
	}
	freeTemp(codigo1->temporal);
	codigo->codigo += codigoAssign;
	delete codigo1;
}




void SrandStatement::generalCodigo(CodigoGenerado * codigo){
	

	string codigoCall;
		string TemporalActual = NewTemp();
		codigoCall = "li "+TemporalActual +", MS_COUNTER_REG_ADDR \n";		
		codigoCall += "move $a0, "+TemporalActual +"\n";
		codigoCall += "jal rand_seed \n";
		freeTemp(TemporalActual);
		codigo->codigo += codigoCall;
	
}
void BlockStatement::generalCodigo(CodigoGenerado * codigo){
	
	if(!listStatement.empty())
	{
		list<Statement*>::iterator pos;

		pos = listStatement.begin();
		while(pos != listStatement.end())
		{ 
		
			(*pos)->generalCodigo(codigo);
			pos++;
			
		}
	}else{
		codigo = new CodigoGenerado();
	}
}

void PrintSoloStatement::generalCodigo(CodigoGenerado * codigo){

data += " msg"+to_string(cantidadMsg)+":.asciz \""+ stringtxt+"\" \n";
		string codigoPrint;
	string TemporalActual = NewTemp();
	codigoPrint = "la "+ TemporalActual +", msg"+to_string(cantidadMsg++)+"\n";
	
	codigoPrint += "move $a0, "+TemporalActual+"\n";        
	codigoPrint += "jal puts\n";
	codigo->codigo += codigoPrint;

}
void PrintStatement::generalCodigo(CodigoGenerado * codigo){
		
 vector<string> listapalabras = split(stringtxt);

 vector<string>::iterator palabras = listapalabras.begin();
 
 ExprList::iterator pos;
 if(!lista->empty()&& lista !=NULL)
 	 pos = lista->begin();

while(palabras != listapalabras.end()){
		data += " msg"+to_string(cantidadMsg)+":.asciz \""+(*palabras)+"\" \n";
		string codigoPrint;
	string TemporalActual = NewTemp();
	codigoPrint = "la "+ TemporalActual +", msg"+to_string(cantidadMsg++)+"\n";
	
	codigoPrint += "move $a0, "+TemporalActual+"\n";        
	codigoPrint += "jal puts\n";

	freeTemp(TemporalActual);
	palabras++;
	if(!lista->empty()  && palabras != listapalabras.end() && lista != NULL)
	{
		if(pos != lista->end()){
			CodigoGenerado *codigo = new CodigoGenerado();
			(*pos)->generalCodigo(codigo);
			
			freeTemp(codigo->temporal);
			codigoPrint += codigo->codigo;      
			if((*pos)->isA(STRING_EXPR))
			{
				codigoPrint += "move $a0, "+codigo->temporal+"\n";        
				codigoPrint += "jal puts\n";
			}else if ((*pos)->isA(CHAR_EXPR)) {
				codigoPrint += "move $a0, "+codigo->temporal+"\n";        
				codigoPrint += "jal put_char\n";
			}else{
				codigoPrint += "move $a0, "+codigo->temporal+"\n";        
				codigoPrint += "jal put_udecimal\n";      
			}
			pos++;
		} 
	}
		codigo->codigo += codigoPrint;

	}

}


void If_Statement::generalCodigo(CodigoGenerado * codigo){
 
	string codigoIf;  
	CodigoGenerado *codigoCond = new CodigoGenerado();
	CodigoGenerado *codigoTrue = new CodigoGenerado();
	CodigoGenerado *codigoFalse = new CodigoGenerado();
	
	expr->generalCodigo(codigoCond);
	ifStatement->generalCodigo(codigoTrue);
	
	
	freeTemp(codigoCond->temporal);
	
	codigoIf = "if"+to_string(cantidadIf)+": \n";
	codigoIf += "\t" + codigoCond->codigo;
	codigoIf += "\t beqz "+codigoCond->temporal+", .else"+to_string(cantidadIf)+" \n";
	codigoIf += codigoTrue->codigo;
	codigoIf += "\t j .endif"+to_string(cantidadIf)+" \n";
	codigoIf +=".else"+to_string(cantidadIf)+":\n";
	
	if( elseStatement != NULL){
		elseStatement->generalCodigo(codigoFalse);
		codigoIf += codigoFalse->codigo;
	} 
	codigoIf += "\t j .endif"+to_string(cantidadIf)+" \n";  
	codigoIf += ".endif"+to_string(cantidadIf++)+": \n";
		
	delete codigoCond;
	delete codigoTrue;
	delete codigoFalse;
	codigo->codigo += codigoIf;
	
}

void While_Statement::generalCodigo(CodigoGenerado * codigo){

	string codigoWhile; 
	CodigoGenerado *codigoCond = new CodigoGenerado();
	CodigoGenerado *codigoBlock = new CodigoGenerado();
	
	expr->generalCodigo(codigoCond);
	whileStatement->generalCodigo(codigoBlock);
	
	
	freeTemp(codigoCond->temporal);
	
	codigoWhile = "while"+to_string(cantidadWhile)+":\n";
	codigoWhile += "\t" + codigoCond->codigo;
	codigoWhile += "\t beqz "+codigoCond->temporal+", .endWhile"+to_string(cantidadWhile)+" \n";
	codigoWhile += codigoBlock->codigo;
	codigoWhile += "\t j while"+to_string(cantidadWhile)+" \n";
	codigoWhile += ".endWhile"+to_string(cantidadWhile++)+": \n";
		
	delete codigoCond;
	delete codigoBlock;
	codigo->codigo += codigoWhile;
	
}

void For_Statement::generalCodigo(CodigoGenerado * codigo){

		
	CodigoGenerado *codigoStart = new CodigoGenerado(); 
	CodigoGenerado *codigoIncremento = new CodigoGenerado();
	CodigoGenerado *codigoCond = new CodigoGenerado();  
	CodigoGenerado *codigoBlock = new CodigoGenerado();
	if(inicializacion != NULL)
	inicializacion->generalCodigo(codigoStart);
	condicional->generalCodigo(codigoCond);
	if(incremento != NULL)
	incremento->generalCodigo(codigoIncremento);
	ForStatement->generalCodigo(codigoBlock);
	
	freeTemp(codigoCond->temporal);
	string TemporalActual = NewTemp();
	
	string codigoFor = "";
	if(inicializacion != NULL)
	codigoFor = codigoStart->codigo;
	codigoFor += "for"+to_string(cantidadFor)+": \n";
	codigoFor += codigoCond->codigo;
	codigoFor += "\t beqz "+codigoCond->temporal+", .endFor"+to_string(cantidadFor)+" \n";
	codigoFor += codigoBlock->codigo;
	if(incremento != NULL)
	codigoFor += codigoIncremento->codigo;
		codigoFor += "\t j for"+to_string(cantidadFor)+" \n";
	codigoFor += ".endFor"+to_string(cantidadFor++)+": \n";
	
	
	delete codigoStart;
	delete codigoIncremento;
	delete codigoBlock;
	delete codigoCond;

	codigo->codigo += codigoFor;
		
}

void DoWhile_Statement::generalCodigo(CodigoGenerado * codigo){

	string codigoDoWhile; 
	CodigoGenerado *codigoCond = new CodigoGenerado();
	CodigoGenerado *codigoBlock = new CodigoGenerado();
	
	expr->generalCodigo(codigoCond);
	DowhileStatement->generalCodigo(codigoBlock);
	
	
	freeTemp(codigoCond->temporal);
	
	codigoDoWhile = "Dowhile"+to_string(cantidadDoWhile)+":\n";
	codigoDoWhile += codigoBlock->codigo;
	codigoDoWhile += "\t" + codigoCond->codigo;
	codigoDoWhile += "\t beqz "+codigoCond->temporal+", .endDoWhile"+to_string(cantidadDoWhile)+" \n";
	codigoDoWhile += "\t j Dowhile"+to_string(cantidadDoWhile)+" \n";
	codigoDoWhile += ".endDoWhile"+to_string(cantidadDoWhile++)+": \n";
		
	delete codigoCond;
	delete codigoBlock;
	codigo->codigo += codigoDoWhile;
	
}
void Producer_Statement :: generalCodigo(CodigoGenerado * codigo){
	string codigoFuncion =string(nombre)+ ": \n";   
	if(parametros != NULL){
		CodigoGenerado *codigoParametro = new CodigoGenerado();
		parametros->generalCodigo(codigoParametro);
		list<Parametro*>::iterator pos = ((Parametros*)parametros)->listParametro.begin();
		int posInt = 0;
		while(pos != ((Parametros*)parametros)->listParametro.end() )
		{
				
			data += string(((DecVariableStatement*)(*pos)->declaracion)->nombre) +":.word 0 \n";
			codigoFuncion += "sw $a"+to_string(posInt++)+", "+((DecVariableStatement*)(*pos)->declaracion)->nombre+" \n";
		/*	string TemporalActual = NewTemp();
			guardar += "lw "+TemporalActual+", "+((DecVariableStatement*)(*pos)->declaracion)->nombre+"\n";
			guardar += "sw "+TemporalActual+", "+to_string(sp_val)+"($sp)\n";
      
      salvar +=  "lw "+TemporalActual+", "+to_string(sp_val)+"($sp)\n";
      salvar += "sw "+TemporalActual+", "+((DecVariableStatement*)(*pos)->declaracion)->nombre+"\n";
      freeTemp(TemporalActual);
			sp_val += 4;*/
			pos++;
		}
		delete codigoParametro;
		freeTemp(codigoParametro->temporal);
	}
	if(producerStatement != NULL){
		/*enFuncion = true;
   
	string antes = "addi $sp, $sp,";
	guardar += "sw $ra, ($sp)\n";
	salvar += "lw $ra, ($sp)\n";*/
		codigoFuncion += "addi $sp, $sp, -4\n sw $ra, ($sp)\n";	
	
	CodigoGenerado *codigoPocedimiento = new CodigoGenerado();
	producerStatement->generalCodigo(codigoPocedimiento);
	//codigoFuncion += antes+" -" +to_string(sp_val)+"\n" + guardar;
	codigoFuncion += codigoPocedimiento->codigo;
	//codigoFuncion += salvar+ antes +to_string(sp_val)+"\n";
	codigoFuncion += ".epilogo"+to_string(cantidadFunciones++)+":\n lw $ra, ($sp)\n addi $sp, $sp, 4\n";
	delete codigoPocedimiento;  
	/*enFuncion = false;
		guardar = " ";
	salvar = " ";
	sp_val = 0;*/
	}
	codigoFuncion += "jr $ra\n";
	codigo->codigo += codigoFuncion;
	  
}

void Funcion_Statement :: generalCodigo(CodigoGenerado * codigo){
	string codigoFuncion ="\n\n"+string(nombre)+ ": \n";     
	if(parametros != NULL){
		CodigoGenerado *codigoParametro = new CodigoGenerado();
		parametros->generalCodigo(codigoParametro);
		list<Parametro*>::iterator pos = ((Parametros*)parametros)->listParametro.begin();
		int posInt = 0;
		while(pos != ((Parametros*)parametros)->listParametro.end())
		{
			data += string(((DecVariableStatement*)(*pos)->declaracion)->nombre) +":.word 0 \n";
			codigoFuncion += "sw $a"+to_string(posInt++)+", "+((DecVariableStatement*)(*pos)->declaracion)->nombre+" \n";
        /*
 			string TemporalActual = NewTemp();
			guardar += "lw "+TemporalActual+", "+((DecVariableStatement*)(*pos)->declaracion)->nombre+"\n";
			guardar += "sw "+TemporalActual+", "+to_string(sp_val)+"($sp)\n";
      
      salvar +=  "lw "+TemporalActual+", "+to_string(sp_val)+"($sp)\n";
      salvar += "sw "+TemporalActual+", "+((DecVariableStatement*)(*pos)->declaracion)->nombre+"\n";
      freeTemp(TemporalActual);
			sp_val += 4;*/
			pos++;

		}
		delete codigoParametro;
	}
	if(funcionStatement != NULL){
    /*string antes ="";
	enFuncion = true;
	antes = "addi $sp, $sp,";
	guardar += "sw $ra, ($sp)\n";
	salvar += "lw $ra, ($sp)\n";
 */codigoFuncion += "addi $sp, $sp, -4\n sw $ra, ($sp)\n";	
	
	CodigoGenerado *codigoPocedimiento = new CodigoGenerado();
	funcionStatement->generalCodigo(codigoPocedimiento);
	//codigoFuncion += antes+" -" +to_string(sp_val)+"\n" + guardar;
	codigoFuncion += codigoPocedimiento->codigo;
	//codigoFuncion += salvar+ antes +to_string(sp_val)+"\n";

		delete codigoPocedimiento;
	/*enFuncion = false;
	guardar = " ";
	salvar = " ";
	sp_val = 4;
*/	codigoFuncion += ".epilogo"+to_string(cantidadFunciones++)+":\n lw $ra, ($sp)\n addi $sp, $sp, 4\n";
	}
	codigoFuncion += "jr $ra\n";

	codigo->codigo += codigoFuncion;
  
}

void CallFuncionStatement :: generalCodigo(CodigoGenerado * codigo){
	string codigoFuncion =" ";    
	if(parametros != NULL){
		ExprList::iterator pos = parametros->begin();
		int posInt = 0;
		while(pos != parametros->end() )
		{
			CodigoGenerado *codigoParametro = new CodigoGenerado();
				(*pos)->generalCodigo(codigoParametro);
				codigoFuncion += codigoParametro->codigo;

			codigoFuncion += "move $a"+to_string(posInt++)+", "+codigoParametro->temporal+" \n";
			freeTemp(codigoParametro->temporal);
		pos++;
		}
		
	}
	codigoFuncion += "jal ";
	codigoFuncion +=string(nombre)+ " \n";
	codigo->codigo += codigoFuncion;  

}

void Return_Statement :: generalCodigo(CodigoGenerado * codigo){
	 string codigoRetorno =" "; 
	if(returnExpr != NULL){
		CodigoGenerado *codigoReturn = new CodigoGenerado();
		returnExpr->generalCodigo(codigoReturn);
		codigo->codigo += codigoReturn->codigo;
		codigoRetorno += "move $v0 ,"+codigoReturn->temporal+"\n";
		freeTemp(codigoReturn->temporal);
	}

	
		
	codigoRetorno += "j .epilogo"+to_string(cantidadFunciones)+" \n";
	codigo->codigo += codigoRetorno;
}


void DecVariableStatement:: generalCodigo(CodigoGenerado * codigo){
		string codigoDec = " ";
		data += string(nombre)+ ": .word ";
		if(inicializar !=NULL){
			if(inicializar->isA(NUM_EXPR)){
				data+= to_string(((NumberExpr*)inicializar)->value)+"\n";
			}else if(inicializar->isA(CHAR_EXPR)) {
				data += "\'";
				data += ((CharExpr*)inicializar)->value;
				data += "\' \n";
			}
			else{
				data += "0 \n";
				CodigoGenerado *declaracion = new CodigoGenerado();
				inicializar->generalCodigo(declaracion);
				codigoDec +=declaracion->codigo;
				codigoDec += "sw "+declaracion->temporal +", "+string(nombre);
			}
		}else{
			data += "0 \n";
		}
		codigo->codigo += codigoDec +"\n";
		
		/*if(enFuncion == true)
		{
			string TemporalActual = NewTemp();
			guardar += "lw "+TemporalActual+", "+string(nombre)+"\n";
			guardar += "sw "+TemporalActual+", "+to_string(sp_val)+"($sp)\n";
      
      salvar +=  "lw "+TemporalActual+", "+to_string(sp_val)+"($sp)\n";
      salvar += "sw "+TemporalActual+", "+string(nombre)+"\n";
      freeTemp(TemporalActual);
			sp_val += 4;
		}*/	
		if(multideclatation != NULL)
		multideclatation->generalCodigo(codigo);
}

void DecArrayStatement:: generalCodigo(CodigoGenerado * codigo){
		string codigoDec = " ";
		data += string(nombre)+ ": .word ";
		if(inicializar!=NULL){
			ExprList::iterator pos = ((ArrayExpr*)inicializar)->value->begin();
			 while(pos != ((ArrayExpr*)inicializar)->value->end()){
				if((*pos)->isA(NUM_EXPR))
					data+= to_string(((NumberExpr*)*pos)->value);
				else if((*pos)->isA(CHAR_EXPR))
					data += ((CharExpr*)*pos)->value;
				pos++;
				if(pos != ((ArrayExpr*)inicializar)->value->end())
					data+=",";
			 }
			 data += "\n";
		}else{
			data += "0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 \n";
		}
		codigo->codigo += codigoDec +"\n";

		if(multideclatation != NULL)
			multideclatation->generalCodigo(codigo);
}
void PreIncrementoStatement::generalCodigo(CodigoGenerado * codigo){
	string codigoIncre; 
	CodigoGenerado *codigoValor = new CodigoGenerado();

	expr1->generalCodigo(codigoValor);


	string TemporalActual = NewTemp();
	codigoIncre = codigoValor->codigo;
	codigoIncre += "addi "+TemporalActual +", "+codigoValor->temporal+", 1 \n";
	if(expr1->isA(ID_EXPR)){
		string id = ((VarNombreExpr*)expr1)->index;
		codigoIncre += "sw "+TemporalActual +", "+id +"\n";
		
	}else if(expr1->isA(ARRAYNOMBRE_EXPR))
	{
		CodigoGenerado *codigoValorArray = new CodigoGenerado();
		((VarNombreArrayExpr*)expr1)->expr1->generalCodigo(codigoValorArray);
		string TemporalActual2 = NewTemp();
		codigoIncre += codigoValorArray->codigo;
		codigoIncre += "sll "+codigoValorArray->temporal+", "+codigoValorArray->temporal+", 2\n";
		codigoIncre += "la "+TemporalActual2 +", "+((VarNombreArrayExpr*)expr1)->index;
		codigoIncre += "\n add "+TemporalActual2 +", "+TemporalActual2 +", "+codigoValorArray->temporal+"\n"; 
		codigoIncre += "sw "+TemporalActual +", ("+ TemporalActual2+")\n";
		freeTemp(TemporalActual2);
		freeTemp(codigoValorArray->temporal);
	}
	freeTemp(codigoValor->temporal);
	freeTemp(TemporalActual);
	codigo->codigo += codigoIncre ;
	
}
void PreDecrementoStatement::generalCodigo(CodigoGenerado * codigo){
	string codigoIncre; 
	CodigoGenerado *codigoValor = new CodigoGenerado();

	expr1->generalCodigo(codigoValor);
	
	string TemporalActual = NewTemp();
	codigoIncre = codigoValor->codigo;
	codigoIncre += "addi "+TemporalActual +", "+codigoValor->temporal+", -1 \n";
	if(expr1->isA(ID_EXPR)){
		string id = ((VarNombreExpr*)expr1)->index;
		codigoIncre += "sw "+TemporalActual +", "+id +"\n";
		
	}else if(expr1->isA(ARRAYNOMBRE_EXPR))
	{
		CodigoGenerado *codigoValorArray = new CodigoGenerado();
		((VarNombreArrayExpr*)expr1)->expr1->generalCodigo(codigoValorArray);
		string TemporalActual2 = NewTemp();
		codigoIncre += codigoValorArray->codigo;
		codigoIncre += "sll "+codigoValorArray->temporal+", "+codigoValorArray->temporal+", 2\n";
		codigoIncre += "la "+TemporalActual2 +", "+((VarNombreArrayExpr*)expr1)->index;
		codigoIncre += "\n add "+TemporalActual2 +", "+TemporalActual2 +", "+codigoValorArray->temporal+"\n"; 
		codigoIncre += "sw "+TemporalActual +", ("+ TemporalActual2+")\n";
		freeTemp(TemporalActual2);
		freeTemp(codigoValorArray->temporal);
	}

	freeTemp(codigoValor->temporal);
	freeTemp(TemporalActual);
	codigo->codigo += codigoIncre ;
	
}


void PosIncrementoStatement::generalCodigo(CodigoGenerado * codigo){
	string codigoIncre; 
	CodigoGenerado *codigoValor = new CodigoGenerado();

	expr1->generalCodigo(codigoValor);
	
	string TemporalActual = NewTemp();
	codigoIncre = codigoValor->codigo;
	codigoIncre += "addi "+TemporalActual +", "+codigoValor->temporal+", 1 \n";
	if(expr1->isA(ID_EXPR)){
		string id = ((VarNombreExpr*)expr1)->index;
		codigoIncre += "sw "+TemporalActual +", "+id +"\n";
		
	}else if(expr1->isA(ARRAYNOMBRE_EXPR))
	{
		CodigoGenerado *codigoValorArray = new CodigoGenerado();
		((VarNombreArrayExpr*)expr1)->expr1->generalCodigo(codigoValorArray);
		string TemporalActual2 = NewTemp();
		codigoIncre += codigoValorArray->codigo;
		codigoIncre += "sll "+codigoValorArray->temporal+", "+codigoValorArray->temporal+", 2\n";
		codigoIncre += "la "+TemporalActual2 +", "+((VarNombreArrayExpr*)expr1)->index;
		codigoIncre += "\n add "+TemporalActual2 +", "+TemporalActual2 +", "+codigoValorArray->temporal+"\n"; 
		codigoIncre += "sw "+TemporalActual +", ("+ TemporalActual2+")\n";
		freeTemp(TemporalActual2);
		freeTemp(codigoValorArray->temporal);
	}
	freeTemp(codigoValor->temporal);
	freeTemp(TemporalActual);
	codigo->codigo += codigoIncre;
	
}
void PosDecrementoStatement::generalCodigo(CodigoGenerado * codigo){
	string codigoIncre; 

	CodigoGenerado *codigoValor = new CodigoGenerado();

	expr1->generalCodigo(codigoValor);
	string TemporalActual = NewTemp();
	codigoIncre = codigoValor->codigo;
	codigoIncre += "addi "+TemporalActual +", "+codigoValor->temporal+", -1 \n";
	if(expr1->isA(ID_EXPR)){
		string id = ((VarNombreExpr*)expr1)->index;
		codigoIncre += "sw "+TemporalActual +", "+id +"\n";
		
	}else if(expr1->isA(ARRAYNOMBRE_EXPR))
	{
		CodigoGenerado *codigoValorArray = new CodigoGenerado();
		((VarNombreArrayExpr*)expr1)->expr1->generalCodigo(codigoValorArray);
		string TemporalActual2 = NewTemp();
		codigoIncre += codigoValorArray->codigo;
		codigoIncre += "sll "+codigoValorArray->temporal+", "+codigoValorArray->temporal+", 2\n";
		codigoIncre += "la "+TemporalActual2 +", "+((VarNombreArrayExpr*)expr1)->index;
		codigoIncre += "\n add "+TemporalActual2 +", "+TemporalActual2 +", "+codigoValorArray->temporal+"\n"; 
		codigoIncre += "sw "+TemporalActual +", ("+ TemporalActual2+")\n";
		freeTemp(TemporalActual2);
		freeTemp(codigoValorArray->temporal);
	}
	freeTemp(TemporalActual);
	freeTemp(codigoValor->temporal);
	codigo->codigo += codigoIncre ;
	
}