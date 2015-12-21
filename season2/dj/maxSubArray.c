#include <stdio.h>
#include <stdlib.h>

#define Error -99999

int findMaxArray_N2(int* arr, int size)
{
    if (arr == NULL || size <= 0) //-3 -2 5 3
        
        return Error;
    
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        int currentMax=0;
        
        for (int j = i; j < size; j++)
        {
            currentMax += arr[j];
            
            if (currentMax > max)
                
                max = currentMax;
        }
    }
    return max;
}

int findCrossMaxSubArray(int*arr, int left, int mid, int right)
{
    if (arr == NULL || right < 0)       // -3 -2 -5 -3
        
        return Error;
    
    int leftMax = Error;
    int rightMax = Error;
    
    int currentSum = 0;
    
    for(int i=mid; i>=left; i--)
    {
        currentSum += arr[i];
        if(currentSum > leftMax)
            leftMax=currentSum;
    }
    
    currentSum=0;
    
    for(int i=mid+1; i<=right; i++)
    {
        currentSum += arr[i];
        
        if(currentSum > rightMax)
            rightMax = currentSum;
        
    }
    
    return leftMax + rightMax;
    
}

int getMaxSubNlogN(int *arr, int left, int right)
{
    if (arr == NULL || right < 0)
        
        return Error;
    
    if( left == right)
        return arr[left];
    
    int mid= left + (right-left)/2;
    int leftSum= getMaxSubNlogN(arr, 0, mid);
    int rightSum= getMaxSubNlogN(arr, mid+1, right);
    int midSum = findCrossMaxSubArray(arr, left, mid, right);
    int maxSum;
    
    maxSum = leftSum > rightSum ? leftSum : rightSum;
    maxSum = maxSum > midSum ? maxSum : midSum;
    
    return maxSum;
    
}

int main()
{
    int* num0 = NULL;
    int num1[1] = { 3 }; //3
    int num2[2] = { 5, -3 }; //5
    int num4[4] = { -3, -2, -5, -3 };//3
    int num20[20] = { -3, -1, -2, -5,- 5, -6, 7, 8, 9, 9, 8, 7, -11, -13, -4, -3, -2, -1, 0, 10 };//48
    
    //원소 0개
    printf("원소 0개: %d \n",findMaxArray_N2(num0,NULL));
    printf("원소 0개: %d \n",getMaxSubNlogN(num0,NULL, NULL));
    //원소 1개
    printf("원소 1개: %d \n",findMaxArray_N2(num1,1));
    printf("원소 1개: %d \n",getMaxSubNlogN(num1,0,0));
    //원소 2개
    printf("원소 2개: %d \n",findMaxArray_N2(num2,2));
    printf("원소 2개: %d \n",getMaxSubNlogN(num2,0,1));
    //원소 4개
    printf("원소 4개: %d \n",findMaxArray_N2(num4,4));
    printf("원소 4개: %d \n",getMaxSubNlogN(num4,0,3));
    //원소 20개
    printf("원소 20개: %d \n",findMaxArray_N2(num20,20));
    printf("원소 20개: %d \n",getMaxSubNlogN(num20,0,19));
    
    return 0;
}