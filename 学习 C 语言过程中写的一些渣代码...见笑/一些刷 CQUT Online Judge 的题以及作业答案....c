//
//  main.c
//  C_playground1
//
//  Created by  Reign on 15/10/16.
//  Copyright © 2015年  Reign. All rights reserved.
//

/* A1 printf hello world
#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
*/


/* A2 定义为局部性质的数组 不理解
#include <stdio.h>
void main()
{
    int a[5]; //定义局部性质的数组
    int i;
    for(i=0;i<5;i++)
    {
        printf("%2d",a[i]);
    }
    printf("\n");
}
*/



/* A3 coj.cqut.edu.cn 1019
#include <stdio.h>
#define Pi 3.14
float volume(float a, float b)
{
    return(Pi*a*a*b);
}
float area(float c, float d)
{
    return(c*c*Pi*2+2*c*Pi*d);
}
int main(void)
{
    float r,h;
    printf("Please input the r and h.\n");
    scanf("%f%f",&r,&h);
    float vo ;
    vo = volume(r,h);
    float ar;
    ar = area(r,h);
    printf("%.3f %.3f",vo,ar);
    return 0;
}

*/

/* A4 coj.cqut.edu.cn 1020

#include<stdio.h>
float hehe(int a,int b)
{
    ;
}
int main()
{
    int c, d;
    scanf("%d %d",&c,&d);
    int e;
    //e = hehe(c,d);
    printf("%d",e);
    return 0;
}

*/

/* A5 coj.cqut.edu.cn 1021 failed...but last , succeed...

#include<stdio.h>
#include<math.h>
float jieFC(int a ,int b )
{
    float h, i;
    h = (float)a ,i = (float)b;
    return( (5-3*b)/(2*a));
}
int main(void)
{
    float a,b;
    float e;
    scanf("%f%f",&a,&b);
    //e = jieFC(c, d);
    e = (5-3*b)/(2*a);
    printf("%.1f",e);
    return 0;
}

*/

/* A5 coj.cqut.edu.cn 1030

#include <stdio.h>
int main()
{
    int x;
    int y;
    scanf("%d",&x);
    if (x <= 160)
        y = 10*x;
    else
        y = 1600+(x-160)*30;
    
    printf("%d",y);
    return 0;
}

*/

/* A6 coj.cqut.edu.cn 1028

#include <stdio.h>
int main()
{
    int x , y;
    scanf("%d",&x);
    if (x<=5)
        y = x*x+3*x-4;
    else
        y = x*x-5*x+7;
    printf("%d",y);
    return 0;
}

*/

/* A7 coj.cqut.edu.cn 1032

#include <stdio.h>
int main(void)
{
    int x;
    scanf("%d",&x);
    if(x>=90)
        printf("A");
    else if(x>=80 && x<90)
        printf("B");
    else if(x>=70 && x<80)
        printf("C");
    else if(x>=60 && x<70)
        printf("D");
    else
        printf("E");
    return 0;
}

*/

/* A8 coj.cqut.edu.cn 1031

#include <stdio.h>
#include <math.h>
float pf(float a,float b)
{
    return(pow(a,2)+pow(b,2));
}
int main(void)
{
    float x,y;
    scanf("%f%f",&x,&y);
    float c;
    c= pf(x,y);
    if( c == 20.25)
        printf("on");
    else if (c < 20.25)
        printf("in");
    else
        printf("out");
    return 0;
    
}

*/

/* A9 coj.cqut.edu.cn 1022

#include<stdio.h>
int main()
{
    char x;
    scanf("%c",&x);
    x = x+32;
    printf("%c",x);
    return 0;
}

*/

/* A10 coj.cqut.edu.cn 1023

#include<stdio.h>
int main()
{
    float a,b,c;
    scanf("%f%f%f",&a,&b,&c);
    printf("%.2f",(a+b+c)/3);
    return 0;
}

*/

/* A11 coj.cqut.edu.cn 1024

#include<stdio.h>
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d %d",a/b,a%b);
    return 0;
}

*/

/* A12 coj. 1025

#include<stdio.h>
int main()
{
    float a,b,c;
    scanf("%f%f",&a,&b);
    printf("%g %g\n",a,b);
    c=b,b=a,a=c;
    printf("%g %g",a,b);
    return 0;
}

*/

/* A13 coj. 1026

#include<stdio.h>
#include<math.h>
int hehe(int a1, int a2, int a3)
{
    return(pow(a2*a2-4*a1*a3,2));
}
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    printf("%d %d",(-b+hehe(a,b,c))/(2*a),(-b-hehe(a,b,c))/(2*a));
    return 0;
}

*/

/* A14 coj. 1027

#include<stdio.h>
int main()
{
    float money,year,rate;
    scanf("%f%f%f",&money,&year,&rate);
    printf("%.1f",money*pow((1+rate),year));
    return 0;
}

*/

