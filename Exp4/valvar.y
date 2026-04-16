%{
#include <stdio.h>
#include <stdlib.h>
int yylex();
void yyerror(const char *s);
%}

%token L D

%%
S : L X '\n'   { printf("Valid Variable\n"); }
  ;

X : L X
  | D X
  |        /* empty */
  ;
%%

int main() {
    printf("Enter: ");
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    printf("Invalid Variable\n");
}