  #include "ash.h"
#include <stdio.h>
#include <cstring>
#include <stdlib.h>

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
int cantidadFor =0;
int cantidadMsg =0;

string data="#include \"screen.h\"\n #include \"system.h\"\n.global main\n.data\n";


string NewTemp() {
    std::map<string, bool>::iterator it=TemporalesMaps.begin();
    while (it!=TemporalesMaps.end()){
        if(!it->second) {
            TemporalesMaps[it->first] = true;
            return it->first;
        }
	it++;
     }
}

void freeTemp(string temporal) {
    if(TemporalesMaps[temporal])
        TemporalesMaps[temporal] = false;
}

Tipo* ArrayExpr :: ValidateSemantic(){
  ExprList::iterator it = value->begin();
    Expr * primero = *it;
    while (it != value->end()) {
      Expr * st = *it;
       if(!st->ValidateSemantic()->isA(primero->ValidateSemantic()->getKind())){
         cout<< "Error : arreglo de diferentes tipos linea " << yylineno <<  endl;
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
  if(valor->isA(arrayTipo) || expr1->ValidateSemantic()->isA(arrayTipo)||\
    valor->isA(procedimientoTipo) || expr1->ValidateSemantic()->isA(procedimientoTipo)){\
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
IMPLEMENT_BINARY_EXPR_SEMANTIC(MasIgual);
IMPLEMENT_BINARY_EXPR_SEMANTIC(MenosIgual);
IMPLEMENT_BINARY_EXPR_SEMANTIC(MultIgual);
IMPLEMENT_BINARY_EXPR_SEMANTIC(DivIgual);
IMPLEMENT_BINARY_EXPR_SEMANTIC(ModIgual);
IMPLEMENT_BINARY_EXPR_SEMANTIC(OrBitIgual);
IMPLEMENT_BINARY_EXPR_SEMANTIC(AndBitIgual);
IMPLEMENT_BINARY_EXPR_SEMANTIC(XorBitIgual);
IMPLEMENT_BINARY_EXPR_SEMANTIC(AsigCorIzqIgual);
IMPLEMENT_BINARY_EXPR_SEMANTIC(AsigCorDerIgual);


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
IMPLEMENT_INOUT_STATEMENT_SEMANTIC(Scanf);

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
    if(parametros == NULL && ((FuncionTipo*)tipo)->parametros != NULL){
       cout<< "Error : demasiados parametros en la funcion "<< nombre <<" linea " <<yylineno << endl;
        exit(0);
    }else if(parametros->size() != ((FuncionTipo*)tipo)->parametros->size()){
       cout<< "Error : demasiados parametros en la funcion a "<< nombre <<" linea " <<yylineno << endl;
        exit(0);
    }
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
      if(!tipo->isA(funcionTipo)&&!tipo->isA(funcionTipo)){
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
    if(parametros == NULL && ((FuncionTipo*)tipo)->parametros != NULL){
       cout<< "Error : demasiados parametros en la funcion "<< nombre <<" linea " <<yylineno << endl;
        exit(0);
    }else if(parametros->size() != ((FuncionTipo*)tipo)->parametros->size()){
       cout<< "Error : demasiados parametros en la funcion a "<< nombre <<" linea " <<yylineno << endl;
        exit(0);
    }
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

void VarNombreExpr:: generalCodigo(CodigoGenerado * codigo)
{
	if(exiteval(id)){
		data += id+": .word 0 \n";
		valores.push_back(id);
	}
	string TemporalActual = NewTemp();
	codigo->codigo = "lw " + TemporalActual + ", " + id +"\n";
    codigo->temporal = TemporalActual;
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
  		strs <<((NumExpr*)expr1)->value;
		codigoAdd += "addi " + TemporalActual + ", " + codigo2->temporal + ", " +  strs.str() + "\n";

	}else if(expr2->isA(NUM_EXPR)){
		codigoAdd = codigo1->codigo;
		stringstream strs;
  		strs <<((NumExpr*)expr2)->value;
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
  		strs <<((NumExpr*)expr1)->value;
		codigoSub = codigo2->codigo;
		codigoSub += "addi " + TemporalActual + ", " + codigo2->temporal + ", -" +  strs.str() + "\n";

	}else if(expr2->isA(NUM_EXPR)){
		stringstream strs;
  		strs <<((NumExpr*)expr2)->value;
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
	codigoDiv += "move "+TemporalActual+", $a0 \n"; 

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
	codigoMod += "move "+TemporalActual+", $a1 \n"; 

    codigo->codigo = codigoMod;
	codigo->temporal = TemporalActual;
	 
}


void ExponentExpr:: generalCodigo(CodigoGenerado * codigo)
{
	CodigoGenerado *codigo1 = new CodigoGenerado();
	CodigoGenerado *codigo2 = new CodigoGenerado();

    expr1->generalCodigo(codigo1);
	expr2->generalCodigo(codigo2);
	
	freeTemp(codigo1->temporal);
	freeTemp(codigo2->temporal);
	string codigoExponent;	
	string TemporalActual = NewTemp();
	
	codigoExponent ="move $a0, "+codigo1->temporal+"\n";
	codigoExponent ="move $a1, "+codigo2->temporal+"\n";
	codigoExponent ="jal exponecial \n"; 
	codigo->codigo = codigoExponent;
	codigoExponent ="move "+TemporalActual+", $v0 \n";
	codigo->temporal = TemporalActual;
	
}
void LTExpr:: generalCodigo(CodigoGenerado * codigo)
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
  		strs <<((NumExpr*)expr1)->value;
		codigoLT += "slti " + TemporalActual + ", " + codigo2->temporal + ", " +   strs.str() + "\n";

	}else if(expr2->isA(NUM_EXPR)){
		stringstream strs;
  		strs <<((NumExpr*)expr2)->value;
		codigoLT = codigo1->codigo;
		codigoLT += "slti " + TemporalActual + ", " + codigo1->temporal + ", " +   strs.str() + "\n";
	}else{
		codigoLT = codigo1->codigo + codigo2->codigo;
		codigoLT += "slt " + TemporalActual + ", " + codigo1->temporal + ", " + codigo2->temporal + "\n";
	}
	codigo->codigo = codigoLT;
	codigo->temporal = TemporalActual;
	 
}





void GTExpr:: generalCodigo(CodigoGenerado * codigo)
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

void GTEExpr:: generalCodigo(CodigoGenerado * codigo)
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

void LTEExpr:: generalCodigo(CodigoGenerado * codigo)
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

void NEExpr:: generalCodigo(CodigoGenerado * codigo)
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


void EQExpr :: generalCodigo(CodigoGenerado * codigo)
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
