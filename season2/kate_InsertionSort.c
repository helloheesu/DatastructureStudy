//
//  main.c
//  InsertionSort
//
//  Created by Kate KyuWon on 10/19/15.
//  Copyright (c) 2015 Kate KyuWon. All rights reserved.
//

#include <stdio.h>

void insertionSort(int* arr, int arrlen);
void printArray(int* arr, int arrlen);
int isSorted(int* arr, int arrlen);

void showTestResult(int* arr, int arrlen);

int main(int argc, const char * argv[]) {
    
    //원소 갯수 관점 테스트
    
    printf("case 1-1: No Element.\n");
    int *arr = NULL;
    int arrlen = 0;
    showTestResult(arr, arrlen);
    
    printf("case 1-2: one Element.\n");
    int arr1[] = {1};
    int arrlen1 = (int) sizeof(arr1) / sizeof(int);
    showTestResult(arr1, arrlen1);
    
    printf("case 1-3: two Elements.\n");
    int arr2[] = {1,2};
    int arrlen2 = (int) sizeof(arr2) / sizeof(int);
    showTestResult(arr2, arrlen2);
    
    printf("case 1-4: three Elements.\n");
    int arr3[] = {1,2, 3};
    int arrlen3 = (int) sizeof(arr3) / sizeof(int);
    showTestResult(arr3, arrlen3);
    
    //입력 특성 관점 테스트
    
    printf("case 2-1: ascending case.\n");
    int arr4[] = {4, 5, 6};
    int arrlen4 = (int) sizeof(arr4) / sizeof(int);
    showTestResult(arr4, arrlen4);

    
    printf("case 2-2: descending case.\n");
    int arr5[] = {6, 5, 4, 3};
    int arrlen5 = (int) sizeof(arr5) / sizeof(int);
    showTestResult(arr5, arrlen5);

    printf("case 2-3: random case.\n");
    int arr6[] = {5, 7, 3, 1, 4};
    int arrlen6 = (int) sizeof(arr6) / sizeof(int);
    showTestResult(arr6, arrlen6);
    
    printf("case 2-4: same value case.\n");
    int arr7[] = {8, 8, 8};
    int arrlen7 = (int) sizeof(arr7) / sizeof(int);
    showTestResult(arr7, arrlen7);
    
    
    return 0;
}

void showTestResult(int* arr, int arrlen){
    printf("Before sorting: \n");
    printArray(arr, arrlen);
    insertionSort(arr, arrlen);
    printf("After sorting: \n");
    printArray(arr, arrlen);
    
    int isSortedResult = isSorted(arr, arrlen);
    printf("The result is ");
    if(isSortedResult == 1) printf("sorted.\n");
    else printf("NOT sorted.\n");
    puts(" ");
    
    return;
}

void insertionSort(int* arr, int arrlen){
    if(!arr || arrlen == 0){
        printf("No Array Input to be sorted.\n");
        return;
    }
    int inserted = 0;
    int i = 0;
    int j = 0;
    
    for(i = 1; i <arrlen; i++){
        inserted = arr[i];
        for(j = i-1; j >=0 ; j--){
            if(arr[j] <= inserted) break;
            else arr[j+1] = arr[j];
        }
        
        arr[j+1] = inserted;
    }
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

void printArray(int* arr,int arrlen){
    if(!arr || arrlen == 0){
        printf("No Array Input to be printed.\n");
        return;
    }
    int i = 0;
    
    for(i = 0; i<arrlen; i++){
        printf("[%d] : %d \n", i+1, arr[i]);
    }
}