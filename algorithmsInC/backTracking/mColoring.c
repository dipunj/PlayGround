#include <stdio.h>

#define UNASSIGNED -1

// For the ease of readability
#define true 1
#define false 0

int N;		// The number of vertices

void getGraph(int graph[N][N]);
void solveGraph(int graph[N][N], int);
int graphUtility(int graph[N][N], int , int color[N], int );
int isSafe(int graph[N][N], int , int color[N], int);

int main()
{
	printf("Enter the no of vertices in the graph\n");
	scanf("%d",&N);

	int graph[N][N];
	getGraph(graph);
	
	int m;
	printf("Enter the value of m:\n");
	scanf("%d",&m);

	solveGraph(graph, m);
}

// Takes the input from the user.
void getGraph(int graph[N][N])
{
	int i,j;

	// Taking input
	printf("Enter the adjacency matrix for the graph\n");
	for( i = 0 ; i < N ; ++i )
		for( j = 0 ; j < N ; ++j )
			scanf("%d",&graph[i][j]);
	
	// Confirming the input
	printf("The matrix entered is :");
	for( i = 0 ; i < N ; ++i )
	{
		printf("\n\t\t");
		for( j = 0 ; j < N ; ++j )
			printf("%d ",graph[i][j]);
	}
	printf("\n");
}

// Boiler plate for graphUtility() function.
void solveGraph(int graph[N][N], int m)
{
	int i,color[N];

	// Initializing the colors for each vertex
	for(i = 0 ; i < N ; ++i)
		color[i] = UNASSIGNED;
	if (graphUtility(graph, m, color, 0) == false)
	{
		printf("The solution doesn't exist\n");
		return;
	}

	printf("The solution exists :: ");
	for (i = 0; i < N; ++i)
		printf("\n\tVertex No. %d :: Color = %d\n",i+1,color[i]);
}

// The protagonist function which performs backtracking.
int graphUtility(int graph[N][N], int m, int color[N], int v)
{

	// If v reaches N, problem is solved
	if(v == N)
		return true;
	
	int i;
	for(i = 1 ; i <= m ; ++i )
		if(isSafe(graph,v,color,i) == true)
		{
			// set the color of vth vertex to i
			color[v] = i;
			if(graphUtility(graph,m,color,v+1))
				return true;
			// reset the color of vth vertex if setting the color 
			// to i doesn't lead to solution
			color[v] = UNASSIGNED;
		}

	// If for any color from 1 to m doesn't lead to a solution then solution doesn't exist
	return false;
}


// To check whether the vertex v can be safely colored/set to color c
int isSafe(int graph[N][N], int v, int color[N], int c)
{
	int i;
	for (i = 0; i < N; ++i)
		if (graph[v][i] && color[i] == c)
			return false;
	return true;
}