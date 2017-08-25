#ifndef ast_functions_hpp
#define ast_functions_hpp

using namespace std;
class FunctionDef
        : public Base
{
private:
std :: string returnType;
std:: string fName;
paramList* paramPtr;
astList* allPtr;

public:
FunctionDef(string a, string b,paramList* c,astList* d)
        : returnType(a),fName(b),paramPtr(c),allPtr(d)
{
}
virtual void addList(Base* ptr){
}

virtual void print() const override
{
}
virtual void pAssem(Stack* stPtr) const override {
        stPtr->setFuncName(fName);
//only want to update return is there is a function call
        cout << ".globl "<< fName << endl;
        cout << ".ent " << fName << endl; // needed to work
        std :: cout << ".type " << fName << ", @function" << std:: endl;
        cout << fName << ": \n" << endl; //entry point to function
        //allocate 8 byte on stack

        stPtr->push_Stack(); //stack offset
        //get number of params
        if( paramPtr!= NULL) {
                paramPtr->pAssem(stPtr);
        }
        if (allPtr!=NULL) {
                allPtr->pAssem(stPtr);

        }
        stPtr->endFunction(fName,stPtr);



}

};

class FunctionCall
        : public Base
{
private:

std:: string fName;
ArgumentList* argListPtr;


public:
FunctionCall(string a, ArgumentList* b)
        : fName(a),argListPtr(b)
{
}
virtual void addList(Base* ptr){
}

virtual void print() const override
{
}
virtual void pAssem(Stack* stPtr) const override {
        stPtr->setfuncCall(true);

        if( argListPtr!= NULL) { //store argument Li - load constant into reg
                argListPtr->pAssem(stPtr);
        }
        cout << "jal " << fName << endl; //jump to Function
        cout << "nop"<<endl;
  

        stPtr->setReg(2); //result will be in 2
        //get result register and put into reg 2


}

};
class Argument
        : public Base
{
private:
int value;
bool Var;
Base* variable;
public:
Argument (int a,bool isVar,Base *ptr) : value (a), Var(isVar), variable(ptr)
{
}
virtual void addList(Base* ptr){
}

virtual void print() const override
{
}
virtual void pAssem(Stack* stPtr) const override {

        int reg = stPtr->getReg();

        cout << "li" << " $"<<reg << ", " << value << endl;
}

};

#endif