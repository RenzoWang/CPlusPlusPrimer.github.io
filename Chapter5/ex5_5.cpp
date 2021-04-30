#include <iostream>
#include <vector>
#include <string>
using std::vector; using std::string; using std::cout; using std::endl; using std::cin;

int main()
{
    vector<string> scores = {"F","D","C","B","A","A++"};
    for(int g; cin >> g;)
    {
        string lettergrade;
        if (g < 60)
        {
            lettergrade = scores[0];
        }
        else
        {
            lettergrade = scores[(g-50)/10];
            if(g != 100)
            {
                lettergrade += g % 10 > 7 ? "+" : g%10 < 3 ? "-":"";
            }
        }
        cout << lettergrade <<endl;
    }
    return 0;
}