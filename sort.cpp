#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void insertSort(vector<string>& array, int size){
    //if our array is one element, then it is sorted
    if (size <= 1){
        return;
    }

    insertSort(array, size - 1);

    string lastVal = array[size-1];
    int j = size - 2;

    while (j >= 0 && array[j].compare(lastVal) > 0){
        array[j + 1] = array[j];
        j--;
    }
    array[j+1] = lastVal;

}

int main(int argc, char const* argv[]) {
    ifstream file(argv[1]);
    vector<string> lines;
    string line;
    if (file.is_open()){
        while (getline(file, line)){
            lines.push_back(line);
        }
        file.close();
    } else{
        string info;
        while (getline(cin, line)){
            if (line == ""){
                break;
            }
            lines.push_back(line);
        }
    }
    insertSort(lines, lines.size());
    for (int i = 0; i < lines.size(); i++){
        cout << lines[i] <<endl;
    }
    return 0;
}
