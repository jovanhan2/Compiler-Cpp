%code requires{
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
}

// Represents the value associated with any kind of
// AST node.
%union{
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
}
%token T_COMMAR T_NEWLINE T_RETURN T_MODULO T_GREATERTHAN T_LESSTHAN T_NOT T_WHILE T_ELSE T_FOR T_QUESTIONM T_COLON
%token T_TIMES T_PLUS T_DIVIDE T_MINUS T_LBRACKET T_RBRACKET T_LOG T_EXP T_SQRT T_NUMBER T_VARIABLE T_LCURLY T_RCURLY T_NUMINT T_SEMICOLON
%token T_IF T_EQUAL T_MUL_ASSIGN T_DIV_ASSIGN T_MOD_ASSIGN T_ADD_ASSIGN T_SUB_ASSIGN T_LEFT_ASSIGN T_RIGHT_ASSIGN T_AND_ASSIGN T_XOR_ASSIGN T_OR_ASSIGN
%token T_LE_OP T_GE_OP T_EQ_OP T_NE_OP T_RIGHT_OP T_LEFT_OP T_INC_OP T_DEC_OP T_PTR_OP T_AND_OP T_OR_OP




%type <expr> EXPR TERM FACTOR
%type<basePtr> STATEMENT BASE STATEMENTNOSEMI
%type<listPtr> FUNCTIONLIST DECLARATIONLIST STATEMENTLIST PARAMLIST ALLSTATE

%type <DecPtr> DECLARATION

%type <paramPtr> PARAM

%type <Funct> FUNCTION

%type <number> T_NUMBER
%type <string> T_VARIABLE T_NUMINT TYPE

%start ROOT

%%

ROOT : BASE { g_root = $1; }

BASE : FUNCTIONLIST { $$ = new astList();$$->addList($1);}
| FUNCTIONLIST ALLSTATE{ $$->addList($2);}
| DECLARATIONLIST { $$ = new astList();$$->addList($1);}

//nee to fix mul func def

/*
| DECLARATIONLIST FUNCTIONLIST  { $$->addList($2);}
| FUNCTIONLIST DECLARATIONLIST { $$->addList($2);}
| DECLARATIONLIST FUNCTIONLIST DECLARATIONLIST { $$->addList($2);$$->addList($3);}
*/



/*****************************************Function*****************************************************************/

FUNCTIONLIST : DECLARATIONLIST FUNCTION{ $$ = new astList(); $$ -> addList($1);$$ -> addList($2);}

| FUNCTION {$$ = new astList(); $$ -> addList($1);}
| FUNCTIONLIST FUNCTION{ $$->addList($2);}
| FUNCTIONLIST DECLARATIONLIST FUNCTION {$$->addList($2);$$->addList($3); }

 FUNCTION : TYPE T_VARIABLE T_LBRACKET PARAMLIST T_RBRACKET T_LCURLY ALLSTATE T_RCURLY //param + code
 {$$ = new FunctionDef(*$1,*$2,$4,$7);}
 | TYPE T_VARIABLE T_LBRACKET T_RBRACKET T_LCURLY ALLSTATE T_RCURLY //no param
 {$$ = new FunctionDef(*$1,*$2,NULL,$6);}
 | TYPE T_VARIABLE T_LBRACKET T_RBRACKET T_LCURLY T_RCURLY // no param no  code
 {$$ = new FunctionDef(*$1,*$2,NULL,NULL);}
 | TYPE T_VARIABLE T_LBRACKET PARAMLIST T_RBRACKET T_LCURLY T_RCURLY //no code
 {$$ = new FunctionDef(*$1,*$2,$4,NULL);}


 /* function definition not needed
 | TYPE T_VARIABLE T_LBRACKET PARAMLIST T_RBRACKET T_SEMICOLON //function definition
 {$$ = new FunctionDef(*$1,*$2,$4,NULL);}
 | TYPE T_VARIABLE T_LBRACKET T_RBRACKET T_SEMICOLON //function definition - no params
 {$$ = new FunctionDef(*$1,*$2,NULL,NULL);}
 */


PARAMLIST : PARAM { $$ = new astList(); $$ -> addList($1);}
| PARAMLIST T_COMMAR PARAM { $$ ->addList($3);}


PARAM : TYPE T_VARIABLE { $$ = new Param(*$1,*$2);}





 /*****************************************Declarations + Statement combined*****************************************************************/
 ALLSTATE   : DECLARATIONLIST STATEMENTLIST  { $$ = new astList();$$->addList($1); $$->addList($2);}
  |STATEMENTLIST { $$ = new astList();$$->addList($1);}
 | DECLARATIONLIST { $$ = new astList();$$->addList($1);}


 //| FUNCTION {  $$ = new AllCode();$$->addList($1);}// nested function not int C



/*****************************************Statement*****************************************************************/
STATEMENTLIST : STATEMENT  {$$ = new astList();$$ ->addList($1);}
| STATEMENTLIST STATEMENT { $$ -> addList($2);}
| STATEMENTLIST STATEMENTNOSEMI  { $$ -> addList($2);}

