//
//  bubbleSort.c
//  Sort
//
//  Created by 刘涛 on 12/28/15.
//  Copyright © 2015 LT. All rights reserved.
//

#include "bubbleSort.h"

void bubbleSort(int arr[], int length){
    for (int i = 0; i < length-1; i++) {
        for (int j = 0; j < length-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
        for (int i = 0; i < length; i++) {
            printf("\narr[%d]:%d",i,arr[i]);
        }
        printf("\n\n");
    }
    for (int i = 0; i < length; i++) {
        printf("\narr[%d]:%d",i,arr[i]);
    }
}
