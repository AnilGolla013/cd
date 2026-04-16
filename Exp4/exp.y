%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
void yyerror(const char *s);
%}

%%
S : E { printf("Valid Expression\n"); }
  ;

E : E '+' E
  | E '*' E
  | E '-' E
  | E '/' E
  | '(' E ')'
  | 'a'
  ;
%%

int main(){
    printf("Enter: ");
    yyparse();
    return 0;
}

void yyerror(const char *s){
    printf("Invalid Expression\n");
}