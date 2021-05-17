#ifndef CH5_ex7_27_h
#define CH5_ex7_27_h


#include<vector>
#include<string>
#include<iostream>

class Screen{
    public:
        
        typedef std::string::size_type pos;
        //using pos = std::string::size_type;
        Screen() = default;//1
        Screen(pos ht, pos wd): height(ht), width(wd), contents(ht*wd,' ') { } //2
        Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht*wd, c) { } //3
        
        char get() const { return contents[cursor]; }
        inline char get(pos r, pos c) const { return contents[r * width + c]; }

        Screen &move (pos r, pos c);
        inline Screen &set (char c);
        inline Screen &set(pos r, pos col, char ch);

        const Screen &display(std::ostream &os) const { do_display(os); return *this; }
        Screen &display(std::ostream &os) { do_display(os); return *this; }

    private:
        pos cursor = 0;
        pos height = 0, width = 0;
        std::string contents;

        mutable size_t access_ctr;

    private:
        void do_display(std::ostream &os) const { os << contents; }
};

inline Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen& Screen::set(pos r, pos col, char ch)
{
    contents[r*width+col] = ch;
    return *this;
} 

inline Screen& Screen::move(pos r, pos c)
{
    pos row = r*width;
    cursor = row + c;
    return *this;
}

#endif