#include <stdio.h>
#include <stdlib.h>

int main() 
{
    long long argv[6];
    long long sum=0;
    for(int i=0;i<6;i++)
    {
        scanf("%lld",&argv[i]);
        sum+=argv[i]*argv[i]*argv[i];
    }
    printf("%lld",sum);
	return 0;
}