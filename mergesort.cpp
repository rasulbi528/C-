#include <conio.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void merge(int* arr,int low,int mid,int high){
	int l , m , j , h , i;
	l = low;
	m = mid;
	j = mid+1;
	h = high;
	int a[high-low+1]; 
	for(i = low;(l<=m) && (j<=h);i++){
		if(arr[l]<arr[j]){
			a[i] = arr[l];
			l++;
		}
		else{
			a[i] = arr[j];
			j++;
		}
	}
	
	
	if(l>m){
		for(int k = j;k<=h;k++){
			a[i] = arr[k];
			i++;
		}
	}
	
	else if(j>h){
		for(int k = l;k<=m;k++){
			a[i] = arr[k];
			i++;
		}
	}
	
	for(int i = low ; i<= high ;i++){
		arr[i] = a[i];
	}
	
}

void mergesort(int* arr,int low , int high){
	int mid;
	if(low<high){
		mid = (low+high)/2;
		mergesort(arr,low,mid);
		mergesort(arr,mid+1,high);
		 merge(arr,low,mid,high);
	}
}

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
	
	mergesort(arr,0,size-1);
	
	printf("Sorted list is\n");
	for(int i = 0;i<size;i++){
		printf("%d ",arr[i]);	
	}
	getch();
	return 0;
}
