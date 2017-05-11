#include <stdio.h>
#include <string.h>

void permute(char str[],int l, int r);
void swap(char* a, char* b);

int count;

int main()
{
	char str[500];
	printf("Enter the string\n");
	scanf("%s",str);
	printf("The string is :: %s\nThe perumtations are :\n",str);
	permute(str,0,strlen(str));
	return 0;
}

void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void permute(char str[],int l, int r)
{
	if (l == r)
	{
		++count;
		printf("\t\t%d.\t%s\n",count,str);
	}
	else
	{
		int i;
		for (i = l; i < r; ++i)
		{
			swap(&str[l], &str[i]);
			permute(str,i+1,r);
			swap(&str[l], &str[i]);
		}
	}	
}