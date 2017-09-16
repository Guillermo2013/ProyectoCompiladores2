#ifndef _ASI_H
#define _ASI_H
#include <list>
#include <map>
#include <iostream>
#include <stdio.h>
#include "Semantico.h"
#include <vector>

using namespace std;
extern int yylineno;


class CodigoGenerado
{
  public:
	string codigo;
	string temporal;
	CodigoGenerado(){
		codigo = "";
		temporal = "";
	};
	~CodigoGenerado(){};
};

enum ExprTipo {
  LT_EXPR,
  LTE_EXPR,
  GT_EXPR,
  GTE_EXPR,
  NE_EXPR,
  EQ_EXPR,
  ADD_EXPR,
  SUB_EXPR,
  MULT_EXPR,
  DIV_EXPR,
  MOD_EXPR,
  AND_EXPR,
  OR_EXPR,
  CORIZQ_EXPR,
  CORIDER_EXP,
  ExclXBIT_EXPR,
  YXBit_EXPR,
  OXBIT_EXPR,
  POSINC_EXPR,
  POSDEC_EXPR,
  PREINC_EXPR,
  PREDEC_EXPR,
  DESFE_EXPR,
  REFE_EXPR,
  ASIG_EXPR,
  MASIGULA_EXPR,
  MENOSIGUAL_EXPR,
  MULTIGUAL_EXPR,
  DIVIGUAL_EXPR,
  MODIGUAL_EXPR,
  ORBITIGUAL_EXPR,
  XORIGUAL_EXPR,
  ANDIGUAL_EXPR,
  CORIIZIGUAL_EXPR,
  CORIDERIGUAL_EXPR,
  NEGACION_EXPR,
  RAND_EXPR,
  COMPE_EXPR,
  TERNARIO_EXPR,
  EXPT_EXPR,
  NUM_EXPR,
  ID_EXPR,
  STRING_EXPR,
  ARRAY_EXPR,
  ARRAYNOMBRE_EXPR,
  PARAMETROS_EXPR,
  CHAR_EXPR,
  INPUT_EXPR,
  CALL_EXPR
};

class Expr{
public:
virtual Tipo* ValidateSemantic() = 0;
virtual void generalCodigo(CodigoGenerado * codigo) = 0;
virtual int getKind() = 0;
bool isA(int kind) { return (getKind() == kind); }

};

typedef list<Expr*> ExprList;
class BinaryExpr:public Expr{
 protected:
	BinaryExpr(Expr *expr1,Expr *expr2){
		this->expr1 = expr1;
		this->expr2 = expr2;	
	}

 public:
	Expr *expr1,*expr2;
 	
};

class UnaryExpr:public Expr{
 protected:
	UnaryExpr(Expr *expr1){
		this->expr1 = expr1;
	}
 public:
	Expr *expr1;
 	
};
class AssignExpr:public Expr{
 protected:
	AssignExpr(Expr *nombre,Expr *expr1){
		this->expr1 = expr1;
		this->nombre = nombre;	
	}
 public:
	Expr *nombre;
	Expr *expr1;
 	
};

#define DEFINE_BINARY_EXPR(name,tipo) \
	class name##Expr : public BinaryExpr { \
	public : \
		name##Expr(Expr *expr1,Expr *expr2):BinaryExpr(expr1,expr2){\
		} \
		Tipo* ValidateSemantic();\
		int getKind() { return tipo; }\
		void generalCodigo(CodigoGenerado * codigo);\
	}

DEFINE_BINARY_EXPR(Add,ADD_EXPR);
DEFINE_BINARY_EXPR(Sub,SUB_EXPR);
DEFINE_BINARY_EXPR(Mult,SUB_EXPR);
DEFINE_BINARY_EXPR(Div,DIV_EXPR);
DEFINE_BINARY_EXPR(Igual,EQ_EXPR);
DEFINE_BINARY_EXPR(Distinto,NE_EXPR);
DEFINE_BINARY_EXPR(Mayor,GT_EXPR);
DEFINE_BINARY_EXPR(Menor,LT_EXPR);
DEFINE_BINARY_EXPR(MayorIgual,GTE_EXPR);
DEFINE_BINARY_EXPR(MenorIgual,LTE_EXPR);
DEFINE_BINARY_EXPR(Or,OR_EXPR);
DEFINE_BINARY_EXPR(And,AND_EXPR);
DEFINE_BINARY_EXPR(Mod,MOD_EXPR);
DEFINE_BINARY_EXPR(CorrimientoIzq,CORIZQ_EXPR);
DEFINE_BINARY_EXPR(CorrimientoDer,CORIDER_EXP);
DEFINE_BINARY_EXPR(OPorBit,OXBIT_EXPR);
DEFINE_BINARY_EXPR(ExclPorBit,ExclXBIT_EXPR);
DEFINE_BINARY_EXPR(YPorBit,YXBit_EXPR);

