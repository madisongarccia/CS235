#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, char const* argv[]) {
    string f_name = "qwerty.cool";
    fstream inFile;
    set<string> theSet;
    string line;
    inFile.open(argv[1], ios::in);
    if (inFile.is_open()){
        while (!(inFile.eof())){
            getline(inFile, line);
            if (theSet.find(line) == theSet.end()){
                theSet.insert(line);
                cout << line << endl;
            }
        }
    }else{
        string input;
        getline(cin, input);
        istringstream iss(input);
        string word;
        while (getline(iss, word, '\n')){
            if (theSet.find(word) == theSet.end()) {
                            theSet.insert(word);
                            cout << word << endl;
                        }
              }
    }
    inFile.close();
    return 0;
}















