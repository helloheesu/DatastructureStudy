//
//  Kate_intro
//
//  Created by Kate KyuWon on 10/14/15.
//  Copyright (c) 2015 Kate KyuWon. All rights


#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    struct node *leftchild;
    struct node *rightchild;
    int num;
} node_t;

typedef struct tree{
    node_t *root;
}tree_t;

tree_t* makeSampleTree(void);
int countInternalNode(node_t* root);
int* makeAllOrder(int* arr, int arrlen);

int main(int argc, const char * argv[]) {
    
    tree_t* newtree = makeSampleTree();
    printf("the number of internal nodes is %d.\n", countInternalNode(newtree->root));
    
    int arr[] = { 1, 2, 3, 4, 6, 7, 5};
    int arrlen = (int) sizeof(arr) / sizeof(int);
    int* arrOrdered = makeAllOrder(arr,arrlen);
    
    for(int i=0; i<arrlen; i++){
        printf(" [%d] : %d \n", i+1, arrOrdered[i]);
    }
    
    return 0;
}



int countInternalNode(node_t* root){
    if(!root) //return NULL; 보다 자연스러움 : 잘못된 값이 들어왔을 때 오류 처리
        return -1;
    
    int count = 0;
    /*
    if(!(root->leftchild) && !(root->rightchild) ) count += 0;
    else {
        count++;
        if(root->leftchild) count += countInternalNode(root->leftchild);
        if(root->rightchild) count += countInternalNode(root->rightchild);
    }
    */
    if((root->leftchild) || (root->rightchild)){
        count++;
        if(root->leftchild) count += countInternalNode(root->leftchild);
        if(root->rightchild) count += countInternalNode(root->rightchild);
    }
    return count;
}

//정렬 안 된 배열의 마지막 요소까지 정렬
//마지막 요소를 따로 저정해 논 후
//삽입될 자리를 찾아 삽입
//마지막에서 두번째 요소부터 대소비교.
//삽입될 요소보다 크다면 해당 인덱스의 요소는 인덱스 하나 큰 자리로 옮겨진다.
int* makeAllOrder(int* arr, int arrlen){
    
    int willInserted = arr[arrlen - 1];
    int prePosOfTarNum = 0;
    
    for(prePosOfTarNum = arrlen - 2; prePosOfTarNum >= 0; prePosOfTarNum--){
        if(arr[prePosOfTarNum] <= willInserted) break;
        else
            arr[prePosOfTarNum + 1] = arr[prePosOfTarNum];
    }
    arr[prePosOfTarNum + 1] = willInserted;
    
    return arr;
}


tree_t* makeSampleTree(void){
    tree_t *newTree = (tree_t*) malloc(sizeof(tree_t));
    newTree -> root = NULL;
    
    
    node_t *depth0 = (node_t*)malloc(sizeof(node_t));
    depth0 -> num = 1;
    
    newTree -> root = depth0;
    
    node_t *depth1_1 = (node_t*)malloc(sizeof(node_t));
    depth1_1 -> num = 2;
    depth1_1 -> leftchild = NULL;
    depth1_1 -> rightchild = NULL;
    node_t *depth1_2 = (node_t*)malloc(sizeof(node_t));
    depth1_2 -> num= 3;
    depth1_2 -> leftchild = NULL;
    depth1_2 -> rightchild = NULL;
    
    depth0 -> leftchild = depth1_1;
    depth0 -> rightchild = depth1_2;
    
    node_t *depth2_1 = (node_t*)malloc(sizeof(node_t));
    depth2_1 -> num = 4;
    depth2_1 -> leftchild = NULL;
    depth2_1 -> rightchild = NULL;
    
    depth1_1 -> leftchild =depth2_1;

    return newTree;
}
