#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>

void usage(void)
{
	printf("./random n a b\n");
	printf("Generate n random numbers between a and b.\n");
	printf("Please input a less than b.\n");
}
void initial()
{
	srandom(time(0));
}
int generate_random(int a, int b)
{
	int width;

	assert(a<b);
	width = b - a + 1;

	return random()%width + a;
}

int main(int argc, char *argv[])
{
	int n, a, b;
	if(argc != 4){
		usage();
		return -1;
	}
	sscanf(argv[1],"%d", &n);
	sscanf(argv[2],"%d", &a);
	sscanf(argv[3],"%d", &b);

//	printf("a:%d,b:%d,c:%d\n", n, a, b);

	// I don't know why the result seems the the same while running 
	// several times, though I set the srand function.
	// IT IS A TODO LIST.
	// Fixed. Srand and rand are a couple, while srandom is whit random
	initial();
	//printf("%u\n", (unsigned int)time(0));
	while(n--){
		printf("%d\n", generate_random(a, b));
	}
	return 0;
}