STATEMENT : T_VARIABLE ASSIGNMENT_OP EXPR T_SEMICOLON {$$ = new Statement();}
| RETURN { $$ = new Statement();}
| INCDEC T_VARIABLE T_SEMICOLON{$$ = new Statement();}
| T_VARIABLE INCDEC T_SEMICOLON{$$ = new Statement();}
|  IFWHILE T_LBRACKET COMPARE T_RBRACKET T_LCURLY ALLSTATE T_RCURLY {$$ = new ifDef(); $$->addList($6); }
| IFWHILE T_LBRACKET COMPARE T_RBRACKET T_LCURLY T_RCURLY {$$ = new ifDef(); }
| T_ELSE T_LCURLY ALLSTATE T_RCURLY {$$ = new ifDef(); $$->addList($3); }
| T_ELSE T_LCURLY T_RCURLY {$$ = new ifDef(); }
| T_FOR T_LBRACKET DECLARATION COMPARE T_SEMICOLON T_VARIABLE INCDEC T_RBRACKET T_LCURLY ALLSTATE T_RCURLY
{$$ = new ifDef(); $$->addList ($10);}
| T_FOR T_LBRACKET DECLARATION COMPARE T_SEMICOLON T_VARIABLE INCDEC T_RBRACKET T_LCURLY T_RCURLY
{$$ = new ifDef();}
| T_LBRACKET COMPARE T_RBRACKET T_QUESTIONM STATEMENTNOSEMI T_COLON STATEMENT { $$ = new astList(); $$->addList($5);$$->addList($7);}
| COMPARE T_QUESTIONM STATEMENTNOSEMI T_COLON STATEMENT { $$ = new astList(); $$->addList($3);$$->addList($5);}


STATEMENTNOSEMI : T_VARIABLE ASSIGNMENT_OP EXPR {$$ = new Statement();}
| INCDEC T_VARIABLE {$$ = new Statement();}
| T_VARIABLE INCDEC{$$ = new Statement();}


 ///| IFWHILE T_LBRACKET COMPARE T_RBRACKET T_LCURLY T_RCURLY {$$ = new ifDef(); }
/*****************************************If statemet*****************************************************************/


/*****************************************Declaration*****************************************************************/






DECLARATIONLIST : DECLARATION {$$ = new astList(); $$ -> addList($1);}

| DECLARATIONLIST DECLARATION {$$ -> addList($2);}





DECLARATION : TYPE T_VARIABLE T_SEMICOLON {  $$ = new Declaration (*$1,*$2);  }
| TYPE T_VARIABLE T_EQUAL EXPR T_SEMICOLON {
  $$ = new Declaration (*$1,*$2);
}





/*****************************************Base*****************************************************************/
EXPR : TERM                 { $$ = $1; }
|EXPR T_PLUS TERM  {$$ = new AddOperator($1,$3);}
|EXPR T_MINUS TERM  {$$ = new SubOperator($1,$3);}
|EXPR T_MODULO TERM {}
;

TERM : TERM T_TIMES FACTOR   {$$ = new MulOperator($1,$3);}
|TERM T_DIVIDE FACTOR   {$$ = new DivOperator($1,$3);}
|FACTOR               { $$ = $1; }

;

FACTOR : T_NUMBER           { $$ = new Number($1);}
      | T_VARIABLE          {$$ = new Variable (*$1);}
      | T_LBRACKET EXPR T_RBRACKET { $$ = $2; }
;
/*****************************************Definitions*****************************************************************/

RETURN : T_RETURN T_VARIABLE T_SEMICOLON
TYPE : T_NUMINT {$$ = new std::string ("int");};
/*****************************************Comparison*****************************************************************/
IFWHILE : T_IF | T_WHILE


COMPARE :
COMPARE2VAR
| T_NOT T_LBRACKET COMPARE2VAR T_RBRACKET
| T_NUMBER

COMPARE2VAR : T_VARIABLE COND_OP T_VARIABLE
| T_VARIABLE COND_OP T_NUMBER
| T_NUMBER COND_OP T_NUMBER


COND_OP :
T_EQ_OP
|T_NE_OP
|T_GREATERTHAN
|T_LESSTHAN
|T_LE_OP
|T_GE_OP
|UNARY_OP
/*****************************************++--*****************************************************************/
INCDEC : T_INC_OP
| T_DEC_OP

/*****************************************&& ||*****************************************************************//*****************************************Definitions*****************************************************************/
UNARY_OP :
T_AND_OP
|T_OR_OP



ASSIGNMENT_OP : T_EQUAL /* Eq uality statement*/
|T_MUL_ASSIGN
|T_DIV_ASSIGN
|T_MOD_ASSIGN
|T_ADD_ASSIGN
|T_SUB_ASSIGN
|T_LEFT_ASSIGN
|T_RIGHT_ASSIGN
|T_AND_ASSIGN
|T_XOR_ASSIGN
|T_OR_ASSIGN
;

%%

const Base *g_root; // Definition of variable (to match declaration earlier)

const Base *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