/* A15 coj. 1034

#include <stdio.h>
int main()
{
    int i,n,sum;
    sum=0,i=1;
    scanf("%d",&n);
    while (i<=n)
    {
        sum = sum+(3*i-1);
        i=i+1;
    }
    printf("%d",sum);
}

*/

/* A16 P58 3.11 2 Ti

#include<stdio.h>
int main()
{
    char a ;
    scanf("%d",&a);
    printf("%c",a);
}

*/

/* A17 coj. 1035

#include<stdio.h>
int main()
{
    int i,n,x,max;
    i = 0,max = 0;
    scanf("%d",&n);
    while(n>0)
    {
        scanf("%d",&x);
        if(x >= max)
            max=x;
        else
            max=max;
        n=n-1;
    }
    printf("%d",max);
    return 0;
}

*/

/* A18 code[vs] 1201

#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    long a,max,min;
    max=-pow(2,31),min=pow(2,31)-1;
    scanf("%d",&n);
    while(n>0)
    {
        scanf("%ld",&a);
        if(a>max)
            max=a;
        if(a<min)
            min=a;
        n=n-1;
    }
    printf("%ld %ld",min,max);
    return 0;
}

*/

/* A19 code[vs] 1202

#include<stdio.h>
int main()
{
    int n;
    long a,sum;
    sum=0;
    scanf("%d",&n);
    while(n>0)
    {
        scanf("%ld",&a);
        sum = sum+a;
        n=n-1;
    }
    printf("%ld",sum);
    return 0;
}

*/

/* A20 code[vs] 1206

#include<stdio.h>
int main()
{
    double a;
    scanf("%lf",&a);
    printf("%.2lf",a);
    return 0;
}

*/

/* A21 code[vs] 1203 ||

#include<stdio.h>
int main()
{
    double a,b;
    scanf("%lf%lf",&a,&b);
    if((a-b)>0.00000001 || (b-a)>0.00000001)
        printf("no");
    else
        printf("yes");
    return 0;
}

*/

/* A22 code[vs] 2235

#include<stdio.h>

int main()
{
    int price;
    float cost,a;
    scanf("%d%f",&price,&cost);
    int c,d;
    a=price*cost*0.01;
    c=price*cost*0.01;
    if((a-c)>=0.5)
        c=c+1;

    d=c*10;
    printf("%d",d);
    return 0;
}

*/

/* A23 code[vs] 1023

#include<stdio.h>

int main()
{
    int a,i;
    float xia,shang,b,c;
    xia=0,shang=0;
    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        scanf("%f%f",&b,&c);
        shang=shang+b*c;
        xia=xia+b;
    }
    printf("%.2f",shang/xia);
    return 0;
}

*/

/* A24 code[vs] 1430

#include<stdio.h>
#include<math.h>
int main()
{
    unsigned int a,b,i;
    float c=0.0;
    scanf("%d",&a);
    b=sqrt(a);
    //printf("%d",b);
    for(i=2;i<=b;i++)
    {
        c=a%i;
        if(c==0)
            goto case1;
    }
    goto case3;
case1:printf("\\n");
    goto case2;
case3:printf("\\t");
case2:;
    return 0;
}

*/

/* A25 shuben P13

#include<stdio.h>
int main(){
    char c1,c2;
    c1=97;c2=98;
    printf("c1=%c c2=%c\n",c1,c2);
    printf("c1=%d c2=%d\n",c1,c2);
    c1=c1-32;c2=c2-32;
    printf("c1=%c c2=%c\n",c1,c2);
    printf("c1=%d c2=%d\n",c1,c2);

}

*/

/* A26 coj 1033 zuoye A 2815

#include<stdio.h>
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    printf("%d%d%d",a,b,c);
    return 0;
}

*/

/* A27 coj 1033 zuoye B 2816

#include <stdio.h>
int main(){
    int a,b,c;
    scanf("%d",&a);
    b=a%7;
    c=(a-b)/7;
    printf("%d days are %d weeks and %d days.",a,c,b);
    return 0;
}

*/

/* A28 coj 1033 zuoye C 2817 wrong

#include <stdio.h>
#include <math.h>
int main(){
    double a,b;
    scanf("%lf",&a);
    b=pow(a,3);
    printf("%.2f\n",b);
    return 0;
}

*/

/* A29 coj 1033 zuoye D 2818

#include <stdio.h>
int main()
{
    char a,b,c,d,e;
    scanf("%c%c%c%c%c",&a,&b,&c,&d,&e);
    a=a+4;b=b+4;c=c+4;d=d+4;e=e+4;
    printf("%c%c%c%c%c",a,b,c,d,e);
    return 0;
}

*/

/* A30 coj 1033 zuoye E 2819

#include<stdio.h>
int main()
{
    char x;
    scanf("%c",&x);
    x = x+32;
    printf("%c\n",x);
    return 0;
}

*/

/* A31 coj 1033 zuoye F 2820

#include<stdio.h>
int main()
{
    long int a,b,sum,max,min,c,d;
    scanf("%ld%ld",&a,&b);
    sum=a+b;
    a>b?(max=a,min=b):(max=b,min=a);
    c=max%min;
    d=(max-c)/min;
    printf("%ld %ld",sum,d);
    return 0;
}
 
*/

