#include "ast.hpp"
using namespace std;

int main()
{
        const Base *ast=parseAST();
        int test = 0;
        if (test == 1 ) {
                cout << "#Stack : " << endl;
                cout << "" << endl;
                cout << "=========================" << endl;
                cout << "0 - Current stack pointer" << endl;
                cout << "=========================" << endl;
                cout <<"+ 4 Return address" << endl;
                cout << "=========================" << endl;
                cout << "+ 8 Old frame pointer " << endl;
                cout << "=========================" << endl;
                cout << "+ 12 Funcall Return address " << endl;
                cout << "=========================" << endl;
                cout << "+34 second var" << endl;
                cout << "=========================" << endl;
                cout << "+36 first var" << endl;
                cout << "=========================" << endl;
                cout << endl;
        }
//use cat {inputfile} | bin/c_lexer to run
        Stack *stack = new Stack();
        //cout << "In complier" << endl;
        ast->pAssem(stack);
        //  ast->print();

        std::cout<<std::endl;

        return 0;
}
