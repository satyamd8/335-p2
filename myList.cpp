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
    std::list<int> tempList;
    std::vector<int> medList;

    for (auto it = instructions->begin(); it != instructions->end(); ++it) {
        if (*it != -1) {
            auto insertPos = tempList.begin();
            while (insertPos != tempList.end() && *insertPos < *it) {
                ++insertPos;
            }
            tempList.insert(insertPos, *it);
        } else {
            int median;
            if (tempList.size() % 2 == 0) {
                auto it1 = tempList.begin();
                std::advance(it1, tempList.size() / 2 - 1);
                auto it2 = it1;
                std::advance(it2, 1);
                median = (*it1 + *it2) / 2;
            } else {
                auto itMedian = tempList.begin();
                std::advance(itMedian, tempList.size() / 2);
                median = *itMedian;
            }
            medList.push_back(median);
            tempList.erase(std::next(tempList.begin(), tempList.size() / 2));
        }
    }

    for (int i = 0; i < medList.size(); i++) {
        std::cout << medList[i] << " ";
    }
}

/* Copyright 2024, Satyam Dhar */