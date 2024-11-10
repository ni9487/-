#include <stdio.h>
#define max 200//為了傳二維進函式

int nearest(int key[],int visited[],int k)//~~~~用來找key裡最小的那個
{
    int min=1000000;
    int minpos=0;
    for(int i=0;i<k;i++)//refind the node with shortest len
    {
        if(visited[i]==0&&key[i]<min)
        {
            min=key[i];
            minpos=i;
        }
    }
    return minpos;
}

int prim(int arr[max][max],int k)
{
    int sum=0;
    int key[k];//shortest len for nodes
    int visited[k];
    for(int i=0;i<k;i++)
    {
        key[i]=1000000;
        visited[i]=0;
    }
    key[0]=0;
    for(int i=0;i<k;i++)
    {
        int near=nearest(key,visited,k);
        visited[near]=1;
        sum+=key[near];
        for(int j=0;j<k;j++)//~~~~用來更新key裡的狀態
        {
            if(arr[near][j]!=0 && visited[j]==0 && arr[near][j]<key[j])
            {   //key的各位置會保持著各節點到上一節點的最短距
                key[j]=arr[near][j];//把和near節點有聯繫的都找出，如果比原本在key裡的路短就更新，
                //比如0節點走到4節點，即key[4]原本要35，後發現3節點走到4節點只要29，key[4]就變29
            }
        }
    }
    return sum;
}

int main() 
{
    int k=0;
    int arr[max][max];
    scanf("%d",&k);
    for(int i=0;i<k+1;i++)
    {
        for(int j=0;j<k+1;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    int ssum=prim(arr,k+1);
    printf("%d\n",ssum);
}
