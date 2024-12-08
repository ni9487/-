#include<stdio.h>

int main()
{
    int i,j;
    int times;
    scanf("%d",&times);
    for(int k=0;k<times;k++)
    {
        scanf("%d %d",&i,&j);
        int area=i+j;
        printf("%d\n",area);
    }  
}