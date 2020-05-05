/*************************************************************
 CSCI 340 - Assignment 6 - Spring 2018

 Progammer: Carlton Hunt
 Z-ID: Z1772974
 Section: 1
 TA: Saurabh Chitre
 Date Due: March 23, 2018
 Purpose: Implements a derived class to represent a BST.
 ************************************************************/
#include <iostream>
#include "assignment5.h"
#include "assignment6.h"

using namespace std;

/**********************insert************************************
 Use: calls the insert method with a root and value
 Returns: No Returns.
 ***************************************************************/
void BST::insert( int val)
{
    insert(root, val);
}

/***************************search*******************************
 Use: Calls private search method.
 Returns: True/False
 ***************************************************************/
bool BST::search( int val)
{
    return search(root, val);
}

/*************************remove*********************************
 Use: Calls the remove method with a value.
 Returns: True/False
 ***************************************************************/
bool BST::remove( int val)
{
    return remove(root, val);
}

/********************sumLeftLeaves*******************************
 Use: sums up the left leaves from the root.
 Returns: An integer from the sum
 ***************************************************************/
int BST::sumLeftLeaves()
{
    return sumLeftLeaves(root);
}

/*******************insert***************************************
 Use: Inserts the value into BST.
 Returns: No returns.
 ***************************************************************/
void BST::insert( Node*& n, int val )
{
    if ( n == NULL )
    {
        n = new Node(val);
    }
    else if ( n->data > val )
    {
        insert( n->left, val);
    }
    else
    {
        insert( n->right, val);
    }
}

/**********************search************************************
 Use: Searches for a value
 Returns: True/False.
 ***************************************************************/
bool BST::search( Node*& n, int val )
{
    if ( n != NULL )
    {
        if ( n->data == val )
        {
            return true;
        }
        else if ( n->data > val )
        {
            return search( n->left, val );
        }
        else
        {
            return search( n->right, val);
        }
    }
    else
    {
        return false;
    }
}

/***********************remove************************************
 Use: Removes a node from the tree
 Returns: True/False
 ***************************************************************/
bool BST::remove( Node*& n, int val )
{
    Node* predecessor = n;

    if( n->data == NULL )
    {
        return false;
    }
    if ( n->data > val )
    {
        return remove(n->left, val);
    }
    if ( n->data < val )
    {
        return remove(n->right, val);
    }

    if( n->left != NULL && n->right != NULL )
    {
        predecessor = n->left;

        while( predecessor->right != NULL)
        {
            predecessor = predecessor->right;
        }

        n->data = predecessor->data;

        return remove( n->left, predecessor->data );
    }

    if( n->right == NULL )
    {
        n = n->left;
    }
    else if( n->left == NULL )
    {
        n = n->right;
    }
    else
    {
        predecessor = n->left;

        while( predecessor->right != NULL )
        {
            predecessor = predecessor->right;
        }

        predecessor->right = n->right;
        predecessor = n;
        n = n->left;
        delete predecessor;

    }

    return true;
}

/***********************isLeaf************************************
 Use: Decides if a node is a leaf.
 Returns: True/False
 ***************************************************************/
bool isLeaf( Node *n )
{
    if ( n == NULL )
    {
        return false;
    }
    else if( n->left == NULL && n->right == NULL )
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*******************sumLeftLeaves********************************
 Use: Return the sum of the left leaves from the root
 Returns: A value of the sum.
 ***************************************************************/
int BST::sumLeftLeaves( Node*& n )
{
    int sum = 0;

    if ( n != NULL )
    {

        if (isLeaf(n->left))
        {
            sum += n->left->data;
        }
        else
        {
            sum += sumLeftLeaves(n->left);
        }

        sum += sumLeftLeaves(n->right);
    }

    return sum;
}
