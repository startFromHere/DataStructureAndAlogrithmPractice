//
//  quickSort.c
//  Sort
//
//  Created by 刘涛 on 12/28/15.
//  Copyright © 2015 LT. All rights reserved.
//

#include "quickSort.h"

void sortByIndexs(int array[], int smallIndex, int bigIndex);

void quickSort(int arr[], int length){
    if (length>1) {
        int endIndex = length-1;
        int startIndex = 0;
        int tempValue = arr[0];
        
        while (startIndex < endIndex) {
            tempValue = arr[startIndex];
            while (arr[endIndex] < tempValue) {
                endIndex--;
            }
            
            while (arr[startIndex] > tempValue) {
                startIndex++;
            }
            
            printf("startIndex:%d  endIndex:%d  ",startIndex,endIndex);
            
            arr[startIndex] = arr[endIndex];
            arr[endIndex] = tempValue;
        }
        
        
        quickSort(arr, startIndex);
        quickSort(arr+startIndex+1, length-startIndex-1);
    }

}
