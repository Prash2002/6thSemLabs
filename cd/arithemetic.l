%{
#include<stdio.h>
int lineNo = 1;
%}

operator [-+*/]
identifier [a-zA-Z][a-zA-Z0-9]*
number [0-9]+
expression [({identifier} | {number}){operator}({identifier} | {number})

%%  
\n {lineNo++;}
{identifier}"="{expression}+";" {printf("Valid at %d\n", lineNo);}
{identifier}"="({number}|{identifier})+";" {printf("Valid at %d\n", lineNo);}
 
{identifier}"=;" {printf("Invalid at %d\n", lineNo);}
{identifier}"="[({identifier} | {number}){operator}{operator}+({identifier} | {number}) {printf("Invalid at %d\n", lineNo);}

%%

void main(){
    yyin = fopen("sample/sample2.c", "r");
    yylex();
    fclose(yyin);
}