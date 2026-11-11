#include <stdio.h>
#include <string.h>
int my_strlen(const char *a);/*传回去的是数据*/ 
char *my_strcpy(char *s1,const char *s2);/*传回去的是地址*/ 
char *my_strcat(char *s3,const char *s4);/*传回去的是地址*/ 
int my_strcmp(const char*s5,const char *s6);/*传回去的是数据 */
int main()
{
	char s[]="hello";
	char *a="hello";
	printf("sizeof(s)=%lu\n",(unsigned long)sizeof(s));/*字符串hello含有隐藏的字符'\0'，它不会显示出来，但它是真实存在的*/ 
	printf("strlen(s)=%d\n",strlen(s));/*strlen只会数明面上的字符并打印字符个数，隐藏的'\0'不会打印*/
	printf("sizeof(a)=%lu\n",(unsigned long)sizeof(a));/*输出是4，这是因为我的编译器是32位的，所以指针地址宽度占4个字节(如果是64位的就是8个字节),上面的s是
	数组，每个元素都有一个单独的地址，以char为类型所以输出6*/
	printf("sizeof(*a)=%lu\n",(unsigned long)sizeof(*a));/*输出是1，因为输出的是*a的字节长，指针里的'h'(就是*a)是一个以char为类型的字符(*(a+1)是'e'由此类推)，所以输出1*/
	printf("strlen(a)=%d\n",strlen(a));
	printf("a=%p\n",&a);
	printf("strlen(p-a)=%d\n",my_strlen(a));
	char b[23];/*要有足够的长度来接住被复制的字符串*/ 
	my_strcpy(b,"hello");/*填入函数*/ 
	printf("b=%s\n",b);/*%s是给他一个地址，然后从这个地址开始依次往后打印地址里的内容
	直到碰到'\0'*/ 
	char c[23]="hello";/*要有足够的长度来储存后续的字符串*/ 
	my_strcat(c," world");
	printf("c=%s\n",c);
	printf("%d\n",my_strcmp("abds","abd"));
	return 0;
 } 
 int my_strlen(const char*a)/*需要一个指针，并且保证不修改他*/ 
 {
 	const char*p=a;/*定义一个新指针p，与a一致保证，刚开始p的第一个字符是a的第一个字符*/
	 while(*p!='\0')/*p指向的字符不等于零即不是'\0'循环继续*/ 
	 {
	 	p++;/*指向下一个字符*/ 
	  } 
	  return (int)(p-a);/*最后p指向字符'\0'是第六个字符，a指向'h'第一个字符，所以p-a通过类型转换就等于5*/ 
 }
 char *my_strcpy(char *s1,const char *s2)
 {
 	char *d=s1;/*定义一个指针d，使其等于指针s1*/ 
 	while(*s2!='\0')/*s2是被交换的字符串指针，当s2所指的字符不为0时，循环继续*/ 
 	{
 		*d=*s2;/*指针d所指的字符等于s2所指的字符,因为d和s1指向的是同一个地址，所以d改变s1也能接收到*/ 
 		d++;/*指针往下移一位，指向下一个地址*/ 
 		s2++;/*指针往下移一位，指向下一个地址*/
	 }
	 *d='\0';/*当s2指向字符'\0'时循环停止，此时指针d并没有复制到s2的字符，因此要手动添0*/ 
	 return s1;/*此时s1是指向开头，d指向结束符，所以返回s1可以从头开始打印。另外
	 函数定义的是char *，所以要返回地址，如果是char，则要返回值*/ 
 }
 char *my_strcat(char *s3,const char *s4)
 {
 	char *w=s3;/*同理w和s3指向同一地址*/ 
 	while(*w!='\0')
 	{
 		w++;/*时w指向结束符，以便被s4的第一个字符覆盖*/ 
	 }
	 while(*s4!='\0')
	 {
	 	*w=*s4;
	 	w++;
		s4++; 
	 }
	 *w='\0';
	 return s3;
 }
 int my_strcmp(const char*s5,const char *s6)/*const防止字符串误改*/ 
 {
 	while(*s5!='\0'&&*s6!='\0'&&*s5==*s6)/*s5,s6没结束或者字符相等时循环继续*/ 
 	{
 		s5++;/*移到下一项继续比较*/ 
 		s6++; 
	 }
	 return (unsigned char)*s5-(unsigned char)*s6;/*加保险做法*/ 
 }
