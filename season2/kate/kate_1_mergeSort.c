//
//  main.c
//  mergeSort
//
//  Created by Kate KyuWon on 10/26/15.
//  Copyright (c) 2015 Kate KyuWon. All rights reserved.
//

#include <stdio.h>

void mergeSort(int* arr, int startIdx, int endIdx);
void merge(int* arr, int formerIdx, int formerEnd, int latterIdx, int latterEnd);
void printArray(int* arr, int arrlen);
int isSorted(int* arr, int arrlen);
void showTestResult(int* arr, int arrlen);


int main(int argc, const char * argv[]) {
   
    //case 0 - 0 element
    int *arr = NULL;
    int arrLen = (int)sizeof(arr) / sizeof(int);
    showTestResult(arr, arrLen);
    
    //case 1 - one element
    int arr1[1] = {1};
    int arrLen1 = (int)sizeof(arr1) / sizeof(int);
    showTestResult(arr1, arrLen1);
    
    //case 2.1 - two elements, incremented
    int arr2[2] = {1, 100};
    int arrLen2 = (int)sizeof(arr2) / sizeof(int);
    showTestResult(arr2, arrLen2);
    
    //case 2.2 - two elements, decremented
    int arr22[2] = {100, 23};
    int arrLen22 = (int)sizeof(arr22) / sizeof(int);
    showTestResult(arr22, arrLen22);
    
    //case 2.3 - two elements, same
    int arr23[2] = {51,51};
    int arrLen23 = (int)sizeof(arr23) / sizeof(int);
    showTestResult(arr23, arrLen23);
    
    //case 3.1 - many elements, incremented
    int arr3[20] = {1,2,3,4,5,6,7,8,9,50, 61,62,63,64,65,66,67,68,69, 101};
    int arrLen3 = (int)sizeof(arr3) / sizeof(int);
    showTestResult(arr3, arrLen3);

    //case 3.2 - three elements, decremented
    int arr32[20] = {99, 97, 95., 93, 91, 89, 87, 85, 83, 81, 79, 77, 75, 73, 71, 69, 67, 65, 63, 61};
    int arrLen32 = (int)sizeof(arr32) / sizeof(int);
    showTestResult(arr32, arrLen32);
    
    //case 3.3 - three elements, randomed
    int arr33[10] = {33 , 33, 33, 33, 33, 33, 33, 33, 33, 33};
    int arrLen33 = (int)sizeof(arr33) / sizeof(int);
    showTestResult(arr33, arrLen33);
    

    return 0;
}

void mergeSort(int* arr, int startIdx, int endIdx){
    
    
    if(!arr){
        printf("ERROR - no input\n");
        return;
    }
    //debug// printf("start : %d, end: %d\n", startIdx, endIdx );
    if(startIdx > endIdx){
        printf("ERROR - wrong index\n");
    }
    else if(startIdx < endIdx){
        int meanIdx = startIdx + ((endIdx - startIdx) / 2);
        mergeSort(arr, startIdx, meanIdx);
        mergeSort(arr, meanIdx+1, endIdx);
        merge(arr, startIdx, meanIdx, meanIdx+1, endIdx);
    }
    else{
        return ;
    }
    
}

void merge(int* arr, int formerIdx, int formerEnd, int latterIdx, int latterEnd){
    
    if(!arr){
        printf("ERROR - no input\n");
        return;
    }
    //debug// printf("former : %d, latter: %d\n", formerIdx, latterEnd );
    int arrLen = latterEnd - formerIdx + 1 ;
    int* tempArr = (int*)malloc(sizeof(int) * arrLen);
    
    int tempIdx = 0;
    int i = formerIdx;
    int j = latterIdx;
    
  
    while(i <= formerEnd && j <= latterEnd){
        if(arr[i] <= arr[j])
            tempArr[tempIdx++] = arr[i++];
        else
            tempArr[tempIdx++] = arr[j++];
    }
    
    if(i > formerEnd){
        while(tempIdx < arrLen)
            tempArr[tempIdx++] = arr[j++];
    }else if(j > latterEnd){
        while(tempIdx < arrLen)
            tempArr[tempIdx++] = arr[i++];
    }
    
    i = formerIdx;
    for(tempIdx = 0; tempIdx < arrLen; tempIdx++){
        arr[i] = tempArr[tempIdx];
        i++;
    }
    free(tempArr);
    //debug// printArray(arr, arrLen);
}

void printArray(int* arr,int arrlen){
    if(!arr || arrlen == 0){
        printf("No Array Input to be printed.\n");
        return;
    }
    int i = 0;
    
    for(i = 0; i<arrlen; i++){
        printf("%5d", arr[i]);
    }
    puts(" ");
}

int isSorted(int* arr, int arrlen){
    if(!arr || arrlen == 0){
        printf("No Array Input to check.\n");
        return -1;
    }
    int isSorted = 1;
    int i =0;
    
    for(i = 0 ; i < arrlen-1 ; i++){
        if( arr[i] > arr[i+1]) isSorted = 0;
    }
    
    return isSorted;
}

void showTestResult(int* arr, int arrlen){
    printf("Before sorting: \n");
    printArray(arr, arrlen);
    mergeSort(arr, 0, arrlen-1);
    printf("After sorting: \n");
    printArray(arr, arrlen);
        
    int isSortedResult = isSorted(arr, arrlen);
    printf("The result is ");
    if(isSortedResult == 1) printf("sorted.\n");
    else printf("NOT sorted.\n");
    puts(" ");
    
    return;
}
