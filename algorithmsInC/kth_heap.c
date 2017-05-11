#include <stdio.h>
#define parent(i) i/2
#define left(i) 2*i+1
#define right(i) 2*i+2
#define SIZE 5

void printArr(int A[]);
int extractMin(int arr[]);
void swap(int *a, int *b);
void minHeapify(int A[], int indx);
void getArr(int A[]);

int heapsize = SIZE - 1;

int main()
{
	int k,arr[SIZE];
	int i,ans;
	
	printf("Enter the numbers\n");
	getArr(arr);

	minHeapify(arr,0);
	
	printf("Enter the value of k\n");
	scanf("%d",&k);
	
	for (i = 0; i < k; ++i)
		printf("The %d order statistic is %d\n",i+1,extractMin(arr));
	
	return 0;
}

// Extracts the minimum i.e the root in min heap
int extractMin(int arr[])
{
	swap(&arr[0],&arr[heapsize--]);
	minHeapify(arr,0);
	return arr[heapsize+1];
}

// swaps contents of the variables pointed by a and b
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Creates the min heap
void minHeapify(int A[], int indx)
{
	int smallest = indx;
	if(left(indx) <= heapsize && A[left(indx)] < A[smallest]) 
		smallest = left(indx);
	if(right(indx) <= heapsize && A[right(indx)] < A[smallest]) 
		smallest = right(indx);

	if (smallest != indx)
	{
		swap(&A[smallest],&A[indx]);
		minHeapify(A,smallest);
	}
}

// prints the complete array which stores the heap
void printArr(int A[])
{
	int i;
	printf("\n\t");
	for (i = 0; i < SIZE; ++i)
		printf("%2d ", A[i]);
	printf("\n");
}

// gets the input from user
void getArr(int A[])
{
	int i;
	for (i = 0; i < SIZE; ++i)
		scanf("%d",&A[i]);
}