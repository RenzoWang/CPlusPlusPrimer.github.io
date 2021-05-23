#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using std::vector; using std::string; using std::cin; using std::istringstream;
using std::ostringstream; using std::ifstream; using std::cerr; using std::cout; using std::endl;
using std::isdigit;

struct PersonInfo {
    string name;
    vector<string> phones;
};

bool valid(const string &nums)
{
    for(auto str : nums)
    {
        if(!isdigit(str))
            return false;
    }
    return true;
}

string format( const string& str)
{
    return str.substr(0,3) + "-" + str.substr(3,3) + "-" + str.substr(6);
}

int main()
{
    ifstream ifs("phonenumbers.txt");
    if(!ifs)
    {
        cerr << "No data ?!" <<endl;
        return -1;
    }

    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    while (getline(ifs, line))
    {
        PersonInfo info;
        record.clear();
        record.str(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }

    for (const auto &entry : people)
    {
        ostringstream formatted, badNums;
        for (const auto &nums : entry.phones)
            if (!valid(nums)) badNums << " " << nums;
            else formatted << " " << format(nums);
        if (badNums.str().empty())
            cout << entry.name << " " << formatted.str() << endl;
        else
            cerr << "input phonenumber error: " << entry.name
                 << " invalid number(s) " << badNums.str() << endl;
    }

    return 0;
}