// PROVIDE N, CAP USING COMMAND LINE
// EG. 
// gcc knapSack.c -D N=3 -D CAP=5

#include <stdio.h> 	
#define max(a,b) (a>b)?a:b

void printObjects(int, int );
void printBenefit(int T[N+1][CAP+1]);
int knapSack(int W[], int P[]);
void getSack(int W[], int P[]);

int T[N+1][CAP+1];
int B[N+1][CAP+1];
int W[N],P[N];

int main()
{
	getSack(W,P);
	printf("%d is the max value",knapSack(W,P));
}

int knapSack(int W[N], int P[N])
{
	int i,j,a,b;
	for (i = 0; i <= N; ++i)
	{
		for (j = 0; j <= CAP; ++j)
		{
			if(i == 0 || j == 0)
				T[i][j] = 0;
			else
			{
				if(W[i-1] <= j)
				{
					a = P[i-1] + T[i-1][j-W[i-1]];
					b = T[i-1][j];
					T[i][j] = max(a, b);
					if (a > b)
						B[i][j] = 1;
					else
						B[i][j] = 0;
				}
				else
					T[i][j] = T[i-1][j];
			}
		}
	}
	printf("Following is the benefit matrix \n\t     ");
	printBenefit(T);
	printf("Following is the marker matrix \n\t     ");
	printBenefit(B);

	printf("Choose the following objects to get maximum benfit ::\n");
	printObjects(N,CAP);

	return T[N][CAP];
}
void printObjects(int n, int cap)
{
	if(n == 0 || cap == 0)
		return;
	else
	{
		if(B[n][cap] == 1)
		{
			// Object was chosen
			printf("object :: %d\n\tweight :: %d\n\tprofit :: %d\n",n,W[n-1],P[n-1]);
			printObjects(n-1,cap-W[n-1]);
		}
		else
			printObjects(n-1,cap);
	}
}
void printBenefit(int T[N+1][CAP+1])
{
	int i,j;
	for (j = 0; j < CAP+1; ++j)
		printf("%4d",j);
	printf("\n\t------");
	
	for (int i = 0; i < CAP+1; ++i)
		printf("----");
	for (int i = 0; i < N+1; ++i)
	{
		printf("\n\t %2d |",i);
		for (j = 0; j < CAP+1 ; ++j)
			printf("%4d",T[i][j]);
	}
	printf("\n");
}

void getSack(int W[], int P[])
{
	int i;
	for (i = 0; i < N; ++i)
	{
		printf("Enter details of %d item\n",i+1);

		printf("Weight :: ");
		scanf("%d", &W[i]);
		
		printf("Profit :: ");
		scanf("%d", &P[i]);
	}
}
