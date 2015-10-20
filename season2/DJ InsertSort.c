//
//  main.c
//  InsertionSort
//
//  Created by 임동준 on 2015. 10. 20..
//  Copyright © 2015년 임동준. All rights reserved.
//

#include <stdio.h>


int isSorted(int arr[], int length)
{
    int i;
    
    for(i=0; i<length-1; i++)
    {
        if(arr[i]>arr[i+1])
            return 0;
        
    }
    return 1;
}

void InserSort(int arr[], int length)
{
    int i, j;
    int key;
    
    for(i=1; i<length; i++)
    {
        key = arr[i];
        
        for(j=i-1; j>=0; j--)
        {
            if(arr[j]>key)
                arr[j+1]=arr[j];
            else
                break;
        }
        
        arr[j+1] = key;
    }
}

int main(void)
{
    int arr0[]={};
    int arr1[1]={1};
    int arr2[2]={2,1};
    int arr20[20]={20,17,19,18,16,11,13,15,14,12,10,8,5,6,9,7,4,1,3,2}; //랜덤
    int arr201[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}; //증가순
    int arr202[20]={20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1}; //감소순
    int arr3[10]={3,3,3,3,3,3,3,3,3,3};
    
    
    
    
    InserSort(arr0, sizeof(arr0)/sizeof(int));
    InserSort(arr1, sizeof(arr1)/sizeof(int));
    InserSort(arr2, sizeof(arr2)/sizeof(int));
    InserSort(arr20, sizeof(arr20)/sizeof(int));
    InserSort(arr201, sizeof(arr201)/sizeof(int));
    InserSort(arr202, sizeof(arr202)/sizeof(int));
    InserSort(arr3, sizeof(arr3)/sizeof(int));
    
    isSorted(arr20, sizeof(arr20)/sizeof(int));
    
    printf("\n");
    
    for(int i=0; i<1; i++)
        printf("%d ", arr0[i]);
    
    printf("\n");
    
    for(int i=0; i<1; i++)
        printf("%d ", arr1[i]);
    
    printf("\n");
    
    for(int i=0; i<2; i++)
        printf("%d ", arr2[i]);
    
    printf("\n");
    
    for(int i=0; i<20; i++)
        printf("%d ", arr20[i]);
    
    printf("\n");
    
    for(int i=0; i<20; i++)
        printf("%d ", arr201[i]);
    
    printf("\n");
    
    for(int i=0; i<20; i++)
        printf("%d ", arr202[i]);
    printf("\n");
    
    for(int i=0; i<10; i++)
        printf("%d ", arr3[i]);
    printf("\n");
    
    return 0;
}
