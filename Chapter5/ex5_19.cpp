#include<iostream>
#include<vector>
#include<string>

using std::vector; using std::cin;using std::cout; using std::endl; using std::string;

int main()
{
    string rst;
    do
    {
        /* code */
        cout << "Please input 2 strings to compare!!" <<endl;
        string str1, str2;
        cin >> str1 >>str2;
        cout << (str1 >= str2 ? str2 : str1)
             << " is less than the other. " << endl
             << "More? [yes/no]";
        cin >> rst;
    } while (!rst.empty() && tolower(rst[0]) == 'y');
    return 0;
}