#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct heap {
    int size;
    int capacity;
    int *element;
} heap_t;

void swap(int* a, int* b)
{
    if(a == NULL || b == NULL)
        return;
    
    int temp;
    
    temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(heap_t* heap, int position)
{
    
    if(heap == NULL || heap->element == NULL || position <= 0)
        return;
    
    int leftChild;
    int rightChild;
    int largest;
    
    leftChild = position * 2;
    rightChild = position * 2 + 1;
    
    if(leftChild <= heap->size && heap->element[leftChild] > heap->element[position])
    {
        largest = leftChild;
    } else {
        largest = position;
    }
    
    if(rightChild <= heap->size && heap->element[rightChild] > heap->element[largest])
    {
        largest = rightChild;
    }
    
    if(largest != position)
    {
        swap(&heap->element[position], &heap->element[largest]);
        maxHeapify(heap, largest);
    }
}

int isMaxHeap(heap_t *heap)
{
    if(heap == NULL || heap->element == NULL)
        return 1;
    
    int leftChild;
    int rightChild;
    int position;
    
    
    for(position = 1; position < heap->size/2; position++)
    {
        leftChild = 2 * position;
        rightChild = 2 * position + 1;
        
        if(leftChild <= heap->size && heap->element[leftChild] > heap->element[position])
            return 0;
        
        if(leftChild <= heap->size && heap->element[rightChild] > heap->element[position])
            return 0;
    }
    
    return 1;
}

heap_t* makeSampleHeap(int numOfNode)
{
  
    if(numOfNode < 0)
        return NULL;
    
    int i=0;
    int num;
    heap_t* heap;
    heap = malloc(sizeof(heap_t));
    
    heap->size = numOfNode;
    heap->capacity = numOfNode;
    heap->element = malloc((numOfNode) * sizeof(int));
    
    for(i = 1; i <= numOfNode; i++)
    {
        num = rand()%30+1;
        heap->element[i] = num;
    }
    
    for(i=heap->size/2; i>0; i--)
    {
        maxHeapify(heap, i);
    }
    
    return heap;
}

void printHeap(heap_t *heap)
{
    
    if(heap == NULL || heap->element == NULL)
        return;
    
    int i;
    
    for(i = 1; i <= heap->size; i++)
    {
        printf("%d ", heap->element[i]);
    }
    printf("\n");
}

int main(void)
{
    int i;
    heap_t *sampleHeap;
    
    for(i=0; i<10; i++)
    {
        sampleHeap=makeSampleHeap(rand()%10+1);
        printf("\n");
        printHeap(sampleHeap);
        printf("MaxHeap Check: %s\n", isMaxHeap(sampleHeap) ? "Maxheap ok" : "This is not Maxheap");
        free(sampleHeap);
    }
    
    return 0;
}