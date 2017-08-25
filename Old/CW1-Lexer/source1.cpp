#include "lex.hpp"
#include <cassert>
#include <iostream>
#include <vector>
#include <sstream>
#include <regex>
#include <iterator>
using namespace std;

TokenValue yylval;

string JFormat (vector<string> items){


  stringstream ss;
  ss<< "[";

  for (unsigned int i = 0 ; i < items.size();i++){
    ss<< items[i] << ", ";
  }

  ss << "{}";
  ss << "]";

  return ss.str();//

}


string eachJformat (string CLASS, string TEXT, int lineno,int colno,int sourceno ,string FILENAME){

  stringstream ss;

  ss << "{ \"Class\":" << "\"" <<  CLASS << "\",";
  ss  << "\t\"Text\":" << "\"" <<  TEXT<< "\",";
  ss  << "\t\"StreamLine\":" <<  lineno<< ",";
  ss  << "\t\"SourceLine\":"  <<  sourceno<< ",";
  ss  << "\t\"SourceCol\":" <<  colno<< ",";
  ss  << "\t\"SourceFile\":" << "\"" <<  FILENAME<< "\" }";

  return ss.str();

}

void vecOut(vector<string> a){
  for (unsigned int i = 0 ; i < a.size();i++)
  cout<<a[i]<<endl;


}

void eraseQuotes(string &temp){
//  cout << "TEMP is eraseQuotes" << temp << endl;
  if (temp == "\"\""){
    temp ="";
  }
  else {

    if (temp.at(0)== '\"'){
      temp.erase(temp.begin());
    }
    if (temp.back()== '\"'){
      temp.erase(temp.end()-1);
    }
    if (temp.at(0)== '\''){
      temp.erase(temp.begin());
    }
    if (temp.back()== '\''){
      temp.erase(temp.end()-1);
    }

  }
}

int main (){

//streamlien increase for each line in the pre processed filename
//Sourceline increases by one excluding lines that have #
  vector <string> tokensVec;
string filename = "";
string sNum;//source line of file
while (1) {

  string temp;
  TokenType type = (TokenType) yylex(); //can be either none, number or word

  if (type == None) {

    break; // No more tokens
  } else if (type == Hash) {

    //here we get the hash, and split up the file into string and line number

    regex stringLiteral("\"(.)*\"");
    regex digit("[0-9]+");
    const string s = *yylval.wordValue;


    std::smatch match;

    if (std::regex_search(s.begin(), s.end(), match, stringLiteral)){

      //  std::cout << "match: " << match[0] << '\n';
        filename = match[0].str();
        eraseQuotes(filename);
        //cout << "FILENAME :" << filename << endl;

}

if (std::regex_search(s.begin(), s.end(), match, digit)){

  //  std::cout << "match: " << match[0] << '\n';
    sNum = match[0].str();
    sourceno = stoi(sNum);
  //  cout << "sourcenum number :" << sourceno<< endl;
sourceno = sourceno -1; //fix offset
}



  //  cout << "Hash is " << temp << endl;
    //tokensVec.push_back(eachJformat("Invalid",temp,lineno,colno,sourceno,filename));



    delete yylval.wordValue;

  } else if (type == Invalid) {


    temp = *yylval.wordValue;

    tokensVec.push_back(eachJformat("Invalid",temp,lineno,colno,sourceno,filename));



    delete yylval.wordValue;


} else if (type == Keyword) {


  temp = *yylval.wordValue;

  tokensVec.push_back(eachJformat("Keyword",temp,lineno,colno,sourceno,filename));



  delete yylval.wordValue;


} else if (type == Identifier) {
  temp = *yylval.wordValue;
  tokensVec.push_back(eachJformat("Identifier",temp,lineno,colno,sourceno,filename));
  delete yylval.wordValue;

} else if (type == Operator) {
  temp = *yylval.wordValue;
  tokensVec.push_back(eachJformat("Operator",temp,lineno,colno,sourceno,filename));
  delete yylval.wordValue;

} else if (type == Constant) {
  temp = *yylval.wordValue;

  eraseQuotes(temp);
  //remove ' from char'



  tokensVec.push_back(eachJformat("Constant",temp,lineno,colno,sourceno,filename));

  delete yylval.wordValue;

} else if (type == Stringliteral) {
  temp = *yylval.wordValue;
   eraseQuotes(temp);
  //remove " from string"

  tokensVec.push_back(eachJformat("StringLiteral",temp,lineno,colno,sourceno,filename));
  delete yylval.wordValue;
} else {
  assert(0); // There are only three token types.


  return 1;
}



}


vecOut(tokensVec);


//cout << JFormat(tokensVec) << endl;
return 0;




}
