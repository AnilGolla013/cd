%{
#include "valvar.tab.h"
%}

%%
[a-zA-Z]    return L;
[0-9]       return D;
\n          return '\n';
[ \t]       ;
.           return yytext[0];
%%

int yywrap() { return 1; }