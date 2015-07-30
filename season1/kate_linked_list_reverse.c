//
//  main.c
//  linked_list_reverse
//
//  Created by Kate KyuWon on 7/29/15.
//  Copyright (c) 2015 Kate KyuWon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} node_t;

node_t* linked_list_reverse(node_t* head){
    if ( head == NULL ) {
        printf("Input Error: NULL");
        return NULL;
    }
    
    node_t* temp = NULL;
    node_t* newHead = NULL;
    
    while(head!=NULL){
        temp = head;
        head = head->next;
        temp->next = newHead;
        newHead = temp;
    }
    
    return newHead;
    
}

void linked_list_print(node_t* head){
    if ( head == NULL ) {
        printf("Input Error: NULL");
        return ;
    }
    
    node_t* temp = head;
    while(temp != NULL){
        printf("%3d*", temp->data);
        temp = temp->next;
    }
    
    printf("\n");
}

int main(int argc, const char * argv[]) {
    
    node_t* head = NULL;
    node_t* one = (node_t*)malloc(sizeof(node_t) * 1);
    one->data = 1;
    head = one;
    
    node_t* two = (node_t*)malloc(sizeof(node_t) * 1);
    two->data = 2;
    node_t* three = (node_t*)malloc(sizeof(node_t) * 1);
    three->data = 3;
    node_t* four = (node_t*)malloc(sizeof(node_t) * 1);
    four->data = 4;
    node_t* five = (node_t*)malloc(sizeof(node_t) * 1);
    five->data = 5;
    
    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = NULL;
    
    puts("before reverse");
    linked_list_print(head);
    
    puts("after reverse");
    head = linked_list_reverse(head);
    linked_list_print(head);
    
    
    return 0;
}
