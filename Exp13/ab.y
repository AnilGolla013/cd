%{
#include <stdio.h>
#include <stdlib.h>
int yylex();
int yyerror(const char *s);
%}

%%
S: A B
 | A
 ;

A: 'a' A
 | 'a'
 ;

B: 'b' B
 | 'b'
 ;
%%

int yyerror(const char *s) {
    printf("Invalid Input\n");
    return 0;
}

int main() {
    printf("Enter input: ");
    yyparse();
    printf("Valid Input\n");
    return 0;
} 