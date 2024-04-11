/*
Name: Satyam Dhar
Class: CSCI 335 Professor Tojeira
Title: myList.cpp
Description: Implementation of the vectorMedian function
Date: 4/5/2024
*/

#include "myList.hpp"
#include <iostream>


/*
    Inserting to list
        First iterates through list to find propert insert position based on least to greatest
        then inserts
    Popping median
        finds median index, handles even and odd cases
        adds median to vector of medians
        erases median from list
    median vector is printed
*/
void listMedian(const std::vector<int> * instructions) 
{
    std::list<int> tempList;
    std::vector<int> medList;

    for (auto it = instructions->begin(); it != instructions->end(); ++it) {
        if (*it != -1) { //can change to for loop
            auto insertPos = tempList.begin();
            while (insertPos != tempList.end() && *insertPos < *it) {
                ++insertPos;
            }
            tempList.insert(insertPos, *it);
        } else {
            int median;
            auto medianFind = tempList.begin();
            if (tempList.size() % 2 == 0) {
                std::advance(medianFind, tempList.size() / 2 - 1);
                medList.push_back(*medianFind);
                tempList.erase(std::next(tempList.begin(), tempList.size() / 2 - 1));
            } else {
                std::advance(medianFind, tempList.size() / 2);
                medList.push_back(*medianFind);
                tempList.erase(std::next(tempList.begin(), tempList.size() / 2));
            }
        }
    }


    for (int i = 0; i < medList.size(); i++) {
        std::cout << medList[i] << " ";
    }
}

/* Copyright 2024, Satyam Dhar */