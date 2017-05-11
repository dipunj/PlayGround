#include <stdio.h>
#include <string.h>

void permute(char str[],int l, int r);
void swap(char* a, char* b);

int main()
{
	char str[500];
	scanf("%s",str);
	int l = strlen(str)-1;
	permute(str,0,strlen(str)-1);
	return 0;
}

// swaps the content of two char variables
void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

// permutes the string str using backtracking
void permute(char str[],int l, int r)
{
	if (l == r)
		printf("%s\n",str);
	else
	{
		int i;
		for (i = l; i <= r; ++i)
		{
			swap(&str[l], &str[i]);
			permute(str,l+1,r);
			swap(&str[l], &str[i]);		// backtrack
		}
	}	
}
