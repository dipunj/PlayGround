#include <stdio.h>
#include <limits.h>

// Number of matrices to be chained
#define N 4

// dimensions of matrices
// P[0] _ P[1] is the dimension of 0th matrix...so on
int P[N+1];

void printBracket(int i, int j, int B[N][N]);
void printTable(int table[N][N]);
int matrixChain(int P[]);
int ctr;

int main()
{
	int i;
	printf("Enter the dimensions of the matrices\n");
	
	for(i = 0; i <= N ; ++i)
		scanf("%d",&P[i]);
	
	printf("%d is the min no. of multiplications required\n",matrixChain(P));
}

// Iterative memoized function to compute the minimum no. of multiplications required
int matrixChain(int P[])
{
	int i,j,k,l;
	int B[N][N],table[N][N];
	int eval;

	// Level 0
	for(i = 0 ; i < N ; ++i)
		B[i][i] = table[i][i] = 0;

	// Level 1 -> N-1 
	for(l = 1 ; l < N ; ++l)
	{
		for(i = 0 ; i <= N-1-l; ++i )
		{
			j = i+l;
			table[i][j] = INT_MAX;
			for(k = i; k < j ; ++k)
			{
				eval = table[i][k] + table[k+1][j] + P[i]*P[k+1]*P[j+1];
				if(eval < table[i][j])
				{
					table[i][j] = eval;
					B[i][j] = k;
				}
			}
		}
	}

	printf("The optimal substructure is as follows :: \n");
	printTable(table);

	printf("Arrange the brackets as follows\n\t");
	printBracket(0,N-1,B);
	printf("\n");

	return table[0][N-1];
}

// Recursive function to print the brackets in the chain
void printBracket(int i, int j, int B[N][N])
{
	if( i == j )
		printf("M%d",++ctr);
	else
	{
		printf("( ");
		printBracket(i,B[i][j],B);
		printBracket(B[i][j]+1, j, B);
		printf(" )");
	}
}

// A function to print the optimal substructure
void printTable(int table[N][N])
{
	int i,j;

	printf("\n\t i->");
	for(i=0; i<N; ++i)
		printf("%5d ",i+1);
	printf("\n\t    ");
	for(i=0; i<N; ++i)
		printf("------");
	printf("\nj\t");
	for(j=N-1 ; j >= 0  ; --j)
	{
		printf("%d | ", j+1);
		for(i=0 ; i <= j ; ++i)
			printf("%5d ",table[i][j]);
		printf("\n\t");
	}
	printf("\n");
}
