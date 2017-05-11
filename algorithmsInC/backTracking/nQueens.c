#include <stdio.h>

void solveQueens(int);
int queenUtility(int n, int board[n][n],int);
int isSafe(int n, int board[n][n],int, int );
void printBoard(int n, int board[n][n]);

void main()
{
	int n;
	printf("Enter the size of the chess board\n");
	scanf("%d",&n);

	solveQueens(n);
}

void printBoard(int n, int board[n][n])
{
	int i,j;
	for(i = 0 ; i < n ; ++i)
	{
		printf("\n\t\t");
		for(j = 0 ; j < n ; ++j)
			printf("%d ",board[i][j]);
		printf("\n");
	}
}
void solveQueens(int n)
{
	int i,j,board[n][n];
	for(i=0;i<n;++i)
		for(j=0;j<n;++j)
			board[i][j] = 0;

	if(!queenUtility(n,board,0))
	{
		printf("Solution does not exists\n");
		return;
	}
	printBoard(n,board);
	return;
}

int queenUtility(int n, int board[n][n], int col)
{
	if(col >= n  )
		return 1;
	int row;
	for(row=0 ; row < n ; ++row)
	{
		if(isSafe(n,board,row,col))
		{
			board[row][col] = 1;
			if(queenUtility(n,board,col+1))
				return 1;
			board[row][col] = 0;
		}
	}
	return 0;
}

int isSafe(int n, int board[n][n], int row, int col)
{
	int i,j;
	for(i=0 ; i < col ; ++i)
		if(board[row][i] == 1)
			return 0;
	for (i = row , j = col ; i >= 0 && j >= 0 ; --i, --j)
		if(board[i][j] == 1)
			return 0;
	for(i = row , j = col ; i < n && j >= 0 ; ++i, --j)
		if(board[i][j] == 1)
			return 0;
	return 1;
}