%option noyywrap
%option yylineno
%option nounput

%{
//nounput is to insert single character into input stream
//yylineno is the line numbers

#include "lex.hpp"
#include <iostream>

int sourceno = 1; //counts the number of lines excluding hashes - yylineno - hascount
//reset each time we meet a line directive

//find the line number for EACH source file

int lineno = 0; //transfer to main
int colno = 0; //transfer to main
int column = 0; //for main counting colum function
int outputC=0; //add offset
int hashCount=0; // counting lines with hashes
int countSpacestoFirst = 0;
int firstToken = 0;
void count(); //counting column function
void FindSourceOffset(int &firstToken, int countSpacestoFirst, int &hashCount) ;


//filename old \#[ 0-9]+\"[a-zA-Z_]+\.c\"
// filename new \"(.[^"]*\.c)\"
// old string literal  \"(\\.|[^\\"])*\"
// OLD filename \#[ 0-9]+\"[a-zA-Z_]+\.c\"
%}
letter [a-zA-Z]
word {letter}+
digit [0-9]
digits [0-9]+


keyword auto|double|int|struct|break|else|long|switch|case|enum|register|typedef|char|extern|return|union|const|float|short|unsigned|continue|for|signed|void|default|goto|sizeof|volatile|do|if|static|while|sizeof
identifier [a-zA-Z_][a-zA-Z0-9_]*
operator \.\.\.|>>=|<<=|\+=|\-=|\*=|\/=|\%=|\&=|\^=|\|=|>>|<<|\+\+|\-\-|->|&&|\|\||<=|>=|==|\!=|;|\{|\}|,|:|=|\(|\)|\[|\]|\.|&|\!|\~|\-|\+|\*|\/|%|\<|\>|\^|\||\?
constant  -?{digits}\.{digits}|-?{digits}|-?{digits}|0x{digits}|0b{digits}|\'\\?.\'
hash #.*


stringLiteral \"(\\.|[^\\"])*\"


invalid {digits}{word}|\/*.*\*\/|\/\/|\\|@





%%
{hash} {

	hashCount ++;
	count();
	outputC = column - (yyleng -1); //get start of word
	lineno = yylineno;
	colno = outputC;


	std::string mystring(yytext);

	yylval.wordValue = new std::string();

	*yylval.wordValue = mystring;
	return Hash;
}



{stringLiteral} {

count();
outputC = column - (yyleng -1); //get start of word
lineno = yylineno;
colno = outputC;

//fprintf(stderr, "Stringliteral : %s LineNo: %d Column :%d\n",yytext,yylineno,outputC);

std::string mystring(yytext);

yylval.wordValue = new std::string();

*yylval.wordValue = mystring;



return Stringliteral;
}

{invalid}     {

/* get rid of 556sadsa digits then numbers */


count();
outputC = column - (yyleng -1); //get start of word
lineno = yylineno;
colno = outputC;
std::string mystring(yytext);

yylval.wordValue = new std::string();

*yylval.wordValue = mystring;


return Invalid;

}


{operator}     {

count();
outputC = column - (yyleng -1); //get start of word
lineno = yylineno;
colno = outputC;

std::string mystring(yytext);

yylval.wordValue = new std::string();

*yylval.wordValue = mystring;

//fprintf(stderr, "Operator : %s  LineNo: %d Column : %d \n",yytext,yylineno,outputC);

return Operator;

}
{keyword}     {

count();
outputC = column - (yyleng -1); //get start of word
lineno = yylineno;
colno = outputC;

std::string mystring(yytext);

yylval.wordValue = new std::string();

*yylval.wordValue = mystring;



//fprintf(stderr, "Keyword : %s LineNo: %d Column :%d\n",yytext,yylineno,outputC);
return Keyword;

}


{identifier}     {

count();
outputC = column - (yyleng -1); //get start of word
std::string mystring(yytext);
lineno = yylineno;
colno = outputC;

yylval.wordValue = new std::string();

*yylval.wordValue = mystring;

//fprintf(stderr, "Identifier : %s LineNo: %d Column :%d\n",yytext,yylineno,outputC);
return Identifier;

}

{constant}          {

count();
outputC = column - (yyleng -1); //get start of word
lineno = yylineno;
colno = outputC;


std::string mystring(yytext);

yylval.wordValue = new std::string();

*yylval.wordValue = mystring;

//fprintf(stderr, "Constant : %s LineNo: %d Column :%d\n",yytext,yylineno,outputC);

return Constant;
}




[\n] { count(); countSpacestoFirst++; sourceno ++; }


[ \t\v\f]		{ count(); countSpacestoFirst++; }






%%


void count()
{
	int i;

	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
			column = 0;
		else if (yytext[i] == '\t')
			column += 8 - (column % 8);
		else
			column++;



  //  ECHO; //Prints out the whole line

}
void FindSourceOffset(int &firstToken, int countSpacestoFirst,int &hashCount) {
if(firstToken != 1){

	hashCount = hashCount + countSpacestoFirst-1;

}
firstToken = 1;

}

void yyerror (char const *s)
{
  fprintf (stderr, "Flex Error: %s\n", s); /* s is the text that wasn't matched */
  exit(1);
}
