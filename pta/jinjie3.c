#include <stdio.h>
int main()
{
    int N;
    int odd=0;
    int even=0;
    int num;
    int i=1;
    scanf("%d",&N);
    for(i=1;i<=N;i=i+1)
    {scanf("%d",&num);
    if(num%2==1)
    {
        odd=odd+1;
    }
        else
        {
            even=even+1;
        }
    }
    printf("%d %d",odd,even);
    return 0;
}
