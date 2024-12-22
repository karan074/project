#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}
struct Node *head=NULL
void insert(int rawdata)
{
    struct Node *newnode;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=rawdata;
    newnode->next=NULL;
    if (head==NULL)
    {
        head=newnode;
    }
    else
    {
        struct Node *temp=head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
int main()
{
    insert(10);
}