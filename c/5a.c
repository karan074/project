#include <stdio.h> 
#include <stdlib.h> 

struct Node  
{ 
int data; 
struct Node* next; 
}; 
struct Queue  
{ 
struct Node* front; 
struct Node* rear;
}; 

struct Queue* createQueue()  
{ 
struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue)); 
queue->front = queue->rear = NULL; 
return queue; 
} 

int isEmpty(struct Queue* queue)  
{ 
return (queue->front == NULL); 
} 
  
void enqueue(struct Queue* queue, int data)  
{ 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = data; 
    newNode->next = NULL; 
     
    if (isEmpty(queue))  
    { 
        queue->front = queue->rear = newNode; 
    } 
    else  
    { 
        queue->rear->next = newNode; 
        queue->rear = newNode; 
    } 
} 
 
int dequeue(struct Queue* queue)  
{ 
    if (isEmpty(queue))  
    { 
        printf("Queue underflow: Cannot dequeue from an empty queue.\n"); 
        return -1;
    } 
     
    struct Node* temp = queue->front; 
    int data = temp->data; 
    queue->front = queue->front->next; 
     
    free(temp); 
     
    return data; 
} 
 
void display(struct Queue* queue)  
{ 
    if (isEmpty(queue))  
    { 
        printf("Queue is empty.\n"); 
        return; 
    } 
     
    struct Node* current = queue->front; 
    printf("Queue elements: "); 
     
    while (current != NULL)  
    { 
        printf("%d ", current->data); 
        current = current->next; 
    } 
    printf("\n"); 
} 
int main()  
{ 
struct Queue* queue = createQueue(); 
enqueue(queue, 10); 
enqueue(queue, 20); 
enqueue(queue, 30); 
display(queue); 
printf("Dequeued element: %d\n", dequeue(queue)); 
display(queue); 
printf("Is the queue empty? %s\n", isEmpty(queue) ? "Yes" : "No"); 
return 0;
}