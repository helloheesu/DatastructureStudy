//
//  main.c
//  MergeSort
//
//  Created by 임동준 on 2015. 10. 26..
//  Copyright © 2015년 임동준. All rights reserved.
//

#include <stdio.h>


void divide(int arr[], int left, int right)
{
    int mid;
    
    if(left<right){
        
    
    mid=(left+right);
    
    merge(arr, left, mid); //left~mid에 위치한 데이터 정렬!
    merge(arr, mid+1, right); //mid+1~right에 위치한 데이터 정렬
    merge(arr, left, mid, right); //정렬된 두 배열 병합
    }
}

void merge(int arr[], int left, int mid, int right)
{
    int front=left;
    int rear=mid+1;
    int i;
    
    int *mergeArr = (int*)malloc(sizeof(int)*(right+1));
    int mergeIdx=left;
    
    while(front <= mid && rear <=right)
    {
        if(arr[front]<=arr[rear])
            mergeArr[mergeIdx]=arr[front++];
        else
            mergeArr[mergeIdx]=arr[rear++];
        
        mergeIdx++;
    }
    
    if(front > mid) //두 개의 배열 중 앞부분 배열이 먼저 다 정렬 되었고, 뒷부분의 배열만 남았을 때,
    {
        for(i=front; i<=right; i++)
            mergeArr[mergeIdx]=arr[i];
    }
    else            //배열의 앞 부분만 남았을 때
    {
            for(i=front; i<=mid; i++)
            mergeArr[mergeIdx]=arr[i];
    }


        for(i=left; i<=right; i++)
        arr[i]=mergeArr[i];
    
        free(mergeArr);
}

int main(int argc, const char * argv[]) {

    int i;
    int arr[10] = {5,2,6,9,1,3,4,7,8,10};
    divide(arr, 0, 9);
    
    for(i=0; i<10; i++)
    {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    
    
    
    
    
    return 0;
}
