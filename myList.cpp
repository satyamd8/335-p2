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
    std::vector<int> temp;

    for (int i = 0; i < instructions->size(); i++){
        auto it = std::lower_bound(temp.begin(), temp.end(), i);
        if (instructions[i])
    }
}

/* Copyright 2024, Satyam Dhar */