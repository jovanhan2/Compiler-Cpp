#include <vector>

class Declaration : public Base {

private:
std :: string type;
std :: string id;

public:
Declaration (std::string t, std:: string i) : type(t),id(i){
};
virtual void addList (Base *d) override{

}
virtual void print() const override
{

        std::cout<<"\t<Variable id=\""<<id<<"\" />"<< std::endl;


}
};
