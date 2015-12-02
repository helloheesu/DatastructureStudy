//
//  checkArraySort.c
//  ds&al
//
//  Created by Kate KyuWon on 11/29/15.
//  Copyright © 2015 KateKyuwon. All rights reserved.
//

#include "checkArraySort.h"


void printArray(int* arr,int arrlen){
    if(!arr || arrlen == 0){
        printf("No Array Input to be printed.\n");
        return;
    }
    int i = 0;
    
    for(i = 0; i<arrlen; i++){
        printf("%5d", arr[i]);
    }
    puts(" ");
}

int isSorted(int* arr, int arrlen){
    if(!arr || arrlen == 0){
        printf("No Array Input to check.\n");
        return -1;
    }
    int isSorted = 1;
    int i =0;
    
    for(i = 0 ; i < arrlen-1 ; i++){
        if( arr[i] > arr[i+1]) isSorted = 0;
    }
    
    return isSorted;
}