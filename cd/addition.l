%{
#include "y.tab.h"
#include<stdio.h>
extern int yylval;
int val;
%}
%%
[a-zA-Z][a-zA-Z0-9]* {printf("\n enter the value of id: %s", yytext);
                      scanf("%d",&val);
                      yylval = val;
                      return id; 
                    }
[0-9]+ {yylval= atoi(yytext); return num;}
[\t] ;
\n ;
. {return yytext[0];}
%%
int yywrap(){
    return 1;
}
