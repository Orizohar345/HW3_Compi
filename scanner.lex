%{
	#include "parser.tab.hpp"
        #include "hw3_output.hpp"
        #include "tables_stack.h"
        #include "types.h"
%}

%option yylineno
%option noyywrap

%%
int             {return INT;}
byte            {return BYTE;}
b               {return B;}
bool            {return BOOL;}
and             {return AND;}
or              {return OR;}
not             {return NOT;}
true            {return TRUE;}
false           {return FALSE;}
return          {return RETURN;}
if              {return IF;}
else            {return ELSE;}
while           {return WHILE;}
break           {return BREAK;}
continue        {return CONTINUE;}
;               {return SC;}
\(              {return LPAREN;}
\)              {return RPAREN;}
\{              {return LBRACE;}
\}              {return RBRACE;}
=               {return ASSIGN;}
==|!=                                   {return RELOP_EQ;}
>|<|<=|>=                               {return RELOP_REL;}
\-|\+                                   {return BINOP_ADD;}
\/|\*                                   {return BINOP_MULT;}
[a-zA-Z][a-zA-Z0-9]*                    {yylval.text = yytext; return ID;}
[1-9][0-9]*|0                           {return NUM;}
\"([^\n\r\"\\]|\\[rnt"\\])+\"           {return STRING;}
[ \n\t\r]	                        ;
\/\/[^\r\n]*[ \r|\n|\r\n]?              ;
.                                       {output::errorLex(yylineno); exit(0);}

