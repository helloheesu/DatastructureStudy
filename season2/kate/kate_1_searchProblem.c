//
//  main.c
//  kate_LoopInvariantBookExam
//
//  Created by Kate KyuWon on 10/22/15.
//  Copyright (c) 2015 Kate KyuWon. All rights reserved.
//

#include <stdio.h>
int searchIdxOfCertainValue(int* arr, int value, int len);
void showResult(int* arr, int value,int len);

int main(int argc, const char * argv[]) {
    
    int *arr = NULL;
    int arrLen = sizeof(arr) / sizeof(int);
    //case0-1. 입력갯수가 0개.
    showResult(arr, 0, arrLen);
    
    int arr1[] = {3};
    int arrLen1 = sizeof(arr1) / sizeof(int);
    showResult(arr1, 6, arrLen1); //case1-2. 입력갯수가 1개, 값이 없음.
    showResult(arr1, 3, arrLen1); //case1-3. 입력갯수가 1개, 값이 있음.
    
    int arr2[] = {4, 5};
    int arrLen2 = sizeof(arr2) / sizeof(int);
    showResult(arr2, 1, arrLen2); //case2-1. 입력갯수가 2개, 값이 없음.
    showResult(arr2, 4, arrLen2); //case2-1. 입력갯수가 2개, 값이 있음.
    showResult(arr2, 5, arrLen2); //case2-1. 입력갯수가 2개, 값이 있음.
    
    int arr3[] = {6, 7 ,8};
    int arrLen3 = sizeof(arr3) / sizeof(int);
    showResult(arr3, 1, arrLen3); //case3-1. 입력갯수가 3개, 값이 없음.
    showResult(arr3, 6, arrLen3); //case3-1. 입력갯수가 3개, 값이 있음.
    showResult(arr3, 7, arrLen3); //case3-1. 입력갯수가 3개, 값이 있음.
    showResult(arr3, 8, arrLen3); //case3-1. 입력갯수가 3개, 값이 있음.
    
    
    return 0;
}


//배열 안에 찾는 값이 있으면 해당 인덱스 반환, 없으면 NULL.
int searchIdxOfCertainValue(int arr[], int value,int arrLen){
    if(!arr) return  -1; //check an unusual case.
    
    int idxSearched = -2;
    int i = 0;
    
    for(i = 0; i<arrLen; i++){
        if(arr[i] == value){
            idxSearched = i;
            break;
        }
    }
    
    return idxSearched;
}

void showResult(int* arr, int value,int arrlen){
    int result = searchIdxOfCertainValue(arr, value, arrlen);
    //printf("result : %d", result); //확인용
    
    if(result == -1) printf("Wrong input : no sequence of numbers. \n");
    else if(result == -2)
        printf("There is no certain value in data.\n");
    else
        printf("The index of certain value is %d\n", result);
    
    
    return;
}