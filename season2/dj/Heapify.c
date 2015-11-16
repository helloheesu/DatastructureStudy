#include <stdio.h>
#include <stdlib.h>


void buildHeap(int arr[], int size)
{
    int i = size/2;
    while(i > 0) 
        heapify(arr, size, i--);
}


void heapify(int arr[], int size,  int id)
{
    
    int childLeft = 0, childRight = 0;
    int MAXIdx = id;
   
    if(arr[2*id])
        leftChild = 2*id;
    if(arr[2*id + 1])
        rightChild = 2*id + 1;
    if(arr[childLeft] > arr[id])
        MAXIdx = leftChild;
    if(arr[childRight] > arr[largest])
        MAXIdx = rightChild;

    if(MAXIdx != id)
    {
        swap(arr, id, MAXIdx);
        heapify(arr, size, id);
    }
    
}

void swap(int *arr, int id, int MAXIndex)
{
    int temp = arr[id];
    arr[id] = arr[MAXIndex];
    arr[MAXIndex] = temp;
}


int main(int argc, char *argv[])
{
    int heapArr[] = {0, 1, 2, 3, 4, 5, 6 , 7, 8 ,9 ,10 , 11, 12, 13 ,14 ,15};
    int size = sizeof(heapArr)/sizeof(int);
    
    buildHeap(heapArr, size);
}

