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

  double number;
  std::string *string;


  paramList *paramlistPtr;
  astList *listPtr;
   Declaration *DecPtr;
   Statement *statePtr;

   FunctionDef *Funct;

   astList *topPtr;
   Param *paramPtr;


   Base *basePtr;
   ifLoop *ifPtr;
  Argument *argPtr;
  ArgumentList * argListPtr;
  FunctionCall *funcCallPtr;
  DeclarationList *decList;
  Comp *comPtr;
}
%token T_COMMAR T_NEWLINE T_RETURN T_MODULO T_GREATERTHAN T_LESSTHAN T_NOT T_WHILE T_ELSE T_FOR T_QUESTIONM T_COLON
%token T_TIMES T_PLUS T_DIVIDE T_MINUS T_LBRACKET T_RBRACKET T_LOG T_EXP T_SQRT T_NUMBER T_VARIABLE T_LCURLY T_RCURLY T_NUMINT T_SEMICOLON
%token T_IF T_EQUAL T_MUL_ASSIGN T_DIV_ASSIGN T_MOD_ASSIGN T_ADD_ASSIGN T_SUB_ASSIGN T_LEFT_ASSIGN T_RIGHT_ASSIGN T_AND_ASSIGN T_XOR_ASSIGN T_OR_ASSIGN
%token T_LE_OP T_GE_OP T_EQ_OP T_NE_OP T_RIGHT_OP T_LEFT_OP T_INC_OP T_DEC_OP T_PTR_OP T_AND_OP T_OR_OP T_CHAR T_QUOTE

%type <decList> DECLARATIONLIST

%type <argListPtr> ARGUMENTLIST
%type<argPtr> ARGUMENT
//%type <comPtr>
%type<basePtr> BASE EXPR TERM FACTOR STATEMENT IFLOOP COMPARITORS COMPARETERM  COMPARE WHILE FORLOOP DECLARATION FUNCTIONCALL FUNCTION
%type<listPtr> FUNCTIONLIST STATEMENTLIST ALLSTATE
%type<paramlistPtr> PARAMLIST


%type <paramPtr> PARAM



%type <number> T_NUMBER
%type <string> T_VARIABLE T_NUMINT TYPE ASSIGNMENT_OP INCDEC COND_OP CON_OPANDOR

%start ROOT
%expect 0//dangling else
%%

ROOT : BASE { g_root = $1; }

BASE : FUNCTIONLIST { $$ = new astList();$$->addList($1); }
| FUNCTIONLIST ALLSTATE{ $$->addList($2);}
| DECLARATIONLIST { $$ = new astList();$$->addList($1);}
| FACTOR { $$ = new astList(); $$->addList($1);}

//nee to fix mul func def

/*****************************************Function*****************************************************************/

FUNCTIONLIST : DECLARATIONLIST FUNCTION{ $$ = new astList(); $$ -> addList($1);$$ -> addList($2);}

| FUNCTION {$$ = new astList(); $$ -> addList($1);}
| FUNCTIONLIST FUNCTION{ $$->addList($2);}
| FUNCTIONLIST DECLARATIONLIST FUNCTION {$$->addList($2);$$->addList($3); }
| FUNCTION T_SEMICOLON {$$ = new astList(); $$->addList($1);}

 FUNCTION : TYPE T_VARIABLE T_LBRACKET PARAMLIST T_RBRACKET T_LCURLY ALLSTATE T_RCURLY //param + code
 {$$ = new FunctionDef(*$1,*$2,$4,$7);}
 | TYPE T_VARIABLE T_LBRACKET T_RBRACKET T_LCURLY ALLSTATE T_RCURLY //no param
 {$$ = new FunctionDef(*$1,*$2,NULL,$6); }
 | TYPE T_VARIABLE T_LBRACKET T_RBRACKET T_LCURLY T_RCURLY // no param no  code
 {$$ = new FunctionDef(*$1,*$2,NULL,NULL);}
 | TYPE T_VARIABLE T_LBRACKET PARAMLIST T_RBRACKET T_LCURLY T_RCURLY //no code
 {$$ = new FunctionDef(*$1,*$2,$4,NULL);}
 | TYPE T_VARIABLE T_LBRACKET T_RBRACKET  // no param Func definition
 {$$ = new astList();}
 | TYPE T_VARIABLE T_LBRACKET PARAMLIST T_RBRACKET //param funcction def
 {$$ = new astList();}






/*****************************************Parameters*****************************************************************/
PARAMLIST : PARAM { $$ = new paramList(); $$ -> addList($1);}
| PARAMLIST T_COMMAR PARAM { $$ ->addList($3);}
PARAM : TYPE T_VARIABLE { $$ = new Param(*$1,*$2);}
 /*****************************************Declarations + Statement combined*****************************************************************/
 ALLSTATE   : DECLARATIONLIST STATEMENTLIST  { $$ = new astList();$$->addList($1); $$->addList($2);}
  |STATEMENTLIST { $$ = new astList();$$->addList($1);}
 | DECLARATIONLIST { $$ = new astList();$$->addList($1);}


