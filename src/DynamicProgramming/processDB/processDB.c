#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define NUM_FIELDS 3
struct SplitLine {
    char *fields[NUM_FIELDS];
};

/* If you wish you can include any more files here.
 *    (from standard C libraries only) 
 *       For example, do not include <conio.h>
 */
struct info
{
    int id;
    int marks;
    int subs;
    int flagged;
};
int processData(struct SplitLine array[], int len) {
    /* 
     * Modify this function to process `array` as indicated
     * in the question. At the end, return the appropriate 
     * value.
     *
     * Please create appropriate classes, and use appropriate
     * data structures as necessary.
     *
     * Do not print anything in this function.
     *
     * Note: the existing program is not intended to be an example
     * of good programming practice. (For example, struct
     * SplitLine is not a very good way to hold the data for this
     * problem.)  However, the code that *you* write will be
     * evaluated on the basis of the quality of the code, use of
     * appropriate structures, comments, and
     * efficiency of the algorithm used.
     *
     * Submit this entire program (not just this function)
     * as your answer
     */
     /* As per the initial program given we can not have more than 1024 lines
      * of DB it restrict the array here. So using an array of 1024 for faster
      * access instead of creating a list and take the sum of all the numbers
      */
    struct info student[1024] = {0};
    int total_count = 0;
    int i =0;

    // Not considering corner cases like subjects and student id's beyond 1024
    //printf("len %d \n", len);
    for(i=0; i< len; i++)
    {
	if (array[i].fields != NULL)
	{
	    int id = atoi(array[i].fields[0]);
            student[id].subs++;
	    student[id].marks += atoi(array[i].fields[2]);
	    if (student[id].subs > 6)
	    {
		printf("%d \n", student[id].subs);
	    }
            if ((student[id].marks >= 100) && !student[id].flagged)
	    {
	        total_count++;
		student[id].flagged = 1;
	    }
	    //printf(" [%d:] %d : marks %d %s \n", i, id, atoi(array[i].fields[2]), array[i].fields[1]);
	}
    }
    return total_count;
}

int main() {
    FILE *fpin, *fpout;
    struct SplitLine *array;
    char buf[1024];
    int len = 0, maxsize = 1024, i, input, retVal;
    int result;
    char *delimiters = ",\t\n";
    char *token;

    /* This part just opens the input and output files */
    if ((fpin = fopen("input.txt", "r")) == NULL) {
	fprintf(stderr, "Error opening input.txt");
	exit(-1);
    }

    if ((fpout = fopen("output.txt", "w")) == NULL) {
	fprintf(stderr, "Error opening output.txt");
	exit(-1);
    }


    /* Here we read in the input file, line-by-line */
    array = (struct SplitLine *)malloc(maxsize*sizeof(struct SplitLine));
    while(fgets(buf, sizeof(buf), fpin) != NULL) {
	/* Split each line of the input into fields
	   separated by the delimiters (comma or space)
	   and put the fields into the struct SplitLine in array */
	token = strtok(buf, delimiters);
	i = 0;
	do {
	    if (!token) {
		if (i==0) {
		    /* This is a blank line. Go to next line. */
		    break;
		} else {
		    /* Badly formatted input line. */
		    fprintf(stderr, "Bad input line");
		    exit(-1);
		}
	    }
	    array[len].fields[i++] = strdup(token);
	    token = strtok(NULL, delimiters);
	} while(i<NUM_FIELDS);
	if (i!=0)
	    len++;                    /* Ignore blank lines */
	if (len == maxsize) {       /* array is full. increase size */
	    maxsize *= 2;
	    array = (struct SplitLine *)realloc(array, 
		    maxsize*sizeof(struct SplitLine));
	}
    }
    fclose(fpin);
    retVal = processData(array, len);
    fprintf(fpout, "%d\n", retVal);
    fclose(fpout);
    for(len--; len>=0; len--)     /* free the allocated data */
	for(i=0; i<NUM_FIELDS; i++) 
	    free(array[len].fields[i]);
    return 0;
}

