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
        first 
    */

    std::vector<int> temp;

    for (int i = 0; i < instructions->size(); i++){
        auto it = std::lower_bound(instructions->begin(), instructions->end(), i);
        if (instructions->at(i) != -1){
            temp.insert(it, instructions->at(i));
        }

        int median = temp.size()/2;

        std::cout << median << " ";

        temp.erase(temp.begin() + median);
    }
}

/* Copyright 2024, Satyam Dhar */

