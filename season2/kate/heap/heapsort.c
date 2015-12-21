//
//  heapsort.c
//  ds&al
//
//  Created by Kate KyuWon on 11/29/15.
//  Copyright © 2015 KateKyuwon. All rights reserved.
//

#include "heapsort.h"

void testHeapSort(int *arr, int arrSize){
    puts("\n<BEFORE Heapsort>");
    printArray(arr, arrSize);
    puts("<AFTER Heapsort>");
    heapSort(arr, arrSize);
    printArray(arr, arrSize);
    
    int isSortedResult = isSorted(arr, arrSize);
    printf("The result is ");
    if(isSortedResult == 1) printf("sorted.\n");
    else printf("NOT sorted.\n");
    puts("=================\n");
    
    return;
    
}

void heapSort(int* arr, int arrSize){
    if(!arr) return;
    
    heap_t *tempHeap = heapAlloc(arrSize);
    
    for(int i = 0; i<arrSize; i++)
        tempHeap->element[i+1] = arr[i];
    tempHeap->size = arrSize;
    
    buildMaxHeap(tempHeap);
    
    for(int i = (tempHeap->size); i>1; i--){
        swapInHeap(tempHeap, i, 1);
        tempHeap->size = (tempHeap->size) - 1;
        max_heapify(tempHeap, 1);
    }
    
    for(int i = 0; i<arrSize; i++)
        arr[i] = tempHeap->element[i+1] ;
}


