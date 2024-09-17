#include<stdio.h>
#include<string.h>

int main()
{
    int n;
    scanf("%d",&n);
    getchar();

    char str[1002];

    for(int j=0;j<n;j++)
    {
        int arr[256]={0};
        fgets(str,1002,stdin);
        int len=strlen(str);

        int maxcnt=0;
        char max=0;
        for(int i=0;i<len;i++)
        {
            arr[str[i]]++;
            if(arr[str[i]]>maxcnt)
            {
                maxcnt=arr[str[i]];
                max=str[i];
            }
        }
        printf("%c\n",max);
    }
    return 0;
} 
        