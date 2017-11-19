#include <stdio.h>
#include <stdlib.h>

int max_index(int *arr, int res_size)
{
    int i = 0;
    int max =0;
    int max_value = arr[0];
    int max_index;
    for (i=0; i< res_size; i++)
    {
	if (arr[i] >= max_value)
	{
	    max_index = i;
	    max_value = arr[i];
	}
    }
    return max_index;
}
int *rotate_arr(int *uArr, int u_size, int rotate)
{
    int i =0;
    int temp = uArr[0];
    for(i =0; i <u_size-2; i++)
    {
	uArr[i] = uArr[i+1];
    }
    uArr[i+1] = temp;
    return uArr;
}
int *getMaxindex(int *array, int a_size, int *rotate, int r_size, int *result_size)
{
    int i, j, rval;
    int k;
    int *uArr;
    int max_val = 0;
    int *res;

    uArr = malloc(a_size);
    res = malloc(r_size);

    for(i =0; i <r_size-1; i++)
    {
        for(i = 0; i< a_size-1; i++)
        {
   	    uArr [i] = array[i];
        }
	rval = rotate[i];
	for(j=0;j<rval;j++)
	{
	    uArr = rotate_arr(uArr, a_size, rval);
	    for(k=0;k<a_size;k++)
	    {
		printf("%d",uArr[k]);
	    }
	}

	res[i] = max_index(uArr, a_size);
    }
    for(k=0;k<a_size;k++)
    {
        printf("%d",uArr[k]);
    }
    *result_size = r_size;
    return res;
}

int main()
{
    int a_size;
    int r_size;
    int res_size;
    int *array;
    int *rarray;
    int *res;
    int i;

    scanf("%d", &a_size);
    printf("array scanning %d \n",a_size);
    array = malloc(a_size);
    if(NULL == array)
    {
	printf("error No mem\n");
        return -1;
    }
    for(i=0; i< a_size; i++)
    {
      scanf("%d", &array[i]);
    }
    for(i = 0; i< a_size; i++)
    {
        printf("array[%d,%d] \n",i, array[i]);
    }
    scanf("%d", &r_size);
    printf("rarray scanning size %d  \n", r_size);
    rarray = malloc(r_size);
    if(NULL == rarray)
    {
	printf("error No mem\n");
	free(array);
        return -1;
    }
    printf("rarray scanning size %d  \n", r_size);
    for(i=0; i< r_size; i++)
    {
      scanf("%d", &rarray[i]);
    }

    for(i = 0; i< r_size; i++)
    {
        printf("rarray[%d,%d] \n",i, rarray[i]);
    }
    res = getMaxindex(array, a_size, rarray, r_size, &res_size);

    for (i = 0; i < res_size; i++)
    {
	printf("%d", res[i]);
    }

}

