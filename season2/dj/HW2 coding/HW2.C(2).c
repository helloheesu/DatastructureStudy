#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef enum {false, true} bool;
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

void buildMaxHeap(heap_t *heap)
{
    
    if(heap == NULL || heap->element == NULL)
        return;
    
    int i;
    int size;
    
    size = heap->size;
    
    for(i=size/2; i > 0; i--)
    {
        maxHeapify(heap, i);
    }
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

int* HeapSort(heap_t* heap, int size)
{
   
    if(heap == NULL || heap ->element == NULL || size < 0)
        return NULL;
    
    int i;
    int* array = (int*)malloc(size * sizeof(int));
    
    buildMaxHeap(heap);
    for(i = size; i > 0; i--)
    {
        array[i-1] = heap->element[1];
        swap(&heap->element[i], &heap->element[1]);
        heap->size = heap->size -1;
        maxHeapify(heap, 1);
    }
    return array;
}


int heapExtractMaximum(heap_t* heap, int* maxvalue)
{
    
    if(heap == NULL || heap->element == NULL)
        return 0;
    
    if(heap->size < 1)
        return 0;
    *maxvalue = heap->element[1];
    heap->element[1] = heap->element[heap->size];
    
    
    heap->size = heap->size-1;
    maxHeapify(heap, 1);
    
    return 1;
}


void heapIncreaseKey(heap_t* heap, int i, int key)
{

    if(heap == NULL || heap->element == NULL)
        return;
    
    if(heap->element[i]>key)
        return;
    
    heap->element[i] = key;
    
    while(i>1 && heap->element[i/2] < heap->element[i])
    {
        swap(&heap->element[i/2], &heap->element[i]);
        i/=2;
    }
}


void maxHeapInsert(heap_t* heap, int key)
{

    if(heap == NULL || heap->element == NULL || key < 0)
        return;
    
    heap->size = heap->size + 1;
    heap->element[heap->size] = INT_MIN;
    heapIncreaseKey(heap, heap->size, key);
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


bool isSorted(int *array, int size)
{

    if(array == NULL || size < 0)
        return false;
    
    int i;
    for(i=1; i < size-1; i++)
    {
        if(array[i-1] > array[i])
        {
            return false;
        }
    }
    return true;
}

void printArray(int* array, int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}


int main(void)
{
    int NumOfNode;
    int* sortedArray;
    int MaxValue;
    
    heap_t* heap;
    
    NumOfNode = 10;
    
    
    //-----Build MaxHeap------------------------------------------------------
    heap = makeSampleHeap(NumOfNode);
    printf("sample array:  ");
    printHeap(heap);
    printf("build_max_heap srart\n");
    buildMaxHeap(heap);
    printf("result: ");
    printHeap(heap);
    printf("maxHeap check: %s ", (isMaxHeap(heap)) ? "ok" : "wrong");
    printf("\n\n--------------------------------\n\n");
    free(heap);
    
    //-----HeapSort------------------------------------------------------
    int testArr[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    printf("input array: ");
    printArray(testArr, 10);
    printf("\nHeapSort start\n");
    sortedArray = HeapSort(heap, NumOfNode);
    printf("result: ");
    printArray(sortedArray, NumOfNode);
    printf("\n%s ", (isSorted(sortedArray, sizeof(sortedArray))) ? "sorting check ok" : "unsorted");
    printf("\n\n--------------------------------\n\n");
    free(sortedArray);
    
    //-----heapExtractMaximum-----------------------------------------------------
    
    heap = makeSampleHeap(NumOfNode);
    buildMaxHeap(heap);
    printf("sample array:  ");
    printHeap(heap);
    printf("extract Maximum start\n");
    (heapExtractMaximum(heap, &MaxValue)) ? : perror("heapExtractMaximum error");
    printf("result: %d \n", MaxValue);
    printf("\n--------------------------------\n\n");
    free(heap);
    
    //-----Heap Insertion-----------------------------------------------------
    
    heap = makeSampleHeap(NumOfNode-1);
    buildMaxHeap(heap);
    printf("sample array:  ");
    printHeap(heap);
    printf("input value 32 node\n");
    maxHeapInsert(heap, 32);
    printf("result: ");
    printHeap(heap);
    free(heap);
    
}