%{
#include<stdio.h>
int c=1;
FILE *fp;
%}
%%
\n {c++;}
["][a-z0-9A-Z_, ]*["] {ECHO;printf("Valid string at line %d\n", c);}
["][a-z0-9A-Z,_ ]* {ECHO;printf("Invalid string at line %d\n", c);}
. ;
%%
void main(){
    yyin = fopen("../sample/string.c", "r");
    yylex();
    fclose(yyin);
}