#include<stdio.h>
main(){
	int arr[10],i,min,ind,j;
	for(i = 0;i<10;i++){
		scanf("%d",&arr[i]);
	}
	min = arr[9];
	ind = 9;
	for(i = 1;i<9;i++){
		if(min>arr[i]){
			min = arr[i];
			ind = i;
		}
	}
	if(min<=arr[0]){
		for(j = 0;j<=min;j++){
			printf("%d",ind);
		}
	}
	else{
		printf("1");
		for(j = 0;j<=arr[0];j++){
			printf("0");
		}
	}
}
