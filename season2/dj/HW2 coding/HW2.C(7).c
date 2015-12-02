#include<stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int start, int end) {
    int flag = -1;
    int pivot = arr[end];
    for (int checkedPoint = 0; checkedPoint < end; checkedPoint++) {
        if (arr[checkedPoint] < pivot) {
            flag++;
            swap(&arr[checkedPoint], &arr[flag]);
        }
    }
    swap(&arr[flag + 1], &arr[end]);
    return flag + 1;
}

int selectKth(int *arr, int start, int end, int kth) {
    int pivot = 0;
    if (arr == NULL) {
        perror("This is empty array \n");
        return -1;
    }
    if (kth > end || kth < start) {
        perror("wrong insert \n");
        return -1;
    }
    pivot = partition(arr, start, end);
    if (pivot == kth)
        return arr[pivot];
    else if (pivot > kth)
        return selectKth(arr, start, pivot - 1, kth);
    else return selectKth(arr, pivot + 1, end, kth);
}

int main(void) {
    int * array = NULL;
    printf("wrong Insert : %d \n", selectKth(array, 0, 0, 0));
    printf("\n");
    
    int arrayOutOfIdx[1] = { 1 };
    printf("kth Index break bounds: %d \n", selectKth(arrayOutOfIdx, 0, 0, 10));
    printf("\n");
    
    int arr1[1] = { 1 };
    for(int i=0; i<1; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    printf("1th Index: %d \n", selectKth(arr1, 0, 0, 0));
    printf("\n");
    
    int arr2[2] = { 1, 2 };
    for(int i=0; i<2; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");
    printf("2th Index : %d \n", selectKth(arr2, 0, 1, 1));
    printf("\n");
    
    int arr22[3] = { 2, 1, 7 };
    for(int i=0; i<3; i++)
    {
        printf("%d ", arr22[i]);
    }
    printf("\n");
    printf("2th Index : %d \n", selectKth(arr22, 0, 1, 1));
    printf("\n");
    
    int arr10[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    for(int i=0; i<10; i++)
    {
        printf("%d ", arr10[i]);
    }
    printf("\n");
    printf("5th Index : %d \n", selectKth(arr10, 0, 9, 4));
    printf("\n");
    
    int arr12[12] = { 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    for(int i=0; i<12; i++)
    {
        printf("%d ", arr12[i]);
    }
    printf("\n");
    printf("7th Index : %d \n", selectKth(arr12, 0, 11, 6));
    printf("\n");
}