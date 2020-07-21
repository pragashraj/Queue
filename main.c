#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 5
 typedef struct queue{
    int data[CAPACITY];
    int front;
    int rear;
    int count;
 }queue;

 typedef enum {true,false} boolean;

 void create_queue(queue *q){
    q->front=0;
    q->rear=-1;
    q->count=0;
 }

 boolean is_queue_empty(queue *q){
    return (q->count==0);
 }

 boolean is_queue_full(queue *q){
    return (q->count==CAPACITY);
 }


 void insert_Data(queue *q , int element){
    if(is_queue_full(q)){
        printf("already full");
    }
    else{
        q->data[++q->rear]=element;
        q->count++;
    }
 }


 void remove_Data(queue *q){
    if(is_queue_empty(q)){
        printf("already empty");
    }
    else{
        int *element=q->data[q->front];
        q->front++;
        q->count--;
        free(element);
    }
 }


 void display(queue *q){
    if(is_queue_empty(q)){
        printf("No data to display");
    }
    else{
        int i;
        for(i=q->front;i<=q->rear;i++){
            printf("%d\t",q->data[i]);
        }
        printf("\n");
    }
}

int main()
{
    queue q;
    create_queue(&q);
    insert_Data(&q,10);
    insert_Data(&q,20);
    insert_Data(&q,30);
    display(&q);

    remove_Data(&q);
    display(&q);

    insert_Data(&q,40);
    display(&q);

    return 0;
}







