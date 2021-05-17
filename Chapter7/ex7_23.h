#ifndef CH5_ex7_23_h
#define CH5_ex7_23_h


#include<vector>
#include<string>

class Screen{
    public:
        
        typedef std::string::size_type pos;
        //using pos = std::string::size_type;
        Screen() = default;

        Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht*wd, c) { }
        
        char get() const { return contents[cursor]; }
        inline char get(pos r, pos c) const { return contents[r * width + c]; }
    private:
        pos cursor = 0;
        pos height = 0, width = 0;
        std::string contents;

        mutable size_t access_ctr;
};



#endif