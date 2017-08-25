#ifndef lex
#define lex_hpp

#include <string>
//https://www.lysator.liu.se/c/ANSI-C-grammar-l.html#check-type

enum TokenType{ //like struct
    None   = 0, // This indicates there are no more tokens
    Keyword = 1, // token codes must be positive
    Identifier =2,   // = 2, implicit from C++ enumeration
    Operator = 3,
    Constant = 4,
    Stringliteral = 5,
    Filename = 6,
    Invalid = 7,
    Hash
};

// Example

// enum Color {red,green,blue, a = 20};
//Color r = red;

//switch (r) - > red ,blue , green

// red = 0, green = 1, blue = 2 , a =20

union TokenValue{
    double numberValue;
    std::string *wordValue; //pointer to first character in string

};



// This is a global variable used to move the
// attribute value from the lexer back to the
// main program.


extern TokenValue yylval;
extern int lineno;
extern int colno;
extern int sourceno;



// By convention it is called yylval, as that is
// the name that will be automatially generated
// by Bison (see next lab).



// This is the lexer function defined by flex. Each
// time it is called, a token type value will be
// returned.
extern int yylex();

#endif
