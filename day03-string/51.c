#include <stdio.h>
int my_strlen(const char *s1);
char *my_strcpy(char *s2,char *s3); 
int main()
{
	char *s1="hello";
	printf("s1=%d\n",my_strlen(s1));
	char s2[23]="happy";
	char *s3="good";
	my_strcpy(s2,s3);
	printf("s2=%s\n",s2);
	return 0;
	
}
int my_strlen(const char *s1)
{
	const char *d=s1;
	while(*d!='\0')
	{
		d++;
	}
	return d-s1;
}
char *my_strcpy(char *s2,char *s3)
{
	char *a=s2;
	while(*s3!='\0')
	{
		*a=*s3;
		a++;
		s3++;
	}
	*a='\0';
	return s2;
}
