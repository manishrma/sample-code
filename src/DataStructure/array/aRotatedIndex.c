/*
 * This problem was given to me in an interview techincal round with MapR and
 * i was failed to complete it thus the journey starts for solving the different
 * problems.
 *
 * Problem:-
 * There is an int array int *arr with size a_size and second array int *rotate
 * of size r_size. The task was to rotate the array 1 with the value in the rotate
 * array and then create a new array with the list of indexes of the highest value
 * number in the array 1.
 *
 * if arr = [3, 5, 6, 8, 10] and rotate = [3, 4, 0, 6]
 *
 * then we have to rotate the arr with rotate[0] = 3 first thus it will be 
 * [5, 6, 8, 10, 3]
 * [6, 8, 10, 3, 5]
 * [8, 10, 3, 5, 6]
 *     ^
 *
 * so now we need to create and array res[0] = 1 i.e index of the highest value int.
 *
 * The problem was actually not explaned there as it is. It was made very complicated 
 * so you need to practice reading first and then put the logic. you will be short 
 * of time so you try to put raw logic but that wont work usually.
 * so practice and practice.
 */

#include <stdio.h>
#include <malloc.h>

int *getMaxIndexArray(int *arr, int a_size, int *rotate, int r_size, int *res_size)
{
    int i = 0;
    int max_val = arr[0];
    int max_index = 0;
    int shift =0;
    int *res;

    *res_size = r_size;
    res = malloc(r_size);
    if (NULL == res)
    {
	printf("Unable to allocate mem %d \n", r_size);
	return NULL;
    }

    // get the index of the biggest integer

    for (i=1; i <a_size; i++)
    {
	if (arr[i] > max_val)
	{
	    max_val = arr[i];
	    max_index = i;
	}
    }
    printf("maximum index is at %d \n", max_index);

    for (i=0; i<r_size; i++)
    {
	shift = rotate[i] % a_size;
	res[i] = (shift <= max_index) ? (max_index - shift): (a_size - (shift - max_index));
        if (shift < 0)
	    res[i] %= a_size;
    }
    return res;

}
int main ()
{
    int *arr, *rotate, *res;
    int val;
    int a_size, r_size, res_size;

    printf("Enter the size of the array1 =");
    scanf("%d",&a_size);

    arr = malloc(a_size * sizeof(int));
    if (NULL == arr)
    {
	printf("Unable to allocate arr of size %d \n", a_size);
	return -1;
    }
    printf("Enter the number followed by and enter\n");
    for (val=0; val<a_size; val++)
    {
	scanf("%d", &arr[val]);
    }


    printf("Enter the size of the rotate element array =");
    scanf("%d",&r_size);
    rotate = malloc(r_size * sizeof(int));
    if (NULL == rotate)
    {
	printf("Unable to allocate rotate of size %d \n", r_size);
	return -1;
    }
    printf("Enter the number followed by and enter\n");
    for (val=0; val<r_size; val++)
    {
	scanf("%d", &rotate[val]);
    }

    res = getMaxIndexArray(arr, a_size, rotate, r_size, &res_size);
    if (NULL != res)
    {
	printf("res = [");
	for (val=0; val<res_size; val++)
	{
	    printf("%d, ",res[val]);
	}
	printf("]\n");
    }

    free(arr);
    free(rotate);
    free(res);

}
