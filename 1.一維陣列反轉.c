#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int argc,argv[102],argprint[102];
    scanf("%d",&argc);

    for(int i=0;i<argc;i++)
    {
        scanf("%d",&argv[i]);
        argprint[argc-i-1]=argv[i];
    }
    for(int i=0;i<argc-1;i++)
    {
        printf("%d ",argprint[i]);
    }
    printf("%d\n",argprint[argc-1]);
	return 0;
}