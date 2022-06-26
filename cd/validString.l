%{
#include<stdio.h>
int lineNo = 1;
%}

%%  
\n {lineNo++;}
["][a-zA-Z0-9|" "|","]*["] {printf("String :) ");}
%%

void main(){
    yyin = fopen("sample/sample2.c", "r");
    yylex();
    fclose(yyin);
}