  #include "ash.h"
#include <stdio.h>
#include <cstring>
#include <stdlib.h>

typedef pair<char *, int> elemento;
StackContenido *stack = new StackContenido();



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