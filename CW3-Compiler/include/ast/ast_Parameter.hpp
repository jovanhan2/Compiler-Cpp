class Param : public Base
{
private:

string type;
string id;

public:
Param( string a, string b) : type(a), id(b) {
};

/*
mutable int stackOffset;
mutable int reg;
public:
Param( string a, string b, int stackOff = 0,int reg=0) : type(a), id(b),stackOffset(stackOff),reg(reg) {
};
*/

virtual void print() const override
{
        std::cout<<"\t<Parameter id=\""<<id<<"\" />";
}
virtual void addList (Base* p) override {

}

virtual void pAssem(Stack* stPtr) const override {

      int reg = stPtr -> getReg();
      int stackOffset = stPtr -> getStackOffset();
    //  std::cout << "In param reg stack offset : " << reg << "  " << stackOffset << std::endl;
       stPtr->storeLoad ("sw",reg,stackOffset);
        //need to save it to map here
        stPtr->bindingInsert(stackOffset,id); //save stack offset





}
};
