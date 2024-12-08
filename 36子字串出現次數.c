#include<stdio.h>
#include<string.h>
int main()
{
    char find[1000];
    char input[1000];   
    scanf("%s",find);
    scanf("%s",input);

    int cnt=0;
    for(int i=0;i<strlen(input)-strlen(find)+1;i++)
    {
        int check=0;
        for(int j=i;j<i+strlen(find);j++)
        {
            if(input[j]!=find[j-i])
            {
                check=1;
                break;
            }
        }
        if(check==0)
        {
            cnt++;
        }
    }
    printf("%d\n",cnt);
}