//
//  main.c
//  C_playground5_homework_10
//
//  Created by  Reign on 15/12/9.
//  Copyright © 2015年  Reign. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printfIntArray(int *p,int len,int newline) {
    printf("当前调用函数:输出长度为%d的整形数组...\n",len);
    if(newline)
        printf("当前格式:每输出%d个数据换一行\n",newline);
    int i;
    int c=1;
    for (i=0;i<len;i++,c++) {
        printf("%d\t",*(p+i));
        if( ( newline && !(c%newline) ) )
            printf("\n");
    }
    printf("输出完毕...\n");
}


void initIntArray(int *p,int len,int output) {
    //len为长度,output为是否输出到当前显示设备
    printf("当前调用函数:初始化长度为%d的整形数组...\n",len);
    srand((unsigned) time(NULL));
    int i;
    for(i=0;i<len;i++) {
        *(p+i)=rand()%1000-500;
        printf("%d ",i+1);//显示当前进度
    }
    printf("...\n初始化完毕!\n");
    if(output){
        printf("正在输出刚刚初始化的数组...\n");
        printfIntArray(p, len, output);
    }
    //如果初始化之后立即输出则传人参数output为非0,并且每输出output个数据换一行
}


void switchSort(int *p,int len) {
    printf("正在进行选择排序...\n");
    int i,j;
    int sign;//记录最小项下标
    int temp;//交换中介
    int count=0;//记录次数
    int judge;//判断是否交换,修改为1则为真即交换过
    for (i=0;i<len-1;i++,count++) {
        
        judge=0;
        sign=i;
        
        for (j=i;j<len;j++) {
            if ( *(p+sign) > *(p+1+j) ) {
                judge=1;
                sign=j+1;
            }
        }
        
        //if(!judge)
        //     break;
        
        temp=*(p+i);
        *(p+i)=*(p+sign);
        *(p+sign)=temp;
        
        for (int o=0;o<len;o++) {
            printf("%d\t",*(p+o));
        }
        printf("\n");
        
    }
    printf("选择排序完毕...总计%d次\n",count);
}

void exe_1() {
    printf("1.用指针作为函数参数，实现数组的选择排序\n");
    printf("请输入数组长度:");
    int len;
    scanf("%d",&len);
    int *p;
    p=(int *)malloc(sizeof(int)*len);
    initIntArray(p, len, 0);
    switchSort(p,len);
    printfIntArray(p,len,0);
    free(p);
}

void binarySearch(int *p, int len) {
    int low=0;
    int high=len;
    
}

void exe_2() {
    printf("2.用指针作为函数参数，实现有序数组的二分查找\n");
    printf("请输入数组长度:");
    int len;
    scanf("%d",&len);
    int *p;
    p=(int *)malloc(sizeof(int)*len);
    initIntArray(p, len, 0);
    switchSort(p,len);
    printfIntArray(p,len,20);
    binarySearch(p, len);
    free(p);
}

int main(void)
{
    //exe_1();
    
    return 0;
}
