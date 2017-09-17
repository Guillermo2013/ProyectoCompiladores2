#include <stdio.h>
#include "tokens.h"
#include <fstream>
#include "ash.h"
extern FILE *yyin;
extern string data;
char *yyfilename;
extern Statement* input;
int yylex();
int main (int argc , char * argv[]){
 if(argc != 2){
	fprintf(stderr,"USAGE : %s <input file>\n",argv[0]);	
	return 1;
 }
 
 yyin = fopen (argv[1],"r");
 yyfilename = argv[1]; 
if(yyin == NULL){
 	fprintf(stderr,"Cannot open file: %s \n",argv[0]);	
	return 1;
 }	

 yyparse();
fclose(yyin);
  
   if(input != 0){  
	CodigoGenerado * codigo = new CodigoGenerado();
	input->ValidateSemantic();
	input->generalCodigo(codigo);
	ofstream fs("/home/guillermo/Desktop/ProyectoCompiladores2/vmipssoc/src/main.S");
	fs<<data<<endl;
	fs<< ".text\n clean: \nli $a0, BRIGHT_WHITE\n li $a1, BLACK\njal set_color\n jal clear_screen\n jal main\n j .\n";


	fs<<codigo->codigo<<endl;
	fs<<"\nj ."<<endl;
	fs.close();

}
   

}
