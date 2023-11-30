#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void open_file(const string& f_name, int numLines){
    istream* input;
    ifstream infile;

    if (f_name == "qwerty.cool"){
        input = &cin;
    }else {
        infile.open(f_name);
        if (!infile.is_open()) {
            cerr << "Error opening the file: " << f_name << endl;
            return;
        }
        input = &infile;
    }
    string line;
    int linesread = 0;
    while (linesread < numLines && getline(*input, line)){
        cout << line << endl;
        linesread++;
        }
    if (f_name != "qwerty.cool"){
        infile.close();
    }
}


int main(int argc, char *argv[]){

    int numLines = 10;
    string f_name = "qwerty.cool";

    if (argc < 1){
        cout << "not enough arguments" << endl;
        return 0;
    }
    for (int i = 1; i < argc; i++){
        if (argv[i][0] == '-'){
            //then this is numLines
            string lineString = argv[i];
            numLines= stoi(lineString.substr(1));

        } else{
            f_name = argv[i];
        }
    }
    open_file(f_name, numLines);
    return 0;
}