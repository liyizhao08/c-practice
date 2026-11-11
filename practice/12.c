#include <stdio.h>
int main()
 {
 	int x;
 	int a;
 	int num=0;
 	scanf("%d",&x);
 	while(x>0)
 	{
 		a=x%10;
 		num=num*10+a;
 		x/=10;
	 }
	 printf("%d",num);
	 return 0;
 } 
