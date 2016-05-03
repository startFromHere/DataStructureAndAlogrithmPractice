//
//  main.c
//  MaximumSequence
//
//  Created by 刘涛 on 4/22/16.
//  Copyright © 2016 LT. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void test1(int * arr,int length){
    int maxValue=0,fromIndex=0,toIndex=0;
    for (int i=0; i<6; i++) {
        int sum=0;
        for (int j=i; j<6; j++) {
            sum += *(arr+j);
            maxValue = maxValue<sum?sum:maxValue;
//            printf("\n[%d-%d]:%d",i,j,sum);
        }
    }
    
//    printf("\n\nmaximunValue:%d\n",maxValue);
}

int Max3(int a,int b,int c){
    int d=(a>b?a:b);
    return d>c?d:c;
}

int test2(int * arr,int left,int right){
    int MaxLeftSum,maxRightSum;
    int MaxLeftBorderSum,MaxRightBorderSum;
    int LeftBorderSum,RightBorderSum;
    int center,i;
    
    if (left == right) {
        if (arr[left]>0) {
            return arr[left];
        } else {
            return 0;
        }
    }
    
    center = (left+right)/2;
    MaxLeftSum = test2(arr, left, center);
    maxRightSum = test2(arr, center+1, right);
    
    MaxLeftBorderSum = 0;
    LeftBorderSum = 0;
    for (i=center; i>=left; i--) {
        LeftBorderSum += arr[i];
        if (LeftBorderSum > MaxLeftBorderSum) {
            MaxLeftBorderSum = LeftBorderSum;
        }
    }
    
    MaxRightBorderSum = 0;
    RightBorderSum = 0;
    for (i=center+1; i<right; i++) {
        RightBorderSum += arr[i];
        if (RightBorderSum>MaxRightBorderSum) {
            MaxRightBorderSum = RightBorderSum;
        }
    }

    int result = Max3(MaxLeftSum,maxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
//    printf("\nresult:%d",result);
    return result;
}

int test3(int * arr,int length){
    int temp=0;
    int sum=0;
    for (int i=0; i<length; i++) {
        sum += arr[i];
        if (sum < 0) {
            sum = 0;
        }else if (temp < sum) {
            temp = sum;
        }
    }
    
//    printf("sum:%d  tmp:%d",sum,temp);
    return sum;
}

int main(int argc, const char * argv[]) {
    time_t timep;
    struct tm *p;
    time(&timep);
    p=gmtime(&timep);
    
    printf("\n开始产生随机数,时间：%d:%d:%d",p->tm_hour,p->tm_min,p->tm_sec);
    
    int arr[10000000] = {-2,11,-4,13,-5,-2};
    for (int i=0; i<100000; i++) {
        arr[i] = (1-rand()%2*2)*rand()%20000000;
    }
    time(&timep);
    p=gmtime(&timep);
    printf("\n\n方法1，时间复杂度O(N*N),时间：%d:%d:%d",p->tm_hour,p->tm_min,p->tm_sec);
    test1(arr, 10000000);
    time(&timep);
    p=gmtime(&timep);
    printf("\n\n方法2，时间复杂度O(N*N),时间：%d:%d:%d",p->tm_hour,p->tm_min,p->tm_sec);
    test2(arr,0,9999999);
    time(&timep);
    p=gmtime(&timep);
    printf("\n\n方法3，时间复杂度O(N*N),时间：%d:%d:%d",p->tm_hour,p->tm_min,p->tm_sec);
    test3(arr,10000000);
    
    return 0;
}