#define DEFINE_UNARY_EXPR(name,tipo) \
	class name##Expr : public UnaryExpr { \
	public : \
		name##Expr(Expr *expr1):UnaryExpr(expr1){} \
		Tipo* ValidateSemantic();\
		int getKind() { return tipo; }\
		void generalCodigo(CodigoGenerado * codigo);\
}

DEFINE_UNARY_EXPR(Desferencia,DESFE_EXPR);
DEFINE_UNARY_EXPR(PreIncremento,PREINC_EXPR);
DEFINE_UNARY_EXPR(PreDecremento,PREDEC_EXPR);
DEFINE_UNARY_EXPR(PosIncremento,POSINC_EXPR);
DEFINE_UNARY_EXPR(PosDecremento,POSDEC_EXPR);
DEFINE_UNARY_EXPR(Referencia,REFE_EXPR);
DEFINE_UNARY_EXPR(Negacion,NEGACION_EXPR);
DEFINE_UNARY_EXPR(Complemento,COMPE_EXPR);

#define DEFINE_ASSIGN_EXPR(name,tipo) \
	class name##Expr : public AssignExpr { \
	public : \
		name##Expr(Expr *nombre,Expr *expr1):AssignExpr(nombre,expr1){} \
		Tipo* ValidateSemantic();\
		int getKind() { return tipo; }\
		void generalCodigo(CodigoGenerado * codigo);\
}

DEFINE_ASSIGN_EXPR(Asignar,ASIG_EXPR);	
DEFINE_ASSIGN_EXPR(MasIgual,MASIGULA_EXPR);
DEFINE_ASSIGN_EXPR(MenosIgual,MENOSIGUAL_EXPR);
DEFINE_ASSIGN_EXPR(MultIgual,MULTIGUAL_EXPR);
DEFINE_ASSIGN_EXPR(DivIgual,DIVIGUAL_EXPR);
DEFINE_ASSIGN_EXPR(ModIgual,MODIGUAL_EXPR);
DEFINE_ASSIGN_EXPR(OrBitIgual,ORBITIGUAL_EXPR);
DEFINE_ASSIGN_EXPR(AndBitIgual,ANDIGUAL_EXPR);
DEFINE_ASSIGN_EXPR(XorBitIgual,XORIGUAL_EXPR);
DEFINE_ASSIGN_EXPR(AsigCorIzqIgual,CORIIZIGUAL_EXPR);
DEFINE_ASSIGN_EXPR(AsigCorDerIgual,CORIDERIGUAL_EXPR);

class TernarioExpr:public Expr{
 public:
	TernarioExpr(Expr* condicion,Expr *expr1,Expr *expr2){
		this->condicion = condicion;
		this->expr1 = expr1;
		this->expr2 = expr2;
	
	}	
	Expr* condicion;
	Expr *expr1;	
	Expr *expr2;
	Tipo* ValidateSemantic();
	int getKind() { return TERNARIO_EXPR; }
	void generalCodigo(CodigoGenerado * codigo);

};

class NumberExpr:public Expr{
 public:
	NumberExpr(int value){
		this->value = value;	
	}	
	int value;
	Tipo* ValidateSemantic(){ return new IntTipo();}
	int getKind() { return NUM_EXPR; }
	void generalCodigo(CodigoGenerado * codigo);
};
class StringExpr:public Expr{
 public:
	StringExpr(char* value){
		this->value = value;	
	}	
	char* value;
	Tipo* ValidateSemantic(){ return new StringTipo();}
	int getKind() { return STRING_EXPR; }
	void generalCodigo(CodigoGenerado * codigo);
};
class CharExpr:public Expr{
 public:
	CharExpr(char value){
		this->value = value;	
	}	
	char value;
	Tipo* ValidateSemantic(){ return new CharTipo();}
	int getKind() { return CHAR_EXPR; }
	void generalCodigo(CodigoGenerado * codigo);
};

class ArrayExpr:public Expr{
 public:
	ArrayExpr(ExprList *value){
		this->value = value;
	;	
	}	
	ExprList *value;
	Tipo* ValidateSemantic();
	int getKind() { return ARRAY_EXPR; }
	void generalCodigo(CodigoGenerado * codigo);
};




class VarNombreExpr:public Expr{
 public:
	char *index;
	
	VarNombreExpr(char * index){
		this->index = index;
			
	}
	Tipo* ValidateSemantic();
	int getKind() { return ID_EXPR; }
	void generalCodigo(CodigoGenerado * codigo);
};
class VarNombreArrayExpr:public Expr{
 public:
	char *index;
	Expr*expr1;
	
