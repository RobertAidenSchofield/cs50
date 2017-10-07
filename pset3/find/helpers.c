/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
#include <stdio.h>       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool linear_search(int value, int values[], int n)
{
    for (int i = 0; i < n; i++)
        if (values[i] == value)
            return true;

    return -1;
}





bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    int min = 0;
    int max = n-1;
    
    

    while( min <= max )
    {
        int mid = (min + max)/2;
        if (values[mid] == value)
        {
            return true; 
        }
        else if (value > values[mid])
        {
            max = mid + 1;
        }
        else if (value < values[mid])
        {
            max = mid - 1;
        }
        else
        {
            break;
        }
    }

    return false ;
}


/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    // selection sort
    int temp; 
    for (int i = 0; i < n; i++)
    {
        int smallest = i;
        for(int j = i + 1; j < n; j++)
        {
            if(values[smallest] > values[j])
                smallest = j;
        }
        //swap
        temp = values[smallest];
        values[smallest] = values[i];
        values[i] = temp;
    }
    
   
}