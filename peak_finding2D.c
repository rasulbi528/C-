#include<conio.h>
#include<stdio.h>

int max_index(int** arr,int n,int col){
	int i = 0,ret = 0,max = arr[0][col];
	for(i = 1;i<n;i++){
		if(max>arr[i][col]){
			max = arr[i][col];
			ret = i;
		}
	}
}

int main(){
	int** arr;
	int j,i,n,m,min,max,index,max_elem;
	scanf("%d",&n);
	scanf("%d",&m);
	arr = (int**)malloc(sizeof(n*sizeof(int*)));
	for(i = 0;i<n;i++){
		arr[i] = (int*)malloc(sizeof(int)*m);
	}
	for(i = 0;i<n;i++){
		for(j = 0;j<m;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	min = 0,max = m;
	while(min<max){
		index = (min+max)/2;
		max_elem = max_index(arr,n,index);
		 
	}
	return 0;
}
