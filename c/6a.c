#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
};
struct Node* insertAtBeginning(struct Node* head,int value){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    if (newNode==NULL){
        printf("memory allocation failed");
        return head;
    }
    newNode->data=value;
    newNode->next=head;
    return newNode;
}  
struct Node* insertAtEnd(struct Node* head,int value){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    if (newNode==NULL){
        printf("memory allocation failed");
        return head;
    }
    newNode->data=value;
    newNode->next=NULL;
    
    if (head==NULL){
        return newNode;
    }

    struct Node*current=head;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=newNode;
    return newNode;
}
struct Node* deleteByValue(struct Node* head,int value){
    if (head==NULL){
        printf("list is empty cannot delete");
        return head;
    }
    if (head->data==value){
        struct Node*temp=head;
        head=head->next;
        free (temp);
        return head;
    }
     struct Node*current=head;
    while(current->next!=NULL && current->next->data!=value){
        current=current->next;
    }
    if (current->next==NULL){
        printf("value not found ");
        return head;
    }
    struct Node* temp=current->next;
    current->next=current->next->next;
    free (temp);
    return head;
}
void displayList(struct Node*head){
    printf("linked list:");
    struct Node*current=head;
    while(current!=NULL){
        current=current->next;
    }
    printf("NULL\n");
}
int main(){
    struct Node*head=NULL;
    int choice,value;
    while(1){
        printf("\nMenu:");
        printf("1.insert at beginning");
        printf("2.insert at end");
        printf("3.delete by value");
        printf("4. display");
        printf("5.exit");
        printf("Enter your choice");
        scanf("%d",&choice);
    
    switch(choice){
        case 1:
        printf("enter value to insert:");
        scanf("%d",&value);
        head=insertAtBeginning(head,value);
        break;
        case 2:
        printf("enter value to insert:");
        scanf("%d",&value);
        head=insertAtEnd(head,value);
        break;
         case 3:
        printf("enter value to delete:");
        scanf("%d",&value);
        head=deleteByValue(head,value);
        break;
        case 4:
        displayList(head);
        break;
        case 5 :
        while(head!=NULL){
            struct Node*temp=head;
            head=head->next;
            free(temp);
        }
          return 0;
        default:
        printf("invalid choice:");


    }
}
return 0;
}