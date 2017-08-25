#ifndef ast_expression_hpp
#define ast_expression_hpp

#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Stack { //need to fix if greater than 32 reg reset
protected:
mutable int stackOffset; //now max 40
mutable int reg; //which register
mutable int exprVal; //value of expressions
mutable int numOperands; // num of operatnds
mutable bool Ret;
mutable int vars; // num of vars
mutable int numConst;

mutable int uniqueLabel;

mutable string funcName; //function name

mutable vector<string> ifLabel;

mutable int opCount;

mutable bool multiCond;

mutable bool funcCall;
mutable int global;
std::map < int, std::string > bindings; //use static to prevent reinitialization

mutable vector<string> returnLabel;
public:
Stack (int a = 0, int b = 0,int c =0) : stackOffset(a),reg(b),uniqueLabel(c){
}
//===================Stack stuff
void push_Stack () {

        cout << "addiu $sp, $sp, -100 #Allocate 25 bytes" << endl; //allocate 8 bytes
        cout << "sw $31,96($sp)"<<endl;
        cout << "sw $fp, 92($sp) #Old frame pointer 2 blocks down " << endl; // store prev frame poitner (4 offset
// MEM [sp + 4 ] = $fp)
        cout << "move $fp, $sp" << endl; //new frame pointer
        stackOffset =stackOffset -8;

}
//SET THE PARAMETERS DEFAULT reg
void setReg(int x){
        reg = x;
        //cout << "reg is " << reg << endl;
}
void setStackOffset(int x){
        stackOffset = x;
}
int getStackOffset(){
        return stackOffset;
}
void incdecStackOffset(int x ){
        stackOffset = stackOffset + x;
}



void incParamRegStack () const {
        reg = reg + 1;
        stackOffset = stackOffset + 4;
}
void incdecReg (int x ){
        reg = reg + x;
}
// Getter functions
int getReg(){
        return reg;
}


// Assembly instructions
void storeLoad(std::string opcode,int op1,int offset){

        cout << opcode << " $"<< op1 << ", "<< offset <<"($fp)" <<endl;
}
void storeLoad(std::string opcode,string op1,string offset){

        cout << opcode << " $"<< op1 << ", "<< offset <<endl;
}
void moveIns (std::string opcode, string op1, string op2){
        cout << opcode << " $"<<op1<<", $"<<op2<<endl;

}
void instruct(std::string opcode,int op1,int op2,int op3){

        cout << opcode << " $"<< op1 << ", " <<"$"<<op2 << ", "<<"$"<<op3 <<endl;
}
void instruct(std::string opcode,string op1,string op2,string op3){ //overloaded for string

        cout << opcode << " $"<< op1 << ", " <<"$"<<op2 << ", "<<"$"<<op3 <<endl;
}

void TrapTeq(int reg){

        cout << "teq $"<<reg <<", $0, 7" << endl;
}
void HiLoReg ( std::string hilo,int reg ){
        cout << "mf"<<hilo << " $"<<reg << endl;
}



//==============================MAP================
void bindingInsert(int reg, string var){
        bindings.insert(std::pair<int,string>(reg,var));
}
void mapOut() {
        cout << "************************Printing map***************************" << endl;
        for (std::map < int, string > ::iterator it = bindings.begin(); it != bindings.end(); ++it) {
                cout << it->first << " => " << it->second << endl;
        }
        cout << "************************Finished printing***************************" << endl;
}

bool mapLookup( string variable) {
        //do register : variable
        for (std::map < int, string > ::iterator it = bindings.begin(); it != bindings.end(); ++it) {
                if (variable == it->second) {
                        //cout << "We've found the register for : " << variable << ", it's " << it->first << endl;
                        return true; //register where it's stored

                }

        }

        return false;
}
int mapGet( string variable) {
        //do register : variable
        for (std::map < int, string > ::iterator it = bindings.begin(); it != bindings.end(); ++it) {
                if (variable == it->second) {
                        //cout << "We've found the register for : " << variable << ", it's " << it->first << endl;
                        return it->first; //register where it's stored

                }

        }
        return 0;
}

