//
//  stack.c
//  stackAndSequeneAndLinklist
//
//  Created by 刘涛 on 12/29/15.
//  Copyright © 2015 LT. All rights reserved.
//

#include "stack.h"
#include <string.h>
void palindromeJudge(){
    for (int count=0; count<10; count++) {
        char a[101],s[101];
        int top;
        unsigned long i,len,mid,next;
        
        gets(a);
        len = strlen(a);
        mid = (len-1)/2;
        
        top=-1;
        for (i=0; i<=mid; i++) {
            s[++top]=a[i];
        }
        
        if (len%2==0) {
            next=mid+1;
        } else {
            next=mid;
        }
        
        for (i=next; i<len; i++) {
            if (a[i]!=s[top]) {
                break;
            }
            top--;
        }
        
        if (top==-1) {
            printf("YES");
        } else {
            printf("NO");
        }

    }
}
