//
//  list.c
//  List
//
//  Created by 刘涛 on 4/27/16.
//  Copyright © 2016 LT. All rights reserved.
//

#include "list.h"
#include <stdlib.h>
#include <stdio.h>

struct node{
    int num;
    struct node * next;
};

int isEmpty(struct node *head){
//    printf("\nnum:%d   bool:%d\n  next:%d",head->num,head->next == NULL,head->next);
    return head == NULL;
}

void insertANode(struct node *head){
    int i=0,num;
    printf("请输入要插入的位置：\n");
    scanf("%d",&i);
    printf("请输入要插入的值：\n");
    scanf("%d",&num);
    struct node *newNode;
    for (int j=0; j<i-1; j++) {
        head = head->next;
    }
    
    newNode = malloc(sizeof(struct node));
    newNode->num = head->num;
    newNode->next = head->next;
    
    head->num = num;
    head->next = newNode;
}

void deleteANode(struct node *head){
    int i=0,num;
    printf("请输入要删除的位置：\n");
    scanf("%d",&i);
    struct node *preNode = head;
    struct node *nextNode;
    for (int j=0; j<i-2; j++) {
        head = head->next;
    }if (i<=1) {
        head->num = head->next->num;
        head->next = head->next->next;
    }else if (head->next->next == NULL){
        head->next = NULL;
    }else {
        nextNode = preNode->next->next;
        
        free(preNode->next);
        preNode->next->next=NULL;
        
        preNode->next = nextNode;
    }
    
}

struct node * creatNode(struct node * head){
    struct node *p,*p1;
    p = p1 = malloc(sizeof(struct node));
    printf("请输入数据（数据小于0时，将退出输入)：\n");
    scanf("%d",&p->num);
    while (p->num > 0) {
        if (head == NULL) {
            head = p;
        } else {
            p1->next = p;
        }
        p1=p;
        printf("请输入数据（数据小于0时，将退出输入)：\n");
        p=malloc(sizeof(struct node));
        scanf("%d",&p->num);
    }
//    free(p);
    p=NULL;
    p1->next = NULL;
    return head;
}

void print(struct node * temp){
    struct node * L = temp;
    while (L!=NULL) {
        printf("%d\n",L->num);
        L = L->next;
    }
}
