#include <iostream>
using std::cout; using std::endl; using std::begin; using std::end;

void print(const int* pi)
{
    if(pi)
        cout << *pi <<endl;
}

void print(const int (&arr)[2])
{
    for (auto i:arr)
        cout << i <<endl;
}

void print(const char *cp)
{
    if(cp)
        while(*cp)
            cout << *cp++ <<endl; 
}

void print(const int* beg, const int* end)
{
    while(beg != end)
        cout << *beg++ <<endl;
}

void print(const int arr[], size_t size)
{
    for(int i = 0; i < size; ++i)
    {
        cout << arr[i] <<endl;
    }
}

int main()
{
    int i = 0, j[2] = {0,1};
    char ch[5] = "test";    // c-style string end by '\0'
    cout << "====print int======="<<endl;
    print(&i);
    cout << "====print array======"<<endl;
    print(j);
    cout << "====print char array==========="<<endl;
    print(ch);
    cout << "====print array======"<<endl;
    print(begin(j),end(j));
    cout << "====print array======"<<endl;
    print(j,end(j)-begin(j));
    

    return 0;

}