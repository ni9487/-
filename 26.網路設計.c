#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 200//為了傳二維進函式

typedef struct 
{
    int from;
    int to;
}edge;

int cmp(const void*a,const void*b)
{
    edge*edgea=(edge*)a;
    edge*edgeb=(edge*)b;
    int compare=edgea->from-edgeb->from;
    if(compare==0)
    {
        return edgea->to-edgeb->to;
    }
    return compare;
}

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

int prim(int arr[max][max],int k,int from[max])
{
    int sum=0;
    int key[k];//shortest len for nodes
    int visited[k];
    int edgecnt=0;
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
                from[j]=near;//第一次入迴圈會得到誰來自0節點，但永遠不知0來自誰
            }
        }
    }
    return sum;
}

int main() 
{
    int k=0;
    int input=0;
    char name[max][max];
    int arr[max][max];
    scanf("%d %d",&k,&input);
    for(int i=0;i<k;i++)
    {
        scanf("%s",name[i]);
    }
    char a[max],b[max];
    int distance;

    int from[k];
    edge edges[k-1];

    for(int i=0;i<input;i++)
    {
        scanf("%s %s %d",a,b,&distance);
        int sta,end;
        for(int i=0;i<k;i++)
        {
            if(strcmp(a,name[i])==0)
            {
                sta=i;
            }
            if(strcmp(b,name[i])==0)
            {
                end=i;
            }
        }
        arr[sta][end]=distance;
        arr[end][sta]=distance;
    }
    int ssum=prim(arr,k,from);
    for(int i=1;i<k;i++)
    {
        edges[i-1].from=i;
        edges[i-1].to=from[i];
    }
    for(int i=0;i<k-1;i++)
    {
        if(edges[i].from>edges[i].to) 
        {
            int temp=edges[i].from;
            edges[i].from=edges[i].to;
            edges[i].to=temp;
        }
    }
    qsort(edges,k-1,sizeof(edge),cmp);
    for(int i=0;i<k-1;i++)
    {
        printf("(%s %s)",name[edges[i].from],name[edges[i].to]);
    }
    printf("\n%d\n",ssum);
}
//(W1 W2)(W1 W4)(W2 W3)(W4 W5)(W4 W7)(W6 W7)