#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	long buf;

	read(0, &buf, 8);
	if (buf == 140733365443355)
		printf("HI!\n");
	else
		printf("%ld\n", buf);
	return (0);
}
