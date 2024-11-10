//        0 1 2 3 4
// female 1 1 2 3 5
// male   0 1 2 4 7 由當前公數+母數=下年公數

#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int female[n+1];
    int male[n+1];

    female[0]=1;
    female[1]=1;
    male[0]=0;
    male[1]=1;

    for(int i=2;i<n+1;i++)
    {
        female[i]=female[i-1]+female[i-2];
        male[i]=female[i-1]+male[i-1];
    }

    printf("%d %d\n",male[n],female[n]);
}