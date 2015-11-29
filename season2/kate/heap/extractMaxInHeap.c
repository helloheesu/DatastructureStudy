//
//  extractMaxInHeap.c
//  ds&al
//
//  Created by Kate KyuWon on 11/29/15.
//  Copyright © 2015 KateKyuwon. All rights reserved.
//

#include "extractMaxInHeap.h"

void testExtractMax(heap_t* heap){
    if(!heap) return;
    
    int *maxValue = (int*)calloc(1,sizeof(int));
    int result = 0;
    
    result = extractMax(heap, maxValue);
    
    if(result > 0){
        printf("\nThe maximum value extracted is %d.\nThe result heap is like\n", *maxValue);
        printHeap(heap);
        
    }else{
        printf("\nExtraction of the maximun value in the heap is failed.\n");
    }
}

int extractMax(heap_t* heap, int* maxValue){
    if(!heap || heap->size < 1) return -1;
    *maxValue = heap->element[1];
    
    swapInHeap(heap, heap->size, 1);
    heap->size = heap->size - 1;
    max_heapify(heap, 1);
    
    return 1;
}

