//  @Brief  Write a function to open a file for input and read its contents into a vector of strings, 
//          storing each line as a separate element in the vector. 

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using std::vector; using std::string; using std::ifstream; using std::cout; using std::endl;

void readFileToVec(const string& filename, vector<string>& vec)
{
    ifstream ifile(filename);
    if(ifile)
    {
        string str;
        while(std::getline(ifile, str))
            vec.push_back(str);
    }
}

int main()
{
    vector<string> vec;
    readFileToVec("test.txt", vec);
    for (const auto &str : vec) cout << str << endl;

    return 0;
}