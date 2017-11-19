/* Gives the increasing and decreasing 
 * index in an array
 * This program takes the commandline arguments 
 * ./aIncreasingDecreasingIndex 11 10 9 8 7 6 12 13 14 15 16 17
 * value = 12
 */
   
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    int arr[256];
    int i=0;
    int len = 0;
    int max = 0;

    for(i=0; i< argc-1; i++)
    {
	arr[i] = atoi(argv[i+1]);
        printf("%d \n", arr[i]);
    }
    len = i;
    printf("len %d \n", len);


    max = arr[0];
    for(i =1; i<len; i++)
    {
	if (max < arr[i])
	{
	    max = arr[i];
	    break;
	}
    }
    printf("value %d\n",max);
    return 0;
}
