#include <stdio.h>
#define cude(x) ((x)*(x)*(x))/*加括号是为了防止运算顺序错误，导致实际输出结果与预期输出结果不同*/
#define num 5+2 
/*带参数的宏的原则：一切都要有括号，值要有括号，参数也要有括号*/ 
int main()
{
	int i;
	scanf("%d",&i);
	printf("%d\n",cude(i));
	printf("%d\n",num*2);/*预期输出结果应该为20，但实际输出结果为9*/ 
	return 0;
}