	VarNombreArrayExpr(char * index,Expr*expr1){
		this->index = index;
		this->expr1 = expr1;
			
	}	
	Tipo* ValidateSemantic();
	int getKind() { return ARRAYNOMBRE_EXPR; }
	void generalCodigo(CodigoGenerado * codigo);
};

class FuncionExpr: public Expr 
{
 public: 
		
		char* nombre;
		ExprList * parametros;
		FuncionExpr(char  * nombre,ExprList * parametros){
			this->nombre = nombre;
			this->parametros = parametros;
			
		}
		Tipo* ValidateSemantic();
		int getKind() { return CALL_EXPR; }
		void generalCodigo(CodigoGenerado * codigo);

};

class RandExpr : public Expr{
public:

       
	RandExpr() {}
    Tipo* ValidateSemantic(){ return new IntTipo();};
    void generalCodigo(CodigoGenerado * codigo);
    int getKind() { return RAND_EXPR; }
	
    
};

class Statement{
 public: 	
 virtual void ValidateSemantic() = 0;
 virtual void generalCodigo(CodigoGenerado * codigo) = 0;
};

class AssignStatement : public Statement{
	protected:
	
		AssignStatement(Expr * nombre, Expr * expr1){
			this->nombre = nombre;
			this->expr1 = expr1;
                      
		}
	public:	
	Expr * nombre;
		Expr *expr1;
		
};

#define DEFINE_ASSIGN_Statement(name) \
	class name##Statement : public AssignStatement { \
	public : \
		name##Statement(Expr *nombre,Expr *expr1):AssignStatement(nombre,expr1){} \
		void ValidateSemantic();\
		void generalCodigo(CodigoGenerado * codigo); \
	}

DEFINE_ASSIGN_Statement(Asignar);
DEFINE_ASSIGN_Statement(MasIgual);
DEFINE_ASSIGN_Statement(MenosIgual);
DEFINE_ASSIGN_Statement(MultIgual);
DEFINE_ASSIGN_Statement(DivIgual);
DEFINE_ASSIGN_Statement(ModIgual);
DEFINE_ASSIGN_Statement(OrBitIgual);
DEFINE_ASSIGN_Statement(AndBitIgual);
DEFINE_ASSIGN_Statement(XorBitIgual);
DEFINE_ASSIGN_Statement(AsigCorIzqIgual);
DEFINE_ASSIGN_Statement(AsigCorDerIgual);



class PrintStatement : public Statement{
public:
	ExprList  *lista;
        char * stringtxt;
	PrintStatement(char * stringtxt,ExprList  *lista) {
      	 	this->lista = lista; 
		this->stringtxt = stringtxt; 
    	}
    void ValidateSemantic();
    void generalCodigo(CodigoGenerado * codigo);
    
};

class PrintSoloStatement : public Statement{
public:

        char * stringtxt;
	PrintSoloStatement(char * stringtxt) {
 
		this->stringtxt = stringtxt; 
    	}
    void ValidateSemantic(){};
    void generalCodigo(CodigoGenerado * codigo);
    
};
class SrandStatement : public Statement{
public:

       
    SrandStatement() {  }
    void ValidateSemantic(){ };
    void generalCodigo(CodigoGenerado * codigo);
    
};


class If_Statement : public Statement{
	public: 
		Expr *expr;
		Statement *ifStatement;
		Statement *elseStatement;
		If_Statement(Expr *expr,Statement *ifStatement,Statement *elseStatement){
			this->expr = expr;
			this->ifStatement = ifStatement;
			this->elseStatement = elseStatement;
		}

		void ValidateSemantic();
		void generalCodigo(CodigoGenerado * codigo);
};
class While_Statement : public Statement{
	public: 
		Expr *expr;
		Statement *whileStatement;
		
		While_Statement(Expr *expr,Statement *whileStatement){
			this->expr = expr;
			this->whileStatement = whileStatement;
			
		}
		void ValidateSemantic();
		void generalCodigo(CodigoGenerado * codigo);
		
};

class DoWhile_Statement : public Statement{
	public: 
		Expr *expr;
		Statement *DowhileStatement;
		
		DoWhile_Statement(Expr *expr,Statement *DowhileStatement){
			this->expr = expr;
			this->DowhileStatement = DowhileStatement;
			
		}

		void ValidateSemantic();
		void generalCodigo(CodigoGenerado * codigo);
};

class BlockStatement : public Statement
{
 public :
	BlockStatement(){};
	void addStatement(Statement *statement){
	 listStatement.push_back(statement);
	}
	list<Statement*> listStatement;
	void ValidateSemantic();
	void generalCodigo(CodigoGenerado * codigo);
};


