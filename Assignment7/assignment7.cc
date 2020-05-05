/******************************************************************
 CSCI 340 - Assignment 7 - Spring 2018

 Progammer: Carlton Hunt
 Z-ID: Z1772974
 Section: 1
 TA: Saurabh Chitre
 Date Due: 04/06/2018
 Purpose: This program sorts numbers using the heapsort technique.
 *****************************************************************/

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using std::endl;
using std::swap;
using std::setw;
using std::random_shuffle;
using std::vector;
using std::cout;

void build_heap ( vector < int >& v, int heap_size, bool (*compar)(int, int) );
void heapify( vector < int >& v, int heap_size, int r, bool (*compar)(int, int));
bool less_than ( int e1, int e2 );
bool greater_than ( int e1, int e2 );
void heap_sort ( vector < int >& v, int heap_size, bool (*compar)(int, int) );
int extract_heap ( vector < int >& v, int& heap_size, bool (*compar)(int, int) );
void print_vector ( vector < int >& v, int pos, int size );

const int HEAP_SIZE = 50;

int main(int argc, char** argv) {
    // ------- creating input vector --------------
    vector<int> v;
    v.push_back(-1000000);    // first element is fake
    for (int i=1; i<=HEAP_SIZE; i++)
        v.push_back( i );
    random_shuffle( v.begin()+1, v.begin()+HEAP_SIZE+1 );

    cout << "\nCurrent input numbers: " << endl;
    print_vector( v, 1, HEAP_SIZE );

    // ------- testing min heap ------------------
    cout << "\nBuilding a min heap..." << endl;
    build_heap(v, HEAP_SIZE, less_than);
    cout << "Min heap: " << endl;
    print_vector( v, 1, HEAP_SIZE );
    heap_sort( v, HEAP_SIZE, less_than);
    cout << "Heap sort result (in ascending order): " << endl;
    print_vector( v, 1, HEAP_SIZE );

    // ------- testing max heap ------------------
    cout << "\nBuilding a max heap..." << endl;
    build_heap(v, HEAP_SIZE, greater_than);
    cout << "Max heap: " << endl;
    print_vector( v, 1, HEAP_SIZE );
    heap_sort( v, HEAP_SIZE, greater_than);
    cout << "Heap sort result (in descending order): " << endl;
    print_vector( v, 1, HEAP_SIZE );

    return 0;
}

/*************************builld_heap**************************************
 Use: This function builds a heap with heap_size in the vector.
 Returns: No returns.
 **************************************************************************/
void build_heap (vector < int >& v, int heap_size, bool (*compar)(int, int))
{
    for( int i = heap_size / 2; i >= 1; i-- )
       {
           heapify(v, heap_size, i, compar);
       }
}

/***************************heapify********************************************
 Use: This function heapifies the tree at the root position.
 Returns: No returns.
 *******************************************************************************/
void heapify (vector < int >& v, int heap_size, int r, bool (*compar)(int, int))
{
    int left = 2*r;
    int right = 2*r+1;
    int largest;
    int temp;

    if( left <= heap_size && compar(v[left], v[r]))
       {
           largest = left;
       }
    else
       {
           largest = r;
       }
    if( right <= heap_size && compar(v[right], v[largest]))
       {
           largest = right;
       }
    if( largest!= r )
       {
           temp = v[r];
           v[r] = v[largest];
           v[largest] = temp;
           heapify(v, heap_size, largest, compar);
       }
}

/**************************less_than*************************************
 Use: Compares the two integers and returns true if e1 is less than e2.
 Returns: A bool(true/false).
 ***********************************************************************/
bool less_than ( int e1, int e2 )
{
    if ( e1 < e2 )
       {
           return true;
       }
    else
       {
          return false;
       }
}

/****************************greater_than***********************************
 Use: Compares two integers and returns true if e1 is greater than e2.
 Returns: A bool(true/false).
 ***************************************************************************/
bool greater_than ( int e1, int e2 )
{
    if ( e1 > e2 )
       {
           return true;
       }
    else
       {
           return false;
       }
}

/******************************heap_sort*************************************
 Use: This function implements the heap sort algorithm.
 Returns: No Returns.
 ***************************************************************************/
void heap_sort (vector < int >& v, int heap_size, bool (*compar)(int, int))
{
    int i;

    for( i = heap_size; i >= 2; i-- )
       {
           v[i] = extract_heap(v, heap_size, compar);
       }

    reverse( v.begin() + 1, v.end());
}

/**************************extract_heap*****************************************
 Use: This function takes the first value and deletes it.
 Returns: An integer value.
 *******************************************************************************/
int extract_heap ( vector < int >& v, int& heap_size, bool (*compar)(int, int) )
{
    int delete_me;

    delete_me = v[1];

    v[1] = v[heap_size];

    heap_size = heap_size -1;

    heapify( v, heap_size, 1, compar );

    return delete_me;

}

/**************************print_vector*************************************
 Use: This function prints the vector until the end.
 Returns: No Returns.
 ***************************************************************************/
void print_vector ( vector < int >& v, int pos, int size )
{
    const int ITEM_W = 5;
    const int NO_ITEMS = 8;

    vector<int>::const_iterator it;
	int counter = 0;
    for (it = v.begin() + 1; it != v.end(); it++)
       {
           cout << setw(ITEM_W) << *it;
           if (counter % NO_ITEMS == 7)
              {
                 cout << endl;
              }

        counter++;
	}

	cout << endl;

}
