#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

void counting_sort(int* a,int size,int k){
	int *c = (int*)malloc(sizeof(int)*(1+k));
	int *b = (int*)malloc(sizeof(int)*(1+size));
	for(int i = 1;i<=k;i++){
		c[i] = 0;
	}
	for(int i = 1;i<=size;i++){
		c[a[i]] += 1;
	}
	for(int i = 2; i<=k ;i++){
		c[i] += c[i-1];
	}
	for(int i = size;i>=1;i--){
		b[c[a[i]]] = a[i];
		c[a[i]] = c[a[i]]-1;
	}
	
	for(int i = 1;i<=size;i++){
		a[i]= b[i];
	}
}

int main(){
	int *arr;
	int size,k;
	printf("Enter size\n");
	scanf("%d",&size);
	printf("Enter range\n");
	scanf("%d",&k);
	arr = (int*)malloc(sizeof(int)*(1+size));
	for(int i = 1;i<=size;i++){
		scanf("%d",&arr[i]);
	}
	counting_sort(arr,size,k);
	for(int i = 1;i<=size;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}

