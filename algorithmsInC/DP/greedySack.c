#include <stdio.h>

#define max(a,b) (a>b)?a:b

void getSack(int W[], int P[], int n);
int GreedySack(int n, int max, int W[], int P[]);

int main()
{
	int max_weight,n;
	printf("Enter n::\n");
	scanf("%d",&n);
	printf("Enter maximum capacity of KnapSack\n");
	scanf("%d",&max_weight);

	int W[n],P[n];
	getSack(W,P,n);
	printf("%d is the max value",GreedySack(n,max_weight,W,P));
}

void getSack(int W[], int P[], int n)
{
	int i;
	for (i = 0; i < n; ++i)
	{
		printf("Enter details of %d item\n",i+1);
		printf("Weight :: ");
		scanf("%d", &W[i]);
		printf("Profit :: ");
		scanf("%d", &P[i]);
	}
}

int GreedySack(int n, int max, int W[], int P[])
{
	if( max == 0 || n == 0)
		return 0;
	if(W[n-1] > max)
		return GreedySack(n-1, max, W, P);
	else
		return max(P[n-1] + GreedySack(n-1, max - W[n-1], W, P), GreedySack(n-1, max, W, P));
}