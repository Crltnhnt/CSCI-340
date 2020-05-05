/***********************************************************
 CSCI 340 - Assignment 6 - Spring 2018

 Progammer: Carlton Hunt
 Z-ID: Z1772974
 Section: 1
 TA: Saurabh Chitre
 Date Due: March 23, 2018
 Purpose: Implements a derived class to represent a BST.
 ************************************************************/
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "assignment5.h"

using namespace std;

const int MAX_SIZE = 40;
const int MAX_COUNT = 40;
const int WIDTH = 5;
const int ROW_SIZE = 8;

int mcount = 0;
int rcount = 0;

void display(int d) {
    if ( mcount < MAX_COUNT ) {
        cout << setw(WIDTH) << d;
        mcount++;
        rcount++;
        if ( rcount == ROW_SIZE ) {
            cout << endl;
            rcount = 0;
        }
    }
}

/***************************Node*********************************
 Use: Class Constructor
 Returns: No Returns.
 ***************************************************************/
Node::Node()
{
}

/**********************binTree***********************************
 Use: Class Constructor
 Returns: No Returns.
 ***************************************************************/
binTree::binTree()
{
    root = nullptr;
}

/************************insert**********************************
 Use: Inserts a value to the root
 Returns: No Returns.
 ***************************************************************/
void binTree::insert(int val)
{
    insert(root, val);
}

/***************************height********************************
 Use: Returns a value for the height
 Returns: An integer
 ***************************************************************/
unsigned binTree::height() const
{
    return height(root);
}

/**********************size**************************************
 Use: Retreives the size of the BST
 Returns: A value for the size of the BST.
 ***************************************************************/
unsigned binTree::size() const
{
    return size(root);
}

/*************inorder*********************************************
 Use: Calls inorder
 Returns: No Return.
 ***************************************************************/
void binTree::inorder( void(* val)(int) )
{
    inorder(root, val);
}

/***************************************************************
 Use: Calls preorder
 Returns: No Returns.
 ***************************************************************/
void binTree::preorder( void(* val)(int) )
{
    preorder(root, val);
}

/*****************postorder**************************************
 Use: Calls postorder
 Returns: No Returns.
 ***************************************************************/
void binTree::postorder( void(* val)(int) )
{
    postorder(root, val);
}

/************************insert**********************************
 Use: This function is used to insert a node in the data either
      as the root, left leave or right leave.
 Returns: No Returns.
 ***************************************************************/
void binTree::insert( Node*& r, int val )
{
	if ( r == nullptr)
	{

        r = new Node;
        r->data = val;
        r->left = nullptr;
        r->right = nullptr;
	}
	else
	{
		if ( size(r->right) < size(r->left) )
		{
			insert(r->right, val);
		}
		else
		{
			insert(r->left, val);
		}
	}
}


/********************size****************************************
 Use: This function counts number of right and left nodes and
      returns the sum plus 1.
 Returns: an integer.
 ***************************************************************/
unsigned binTree::size( Node* r ) const
{
	if (r == nullptr)
	{
		return 0;
	}
	else
	{
        return 1 + size(r->left) + size(r->right);
	}
}


/******************************height*********************************
 Use: This function will return the height of the BST from the root.
 Returns: No Returns.
 ********************************************************************/
unsigned binTree::height( Node* r ) const
{
	if (r == nullptr)
	{
		return -1;
	}
	else
	{

        int leftDepth = height(r->left);
        int rightDepth = height(r->right);

        if (rightDepth < leftDepth)
        {
            return leftDepth + 1;
        }
        else
        {
            return rightDepth + 1;
        }
	}
}


/*********************inorder****************************************
 Use: This function will traverse the tree from the root.
 Returns: No Returns.
 *******************************************************************/
void binTree::inorder( Node* r, void(* p)(int) )
{
	if (r != NULL)
	{
		inorder(r->left, p);
        p(r->data);
		inorder(r->right, p);
	}
}


/*************************preorder*******************************
 Use: This function will traverse the tree recursively.
 Returns: No Returns.
 ***************************************************************/
void binTree::preorder( Node* r, void(* p)(int) )
{
	if (r != NULL)
	{
        p(r->data);
		preorder(r->left, p);
		preorder(r->right, p);
	}
}


/********************postorder***********************************
 Use: This function traverses the tree.
 Returns: No Returns.
 ***************************************************************/
void binTree::postorder( Node* r, void(* p)(int) )
{
	if (r != NULL)
	{
		postorder(r->left, p);
		postorder(r->right, p);
        p(r->data);
	}
}


#ifdef BINTREE_MAIN
int main() {
    vector<int> v(MAX_SIZE);
    for (int i=1; i<MAX_SIZE; i++)
        v[i] = i;
    random_shuffle( v.begin(), v.end() );

    binTree bt;
    vector<int>::iterator it;
    for (it=v.begin(); it!=v.end(); it++)
        bt.insert( *it );

    cout << "Height: " << bt.height() << endl;
    cout << "Size: " << bt.size() << endl;
    cout << "In order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.inorder( display );
    cout << "\n\nPre order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.preorder( display );
    cout << "\n\nPost order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.postorder( display );

    cout << endl;
    return 0;
}

#endif
