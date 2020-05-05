/****************************************************************************
CSCI 340 Spring 2018

Program:        Assignment 4
Programmer:     Carlton Hunt
Z-ID:           z1772974
Section:        1
TA:             Saurabh Chitre
Due Date:       02/22/2018
****************************************************************************/

#ifndef ASSIGNMENT4_H
#define ASSIGNMENT4_H
#include <stack>

class Queue {
    private:
        std::stack<int> s1, s2;
    public:
        bool empty() const;
        int size() const;
        int front();
        int back();
        void push(const int& val);
        void pop();
};

#endif
