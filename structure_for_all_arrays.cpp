#include <conio.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int main(){
	int *arr;
	int size;
	printf("Enter size\n");
	scanf("%d",&size);
	arr = (int*)malloc(sizeof(int)*size);
	printf("Enter elements\n");
	for(int i = 0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	
	return 0;
}
