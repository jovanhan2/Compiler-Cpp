#include <vector>

class Declaration : public Base {

private:
std :: string type;
std :: string id;
Base* ptr;
public:
Declaration (std::string t, std:: string i, Base *a) : type(t),id(i),ptr(a){
};
virtual void addList (Base *d) override {

}
virtual void print() const override
{

        std::cout<<"\t<Variable id=\""<<id<<"\" />"<< std::endl;


}
virtual void pAssem(Stack* stPtr) const override {
        cout << endl;
        cout << "# (Dec) varID :" <<id << " type :" << type <<endl;
        //std::string reg = "$2";
        //  std::cout << "In assembly " << id << std::endl;
//  std :: cout << "add " << reg << ", $0, 0" << std:: endl;

        if (ptr ==NULL ) { //simple dec int x;
                if ( stPtr->mapLookup(id) == true) {
                        //if it's in map, get the offset
                        cout <<"Error! You have already declared this variable";
                        cout << " Line : " << lineNum << endl;

                }
                else {
                        int stackOffset = stPtr->getStackOffset(); // get stack offset
                        stPtr->bindingInsert(stackOffset,id); //save stack offset
                        int reg = stPtr->getReg(); //reg 4
                        stPtr->storeLoad("lw",reg,stackOffset);
                }
        }

        if (ptr != NULL) {


                // now save to stack
                //check if in map
                if ( stPtr->mapLookup(id) == true) {
                        //if it's in map, get the offset
                        cout <<"Error! You have already declared this variable";
                        cout << " Line : " << lineNum << endl;

                }
                else { //not in map

                        cout << "#Placing into map, line : "<< lineNum << endl;

                        int stackOffset = stPtr->getStackOffset(); // get stack offset
                        stPtr->bindingInsert(stackOffset,id); //save stack offset

                        stPtr->setVar(0); // number of varaibles in expr = 0
                        //  ptr->print();
                        ptr->pAssem(stPtr); //store number into exp value
                        //want to check how many variables here (in declaration)
                        int reg = stPtr->getReg();
                        stPtr->storeLoad("sw",reg,stackOffset);
                        //stPtr->mapOut();

                }
        }
}

};
