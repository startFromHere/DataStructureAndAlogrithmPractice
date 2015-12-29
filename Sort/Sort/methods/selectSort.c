//
//  selectSort.c
//  Sort
//
//  Created by 刘涛 on 12/28/15.
//  Copyright © 2015 LT. All rights reserved.
//

#include "selectSort.h"

void selectSort(int array[], int length){
    for (int i=0; i<length-1; i++) {
        int tempIndex = i;
        for (int j=i+1; j<length; j++) {
            if (array[tempIndex] > array[j]) {
                tempIndex = j;
            }
        }
        if (array[i] > array[tempIndex]) {
            swap(&array[i], &array[tempIndex]);
        }
    }
    
    for (int i = 0; i < length; i++) {
        printf("\narr[%d]:%d",i,array[i]);
    }
}
