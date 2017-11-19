/*
 * Print the Maximum Sub Rectangle array in 2D array

{ 1,  2,  0, -4,  5,  6},
{ 0, -1,  0, -1,  0,  7},
{-9,  3,  7, -1,  8,  0},
{ 1,  1,  7, -1,  0,  9},
{ 7,  0, 29, -28, 0, 10},
{ 6, -5, 14, -13, 0,  1}};

Sample Output

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 ... 31
*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


#define MAX_COLN    (6)
#define MAX_ROWS    (6)

int kadane_algo(int *arr, int *start, int *finish)
{
    int curr_sum =0, max_sum =0;
    for(int i =0; i < MAX_COLN; i++)
    {
        curr_sum += arr[i];
        
        if (sum >)
    }

}
int main()
{
    int arr[MAX_ROWS][MAX_COLN] = { 1,  2,  0, -4,  5,  6},
                                  { 0, -1,  0, -1,  0,  7},
                                  {-9,  3,  7, -1,  8,  0},
                                  { 1,  1,  7, -1,  0,  9},
                                  { 7,  0, 29, -28, 0, 10},
                                  { 6, -5, 14, -13, 0,  1}};

    int sRIndex =0, eRIndex=MAX_ROWS;
    int sCIndex =0, eCIndex=MAX_COLN;
    int tLeft =0, tRight =0, bLeft =0, bRight =0; 
    int max_sum =0, curr_sum=0;
    int temp[MAX_COLN];

    /* Using the kadane's Algorithm for finding Maximum
     * rectangle sum
     */
    for(sRIndex=0; sRIndex<MAX_ROWS; sRIndex++)
    {
        int start, finish;

        /* Add the first column to the temp array */
        for(sCIndex=0; sCIndex<MAX_COLN; sCIndex++)
        {
            temp[sCIndex] += arr[sRIndex][sCindex];
        }
        curr_sum = kadane_algo(arr, &start, &finish);

        if( curr_sum > max_sum)
        {
            max_sum = curr_sum;
            tLeft = sRIndex;
            tRight = sCIndex;
            bLeft = start;
            bRight = finish;
        }
    }
    printf("\n");
    return 0;
}
