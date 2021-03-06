//
//  main.c
//  queue
//
//  Created by Kate KyuWon on 7/22/15.
//  Copyright (c) 2015 Kate KyuWon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


//circular queue

#define boolean int
#define true 1
#define false 0

int MAXLENGTH = 1;

//처음에 front 와 rear를 -1로 초기화하고 풀었을 때, 오류가 났다.
int front = 0;
int rear = 0;

int* creatQueue(int MAXLENGTH);
void enqueue(int* queue,int data);
boolean isFullQueue();
void fullQueue(void);
int dequeue(int* queue);
boolean isEmptyQueue();



int* creatQueue(int userMAX){
    
    //처음에 circular queue 중 사용하지 않는 하나의 공간을 생각하지 못해서 오류가 났다.
    MAXLENGTH = userMAX + 1;
    return (int*)malloc( sizeof(int) * MAXLENGTH );
}

void enqueue(int* queue,int data){
    if(!isFullQueue()){
        ++rear;
        rear = rear % MAXLENGTH;
        printf("rear: %d\n", rear);
        queue[rear] = data;
    }
    else{
        fullQueue();
        return ;
    }
}

boolean isFullQueue(){
    if( (rear + 1) % MAXLENGTH == front )
        return  true;
    else
        return false;
}

void fullQueue(void){
    printf("\nThe queue is full");
    return;
}

int dequeue(int* queue){
    if(!isEmptyQueue()){
        front = (front +1) % MAXLENGTH;
        return queue[front];
    }
    else{
        printf("There is no data in a queue");
        return (int)NULL;
    }
}

boolean isEmptyQueue(){
    if(rear == front)
        return true;
    else
        return false;
}

void printQueue(int* queue){
    int i = (front + 1) % MAXLENGTH;
    
 
    //rear가 제일 끝에 있을 때, 두번째 조건(i != front)이 없으면 무한루프를 돈다.
    while(i <= rear && i != front) {
        printf("%3d", queue[i]);
        
        ++i;
        i = i % MAXLENGTH;
    }
    
    printf("\n");
    
    return ;
}


int main(int argc, const char * argv[]) {
    
    int* queue = creatQueue(4);
    enqueue(queue, 1);
    printQueue(queue);
    enqueue(queue, 2);
    printQueue(queue);
    enqueue(queue, 3);
    printQueue(queue);
    enqueue(queue, 4);
    printQueue(queue);
    enqueue(queue, 5);
    printQueue(queue);
    
    printf("%2d is out.\n", dequeue(queue));
    printQueue(queue);
    printf("%2d is out.\n", dequeue(queue));
    printQueue(queue);
    printf("%2d is out.\n", dequeue(queue));
    printQueue(queue);
    printf("%2d is out.\n", dequeue(queue));
    printQueue(queue);
    printf("%2d is out.\n", dequeue(queue));
    printQueue(queue);


    

      return 0;
}
