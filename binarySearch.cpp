/*
Ahmad Gonzalez@00639446
CPS 272 Machine Problem 1 Part 2
Binary search function used to find the key value in an array.
*/


#include "binarySearch.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

//Constructor
BinarySearch::BinarySearch()
{

}

//Binary Search template 
template <typename T> int search(const T arr[], int first, int last, const T& target)
{
	int mid;
	bool found = false;
	int count = 0;

	while (first <= last && !found) // Loop terminates when the key is found or at the end of the array list.
	{
    	mid = (first + last) / 2;//Calcualtes the mid point to compare.

		if (arr[mid] == target)//If the mid value is equal to the key value, end the loop and return the value and increment the count variable by one.
		{
			found = true;
			count++;
		}

		else if (arr[mid] > target)//If not found and mid value is greater, the last value is initialized to the new value less than the current mid value so in the next loop execution the left side of the array is checked.
			last = mid - 1;

		else
			first = mid + 1;//If not found and mid value is less than the key value the right side of the array is search in the next loop execution.
			count += 2; //Adds 2 to the counter because it requires two comparisons if the key value is not found.
	}
	
	if (found)
		return count;

	else
		return -count;
	
}