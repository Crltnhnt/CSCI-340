/***********************************************************
 CSCI 340 - Assignment 6 - Spring 2018

 Progammer: Carlton Hunt
 Z-ID: Z1772974
 Section: 1
 TA: Saurabh Chitre
 Date Due: March 23, 2018
 Purpose: Implement a derived class to represent a BST.
 ************************************************************/
#ifndef ASSIGNMENT6
#define ASSIGNMENT6
#include "assignment5.h"

class BST : public binTree {
    public:
        BST() : binTree() {}
        void insert( int );
        bool search( int );
        bool remove( int );
        int sumLeftLeaves();
    private:
        void insert( Node*&, int );
        bool search( Node*&, int );
        bool remove( Node*&, int );
        int sumLeftLeaves(Node*&);
};

#endif
