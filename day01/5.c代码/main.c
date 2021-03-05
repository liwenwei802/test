#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void  main(int argc, char* argv[])
{
	char str[100];
	char *ch;
	ch = (char *)malloc(sizeof(char) * 10);

	int m = sizeof(ch);
	printf("m = %d\n", m);
	gets(ch);
	printf("ch = %s\n", ch);
	//printf("%s\n", gets(str));
	
	system("pause");
}
