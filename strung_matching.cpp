#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#define d 10
void RabinKarpStringMatch(char *, char *, int);
int main()
{
       char Text[10], Pattern[20];
       int Number = 11; //Prime Number
       printf("\nEnter Text String : ");
       gets(Text);
       printf("\nEnter Pattern String : ");
       gets(Pattern);

       RabinKarpStringMatch(Text,Pattern,Number);
       getch();
       return 0;
}

void RabinKarpStringMatch(char *Text, char *Pattern, int Number)
{
       int a = 0,b = 0,m,n,j;
       m = strlen(Pattern);
       n = strlen(Text);
       
       for(int i = 0;i<m;i++){
       		a = a+(int)Pattern[i];
       		b = b+(int)Text[i];
       }
       
       for(int  i = 0;i<=(n-m);i++){
       		if(a==b){
       			  for(j=0;j<m;j++)
                        if(Text[i+j] != Pattern[j])
                        	break;
                  if(j==m){
			           printf("\nPattern Found at Position :  %d",i+1);
			           break;
					}
       		}
       		b = b + (int)Text[i+m] - (int)Text[i];
       }

}
