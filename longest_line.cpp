#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std; //always include

int main(int argc, char const* argv[]) {
    fstream inFile;
    inFile.open(argv[1], ios::in);
    if (inFile.is_open()){
        string line;
        int largest_line = 0;
        string final_line;
        while (getline(inFile, line)){
            istringstream iss(line);
            string word;
            int word_count = 0;

            while (iss >> word){
                word_count ++;
            }
            if (word_count > largest_line){
                largest_line = word_count;
                final_line = line;
            }
        }
        cout << final_line << endl;
    }
    inFile.close();
    return 0;
}