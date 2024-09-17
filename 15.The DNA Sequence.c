#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int section=0;
    char c[1000];
    while(scanf("%d %s",&section,c)!=EOF)
    {
        int len=strlen(c);
        int start=0;
        for(int i=0;i<len;i++)
        {
            c[i]=tolower(c[i]);
        }
        for(int i=0;i<len;i++)
        {
            if(c[i]=='c'||c[i]=='g')
            {
                start=i;
                break;
            }
        }
        double maxrate=0;
        for(int i=start;i<len-section;i++)
        {
            for(int j=i;j<len;j++)
            {
                double lennow=j-i+1;
                if(lennow>=section)
                {
                    double cntcg=0;
                    for(int t=i;t<j+1;t++)
                    {
                        if(c[t]=='c'||c[t]=='g')
                        {
                            cntcg++;
                        }
                    }
                    double nowrate=cntcg/lennow;
                    if(maxrate<nowrate)
                    {
                        maxrate=nowrate;
                    }
                }
            }
        }
        printf("%.3f\n",maxrate);
    }
}