//
//  linklist.c
//  stackAndSequeneAndLinklist
//
//  Created by 刘涛 on 12/29/15.
//  Copyright © 2015 LT. All rights reserved.
//

#include "linklist.h"
#include <stdlib.h>
struct node{
    int dada;
    struct node *next;
};

void linklistFunc(){
    struct node *head,*p,*q,*t;
    int i,n,a;
    head = NULL;
    
    printf("请输入数字总个数，按回车键结束：\n");
    scanf("%d",&n);
    
    printf("请输入%d个数字，按回车键结束：\n",n);
    
    q=(struct node *)malloc(sizeof(struct node));
    
    for (i=1; i<=n; i++) {
        scanf("%d",&a);
        
        p=(struct node *)malloc(sizeof(struct node));
        p->dada = a;
        p->next = NULL;
        
        if (head==NULL) {
            head = p;
        } else {
            q->next = p;
        }
        q=p;
    }

    t=head;
    printf("请输入要插入的值：\n");
    
    scanf("%d",&a);
    while (t!=NULL) {
        if (t->next->dada>20) {
            struct node *addNode = (struct node *)malloc(sizeof(struct node));
            addNode->dada = a;
            addNode->next = t->next;
            t->next = addNode;
            break;
        }
        printf("%d ",t->dada);
        t=t->next;
    }
    
    t=head;
    while (t!=NULL) {
        printf("%d ",t->dada);
        t=t->next;
    }
    
}