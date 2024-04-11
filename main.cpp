/*
Name: Satyam Dhar
Class: CSCI 335 Professor Tojeira
Title: main.cpp
Description: Converts input files to vector in a format readable for functions. Then passes vector to functions.
Date: 4/5/2024
*/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "myVector.hpp"
#include "myList.hpp"
#include "myHeap.hpp"
#include "myAVLtree.hpp"
using namespace std;

//CHANGE

int main(){
    string input = "input3.txt";
    ifstream fin(input);

    vector <int> instructions;

    string l;
    while (getline(fin, l)){
        istringstream word(l);
        string inst;
        int value; 

        if (word >> inst){
            if (inst == "insert"){
                if (word >> value){
                    instructions.push_back(value);
                }
            }
            else if (inst == "pop"){
                string k;
                if (word >> k && k == "median"){
                    instructions.push_back(-1);
                }
            }
        }
        
    }
    fin.close();
    vectorMedian(&instructions);
    listMedian(&instructions);
    heapMedian(&instructions);
    treeMedian(&instructions);
    cout << "done" << endl;
}
