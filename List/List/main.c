//
//  main.c
//  List
//
//  Created by 刘涛 on 4/27/16.
//  Copyright © 2016 LT. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, const char * argv[]) {
    struct node *head;
//    head = NULL;
    
    
    head = creatNode(head);
    print(head);
    char *result = isEmpty(head) == 0?  "不是空表" :"是空表";
    printf("\n%s\n\n",result);
//    insertANode(head);
//    print(head);
    deleteANode(head);
    print(head);
    
    return 0;
}





