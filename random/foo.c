#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>

int main(int argc, char *argv[])
{
	unsigned int ui;
	ui = (unsigned int)time(0);
	printf("ui:%u\n",ui);
	srand(ui);
	printf("random number #1:%ld\n", random());
	printf("random number #2:%ld\n", random());
	printf("random number #3:%ld\n", random());

	return 0;
}
