#include <conio.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node{
	int value,size;
};

void swap(int* arr,int i,int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void max_heapify(int* arr,int size , int i){
	int j = 2*i;
	if((j <=size) && ((j+1)<=size))
	 if((arr[j] < arr[j+1]) && (arr[i]<arr[j+1]) ){
	 	swap(arr,i,j+1);
		max_heapify(arr,size,j+1);
	 }
	 else if(arr[i]<arr[j]){
	 	swap(arr,i,j);
		max_heapify(arr,size,j);
	 }
	 else if((j<=size) && !((j+1)<=size)){
	 	if(arr[i]<arr[j]){
	 	 	swap(arr,i,j);		
		}
	 }
}

void extract_max(int* arr,int size,struct node* rv){
	rv->value = arr[1];
	swap(arr,1,size);
	rv->size = size - 1;
	max_heapify(arr,rv->size,1);
}

void build_max_heap(int* arr,int size){
	for(int i = (size)/2 ; i > 0;i--){
		max_heapify(arr,size,i);
	}
}

int main(){
	int *arr;
	struct node* rv;
	rv = (struct node*)malloc(sizeof(struct node));
	int size;
	printf("Enter size\n");
	scanf("%d",&size);
	arr = (int*)malloc(sizeof(int)*(size+1));
	printf("Enter elements\n");
	for(int i = 1;i<=size;i++){
		scanf("%d",&arr[i]);
	}
	build_max_heap(arr,size);
	int max = size;
	for(int i = 1;i <= max;i++){
		extract_max(arr,size,rv);
		printf("%d ",rv->value);
		size = rv->size;  
	}
	return 0;
}
