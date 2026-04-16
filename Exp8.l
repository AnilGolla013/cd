%{
#include<stdio.h>
int sc=0,wc=0,lc=0,cc=0;
%}

%%
\n              { lc++; cc++; }
[ \t]+          { sc += yyleng; cc += yyleng; }
[^\t\n ]+       { wc++; cc += yyleng; }
.               { cc++; }
%%

int main()
{
    printf("Enter the input:\n");
    yylex();
    printf("Lines = %d\n", lc);
    printf("Spaces = %d\n", sc);
    printf("Words = %d\n", wc);
    printf("Characters = %d\n", cc);
    return 0;
}

int yywrap()
{
    return 1;
}