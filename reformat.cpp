#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std; //always include

int main(int argc, char const* argv[]) {
    fstream inFile;
    ofstream outFile(argv[2]);
    inFile.open(argv[1], ios::in);
    if (inFile.is_open()){
        string line;
        while (getline(inFile, line)){
            istringstream iss(line);
            string first_name, last_name;
            int point_score;
            double factor;

            if (iss >> first_name >> last_name >> point_score >> factor){
                double output_score = point_score * factor;
                string string_val = to_string(output_score);
                string_val.erase(string_val.find_last_not_of("0") +  1, std::string::npos);
                string_val.erase(string_val.find_last_not_of(".") +  1, std::string::npos);
                string formatted_line = last_name + ", " + first_name + ": " + string_val ;
                outFile << formatted_line << endl;
            }

        }
    }
    inFile.close();
    outFile.close();
    return 0;
}
