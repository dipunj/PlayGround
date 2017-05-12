#include <stdio.h>
#include <unistd.h>

int main()
{
	int i;
	printf("Continue in...");
	for (i = 9; i > 0 ; --i)
	{
		printf("%d",i);
		printf("\b");
		fflush(stdout);
		sleep(1);
	}
}