#ifndef ast_expression_hpp
#define ast_expression_hpp

#include <string>
#include <iostream>
#include <map>

class Base
{
  protected :
  Base *ptr;
public:
    virtual ~Base()
    {}
      virtual void addList (Base*) = 0;

    virtual void print() const =0;



};


#endif
