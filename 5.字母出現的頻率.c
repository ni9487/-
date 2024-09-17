#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() 
{
    int arr[26]={0};
    char sentence[10000];

    fgets(sentence, sizeof(sentence), stdin);
    int length = strlen(sentence);

    for(int i=0;i<length;i++)
    {
        if(isalpha(sentence[i])&&islower(sentence[i]))
        {
            arr[(int)sentence[i]-'a']++;
        }
        else if(isalpha(sentence[i])&&isupper(sentence[i]))
        {
            arr[(int)sentence[i]-'A']++;
        }
    }
    for(int i=0;i<25;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("%d\n",arr[25]);
}