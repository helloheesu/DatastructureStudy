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
#include <math.h>

typedef struct heap{
    int size;
    int *element;
}heap_t;

void max_heapify(heap_t* heap, int pos);
void swapInHeap(heap_t* heap, int a, int b);

heap_t* makeSampleHeap(int n);
int isMaxHeap(heap_t* heap, int pos);
void printHeap(heap_t* heap);
void testHeapify(heap_t* heap);

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
    
    heap_t *root3 = makeSampleHeap(3);
    root3->element[1] = 4;
    root3->element[2] = 5;
    root3->element[3] = 6;
    testHeapify(root3);
    
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
    
}

void testHeapify(heap_t* heap){
    puts("\n<BEFORE>");
    printHeap(heap);
    max_heapify(heap, 1);
    
    puts("<AFTER>");
    int result = isMaxHeap(heap, 1);
    if(result<0) printf("Wrong input.\n");
    else if(result) printf("Turned into MAX-HEAP\n");
    else printf("NOT MAX-HEAP\n");
    printHeap(heap);
    puts("=================\n");
    
    return;
}

void printHeap(heap_t* heap){
    if(!heap){
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

