#include <stdio.h>
int main()
{
	 int m,n;
	 scanf("%d %d",&m,&n);
	 int finish=0;
	 int count=0;
	 do
	 {
	 	int num;
	 	scanf("%d",&num);
	 	count ++;
	 	if(num<0)
	 	{
	 		printf("Game Over");
			break; 
		 }
		 else if(num<m)
		 {
		 	printf("Too small");
		 	finish=1;
		  } 
		  else if(num>m)
		  {
		  	printf("Too big");
		  	finish=1;
		  }
		  else if(num==m)
		  {
		  	if(count==1)
		  	{
		  		printf("Bingo");
		  		finish=0;
			  }
			  else if(2<=count<=3)
			  {
			  	printf("Lucky You");
			  	finish=0;
			  }
			  else if(3<count<=n)
			  {
			  	printf("Good Guess");
			  	finish=0;
			  }
		  }
		  if(count>n)
		  {
		  	printf("Game Over");
		  	break;
		  }
		  
	 }while(finish==1);
	 return 0; 
} 
