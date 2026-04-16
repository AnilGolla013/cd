%{
#include<stdlib.h>
#include "cal.tab.h"
%}

%%
[0-9]+    { yylval = atoi(yytext); return NUM; }
[ \t]     ;
\n        return '\n';
.         return yytext[0];
%%

int yywrap(){ return 1; }