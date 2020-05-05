/***********************************************************
 Program:   Assignment 3
 Progammer: Carlton Hunt
 Z-ID: 	    Z1772974
 Section:   1
 TA:        Saurabh Chitre
 Date Due:  02/14/2018

 Purpose: This program utilizes the Sieve of Eratosthenes
          algorithm to print all prime numbers within a specific
          range.
**************************************************************/

#include <iostream>
#include <cmath>
#include <set>
#include <iomanip>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;
using std::setw;
using std::stoi;
using std::string;
using std::sqrt;
using std::set;

/*******************************************************************
*********************sieve of eratosthenes**************************

 Use: sieve of eratosthenes algorithim to remove all prime numbers
 Returns: No Returns
********************************************************************/
void sieve( set<int>& s, const int lower, const int upper)
{ for(int m = 2; m*m <= upper; m++)
    {
       set<int>::iterator it;
       for(it = s.begin(); it != s.end(); it++)
	 {
	    if(*it % m == 0 && m != *it)
	      {
		s.erase(it);
	      }
         }
      }
}

/******************************************************************
*************************print_primes******************************

 Use: Prints the elements in the integer set
 Returns: No Returns
 *******************************************************************/
void print_primes( const set<int>& s, const int lower, const int upper)
{
   const int ITEM_W = 4;
   const int NO_ITEMS = 6;

   set<int>::const_iterator it;

   cout << "\nThere are " << s.size() << " prime numbers between " << lower << " and " << upper << ": " << endl;

   int counter = 0;
   for(it = s.begin(); it != s.end(); it++)
      {
        cout << setw(ITEM_W) << *it;
        if(counter % NO_ITEMS == 5)
        {
          cout << endl;
        }

        counter++;
      }

}

/****************************************************************
************************run_game*********************************

 Use: This takes the input from the user and display the results
 Returns: No Returns
 ***************************************************************/
void run_game(set<int>& s)
{
    bool Begin = true;

    while(Begin)
    {
        string inputUser;
        int upper;
        int lower;

        cout <<"Please input lower bound and upper bound and hit enter (e.g. 10 100): " ;
        cin >> lower;
        cin >> upper;

        if (lower < 2)
        {
            lower = 2;
        }

        for(int i = lower; i <= upper; i++)
        {
            s.insert(i);
        }

        sieve(s, lower, upper);

        print_primes(s, lower, upper);

        cout <<"\n\nDo you want to continue or not? Please answer yes or no and hit enter: " ;
        cin >> inputUser;

        if (inputUser == "yes || YES")
        {
            Begin = true;
            s.clear();
        }
        else
        {
            Begin = false;
        }

    };
}

int main()
{
    set<int> s;
    run_game(s);
    return 0;
}
