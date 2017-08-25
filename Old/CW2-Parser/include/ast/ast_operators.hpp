#ifndef ast_operators_hpp
#define ast_operators_hpp


#include <string>
#include <iostream>

class Operator
        : public Base
{
private:
const Base *left;
const Base *right;
protected:
Operator(const Base *_left, const Base *_right)
        : left(_left)
        , right(_right)
{
}
public:

virtual ~Operator()
{
        delete left;
        delete right;
}
virtual void addList (Base*)override{}

virtual const char *getOpcode() const =0;

const Base *getLeft() const
{
        return left;
}

const Base *getRight() const
{
        return right;
}

virtual void print() const override


{
        std::cout<<"( ";
        left->print(); //print number from number class
        std::cout<<" ";
        std::cout<<getOpcode();
        std::cout<<" ";
        right->print();
        std::cout<<" )";
}



};






class AddOperator
        : public Operator
{
protected:
virtual const char *getOpcode() const override
{
        return "+";
}
public:
AddOperator(const Base *_left, const Base *_right)
        : Operator(_left, _right)
{
}





};

class SubOperator
        : public Operator
{
protected:
virtual const char *getOpcode() const override
{
        return "-";
}
public:
SubOperator(const Base *_left, const Base *_right)
        : Operator(_left, _right)
{
}

};

class MulOperator
        : public Operator
{
protected:
virtual const char *getOpcode() const override
{
        return "*";
}
public:
MulOperator(const Base *_left, const Base *_right)
        : Operator(_left, _right)
{
}



};

class DivOperator
        : public Operator
{
protected:
virtual const char *getOpcode() const override
{
        return "/";
}
public:
DivOperator(const Base *_left, const Base *_right)
        : Operator(_left, _right)
{
}

};




#endif
