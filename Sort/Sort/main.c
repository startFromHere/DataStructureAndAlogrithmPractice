//
//  main.c
//  Sort
//
//  Created by 刘涛 on 12/28/15.
//  Copyright © 2015 LT. All rights reserved.
//

#include <stdio.h>

void sort();
void stackSequenceAndLinklist();

int main(int argc, const char *argv[]) {
    // insert code here...
    printf("Hello, World!\n");

//    stackSequenceAndLinklist();
    sort();
    return 0;
}

//排序练习
void sort() {
    int sourceArr[10] = {17, 33, 4, 12, 31, 10, 22, 5, 19, 16};
    int arrayLength = sizeof(sourceArr)/sizeof(sourceArr[0]);
    
    printf("数组长度：%lu  元素长度：%lu", sizeof(sourceArr),sizeof(sourceArr[0]));
    
    
    /**
     *  冒泡排序
     */
    //bubbleSort(sourceArr, arrayLength);
    
    
    /**
     *  选择排序
     */
    //selectSort(sourceArr, arrayLength);
    
    
    /**
     *  插入排序
     */
    //insertSort(sourceArr, arrayLength);
    
    
    /**
     *  快速排序
     */
    //quickSort(sourceArr, arrayLength);
    
    
    /**
     *  归并排序
     */
    mergeSort(sourceArr, arrayLength);
    
    for (int i=0; i<10; i++) {
        printf("\n%d",sourceArr[i]);
    }
    
}

