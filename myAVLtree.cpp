/*
Name: Satyam Dhar
Class: CSCI 335 Professor Tojeira
Title: myAVLtree.cpp
Description: Implementation of the vectorMedian function
Date: 4/5/2024
*/

#include "myAVLtree.hpp"
#include <iostream>

int height(AvlNode *t) {
    return t == nullptr ? -1 : t->height;
}

void insert(const int &x, AvlNode *&t){
    if (t == nullptr)
        t = new AvlNode{x, nullptr, nullptr};
    else if (x <= t->element)
        insert(x, t->left);
    else if (t->element < x)
        insert(x, t->right);

    balance(t);
}

void balance(AvlNode *&t){
    if( t == nullptr )
        return;

    if( height( t->left ) - height( t->right ) > ALLOWED_IMBALANCE )
        if( height( t->left->left ) >= height( t->left->right ) )
            rotateWithLeftChild( t );
        else
            doubleWithLeftChild( t );
    else
    if( height( t->right ) - height( t->left ) > ALLOWED_IMBALANCE )
        if( height( t->right->right ) >= height( t->right->left ) )
            rotateWithRightChild( t );
        else
            doubleWithRightChild( t );

    t->height = max( height( t->left ), height( t->right ) ) + 1;
}

void rotateWithLeftChild(AvlNode *&k2){
    AvlNode *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
    k1->height = max( height( k1->left ), k2->height ) + 1;
    k2 = k1;
}

void rotateWithRightChild(AvlNode *&k2){
    AvlNode *k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = max( height( k2->right ), height( k2->left ) ) + 1;
    k1->height = max( height( k1->right ), k2->height ) + 1;
    k2 = k1;
}

void doubleWithLeftChild(AvlNode *&k3){
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

void doubleWithRightChild(AvlNode *&k3){
    rotateWithLeftChild(k3->right);
    rotateWithRightChild(k3);
}

void remove(const int &x, AvlNode *&t){
    if (t == nullptr)
        return; //Item not found; do nothin
    
    if(x < t->element)
        remove(x, t->left);
    else if(t->element < x)
        remove( x, t->right);
    else if(t->left != nullptr && t->right != nullptr) // Two children
    {
        t->element = findMin(t->right)->element;
        remove(t->element, t->right);
    }
    else
    {
        AvlNode *oldNode = t;
        t = (t->left != nullptr) ? t->left : t->right;
        delete oldNode;
        oldNode == nullptr; //deletes pointer
    }
    balance(t);
}

AvlNode *findMin(AvlNode *t){
    if( t == nullptr )
        return nullptr;
    if( t->left == nullptr )
        return t;
    return findMin( t->left );
}

AvlNode *findMin(AvlNode *t){
    if( t != nullptr )
        while( t->right != nullptr )
            t = t->right;
    return t;
}

void treeMedian(const std::vector<int> * instructions)
{
    std::vector<int> medList;
    //max tree initialize
    AvlNode *max = nullptr;
    //min tree initialize
    AvlNode *min = nullptr;

    int maxCount = 0;
    int minCount = 0;

    for (auto it = instructions->begin(); it != instructions->end(); ++it){
        if (/*max*/ == nullptr && *it != -1){
            //insert
            //count max += 1
        }
        else if (*it != -1){
            //pushback from leaf of max tree (right-most node of max)
            //remove
            //count max -= 1
            if (/*count min > count max*/){ //scuffed case
                //create copy of left-most node of min tree
                //remove from min tree
                //insert to max tree
                //count min -= 1
                //count max += 1
            }
        }
        else{
            if (*it <= /*right most node of max*/){
                //insert
                //count max += 1
                if (/*count max > count min + 1*/){
                    //copy the right-most node of max tree
                    //remove from max tree
                    //insert to min tree
                    //count max -=1
                    //count min += 1
                }
            }
            else if (*it > /*right-most node of max*/){ //findmax function??
                //insert TO MIN TREE
                //count min += 1
                if (/*count min > count max*/){
                    //same as popping
                    //create copy of left-most node of min tree
                    //remove from min tree
                    //insert to max tree
                    //count min -= 1
                    //count max += 1
                }
            }
        }
    }
}

/* Copyright 2024, Satyam Dhar */

