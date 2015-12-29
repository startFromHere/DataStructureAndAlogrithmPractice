//
//  insertSort.c
//  Sort
//
//  Created by 刘涛 on 12/28/15.
//  Copyright © 2015 LT. All rights reserved.
//

#include "insertSort.h"

void insertSort(int array[], int length) {
    for (int i=1; i<length; i++) {
        for (int j=0; j<i; j++) {
            if (array[i] < array[j]) {
                int temp = array[i];
                for (int k=i; k>j; k--) {
                    array[k] = array[k-1];
                }
                array[j] = temp;
            }
        }
    }
    for (int i = 0; i < length; i++) {
        printf("\narr[%d]:%d",i,array[i]);
    }
}