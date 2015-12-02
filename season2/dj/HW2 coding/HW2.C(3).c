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

int checkPartition(int *arr, int size, int posPivot){
    int i;
    int pivot=arr[posPivot];
    
    for(i=0; i<posPivot; i++){
        if(arr[i]>pivot)
            return 0;
    }
    for( i=posPivot+1; i<size-1; i++ ){
        if(arr[i]<pivot)
            return 0;
    }
    
    return 1;
}

int main(void){
    
    int i, j, posPivot;
    int *arr;
    int arrIncreas[10]={1,2,3,4,5,6,7,8,9,10};
    int arrDecreas[10]={10,9,8,7,6,5,4,3,2,1};
    
    // length 32 array partition
    for(i=1; i<33; i++){
        
        arr=(int *)malloc(sizeof(int)*i);
        
        for(j=0; j<i; j++){
            arr[j]=(rand()%40);
            printf("%d ", arr[j]);
        }
        printf("\n");
        
        posPivot=partition(arr, 0, i-1);
        
        for(j=0; j<i; j++){
            printf("%d ", arr[j]);
        }
        printf("\n");
        
        if(checkPartition(arr, i, posPivot))
            printf("size [%d] partition finished\n", i);
        
        free(arr);
        printf("\n");
    }
    
    // increasing array partition
    for(i=0; i<10; i++){
        printf("%d ", arrIncreas[i]);
    }
    printf("\n");
    
    posPivot=partition(arrIncreas, 0, 9);
    
    for(i=0; i<10; i++){\
        printf("%d ", arrIncreas[i]);
    }
    printf("\n");
    
    if(checkPartition(arrIncreas, 10, posPivot))
        printf("increased array partition ok\n");
    
    printf("\n");
    
    
    
    // decreasing array partition
    for(i=0; i<10; i++){
        printf("%d ", arrDecreas[i]);
    }
    printf("\n");
    
    posPivot=partition(arrDecreas, 0, 9);
    
    for(i=0; i<10; i++){
        printf("%d ", arrDecreas[i]);
    }
    printf("\n");
    
    if(checkPartition(arrDecreas, 10, posPivot))
        printf("increased array partition ok\n");
    
    printf("\n");
    
    
    
    return 0;
}