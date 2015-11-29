//
//  maxHeapify.h
//  ds&al
//
//  Created by Kate KyuWon on 11/29/15.
//  Copyright © 2015 KateKyuwon. All rights reserved.
//

#ifndef maxHeapify_h
#define maxHeapify_h

#include <stdio.h>
#include "heap.h"

void max_heapify(heap_t* heap, int pos);
void swapInHeap(heap_t* heap, int a, int b);
void testHeapify(heap_t* heap);


#endif /* maxHeapify_h */
