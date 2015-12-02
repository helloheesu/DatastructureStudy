#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

int partition(int *arr, int start, int end){
    
    int pivot, endOfLow, posBeChecked;
    
    if(arr==NULL || end-start<=0)
        return -1;
    
    pivot=arr[end];
    endOfLow=start-1;
    
    for (posBeChecked=start; posBeChecked<end; posBeChecked++){
        if (arr[posBeChecked]<=pivot){
            endOfLow++;
            swap(&arr[endOfLow], &arr[posBeChecked]);
        }
    }
    swap(&arr[endOfLow+1], &arr[end]);
    
    return endOfLow+1;
}

void quickSort(int *arr, int start, int end){
    
    int posPivot;
    
    if (start<end){
        posPivot=partition(arr, start, end);
        quickSort(arr, start, posPivot-1);
        quickSort(arr, posPivot+1, end);
    }
    
    return;
}

int checkQuickSort(int *arr, int size){
    int i;
    
    for(i=1; i<size; i++){
        if(arr[i]<arr[i-1])
            return 0;
    }
    
    return 1;
}

int main(void){
    
    int i, j;
    int *arr;
    int arrIncrease[10]={1,2,3,4,5,6,7,8,9,10};
    int arrDecrease[10]={10,9,8,7,6,5,4,3,2,1};
    
    // length 16 array partition
    for(i=1; i<16; i++){
        
        arr=(int *)malloc(sizeof(int)*i);
        
        for(j=0; j<i; j++){
            arr[j]=(rand()%30);
            printf("%d ", arr[j]);
        }
        printf("\n");
        
        quickSort(arr, 0, i-1);
        
        for(j=0; j<i; j++){\
            printf("%d ", arr[j]);
        }
        printf("\n");
        
        if(checkQuickSort(arr, i))
            printf("size [%d] quickSort ok\n", i);
        
        free(arr);
        printf("\n");
    }
    
    // increasing array partition
    for(i=0; i<10; i++){
        printf("%d ", arrIncrease[i]);
    }
    printf("\n");
    
    quickSort(arrIncrease, 0, 9);
    
    for(i=0; i<10; i++){\
        printf("%d ", arrIncrease[i]);
    }
    printf("\n");
    
    if(checkQuickSort(arrIncrease, 10))
        printf("increased array quicksort finished\n");
    
    printf("\n");
    
    
    
    // decreasing array partition
    for(i=0; i<10; i++){
        printf("%d ", arrDecrease[i]);
    }
    printf("\n");
    
    quickSort(arrDecrease, 0, 9);
    
    for(i=0; i<10; i++){\
        printf("%d ", arrDecrease[i]);
    }
    printf("\n");
    
    if(checkQuickSort(arrDecrease, 10))
        printf("decreased array quicksort finished\n");
    
    printf("\n");
    
    
    return 0;
}