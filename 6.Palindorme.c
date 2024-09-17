#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    char arr[1000];
    int top;
}Stack;

void initstack(Stack*s)
{
    s->top=-1;
}

bool isempty(Stack*s)
{
    return(s->top==-1);
}

void push(Stack*s,char c)
{
    s->arr[++(s->top)]=c;
}

char pop(Stack*s)
{
    if(!isempty(s))
    {
        char toReturn=s->arr[s->top];
        s->top--;
        return toReturn;
    }
    return '\0';
}

bool isPalindorme(char str[])
{
    Stack sentence;
    initstack(&sentence);
    int len=strlen(str);
    int half=strlen(str)/2;
    for(int i=0;i<half;i++)
    {
        push(&sentence,str[i]);
    }

    int start=0;
    if(len%2==0)
    {
        start=half;
    }
    else
    {
        start=half+1;
    }

    for(int i=start;i<len;i++)
    {
        if(pop(&sentence)!=str[i])
            return false;
    }
    return true;
}

int main()
{
    char str[1000];
    scanf("%s",str);
    if (isPalindorme(str)) 
    {
        printf("yes\n");
    } 
    else 
    {
        printf("no\n");
    }
    return 0;
}
