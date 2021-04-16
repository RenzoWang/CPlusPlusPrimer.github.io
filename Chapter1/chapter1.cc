#include <iostream>
#include "Sales_item.h"
/**
 * @brief exercise 1.2
 * shift+alt+a code blank 
 * @return int 
 */
/* int main()
{
    std::cout << "enter 2 numbers:" <<std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "Hello, world." <<std::endl;
    std::cout <<" the sum of " << v1 <<"and"<< v2 << " is " << v1+v2 <<std::endl;
    std::cout <<" The product of " << v1 <<" and " <<v2 <<" is " << v1*v2 <<std::endl;
    
    return 0;
} */

/**
 * @brief exercise 1.4
 * 
 */
int ch1_exercise_1_9(){
    std::cout << "Enter 2 numbers:" <<std::endl;
    int v1 = 0, v2 = 0, sum = 0;
    std::cin >> v1 >> v2;
    int v1_bak = v1;
    while(v1 <= v2){
        sum += v1;
        ++v1;
    }
    std::cout << "Sum of" << v1_bak <<" to " << v2 <<" is " << sum <<std::endl;
    return 0;
}

int ch1_exercise_1_10(){
    std::cout << "Enter 2 numbers:" <<std::endl;
    int v1 = 0, v2 = 0, sum = 0;
    std::cin >> v1 >> v2;
    std::cout << "Increasing Sort" << std::endl;
    while(v1 >= v2){
        std::cout << v1 << " ";
        --v1;
    }
    return 0;
}

int ch1_exercise_1_11(){
    std::cout << "Enter 2 numbers:" <<std::endl;
    int v1 = 0, v2 = 0, sum = 0;
    std::cin >> v1 >> v2;
    if(v1 > v2){
        std::cout << "Increasing Sort" << std::endl;
        while(v1 >= v2){
        std::cout << v2 << " ";
        ++v2;
        }
    }
    else if(v1 < v2){
        std::cout << "Increasing Sort" << std::endl;
        while(v2 >= v1){
        std::cout  << v1 << " ";
        ++v1;
        }

    }
    else{
        std::cout << "Equation" << v1 << v2 <<std::endl;
    }

    return 0;
}

int ch1_exercise_1_16(){
    int sum = 0, value = 0;

	while (std::cin >> value) // ctrl +z ，之后按下enter或return 作为文件结束符
	{
		sum += value;
	}

	std::cout << sum << std::endl;

	return 0;
}

int ch1_exercise_1_18(){
    
    int currVal = 0, val = 0;

	if (std::cin >> currVal)
	{
		int cnt = 1;
		while (std::cin >> val)
		{
			if (val == currVal)
			{
				++cnt;
			}
			else
			{
				std::cout << currVal << " occurs " << cnt << " times" << std::endl;
				currVal = val;
				cnt = 1;
			}
		}
		std::cout << currVal << " occurs " << cnt << " times" << std::endl;
	}
	return 0;
}
int ch1_exercise_1_19(){
    std::cout << "Enter 2 numbers:" <<std::endl;
    int v1 = 0, v2 = 0, sum = 0;
    std::cin >> v1 >> v2;
    if(v1 >v2){
        std::cout << "Descending Sort" << std::endl;
        while(v1 >= v2){
            std::cout << v1 << " ";
            --v1;
        }

    }
    else
    {
        std::cout << "Increasing Sort" << std::endl;
        while(v1 <= v2){
            std::cout << v1 << " ";
            ++v1;
        }
    }

    return 0;
}
int ch1_exercise_1_20()
{
    for(Sales_item item; std::cin >> item; std::cout << item<<std::endl);
    return 0;
}

int ch1_exercise_1_21()
{
    Sales_item item1, item2;
    std::cin >> item1 >> item2;
    if(item1.isbn() == item2.isbn())
    {
        std::cout <<item1+item2<<std::endl;
        return 0;
    }
    else{
        std::cerr <<"Not the same ISBN" <<std::endl;
        return -1;
    }
}
int ch1_exercise_1_22()
{
    Sales_item total;
    if(std::cin >> total){
        Sales_item trans;
        while(std::cin >> trans){
            if(total.isbn() == trans.isbn()){
                total += trans;
            }
            else{

                std::cout << total <<std::endl;
                total = trans;
            }
        }
        std::cout <<total<<std::endl;
    }
    else{
        std::cerr << "No data?!" <<std::endl;
        return -1;
    }
    return 0;
}

int ch1_exercise_1_23()
{
    Sales_item curritem, tranitem;
    if(std::cin >> curritem)
    {
        int count = 1;
        while(std::cin >>tranitem)
        {
            if(curritem.isbn() == tranitem.isbn())
            {
                ++count;
            }
            else{
                std::cout << "Current Book: " << curritem.isbn() << " sold " << count <<" times" <<std::endl;
                curritem = tranitem;
                count = 1;
            }
        }
        std::cout << "Current Book: " << curritem.isbn() << " sold " << count <<" times" <<std::endl;

    }
}
/*
 * Filename: d:\Development\Test code\C++primer\CPlusPlusPrimer.github.io\Chapter1\chapter1.cc
 * Path: d:\Development\Test code\C++primer\CPlusPlusPrimer.github.io\Chapter1
 * Created Date: Thursday, April 15th 2021, 5:53:52 pm
 * @Author: Renzo WANG
 * @Description: Practice for Primer
 * Copyright (c) 2021 Your Company
 */

int main(){
    //ch1_exercise_1_9();
    //ch1_exercise_1_10();
    //ch1_exercise_1_11();
    //ch1_exercise_1_16();
    //ch1_exercise_1_18();
    //ch1_exercise_1_19();
    //ch1_exercise_1_20();
    //ch1_exercise_1_21();
    ch1_exercise_1_22();
    //ch1_exercise_1_23();
    return 0;

}