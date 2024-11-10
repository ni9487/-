#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char c[1000];
    scanf("%s",c);
    int len=strlen(c);
    for(int i=0;i<len;i++)
    {
        printf("%c",c[i]-3);
    }
    printf("\n");
}