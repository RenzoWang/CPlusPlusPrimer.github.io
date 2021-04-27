#include <iostream>
#include <vector>

using std::vector; using std::cout; using std::endl; using std::cin;

int main()
{
    vector<unsigned> scores(11,0);
    unsigned grade;
    for(;cin >> grade;)
        if (grade <= 100)
            ++ *(scores.begin() + grade / 10);
    
    for (auto s : scores)
        cout << s <<" ";
    cout <<endl;

    return 0;
}