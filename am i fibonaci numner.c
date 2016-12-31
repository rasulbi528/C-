#include<stdio.h>

int isfibonacci(int n){
	int n1 = 0,n2 = 1,sum;
	sum = n1 + n2;
	while(sum<n){
		n1 = n2;
		n2 = sum;
		sum = n1+n2;
	}
	if(sum==n){
		return 1;
	}
	return 0;
}

main(){
	int n;
	scanf("%d",&n);
	if(isfibonacci(n)){
		printf("Yes");
	}
	else{
		printf("No");
	}
}
