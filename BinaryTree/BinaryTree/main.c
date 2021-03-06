//
//  main.c
//  BinaryTree
//
//  Created by 移动支付－刘涛 on 11/28/16.
//  Copyright © 2016 移动支付－刘涛. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct node{
    char value[5];
    int repeatTimes;
    struct node *lchild;
    struct node *rchild;
}Node;

typedef struct tree{
    Node *root;
    int size;
}Tree;

void insertANodeIntoTree(Node *newNode,Node *existNode){
    if (atoi(existNode->value) == atoi(newNode->value)) {
        (existNode->repeatTimes)++;
        return;
    } else if (atoi(existNode->value) >atoi(newNode->value)) {
        if (existNode->lchild == NULL) {
            existNode->lchild = newNode;
        } else {
            insertANodeIntoTree(newNode, existNode->lchild);
        }
    } else {
        if (existNode->rchild == NULL) {
            existNode->rchild = newNode;
        } else {
            insertANodeIntoTree(newNode, existNode->rchild);
        }
    }
}

void showTree(Node *node){
    //前序遍历
    /*
    if (node == NULL) {
        return;
    }
    for (int i=0; i<node->repeatTimes; i++) {
        printf("%s   ",node->value);
    }
    
    if (node->lchild != NULL) {
        showTree(node->lchild);
    }
    if (node->rchild != NULL) {
        showTree(node->rchild);
    }
     */
    /*
    //中序遍历
    if(node->lchild){
        showTree(node->lchild);
    }
    for (int i=0; i<node->repeatTimes; i++) {
        printf("%s   ",node->value);
    }
    if (node->rchild) {
        showTree(node->rchild);
    }
    */
    
    //后序遍历
    if(node->rchild){
        showTree(node->rchild);
    }
    if (node->lchild) {
     showTree(node->lchild);
    }
    for (int i=0; i<node->repeatTimes; i++) {
        printf("%s   ",node->value);
    }
}

int main(int argc, const char * argv[]) {
    Tree *myTree;
    Node *currentNode = malloc(sizeof(Node));
    currentNode->repeatTimes = 1;
    currentNode->lchild = NULL;
    currentNode->rchild = NULL;
    
    puts("Please input the root value:\n");
    while (gets(currentNode->value) != NULL && currentNode->value[0] != '\0' &&currentNode->value[0] != '\n') {
        if (myTree == NULL) {
            myTree = malloc(sizeof(Tree));
            myTree->root = currentNode;
        } else {
            insertANodeIntoTree(currentNode, myTree->root);
        }
        currentNode = malloc(sizeof(Node));
        currentNode->repeatTimes = 1;
        currentNode->lchild = NULL;
        currentNode->rchild = NULL;
    }
    
    showTree(myTree->root);
    
    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "Tree.h"

char menu(void);
void addpet (Tree * pt);
void droppet (Tree * pt);
void showpets (const Tree * pt);
void findpet (const Tree * pt);
void printitem (Item item);
void uppercase (char * str);


int main(int argc, const char * argv[]) {
    Tree pets;
    char choice;
    
    InitializeTree(&pets);
    while ((choice = menu()) != 'q') {
        switch (choice) {
            case 'a':
                addpet(&pets);
                break;
            case 'l':
                showpets(&pets);
                break;
            case 'f':
                findpet(&pets);
                break;
            case 'n':
                printf("%d pets in club\n",TreeItemCount(&pets));
                break;
            case 'd':
                droppet(&pets);
                break;
            default:
                puts("Switching error");
                break;
        }
    }
    
    DeleteAll(&pets);
    puts("Bye!");
    
    return 0;
}

char menu(void){
    int ch;
    
    puts("Nerfville Pet Club Membership Program");
    puts("Enter the letter correspinding to your choice:");
    puts("a) add a pet   l) show list of pets");
    puts("n) number of pets   f) find pets");
    puts("d) delete a pet   q) quit");
    
    while ((ch = getchar()) != EOF) {
        while (getchar()!='\n') {
            continue;
        }
        ch = tolower(ch);
        if (strchr("alfndq", ch) == NULL) {
            puts("Please enter an a,l,f,n,d or q");
        } else {
            break;
        }
    }
    
    if (ch == EOF) {
        ch = 'q';
    }

    return ch;
}


void addpet(Tree * pt){
    Item temp;
    
    if (TreeIsFull(pt)) {
        puts("No room in the club!");
    } else {
        puts("Please enter name of pet:");
        gets(temp.petname);
        puts("Please enter pet kind:");
        gets(temp.petkind);
        uppercase(temp.petname);
        uppercase(temp.petkind);
        AddItem(&temp, pt);
    }
}

void showpets(const Tree * pt){
    if (TreeIsEmpty(pt)) {
        puts("No enteries!");
    } else {
        Traverse(pt, printitem);
    }
}

void printitem(Item item){
    printf("Pet:%-19s kind:%-19s\n",item.petname,item.petkind);
}

void findpet(const Tree * pt){
    Item temp;
    
    if (TreeIsEmpty(pt)) {
        puts("No entries");
        return;
    }
    
    puts("Please enter name of pet you wish to find:");
    gets(temp.petname);
    puts("Please enter pet kind:");
    gets(temp.petkind);
    uppercase(temp.petname);
    uppercase(temp.petkind);
    printf("%s the %s ",temp.petname,temp.petkind);
    if (InTree(&temp, pt)) {
        printf("is a member.\n");
    } else {
        printf("is not a member.\n");
    }
}

void droppet(Tree * pt){
    Item temp;
    
    if (TreeIsEmpty(pt)) {
        puts("No entries!");
        return;
    }
    
    puts("Please enter name of pet you wish to delete:");
    gets(temp.petname);
    puts("Please enter pet kind:");
    gets(temp.petkind);
    uppercase(temp.petname);
    uppercase(temp.petkind);
    printf("%s the %s ",temp.petname,temp.petkind);
    if (DeleteItem(&temp, pt)) {
        printf("is dropped from the club.\n");
    } else {
        printf("is not a membet.\n");
    }
}

void uppercase (char * str){
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}

*/







