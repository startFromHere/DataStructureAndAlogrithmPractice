//
//  list.h
//  List
//
//  Created by 刘涛 on 4/27/16.
//  Copyright © 2016 LT. All rights reserved.
//

#ifndef list_h
#define list_h

#include <stdio.h>


struct node * creatNode(struct node * head);
void print(struct node *head);
int isEmpty(struct node *head);
void insertANode(struct node *head);
void deleteANode(struct node *head);

#endif /* list_h */
