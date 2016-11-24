//
//  main.c
//  C_playground2_xh_dg
//
//  Created by  Reign on 15/11/10.
//  Copyright © 2015年  Reign. All rights reserved.
//  此工程用来研究循环与函数递归


#include <stdio.h>


//下面是四个输出乘法表的函数。
void multiplicantion_1();
void multiplicantion_2();
void multiplicantion_3();
void multiplicantion_4();

//下面是对递归的研究。


//递归计算 n!
double factorial_1(double n);
double factorial_2(double n);

//递归求两个数最大公约数
long maxDivisor(long a,long b);

//递归之汉诺塔游戏
void moveStep(int a,int b);
void hanoi(int n,int a,int b,i

int main(int argc, const char * argv[]) {
    
//    multiplicantion_1();
//    multiplicantion_2();
//    multiplicantion_3();
//    multiplicantion_4();
    
    
//    printf("%lf",factorial_1(5));
//    printf("%ld",maxDivisor(2424,3333));
    startHanoi();
    return 0;
}

//下面是四个输出乘法表的函数。如果A*B=C，那么A=num_1,B=num_2。

//这是一个输出乘法表的函数，左下直角。市面上大部分乘法表都是如下格式。
//下面是输出样例。
/*
1*1=1
1*2=2	2*2=4
1*3=3	2*3=6	3*3=9
1*4=4	2*4=8	3*4=12	4*4=16
1*5=5	2*5=10	3*5=15	4*5=20	5*5=25
1*6=6	2*6=12	3*6=18	4*6=24	5*6=30	6*6=36
1*7=7	2*7=14	3*7=21	4*7=28	5*7=35	6*7=42	7*7=49
1*8=8	2*8=16	3*8=24	4*8=32	5*8=40	6*8=48	7*8=56	8*8=64
1*9=9	2*9=18	3*9=27	4*9=36	5*9=45	6*9=54	7*9=63	8*9=72	9*9=81
*/
void multiplicantion_1()
{
    int num_1=1,num_2=1;
    //printf("%d %d\n",num_1,num_2);
    //num_2为行数，所以在外层循环。
    for(;num_2<=9;num_2++)
    {
        for(;num_1<=num_2;num_1++)
            printf("%d*%d=%d\t",num_1,num_2,num_1*num_2);
        printf("\n");
        num_1=1;
    }
}

//这是一个输出乘法表的函数，右下直角。下面是输出样例。总感觉这个乘法表怪怪的。
/*
                                                                1*1=1
                                                        1*2=2	2*2=4
                                                1*3=3	2*3=6	3*3=9
                                        1*4=4	2*4=8	3*4=12	4*4=16
                                1*5=5	2*5=10	3*5=15	4*5=20	5*5=25
                        1*6=6	2*6=12	3*6=18	4*6=24	5*6=30	6*6=36
                1*7=7	2*7=14	3*7=21	4*7=28	5*7=35	6*7=42	7*7=49
        1*8=8	2*8=16	3*8=24	4*8=32	5*8=40	6*8=48	7*8=56	8*8=64
1*9=9	2*9=18	3*9=27	4*9=36	5*9=45	6*9=54	7*9=63	8*9=72	9*9=81
*/
void multiplicantion_2()
{
    int num_1=1,num_2=1;
    //printf("%d %d\n",num_1,num_2);
    //num_2为行数，所以在外层循环。
    for(;num_2<=9;num_2++)
    {
        for(int i=9-num_2;i>0;i--)
            printf("        ");
        for(;num_1<=num_2;num_1++)
            printf("%d*%d=%d\t",num_1,num_2,num_1*num_2);
        
        printf("\n");
        num_1=1;
        
    }
}

//这是一个输出乘法表的函数，左上直角。下面没有输出样例。因为

void multiplicantion_3()
{

//我居然画不出来左上直角的乘法表。。。醉了。
    
}


//这是一个输出乘法表的函数，右上直角。
//下面是输出样例。
/*
1*1=1	1*2=2	1*3=3	1*4=4	1*5=5	1*6=6	1*7=7	1*8=8	1*9=9
        2*2=4	2*3=6	2*4=8	2*5=10	2*6=12	2*7=14	2*8=16	2*9=18
                3*3=9	3*4=12	3*5=15	3*6=18	3*7=21	3*8=24	3*9=27
                        4*4=16	4*5=20	4*6=24	4*7=28	4*8=32	4*9=36
                                5*5=25	5*6=30	5*7=35	5*8=40	5*9=45
                                        6*6=36	6*7=42	6*8=48	6*9=54
                                                7*7=49	7*8=56	7*9=63
                                                        8*8=64	8*9=72
                                                                9*9=81
*/
void multiplicantion_4()
{
    int num_1=1,num_2=1;
    for(;num_1<=9;num_1++)
    {
        //num_1为行数，所以在外层循环。
        for(int i=num_1-1;i>0;i--)
            printf("        ");
        for(num_2=num_1;num_2<=9;num_2++)
            printf("%d*%d=%d\t",num_1,num_2,num_1*num_2);
        printf("\n");
        num_2=1;
    }
    
}

//下面是对递归的研究。

//递归计算 n!

double factorial_1(double n)
{
    double result=1;
    if(n==0)
        return result;
    else
        return n*factorial_1(n-1);
}

double factorial_2(double n)
{
    if(n==1)
        return 1;
    else
        return n*factorial_2(n-1);
}

//递归求两个数最大公约数

long maxDivisor(long a,long b)
{
    if(a%b==0)
        return b;
    else
        return maxDivisor(b,a%b);
}

/*
1. 输入 2424, 3333
2. (2424%3333=2424)!=0  , maxDivison(3333,2424%3333=2424)
3. 递归 3333, 2424
4. 递归 (2424, 909) - (909, 606) - (606, 303)
5. 返回 303
*/

//递归之汉诺塔游戏

void moveStep(int a,int b)
{
    printf("%d -> %d\n",a,b);
}
void hanoi(int n,int a,int b,int c)
{
    if(n==1)
        moveStep(a,c);
    else
    {
        hanoi(n-1,a,c,b);
        moveStep(a,c);
        hanoi(n-1,b,a,c);
    }
}
void startHanoi()
{
    int n;
    scanf("%d",&n);
    hanoi(n,1,2,3);
    //1.源 2.中间 3.目的
}
/*
    1 -> 3
    1 -> 2
    3 -> 2
    1 -> 3
    2 -> 1
    2 -> 3
    1 -> 3
 
input 3 
-> hanoi(3,1,2,3)    n3a1b2c3
-> hanoi(2,1,3,2)    n2a1b3c2
-> hanoi(1,3,1,2)    (3->2)
 
 
 
 
好吧，我承认自己还是没搞懂汉诺塔递归。。。
*/






