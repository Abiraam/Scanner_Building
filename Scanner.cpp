// Scanner.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
using namespace std;


bool isSubToken = false;
bool isNumber (const string& str) {
    return str.find_first_not_of("0123456789") == string::npos;
}

vector <string> checkToken(string Line) {
    vector<string> token;

    size_t spaceFound = Line.find(" ");
    if (spaceFound != 4294967295) {
        stringstream ss(Line);
        istream_iterator<string> begin(ss);
        istream_iterator<string> end;
        vector<string> extraTokens(begin, end);
        vector<string> extraToken2;
        isSubToken = true;
        string s;
        //a long way of spliting a line with multiple tokens
        for (auto &i: extraTokens) {
            extraToken2 = checkToken(i);
            s= extraToken2.back();
            token.push_back(s);
        }
        isSubToken = false;
        return token;
    }
    else {
        //this entire series of if else blocks return token types
        if (Line == "read") {
            token.push_back("read");
        }
        else if (Line == "write") {
            token.push_back("write");
        }
        else if (Line == "*") {
            token.push_back("times");
        }
        else if (Line == "+") {
            token.push_back("plus");
        }
        else if (Line == "/") {
            token.push_back("div");
        }
        else if (Line == "-") {
            token.push_back("minus");
        }
        else if (isNumber(Line)) {
            token.push_back("number");
        }
        else if (Line == "(") {
            token.push_back("lparen");
        }
        else if (Line == ")") {
            token.push_back("rparen");
        }
        else if (Line == ":=") {
            token.push_back("assign");
        }
        else {
            if (isSubToken==false) {
                token.push_back("error");
                /*this is because identifier tokens are not used on their own
                for example
                
                int sum = a + b; is valid
                
                sum; is not valid because it is not declaring nor is it writing itself*/
            }
            else {
                token.push_back("id");
            }
        }
    }

    return token;
}

vector<string> scanner(string fileName) {
    ifstream infile(fileName);  //streams file

    vector<string> tokenArray;
    vector<string> returnedTokens;
    bool isComment = false;
    string line;
    /*  Until all lines are read, the loop will read each line one by one,
        identifying tokens and placing them into the token array unless there was
        an error.*/
    while (getline(infile, line)) {
        //loop will run if the line is not a comment
        if (isComment == false) {

            size_t commentFound = line.find("/*");

            if (commentFound != 4294967295) {

                isComment = true;
                continue;
            }
            else {
                returnedTokens = checkToken(line);
                for (string i : returnedTokens) {
                    tokenArray.push_back(i);
                }
                continue;
            }
        }
        else {
            size_t commendFound = line.find("*/");
            if (commendFound != 4294967295) {
                isComment = false;
                continue;
            }
        }
    }
    return tokenArray;
}

int main()
{ 
    vector<string> tokenArray;  //holds the Tokens Identified
    string fileName;            //Holds file name

    cin >> fileName;            //inputs name of file
    
    
    tokenArray = scanner(fileName);

    if (find(tokenArray.begin(), tokenArray.end(), "error") != tokenArray.end()) {
        cout << "ERROR" << endl;
        return 0;
    }

    //print all from vector
    cout << "(";
    for (string i : tokenArray) {
        cout << i << ", ";
    }
    cout << ")" << endl;

    system("pause");
}