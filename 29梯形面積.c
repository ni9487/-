#include<stdio.h>

int main()
{
    int i,j,k;
    scanf("%d %d %d",&i,&j,&k);
    double area=(((double)i+(double)j)*(double)k)/2;
    printf("Trapezoid area:%.1f\n",area);
}