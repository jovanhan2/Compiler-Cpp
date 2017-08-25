#ifndef ast_primitives_hpp
#define ast_primitives_hpp

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;




class Number
    : public Base
{
private:
    double value;
public:
    Number(double _value)
        : value(_value)
    {}

    double getValue() const
    { return value; }
virtual void addList (Base*)override{}
    virtual void print() const override
    {
        std::cout<<value;
    }


};

class Variable
    : public Base
{
private:
    std::string id;
public:
    Variable(const std::string &_id)
        : id(_id)
    {}
virtual void addList (Base*) override{}
    const std::string getId() const
    { return id; }

    virtual void print() const override
    {
      std::cout << id;
      //  std::cout<<"<Parameter id=\""<<id<<"\" />"<< std::endl;
    }

};


#endif
