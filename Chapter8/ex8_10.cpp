#include<iostream>
#include<sstream>
#include <fstream>
#include<string>
#include<vector>

using std::vector; using std::string; using std::ifstream; using std::cout; using std::endl;

void readFile(const string &filename, vector<string>& vec)
{
    ifstream in(filename);
    if(in)
    {
        string str;
        while(getline(in,str))
            vec.push_back(str);

        for(auto &line : vec)
        {
            std::istringstream iss(line);
            string word;
            while(iss >> word)
                cout << word <<endl;
        }
    }
    else
    {
        std::cerr << "No data ?!" <<endl;
    }

}

int main()
{
    vector<string> vecl;
    readFile("test.txt", vecl);

    return 0;
}