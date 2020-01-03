#include <iostream>
#include <fstream>
#include "Stack.h"


int main() {
    using namespace std;

    ifstream infile("../pascal_code.txt");
    ifstream infile2("../pascal_code.txt");

    Stack s = Stack();


    char c;
    char endChar;


    string str;
    string begin = "begin";
    string end = "end";

    bool checkForBegin = true;
    bool checkForEnd = false;

    if (infile >> c && checkForBegin) {
        if (!(c == 'B' || c == 'b')) {
            checkForBegin = false;
        }
    }

    if (infile >> c && checkForBegin) {
        if (!(c == 'E'|| c == 'e')) {
            checkForBegin = false;
        }
    }

    if (infile >> c && checkForBegin) {
        if (!(c == 'G'|| c == 'g')) {
            checkForBegin = false;
        }
    }

    if (infile >> c && checkForBegin) {
        if (!(c == 'I'|| c == 'i')) {
            checkForBegin = false;
        }
    }

    if (infile >> c && checkForBegin) {
        if (!(c == 'N'|| c == 'n')) {
            checkForBegin = false;
        }
    }

    bool curveBracket = true;
    bool squareBracket = true;
    bool squigglyBracket = true;


    if (!checkForBegin) {
        cout << "\"Begin\" is not in the code" << endl;
    } else {

        while (infile >> c) {
            if (c == '{' || c == '[' || c == '(')
                s.push(c);
            else if (c == ']') {
                if (s.top() == '[') {
                    s.pop();
                } else {
                    cout << "Imbalance detected with ]" << endl;
                }
            } else if (c == '}') {
                if (s.top() == '{') {
                    s.pop();
                } else {
                    cout << "Imbalance detected with }" << endl;
                }
            } else if (c == ')') {
                if (s.top() == '(') {
                    s.pop();
                } else {
                    cout << "Imbalance detected with )" << endl;
                }
            }

            infile2 >> endChar;
            if (endChar == 'E' || endChar == 'e') {
                infile2 >> endChar;
                if (endChar == 'N' || endChar == 'n') {
                    infile2 >> endChar;
                    if (endChar == 'D' || endChar == 'd') {
                        checkForEnd = true;
                    }
                }
            }
        }
    }


    if (!checkForEnd) {
        cout << "There is no \"End\" in the file." << endl;
    } else {
        if (s.size() == 0) {
            cout << "File contains an balanced expression." << endl;
        } else {
            cout << "File contains a unbalanced expression." << endl;
        }
    }


    return 0;

}