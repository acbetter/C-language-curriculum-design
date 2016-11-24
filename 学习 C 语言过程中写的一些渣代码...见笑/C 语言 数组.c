//
//  main.c
//  C_playground4_array
//
//  Created by  Reign on 15/11/20.
//  Copyright © 2015年  Reign. All rights reserved.
//  此工程用来研究数组。。。

#include <stdio.h>

#include <string.h>

#define Len 5

#define Len_100 100

void arrayInt_1()
{
    int i;
    int arr[Len];
    memset(arr,0,sizeof(int)*Len);
    for(i=0;i<Len;i++)
    {
        printf("%d ",arr[i]);
    }
}

void arrayInt_2()
{
    int i;
    int arr[Len]={1,2};
    
    for(i=0;i<Len;i++)
    {
        printf("%d ",arr[i]);
    }

}

void arrayChar_1()
{
    char arr[3]={'a','b','c'};
    //print abc\300\367\277_\377
    printf("%s",arr);
}

void arrayChar_2()
{
    char a[10],b[10],c[10]={'a','\0'};
    for(int i=0;i<10;i++)
        printf("%c ",a[i]);
    printf("\n");
    for(int i=0;i<10;i++)
        printf("%c ",b[i]);
    printf("\n");
    for(int i=0;i<10;i++)
        printf("%c ",c[i]);
    
}

void arrayChar_3()
{
    char i=1,a[100]={"afkh"};
    printf("%d",i);
    //memset(a,0,sizeof(char)*100);
    scanf("%s",&a[2]);
    printf("%s",a);
}

void arrayChar_4()
{
    char str[Len];
    int i;
    for(i=0;i<Len;i++)
        scanf("%c ",&str[i]);
    for(i=0;i<Len;i++)
        printf("%c ",str[i]);
}

void arrayChar_5()
{
    int i;
    char str[Len];
    for(i=1;i<Len;i++)
    {
        str[i]=getchar();
        if(str[i]=='\n')
            break;
    }
        
    
}

//冒泡排序
#define N 5
void bub_sort()
{
    int i,judge;
    long temp,arr[N];
    
    for(i=0;i<N;i++)
        scanf("%ld",&arr[i]);
    
    for(i=0;i<N-1;i++)
    {
        judge=1;
        for(int j=i;j<N-i-1;j++)
        {
            if(arr[j]<arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                judge=0;
            }
        }
        if(judge)
            break;
    }
    for(i=0;i<N;i++)
        printf("%ld ",arr[i]);
}

//选择排序
//#define N 5
//not redefined N but...
#define Ns 5
void switch_sort_maxToLeft()
{
    int i;
    long temp,a[Ns];
    for(i=0;i<Ns;i++)
        scanf("%ld",&a[i]);
    for(i=0;i<Ns-1;i++)
    {
        int record=i;
        for(int j=i;j<Ns-1;j++)
            if(a[j+1]>a[j])
                record=j+1;
        if(record!=i)
        {
            temp=a[i];
            a[i]=a[record];
            a[record]=temp;
        }
    }
    for(i=0;i<Ns;i++)
        printf("%ld ",a[i]);
}

// arrayTest

void arrayTest()
{
    
}

int main()
{
    //arrayInt_2();
    arrayChar_5();
    //switch_sort_maxToRight();
    
}
