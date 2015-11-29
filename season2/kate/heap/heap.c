//
//  heap.c
//  ds&al
//
//  Created by Kate KyuWon on 11/29/15.
//  Copyright © 2015 KateKyuwon. All rights reserved.
//

#include "heap.h"

heap_t* makeSampleHeap(int n){
    
    heap_t *root = (heap_t*)malloc(sizeof(heap_t));
    root->element = (int*)malloc(sizeof(int)* (n+1));
    root->element[0] = '\0';
    root->size = n;
    
    return root;
}

/*
 * isMaxHeap
 * check whether it is a max-heap
 * return true if it's a max-heap, false when it's not
 * and -1, input heap doesn't exist
 */
int isMaxHeap(heap_t* heap, int pos){
    if(!heap){
        return -1;
    }
    
    int left = pos * 2;
    int right = left + 1;
    
    if( left > heap->size ) return true;
    if( heap->element[left] > heap->element[pos]) return false;
    if( right <= heap-> size ) {
        if( heap->element[right] > heap->element[pos]) return false;
        
        isMaxHeap(heap, right);
    }
    
    isMaxHeap(heap, left);
    
    return true;
}


void printHeap(heap_t* heap){
    if(!heap || heap->size < 1){
        printf("Wrong input for printing.\n");
        return;
    }
    int totalLevel = (int)log2(heap->size) + 1;
    int i=0, j=0;
    
    for(i = 1; i < totalLevel; i++){
        printf("[level %d]", i);
        int endIdx = (int)pow(2,i);
        for(j = i; j < endIdx; j++){
            printf("%4d", heap->element[j]);
        }
        printf("\n");
    }
    if(totalLevel > 1){
        printf("[level %d]", totalLevel);
        for(;j <= heap->size; j++){
            printf("%4d", heap->element[j]);
        }
    }else if(totalLevel == 1){
        printf("[level %d]", 1);
        printf("%4d", heap->element[1]);
    }
    printf("\n");
    
    return;
}
