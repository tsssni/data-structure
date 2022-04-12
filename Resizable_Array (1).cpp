#include<stdio.h>
#include<stdlib.h>
#define BLOCK_SIZE 20
typedef struct{
	int *array;
	int size;
} Array;
Array array_create(int init_size){
	Array a; 
	a.array=(int *)malloc(sizeof(int)*init_size);
	a.size=init_size;
	return a;
} 
void array_free(Array *a){
	free(a->array);
	a->array=NULL;
	a->size=0;
}
int array_size(const Array a){
	return a.size;
}
void array_inflate(Array *a,int more_size){
	int* p;
	p=(int *)malloc(sizeof(int)*(a->size+more_size));
	for(int i=0;i<a->size;i++) p[i]=a->array[i];
	free(a->array);
	a->array=p;
	a->size+=more_size;
}
int* array_at(Array* a,int index){
	if(index>=a->size) array_inflate(a,(index/BLOCK_SIZE+1)*BLOCK_SIZE-a->size);
	return &a->array[index];
}

int main(){
	Array a;
	int num,cnt=0;
	a=array_create(100);
	while(num!=-1){
		scanf("%d",&num);
		if(num!=-1) *array_at(&a,cnt++)=num;
	}
	free(&a);
}