class Producer_Statement: public Statement 
{
 public: 
		char* nombre;
		Expr * parametros;
		Statement *producerStatement;
		Producer_Statement(char* nombre,Expr * parametros,Statement *producerStatement){
			this->nombre = nombre;
			this->parametros = parametros;
			this->producerStatement = producerStatement;
			
		}
		void ValidateSemantic();
		void generalCodigo(CodigoGenerado * codigo);
		
};

class For_Statement: public Statement 
{
 public: 
		
		Statement *inicializacion;
		Expr * condicional;
		Expr * incremento;
		Statement *ForStatement;
		For_Statement(Statement *inicializacion,Expr * condicional,Expr * incremento,Statement *ForStatement){
			this->inicializacion = inicializacion;
			this->condicional = condicional;
			this->incremento = incremento;
			this->ForStatement = ForStatement;
			
		}
		void ValidateSemantic();
		void generalCodigo(CodigoGenerado * codigo);
		
};

class DecArrayStatement: public Statement 
{
 public: 
		
		char  * type;
		char  * nombre;
		Expr * tam;		
		Expr * inicializar;
		Statement * multideclatation;
		DecArrayStatement(char  * type,char  * nombre,Expr * tam,Expr *inicializar,Statement * multideclatation){
			this->type = type;
			this->nombre = nombre;
			this->tam = tam;
			this->inicializar = inicializar;
			this->multideclatation = multideclatation;
		}
		void ValidateSemantic();
		void generalCodigo(CodigoGenerado * codigo);
};

class DecApuntadorStatement: public Statement 
{
 public: 
		char  * type;
		char  * nombre;		
		Expr * inicializar;
		Statement * multideclatation;
		DecApuntadorStatement(char  *type,char  *nombre,Expr *inicializar,Statement * multideclatation){
			this->type = type;
			this->nombre = nombre;
			this->inicializar = inicializar;
			this->multideclatation = multideclatation;
		}

		void ValidateSemantic();
		void generalCodigo(CodigoGenerado * codigo){};
};
class DecVariableStatement: public Statement 
{
 public: 
		
		char  * type;
		char  * nombre;		
		Expr * inicializar;
		Statement * multideclatation;
		DecVariableStatement(char  * type,char  * nombre,Expr *inicializar,Statement * multideclatation){
			this->type = type;
			this->nombre = nombre;
			this->inicializar = inicializar;
			this->multideclatation = multideclatation;
		}
		void ValidateSemantic();
		void generalCodigo(CodigoGenerado * codigo);
		
};
class Funcion_Statement: public Statement 
{
 public: 
		
		char  * type;
		char* nombre;
		Expr * parametros;
		Statement *funcionStatement ;
		Funcion_Statement(char  * type,char  * nombre,Expr * parametros,Statement *funcionStatement){
			this->type = type;
			this->nombre = nombre;
			this->parametros = parametros;
			this->funcionStatement = funcionStatement;
			
		}
		void ValidateSemantic();
		void generalCodigo(CodigoGenerado * codigo);
};


class Return_Statement: public Statement 
{
 public:	
		
		Expr * returnExpr;
		Return_Statement(Expr * returnExpr){
			this->returnExpr = returnExpr;
			
		}
		void ValidateSemantic(){};
		void generalCodigo(CodigoGenerado * codigo);
	
};


class CallFuncionStatement: public Statement 
{
 public: 
		
		
		char* nombre;
		ExprList *parametros;
		CallFuncionStatement(char  * nombre,ExprList *parametros){
			
			this->nombre = nombre;
			this->parametros = parametros;
			
		}

		void ValidateSemantic();
		void generalCodigo(CodigoGenerado * codigo);
};

#define DEFINE_Increment_Statement(name) \
	class name##Statement : public Statement { \
	public : \
		Expr *expr1;\
		name##Statement(Expr *expr1){this->expr1 = expr1;} \
		void ValidateSemantic();\
		void generalCodigo(CodigoGenerado * codigo);\
	}


DEFINE_Increment_Statement(PreIncremento);
DEFINE_Increment_Statement(PreDecremento);
DEFINE_Increment_Statement(PosIncremento);
DEFINE_Increment_Statement(PosDecremento);


class Parametro : public Expr
{
 public: 
		
		
		const char  * type;		
		Statement * declaracion;
		
		Parametro(const char  * type,Statement *declaracion){
			this->type = type;
			this->declaracion = declaracion;
			
		}

		Tipo* ValidateSemantic();
		int getKind() { return PARAMETROS_EXPR; }
		void generalCodigo(CodigoGenerado * codigo);
};

class Parametros : public Expr
{
 public :
	Parametros(){};
	void addParametro(Parametro *parametro){
	 listParametro.push_back(parametro);
	}
		list<Parametro*> listParametro;
	Tipo* ValidateSemantic(){return new IntTipo();};
	int getKind() { return PARAMETROS_EXPR; }
	void generalCodigo(CodigoGenerado * codigo);
};
#endif 

