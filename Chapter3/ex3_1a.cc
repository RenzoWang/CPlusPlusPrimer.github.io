#include<iostream>

using std::cin;
using std::cout;



int main(){
    cout << "Enter 2 numbers:" << std::endl;
    int v1 = 0, v2 = 0, sum = 0;
    cin >> v1 >> v2;
    int v1_bak = v1;
    while(v1 <= v2){
        sum += v1;
        ++v1;
    }
    cout << "Sum of" << v1_bak <<" to " << v2 <<" is " << sum <<std::endl;
    return 0;
}
