/*
 * File: ex9_34.cpp
 * Project: Chapter9
 * Author: Renzo WANG (you@you.you)
 * -----
 * Modified By: Renzo WANG (you@you.you>)
 * -----
 * Brief: Assuming vi is a container of ints that includes even and odd values, 
          predict the behavior of the following loop. 
          After you've analyzed this loop, write a program to test whether your expectations were correct.
			
			iter = vi.begin(); 
			while (iter != vi.end())    
				if (*iter % 2)        
					iter = vi.insert(iter, *iter);    
				++iter; 
 * -----
 */
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> data { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for(auto cur = data.begin(); cur != data.end(); ++cur)
        if(*cur & 0x1)
            cur = data.insert(cur, *cur), ++cur;
    
    for (auto i : data)
        cout << i << " ";

    return 0;
}