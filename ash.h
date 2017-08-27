#ifndef _ASI_H
#define _ASI_H
#include <list>
#include <map>
#include <iostream>
#include <stdio.h>
	
using namespace std;



class Expr{
public:
 virtual int eval() = 0;
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

#define DEFINE_BINARY_EXPR(name) \
	class name##Expr : public BinaryExpr { \
	public : \
		name##Expr(Expr *expr1,Expr *expr2):BinaryExpr(expr1,expr2){} \
		int eval(); \
}

DEFINE_BINARY_EXPR(Add);
DEFINE_BINARY_EXPR(Sub);
DEFINE_BINARY_EXPR(Mult);
DEFINE_BINARY_EXPR(Div);
DEFINE_BINARY_EXPR(Igual);
DEFINE_BINARY_EXPR(Distinto);
DEFINE_BINARY_EXPR(Mayor);
DEFINE_BINARY_EXPR(Menor);
DEFINE_BINARY_EXPR(MayorIgual);
DEFINE_BINARY_EXPR(MenorIgual);
DEFINE_BINARY_EXPR(Or);
DEFINE_BINARY_EXPR(And);
DEFINE_BINARY_EXPR(Mod);
DEFINE_BINARY_EXPR(CorrimientoIzq);
DEFINE_BINARY_EXPR(CorrimientoDer);
DEFINE_BINARY_EXPR(OPorBit);
DEFINE_BINARY_EXPR(ExclPorBit);
DEFINE_BINARY_EXPR(YPorBit);

#define DEFINE_UNARY_EXPR(name) \
	class name##Expr : public UnaryExpr { \
	public : \
		name##Expr(Expr *expr1):UnaryExpr(expr1){} \
		int eval(){return 0;} \
}
DEFINE_UNARY_EXPR(Desferencia);
DEFINE_UNARY_EXPR(PreIncremento);
DEFINE_UNARY_EXPR(PreDecremento);
DEFINE_UNARY_EXPR(PosIncremento);
DEFINE_UNARY_EXPR(PosDecremento);
DEFINE_UNARY_EXPR(Referencia);
DEFINE_UNARY_EXPR(Negacion);
DEFINE_UNARY_EXPR(Complemento);

#define DEFINE_ASSIGN_EXPR(name) \
	class name##Expr : public AssignExpr { \
	public : \
		name##Expr(Expr *nombre,Expr *expr1):AssignExpr(nombre,expr1){} \
		int eval(){return 0;} \
}

DEFINE_ASSIGN_EXPR(Asignar);
DEFINE_ASSIGN_EXPR(MasIgual);
DEFINE_ASSIGN_EXPR(MenosIgual);
DEFINE_ASSIGN_EXPR(MultIgual);
DEFINE_ASSIGN_EXPR(DivIgual);
DEFINE_ASSIGN_EXPR(ModIgual);
DEFINE_ASSIGN_EXPR(OrBitIgual);
DEFINE_ASSIGN_EXPR(AndBitIgual);
DEFINE_ASSIGN_EXPR(XorBitIgual);
DEFINE_ASSIGN_EXPR(AsigCorIzqIgual);
DEFINE_ASSIGN_EXPR(AsigCorDerIgual);

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
	int eval(){ return 0;}
};

class NumberExpr:public Expr{
 public:
	NumberExpr(int value){
		this->value = value;	
	}	
	int value;
	int eval(){ return value;}
};
class StringExpr:public Expr{
 public:
	StringExpr(char* value){
		this->value = value;	
	}	
	char* value;
	int eval(){ cout<<" "<< value <<endl; return 0;}
};
class CharExpr:public Expr{
 public:
	CharExpr(char value){
		this->value = value;	
	}	
	char value;
	int eval(){ cout<<" "<< value <<endl; return value;}
};

class ArrayExpr:public Expr{
 public:
	ArrayExpr(ExprList *value){
		this->value = value;	
	}	
	ExprList *value;
	int eval(){  return 0;}
};




