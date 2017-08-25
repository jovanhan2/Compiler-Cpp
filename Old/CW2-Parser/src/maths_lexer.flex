%option noyywrap
%option nounput
%{
// Avoid error "error: �fileno� was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "maths_parser.tab.hpp"
%}

DIGIT [0-9]
ID [A-Za-z_]
IDENTIFIER {ID}({ID}|{DIGIT})*

%%


[*]             { return T_TIMES; }
[\+]             { return T_PLUS; }
[/]             { return T_DIVIDE; }
[-]             { return T_MINUS; }
\%              { return T_MODULO;}
[=]             { return T_EQUAL;}
[(]             { return T_LBRACKET; }
[)]             { return T_RBRACKET; }
\,              { return T_COMMAR;}
\>\>=			{  return(T_RIGHT_ASSIGN); }
\<\<=			{  return(T_LEFT_ASSIGN); }
\+=		  {  return(T_ADD_ASSIGN); }
-=			{  return(T_SUB_ASSIGN); }
\*=			{  return(T_MUL_ASSIGN); }
\/=			{  return(T_DIV_ASSIGN); }
%=			{  return(T_MOD_ASSIGN); }
&=			{  return(T_AND_ASSIGN); }
\^=			{  return(T_XOR_ASSIGN); }
\|=			{  return(T_OR_ASSIGN); }
\>      {   return(T_GREATERTHAN);}
\<      {  return(T_LESSTHAN);}
\<=			{  return(T_LE_OP); }
\>=			{  return(T_GE_OP); }
==			{ return(T_EQ_OP); }
!=			{  return(T_NE_OP); }
return  {  return T_RETURN;}
\>\>			{  return(T_RIGHT_OP); }
\<\<			{  return(T_LEFT_OP); }
\+\+			{ return(T_INC_OP); }
--			{  return(T_DEC_OP); }
\?      {  return T_QUESTIONM;}
\-\>			{  return(T_PTR_OP); }
\&\&			{ return(T_AND_OP); }
\|\|			{ return(T_OR_OP); }
\!        { return (T_NOT);}
\:        { return (T_COLON);}

if              { return T_IF;}
while      {return T_WHILE;}
else        {return T_ELSE;}
for         {return T_FOR;}
log             { return T_LOG;   }
exp             { return T_EXP; }
sqrt            { return T_SQRT; }
\{              { return T_LCURLY;}
\}              { return T_RCURLY;}
(int)           {return T_NUMINT;}
[\;]            { return T_SEMICOLON;}
[+-]?([0-9]*[.])?[0-9]+ { yylval.number=strtod(yytext, 0); return T_NUMBER; }
{IDENTIFIER}          {yylval.string=new std::string(yytext); return T_VARIABLE; }

[ \t]+  {}
\n {}

.               { fprintf(stderr, "Invalid token\n"); exit(1); }
%%

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}
