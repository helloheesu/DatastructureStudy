//
//  main.c
//  ds&al
//
//  Created by Kate KyuWon on 11/9/15.
//  Copyright © 2015 KateKyuwon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int* findMaxiumSubarray(int* arr, int low, int high);
int* findCrossMaixSubarray(int* arr, int low, int mid, int high);

void showTestResult(int* arr);

int main(int argc, const char * argv[]) {
   
    int arr1[] = {-9,-8, 2,3,1,4};
    int arrlen1 = (int) sizeof(arr1)/sizeof(int);
    printf("len: %d\n", arrlen1);
    
    showTestResult(findMaxiumSubarray(arr1, 0, arrlen1-1));
    
    
    return 0;
}

int* findCrossMaixSubarray(int* arr, int low, int mid, int high){
    if(!arr) return NULL;
    
    int i = mid;
    int curSum = 0;
    int maxSumLeft = 0;
    int maxPosLeft = mid;
    
    while(i > 0){
        curSum += arr[i];
        if(curSum >= maxSumLeft){
            maxSumLeft = curSum;
            maxPosLeft = i;
        }
        i--;
    }
    
    int j = mid +1;
    curSum = 0;
    int maxSumRight = 0;
    int maxPosRight = mid +1;
    
    while(j <= high){
        curSum += arr[j];
        if(curSum > maxSumRight){
            maxSumRight = curSum;
            maxPosRight = j;
        }
        j++;
    }
    
    int* new = (int*) malloc(sizeof(int) * 3);
    new[0] = maxPosLeft;
    new[1] = maxPosRight;
    new[2] = maxSumLeft + maxSumRight;

    return new;
}

int* findMaxiumSubarray(int* arr, int low, int high){
    if(!arr) return NULL;
    
    if(low == high){
        int* new = (int*)malloc(sizeof(int)*3);
        new[0] = low;
        new[1] = high;
        new[2] = arr[low];
        return new;
    }
    else{
        int mid = low + (high - low)/2;
        int* leftMax = findMaxiumSubarray(arr, low, mid);
        int* rightMax = findMaxiumSubarray(arr, mid+1, high);
        int* crossMax = findCrossMaixSubarray(arr, low, mid, high);
        
        if(leftMax[2] >= rightMax[2] && leftMax[2] >= crossMax[2]){
            free(rightMax);
            free(crossMax);
            return leftMax;
        }
        else if(rightMax[2] >= leftMax[2] && rightMax[2] >= crossMax[2]){
            free(leftMax);
            free(crossMax);
            return rightMax;
        }
        else{
            free(leftMax);
            free(rightMax);
        return crossMax;
        }
    }
}

void showTestResult(int* arr){
    printf("The max subarray is from %d to %d in the array.\nThe sum is %d\n", arr[0], arr[1], arr[2]);
    
    return;
}
