#include <stdio.h>
#include "tokens.h"

extern FILE *yyin;
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
 
 yyparse();
fclose(yyin);
}
