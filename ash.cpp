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
       if(st->ValidateSemantic()->isA(primero->ValidateSemantic()->getKind())){
         cout<< "Error : arreglo de diferentes tipos" << endl;
         exit(-1);
       }
       it++;
    }
    return new ArrayTipo(primero->ValidateSemantic());
}

Tipo* TernarioExpr :: ValidateSemantic(){
  
  if(!expr1->ValidateSemantic()->isA(expr2->ValidateSemantic()->getKind())){
         cout<< "Error : expresiones diferentes ternario" << endl;
         exit(1);
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
  cout<< "Error : variable no existe "<< index << endl;
 
}
Tipo* VarNombreArrayExpr :: ValidateSemantic(){
  
  if(!expr1->ValidateSemantic()->isA(intTipo))
  {
    cout<< "Error : la expresion tiene que se un int " << endl;
  
  }
  list<TablaSimbolos*>::iterator it = stack->Stack.begin();
  while (it != stack->Stack.end()) {
    TablaSimbolos * st = *it;
     if(st->VariableExist(index)){
        if(st->GetVariable(index)->isA(arrayTipo)){
          return ((ArrayTipo*)st->GetVariable(index))->tipoArray;
        }else{
          cout<< "Error : la variable no es un arreglo "<< index << endl;
          exit(1);
        }
     }
     it++;
  }
  cout<< "Error : variable no existe   "<<index << endl;
  exit(1);
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
    cout<< "Error : no se puede realizar operaciones con arreglos o con funciones void " << endl;\
    exit(-1);\
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

    cout<< "Error : la variable no es un apuntador " << endl;\
    exit(-1);\

}
#define IMPLEMENT_BINARY_INC_SEMANTIC(name) \
  Tipo* name##Expr::ValidateSemantic(){ \
    Tipo * valor = expr1->ValidateSemantic();\
  if(valor->isA(funcionTipo) || expr1->ValidateSemantic()->isA(funcionTipo)||\
    valor->isA(procedimientoTipo) || expr1->ValidateSemantic()->isA(procedimientoTipo)){\
    cout<< "Error : no se puede realizar operaciones con  funciones  " << endl;\
    exit(-1);\
  }\
  return valor; \
}

IMPLEMENT_BINARY_INC_SEMANTIC(PreIncremento);
IMPLEMENT_BINARY_INC_SEMANTIC(PreDecremento);
IMPLEMENT_BINARY_INC_SEMANTIC(PosIncremento);
IMPLEMENT_BINARY_INC_SEMANTIC(PosDecremento);

Tipo* NegacionExpr :: ValidateSemantic(){
}
Tipo* ComplementoExpr :: ValidateSemantic(){
  
}
Tipo* AsignarExpr :: ValidateSemantic(){


}

Tipo* ReferenciaExpr :: ValidateSemantic(){
}
Tipo* FuncionExpr :: ValidateSemantic(){
}