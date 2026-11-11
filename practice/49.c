#include <stdio.h>
#include <string.h>
int main()
{
	char s1[]="hello";
	printf("strlen=%lu\n",strlen(s1));
	printf("sizeof=%lu\n",sizeof(s1));
	char s2[]="fuck you";
	printf("strlen=%lu\n",strlen(s2));
	printf("sizeof=%lu\n",sizeof(s2));
	printf("%d\n",strcmp(s1,s2));
	char s3[]="ande";
	printf("strlen=%lu\n",strlen(s3));
	printf("sizeof=%lu\n",sizeof(s3));
	printf("%d\n",strcmp(s2,s3));
	printf("%s\n",strcpy(s1,s2)) ;
	return 0;
 } 
