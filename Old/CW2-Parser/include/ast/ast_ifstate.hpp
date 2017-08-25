#ifndef ast_ifstate_hpp
#define ast_ifstate_hpp





class ifDef
    : public Base
{
private:
vector <Base*> dlist;


public:
  ifDef (){};
  virtual void addList (Base* d) override {
            dlist.push_back(d);
    }

    virtual void print() const override
    {


      std::cout <<"\t\t<Scope>" <<std::endl;
        for (unsigned int i = 0; i < dlist.size(); i++) {

      dlist[i]->print();
    }
    std::cout <<"\t\t</Scope>" <<std::endl;


    }

};

class Else
    : public Base
{
private:
vector <Base*> dlist;


public:
  Else (){};
  virtual void addList (Base* d) override {
            dlist.push_back(d);
    }

    virtual void print() const override
    {


      std::cout <<"\t\t<Scope>" <<std::endl;
        for (unsigned int i = 0; i < dlist.size(); i++) {

      dlist[i]->print();
    }
    std::cout <<"\t\t</Scope>" <<std::endl;


    }

};
/*
class fList : public Base
{
private:

std::vector<FunctionDef*> List;

public:
fList(){};

void addList (FunctionDef* p) {
        List.push_back(p);
}
virtual void print() const override
{
  for (unsigned int i = 0; i < List.size(); i++) {
      //cout << "\t";
          List[i]->print();

  }
  cout << endl;
}


};


*/


#endif
