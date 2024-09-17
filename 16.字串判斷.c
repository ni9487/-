#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char c;
    int total=0;
    while(scanf("%c",&c)!=EOF)
    {
        if(c=='2')
        {
            total++;
        }
    }
    if(total==0)
    {
        printf("0\n");
    }
    else
    {
        printf("%d\n",total);
    }
}