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
#include <chrono>

/*
    Inserting to vector
        Uses lower_bound to determine the correct index to insert to, by checking if value is lower than existing element
        then inserts
    Popping median
        finds median index, handles even and odd cases
        adds median to vector of medians
        erases median from list
    median vector is printed
*/
void vectorMedian(const std::vector<int> * instructions)
{
    std::vector<int> temp;

    std::vector<int> medList;


    for (auto it = instructions->begin(); it != instructions->end(); ++it){
        if (*it != -1){
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

