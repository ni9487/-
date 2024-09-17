#include<stdio.h>
#include<string.h>

int main()
{
    int cnt=0;
    int arr[102];
    while(scanf("%d",&arr[cnt])!=EOF)
    {
        cnt++;
    }
    for(int i=0;i<cnt-1;i++)
    {
        printf("%d ",arr[cnt-i-1]);
    }
    printf("%d\n",arr[0]);
}