/*
Ahmad Gonzalez
CPS 272 Machine Problem 1 Part 2

This program is used to generate random numbers and insert them into an array then
find numbers randomly within the array. This program outputs three values to demonstrate the 
efficiency of the binary search algorithm.
*/


#include "binarySearch.cpp"
#include "selectionSort.cpp"
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() 
{ 

	
	SelectionSort sortObj;//Object for sort function

	const int ARRSIZE = 50000;
	const int RANDOMVALUES = 100000, RANDOMLIMIT = 200000;
	int table[ARRSIZE];
	int sumBinSearchSuccess = 0, sumBinSearchFail = 0, success = 0;
	int i = 0;

	srand((unsigned)time(0));//Used to seed the generator from a point in the sequence that is dependent on a value that is passed as an argument which is the current time.
    //int random_integer;

    for(int index=0; index < ARRSIZE; index++)//Loop to insert random values into array.
    { 
        table[index] = (rand()%(RANDOMLIMIT-1));
 
 
        //cout << random_integer << endl; 
        //cout << "Index" << index << endl;
    } 

    //cout << sizeof(table) / sizeof(int) << endl;


    sortObj.sort(table, ARRSIZE);//Send array to sort function 

/*
   cout << "SORTED: ";
   for (i = 0; i < ARRSIZE; ++i) {
      cout << table[i] << ' ';
   }
   cout << endl;
   */


 

   for(int index=0; index < RANDOMVALUES; index++)//Loop to search for random numbers in the array
    {

        //int random_target = (rand()%(RANDOMLIMIT-1));
 
        //cout << random_target << " random target" << endl; 
        //cout << "Index" << index << endl;

        int searchItem = search(table, 0, ARRSIZE, (rand()%(RANDOMLIMIT-1)));

        //cout << searchItem << endl;

        if (searchItem < 0)
        {
        	sumBinSearchFail += -searchItem;
        	
        }
        else if (searchItem >= 0)
        {
        	success++;
        	sumBinSearchSuccess += searchItem;
        }

   

    }

    //cout << success << ": Success" << endl;
    //cout << sumBinSearchSuccess << ": sumBinSearchSuccess" << endl;
    //cout << sumBinSearchFail << ": sumBinSearchFail" << endl;


    cout << "Empirical Average Case: " << sumBinSearchSuccess / (static_cast<int>(success)) << endl;

    cout << "Empirical Worst Case: " << sumBinSearchFail / (static_cast<int>(RANDOMVALUES - success)) << endl;

    cout << "Theoretical Bound for Worse Case: " << 2.0*(1.0 + int(log(static_cast<double>(ARRSIZE))/log(2.0))) << endl;

    
    return 0;
}

