#ifndef ast_hpp
#define ast_hpp

#include "ast/ast_Base.hpp"

#include "ast/ast_primitives.hpp"
#include "ast/ast_operators.hpp"

#include "ast/ast_types.hpp"
#include "ast/ast_Parameter.hpp"

#include "ast/ast_Declarations.hpp"
#include "ast/ast_StatementList.hpp"

#include "ast/ast_List.hpp"
#include "ast/ast_functions.hpp"
#include "ast/ast_ifstate.hpp"
extern const Base *parseAST();
/* Defined in parser.y as well
   Parse input from stdin (from Flex, which is providing tokens to Bison)
   Then return AST

   bin/print_canonical - use parseAST() to parse input, and print as canonical representation

   Canonical form -

 */

#endif
