#include<stdio.h>

int main()
{
    int i,j;
    scanf("%d %d",&i,&j);
    double area=((double)i*(double)j)/2;
    printf("Triangle area:%.1f\n",area);
}