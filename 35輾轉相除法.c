#include<stdio.h>

int gcd(int i,int j)
{
    while(j!=0)
    {
        int temp=j;
        j=i%j;
        i=temp;
    }
    return i;
}

int main()
{
    int i,j;
    scanf("%d %d",&i,&j);
    printf("%d\n",gcd(i,j));
}