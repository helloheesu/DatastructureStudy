//
//  main.c
//  kate_1_mergeTwoArr
//
//  Created by Kate KyuWon on 10/29/15.
//  Copyright © 2015 Kate KyuWon. All rights reserved.
//

#include <stdio.h>

int* mergeTwoArrs(int* arr1, int size1, int* arr2, int size2){
    if(!arr1||!arr2) return NULL;
    if(size1 <= 0||size2 <= 0) return NULL;
    
    int newArrSize = size1 + size2;
    int* newArr = (int*)malloc(sizeof(int) * newArrSize);
    
    int i = 0, j = 0, newIdx = 0;
    
    for(newIdx = 0; newIdx < newArrSize; newIdx++){
        if(i >= size1)
            newArr[newIdx] = arr2[j++];
        else if(j >= size2)
            newArr[newIdx] = arr1[i++];
        else if(arr1[i] <= arr2[j])
            newArr[newIdx] = arr1[i++];
        else
            newArr[newIdx] = arr2[j++];
    }
    
    return newArr;
}