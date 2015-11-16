//
//  kate_draft.c
//  ds&al
//
//  Created by Kate KyuWon on 11/16/15.
//  Copyright © 2015 KateKyuwon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct heap{
    int size;
    int *element;
}heap_t;

void max_heapify(heap_t* heap, int pos);
void swapInHeap(heap_t* heap, int a, int b);

heap_t* makeSampleHeap(int n);
int isMaxHeap(heap_t* heap, int pos);
void printHeap(heap_t* heap);

int main(){
    heap_t *root0 = NULL;
    
    
}

heap_t* makeSampleHeap(int n){
    heap_t *root = (heap_t*)malloc(sizeof(heap_t));
    root->element = (int*)malloc(sizeof(int)*n);
    root->element[0] = '\0';
    root->size = n;
    return root;
}

int isMaxHeap(heap_t* heap, int pos){
    if(!heap){
        printf("NO node.\n");
        return -1;
    }
    
    int needOneMoreTimeForLeft = false;
    int needOneMoreTimeForRight = false;
    int left = pos * 2;
    int right = left +1;
    
    if( left > heap->size ) return 1;
    if( left <= heap-> size ) {
        if( heap->element[left] > heap->element[pos]) return 0;
        needOneMoreTimeForLeft = true;
    }
    if( right <= heap-> size ) {
        if( heap->element[right] > heap->element[pos]) return 0;
        needOneMoreTimeForRight = true;
    }
    
    if(needOneMoreTimeForRight){
        isMaxHeap(heap, right);
        isMaxHeap(heap, left);
    }else if(needOneMoreTimeForLeft){
        isMaxHeap(heap, left);
    }
        
    return 1;
}

void max_heapify(heap_t* heap, int pos){
    if(!heap) return;
    int maxIdx = pos;
    int leftIdx = 2 * pos;
    int rightIdx = leftIdx + 1;
    
    if(leftIdx <= heap->size){
        maxIdx = leftIdx;
        
        if(rightIdx <= heap->size && heap->element[rightIdx] > heap->element[pos])
            maxIdx = rightIdx;
    }
    
    if(maxIdx != pos){
        swapInHeap(heap, pos, maxIdx);
        max_heapify(heap, maxIdx);
    }
    return;
}

void swapInHeap(heap_t* heap, int a, int b){
    int temp = heap->element[a];
    heap->element[a] = heap->element[b];
    heap->element[b] = temp;
    return;
}

