#include <stdio.h>
#include <string.h>
#include <math.h>

// Only outputs the subsets of size val from set[], of size size
void printPowerSet(char set[], int size,int val)
{
	char temp[val];
	int set_size = pow(2,size);

	int i,j,ctr;

	for(i = 0 ; i < set_size; ++i)
	{
		ctr = 0;
		for(j = 0 ; j < size ; ++j)
			if(i & (1<<j))
				temp[ctr++] = set[j];
		temp[ctr] = '\0';
		if(ctr == val)
			printf("%s\n",temp);
	}
}

int main()
{
	char set[50];
	scanf("%s",set);
	printPowerSet(set,strlen(set),SIZE);
}