/*****************************************Statement*****************************************************************/
STATEMENTLIST : STATEMENT  {$$ = new astList();$$ ->addList($1);}
|STATEMENT T_SEMICOLON {$$ = new astList();$$ ->addList($1);}
| STATEMENTLIST STATEMENT { $$ -> addList($2);}
| STATEMENTLIST STATEMENT T_SEMICOLON{ $$ -> addList($2);}
//| STATEMENTLIST STATEMENTNOSEMI  { $$ -> addList($2);}

STATEMENT : T_VARIABLE ASSIGNMENT_OP EXPR  {
  if (*$2 == "=") {$$ = new Statement(*$1,*$2,$3,false); }
  else {
          Base* var = new Variable(*$1);
          Base* temp = $3; // if conditions not met (+/-*)
          if (*$2 == "+=") {  temp = new AddOperator(var,$3); }
          else if (*$2 == "-=") { temp = new SubOperator(var,$3); }
          else if (*$2 == "*=") {  temp = new MulOperator(var,$3); }
          else if (*$2 == "/=") { temp = new DivOperator(var,$3); }

          $$ = new Statement (*$1,*$2,temp,true); // new statement
  }

}
|  T_RETURN EXPR T_SEMICOLON { $$ = new Statement("","",$2,true); }
| INCDEC T_VARIABLE {$$ = new Statement(*$2,*$1,NULL,false);}
| T_VARIABLE INCDEC {$$ = new Statement(*$1,*$2,NULL,false);}
| T_RETURN T_VARIABLE INCDEC T_SEMICOLON{$$ = new Statement(*$2,*$3,NULL,true);}
| T_RETURN INCDEC T_VARIABLE T_SEMICOLON{$$ = new Statement(*$3,*$2,NULL,true);}

| IFLOOP { $$= $1;}
| WHILE  { $$ = $1;}
| FORLOOP {$$=$1;}



//| T_LBRACKET COMPARE T_RBRACKET T_QUESTIONM STATEMENTNOSEMI T_COLON STATEMENT { $$ = new Statement(); $$->addList($5);$$->addList($7);}
//| COMPARE T_QUESTIONM STATEMENTNOSEMI T_COLON STATEMENT { $$ = new Statement(); $$->addList($3);$$->addList($5);}



//| T_RETURN T_NOT T_LBRACKET COMPARE T_RBRACKET T_SEMICOLON {$$= new Statement();}



/****************************************IF statemetn*****************************************************************/
IFLOOP :
T_IF T_LBRACKET COMPARE T_RBRACKET T_LCURLY ALLSTATE T_RCURLY {$$ = new ifLoop ($3,$6,"if");}
|T_IF T_LBRACKET COMPARE T_RBRACKET T_LCURLY T_RCURLY { $$ = new ifLoop ($3,NULL,"if");}
|T_IF T_LBRACKET COMPARE T_RBRACKET T_LCURLY ALLSTATE T_RCURLY T_ELSE T_LCURLY ALLSTATE T_RCURLY {$$ = new ifelseLoop ($3,$6,$10,"ifelse");}
|T_IF T_LBRACKET COMPARE T_RBRACKET T_LCURLY ALLSTATE T_RCURLY T_ELSE T_LCURLY T_RCURLY {$$ = new ifelseLoop ($3,$6,NULL,"ifelse");}
|T_IF T_LBRACKET COMPARE T_RBRACKET T_LCURLY T_RCURLY T_ELSE T_LCURLY ALLSTATE T_RCURLY {$$ = new ifelseLoop ($3,NULL,$9,"ifelse");}
|T_IF T_LBRACKET COMPARE T_RBRACKET T_LCURLY T_RCURLY T_ELSE T_LCURLY T_RCURLY {$$ = new ifelseLoop ($3,NULL,NULL,"ifelse");}
//) 1
|T_IF T_LBRACKET FACTOR T_RBRACKET T_LCURLY ALLSTATE T_RCURLY {$$ = new ifLoop ($3,$6,"iffactor");}


WHILE : T_WHILE T_LBRACKET COMPARE T_RBRACKET T_LCURLY ALLSTATE T_RCURLY {$$ = new ifLoop ($3,$6,"while");}
|T_WHILE T_LBRACKET COMPARE T_RBRACKET ALLSTATE T_RCURLY {$$ = new ifLoop ($3,NULL,"while");}
|T_WHILE T_LBRACKET FACTOR T_RBRACKET T_LCURLY ALLSTATE T_RCURLY {$$ = new ifLoop ($3,$6,"whilefactor");}
|T_WHILE T_LBRACKET FACTOR T_RBRACKET T_LCURLY T_RCURLY {$$ = new ifLoop ($3,NULL,"whilefactor");}

