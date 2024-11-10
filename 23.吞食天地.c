#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    int n;
    scanf("%d",&n);
    int arr[200]={0};
    int final[200]={0};
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        if(i==0)
            final[0]=arr[0];
        else
            final[i]=final[i-1]+arr[i];
    }
    // for(int i=0;i<n;i++)
    // {
    //     printf("%d ",final[i]);
    // }
    int s,e;
    scanf("%d %d",&s,&e);
    if(s==1)
        printf("%d\n",final[e-1]);
    else if (e==1)
        printf("%d\n",final[0]);
    else
        printf("%d\n",final[e-1]-final[s-2]);
}