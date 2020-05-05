/***********************************************************
 CSCI 340
 Assignment 2
 Progammer: Carlton Hunt

 Z-ID: Z1772974

 Section: 1

 TA: Saurabh Chitre

 Date Due: February 6, 2018

 Purpose: Implement both linear and binary search algorithms on random
 integers stored within vectors.
 ************************************************************/
#include <iostream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>

using std::setw;
using std::cout;
using std::endl;
using std::sort;
using std::rand;
using std::srand;
using std::vector;

const int DATA_SIZE = 100;
const int SEARCH_SIZE = 50;
const int DATA_SEED = 11;
const int SEARCH_SEED = 7;

/****************************************************************
******************genRndNums************************************
Use: Generates random integers within the range and stores them
      in the vector.

Returns: No Returns.
 ***************************************************************/
void genRndNums( vector<int>& v, int seed )
{
   srand(seed);

   vector<int> v1;

   vector<int>::const_iterator iter;
      for (iter = v.begin(); iter != v.end(); iter++)
         {
	      int randomIntegers = rand() % 100 + 1;
	      v1.push_back(randomIntegers);
	  }

    v.swap(v1);

}

/***************************************************************
*********************linearSearch*******************************
Use: Uses linear to search the vector while using the find() pat

Returns:True/False

 ***************************************************************/
bool linearSearch( const vector<int>& inputVec, int x)
{
   vector<int>::const_iterator iter;

      iter = find(inputVec.begin(), inputVec.end(), x);

      if (iter != inputVec.end())
         {
            return true;
          }
	   else
	 {
	    return false;
	  }
}

/***************************************************************
************** Binary Search************************************
Use: Calls the binary_search() function from STL to search for
     the item in vector.

Returns: True/False
 ***************************************************************/
bool binarySearch( const vector<int>& inputVec, int x)
{
   if(binary_search(inputVec.begin(), inputVec.end(), x))
   {
      return true;
   }
   else
   {
      return false;
   }
}

/***************************************************************
***************************Search******************************
Use: Computes the total number of successful searches.

Return: the percentage of successful searches.
 ***************************************************************/
int search( const vector<int>& inputVec, const vector<int>& searchVec,
            bool (*p)( const vector<int>&, int) )
{
   int successCounter = 0;

   vector<int>::const_iterator iter;

   for(iter = searchVec.begin(); iter != searchVec.end(); iter++)
   {
      if(p(inputVec, *iter))
      {
         successCounter += 1;
      }
      else
      {
         continue;
      }
   }

    return successCounter;
}

/***************************************************************
************************sortVector******************************
Use: sorts the elements in ascending order.

Return: No returns.
****************************************************************/
void sortVector (vector<int>& inputVec)
{
   sort(inputVec.begin(), inputVec.end());
}

/***************************************************************
************************printStat*******************************
Use: Prints the percent as floating point numbers.

Return: No returns.
****************************************************************/
void printStat (int totalSucCnt, int vec_size)
{
    float success =totalSucCnt;
    float size =vec_size;
    cout << "Success rate: " << ((success / size)* 100) << "%" << endl;
}

/***************************************************************
**************************print_vec*****************************
Use: Prints the output

Returns: No returns
 ***************************************************************/
void print_vec( const vector<int>& vec )
{
    const int NO_ITEMS = 10;
    const int ITEM_W   = 6;

    vector<int>::const_iterator iter;

    for (iter = vec.begin(); iter != vec.end(); iter++)
    {
        cout << setw(ITEM_W) << *iter;
        if ((iter - vec.begin()) % NO_ITEMS == 9)
        {
            cout << endl;
        }
    }

}

int main() {
    vector<int> inputVec(DATA_SIZE);
    vector<int> searchVec(SEARCH_SIZE);
    genRndNums(inputVec, DATA_SEED);
    genRndNums(searchVec, SEARCH_SEED);

    cout << "----- Data source: " << inputVec.size() << " randomly generated numbers ------" << endl;
    print_vec( inputVec );
    cout << "----- " << searchVec.size() << " random numbers to be searched -------" << endl;
    print_vec( searchVec );

    cout << "\nConducting linear search on unsorted data source ..." << endl;
    int linear_search_count = search( inputVec, searchVec, linearSearch );
    printStat ( linear_search_count, SEARCH_SIZE );

    cout << "\nConducting binary search on unsorted data source ..." << endl;
    int binary_search_count = search( inputVec, searchVec, binarySearch );
    printStat ( binary_search_count, SEARCH_SIZE );

    sortVector( inputVec );

    cout << "\nConducting linear search on sorted data source ..." << endl;
    linear_search_count = search( inputVec, searchVec, linearSearch );
    printStat ( linear_search_count, SEARCH_SIZE );

    cout << "\nConducting binary search on sorted data source ..." << endl;
    binary_search_count = search( inputVec, searchVec, binarySearch );
    printStat ( binary_search_count, SEARCH_SIZE );

    return 0;
}

