//
//  kate_draft.c
//  ds&al
//
//  Created by Kate KyuWon on 11/16/15.
//  Copyright © 2015 KateKyuwon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "checkArraySort.h"

#include "heap.h"
#include "maxHeapify.h"
#include "buildMaxHeap.h"
#include "heapsort.h"
#include "extractMaxInHeap.h"
#include "MaxheapInsertion.h"

int main(){
    heap_t *root0 = NULL;
    testHeapify(root0);
    
    heap_t *root1 = makeSampleHeap(1);
    root1->element[1] = 1;
    testHeapify(root1);
    
    heap_t *root2 = makeSampleHeap(2);
    root2->element[1] = 2;
    root2->element[2] = 1;
    testHeapify(root2);
  
    heap_t *root22 = makeSampleHeap(2);
    root22->element[1] = 2;
    root22->element[2] = 3;
    testHeapify(root22);
    root22 = testInsertInMaxHeap(root22, 4);
 
    heap_t *root3 = makeSampleHeap(3);
    root3->element[1] = 4;
    root3->element[2] = 5;
    root3->element[3] = 6;
    testHeapify(root3);
    root3 = testInsertInMaxHeap(root3, 3);
    root3 = testInsertInMaxHeap(root3, 10);
    root3 = testInsertInMaxHeap(root3, 2);
    
    heap_t *root32 = makeSampleHeap(3);
    root32->element[1] = 8;
    root32->element[2] = 9;
    root32->element[3] = 7;
    testHeapify(root32);
    
    heap_t *root33 = makeSampleHeap(3);
    root33->element[1] = 12;
    root33->element[2] = 10;
    root33->element[3] = 11;
    testHeapify(root33);
    
    heap_t *root4 = makeSampleHeap(4);
    root4->element[1] = 13;
    root4->element[2] = 16;
    root4->element[3] = 15;
    root4->element[4] = 14;
    testHeapify(root4);
    
    heap_t *maxHeap0 = NULL;
    testMaxHeap(maxHeap0);
    testExtractMax(maxHeap0);
    
    heap_t *maxHeap1 = makeSampleHeap(1);
    maxHeap1->element[1] = 1;
    testMaxHeap(maxHeap1);
    testExtractMax(maxHeap1);
    
    heap_t *maxHeap2 = makeSampleHeap(2);
    maxHeap2->element[1] = 2;
    maxHeap2->element[2] = 3;
    testMaxHeap(maxHeap2);
    testExtractMax(maxHeap2);
    
    heap_t *maxHeap3 = makeSampleHeap(3);
    maxHeap3->element[1] = 5;
    maxHeap3->element[2] = 4;
    maxHeap3->element[3] = 6;
    testMaxHeap(maxHeap3);
    testExtractMax(maxHeap3);
    testExtractMax(maxHeap3);
    
    heap_t *maxHeap4 = makeSampleHeap(4);
    maxHeap4->element[1] = 8;
    maxHeap4->element[2] = 7;
    maxHeap4->element[3] = 9;
    maxHeap4->element[4] = 10;
    testMaxHeap(maxHeap4);
    testExtractMax(maxHeap4);
    testExtractMax(maxHeap4);
    testExtractMax(maxHeap4);
    testExtractMax(maxHeap4);
    testExtractMax(maxHeap4);
    
    
    int *arr0 = NULL;
    testHeapSort(arr0, sizeof(arr0)/sizeof(int));
    
    int arr1[] = {3};
    testHeapSort(arr1, sizeof(arr1)/sizeof(int));
    
    int arr21[] = {4, 2};
    testHeapSort(arr21, sizeof(arr21)/sizeof(int));
    
    int arr22[] = {5, 6};
    testHeapSort(arr22, sizeof(arr22)/sizeof(int));
    
    int arr31[] = {9, 7, 8};
    testHeapSort(arr31, sizeof(arr31)/sizeof(int));
    
    int arr32[] = {10, 12, 11};
    testHeapSort(arr32, sizeof(arr32)/sizeof(int));
    
    int arr33[] = {13, 14, 15};
    testHeapSort(arr33, sizeof(arr33)/sizeof(int));
    
}

