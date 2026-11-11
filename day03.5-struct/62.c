#include <stdio.h>
typedef union
{
	int i;
	char ch[sizeof(int)];
}CHI;
int main()
{
	CHI chi;
	int i;
	chi.i =1234;
	for(i=0;i<sizeof(int);i++)
	{
		printf("%02hhx",chi.ch [i]);/*d2040000,小端，数组在内存中是低地址向高地址排队
		num[0]是低地址。低位在后，高位在前*/ 
	}
	printf("\n");
	return 0;
 } 
