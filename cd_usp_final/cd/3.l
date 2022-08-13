%{
#include<stdio.h>
int c=0;
%}
id [a-zA-Z][a-zA-Z0-9]*
ar [/*+-]
num [0-9]+
rel [<>=!]=?
inc "++"
dec "--"
%%
\n {c++;}
{id}" = "({id}|{num})(" "{ar}" "({id}|{num}))";" {printf("\n Valid arithematic operation at line %d", c+1);}
{id}" = "({id}|{num}){ar}";" {printf("\n Missing right operand");}
{id}" = "{ar}({id}|{num})";" {printf("\n Missing left operand");}
{id}" = "({id}|{num})" "{rel}" "({id}|{num})";" {printf("\n Relational operation at %d", c+1);}
({id}|{num})({inc}|{dec})";" {printf("\n Unary Operator at %d", c+1);}
. ;
%%

void main(){
    yyin = fopen("sample.c", "r");
    yylex();
    fclose(yyin);
}