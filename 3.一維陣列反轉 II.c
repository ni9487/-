#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int argv[6],argprint[6];

    for(int i=0;i<6;i++)
    {
        scanf("%d",&argv[i]);
        argprint[6-i-1]=argv[i];
    }
    for(int i=0;i<5;i++)
    {
        printf("%d ",argprint[i]);
    }
    printf("%d\n",argprint[5]);
	return 0;
}