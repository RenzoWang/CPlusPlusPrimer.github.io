#include<iostream>

using std::cout; using std::endl;

class _intAdd{
    public:
        int i_int;
        _intAdd(const int&  a)
        {
            i_int = a;
        }
        _intAdd operator ++(int)
        {
            _intAdd m((*this).i_int);
            ++i_int;
            return m;
        }
};

_intAdd &operator++(_intAdd& i)
{
    ++i.i_int;
    return i;
}

std::ostream &operator<<(std::ostream &io, const _intAdd &i)
{
    std::cout << i.i_int;
    return io;
}

int main()
{
    const int  i = 5;
    _intAdd a(i);
    cout << a <<endl;
    cout << a++ <<endl;
    cout << "value "<<a << endl;
    cout << ++a <<endl;

    cout << "value "<<a << endl;

}