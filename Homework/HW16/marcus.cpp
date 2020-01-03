#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;


class Stack {

private:
    vector<char> data;

public:
    int size() {
        return data.size();
    };

    void push(char input) {
        data.push_back(input);
    };

    bool pop(char &output) {
        if (size() > 0) {
            char temp = data[size() - 1];

            output = temp;

            data.pop_back();

            return true;
        } else {
            return false;
        }
    };

    char top() {
        return data[size() - 1];
    }

    friend ostream &operator<<(ostream &out, const Stack &s) {
        out << s;
        return out;
    }


};


int main() {
    char testChar, beginChar, endChar;
    char outPop;
    bool beginSuccess = true;
    bool endSuccess = true;
    Stack s, b;
    ifstream infile("../pascal_code.txt");
    ifstream infile2("../pascal_code.txt");
    ifstream infile3("../pascal_code.txt");

    infile3 >> beginChar;
    if (beginChar == 'b' || beginChar == 'B') {

    } else {
        beginSuccess = false;
    }

    infile3 >> beginChar;
    if (beginChar == 'e' || beginChar == 'E') {

    } else {
        beginSuccess = false;
    }

    infile3 >> beginChar;
    if (beginChar == 'g' || beginChar == 'G') {

    } else {
        beginSuccess = false;
    }

    infile3 >> beginChar;
    if (beginChar == 'i' || beginChar == 'I') {
    } else {
        beginSuccess = false;
    }
    infile3 >> beginChar;
    if (beginChar == 'n' || beginChar == 'N') {
    } else {
        beginSuccess = false;
    }

    if (beginSuccess == false) {
        cout << "Error. No Begin at beginning.";
        return 404;

    }

    int endIndex = 0;
    while (infile3 >> testChar && endSuccess == true) {
        switch (testChar) {
            case '{':
            case '(':
            case '[':
                s.push(testChar);
                endIndex = 0;
                break;
            case ')':
                if (s.top() == '(') {
                    s.pop(outPop);
                } else { cout << "Error. Extra ')'." << endl; }
                endIndex = 0;
                break;
            case '}':
                if (s.top() == '{') {
                    s.pop(outPop);
                } else { cout << "Error. Extra '}'." << endl; }
                endIndex = 0;
                break;
            case ']':
                if (s.top() == '[') {
                    s.pop(outPop);
                } else { cout << "Error. Extra ']'." << endl; }
                endIndex = 0;
                break;
            case 'e':
            case 'E':
                endIndex = 1;

                break;
            case 'n':
            case 'N':
                if (endIndex == 1) {
                    endIndex += 1;
                } else {
                    endIndex = 0;
                }
                break;
            case 'd':
            case 'D':
                if (endIndex == 2) {
                    endIndex += 1;
                    endSuccess = false;
                } else {
                    endIndex = 0;
                }
                break;
            default:
                endIndex = 0;
                break;
        }
    }


    if (endSuccess == true) {
        cout << "Error. No 'End'" << endl;
    }

    if (s.size() > 0) {
        cout << "Closing Character(s) Missing" << endl;
    }

    cout << "Ending Vector Size: " << s.size() << endl;


    return 0;
}

