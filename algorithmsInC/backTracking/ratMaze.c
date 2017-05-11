#include <stdio.h>

void printMaze(int size, int maze[size][size]);
int isSafe(int x, int y, int size,int maze[size][size]);
void getMaze(int size,int maze[size][size]);
void solveMaze(int size, int maze[size][size]);

void main()
{
	int size;
	printf("Enter the size of the rat maze\n");
	scanf("%d",&size);

	int maze[size][size];
	printf("Enter the dead ends as 0 otherwise 1\n");
	getMaze(size,maze);
	
	solveMaze(size,maze);
}

// Routine to print maze
void printMaze(int size, int maze[size][size])
{
	int i,j;
	for (i = 0; i < size; ++i)
	{
		printf("\t\t");
		for (j = 0; j < size; ++j)
			printf("%d ",maze[i][j]);
		printf("\n");
	}
}

// To check whether the (x,y)th cell is a not a dead end.
int isSafe(int x, int y, int size,int maze[size][size])
{
	// x and y are within the limits of the maze and x,y is not a dead end
	if(x >=0 && x < size && y >=0 && y < size && maze[x][y] == 1)
		return 1;
	return 0;
}

// To take input maze from the user.
void getMaze(int size,int maze[size][size])
{
	int i,j;
	for (i = 0; i < size; ++i)
	{
		printf("Enter the row #%d :: ",i+1);
		for (j = 0; j < size; ++j)
			scanf("%d",&maze[i][j]);
	}
	printf("The maze is :: \n");
	printMaze(size,maze);
}

// The recursive subroutine to find the solution using backtracking.
int mazeUtility(int size,int maze[size][size],int x, int y, int sol[size][size])
{
	if(x == size - 1 && y == size - 1)
	{
		sol[x][y] = 1;
		return 1;
	}
	if(isSafe(x,y,size,maze))
	{
		//set x,y as part of solution
		sol[x][y] = 1;
		if ( mazeUtility(size,maze,x+1,y,sol))
			return 1;
		if ( mazeUtility(size,maze,x,y+1,sol))
			return 1;
		sol[x][y] = 0;	// backtrack
		return 0;
	}
}

// boiler plate code for the mazeUtility function.
void solveMaze(int size, int maze[size][size])
{
	int i,j,sol[size][size];
	for(i=0 ; i < size ; i++)
		for(j=0 ; j < size ; j++)
			sol[i][j] = 0;

	if(mazeUtility(size,maze,0,0,sol))
	{
		printf("The solution for this maze exists\n");
		printf("The solution maze wrt given maze is (follow the 1's):: \n");
		printMaze(size,sol);
	}
	else
		printf("There is no solution for the given maze\n");
}
