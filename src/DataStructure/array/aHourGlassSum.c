/*
 * There are 16 hour glass in 6 x 6 array
Sample Input

1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 2 4 4 0
0 0 0 2 0 0
0 0 1 2 4 0

Sample Output

19
*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int arr[6][6];
    int row, coln;
    int max_value = -1, temp;
    int flag =0;
    for(int arr_i = 0; arr_i < 6; arr_i++){
	for(int arr_j = 0; arr_j < 6; arr_j++){

	    scanf("%d",&arr[arr_i][arr_j]);
	}
    }
    for(row=0; row<4; row++)
    {
	for (coln=0;coln <4; coln++)
	{
	    temp = arr[row][coln] + arr[row][coln+1] + arr[row][coln+2] + arr[row+1][coln+1] \
		   + arr[row+2][coln] + arr[row+2][coln+1] + arr[row+2][coln+2] ;
	    if (!flag)
	    {
		max_value = temp;
		flag = 1;
	    }
	    if (temp >= max_value)
		max_value = temp;
	}
    }
    printf("%d", max_value);
    return 0;
}
