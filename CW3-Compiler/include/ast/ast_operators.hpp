#ifndef ast_operators_hpp
#define ast_operators_hpp


#include <string>
#include <iostream>
using namespace std;
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
virtual void addList (Base*) override {
}

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


{ //( ( ( b + a ) + 50 ) - ( 50 / 5 ) )

        std::cout<<"( ";
        left->print(); //print number from number class
        std::cout<<" ";
        std::cout<<getOpcode();
        std::cout<<" ";
        right->print();
        std::cout<<" )";
}

virtual void pAssem(Stack* stPtr) const override {
        //set opcount = 0 in statement listt
        cout << "\n#Operator" << endl;


        left->pAssem(stPtr); //left value

        int reg1 = stPtr->getReg(); //get left register (-1 because we run through in dec)
        int Lval = stPtr->getexprValue(); // for const




        right->pAssem(stPtr);

        int reg2 = stPtr->getReg(); //get right register
        int Rval = stPtr->getexprValue();



        string c (getOpcode()); //convert string


        stPtr->eval(c,Lval,Rval);         //evaluate constants

                        if ( c == "+") {
                                stPtr->instruct("addu",reg2,reg1,reg2);

                        }
                        if ( c == "-") {
                                stPtr->instruct("subu",reg2,reg1,reg2);

                        }
                        if ( c == "*") {

                                stPtr->instruct("mul",reg2,reg1,reg2);

                        }
                        if ( c == "/") {

                                stPtr->TrapTeq(reg2);
                                stPtr->instruct("div",0,reg1,reg2);
                                stPtr->HiLoReg("hi",reg2);
                                stPtr->HiLoReg("lo",reg2);

                        }

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
