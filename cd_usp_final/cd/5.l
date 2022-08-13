%{
    #include<stdio.h>
    int c = 1;
%}
num [0-9]*
id [a-z][a-zA-Z0-9]*
rel [><=!]=?
cond ({id}|{num}){rel}({id}|{num})
%%
\n {c++;}
"if("{cond}")""{".*"}"(\n)*("else if("{cond}")""{".*"}"(\n)*)*("else{".*"}")? {printf("If Statement found at %d\n", c);}
"else" {printf("Else without preceding if at line: %d\n", c);}
. ;
%%
void main(){
    yyin = fopen("./sample.txt", "r");
    yylex();
    fclose(yyin);
}