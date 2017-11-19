/* Remove Duplicate 
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <inttypes.h>

int main() {

    char *arr = NULL;
    char *dup = NULL;
    uint32_t len, i, j, k;
    
    printf("Enter the length:");
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    scanf("%" SCNu32, &len);
    arr = malloc(len * sizeof(char));
    if (arr == NULL)
    {
	printf("Failed to allocate array \n");
	return 1;
    }
    scanf("%s", arr);
    printf("Input array %s \n", arr);

    for(i=1; i< len; i++)
    {
	for(j=0; j<i; j++)
	{
	    if (arr[j] == arr[i])
	    {
		for (k=i; k< len; k++)
		{
		    arr[k] = arr[k+1];
		}
		arr[k] = '\0';
		len--;
	    }
	}
    }
    printf("output array = %s \n", arr);
    if (arr)
	free(arr);
    return 0;
}

