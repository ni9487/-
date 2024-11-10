#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    double up,down,height;
    while(scanf("%lf %lf %lf",&up,&down,&height)!=EOF)
    {
        double area=(up+down)*height/2;
        printf("Trapezoid area:%.1f\n",area);
    }
}