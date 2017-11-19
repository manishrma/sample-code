/*
 * Print the array in a diagonal format

{{ 1,  7, 12, 16, 19, 21},
 {22,  2,  8, 13, 17, 20},
 {27, 23,  3,  9, 14, 18},
 {31, 28, 24,  4, 10, 15},
 {34, 32, 29, 25,  5, 11},
 {36, 35, 33, 30, 26,  6}};
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

int main()
{
    int arr[6][6] = {{ 1,  7, 12, 16, 19, 21},
		     {22,  2,  8, 13, 17, 20},
		     {27, 23,  3,  9, 14, 18},
		     {31, 28, 24,  4, 10, 15},
		     {34, 32, 29, 25,  5, 11},
		     {36, 35, 33, 30, 26,  6}};
    int row, coln;
    int sIndex =0, eIndex=6;

    row = 0;
    coln = 0;

    // Upper half
    while(sIndex<eIndex)
    {
	while(coln < eIndex)
	{
	    printf("%d ", arr[row][coln]);
	    coln++;
	    row++;
	}
	sIndex++;
	coln = sIndex;
	row = 0;
    }
    sIndex =1;
    row = sIndex;
    coln = 0;
    //lower half
    while(sIndex < eIndex)
    {
	while(row < eIndex)
	{
	    printf("%d ", arr[row][coln]);
	    coln++;
	    row++;
	}
	sIndex++;
	coln = 0;
	row = sIndex;
    }
    printf("\n");
    return 0;
}
