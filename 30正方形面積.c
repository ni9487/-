#include<stdio.h>
#include<math.h>
int main()
{
    double i;
    int times;
    scanf("%d",&times);
    for(int j=0;j<times;j++)
    {
        scanf("%lf",&i);
        double area=i*i;
        printf("%.1f\n",round(area * 10) / 10);
    }  
}