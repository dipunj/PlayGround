#include <stdio.h>
#include <stdlib.h>
#define SIZE 8

void getSet(int set[]);
void solveSet(int set[]);
void printSet(int set[],int x[],int k);
void setUtility(int curr_sum, int remain, int indx);
int comp(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

int req_sum;
int x[SIZE] = {0};
int set[SIZE];

/*
	variable refernce : 

	req_sum	  =  sum which is desired
	curr_sum  =  sum of set[i] for i:0 --> indx - 1
	remain    =  sum of set[i] for i:indx + 1 --> SIZE
	set[]     =  the set which contains the numbers
	x[]       =  boolean array to mark which elements of set[] are taken in the solution
*/

int main()
{
	getSet(set);

	printf("Enter the value of sum required\n");
	scanf("%d", &req_sum);
	
	solveSet(set);
	return 0;
}

void getSet(int set[])
{
	int i;
	printf("Enter the set :: \n");
	for(i = 0; i < SIZE ; ++i)
		scanf("%d",&set[i]);
	
	printf("The set entered by you is\n");
	printf("{  ");
	for (i = 0; i < SIZE; ++i)
			printf("%d, ", set[i]);
	printf("\b\b  }\n");

	// Necessary to sort the data in increasing order
	qsort(set, SIZE, sizeof(int), comp);
}

// Prints the set[i] for i:0-->k, if x[i] is 1
void printSet(int set[],int x[],int k)
{
	int i;
	printf("{  ");
	for (i = 0; i <= k; ++i)
		if(x[i] == 1)
			printf("%2d, ", set[i]);
	printf("\b\b  }\n");
}

// Boiler plate for setUtility() function
void solveSet(int set[])
{
	int i,rem = 0;
	for (i = 0; i < SIZE; ++i)
		rem += set[i];

	setUtility(0,rem,0);
}

// The main function which performs backtracking
void setUtility(int curr_sum, int remain, int indx)
{
	x[indx] = 1;
	if (curr_sum + set[indx] == req_sum)
		printSet(set,x,indx);
	else
	{
		// Taking set[indx]
		// Check whether next value is <= to the desired remaining amount
		if( (set[indx+1] <= req_sum-(curr_sum+set[indx]) ) && (remain >= req_sum-curr_sum) )
			setUtility( curr_sum+set[indx], remain-set[indx], indx+1);
	}

	// Not Taking set[indx]
	if((set[indx+1] <= req_sum-curr_sum) && (remain-set[indx] >= req_sum-curr_sum))
	{
		x[indx] = 0;
		setUtility(curr_sum, remain - set[indx], indx+1);
	}
}
