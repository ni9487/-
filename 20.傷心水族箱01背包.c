#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int weight[n];
    int value[n];
    int arr[n+1][101];
    for(int i=0;i<101;i++)
    {
        arr[0][i]=0;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&weight[i],&value[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<101;j++)
        {
            if(j>=weight[i])
            {
                if(arr[i][j]<arr[i][j-weight[i]]+value[i])
                {
                    arr[i+1][j]=arr[i][j-weight[i]]+value[i];
                }
                else
                {
                    arr[i+1][j]=arr[i][j];
                }
            }
            else
            {
                arr[i+1][j]=arr[i][j];
            }
        }
    }
    printf("%d\n",arr[n][100]);
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<101;j++)
    //     {
    //         printf("%d ",arr[i][j]);
    //     }
    //     printf("\n");
    // }
    return 0;
}