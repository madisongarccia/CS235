#include <iostream>
#include <string>
#include <queue>
#include "input.h"

using namespace std;

int main(int argc, char const* argv[]) {
    priority_queue<string> PQ;
    while (true){
        string name;
        string priority;
        string operation;
        cout << "What do you want to do? ";
        getline(cin, operation);
        if (operation.empty()){
            break;
        }
        else if (operation != "add" && operation != "take"){
            cout << operation << " isn't a valid operation" << endl;
        } else{
            if (operation == "take"){
                if (!PQ.empty()){
                    cout << PQ.top() << endl;
                    PQ.pop();
                } else{
                    cout << "There are no more people in line" << endl;
                }
            } else if (operation == "add"){
                cout << "Name: ";
                getline(cin, name);
                cout << "Priority: ";
                getline(cin, priority);
                if (priority.size() < 2){
                    string combinedString = "0" + priority + " - " + name;
                    PQ.push(combinedString);
                } else{
                    string combinedString = priority + " - " + name;
                    PQ.push(combinedString);
                }
            }
        }
    }
    return 0;
}
