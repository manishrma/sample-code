/*******************************************************
 * Hacker rank problem 
 * https://www.hackerrank.com/challenges/crush/problem
 * Need to add the value k to the given index of the array
 * Then we need to print the maximum value in the list. 
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
    int n; 
    int m; 
    long long int *arr;
    long long int max_val = 0L;

    scanf("%d %d", &n, &m);
    arr = malloc ((n +1) * sizeof(long long int));
    if (arr == NULL)
    {
	printf("unable to allocate mem \n");
	return 1;
    }
    memset(arr, 0, (n +1) * sizeof(long long int));
    for(int a0 = 0; a0 < m; a0++)
    {
	int a; 
	int b; 
	int k; 
	scanf("%d %d %d", &a, &b, &k);
	arr[a-1] += k;
	if( b <= n )
	    arr[b] -= k;
    }
    long long int sum = 0L;
    for(int i = 0; i < n ; i++)
    {
	sum += arr[i];
	if (sum  > max_val)
	{
	    max_val = sum;
	}
    }
    printf("%lld", max_val);
    free(arr);
    return 0;
}


