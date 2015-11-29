//
//  buildMaxHeap.c
//  ds&al
//
//  Created by Kate KyuWon on 11/29/15.
//  Copyright © 2015 KateKyuwon. All rights reserved.
//

#include "buildMaxHeap.h"

void buildMaxHeap(heap_t *root){
    if(!root || root->size <=0 ) return;
    int startPoint = root->size / 2;
    
    for(int subrootIdx = startPoint ; subrootIdx > 0; subrootIdx--){
        max_heapify(root, subrootIdx);
    }
}

void testMaxHeap(heap_t* heap){
    puts("\n<BEFORE Max-heap>");
    printHeap(heap);
    buildMaxHeap(heap);
    
    puts("<AFTER Max-heap>");
    int result = isMaxHeap(heap, 1);
    if(result<0) printf("Wrong input.\n");
    else if(result) printf("Turned into MAX-HEAP\n");
    else printf("NOT MAX-HEAP\n");
    printHeap(heap);
    puts("=================\n");
    
    return;
}




