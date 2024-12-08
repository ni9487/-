#include<stdio.h>
#include<string.h>
int main()
{
    char input[1000];
    scanf("%s",input);

    int check=0;
    for(int i=0;i<strlen(input)/2;i++)
    {
        if(input[i]!=input[strlen(input)-i-1])
        {
            check=1;
        }
    }
    if(check==1)
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n");
    }
    
}