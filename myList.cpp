/*
Name: Satyam Dhar
Class: CSCI 335 Professor Tojeira
Title: myList.cpp
Description: Implementation of the vectorMedian function
Date: 4/5/2024
*/

#include "myList.hpp"
#include <iostream>

void listMedian(const std::vector<int> * instructions)
{
    std::list<int> temp;
    for (int i = 0; i < instructions->size(); i++){
        if (instructions->at(i) != -1){
            //CANT USE LOWER_BOUND
            //have to iterate through list
        }
        else{
            int median = temp.size()/2;
            //must traverse through list to find median
            //can use previous iteration
        }
    }
}

/* Copyright 2024, Satyam Dhar */