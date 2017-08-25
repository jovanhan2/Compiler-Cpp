/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_CW2_PARSER_SRC_MATHS_PARSER_TAB_HPP_INCLUDED
# define YY_YY_CW2_PARSER_SRC_MATHS_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "CW2-Parser/src/maths_parser.y" /* yacc.c:1909  */

  #include "ast.hpp"
  #include <iostream>
  #include <cassert>
  #include <string>
  using namespace std;
  extern const Base *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated STATEMENTLIST can call them.
  //ARGS :
  //| T_NUMINT T_VARIABLE T_LBRACKET ARGS T_RBRACKET T_LCURLY STATEMENTLIST T_RCURLY {}
  /*  | T_NUMINT T_VARIABLE T_SEMICOLON {printf("In match");$$ = new Int(*$2) ;}
    | T_NUMINT T_LBRACKET T_VARIABLE T_RBRACKET T_SEMICOLON {printf("In match");$$ = new Variable(*$3);}


    | COND T_LBRACKET T_NUMINT T_VARIABLE T_RBRACKET {$$ = new Param(*$4)
    |T_NUMINT T_VARIABLE T_EQUAL EXPR T_SEMICOLON {printf("In match");$$ = new Int(*$2) ;}*/
  int yylex(void);
  void yyerror(const char *);

#line 67 "CW2-Parser/src/maths_parser.tab.hpp" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_COMMAR = 258,
    T_NEWLINE = 259,
    T_RETURN = 260,
    T_MODULO = 261,
    T_GREATERTHAN = 262,
    T_LESSTHAN = 263,
    T_NOT = 264,
    T_WHILE = 265,
    T_ELSE = 266,
    T_FOR = 267,
    T_QUESTIONM = 268,
    T_COLON = 269,
    T_TIMES = 270,
    T_PLUS = 271,
    T_DIVIDE = 272,
    T_MINUS = 273,
    T_LBRACKET = 274,
    T_RBRACKET = 275,
    T_LOG = 276,
    T_EXP = 277,
    T_SQRT = 278,
    T_NUMBER = 279,
    T_VARIABLE = 280,
    T_LCURLY = 281,
    T_RCURLY = 282,
    T_NUMINT = 283,
    T_SEMICOLON = 284,
    T_IF = 285,
    T_EQUAL = 286,
    T_MUL_ASSIGN = 287,
    T_DIV_ASSIGN = 288,
    T_MOD_ASSIGN = 289,
    T_ADD_ASSIGN = 290,
    T_SUB_ASSIGN = 291,
    T_LEFT_ASSIGN = 292,
    T_RIGHT_ASSIGN = 293,
    T_AND_ASSIGN = 294,
    T_XOR_ASSIGN = 295,
    T_OR_ASSIGN = 296,
    T_LE_OP = 297,
    T_GE_OP = 298,
    T_EQ_OP = 299,
    T_NE_OP = 300,
    T_RIGHT_OP = 301,
    T_LEFT_OP = 302,
    T_INC_OP = 303,
    T_DEC_OP = 304,
    T_PTR_OP = 305,
    T_AND_OP = 306,
    T_OR_OP = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 26 "CW2-Parser/src/maths_parser.y" /* yacc.c:1909  */

  const Base *expr;
  double number;
  std::string *string;



  astList *listPtr;
   Declaration *DecPtr;


   Statement *statePtr;

   FunctionDef *Funct;

   astList *topPtr;
   Param *paramPtr;

   ifDef *ifDefPtr;
   Base *basePtr;

#line 154 "CW2-Parser/src/maths_parser.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CW2_PARSER_SRC_MATHS_PARSER_TAB_HPP_INCLUDED  */
