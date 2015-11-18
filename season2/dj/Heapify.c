#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct heap {
    int size;
    int *element;
} heap_t;

typedef enum {false, true} bool;

void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void max_heapify(heap_t* heap, int pos)
{
    
    if(heap == NULL || heap->element == NULL || pos <= 0)
        return;
    
    int leftChild;
    int rightChild;
    int maxNode;
    
    leftChild = pos * 2;
    rightChild = pos * 2 + 1;
    
    if(leftChild <= heap->size && heap->element[leftChild] > heap->element[pos])
    {
        maxNode = leftChild;
    } else {
        maxNode = pos;
    }
    
    if(rightChild <= heap->size && heap->element[rightChild] > heap->element[maxNode])
    {
        maxNode = rightChild;
    }
    
    if(maxNode != pos)
    {
        swap(&heap->element[pos], &heap->element[maxNode]);
        max_heapify(heap, maxNode);
    }
}


void buildMaxHeap(heap_t *heap)
{
    if(heap == NULL || heap->element == NULL)
        return;
    
    int i;
    int size;
    
    size = heap->size;
    
    for(i=size/2; i > 0; i--)
    {
        max_heapify(heap, i);
    }
}


heap_t* makeSampleHeap(int numOfNode)
{
    // 예외처리
    if(numOfNode < 0)
        return NULL;
    
    int i=0;
    heap_t* heap;
    heap = (heap_t*)malloc(sizeof(heap_t));
    
    heap->size = numOfNode;
    heap->element = malloc((numOfNode + 1) * sizeof(int));
    
    heap->element[0] = INT_MIN;
    
    for(i = 1; i < numOfNode + 1; i++)
    {
        heap->element[i] = i;
    }
    return heap;
}


bool isMaxHeap(heap_t *heap)
{
    
    if(heap == NULL || heap->element == NULL)
        return true;
    
    int leftChild;
    int rightChild;
    int pos;
    int size;
    
    size = heap->size;
    
    for(pos = 1; pos < size + 1; pos++)
    {
        leftChild = 2 * pos;
        rightChild = 2 * pos + 1;
        
        if(leftChild <= heap->size && heap->element[leftChild] > heap->element[pos])
            return false;
        
        if(leftChild <= heap->size && heap->element[rightChild] > heap->element[pos])
            return false;
    }
    
    return true;
}

void printHeap(heap_t *heap)
{
    if(heap == NULL || heap->element == NULL)
        return;
    
    int i;
    int heapSize;
    
    heapSize = heap->size;
    
    for(i = 1; i < heapSize+1; i++)
    {
        printf("%d ", heap->element[i]);
    }
}



// main 함수
int main(void)
{
    int numOfNode;
    heap_t* heap;
    
    numOfNode = 10;
    
    heap = makeSampleHeap(numOfNode);
    printHeap(heap);
    printf("\n");
    buildMaxHeap(heap);
    printHeap(heap);
    printf("\n");
    printf("%s ", (isMaxHeap(heap)) ? "TRUE" : "FALSE");
    printf("\n");
    free(heap);

  
    
}




