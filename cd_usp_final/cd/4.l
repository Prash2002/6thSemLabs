%{
    #include<stdio.h>
    int c = 1;
%}

id [a-zA-Z][a-zA-Z0-9]*
types "int"|"float"|"char"
num [0-9]+
dec {types}" "{id}(","{id})*

%%
\n {c++;}
"struct "{id}"{"({dec}";"|\n)*"}"({id}(", "{id})*)?";" {printf("Struct found at line %d\n", c);} 
. ;
%%
void main(){
    yyin = fopen("./sample.txt", "r");
    yylex();
    fclose(yyin);
}