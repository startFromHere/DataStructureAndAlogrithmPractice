//
//  quickSort.c
//  Sort
//
//  Created by 刘涛 on 12/28/15.
//  Copyright © 2015 LT. All rights reserved.
//

#include "quickSort.h"

void sortByIndexs(int array[], int smallIndex, int bigIndex);

void quickSort(int array[], int length){
    int startIndex = 0;
    int endIndex = length-1;
    sortByIndexs(array, startIndex, endIndex);
}

void sortByIndexs(int array[], int smallIndex, int bigIndex){
    if (smallIndex>=bigIndex) {
        return;
    }
    int endIndex = bigIndex;
    int startIndex = smallIndex;
    int referenceValue = array[startIndex];
    
    while (smallIndex < bigIndex) {
        while (array[bigIndex]>referenceValue) {
            bigIndex--;
        }
        while (array[smallIndex]<referenceValue) {
            smallIndex++;
        }
        
        swap(&array[smallIndex], &array[bigIndex]);
    }
    if (array[startIndex]<array[smallIndex]) {
        swap(&array[smallIndex], &array[smallIndex]);
        
        sortByIndexs(array, startIndex, smallIndex);
        sortByIndexs(array, smallIndex, endIndex);
    }
}