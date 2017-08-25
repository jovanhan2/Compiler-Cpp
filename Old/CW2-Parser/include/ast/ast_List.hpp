#include <vector>


class astList: public Base {

private:
vector<Base*> st;

public:

astList () {};
virtual void addList (Base *d) override{
    Base *tmp = d;

        st.push_back(tmp);
}
virtual void print() const override
{
  
for (unsigned int i = 0; i < st.size(); i++) {

       st[i]->print();

}

}
};
