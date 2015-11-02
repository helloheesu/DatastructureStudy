#include <stdio.h>
#include <stdlib.h>

int ismergeed(int arr[], int length)
{
    int i;
    
    for(i=0; i<length-1; i++)
    {
        if(arr[i]>arr[i+1])
            return 0;
        
    }
    return 1;
}

void merge(int arr[], int left, int mid, int right)
{
    int fIdx=left; int rIdx=mid+1; int i;
    int *mergeArr = (int*)malloc(sizeof(int)*(right+1)); //병합결과 담을 메모리 공간 할당
    int mIdx=left;
    
    while(fIdx <= mid && rIdx <= right) //병합해 가면서 mergeArr에 담는 과정
    {
        if(arr[fIdx] <= arr[rIdx])
            mergeArr[mIdx]=arr[fIdx++];
        else
            mergeArr[mIdx]=arr[rIdx++];
        mIdx++;
    }
    
    if(fIdx > mid)  //배열의 앞 부분이 mergeArr에 모두 이동되어서 배열 뒷부분에 남은 데이터를 모두 mergeArr로 이동
    {
        for(i=rIdx; i<=right; i++,mIdx++)
            mergeArr[mIdx] = arr[i];
    }
    else            //(fIdx<=mid) 배열의 뒷 부분이 mergerArr로 모두 이동된 경우
    {
        for(i=fIdx; i<=mid; i++,mIdx++)
            mergeArr[mIdx] = arr[i];
    }
    for(i=left; i<=right; i++){
        arr[i]=mergeArr[i];
    }
    free(mergeArr);
    
}

void mergemerge(int arr[], int left,  int right)
{
    int mid;
    
    if(left<right)
    {
        mid = (left+right) /2;
        
        mergemerge(arr, left, mid);
        mergemerge(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int main(int argc, const char * argv[]) {
    
    
    int arr0[]={};
    int arr1[1]={1};
    int arr2[2]={2,1};
    int arr20[20]={20,17,19,18,16,11,13,15,14,12,10,8,5,6,9,7,4,1,3,2}; //랜덤
    int arr201[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}; //증가순
    int arr202[20]={20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1}; //감소순
    int arr3[10]={3,3,3,3,3,3,3,3,3,3};
    
    mergemerge(arr0,NULL,NULL);
    mergemerge(arr1,0,0);
    mergemerge(arr2,0,1);
    mergemerge(arr20,0,19);
    mergemerge(arr201,0,19);
    mergemerge(arr202,0,19);
    mergemerge(arr3,0,9);
    
    ismergeed(arr0,sizeof(arr0)/sizeof(int));
    ismergeed(arr1,sizeof(arr1)/sizeof(int));
    ismergeed(arr2,sizeof(arr2)/sizeof(int));
    ismergeed(arr20,sizeof(arr20)/sizeof(int));
    ismergeed(arr201, sizeof(arr201)/sizeof(int));
    ismergeed(arr202,sizeof(arr202)/sizeof(int));
    ismergeed(arr3,sizeof(arr3)/sizeof(int));
    
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