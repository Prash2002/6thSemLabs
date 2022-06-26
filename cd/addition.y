%{
#include<stdio.h>
%}
%token id num
%%
E: E'+'E {printf("\n addition is recog!"); $$=$1+$3; printf("\n addition result = %d", $$);}
| id {printf("\n id recog!");}
| num {printf("\n num recog!");}
;
%%
void main(){
    printf("\nEnter Expression:");
    yyparse();
}
yyerror(){
    printf("\n invalid expr!");
}