#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int n, char* args[]){
    string folderPath = "A/";

    string fileAPath = folderPath + args[1];
    string fileBPath = folderPath + args[2];

    ifstream fileA(fileAPath);
    ifstream fileB(fileBPath);

    if (!fileA.is_open()) {
        cerr << "Error opening file: " << fileAPath << endl;
        return 1;
    }

    if (!fileB.is_open()) {
        cerr << "Error opening file: " << fileBPath << endl;
        return 1;
    }

    string lineA, lineB;
    while (getline(fileA, lineA) && getline(fileB, lineB)) {
        if (lineA != lineB) {
            cout << "*** file a.cpp :----   " << lineA << endl 
                 << "file b.cpp :----   " << lineB << endl;
        }
    }

    return 0;
}
