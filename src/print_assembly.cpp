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
                cout << "+84 second var" << endl;
                cout << "=========================" << endl;
                cout << "+88 first var" << endl;
                cout << "=========================" << endl;
                cout << "+92 Old frame pointer " << endl;
                cout << "=========================" << endl;
                cout <<"+ 96 Return address" << endl;
                cout << "=========================" << endl;
                cout <<"+ 100 Parmeters" << endl;
                cout << "=========================" << endl;
                cout << endl;
        }
//use cat {inputfile} | bin/c_lexer to run
        Stack *stack = new Stack();
        //cout << "In complier" << endl;
        ast->pAssem(stack);
        ast->print() ;
        //  ast->print();

        std::cout<<std::endl;

        return 0;
}
