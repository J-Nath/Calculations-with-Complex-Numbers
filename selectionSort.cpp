/*
Ahmad Gonzalez
CPS 272 Machine Problem 1 Part 2
Selection sort function used to set the integers in an array in ascending order.
*/


#include "selectionSort.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

SelectionSort::SelectionSort()//Constructor
{
	
}

void SelectionSort::sort(int numbers[], int numbersSize)//Sort function to sort an array in ascending order
{
   int i = 0;
   int j = 0;
   int indexSmallest = 0;
   int temp = 0;  // Temporary variable for swap
   
   for (i = 0; i < numbersSize - 1; ++i)
   {
      
      // Find index of smallest remaining element
      indexSmallest = i;
      for (j = i + 1; j < numbersSize; ++j)
      {
         
         if ( numbers[j] < numbers[indexSmallest] )
         {
            indexSmallest = j;
         }
      }
      
      // Swap numbers[i] and numbers[indexSmallest]
      temp = numbers[i];
      numbers[i] = numbers[indexSmallest];
      numbers[indexSmallest] = temp;
   }
}