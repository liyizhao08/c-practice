#include <stdio.h>
#include <stdlib.h>
int main()
{
	void *p;
	int cnt = 0;
	while((p=malloc(100*1024*1024)))
	{
		cnt++;
	}
	printf("分配了%d00mb的空间\n",cnt);
	free(p); 
	p=NULL;
	return 0;
 } 
