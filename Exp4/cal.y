%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
void yyerror(){}
%}

%token NUM

%%
S : E '\n' { printf("Ans=%d\n", $1); }
  ;

E : E '+' E { $$ = $1 + $3; }
  | E '*' E { $$ = $1 * $3; }
  | NUM
  ;
%%

int main(){
    printf("Enter: ");
    yyparse();
}