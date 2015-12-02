#include <stdio.h>
#include <string.h>

void countingsort(int *arr, int *result, int size, int range){
    
    int i;
    
    if (arr==NULL || result==NULL || size<=0 || range<0)
        return ;
    
    int tmp[range+1];
    
    memset(tmp, 0, (range+1) * sizeof(int));
    
    for (i=0; i<size; i++) {
        if(arr[i]>range || arr[i]<0){
            printf("array contains number beyond the bounds \n");
            return;
        }
        tmp[arr[i]]++;
    }
    
    for(i=1; i<range+1; i++){
        tmp[i]+=tmp[i-1];
    }
    
    for (i=size-1; i>=0; i--) {
        result[tmp[arr[i]]-1]=arr[i];
        tmp[arr[i]]--;
    }
    
}

void testCount(int *arr, int size, int k){
    int i;
    int result[size];
    
    printf("before sort: ");
    for (i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    countingsort(arr, result, size, k);
    
    printf("after sort: ");
    for(i=0; i<size; i++){
        printf("%d ", result[i]);
    }
    printf("\n\n");
}

int main(void){
    
    int *arr1 = NULL;
    int arr2[] = {1};
    int arr3[] = {1,1,1,1,1};
    int arr4[] = {12, 0, 3, 5, 6, 9, 11, 2, 4, 5, 7, 20, 16, 31, 8, 13, 23, 11, 11, 10};
    int arr5[] = {1,2,3,4,5};
    int arr6[] = {5,4,3,2,1};
    
    
    
    testCount(arr1, 0, 0);
    testCount(arr2, sizeof(arr2)/sizeof(int), 1);
    testCount(arr3, sizeof(arr3)/sizeof(int), 1);
    testCount(arr4, sizeof(arr4)/sizeof(int), 20);
    testCount(arr5, sizeof(arr5)/sizeof(int), 5);
    testCount(arr6, sizeof(arr6)/sizeof(int), 5);
    
    
    return 0;
}