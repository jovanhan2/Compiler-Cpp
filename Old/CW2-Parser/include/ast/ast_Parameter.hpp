class Param : public Base
{
private:

string type;
string id;

public:
Param(const string a, string b) : type(a), id(b) {};
virtual void print() const override
{
        std::cout<<"\t<Parameter id=\""<<id<<"\" />";
}
virtual void addList (Base* p)override{

}
};
