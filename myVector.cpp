/*
Name: Satyam Dhar
Class: CSCI 335 Professor Tojeira
Title: myVector.cpp
Description: Implementation of the vectorMedian function
Date: 4/5/2024
*/

#include "myVector.hpp"
#include <iostream>
#include <cmath>

/*
    goes through instructions, 
        if value then push
        if -1 then return and pop median
*/
void vectorMedian(const std::vector<int> * instructions)
{
    //FIND HOW TO USE LOWER_BOUND
    std::vector<int> temp;

    std::vector<int> medList;

    for (auto it = instructions->begin(); it != instructions->end(); ++it){
        if (*it != -1){
            //std::cout << "push" << " ";//test

            auto insert = std::lower_bound(temp.begin(), temp.end(), *it);
            temp.insert(insert, *it);
        }
        else{
            int median;
            if (temp.size() % 2 == 0){
                median = temp.size() / 2 - 1;
            }
            else{
                median = temp.size()/2;
            }

            medList.push_back(temp[median]);
            temp.erase(temp.begin() + median);
        }
    }

    for (int i = 0; i < medList.size(); i++){
        std::cout << medList[i] << " ";
    }
    
}

/* Copyright 2024, Satyam Dhar */

