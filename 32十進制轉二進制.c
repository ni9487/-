#include<stdio.h>

int bi(int num)
{
    for(int i=7;i>=0;i--)
    {
        printf("%d",(num>>i)&1);//每次除2和1取&，只有那位共1才1
    }
    printf("\n");
}

int main()
{
    int num;
    scanf("%d",&num);
    if(num>=0)
    {
        bi(num);
    }
    else
    {
        num=(~(-num))+1;
        bi(num);
    }
}