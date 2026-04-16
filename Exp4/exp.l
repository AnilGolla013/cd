%{
#include "exp.tab.h"
%}

%%
[a-zA-Z0-9]+   return 'a';
[ \t]          ;
\n             return 0;
.              return yytext[0];
%%

int yywrap(){ return 1; }