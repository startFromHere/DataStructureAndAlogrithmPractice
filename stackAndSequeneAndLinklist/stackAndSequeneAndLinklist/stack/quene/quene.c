//
//  quene.c
//  stackAndSequeneAndLinklist
//
//  Created by 刘涛 on 12/29/15.
//  Copyright © 2015 LT. All rights reserved.
//

#include "quene.h"

void restoreNumbers(){
    int a[20] = {6, 3, 1, 7, 5, 8, 9, 2, 4};
    int header = 0, tail = 9;
    while (header != tail) {
        printf("%d\n",a[header]);
        a[tail++]=a[++header];
        header++;
    }
}