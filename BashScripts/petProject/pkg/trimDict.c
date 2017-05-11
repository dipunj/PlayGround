#include <stdio.h>
#include <string.h>

// prints the string arr, if it is exactly TRIM characters long
int main()
{
	char arr[TRIM+1];
	scanf("%s",arr);

	if(strlen(arr) == TRIM)
		printf("%s\n",arr);
	return 0;
}
