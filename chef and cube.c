#include<stdio.h>
#include<string.h>

int main(){
	char str[6][10];
	int i,j,count = 0;
	
	for(i = 0;i<6;i++){
		scanf("%s",str[i]);
		fflush(stdin);
	}
	for(i = 0;i<6;i++){
		count = 0;
		if(i%2==0){
			for(j = 0;j<6;j++){
				if(j!=(i+1)){
					if(str[i].compare(str[j])==0){
						printf("vaishnavi %d\n",j);
						count++;
						if(count==2){
							printf("YES");
							return;
						}
					}
				}
			}
		}
		else{
			for(j = 0;j<6;j++){
				if(j!=(i-1)){
					if(str[i]==str[j]){
						printf("mahesh %d\n",j);
					count++;
						if(count==2){
							printf("YES");
							return;
						}
					}
					
				}
			}
		}
	}
	printf("NO");
	return 0;
}
