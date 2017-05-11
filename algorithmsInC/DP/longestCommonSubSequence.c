#include <stdio.h>
#include <string.h>

#define max(a,b) (a>b)?a:b

#define D_NULL 0
#define D_UP 1
#define D_LEFT 2
#define D_DIAGONAL 3

#define SIZE 100
int la,lb,b_flag[SIZE]={0};		// la - length of a, lb - length of b
char a[SIZE];
char b[SIZE];


int solveLCS(char a[], char b[]);
void printLCS(int i, int j, int dir[lb][la]);
void printStruct(int arr[lb][la]);

int main()
{
	printf("Enter the first string\n");
	scanf("%s",a);

	printf("Enter the second string\n");
	scanf("%s",b);

	la = strlen(a);
	lb = strlen(b);
	printf("Length of LCS is :: %d",solveLCS(a,b));
}

// Function implements dynamic programming paradigm to fill the optimal substructure.
int solveLCS(char a[], char b[])
{
	int opStruct[lb+1][la+1];	// Optimal substructure
	int dir[lb+1][la+1];		// Direction matrix
	
	int i,j;
	for (i = 0; i < lb+1; ++i)
	{
		for (j = 0; j < la+1; ++j)
		{
			// if either of the string is empty
			if(i == 0 || j == 0)
			{
				opStruct[i][j] = 0;
				dir[i][j] = D_NULL;
			}
			else
			{
				// if character of strings match
				if(a[j-1] == b[i-1])
				{
					opStruct[i][j] = opStruct[i-1][j-1] + 1;
					dir[i][j] = D_DIAGONAL;
				}
				else
				{
					// use maximum of earlier values :: opStruct[i-1][j] or opStruct[i][j-1]
					if (opStruct[i-1][j] >= opStruct[i][j-1])
					{
						opStruct[i][j] = opStruct[i-1][j];
						dir[i][j] = D_UP;
					}
					else
					{
						opStruct[i][j] = opStruct[i][j-1];
						dir[i][j] = D_LEFT;
					}
				}
			}
		}
	}


	printf("\nThe optimal substructure is :: \n");
	printStruct(opStruct);

	printf("\n\nThe direction matrix is (0 - NULL, 1 - UP, 2 - LEFT, 3 - DIAGONAL) :: \n");
	printStruct(dir);

	printf("\nThe LCS is :: \n\t");
	printLCS(lb,la,dir);
	printf("\n");

	// print those chars which are in the LCS
	for (i = 0; i < lb; ++i)
	{
		if(b_flag[i] == 1)
			printf("%c ", b[i]);
	}
	return opStruct[lb][la];
}

// Recursive function to flag the chars in string b, which are also in LCS with string a.
void printLCS(int i, int j, int dir[lb+1][la+1])
{
	if(i == 0 || j == 0)
		return;
	else
	{
		// only the diagonal pointing elements are part of LCS.
		if (dir[i][j] == D_DIAGONAL)
		{
			b_flag[i-1] = 1;
			printLCS(i-1,j-1,dir);
		}
		// else follow the direction
		if (dir[i][j] == D_UP)
			printLCS(i-1,j,dir);
		else
			printLCS(i,j-1,dir);
	}
}


// prints table :: for direction matrix or optimal substructure.
void printStruct(int arr[lb+1][la+1])
{
	int i,j;

	printf("\n\n\t  |  0  ");
	for (i = 0; i < la; ++i)
		printf("%c  ",a[i]);
	
	printf("\n\t    ");
	for (i = 0; i < la; ++i)
		printf("----");
	
	printf("\n\t0 | ");
	for (i = 0; i < la+1 ; ++i)
		printf("%2d ",arr[0][i]);

	for (i = 1; i < lb+1 ; ++i)
	{
		printf("\n\t%c | ", b[i-1]);
		for (j = 0; j < la+1; ++j)
			printf("%2d ",arr[i][j]);
	}
}