FORLOOP : T_FOR T_LBRACKET DECLARATION COMPARE T_SEMICOLON STATEMENT T_RBRACKET T_LCURLY ALLSTATE T_RCURLY
{

$$ = new forLoop($4,$9,$3,$6,"for");

}
/*****************************************Functioncall*****************************************************************/

FUNCTIONCALL : T_VARIABLE T_LBRACKET ARGUMENTLIST T_RBRACKET {$$ = new FunctionCall(*$1,$3);}
| T_VARIABLE T_LBRACKET T_RBRACKET {$$ = new FunctionCall(*$1,NULL);}

ARGUMENTLIST : ARGUMENT { $$ = new ArgumentList(); $$ -> addList($1);}
| ARGUMENTLIST T_COMMAR ARGUMENT { $$ ->addList($3);}

ARGUMENT : EXPR { $$ = new Argument($1);}
//T_VARIABLE { Base* ptr = new Variable(*$1);$$ = new Argument(0,ptr);}| T_NUMBER {$$ = new Argument ($1,NULL);}

/*****************************************If statemet*****************************************************************/

DECLARATIONLIST : DECLARATION {$$ = new DeclarationList(); $$ -> addList($1);}

| DECLARATIONLIST DECLARATION {$$ -> addList($2);}


DECLARATION : TYPE T_VARIABLE T_SEMICOLON {  $$ = new Declaration (*$1,*$2,NULL);  }
| TYPE T_VARIABLE T_EQUAL EXPR T_SEMICOLON {
  $$ = new Declaration (*$1,*$2,$4);
}

/*****************************************Base*****************************************************************/
EXPR : TERM                 { $$ =$1; }
|EXPR T_PLUS TERM  {  $$ = new AddOperator($1,$3); }
|EXPR T_MINUS TERM  {  $$= new SubOperator($1,$3);}



;

TERM : TERM T_TIMES FACTOR   { $$ = new MulOperator($1,$3);}
|TERM T_DIVIDE FACTOR   { $$ = new DivOperator($1,$3);}
|FACTOR               { $$ = $1; }
;

FACTOR : T_NUMBER           {$$= new Number ($1); }
      | T_VARIABLE          {$$ = new Variable (*$1);}
      | T_LBRACKET EXPR T_RBRACKET { $$ = $2; }
      | T_QUOTE T_VARIABLE T_QUOTE {$$ = new Char(*$2);}
      | T_QUOTE T_NUMBER T_QUOTE {
        string s =std::to_string($2);$$ = new Char(s);}
      |FUNCTIONCALL {$$ =$1;}
;
/*****************************************Definitions*****************************************************************/
TYPE : T_NUMINT {$$ = new std::string ("int");}
| T_CHAR {$$ = new std::string ("char");}
;
/*****************************************Comparison*****************************************************************/

COMPARE : COMPARETERM { $$ = $1;}
| COMPARE CON_OPANDOR COMPARETERM  {$$ = new Comp($1,$3,*$2);}


COMPARETERM : COMPARETERM COND_OP COMPARITORS {$$ = new Comp($1,$3,*$2);}
| COMPARITORS { $$ = $1;}

COMPARITORS : EXPR COND_OP EXPR {$$ = new Comp($1,$3,*$2);}
| T_LBRACKET COMPARE T_RBRACKET { $$ = $2;}


////////////////////////////////////////////////
COND_OP :
T_EQ_OP {$$ = new std::string ("==");}
|T_NE_OP {$$ = new std::string ("!=");}
|T_GREATERTHAN {$$ = new std::string (">");}
|T_LESSTHAN {$$ = new std::string ("<");}
|T_LE_OP {$$ = new std::string ("<=");}
|T_GE_OP{$$ = new std::string (">=");}

CON_OPANDOR :
T_AND_OP {$$ = new std::string ("&&");}
|T_OR_OP {$$ = new std::string ("||");}
/*****************************************++--*****************************************************************/
INCDEC : T_INC_OP  {$$ = new std::string ("++");}
| T_DEC_OP  {$$ = new std::string ("--");}

/*****************************************&& ||*****************************************************************//*****************************************Definitions*****************************************************************/

ASSIGNMENT_OP : T_EQUAL {$$ = new std::string ("=");} /* Eq uality statement*/
|T_MUL_ASSIGN {$$ = new std::string ("*=");}
|T_DIV_ASSIGN {$$ = new std::string ("/=");}
|T_MOD_ASSIGN {$$ = new std::string ("%=");}
|T_ADD_ASSIGN {$$ = new std::string ("+=");}
|T_SUB_ASSIGN {$$ = new std::string ("-=");}
|T_LEFT_ASSIGN {$$ = new std::string ("<<=");}
|T_RIGHT_ASSIGN {$$ = new std::string (">>=");}
|T_AND_ASSIGN {$$ = new std::string ("&=");}
|T_XOR_ASSIGN {$$ = new std::string ("^=");}
|T_OR_ASSIGN {$$ = new std::string ("|=");}
;
%%

const Base *g_root; // Definition of variable (to match declaration earlier)

const Base *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
