#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int n=0;
    char arr[1000];
    int devide=0;
    scanf("%d",&n);
    scanf("%s",arr);
    scanf("%d",&devide);
    for(int i=0;i<n;i++)
    {
        printf("%c",arr[i]);
        if(i>=devide-1&&(i+1)%devide==0&&i!=n-1)
        {
            printf(" ");
        }
    }
    printf("\n");
}