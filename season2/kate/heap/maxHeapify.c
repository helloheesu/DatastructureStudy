//
//  maxHeapify.c
//  ds&al
//
//  Created by Kate KyuWon on 11/29/15.
//  Copyright © 2015 KateKyuwon. All rights reserved.
//

#include "maxHeapify.h"

void max_heapify(heap_t* heap, int pos){
    if(!heap) return;
    int maxIdx = pos;
    int leftIdx = 2 * pos;
    int rightIdx = leftIdx + 1;
    
    if(leftIdx <= heap->size){
        
        if(heap->element[leftIdx] > heap->element[maxIdx])
            maxIdx = leftIdx;
        
        if(rightIdx <= heap->size && heap->element[rightIdx] > heap->element[maxIdx])
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


void testHeapify(heap_t* heap){
    puts("\n<BEFORE Heapify>");
    printHeap(heap);
    max_heapify(heap, 1);
    
    puts("<AFTER Heapify>");
    int result = isMaxHeap(heap, 1);
    if(result<0) printf("Wrong input.\n");
    else if(result) printf("Turned into MAX-HEAP\n");
    else printf("NOT MAX-HEAP\n");
    printHeap(heap);
    puts("=================\n");
    
    return;
}


