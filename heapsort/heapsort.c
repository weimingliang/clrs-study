//Author: Wei Mingliang
//Date: Sep. 22, 2015
//有两个问题需要解决
//1. 函数参数不一致，有些无需修改heap_size的函数，形参的形式传进去了。
//有些需要修改heap_size的函数，则没有将该参数传进去，而是直接操作全局变量
//2. heap 的数据和heap_size需要做封装，可用结构体，或者数据的最后一项。
//后者采用硬编码的方式。
#include<stdio.h>

#define HEAP_SIZE 2048

int heap[HEAP_SIZE];
int heap_size;

void initial()
{
	int i = 0;
	for( i = 0; i < HEAP_SIZE; ++i)
		heap[i] = 0;
	heap_size = 0;
}

int parent(int i)
{
	return i>>1;
}
int left(int i)
{
	return i<<1;
}
int right(int i)
{
	return (i<<1)+1;
}
void max_heapify(int *a, int size, int i)
{
	int l, r, largest, temp;

	l = left(i);
	r = right(i);
	
	if(l>size || r>size || i>size)
		return;

	largest = i;
	if(a[l]>a[largest])
		largest = l;
	if(a[r]>a[largest])
		largest = r;
	if(largest != i){
		temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
		max_heapify(a, size, largest);
	}

}
void build_max_heap(int *a, int size)
{
	int i;
	i = size>>1;
	while(i>0){
		max_heapify(a, size, i);
		i--;
	}
}
void heap_sort(int *a, int size)
{
	int temp;
	build_max_heap(a, size);
	while(size>1){
		temp = a[size];
		a[size] = a[1];
		a[1]=temp;
		size--;
		max_heapify(a, size,1);
	}
}
void my_print(int *a, int size)
{
	int i;
	for(i = 1; i <= size; ++i){
		printf("%3d:%6d\n", i, a[i]);
	}
}
void read_data(int *a, int size)
{
	int i;
	for(i = 1; i<= size; ++i)
		scanf("%d", a+i);
}

int heap_extract_max(int *a)
{
	int ret, temp;
	if(heap_size < 1){
		printf("heap_size less than one , heap underflow\n");
		return -1;
	}
	ret = a[1];
	a[1]=a[heap_size];
	heap_size--;
	if(heap_size>1)
		max_heapify(a, heap_size, 1);
	return ret;
}
void heap_increase_key(int *a, int i, int key)
{
	int temp;
	a[i] = key;
	while(i>1 && a[parent(i)]<a[i]){
		temp = a[i];
		a[i] = a[parent(i)];
		a[parent(i)] = temp; 
		i--;
	}
}
void heap_insert_key(int *a, int key)
{
	heap_size++;
	a[heap_size]=-0xFFFFFFF;
	heap_increase_key(a, heap_size, key);
}

int main(int argc,const char *argv[])
{
	initial();
	scanf("%d", &heap_size);
	read_data(heap, heap_size);
	my_print(heap, heap_size);
	
	printf("====sorting by heap method=====\n");
	heap_sort(heap, heap_size);
	my_print(heap, heap_size);
}
