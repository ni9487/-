#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#undef None

typedef struct Node{
    char name[20];
    double weight;
    int value;
    double cp;
    struct Node*next;
}Node;

Node *head=NULL;

void append(char namein[],int valuein,double weightin)
{
    Node *new=(Node*)malloc(sizeof(Node));
    strcpy(new->name,namein);
    new->weight=weightin;
    new->value=valuein;
    new->cp=(double)valuein/weightin;
    new->next=NULL;
    if(head==NULL)
    {
        head=new;
        return;
    }
    Node *last=head;
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=new;
}

void swap(Node*a,Node*b) 
{
    char tempName[20];
    double tempWeight;
    int tempValue;
    double tempCp;

    strcpy(tempName,a->name);
    strcpy(a->name,b->name);
    strcpy(b->name,tempName);

    tempWeight = a->weight;
    a->weight = b->weight;
    b->weight = tempWeight;

    tempValue = a->value;
    a->value = b->value;
    b->value = tempValue;

    tempCp = a->cp;
    a->cp = b->cp;
    b->cp = tempCp;
}

void sort()
{
    Node*ptr=head;
    if (ptr==NULL) 
    {   //若串列為空，則不排序
        return;
    }
    Node*nextNode=NULL;

    int swapped=0;
    do  //利用冒泡排序使節點內值不停交換，直到由小到大排好
    {
        swapped=0;
        ptr=head;
        while(ptr->next!=nextNode)
        {
            if(ptr->cp < ptr->next->cp||((ptr->cp == ptr->next->cp)&&(strcmp(ptr->name,ptr->next->name)<0)))
            {
                swap(ptr,ptr->next);
                swapped=1;
            }
            ptr=ptr->next;
        }
        nextNode=ptr;
    }
    while(swapped!=0);//完全沒人交換就停
}

int main() {
    char name[20];
    int value;
    double weight;
    double totalweight=0;

    int cntNode=0;
    while (scanf("%s %d %lf",name,&value,&weight) != EOF) 
    {
        getchar();
        if(weight>20)
        {
            continue;
        }
        double cpnow=(double)value/weight;
        totalweight+=weight;
        if(totalweight<=20)
        {
            append(name,value,weight);
            cntNode++;
            sort();
            continue;
        }

        append(name,value,weight);
        cntNode++;
        sort();
        while(1)
        {
            Node*ptr=head;
            Node*pre=NULL;
            while(ptr->next!=NULL)
            {
                pre=ptr;
                ptr=ptr->next;
            }
            if(cpnow>=ptr->cp&&totalweight>20)//>or>=
            {
                totalweight-=ptr->weight;
                if(pre!=NULL)
                {
                    pre->next=NULL;
                }
                free(ptr);
                cntNode--;
            }
            else
            { 
                break;
            }
        }
    }
    sort();
    int totalvalue=0;
    Node*ptr=head;
    char reverse[cntNode][11];
    int cnt=0;
    while(ptr->next!=NULL)
    {
        totalvalue+=ptr->value;
        strcpy(reverse[cntNode-cnt-1],ptr->name);
        ptr=ptr->next;
        cnt++;
    }
    strcpy(reverse[0],ptr->name);
    totalvalue+=ptr->value;
    for(int i=0;i<cntNode-1;i++)
    {
        printf("%s ",reverse[i]);
    }
    printf("%s\n",reverse[cntNode-1]);
    printf("total weight:%.2f\n",totalweight);
    printf("total value:%d\n",totalvalue);
    
    Node *cur=head;
    Node *next;
    while(cur!=NULL)
    {
        next=cur->next;
        free(cur);
        cur=next;
    }
    return 0;
}