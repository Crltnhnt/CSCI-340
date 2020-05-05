/******************************************************************************
 			CSCI 340 Assignment 1

 Progammer: Carlton Hunt
 Z-ID: 	    z1772974
 Section:   1
 TA:	    Saurabh Chitre
 Date Due: Jan 29, 2018

 Purpose: Implements the two search algorithms (linear & binary) on randomly
         generated integers stored in vectors.
 *****************************************************************************/

#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>

using std::setw;
using std::vector;
using std::endl;
using std::cout;
using std::random_shuffle;

const int DATA_SIZE = 200;
const int DATA_RANGE = 200;
const int DATA_SEED = 9;
const int SEARCH_SEED = 17;

/***************************************************************************
*********************** linear_search****************************************
 Use: finds integer stored within a vector.
 Returns: returns the position of the found element
*****************************************************************************/
int linear_search(const vector<int>& inputVec, const int x, int& comparisons)
{comparisons = 0;

    for(size_t vectorIndex=0; vectorIndex<inputVec.size(); vectorIndex++)
    {comparisons++;
       if(inputVec[vectorIndex]==x)
        {
            return vectorIndex;
        }
    }
    return -1;
}

/***************************************************************************
***********************binary_search*****************************************
 Use: searches for item in vector.
 Returns: Returns the position of the found element if search is successful.
****************************************************************************/
int binary_search(const vector<int>& inputVec, const int x, int& comparisons)
{
 int low, mid, high;
 low=0;
 high=inputVec.size() -1;
    while(low<high)
    {mid=(low + high)/2;
        if(inputVec[mid] == x)
        {
            comparisons++;
            return mid;
        }
        else if(x>inputVec[mid]){
            comparisons++;
            low=mid + 1;
        }
        else{comparisons++;
            high = mid - 1;
            }
    }
    return -1;
}

/***************************************************************
*************************print_vec*****************************
 Use: displays the contents of vec on output
 Returns: returns the output of 8 items.
***************************************************************/
void print_vec( const vector<int>& vec )
{
    const int ITEM_W = 4;
    const int NO_ITEMS = 8;
    vector<int>::const_iterator it;
    for (it=vec.begin(); it!=vec.end(); it++)
    {
        cout << setw(ITEM_W)<<*it;
        if ((it - vec.begin())%NO_ITEMS == 7)
        {
            cout << endl;
        }
    }
}

void average_comparisons(const vector<int>& inputVec, const vector<int>& searchVec, int (*search)(const vector<int>&, const int, int&) )
{
    int i, comparison = 0, sum = 0, found = 0;
    int res = 0;
    for (i = 0; i < (int)searchVec.size(); i++)
    {
        res = search( inputVec, searchVec[i], comparison );
        sum += comparison;
        if ( res >= 0 )
        {
           found++;
        }
    }
    cout << found << " numbers are found. The average number of comparisons in each search: " << (double)sum/(double)searchVec.size() << endl << endl;
}

int random_number()
{
    return rand()%DATA_RANGE + 1;
}


int main ()
{

    // -------- create unique random numbers ------------------//
    vector<int> inputVec(DATA_SIZE);
    srand(DATA_SEED);
    generate(inputVec.begin(), inputVec.end(), random_number);
    sort(inputVec.begin(), inputVec.end());
    vector<int>::iterator it = unique(inputVec.begin(), inputVec.end());
    inputVec.resize( it - inputVec.begin() );
    random_shuffle( inputVec.begin(), inputVec.end() );

    cout << "------ Data source: " << inputVec.size() << " unique random numbers ------" << endl; 
    print_vec(inputVec);
    cout << endl;

    // -------- create random numbers to be searched ---------//
    vector<int> searchVec(DATA_SIZE/2);
    srand(SEARCH_SEED);
    generate(searchVec.begin(), searchVec.end(), random_number);

    cout << "------ " << searchVec.size() << " random numbers to be searched: ------" << endl;
    print_vec(searchVec);
    cout << endl;

    cout << "Linear search: ";
    average_comparisons(inputVec, searchVec, linear_search);
    cout << "Binary search: ";
    average_comparisons(inputVec, searchVec, binary_search);

    sort(inputVec.begin(), inputVec.end());
    cout << "------- numbers in data source are now sorted ---------" << endl << endl;
    cout << "Linear search: ";
    average_comparisons(inputVec, searchVec, linear_search);
    cout << "Binary search: ";
    average_comparisons(inputVec, searchVec, binary_search);

    return 0;

}

