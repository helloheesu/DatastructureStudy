//
//  main.c
//  stack
//
//  Created by Kate KyuWon on 7/13/15.
//  Copyright (c) 2015 Kate KyuWon. All rights reserved.
//
#include <stdio.h>
#include<stdlib.h>
//Stack ADT
#define boolean int
int top = -1;
int maxLength = 1;


boolean isFull();
boolean isEmpty();

int* CreatStack(int userInputNum){
    maxLength = userInputNum;
    int* ptr = (int*) malloc(sizeof(int)*maxLength);
    return  ptr;
}

void Push(int* arr, int new){
    if(isFull()){
        printf("There is no room for another new data.\n");
        return;
    }
    arr[++top] = new;
}

boolean isFull(){
   // printf("top: %2d maxLength: %2d\n", top, maxLength);
    if (top>=maxLength-1) return 1;
    else return 0;
}

int Pop(int* arr){
    if(isEmpty()){
        printf("There is no data to print.\n");
        return (int)NULL;
    }
    return arr[top--];
}

boolean isEmpty(){
    if (top<=-1) return 1;
    else return 0;
}

void printArray(int* arr){
    int i = 0;
    for(i=0; i <maxLength; i++){
        printf("%3d", arr[i]);
    }
}


int main(void) {
    int* arr= CreatStack(4);
    Push(arr, 1);
    Push(arr, 2);
    Push(arr, 3);
    Push(arr, 4);
    Push(arr, 5);
    
    printArray(arr);
    
    printf("\npop: %3d\n", Pop(arr));
    printf("pop: %3d\n", Pop(arr));
    printf("pop: %3d\n", Pop(arr));
    printf("pop: %3d\n", Pop(arr));
    printf("pop: %3d\n", Pop(arr));
    
    printArray(arr);
    
    return 0;
}
