#include <stdio.h>
#include <string.h>

int josephus(int n,int k)
{
    if(n==1)//唯1人時，必定編號0活
        return 0;
    return((josephus(n-1,k)+k)%n);
    //回推，若活到最後處0位，當初剩2人時應該站哪?
    //應站k%2位
}

int main()
{
    int m;  
    scanf("%d",&m);

    for (int test=0;test<m;test++)
    {
        int n;
        int k;
        scanf("%d %d",&n,&k);

        char names[51][51];
        for (int i=0;i<n;i++) 
        {
            scanf("%s",names[i]);
        }

        int winner_index = josephus(n,k);
        printf("%s\n",names[winner_index]);
    }

    return 0;
}

// int josephus(int n, int k)
// {
//     int pos = 0;  
//     for (int i = 2; i <= n; i++) 
//     {
//         pos = (pos + k) % i;
//     }
//     return pos;  
// }
