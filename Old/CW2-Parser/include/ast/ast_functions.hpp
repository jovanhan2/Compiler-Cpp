#ifndef ast_functions_hpp
#define ast_functions_hpp


class FunctionDef
    : public Base
{
private:
    std :: string returnType;
    std:: string fName;
    astList* paramPtr;
    astList* allPtr;



public:
  FunctionDef(string a, string b,astList* c,astList* d)
      : returnType(a),fName(b),paramPtr(c),allPtr(d)
  {}
    virtual void addList(Base* ptr){}

    virtual void print() const override
    {
        std::cout<<endl;
      if (fName != ""){
      std::cout<<"\t<Function id=\""<<fName<<"\">"<< std::endl;
    }
    if (paramPtr != NULL){
      paramPtr ->print();
        std::cout<<endl;
      }

      std::cout <<"\t<Scope>" <<std::endl;
      if (allPtr != NULL){
        std::cout<<"\t";
      allPtr->print();
    }
    std::cout <<"\t</Scope>" <<std::endl;
      //std::cout << std::endl;
      std::cout<<"\t</Function>"<< std::endl;
      std::cout << std::endl;


    }

};



#endif
