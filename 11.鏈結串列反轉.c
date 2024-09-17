#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    int n;
    struct node*next;
}node;

node *head=NULL;

void append(int data)
{
    node *new=(node*)malloc(sizeof(node));
    new->n=data;
    new->next=NULL;
    if(head==NULL)
    {
        head=new;
        return;
    }
    node *last=head;
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=new;
}

void reverse() 
{
    node*prev=NULL;
    node*current=head;
    node*next=NULL;

    while(current != NULL) 
    {
        next=current->next;  
        current->next=prev;  
        prev=current;        
        current=next;       
    }

    head=prev; 
}

void print()
{
    node *ptr=head;
    while(ptr!=NULL)
    {
        printf("%d",ptr->n);
        if(ptr->next!=NULL)
        {
            printf(" ");
        }
        ptr=ptr->next;
    }
    printf("\n");
}


int main() {
    int value=0;
    while (scanf("%d",&value) != EOF) 
    {
        append(value);
    }
    reverse();
    print();
    return 0;
}

