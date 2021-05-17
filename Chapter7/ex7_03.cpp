#include "ex7_02.h"
#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
    Sales_data total;
    Sales_data trans;
    if(cin >> total.bookNo >> total.units_sold >> total.revenue)
    {
        while(cin >> trans.bookNo >> trans.units_sold >> trans.revenue)
        {
            if (total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                cout << total.bookNo <<" " << total.units_sold << " " << total.revenue <<endl;
                total = trans;
            }
        }
        cout << total.bookNo <<" " << total.units_sold << " " << total.revenue <<endl;

    }
    else{
        std::cerr << " NO DATA?!" <<endl;
        return -1;
    }
    return 0;
}
