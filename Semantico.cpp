#include "Semantico.h"

typedef pair<char *, Tipo*> elemento;

void TablaSimbolos::DeclareVariable(char* name, Tipo *type){

	variables.insert(elemento(name,type));
}
Tipo* TablaSimbolos::GetVariable(char* name){
	map<char *, Tipo*>::iterator p = variables.begin();
	  while (p != variables.end() )
	  {
	    if(strcmp(p->first,name) == 0){
	      return p->second; 
	  	   
	   }
	   p ++; 
	}
}
bool TablaSimbolos::VariableExist(char* name){
      map<char *, Tipo *>::iterator p = variables.begin();
	  while (p != variables.end() )
	  {
	    if(strcmp(p->first,name) == 0){
	       return true;  
	    }
	    p ++;
	    
	  }
	  return false;
}
