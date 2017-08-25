#include "ast.hpp"
using namespace std;

int main()
{
    const Base *ast=parseAST();
//use cat {inputfile} | bin/c_lexer to run

    cout << "<?xml version=\"1.0\"?>" << endl;
    cout << "<Program>"<<endl;
    ast->print();
    cout << "</Program>"<<endl;
    std::cout<<std::endl;

    return 0;
}
