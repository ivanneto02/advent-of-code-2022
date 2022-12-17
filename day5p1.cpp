#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>

using namespace std;

int getNumberOfStacks(string startState) {

    string firstLine = startState.substr(0, startState.find("\n"));

    // cout << "\"" << firstLine << "\"" << endl;

    return (firstLine.size() / 4) + 1;
}

int main() {

    ifstream inFS;

    inFS.open("./test.txt");

    if (!inFS.is_open()) { exit(1); }
    
    ostringstream outSS;

    string line;
    // get initial state
    while (!inFS.eof()) {
        getline(inFS, line);
        if (line == "") {
            break;
        }
        outSS << line << "\n";
    }

    int numberOfStacks = getNumberOfStacks(outSS.str());

    cout << numberOfStacks << endl;

    return 0;
}