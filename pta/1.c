#include <stdio.h>
int main()
{
	int price=0;
	int bill=0;
	printf("请输入金额");
	scanf("%d",&price);
	printf("请付钱"); 
	scanf("%d",&bill);
	if(bill>=price)
	{
	printf("找您%d元。",bill-price); 
}
else
{
	printf("对不起先生，钱不够。");
}
	return 0;
 } 
