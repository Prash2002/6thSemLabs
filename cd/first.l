%{
#include<stdio.h>    
%}

%%
[0-9]+ {printf("Number :");ECHO;printf("\n");}
%%

void main(){
    printf("Enter input: ");
    yylex();
}