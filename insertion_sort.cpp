#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void insertion(int* arr,int size){
	for(int i = 1;i<size;i++){
		for(int j = i - 1 ; j >= 0 ; j--){
			if(arr[j]>arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;  
			}
		}
	}
}

int main(){
	int *arr;
	int size;
	printf("Enter size\n");
	scanf("%d",&size);
	arr = (int*)malloc(sizeof(int)*size);
	printf("Enter elements\n");
	for(int i = 0 ; i<size;i++){
		scanf("%d",&arr[i]);
	}
	insertion(arr,size);
	printf("Sorted list is\n");
	for(int i = 0;i<size;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}

