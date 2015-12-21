#include <stdio.h>
#include <string.h>
#include <math.h>

void countSortforRadix(int *arr, int *result, int size, int digitNum){
    
    int i;
    int k=10;
    int mod=pow(k,digitNum);
    int divider=pow(k, digitNum-1);
    
    if (arr==NULL || result==NULL || size<=0 || digitNum<1)
        return ;
    
    
    int tmp[k];
    
    memset(tmp, 0, (k) * sizeof(int));
    
    for (i=0; i<size; i++) {  //count sort에서 각 인덱스에 해당하는 숫자 입력
        tmp[arr[i]%mod/divider]++;
    }
    
    for(i=1; i<k; i++){    //누적된 갯수로 바꿔주는거
        tmp[i]+=tmp[i-1];
    }
    
    for (i=size-1; i>=0; i--) {
        result[tmp[arr[i]%mod/divider]-1]=arr[i]; // result의 index에 접근하기 때문에 -1 해줘야함 ㅠㅠ
        tmp[arr[i]%mod/divider]--;    }
    
    for(i=0; i<size; i++){
        arr[i]=result[i];
    }
    
}

void radixSort(int *arr, int *result, int size, int digitNum){
    
    int i;
    
    if (arr==NULL || result==NULL || size<1 || digitNum<1)
        return;
    
    for(i=1; i<=digitNum; i++){
        countSortforRadix(arr, result, size, i);
    }
    
}

void testRadix(int *arr, int size, int digitNum){
    int i;
    int result[size];
    
    memset(result, 0, size * sizeof(int));
    
    printf("before Radix: ");
    for (i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    radixSort(arr, result, size, digitNum);
    
    printf("after Radix: ");
    for(i=0; i<size; i++){
        printf("%d ", result[i]);
    }
    printf("\n\n");
}

int main(void){
    
    int *arr1 = NULL;
    int arr2[] = {521,123};
    int arr3[] = {152,125,325,569};
    int arr4[] = {567,341,357,811,132};
    int arr5[] = {123,532,215,631,111};
    
    testRadix(arr1, 0, 0);
    testRadix(arr2, sizeof(arr2)/sizeof(int), 3);
    testRadix(arr3, sizeof(arr3)/sizeof(int), 3);
    testRadix(arr4, sizeof(arr4)/sizeof(int), 3);
    testRadix(arr5, sizeof(arr5)/sizeof(int), 3);
    
    return 0;
}