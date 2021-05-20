#ifndef CH5_ex7_31_h
#define CH5_ex7_31_h


class Y;

class X{
    Y *y = nullptr; // remember to initialize pointer.

};
class Y{
    X x;
};

#endif