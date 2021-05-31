/*
 * File: ex9_51.cpp
 * Project: Chapter9
 * Author: Renzo WANG (you@you.you)
 * -----
 * Modified By: Renzo WANG (you@you.you>)
 * -----
 * Brief: // Write a class that has three unsigned members representing year,
            month, and day. Write a constructor that takes a string representing
            a date. Your constructor should handle a variety of date formats,
            such as January 1, 1900, 1/1/1900, Jan 1, 1900, and so on.
 * -----
 */
#include <iostream>
#include <string>
#include <vector>

class Date
{
public:
    Date() = default;
    Date(const std::string& s)
    {
        unsigned format = 0;
        unsigned tag = 0;
        char chr = ',';
        // 1/1/1990
        if(s.find_first_of("/") != std::string::npos)
        {
            format = 0x01;
        }
        //January 1, 1990
        if( s.find_first_of(",") != std::string::npos)//(s.find_first_of(",") >= 4) &&
        {
            format = 0x10;
        }
        //jan 1 1900
        if( s.find_first_of(" ") != std::string::npos )  //s.find_first_of(" ") >=3 &&
        {
            format = 0x10;
            tag = 0x10;

        }


        switch(format)
        {
            case 0x01:
                day = stoi(s.substr(0,s.find_first_of("/")));
                month = stoi(s.substr(s.find_first_of("/") + 1, s.find_last_of("/")- s.find_first_of("/")));
                year = stoi(s.substr(s.find_last_of("/") + 1, 4));
                break;

            case 0x10:
                if(s.find("Jan") < s.size()) month = 1;
                if(s.find("Feb") < s.size()) month = 2;
                if(s.find("Mar") < s.size()) month = 3;
                if(s.find("Apr") < s.size()) month = 4;
                if(s.find("May") < s.size()) month = 5;
                if(s.find("Jun") < s.size()) month = 6;
                if(s.find("Jul") < s.size()) month = 7;
                if(s.find("Aug") < s.size()) month = 8;
                if(s.find("Sep") < s.size()) month = 9;
                if(s.find("Oct") < s.size()) month = 10;
                if(s.find("Nov") < s.size()) month = 11;
                if(s.find("Dec") < s.size()) month = 12;

                

                if(tag == 0x10) 
                    chr = ' ';

                day = stoi(s.substr(s.find_first_of("123456789"), s.find_first_of(chr) - s.find_first_of("123456789")));
                year = stoi(s.substr(s.find_last_of(" ") + 1 ,4));
                break;


        }
    }

    void print();
private:
    unsigned year, month, day;
};

void Date::print()
{
    std::cout << "day: " << day << " "<< "month: " << month << " " <<"year: "<< year <<std::endl;
}

int main()
{
    Date d("1/1/1990");
    d.print();

    return 0;
}