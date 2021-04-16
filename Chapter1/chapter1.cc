#include <iostream>

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
    while(v1 <= v2){
        sum += v1;
        ++v1;
    }
    std::cout << "Sum of" << v1 <<" to " << v2 <<" is " << sum <<std::endl;
    return 0;
}

int ch1_exercise_1_10(){
    std::cout << "Enter 2 numbers:" <<std::endl;
    int v1 = 0, v2 = 0, sum = 0;
    std::cin >> v1 >> v2;
    while(v1 >= v2){
        std::cout << "Descending Sort" << v1 << " ";
        --v1;
    }
    return 0;
}

int ch1_exercise_1_11(){
    std::cout << "Enter 2 numbers:" <<std::endl;
    int v1 = 0, v2 = 0, sum = 0;
    std::cin >> v1 >> v2;
    if(v1 > v2){
        while(v1 >= v2){
        std::cout << "Descending Sort" << v1 << " ";
        --v1;
        }
    }
    else if(v1 < v2){
        while(v2 >= v1){
        std::cout << "Increasing Sort" << v1 << " ";
        ++v1;
        }

    }
    else{
        std::cout << "Equation" << v1 << v2 <<std::endl;
    }

    return 0;
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
    ch1_exercise_1_9();
    //ch1_exercise_1_10();
    //ch1_exercise_1_11();
    return 0;

}