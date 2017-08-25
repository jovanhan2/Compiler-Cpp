#ifndef ast_types_hpp
#define ast_types_hpp


#include <string>
#include <iostream>
#include <vector>




class Types
        : public Base
{
private:
string name;

protected:
Types(const string a) : name(a) {
}

public:

virtual const char *getOpcode() const =0;
virtual void addList (Base* d) override {
          
  }
virtual void print() const override
{

        std::cout<<"\t<Variable id=\""<<name<<"\" />"<< std::endl;
}




};

class Int
        : public Types
{
protected:
virtual const char *getOpcode() const override
{
        return "int";
}
public:
Int(string val)  : Types(val){
}
};

class DeclarationList : public Base
{
private:

const Base *left;
const Base *right;

public:
DeclarationList(const Base *_left, const Base *_right)
        : left(_left)
        , right(_right)
{
}
virtual ~DeclarationList()
{
        delete left;
        delete right;
}
virtual void print() const override
{
        left->print();
        right->print();
        std::cout<< std::endl;
}

};








class FuncDef : public Base
{
private:
string name;
const Base* args;

public:
FuncDef(const string a,const Base* b) : name(a),args(b) {
}

virtual void print() const override
{
/*    std::cout<<"\t<Function id=\""<<name<<"\" />"<< std::endl;
    args->print();
    std::cout<<"\t</Function>"<< std::endl;
 */
}
};



#endif
