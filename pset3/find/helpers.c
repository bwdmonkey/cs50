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
bool search(int value, int values[], int n) {
    int min = 0;
    int max = n;
    
    while (max >= min) {
        int mid = (min+max)/2;
        if (values[mid] == value) {
            return true;
        }
        else if (values[mid] < value) {
            min = mid++;
        }
        else {
            max = mid--;
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    
    for (int k = 0; k < n; k++) {
        for (int j = k; j < n; j++) {
            if (values[j] < values[k]) {
                int holder = values[k];
                values[k] = values[j];
                values[j] = holder;
            }
        }
    }
    return;
}