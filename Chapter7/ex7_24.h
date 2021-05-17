#ifndef CH5_ex7_24_h
#define CH5_ex7_24_h


#include<vector>
#include<string>

class Screen{
    public:
        
        typedef std::string::size_type pos;
        //using pos = std::string::size_type;
        Screen() = default;//1
        Screen(pos ht, pos wd): height(ht), width(wd), contents(ht*wd,' ') { } //2
        Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht*wd, c) { } //3
        
        char get() const { return contents[cursor]; }
        inline char get(pos r, pos c) const { return contents[r * width + c]; }
    private:
        pos cursor = 0;
        pos height = 0, width = 0;
        std::string contents;

        mutable size_t access_ctr;
};



#endif