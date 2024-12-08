#include<stdio.h>

int main()
{
    char sign;
    int r1,i1,r2,i2;
    int times;
    scanf("%d",&times);
    for(int k=0;k<times;k++)
    {
        scanf(" %c %d %d %d %d",&sign,&r1,&i1,&r2,&i2);
        if(sign=='+')
        {
            printf("%d %d\n",r1+r2,i1+i2);
        }
        else if(sign=='-')
        {
            printf("%d %d\n",r1-r2,i1-i2);
        }
        else
        {
            printf("%d %d\n",r1*r2-i1*i2,i1*r2+i2*r1);
        }
    }  
}