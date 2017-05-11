#include <stdio.h>
#include <math.h>
#define UNASSIGNED 0
#define true 1
#define false 0
#define N 9		// sudoku size

int isSafe(int grid[N][N], int row, int col, int num);
int isUnassigned(int grid[N][N],int *x,int *y);
int sudokuUtility(int grid[N][N]);
void getSudoku(int grid[N][N]);
void printSudoku(int grid[N][N]);

void main()
{
	int grid[N][N] = {UNASSIGNED};
	//getSudoku(grid);
	printSudoku(grid);
	printf("\nLoading ...\n");
	if(!sudokuUtility(grid))
		printf("\nSolution doesn't exist\n");
	
	printf("\nThe solution exists :: \n");
	printSudoku(grid);
}

void getSudoku(int grid[N][N])
{
	printf("Enter the sudoku (1 to 9). Enter 0 if you want to leave it unassigned\n\n");
	int i,j;
	for (i = 0; i < N; ++i)
	{
		printf("Enter the row #%dof sudoku\n",i+1);
		for (j = 0; j < N; ++j)
			scanf("%d",&grid[i][j]);
	}
}

// Checks whether the cell (row,col) is unassigned or not
int isUnassigned(int grid[N][N],int *x, int *y)
{
	for (*x = 0; *x < N; ++(*x))
		for (*y = 0; *y < N; ++(*y))
			if(grid[*x][*y] == UNASSIGNED)
				return true;
	return false;
}

// Checks whether it will be safe to put num in the cell (row,col).
int isSafe(int grid[N][N], int row, int col, int num)
{
	int i,j;
	for (i = 0; i < N; ++i)
	{
		if( grid[i][col] == num || grid[row][i] == num)
		return false;
	}
	
	int newRow = row - row%((int)sqrt(N));
	int newCol = col - col%((int)sqrt(N));
	
	for (i = newRow; i < newRow + ((int)sqrt(N)); ++i)
		for (j = newCol; j < newCol + ((int)sqrt(N)); ++j)
			if(grid[i][j] == num)
				return false;
	return true;
}

// This is the protagonist function, performs backtracking
int sudokuUtility(int grid[N][N])
{
	int row,col;
	if(!isUnassigned(grid,&row,&col))
		return true;
	int num;
	for (num = 1; num <= N; ++num)
	{
		if(isSafe(grid,row,col,num))
		{
			grid[row][col] = num;
			if(sudokuUtility(grid))
				return true;
			grid[row][col] = UNASSIGNED;
		}
	}
	return false;
}

// just prints the whole grid
void printSudoku(int grid[N][N])
{
	int i,j;

	for(i = 0 ; i < N ; ++i)
	{
		if(i%((int)sqrt(N)) == 0)
			printf("\n\n\t\t");
		else
			printf("\n\t\t");
		for (j = 0; j < N; ++j)
			if(i%((int)sqrt(N)) == 0)
				printf("- - - ");
		if(i%((int)sqrt(N)) == 0)
			printf("-");
		
		if(i%((int)sqrt(N)) == 0)
			printf("\n\n\t\t");
		else
			printf("\n\t\t");


		for (j = 0; j < N; ++j)
		{
			if(j%((int)sqrt(N)))
				printf(", ");
			else
				printf("| ");
			printf("%3d ",grid[i][j]);
		}
		printf("|");
	}

	printf("\n\n\t\t");
	for (j = 0; j < N; ++j)
		if(i%((int)sqrt(N)) == 0)
			printf("- - - ");
	printf("\n");
}