#include <stdio.h>
#include "tokens.h"
#include <fstream>
#include "ash.h"
extern FILE *yyin;
extern string data;
char *yyfilename;
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
 Statement *input;
 input = NULL;
 yyparse();
  if (input != 0) {
    input->ValidateSemantic();
	CodigoGenerado * codigo = new CodigoGenerado();
	input->generalCodigo(codigo);
	ofstream fs("main.txt");
	fs<<data<<endl;
	fs<< ".text\nmain: \nli $a0, BRIGHT_WHITE\n li $a1, BLACK\njal set_color\n jal clear_screen\n";


	fs<<codigo->codigo<<endl;
	fs<<"\njr $ra"<<endl;
	fs.close();
	
    }
fclose(yyin);
}
