#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int arr[1000];
    int brr[1000]={0};

    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        if(i>=1)
        {
            brr[i]+=arr[i]+brr[i-1];
        }
        else
        {
            brr[i]=arr[i];
        }
    }
    for(int i=0;i<n-1;i++)
    {
        printf("%d ",brr[i]);
    }
    printf("%d\n",brr[n-1]);
}