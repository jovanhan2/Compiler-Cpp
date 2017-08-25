#include <vector>


class astList : public Base {

private:
vector<Base*> st;

public:

astList () {
};
int getSize(){

return st.size();
  //return st.size();
}
virtual void addList (Base *d) override {
        Base *tmp = d;

        st.push_back(tmp);
}
virtual void print() const override
{
}
virtual void pAssem(Stack* stPtr) const override {

        for (unsigned int i = 0; i < st.size(); i++) {

                st[i]->pAssem(stPtr);
          //      cout << "printing astList" << endl;
        }
        //stPtr->mapOut();

}
};

class DeclarationList : public Base {

private:
vector<Base*> st;

public:

DeclarationList () {
};
int getSize(){

return st.size();

}
virtual void addList (Base *d) override {
        Base *tmp = d;

        st.push_back(tmp);
}
virtual void print() const override
{

}
virtual void pAssem(Stack* stPtr) const override {
        //stPtr ->setReg(7); //argument register 7 -> 4
        //once more than 4 push to stack
        stPtr->setStackOffset(76);//set stack offset
        //set reg to save declarations
        stPtr->setReg(8); //8th reg

        cout << endl;
        cout << "#Declarations (saved to stack)"<<endl;
        for (unsigned int i = 0; i < st.size(); i++) {

              st[i]->pAssem(stPtr);

              stPtr-> incdecStackOffset(-4);// decrement by 4

        }
      //  stPtr->mapOut();


}
};


class paramList : public Base {

private:
vector<Base*> st;

public:

paramList () {
};
int getSize(){

return st.size();
  //return st.size();
}
virtual void addList (Base *d) override {
        Base *tmp = d;

        st.push_back(tmp);
}
virtual void print() const override
{

}
virtual void pAssem(Stack* stPtr) const override {
        stPtr ->setReg(4); //set parms register 4
        stPtr ->setStackOffset(80); //set stack offset 8
        cout << "#Storing params $7-$4"<<endl;
        for (unsigned int i = 0; i < st.size(); i++) {

              st[i]->pAssem(stPtr);
            stPtr-> incdecReg(1);// next reg
            stPtr->incdecStackOffset(+4);

        }
        //stPtr->mapOut();

}
};

class ArgumentList : public Base {

private:
vector<Base*> st;

public:

ArgumentList () {
};
int getSize(){

return st.size();

}
virtual void addList (Base *d) override {
        Base *tmp = d;

        st.push_back(tmp);
}
virtual void print() const override
{

}
virtual void pAssem(Stack* stPtr) const override {
        stPtr ->setReg(7); //argument register 7 -> 4
        //once more than 4 push to stack

        for (unsigned int i = 0; i < st.size(); i++) {

              st[i]->pAssem(stPtr);
              stPtr-> incdecReg(-1);// next reg

        }


}
};