///////////////////////////Statement stuff

void setexprValue (int x) {
        exprVal = x;
}


int getexprValue (){
// how does it know when to use numbers and when to use variables?
        return exprVal;
}
//inc dec

////////////////////////Return stuff
void setReturn (bool y){
        Ret = y;
}
bool getReturn (){
        return Ret;
}

///////////////////////////////Varaible stuff

void incdecVar (int x ){
        vars = vars + x;
}
// Getter functions
int getVar(){
        return vars;
}
void setVar (int x){
        vars = x;
}
/////////////////////////const

////////////////////////////////////NUm of operands
void incdecOperands (int x ){
        numOperands =  numOperands + x;
}
// Getter functions
int getOperands(){
        return numOperands;
}
void setOperands (int x){
        numOperands = x;
}
////////////////Evaluate constant
void eval(string c,int Lval,int Rval){
        if ( c == "+") {
                setexprValue(Lval+Rval);

        }
        if ( c == "-") {
                setexprValue(Lval-Rval);

        }
        if ( c == "*") {

                setexprValue(Lval*Rval);

        }
        if ( c == "/") {
                /*
                   cout << "in div"<<endl;
                   cout << "Lval: " << Lval <<endl;
                   cout << "Rval: " << Rval <<endl;
                 */
                if(Rval != 0 ) {
                        setexprValue(Lval/Rval);
                }
        }
}

///////////////////////Label

string makeLabel(string base){
        uniqueLabel++;

        return "__"+base+"__" +std::to_string(uniqueLabel);
}
void getCurrentLabel(){
        int x = uniqueLabel;
        x--;
        cout << "__" << "base"<< "__" << x << endl;
}
void dispLabel(){
        int x = uniqueLabel;
        x--;
        cout << "__" << "base"<< "__" << x << endl;
}

/////////////////////stuff
void endFunction (string fName,Stack* stPtr) {
        cout <<endl;
        cout <<"#End function" << endl;
        stPtr->moveIns("move","sp","fp"); //get back base stack poitner
        cout << "lw $31,96($sp)"<<endl;
        stPtr->storeLoad("lw","fp","92($sp) #Load old frame pointer 2 blocks down"); //load old frame pointer 2 blocks down
        cout << "addiu $sp, $sp, 100  #Release 25 bytes from stack" <<endl;
        cout << "j $31 #Return" << endl;
        cout <<"nop #Delay slot " << endl;

        cout <<".end " << fName<<endl;
        cout << "#End function " << fName << endl;
        cout << endl;
}

void setFuncName(string s) {
        funcName=s;
}
string getFuncName() {
        return funcName;
}
///////////////opcode
void addIfVec(string x){
        ifLabel.push_back(x);
}
void clearIfVec() {
        ifLabel.clear();
}
void printIfLabel(){
//  for (unsigned int i = 0 ; i <ifLabel.size();i++){
        cout<<ifLabel[ifLabel.size()-1]<<":"<<endl;
        //}
        ifLabel.pop_back();
}
void printIfLabelAND() {
        for (unsigned int i = 0; i <ifLabel.size(); i++) {
                cout<<ifLabel[i]<<":"<<endl;
            
        }
        ifLabel.clear();
}
////////////////////////////
void setmultiCond(bool x) {
        multiCond = x;
}
bool getmultiCond() {
        return multiCond;
}
//fuction call
void setfuncCall(bool x) {
        funcCall = x;
}
bool getfuncCall() {
        return funcCall;
}
//global

void setGlobal( int x ){
  global = x;
}
int getGlobal (){
  return global;
}
void setreturnLabel( string x ){
  returnLabel.push_back(x);
}
void OutreturnLabel (){
  for (unsigned int i = 0; i <returnLabel.size(); i++) {
          cout<<returnLabel[i]<<":"<<endl;

  }
  returnLabel.clear();
}

};

class Base : public Stack
{
protected:
Base *ptr;
public:
virtual ~Base()
{
}
virtual void addList (Base*) = 0;

virtual void print() const =0;
virtual void pAssem(Stack*) const =0;



};


#endif