/* A32 coj 1033 zuoye G 2821

#include<stdio.h>
#define PI 3.14
int main()
{
    double r,c;
    scanf("%lf",&r);
    c=2*PI*r;
    printf("%.2lf %.2lf\n",c,r*r*PI);
}

*/

/* A33 实验五 三个数由小到大排列
 
#include<stdio.h>
int main()
{
    int a,b,c,max,min;
    scanf("%d%d%d",&a,&b,&c);
    if(a>b)
        max=a,min=b;
    else
        max=b,min=a;
    if(c>max)
        printf("%d %d %d",min,max,c);
    else if(c>min)
        printf("%d %d %d",min,c,max);
    else
        printf("%d %d %d",c,min,max);
    return 0;
}

*/

/* A34 1382 Problem  C

#include<stdio.h>
int main()
{
    long int n;
    long int sum=0;
    long int temp=1;
    scanf("%ld",&n);
    for(int i=1;i<=n;i++)
    {
        for(int a=1;a<=i;a++)
        {
            temp=temp*a;
        }
        sum=sum+temp;
        temp=1;
    }
    printf("%ld",sum);
    return 0;
}

*/

/* A35 E

#include<stdio.h>
int main()
{
    double k,i;
    double sum=0;
    double n=0;
    scanf("%lf",&k);
    for(i=1.0;;i++)
    {
        sum=sum+1.0/i;
        n=n+1;
        if(sum>k)
        {
            printf("%.lf",n);
            break;
        }
    }
    return 0;
}

*/

/* A36 G

#include<stdio.h>
int main()
{
    int taozi,tianshu;
    taozi=1;
    scanf("%d",&tianshu);
    for(;tianshu>1;tianshu--)
    {
        taozi=(taozi+1)*2;
    }
    printf("%d",taozi);

}

*/

/* A37 B

#include<stdio.h>
#include<math.h>
int main()
{
    double a,b,c;
    double sum=0;
    scanf("%lf%lf%lf",&a,&b,&c);
    for(int i=1.0;i<=a;i++)
    {
        sum=sum+i;
    }
    for(int i=1.0;i<=b;i++)
    {
        sum=sum+pow(i,2);
    }
    for(int i=1.0;i<=c;i++)
    {
        sum=sum+1.0/i;
    }
    printf("%.2lf",sum);
}

*/

/* A38 D

#include<stdio.h>
int main()
{
    int a;
    long int b,sum;
    sum=0;
    scanf("%d",&a);
    int i=0;
    while(i<a)
    {
        scanf("%ld",&b);
        if(b%2==0)
            sum=sum+b;
        
        i++;
    }
    printf("%ld",sum);
    return 0;
}

*/

/* A39 11.12

#include<stdio.h>

void exe_12()
{
    printf("请输入表的上限和下限。\n");
    int a,b;
    scanf("%d%d",&a,&b);
    for(;a<=b;a++)
        printf("%d %d %d\n",a,a*a,a*a*a);
}

void exe_13()
{
    
    char inp;
    printf("请输入一个大写字母：\n");
    
    fflush(stdin);
    
    scanf("%c",&inp);
    int line=inp-'A'+1;
    int oup=0;
    int currentLine=1;
    while(1)
    {
        for(int i=1;i<line;i++)
            printf(" ");
        line--;
        for(int m=1;m<=currentLine;m++)
        {
            printf("%c",'A'+oup);
            oup++;
        }
        oup--;
        for(int n=1;n<currentLine;n++)
        {
            oup--;
            printf("%c",'A'+oup);
        }
        currentLine++;
        
        printf("\n");
        if(line==0)
            break;
    }
}

void exe_17()
{
    int a=2;
    while(1)
    {
        int sum=0;
        for(int i=1;i<a;i++)
        {
            if(a%i==0)
                sum=sum+i;
        }
        if(sum==a)
        {
            printf("%d ",a);
        }
        a++;
        if(a>1000)
            break;
    }
}

void exe_20()
{
    float a,b,c;
    for(a=0;a<=34;a++)
    {
        for(b=0;b<=50;b++)
        {
            for(c=0;c<=100;c++)
            {
                if( (a+b+c)==100&&(3*a+2*b+0.5*c)==100 )
                    printf("大马%.f,中马%.f,小马%.f\n",a,b,c);
            }
        }
    }
}

void exe_28()
{
    int a,b;
    for(a=1;a<=9;a++)
    {
        for(b=a;b<=9;b++)
        {
            printf("%d*%d=%d\t",a,b,a*b);
        }
        printf("\n");
    }

}

int main()
{
    while(1)
    {
        int a;
        scanf("%d",&a);
        switch(a)
        {
            case 12:exe_12();break;
            case 13:exe_13();break;
            case 17:exe_17();break;
            case 20:exe_20();break;
            case 28:exe_28();break;
            default:printf("Error!\n");
        }
    }
}

*/















