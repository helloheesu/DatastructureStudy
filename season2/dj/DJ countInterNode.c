//
//  main.c
//  countInterNode
//
//  Created by 임동준 on 2015. 10. 20..
//  Copyright © 2015년 임동준. All rights reserved.
//

#include <stdio.h>


int countInterNode(node_t * root)
{
    if(!root)
        return -1;
    
    if((root->left == NULL) && (root->right == NULL))
        
        return 0;
    else
        return countInterNode(node->left)+countInterNode(node->right)+1;
    
}

