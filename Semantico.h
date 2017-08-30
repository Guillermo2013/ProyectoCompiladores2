#ifndef _SEMANTICO_H
#define _SEMANTICO_H
#include <map>
#include <list>
#include <stdio.h>
#include <string.h>
using namespace std;


enum ExprKind {
  intTipo,
  charTipo,
  stringTipo,
  arrayTipo,
  apuntadorTipo,
  funcionTipo,
  procedimientoTipo
};

class Tipo
{
public:

	Tipo(){};
    ~Tipo();
    virtual int getKind() = 0;
    bool isA(int kind) { return (getKind() == kind); }
	
};

class IntTipo : public Tipo
{
public:

	IntTipo(){};
	~IntTipo();
	int getKind() { return intTipo; }
};

class CharTipo : public Tipo
{
public:

	CharTipo(){};
	~CharTipo();
	int getKind() { return charTipo; }
};
class StringTipo : public Tipo
{
public:

	StringTipo(){};
	~StringTipo();
	int getKind() { return stringTipo; }
};
class ArrayTipo : public Tipo
{
public:
    Tipo * tipoArray;
	ArrayTipo(Tipo * tipoArray){
		this->tipoArray = tipoArray;
	}
	~ArrayTipo();
	int getKind() { return arrayTipo; }
};

class ApuntadorTipo : public Tipo
{
public:
    Tipo * tipoApuntador;
	ApuntadorTipo(Tipo * tipoApuntador){this->tipoApuntador = tipoApuntador;}
	~ApuntadorTipo();
	int getKind() { return apuntadorTipo; }
	
};
class FuncionTipo : public Tipo
{
public:
    Tipo * retorno;
    map< char *, Tipo* > *parametros;
	FuncionTipo( Tipo * retorno, map< char *, Tipo *> *parametros){
		this->retorno = retorno;
		this->parametros = parametros;
	};
	~FuncionTipo();
	int getKind() { return funcionTipo; }
};
class ProcedimientoTipo : public Tipo
{
public:
    map< char *, Tipo *> *parametros;
	ProcedimientoTipo( map< char *, Tipo *> *parametros){
		this->parametros = parametros;
	};
	~ProcedimientoTipo();
	int getKind() { return procedimientoTipo; }
};

class TablaSimbolos
{
public:
	map< char *, Tipo* > variables;
	TablaSimbolos(){};
	~TablaSimbolos();
	 void DeclareVariable(char* name, Tipo *type);
	 Tipo* GetVariable(char* name);
	 bool VariableExist(char* name);
	
};
class StackContenido
{
public:
	list<TablaSimbolos*> Stack;
	StackContenido(){};	
	~StackContenido(){};
	
};
#endif
