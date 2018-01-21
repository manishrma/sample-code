#include <math.h>
#include <stdio.h>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//using namespace std;

struct nodes
{
    int left;
    int right;
    int level;
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    struct nodes tn[1025]; // as N ranges to 1024 + 1
    int N, T, val;

    scanf("%d", &N);
    for(int i =1; i<= N; i++)
    {
	scanf("%d", &val);
	tn[1].left = val;
	scanf("%d", &val);
	tn[1].right = val;
	tn[1].level = i; //<< wrong level ??
    }
    scanf("%d", &T);
    for(int i =0; i<T; i++)
    {
	scanf("%d", &val);
	for(int j=val; j<=N; j=2*j)
	{
	    int k = 1;
	    while(k == tn[k].level )
	    {
		int temp = tn[j].left;
		tn[j].left = tn[j].right;
		tn[j].right = temp;
		k++;
	    }

	}
    }

    return 0;
}

