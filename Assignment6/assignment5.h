/***********************************************************
 CSCI 340 - Assignment 6 - Spring 2018

 Progammer: Carlton Hunt
 Z-ID: Z1772974
 Section: 1
 TA: Saurabh Chitre
 Date Due: March 23, 2018
 Purpose: Implement a derived class to represent a BST.
 ************************************************************/
#ifndef ASSIGNMENT5
#define ASSIGNMENT5

class binTree;
class BST;

class Node {
    friend class binTree;
    friend class BST;

    public:
        Node(int& x, Node* l = 0, Node* r = 0)
        { data = x; left = l; right = r; }

    public:
        Node();
        int data;
        Node* left;
        Node* right;
};

class binTree {
    public:
        binTree();
        virtual void insert( int );
        unsigned height() const;
        unsigned size() const;
        void inorder( void(*)(int) );
        void preorder( void(*)(int) );
        void postorder( void(*)(int) );

    protected:
        Node* root;

    private:
        void insert( Node*&, int );
        unsigned height( Node* ) const;
        unsigned size( Node* ) const;
		void inorder( Node*, void(*)(int) );
		void preorder( Node*, void(*)(int) );
		void postorder( Node*, void(*)(int) );
};


#endif
