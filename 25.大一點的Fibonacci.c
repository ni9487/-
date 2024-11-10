#include<stdio.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==-1)
        {
            break;
        }
        else
        {
            int fi[n+1];

            fi[0]=1;
            fi[1]=1;

            for(int i=2;i<n+1;i++)
            {
                fi[i]=fi[i-1]+fi[i-2];
            }

            printf("%d\n",fi[n]);
        }
    }
    return 0;
}