#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define MAXSIZE 2048000

int partion(int *, int , int);
void quicksort(int *A, int p, int r)
{
	int q;
	if(p<r){ // the judgement is a nessesary, because the return value of function partion q maybe less the r.
		q = partion(A, p, r);
		quicksort(A, p, q-1);
		quicksort(A, q+1, r);
	}
}
int partion(int *A, int p, int r)
{
	int i, j, temp;
	i = p - 1;
	for(j = p; j < r; ++j){
		if(A[j]<A[r]){
			++i;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	++i;
	temp = A[i];
	A[i] = A[r];
	A[r] = temp;
	return i;
}

void read_data(int *A, int n)
{
	int i;
	for(i = 0; i < n; ++i)
		scanf("%d", A+i);
}

void print_data(int *A, int n)
{
	int i;
	for(i = 0; i < n; ++i)
		printf("%3d:%6d\n", i,A[i]);
}

int main(int argc, const char *argv[])
{
	int A[MAXSIZE], n;
	scanf("%d", &n);
	printf("n=%d\n", n);
	if(n<MAXSIZE)
		read_data(A, n);
	else
		exit(1);
//	print_data(A, n);
//	printf("======sorted by quicksort======\n");
	quicksort(A, 0, n-1);
	print_data(A, n);

	return 0;
}
