#include <stdio.h>
int main()
{
  char ch[100000];
  char num[1000000];
  gets(num);
  gets(num);
  scanf("%s",ch);
  scanf("%s",num);
  int i=0;
  int ret=1;
  int cnt=0;
  int sum;
  while(num[i]!='\0')
  {
  	if(num[i]==ch[0])
  	{
  		int j=i;
  		int k=0;
  		while(ch[k]!='\0')
  		{
  			if(ch[k]==num[j]) ret=1;
  			else 
  			{
  				ret=0;
  				break;
			  }
		  }
	  }
	  if(ret==1)
	  {
	  	cnt++;
	  }
	  if(cnt==1) sum=i; 
  	i++;
  }
  if(cnt==0)
  {
  	printf("-1");
  	return 0;
  }
  printf("%d %d",cnt,sum);
  return 0;
} 
