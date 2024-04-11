/*
Name: Satyam Dhar
Class: CSCI 335 Professor Tojeira
Title: myHeap.cpp
Description: Implementation of the vectorMedian function
Date: 4/5/2024
*/

#include "myHeap.hpp"
#include <iostream>

/*
    Creates two heaps, max and min
    first pushes element to max heap to initialize
    
    popping median
        pushes top of max heap (median) to median vector
        pops top element (median)
        adjust max and min heap depending on thei size
    insert
        check if element in instructions is greater or less than the top element of max heap
        then inserts to the correct heap
*/

void heapMedian(const std::vector<int> * instructions)
{
    std::vector<int> medList;
    
    std::priority_queue<int> max;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min;


    for (auto it = instructions->begin(); it != instructions->end(); ++it){
        if (/*max heap is empty, size == 0*/ max.size() == 0 && *it != -1){
        //push(*it) to max heap
        max.push(*it);
        }
        else if(*it == -1){
            //push into median vector
            medList.push_back(max.top()); //weird
            //pop median from max heap
            max.pop(); //weird
            if (/*min tree > max (size)*/ min.size() > max.size()){
                auto copy = min.top();
                //pop from min, refers to copy
                min.pop();
                //push into max
                max.push(copy);
            }
        }
        else{
                if (*it > max.top()){
                    //push to min
                    min.push(*it);
                    if (min.size() > max.size()){
                        auto copy = min.top();
                        //pop form min
                        min.pop();
                        //push to max
                        max.push(copy);
                    }
                }
                else{
                    //push to max
                    max.push(*it); 
                    if (max.size() > (min.size() + 1)){
                        auto copy = max.top();
                        //pop from max
                        max.pop();
                        //push to min
                        min.push(copy);
                    }
                }
            }
    }

    for (int i = 0; i < medList.size(); i++){
        std::cout << medList[i] << " ";
    }
}

/* Copyright 2024, Satyam Dhar */