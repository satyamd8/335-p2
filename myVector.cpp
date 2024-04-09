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
    goes through instructions, 
        if value then push
        if -1 then return and pop median
*/
void vectorMedian(const std::vector<int> * instructions)
{
    //FIND HOW TO USE LOWER_BOUND
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

