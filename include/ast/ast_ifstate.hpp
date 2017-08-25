#ifndef ast_ifstate_hpp
#define ast_ifstate_hpp
using namespace std;

class Comp : public Base
{
Base* Left;
Base* Right;
string op;
public:
Comp () {
}
Comp (Base *a, Base *b, string op) :
        Left(a),Right(b),op(op){
}
virtual void addList (Base* d) override {

}


virtual void print() const override
{
}
virtual void pAssem(Stack* stPtr) const override {
        stPtr->setmultiCond(false);

        //places left and right into $24 and $25
        stPtr->setReg(23); //primtiive incr by 1
        Left->pAssem(stPtr);
        stPtr->setReg(24);
        Right->pAssem(stPtr);
        // check cond and use beq label

        if (op == "&&" || op == "||") {
                stPtr->setmultiCond(true);
        }
////
        string opCheck; // our branch conditional
        if(op=="==") {
                opCheck = "bne";
                IFLOOP(opCheck,stPtr);
        }
        if(op=="!=") {
                opCheck = "beq";
                IFLOOP(opCheck,stPtr);
        }

        if (op == ">") {
                //If $s is less than $t, $d is set to one. It gets zero otherwise
                opCheck = "bne";
                //Left and right $24,$25 -> always do right
                //First add one to right
                addOnetoRight();
                ifGreatLess(opCheck,stPtr);
        }
        if (op == "<") {
                opCheck = "beq";
                ifGreatLess(opCheck,stPtr);
        }
        if (op == "<=") {
                opCheck = "beq";
                addOnetoRight();
                ifGreatLess(opCheck,stPtr);
        }
        if (op == ">=") {
                opCheck = "bne";
                ifGreatLess(opCheck,stPtr);
        }

}
void addOnetoRight () const {
        cout <<"addiu $25, $25, 1" << endl;
}

void IFLOOP (string opCheck,Stack* stPtr) const { //==,!=
        string label1;
        label1 = stPtr->makeLabel("Equal");
        cout << opCheck<<" $24, $25, " << label1<<endl;
        cout <<"nop"<<endl;
        //print here
        stPtr->addIfVec(label1); //add to vector
}
void SLT() const {
        cout << "slt $24, $24, $25" << endl;                 //not = 0 jump skip
}
void ifGreatLess (string opCheck,Stack* stPtr) const {
        string label1;
        label1 = stPtr->makeLabel("GreaterThan");
        SLT();
        cout << opCheck<<" $24, $0, " << label1<<endl;
        stPtr->addIfVec(label1);
}
};


