#include <vector>
using namespace std;
class Statement : public Base {

private:
vector<Base*> expressions; // might delete
string id;
string opCode; // implement next
Base *ptr;
bool returnY;
public:
Statement(){
};

Statement(string a,string op, Base *b, bool ret) : id(a),opCode(op), ptr(b),returnY(ret) {
}
virtual void print() const override
{
}
virtual void addList (Base *d) override {
        //  Base *tmp = d;

        expressions.push_back(d);

}

virtual void pAssem(Stack* stPtr) const override {
//First check if base ptr is NULL
        if (ptr ==NULL ) {

                cout << "#(No expr )Id : " << id << " opcode : " << opCode << endl;
                if ( stPtr->mapLookup(id) == true) {
                        //if it's in map, get the offset
                        int offset= stPtr->mapGet(id);

                        stPtr->storeLoad("lw",stPtr->getReg(),offset);
                        int reg = stPtr->getReg();

                        if (opCode == "++") { //increment
                                cout << "addiu $"<<reg <<", $"<<reg << ", 1" << endl;
                        }
                        if (opCode == "--") { //increment
                                cout << "addiu $"<<reg <<", $"<<reg << ", -1" << endl;
                        }

                        //////////////?RETURN//////////////

                        if ( returnY == true) {
                                //move to reg 2 if true return
                                cout << "move $2, $" << stPtr->getReg()<<endl;
                        }
                        else {   // no return
                                stPtr->storeLoad("sw",stPtr->getReg(),offset);
                        }

                }
                else {
                        std:: cout << "Your variable " << id << " on line: "<< lineNum <<" is not in the map" << std:: endl;
                        cout << "Have you declared " << id <<"? "<< endl;
                }




        }
        else { // we have expression

                if ((id == "") && returnY == true) {
                        cout << "\n#Return statement" << endl;
                        //get variable name from EXPR
                        //stPtr->setReg(2);

                        stPtr->setReturn (true);

                        stPtr->setVar(0); // number of varaibles in expr = 0
                        ptr->pAssem(stPtr); //remove variable stuff in class

                        //need to check how many variables

                        //function call
                        if (stPtr->getfuncCall()==true) {
                          cout << "move $2, $" << stPtr->getReg() << endl;
                          stPtr->setfuncCall(false); }
                        else if (stPtr->getVar()==0 ) {
                                //this works for numerical
                                //not for  variables
                                cout << "li $2, " << stPtr->getexprValue() << endl;

                        }

                        else {
                                if(stPtr->getGlobal()!= 0) {
                                        cout <<"lw $2"<<", 0($"<<stPtr->getGlobal()<<")"<<endl;
                                }
                                else {
                                        cout << "move $2, $" << stPtr->getReg() << endl;
                                }
                        }



                }





                else { // normal statement
                       //count number of operands (if 1 we do something different)
                        stPtr->setOperands(0);
                        stPtr->setVar(0);
                        stPtr->setReg(9);
                        cout << "\n#Normal statment" << endl;
                        cout << "#id : " << id << " opCode : "<< opCode << endl;
                        cout << endl;
                        //First check if in map
                        if ( stPtr->mapLookup(id) == true) {
                                //if it's in map, get the offset
                                int offset= stPtr->mapGet(id);
                                int destReg = stPtr->getReg();

                                stPtr->storeLoad("lw",stPtr->getReg(),offset);
                                ptr->pAssem(stPtr); //put into exprval;

                                if (opCode == "%=") { //increment
                                        stPtr->TrapTeq(stPtr->getReg()); //if dividing by 0
                                        stPtr->instruct("div",0,destReg,stPtr->getReg());
                                        stPtr->HiLoReg("hi",stPtr->getReg());
                                }
                                if (opCode == "<<=") { //increment
                                        cout << "sllv $"<<stPtr->getReg()<< ", $" <<destReg<< ", $"<<stPtr->getReg()<<endl;
                                        //we load the word from stack into prev reg2
                                        //but we store using the next
                                }
                                if (opCode == ">>=") { //increment
                                        cout << "srlv $"<<stPtr->getReg()<< ", $" <<destReg<< ", $"<<stPtr->getReg()<<endl;
                                }
                                if (opCode == "&=") { //increment
                                        cout << "and $"<<stPtr->getReg()<< ", $" <<destReg<< ", $"<<stPtr->getReg()<<endl;
                                }
                                if (opCode == "^=") { //increment
                                        cout << "xor $"<<stPtr->getReg()<< ", $" <<destReg<< ", $"<<stPtr->getReg()<<endl;
                                }
                                if (opCode == "|=") { //increment
                                        cout << "xor $"<<stPtr->getReg()<< ", $" <<destReg<< ", $"<<stPtr->getReg()<<endl;
                                }


                                stPtr->storeLoad("sw",stPtr->getReg(),offset);

                        }
                        else {
                                //no in map - glboal


                                cout << "lui	$28,%hi(__gnu_local_gp)"<<endl;
                                cout <<"addiu	$28,$28,%lo(__gnu_local_gp)" << endl;
                                cout << "lw $"<< stPtr->getReg()<< ", %got("<<id <<")($28)"<<endl; //the offset
                                int glob = stPtr->getReg();

                                int destReg = stPtr->getReg();


                                ptr->pAssem(stPtr); //put into exprval;

                                if (opCode == "%=") { //increment
                                        stPtr->TrapTeq(stPtr->getReg()); //if dividing by 0
                                        stPtr->instruct("div",0,destReg,stPtr->getReg());
                                        stPtr->HiLoReg("hi",stPtr->getReg());
                                }
                                if (opCode == "<<=") { //increment
                                        cout << "sllv $"<<stPtr->getReg()<< ", $" <<destReg<< ", $"<<stPtr->getReg()<<endl;
                                        //we load the word from stack into prev reg2
                                        //but we store using the next
                                }
                                if (opCode == ">>=") { //increment
                                        cout << "srlv $"<<stPtr->getReg()<< ", $" <<destReg<< ", $"<<stPtr->getReg()<<endl;
                                }
                                if (opCode == "&=") { //increment
                                        cout << "and $"<<stPtr->getReg()<< ", $" <<destReg<< ", $"<<stPtr->getReg()<<endl;
                                }
                                if (opCode == "^=") { //increment
                                        cout << "xor $"<<stPtr->getReg()<< ", $" <<destReg<< ", $"<<stPtr->getReg()<<endl;
                                }
                                if (opCode == "|=") { //increment
                                        cout << "xor $"<<stPtr->getReg()<< ", $" <<destReg<< ", $"<<stPtr->getReg()<<endl;
                                }

                                cout << "sw $"<<stPtr->getReg()<<", 0($"<<glob<<")"<<endl;


                        }
                }



        }
}
};
