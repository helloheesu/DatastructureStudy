//
//  MaxheapInsertion.h
//  ds&al
//
//  Created by Kate KyuWon on 11/29/15.
//  Copyright © 2015 KateKyuwon. All rights reserved.
//

#ifndef MaxheapInsertion_h
#define MaxheapInsertion_h

#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

void increaseMaxHeapKey(heap_t* heap, int index,int keyIncreased);
heap_t* insertInMaxheap(heap_t* heap, int key);
heap_t* testInsertInMaxHeap(heap_t* heap, int key);


#endif /* MaxheapInsertion_h */
