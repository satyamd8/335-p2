/*
Name: Satyam Dhar
Class: CSCI 335 Professor Tojeira
Title: myAVLtree.hpp
Description: Prototype functions for AVL tree pop and push
Date: 4/5/2024
*/
#ifndef myAVLtree_hpp
#define myAVLtree_hpp

#include <vector>
#include <algorithm>
#include <chrono>

struct AvlNode{
    int element;
    AvlNode *left;
    AvlNode *right;
    int height;

    AvlNode(const int &ele, AvlNode *lt, AvlNode *rt, int h = 0)
        : element{ele}, left{lt}, right{rt}, height{h} {}

    AvlNode(int &&ele, AvlNode *lt, AvlNode *rt, int h = 0)
        : element{std::move(ele)}, left{lt}, right{rt}, height{h} {}
};

int height(AvlNode *t);
void insert(const int &x, AvlNode *&t);
void balance(AvlNode *&t);
void rotateWithLeftChild(AvlNode *&k2);
void rotateWithRightChild(AvlNode *&k2);
void doubleWithLeftChild(AvlNode *&k3);
void doubleWithRightChild(AvlNode *&k3);
void remove(const int &x, AvlNode *&t);
AvlNode *findMin(AvlNode *t);
AvlNode *findMax(AvlNode *t);


void treeMedian(const std::vector<int> * instructions){
    std::vector<int> medList;
    //max tree initialize
    AvlNode *max = nullptr;
    //min tree initialize
    AvlNode *min = nullptr;

    int maxCount = 0;
    int minCount = 0;

    for (auto it = instructions->begin(); it != instructions->end(); ++it);

#endif

/* Copyright 2024, Satyam Dhar */