class Loop : public Base
{

Base *cond;
Base *expr;
public:
Loop(){
}
Loop (Base* a, Base *b) :
        cond(a),expr(b) {
}
virtual void addList (Base* d) override {

}
virtual Base* getElseExpr() const =0;
virtual string getloopCode() const =0;
virtual Base* getForDec() const = 0;
virtual Base* getForChanger() const = 0;
virtual void print() const override
{
}
virtual void pAssem(Stack* stPtr) const override {
        cout << "#In loop, type : " << getloopCode() << endl;

        string label1;
        //If statement
        //print cond

        if(getloopCode()=="if") {

                cond->pAssem(stPtr);
                checkCode(expr,stPtr);
                //emit if labels here
                multiCheck(stPtr);
                //    stPtr->clearIfVec();
        }
        if(getloopCode()=="iffactor") {
                string temp2 = stPtr->makeLabel("Jump");

                cond->pAssem(stPtr); //not equals 1
                cout << "li $24, 1 "<<endl;
                cout << "bne $24, $"<<stPtr->getReg() << ", "<<temp2 <<  endl;
                checkCode(expr,stPtr);
                cout << temp2 << ":" << endl;

        }

        if(getloopCode()=="ifelse") {
                cond->pAssem(stPtr);
                checkCode(expr,stPtr);
                //else jump
                label1 = stPtr->makeLabel("ElseJump");
                cout <<"b "<< label1 <<endl;
                multiCheck(stPtr);
                checkCode(getElseExpr(),stPtr);
                cout<<label1 << ": " << endl;
        }
        if(getloopCode()=="while") {

                //jump to bne
                string temp= stPtr->makeLabel("Jump");
                cout << "b " << temp <<endl;
                string whileLabel = stPtr->makeLabel("While");
                label1=stPtr->makeLabel("ExitLoop");
                cout <<whileLabel<< ":"<<endl;
                checkCode(expr,stPtr); //emit checkCode
                cout <<temp << ":"<<endl;
                cond->pAssem(stPtr); //bne
                cout<<"b "<< whileLabel<<endl; //go back if equal
                multiCheck(stPtr);
        }
        if(getloopCode()=="whilefactor") {
                string temp= stPtr->makeLabel("Jump");
                string whileLabel = stPtr->makeLabel("While");
                label1=stPtr->makeLabel("ExitLoop");
                string temp2 = stPtr->makeLabel("Jump");

                cout << "b " << temp <<endl;
                cout <<whileLabel<< ":"<<endl;
                checkCode(expr,stPtr); //emit checkCode
                cout <<temp << ":"<<endl;
                cond->pAssem(stPtr); //not equals 1
                cout << "li $24, 1 "<<endl;
                cout << "bne $24, $"<<stPtr->getReg() << ", "<<temp2 <<  endl;
                cout<<"b "<< whileLabel<<endl; //go back if equal
                cout << temp2 << ":" << endl;
        }
        if (getloopCode()=="for") {

                checkCode(getForDec(),stPtr);
                //while
                string temp= stPtr->makeLabel("Jump");
                cout << "b " << temp <<endl;
                string whileLabel = stPtr->makeLabel("While");
                label1=stPtr->makeLabel("ExitLoop");
                cout <<whileLabel<< ":"<<endl;
                checkCode(expr,stPtr); //emit checkCode
                checkCode(getForChanger(),stPtr);
                cout <<temp << ":"<<endl;
                cond->pAssem(stPtr); //bne
                cout<<"b "<< whileLabel<<endl; //go back if equal
                multiCheck(stPtr);


        }

}
void multiCheck (Stack *stPtr) const {
        if (stPtr->getmultiCond() == true) {
                stPtr->printIfLabelAND();
                stPtr->setmultiCond(false);
        }
        else {
                stPtr->printIfLabel();
        }

}
void checkCode (Base* expr,Stack *stPtr) const {
        checkNull(expr,stPtr);   //print it
        checkReturn(stPtr);
}
void checkReturn(Stack* stPtr) const {

        if (stPtr->getReturn()==1) {
              //  stPtr->endFunction(stPtr->getFuncName(),stPtr);
              string ret = stPtr->makeLabel("Return");
                stPtr->setreturnLabel(ret);
                cout <<"b "<< ret << endl;
                cout <<"nop"<<endl;

                //branch instead
                stPtr->setReturn(0);
        }
}

void checkNull ( Base* expr,Stack* stPtr) const {                 //check if null, then print
        if ( expr != NULL) {
                expr->pAssem(stPtr);                 //stuff in if
        }

}


};
class ifLoop : public Loop {
string loopCode;

public:
ifLoop (Base *a, Base *b,string x) :
        Loop(a,b),loopCode(x) {
}
ifLoop(string x = "if") : loopCode(x) {
}

virtual string getloopCode() const override {
        return loopCode;
}
virtual Base* getElseExpr() const override {
        Base *ptr = new astList();
        return ptr;
}
virtual Base* getForDec() const override {
        Base *ptr = new astList();
        return ptr;
}
virtual Base* getForChanger() const override {
        Base *ptr = new astList();
        return ptr;
}

};
class ifelseLoop : public Loop {
string loopCode;
Base* elseptr;
public:
ifelseLoop (Base *a, Base *b,Base* elseptr,string x) :
        Loop(a,b),loopCode(x),elseptr(elseptr) {
}

virtual Base* getElseExpr() const override {
        return elseptr;
}
virtual string getloopCode() const override {
        return loopCode;
}
virtual Base* getForDec() const override {
        Base *ptr = new astList();
        return ptr;
}
virtual Base* getForChanger() const override {
        Base *ptr = new astList();
        return ptr;
}
};

class forLoop : public Loop {

Base* dec;

Base* Changer;
string loopCode;
public:
forLoop (Base *cond, Base *expr,Base* dec,Base* change, string x) :
        Loop(cond,expr),dec(dec),Changer(change),loopCode(x) {
}

virtual Base* getElseExpr() const override {
        return dec;
}
virtual Base* getForDec() const override {
        return dec;
}
virtual Base* getForChanger() const override {
        return Changer;
}
virtual string getloopCode() const override {
        return loopCode;
}
};



#endif
