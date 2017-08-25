#ifndef ast_primitives_hpp
#define ast_primitives_hpp

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Char : public Base {

private:
string id;

public:
Char(string _c) : id (_c) {
}
virtual void addList (Base*) override {
}
virtual void print() const override
{
        std::cout << id;
        //  std::cout<<"<Parameter id=\""<<id<<"\" />"<< std::endl;
}
virtual void pAssem(Stack* stPtr) const override {

  //convert to string
char x = id.at(0);
  int asc = int(x);


  stPtr->setexprValue(asc);

  stPtr->incdecReg(1); // get next register
  cout <<"#In char: "<<id <<" asci:: "<< asc << endl;
  cout << "li $" << stPtr->getReg() << ", "<<asc << endl;

}
};


class Number
        : public Base
{
private:
double value;
public:
Number(double _value)
        : value(_value)
{
}

double getValue() const
{
        return value;
}
virtual void addList (Base*) override {
}
virtual void print() const override
{
        std::cout<<value;
}
virtual void pAssem(Stack* stPtr) const override {
        stPtr->incdecOperands(1); // num of operands

        stPtr->setexprValue(value);

        stPtr->incdecReg(1); // get next register
        cout <<"#In num: " << value << endl;
        cout << "li $" << stPtr->getReg() << ", "<<value << endl;

        /*
           if (stPtr->getReturn()==true) {
                cout << "li $2, " << value << endl;
           }*/
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
{
}
virtual void addList (Base*) override {
}
const std::string getId() const
{
        return id;
}

virtual void print() const override
{
        std::cout << id;
        //  std::cout<<"<Parameter id=\""<<id<<"\" />"<< std::endl;
}
virtual void pAssem(Stack* stPtr) const override {
        stPtr->incdecOperands(1); //num of operands
        stPtr->incdecVar(1); //increment each time there is a variable

        if (stPtr->getReturn()==true) {
                if ( stPtr->mapLookup(id) == true) {
                        cout <<"#In primitive: " << id << endl;
                        //if it's in map, get the offset

                        stPtr->incdecReg(1); // get next register
                        // load into reg 2
                        stPtr->storeLoad("lw",stPtr->getReg(),stPtr->mapGet(id));
                }
        }
        else {

//check if in map
                if ( stPtr->mapLookup(id) == true) {
                        //if it's in map, get the offset

                        stPtr->incdecReg(1);   // get next register
                        cout <<"#In primitive: " << id << endl;
                        stPtr->storeLoad("lw",stPtr->getReg(),stPtr->mapGet(id));

                }
                else {

                  cout << "lui	$28,%hi(__gnu_local_gp)"<<endl;
                  cout <<"addiu	$28,$28,%lo(__gnu_local_gp)" << endl;
                  cout << "lw $"<< stPtr->getReg()<< ", %got("<<id <<")($28)"<<endl;//the offset
                  int glob = stPtr->getReg();
                  stPtr->setGlobal(glob);
                  stPtr->incdecReg(1);
                  cout <<"lw $"<<stPtr->getReg()<<", 0($"<<glob<<")"<<endl;



                }

        }
}
};


#endif
