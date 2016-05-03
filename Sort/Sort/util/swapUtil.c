

//
//  swapUtil.c
//  Sort
//
//  Created by 刘涛 on 12/28/15.
//  Copyright © 2015 LT. All rights reserved.
//

#include "swapUtil.h"

void swap(int *num1, int *num2){
    int tempNum = *num1;
    *num1 = *num2;
    *num2 = tempNum;
}