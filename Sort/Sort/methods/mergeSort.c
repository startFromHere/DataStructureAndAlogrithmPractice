//
//  mergeSort.c
//  Sort
//
//  Created by 刘涛 on 4/20/16.
//  Copyright © 2016 LT. All rights reserved.
//
#include "stdio.h"
#include "stdlib.h"
#include "mergeSort.h"

void merge_Array(int *a,int size_a,int *b,int size_b){
    int *tmp = malloc((size_a+size_b)*sizeof(int));
    
    int i,j,k;
    i=j=k=0;
    
    while (i<size_a && j<size_b) {
        tmp[k++] = (a[i]>b[j])?b[j++]:a[i++];
    }
    
    while (i<size_a) {
        tmp[k++]=a[i++];
    }
    
    while (j<size_b) {
        tmp[k++]=b[j++];
    }
    
    for (int p=0; p<k; ++p) {
        a[p] = tmp[p];
    }
    
    free(tmp);
}

void mergeSort(int array[],int length){
    if (length>1) {
        mergeSort(array, length/2);
        mergeSort(array+length/2, length-length/2);
        
        merge_Array(array,length/2,array+length/2,length-length/2);
    }
    
}