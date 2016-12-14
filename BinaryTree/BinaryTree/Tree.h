//
//  Tree.h
//  BinaryTree
//
//  Created by 移动支付－刘涛 on 12/14/16.
//  Copyright © 2016 移动支付－刘涛. All rights reserved.
//

#ifndef Tree_h
#define Tree_h
#include <stdio.h>
#include <stdbool.h>

typedef struct item{
    char petname[20];
    char petkind[20];
}Item;

#define MAXITEMS 10

typedef struct node{
    Item item;
    struct node * left;
    struct node * right;
}Node;

typedef struct tree{
    Node * root;
    int size;
}Tree;

void InitializeTree (Tree * pTree);

bool TreeIsEmpty (const Tree * ptree);

bool TreeIsFull (const Tree * ptree);

int TreeItemCount (const Tree * ptree);

bool AddItem(const Item * pi,Tree *ptree);

bool InTree (const Item * pi,const Tree * ptree);

bool DeleteItem (const Item * pi, Tree * ptree);

void Traverse (const Tree * ptree,void (* pfun)(Item item));

void DeleteAll (Tree * ptree);

#endif /* Tree_h */