class VarNombreExpr:public Expr{
 public:
	char *index;
	int eval();
	VarNombreExpr(char * index){
		this->index = index;	
	}	
	
};
class VarNombreArrayExpr:public Expr{
 public:
	char *index;
	Expr*expr1;
	int eval(){return 0;};
	VarNombreArrayExpr(char * index,Expr*expr1){
		this->index = index;
		this->expr1 = expr1;	
	}	
	
};
class DesreferenciaExpr:public Expr{
 public:
	char *index;
	int eval(){return 0;};
	DesreferenciaExpr(char * index){
		this->index = index;	
	}	
	
};
class ReferenciaVarExpr:public Expr{
 public:
	char *index;
	int eval(){return 0;};
	ReferenciaVarExpr(char * index){
		this->index = index;	
	}	
	
};
class Statement{
 public: 
	virtual void exec() = 0;

	
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
		void exec(){} \
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
        char * string;
	PrintStatement(char * string,ExprList  *lista) {
      	 	this->lista = lista; 
		this->string = string; 
    	}
    void exec();
    
};

class ScanfStatement : public Statement{
public:
	ExprList  *lista;
        char * string;
	ScanfStatement(char * string,ExprList  *lista) {
      	 	this->lista = lista; 
		this->string = string; 
    	}
    void exec();
    
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

		void exec();
};
class While_Statement : public Statement{
	public: 
		Expr *expr;
		Statement *whileStatement;
		
		While_Statement(Expr *expr,Statement *whileStatement){
			this->expr = expr;
			this->whileStatement = whileStatement;
			
		}

		void exec();
};

class DoWhile_Statement : public Statement{
	public: 
		Expr *expr;
		Statement *DowhileStatement;
		
		DoWhile_Statement(Expr *expr,Statement *DowhileStatement){
			this->expr = expr;
			this->DowhileStatement = DowhileStatement;
			
		}

		void exec();
};

class BlockStatement : public Statement
{
 public :
	BlockStatement(){};
	void addStatement(Statement *statement){
	 listStatement.push_back(statement);
	}
	list<Statement*> listStatement;
	void exec();
};


class Producer_Statement: public Statement 
{
 public: 
		char* nombre;
		Statement *producerStatement;
		Producer_Statement(char* nombre,Statement *producerStatement){
			this->nombre = nombre;
			this->producerStatement = producerStatement;
			
		}

		void exec();
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

		void exec();
};

class DecArrayStatement: public Statement 
{
 public: 
		
		char  * type;
		char  * nombre;
		Expr * tam;		
		Expr * inicializar;
		DecArrayStatement(char  * type,char  * nombre,Expr * tam,Expr *inicializar){
			this->type = type;
			this->nombre = nombre;
			this->tam = tam;
			this->inicializar = inicializar;
			
		}

		void exec(){};
};

class DecApuntadorStatement: public Statement 
{
 public: 
		char  * type;
		char  * nombre;		
		Expr * inicializar;
		DecApuntadorStatement(char  *type,char  *nombre,Expr *inicializar){
			this->type = type;
			this->nombre = nombre;
			this->inicializar = inicializar;
			
		}

		void exec(){};
};
class DecVariableStatement: public Statement 
{
 public: 
		
		char  * type;
		char  * nombre;		
		Expr * inicializar;
		
		DecVariableStatement(char  * type,char  * nombre,Expr *inicializar){
			this->type = type;
			this->nombre = nombre;
			this->inicializar = inicializar;
			
		}

		void exec(){};
};
class Funcion_Statement: public Statement 
{
 public: 
		
		char  * type;
		char* nombre;
		Statement *funcionStatement;
		Funcion_Statement(char  * type,char  * nombre,Statement *funcionStatement){
			this->type = type;
			this->nombre = nombre;
			this->funcionStatement = funcionStatement;
			
		}

		void exec(){};
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

		void exec(){};
};

#endif 
