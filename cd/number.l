%{
#include<stdio.h>
int lineNo = 1;
%}
number [0-9]+
realNum {number}["."]{number}

%%  
\n {lineNo++;}
{realNum} {printf("Found real number at %d \n ", lineNo);}
{number} {printf("Found number at %d \n ", lineNo);}
{number}[a-zA-Z]+ {printf("Error at %d \n ", lineNo);}
{number}"."([a-zA-Z]|"."|";")+ {printf("Error at %d \n ", lineNo);}

%%

void main(){
    yyin = fopen("sample/sample3.c", "r");
    yylex();
    fclose(yyin);
}