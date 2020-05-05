/****************************************************************************
CSCI 340 Spring 2018

Program:	Assignment 4
Programmer:	Carlton Hunt
Z-ID:		z1772974
Section:	1
TA:		Saurabh Chitre
Due Date:	02/22/2018

Purpose:	To implement the Queue class by using stacks.
****************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>

using std::string;
using std::cerr;
using std::cout;
using std::endl;
using std::cin;
using std::setw;

#include "assignment4.h"

/***************************************************************
**************************Empty*********************************
 Use: Checks to see if s1 and s2 are empty.
 Returns: True or False.
***************************************************************/
bool Queue::empty() const
{
    if (s1.empty() && s2.empty())
       {
        return true;
       }
    else
       {
        return false;
       }
}

/***************************************************************
**************************Size**********************************
 Use: Gives the size of s1 and s2.
 Returns: The sum of s1 and s2.
***************************************************************/
int Queue::size() const
   {
    return s1.size() + s2.size();
   }

/***************************************************************
*************************Front**********************************
 Use: Moves elements from s1 to s2.
 Returns: Returns the oldest element.
***************************************************************/
int Queue::front()
{
    if(s2.empty())
       {
        s2.swap(s1);
       }

    return s2.top();
}

/***************************************************************
*************************Back***********************************
 Use: Returns the newest element.
 Returns: Returns the top element in s1.
***************************************************************/
int Queue::back()
   {
    return s1.top();
   }

/***************************************************************
*************************Push**********************************
 Use: Pushes a new item to s1.
 Returns: No returns.
***************************************************************/
void Queue::push(const int& val)
   {
    s1.push(val);
   }

/***************************************************************
****************************Pop*********************************
 Use: Pops the oldest element.
 Returns: No returns.
***************************************************************/
void Queue::pop()
{
    if(s2.empty())
       {
        s2.swap(s1);
       }
    s2.pop();
}

int main() {
    Queue q;
    string op;
    int val = 0;

   cout << "operation -- size front end" << endl;
   cin >> op;
   while ( !cin.eof() ) {
        if ( op == "push" ) {
            cin >> val;
            q.push( val );
            cout << op << " " << val << "    -- ";
        }
        else if ( op == "pop" ) {
            q.pop();
            cout << op << "       -- ";
        }
        else {
            cerr << "Error input: " << op << endl;
            return 1;
        }
        cout << setw(3) << q.size() << setw(5) << q.front() << setw(5) << q.back();
        cin >> op;
    }

    while ( !q.empty() ){
        q.pop();}

	return 0;
}

