/*
Name: Satyam Dhar
Class: CSCI 335 Professor Tojeira
Title: myVector.cpp
Description: Implementation of the vectorMedian function
Date: 4/5/2024
*/

#include "myVector.hpp"
#include <iostream>

/*
    goes through the instructions input and inserts the appropriate
    inputs while sorting with lower_bound function

    then sets appropriate median and prints each loop
*/
void vectorMedian(const std::vector<int> * instructions)
{

    //RETHINK COMPLETELY
    /*
        if != -1
            insert into vector
                using lower_bound
        else
            pop and return median
    */

    std::vector<int> temp;

    for (int i = 0; i < instructions->size(); i++){
        if (instructions->at(i) != 1){
            auto it = std::lower_bound(instructions->begin(), instructions->end(), i);
            temp.insert(it, instructions->at(i));
        }
        else{
            int median = temp.size()/2;
            std::cout << temp[median] << " ";
            temp.erase(temp.begin() + median);
        }
    }
}

/* Copyright 2024, Satyam Dhar */

