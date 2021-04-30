#include <iostream>
#include <vector>
#include <string>
using std::vector; using std::string; using std::cout; using std::endl; using std::cin;

int main()
{
    vector<string> scores = {"F","D","C","B","A","A++"};
    for(int g=0; cin >> g;)
    {
        string lettergrade;
        lettergrade = g < 60 ?  scores[0] :  scores[(g-50)/10];
        lettergrade += (g == 100 || g < 60) ? "":  g % 10 > 7 ? "+" : g%10 < 3 ? "-":"";
        cout << lettergrade <<endl;
    }

    return 0;
}