%{
#include<stdio.h>
int lineNo = 1;
%}

datatypes "int"|"float"|"char"|"double"

%%  
\n {lineNo++;}
{datatypes} {printf("Declarative Statement at %d\n ", lineNo);}
%%

void main(){
    yyin = fopen("sample/sample3.c", "r");
    yylex();
    fclose(yyin);
}