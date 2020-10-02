#include <vector>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

vector<string> lines;

bool readFile(string filename){
    ifstream file;
    char* line;

    file.open(filename.c_str());

    if(!file.is_open()){
        return false;
    }

    while (getline(file, line)) {
        lines.push_back(line);
    }

    return true;
}

int main()
{

    readFile("outputFile.txt");

    for(int i = 0; i < lines.size(); ++i){
        cout << lines[i] << endl;
    }

    return 0;
}

