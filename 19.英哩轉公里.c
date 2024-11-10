#include <stdio.h>
#include <math.h>

int main()
{
    double s;
    scanf("%lf",&s);
    double m=s*1.6;
    double r=round(m*10)/10;
    printf("%.1f\n",r);
}