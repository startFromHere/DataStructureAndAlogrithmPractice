//
//  cardGame.c
//  stackAndSequeneAndLinklist
//
//  Created by 刘涛 on 12/29/15.
//  Copyright © 2015 LT. All rights reserved.
//

#include "cardGame.h"

struct quene{
    int cards[1000];
    int head;
    int tail;
};

struct stack{
    int cards[10];
    int top;
};

void describeCardGame(){
    struct quene q1,q2;
    struct stack s;
    int book[10];
    int t;
    
    q1.head=0;
    q1.tail=0;
    
    q2.head=0;
    q2.tail=0;
    
    s.top=0;
    
    for (int i=1; i<10; i++) {
        book[i]=0;
    }
    
    printf("请输入小哼手中的牌：\n");
    for (int i=0; i<6; i++) {
        scanf("%d",&q1.cards[q1.tail++]);
    }
    printf("请输入小哈手中的牌：\n");
    for (int i=0; i<6; i++) {
        scanf("%d",&q2.cards[q2.tail++]);
    }
    
    while (q1.head<q1.tail && q2.head<q2.tail) {
        t=q1.cards[q1.head];//小哼出一张牌
        
        if (book[t]==0) {
            q1.head++;
            s.top++;
            s.cards[s.top]=t;
            book[t]=1;
        } else {
            q1.head++;
            q1.cards[q1.tail]=t;
            q1.tail++;
            while (s.cards[s.top]!=t) {
                book[s.cards[s.top]]=0;
                q1.cards[q1.tail]=s.cards[s.top];
                q1.tail++;
                s.top--;
            }
        }
        printf("\n桌上的牌是");
        for (int i=1; i<=s.top; i++) {
            printf(" %d",s.cards[i]);
        }

//        printf("q1手上牌数：%d\n",q1.tail-q1.head);
        
        t=q2.cards[q2.head];
        
        if (book[t]==0) {
            q2.head++;
            s.top++;
            s.cards[s.top]=t;
            book[t]=1;
        } else {
            q2.head++;
            q2.cards[q2.tail]=t;
            q2.tail++;
            while (s.cards[s.top]!=t) {
                q2.cards[q2.tail]=s.cards[s.top];
                q2.tail++;
                book[s.cards[s.top]]=0;
                s.top--;
            }
        }
        printf("\n桌上的牌是");
        for (int i=1; i<=s.top; i++) {
            printf(" %d",s.cards[i]);
        }

//        printf("q2手上牌数：%d\n",q2.tail-q2.head);
        
        if (q2.head == q2.tail) {
            printf("小哼win!\n");
            printf("小哼当前手中的牌是：\n");
            for (int i=q1.head; i<=q1.tail-1; i++) {
                printf(" %d",q1.cards[i]);
            }
            if (s.top>0) {
                printf("\n桌上的牌是");
                for (int i=1; i<=s.top; i++) {
                    printf(" %d",s.cards[i]);
                }
            }
            else printf("\n桌上已经没有牌了");
        } else if (q1.head == q1.tail) {
            printf("小哈win!\n");
            printf("小哈当前手中的牌是：\n");
            for (int i=q2.head; i<=q2.tail-1; i++) {
                printf(" %d",q2.cards[i]);
            }
            if (s.top>0) {
                printf("\n桌上的牌是");
                for (int i=1; i<=s.top; i++) {
                    printf(" %d",s.cards[i]);
                }
            }
            else printf("\n桌上已经没有牌了");
        }
    }
    
}






