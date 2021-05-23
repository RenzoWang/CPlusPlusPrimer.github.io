//  @Brief  Rewrite the previous program to store each word in a separate element.
//  @See    ex8_04.cpp 
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
        while(ifile >> str) //从文件中读入数据类似于cin >>
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