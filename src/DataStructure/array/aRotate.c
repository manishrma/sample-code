#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    unsigned int sz, indx, i;
    unsigned int *arr;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    

    scanf("%u", &sz);
    scanf("%u", &indx);

    arr = malloc(sz * sizeof(unsigned int));
    if (arr == NULL)
    {
	printf("Unable to allocate array of size %d \n", sz);
	return 1;
    }
    for(i=0; i<sz; i++)
    {
	scanf("%u", &arr[i]);
    }
    for(i=0; i<sz; i++, indx++)
    {
	unsigned int val = (indx>=sz)?(indx%sz):indx;
	printf("%u ", arr[val]);
    }
    return 0;
}

