//
//  calculateRanks.c
//  ds&al
//
//  Created by Kate KyuWon on 11/24/15.
//  Copyright © 2015 KateKyuwon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int calculateRanks(int* score, int* rank, int totalnum);

int main(){

    
    int scoreBucket[101] = {0,};
    //int *final
    
    
    return 0;
}

int calculateRanks(int* score, int* rank, int totalnum){
    if(!score || !rank || totalnum <= 0) return 0;
       return 0;
    return 1;
}

void printArray(int * arr, int num){
    for (int i=0; i< num; i++){
        printf("#%d",arr[i]);
    }
}