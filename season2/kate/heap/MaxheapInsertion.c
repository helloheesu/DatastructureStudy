//
//  MaxheapInsertion.c
//  ds&al
//
//  Created by Kate KyuWon on 11/29/15.
//  Copyright © 2015 KateKyuwon. All rights reserved.
//

#include "MaxheapInsertion.h"
#include "maxHeapify.h"

void increaseMaxHeapKey(heap_t* heap, int index, int keyIncreased){
    if(!heap || heap->size < 1) return;
    
    if(keyIncreased < heap->element[index]) return;
    
    heap->element[index] = keyIncreased;
    
    int parentIndex = index / 2;
    while(parentIndex > 0 && heap->element[index] > heap->element[parentIndex]){
        swapInHeap(heap, index, parentIndex);
        index = parentIndex;
        parentIndex = index / 2;
    }
    
};
heap_t* insertInMaxheap(heap_t* heap, int key){
    if(!heap) return NULL;
    
    heap_t *newHeap = heapAlloc(heap->size + 1);
    
    for(int i = 1; i <= heap->size; i++)
        newHeap->element[i] = heap->element[i];
    
    newHeap->element[newHeap->size] = key - 1;
    
    increaseMaxHeapKey(newHeap, newHeap->size, key);
    
    heap_t *temp = heap;
    heap = newHeap;
   
    free(temp->element);
    free(temp);
    
    return heap;
}

heap_t* testInsertInMaxHeap(heap_t* heap, int key){
    
    puts("\n<BEFORE Insertion>");
    printHeap(heap);
    heap = insertInMaxheap(heap, key);
    
    puts("<AFTER Insertion>");
    int result = isMaxHeap(heap, 1);
    if(result<0) printf("Wrong input.\n");
    else if(result) printf("Still MAX-HEAP\n");
    else printf("NOT MAX-HEAP\n");
    printHeap(heap);
    puts("=================\n");
    
    return heap;
}