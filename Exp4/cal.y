%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
void yyerror(const char *s);
%}

%token NUM

%%
S : E '\n' { printf("Answer = %d\n", $1); }
  ;

E : E '+' E { $$ = $1 + $3; }
  | E '*' E { $$ = $1 * $3; }
  | E '-' E { $$ = $1 - $3; }
  | E '/' E { $$ = $1 / $3; }
  | NUM
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