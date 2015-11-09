//
//  main.c
//  ds&al
//
//  Created by Kate KyuWon on 11/9/15.
//  Copyright © 2015 KateKyuwon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

//as O(nlogN)
int* findMaxSubarray(int* arr, int low, int high);
int* findCrossingMaxSubarray(int* arr, int low, int mid, int high);
//as O(n^2)
int* findMaxFair(int* arr, int arrlen);

void compareTwoResult(int* arr, int arrlen);
void showTestResult(int* arr);

int main(int argc, const char * argv[]) {
   
    puts("Case0 : no element");
    int *arr = NULL;
    int arrlen = (int) sizeof(arr)/sizeof(int);
    compareTwoResult(arr, arrlen);
    
    puts("\nCase1-1 : one element");
    int arr1[] = {1};
    int arrlen1 = (int) sizeof(arr1)/sizeof(int);
    compareTwoResult(arr1, arrlen1);
    
    puts("\nCase1-2 : one element");
    int arr12[] = {-3};
    int arrlen12 = (int) sizeof(arr12)/sizeof(int);
    compareTwoResult(arr12, arrlen12);
    
    puts("\nCase2 : two elements");
    int arr2[] = {66, 4};
    int arrlen2 = (int) sizeof(arr2)/sizeof(int);
    compareTwoResult(arr2, arrlen2);

    
    puts("\nCase2-2 : two elements");
    int arr22[] = {0, 0};
    int arrlen22 = (int) sizeof(arr22)/sizeof(int);
    compareTwoResult(arr22, arrlen22);

    puts("\nCase2-3 : two elements");
    int arr23[] = {-2, 0};
    int arrlen23 = (int) sizeof(arr23)/sizeof(int);
    compareTwoResult(arr23, arrlen23);
    
    puts("\nCase2-4 : two elements");
    int arr24[] = {-7, -3};
    int arrlen24 = (int) sizeof(arr24)/sizeof(int);
    compareTwoResult(arr24, arrlen24);
    
    puts("\nCase4 : four elements");
    int arr4[] = {-5, 1, 9, -7};
    int arrlen4 = (int) sizeof(arr4)/sizeof(int);
    compareTwoResult(arr4, arrlen4);

    puts("\nCase4-2 : four elements");
    int arr42[] = {-5, -3, 2, 1};
    int arrlen42 = (int) sizeof(arr42)/sizeof(int);
    compareTwoResult(arr42, arrlen42);

    puts("\nCase4-3 : four elements");
    int arr43[] = {-5, -3, 2, -7};
    int arrlen43 = (int) sizeof(arr43)/sizeof(int);
    compareTwoResult(arr43, arrlen43);

    puts("\nCase5 : many elements");
    int arr5[] = {0, -2, -1, -5, 3, 4,  -9, 7, 10, 2, -11, -3, 12};
    int arrlen5 = (int) sizeof(arr5)/sizeof(int);
    compareTwoResult(arr5, arrlen5);


    
    return 0;
}

int* findMaxFair(int* arr, int arrlen){
    
    if(!arr||arrlen <= 0) return NULL;
    
    int* maxFair = (int*)malloc(sizeof(int)*3);
    int startIdx = 0;
    int untilIdx = 0;
    int maxStart = 0, maxEnd =0;
    int curSum = 0;
    int maxSum = arr[0];
    
    for(startIdx = 0; startIdx<arrlen; startIdx++){
        curSum = 0;
        for(untilIdx = startIdx; untilIdx < arrlen; untilIdx++){
            curSum += arr[untilIdx];
            if(curSum >= maxSum){
                maxSum = curSum;
                maxStart = startIdx;
                maxEnd = untilIdx;
            }
        }
    }
    
    
    maxFair[0] = maxStart;
    maxFair[1] = maxEnd;
    maxFair[2] = maxSum;
    
    return maxFair;
    
}
int* findCrossingMaxSubarray(int* arr, int low, int mid, int high){
    if(!arr) return NULL;
    
    int i = mid;
    int curSum = 0;
    int maxSumLeft = arr[mid];
    int maxPosLeft = mid;
    
    while(i >= low){
        curSum += arr[i];
        if(curSum >= maxSumLeft){
            maxSumLeft = curSum;
            maxPosLeft = i;
        }
        i--;
    }
    
    int j = mid +1;
    curSum = 0;
    int maxSumRight = arr[mid+1];
    int maxPosRight = mid + 1;
    
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

int* findMaxSubarray(int* arr, int low, int high){
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
        int* leftMax = findMaxSubarray(arr, low, mid);
        int* rightMax = findMaxSubarray(arr, mid+1, high);
        int* crossMax = findCrossingMaxSubarray(arr, low, mid, high);
        
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

void compareTwoResult(int* arr, int arrlen){
    puts("[mode 1] O(n^2)");
    showTestResult(findMaxFair(arr, arrlen));
    puts("[mode 2] O(nlogN)");
    showTestResult(findMaxSubarray(arr, 0, arrlen-1));
    
}

void showTestResult(int* arr){
    if(!arr){
        printf("NO ARRAY to show the result.\n");
        return;
    }
    printf("The maxium subarray is from %d to %d in the array.\nThe sum is %d\n", arr[0], arr[1], arr[2]);
    
    return;
}
