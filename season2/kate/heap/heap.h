//
//  heap.h
//  ds&al
//
//  Created by Kate KyuWon on 11/29/15.
//  Copyright © 2015 KateKyuwon. All rights reserved.
//

#ifndef heap_h
#define heap_h

#include <math.h>
#include <stdbool.h>

typedef struct heap{
    int size;
    int *element;
}heap_t;

heap_t* makeSampleHeap(int n);
int isMaxHeap(heap_t* heap, int pos);
void printHeap(heap_t* heap);


#endif /* heap_h */
