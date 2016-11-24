//
//  main.c
//  C_playground5_homework_7_8
//
//  Created by  Reign on 15/11/27.
//  Copyright © 2015年  Reign. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <math.h>



void exe_1()
{
    printf("8.2.1 编写一个程序，求一个整形数组中存储的最大数值。\n");
    int array_int[5]={5,8,90,-4,2};
    int max=array_int[0];
    for (int i=1; i<5; i++)
    {
        if (array_int[i]>max)
            max=array_int[i];
    }
    printf("max=%d\n",max);
}

void exe_2()
{
    printf("8.2.2 编写一个程序，求一个double型数组中存储的最大数值的下标。\n");
    double array_double[5]={59.3,-9.07,78,5,0.3};
    int sign=0;
    double currentMax=array_double[0];
    for (int i=1; i<5; i++)
    {
        if (array_double[i]>currentMax)
        {
            sign=i;
            currentMax=array_double[i];
        }
    }
    printf("sign=%d\n",sign);
}

void exe_3()
{
    printf("8.2.3 编写一个程序，计算一个整形数组中最大的和最小的数之间的差值。\n");
    int array_int[5]={5,8,90,-4,2};
    int currentMax=array_int[0];
    int currentMin=currentMax;
    for (int i=1; i<5; i++)
    {
        if (array_int[i]>currentMax)
            currentMax=array_int[i];
        else
            currentMin=array_int[i];
    }
    printf("Max=%d,Min=%d\n",currentMax,currentMin);
}

void exe_4()
{
    printf("8.2.4 编写一个程序，把两个数组内的相应元素相加，结果存储到第三个数组内。\n");
    int array_1[5]={5,8,90,-4,2};
    int array_2[5]={1235,87,-4860,4,0};
    int array_3[100];
    memset(array_3, 0, sizeof(int)*100);
    for (int i=0; i<5; i++)
    {
        array_3[i]=array_1[i]+array_2[i];
        printf("array_3[%d]=%d\n",i,array_3[i]);
    }
    
}

int IsPrimeNumber(int num)
{
    int i;
    if (num==1)
        return 0;
    for (i=2; i<=sqrt(num); i++)
    {
        if (num%i==0)
            return 0;
    }
    return 1;
}

void exe_5()
{
    printf("8.2.5 在一个数组中存放20个整数，统计并数次该数组中素数的个数。\n");
    printf("初始化数组为 1,2,3 ... 19,20.\n");
    int array_int[20];
    int i;
    int num=0;
    for (i=0; i<20; i++)
        array_int[i]=i+1;
    for (i=0; i<20; i++)
        if (IsPrimeNumber(array_int[i])==1)
            num++;
    
    printf("num=%d\n",num);
}

void InputIntArray(int array[],int length)
{
    printf("当前整形数组长度为：%d\n",length);
    memset(array, 0, sizeof(int)*length);
    printf("请初始化数组：\n");
    int temp;
    for (int i=0; i<length; i++)
    {
        scanf("%d",&temp);
        array[i]=temp;
    }
}

void OutputIntArray(int array[],int length)
{
    printf("正在输出长度为%d的整形数组...\n",length);
    for (int i=0; i<length; i++)
        printf("%d ",array[i]);
    printf("输出完毕\n");
}

void TestIntArray()
{
    int array_test[4]={5};
    InputIntArray(array_test,4);
    OutputIntArray(array_test,4);
}

void InputDoubleArray(double array[],int length)
{
    printf("当前Double形数组长度为：%d\n",length);
    memset(array, 0, sizeof(double)*length);
    printf("请初始化数组：\n");
    double temp;
    for (int i=0; i<length; i++)
    {
        scanf("%lf",&temp);
        array[i]=temp;
    }
}

void OutputDoubleArray(double array[],int length)
{
    printf("正在输出长度为%d的整形数组...\n",length);
    for (int i=0; i<length; i++)
        printf("%g ",array[i]);
    printf("输出完毕\n");
}

void TestDoubleArray()
{
    double array_test[4]={5};
    InputDoubleArray(array_test,4);
    OutputDoubleArray(array_test,4);
}


void exe_6()
{
    printf("8.2.6 任意输入20个数到一维数组a中，求20个数的平均值。\n");
    double array[20],average=0;
    InputDoubleArray(array, 20);
    for (int i=0; i<20; i++)
        average+=array[i];
    average/=20;
    printf("average=%g\n",average);
}


void exe_7()
{
    printf("8.2.7 编写一个程序，输出如下杨辉三角。\n");
    int array[100][100]={0};
    for (int j=0; j<100; j++)
            array[j][1]=1;
    int line,column;
    int input;
    printf("请输入行数:\n");
    scanf("%d",&input);
    for (line=1; line<=input; line++)
    {
        for (column=2; column<=line; column++)
            array[line][column]=array[line-1][column]+array[line-1][column-1];
    }
    for (line=1; line<=input; line++)
    {
        for (column=1; column<=line; column++)
        {
            printf("%d\t",array[line][column]);
        }
        printf("\n");
    }
}

void InitIntTwoDArray_3(int array[][3],int line,int column)
{
    
    for (int i=0; i<line; i++)
    {
        printf("请依次输入二维数组第%d行的值\n",i+1);
        for (int j=0; j<column; j++)
            scanf("%d",&array[i][j]);
    }
    printf("输入完毕！\n");
}

void SwapInt(int *a,int *b)
{
    int temp;
    int *c=&temp;
    *c=*a;
    *a=*b;
    *b=*c;
}

void exe_81();
void exe_82();
void exe_83();


void exe_8()
{
    printf("8.2.8 编写程序，实现矩阵（3行3列）的转置（即行列互换）。\n");
    
    printf("1.数组地址;2.行指针;3.列指针\n");
    int num;
    scanf("%d",&num);
    switch (num)
    {
        case 1:exe_81();break;
        case 2:exe_82();break;
        case 3:exe_83();break;
        default:printf("输入有误,直接退出exe_8\n");break;
    }
    
}

void exe_81()
{
    
    int array[3][3];
    int line,column;
   
    InitIntTwoDArray_3(array,3,3);
    
    for (line=0; line<3; line++)
    {
        for (column=0; column<=line; column++)
        {
            SwapInt(&array[line][column], &array[column][line]);
        }
    }
    
    for (line=0; line<3; line++)
    {
        for (column=0; column<3; column++)
        {
            printf("%d ",array[line][column]);
        }
        printf("\n");
    }
}

void exe_82()
{
    int array[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    
    int (*p)[3];//行指针
    p=array;
    
    printf("正在输出原始数组...\n");
    int i,j;
    for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
        {
            printf("%d ",*(*(p+i)+j));
        }
        printf("\n");
    }
    
    printf("正在转置...\n");
    for (i=0; i<3; i++)
    {
        for (j=0; j<i; j++)
        {
            SwapInt(*(p+i)+j, *(p+j)+i);
        }
    }
    
    printf("正在输出...\n");
    for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
        {
            printf("%d ",*(*(p+i)+j));
        }
        printf("\n");
    }
    
}

void exe_83()
{
    int array[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    
    int *p;//列指针
    p=array[0];
    
    printf("正在输出原始数组...\n");
    int i,j;
    for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
        {
            printf("%d ",*(p+3*i+j));
        }
        printf("\n");
    }
    
    printf("正在转置...\n");
    for (i=0; i<3; i++)
    {
        for (j=0; j<i; j++)
        {
            SwapInt(p+3*i+j, p+3*j+i);
        }
    }
    
    printf("正在输出...\n");
    for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
        {
            printf("%d ",*(p+3*i+j));
        }
        printf("\n");
    }
    
}


/*  0   1   2   3
 
0   1   2   3   4
1   5   6   7   8
2   9   10  11  12
3   13  14  15  16
 
*/

void exe_9()
{
    printf("8.2.9 定义两个二维数组，分别对这两个数组输入数据，求A+B和A-B的值。\n");
    int array_1[2][3],array_2[2][3];
    InitIntTwoDArray_3(array_1,2,3);
    InitIntTwoDArray_3(array_2,2,3);
    int i,j;
    for (i=0; i<2; i++)
    {
        for (j=0; j<3; j++)
        {
            printf("%d\t",array_1[i][j]+array_2[i][j]);
        }
        printf("\n");
    }
    for (i=0; i<2; i++)
    {
        for (j=0; j<3; j++)
        {
            printf("%d\t",array_1[i][j]-array_2[i][j]);
        }
        printf("\n");
    }
}

void exe_10()
{
    printf("8.2.10 求一个3*3的整形矩阵对角线元素之和。\n");
    int array[3][3];
    InitIntTwoDArray_3(array, 3, 3);
    int i,j;
    int sum=0;
    for (i=0; i<3; i++)
        for (j=0; j<3; j++)
            if (i==j||i+j==2)
                sum+=array[i][j];
    printf("sum=%d\n",sum);
}

void exe_11()
{
    printf("8.2.11 运行下面的程序，写出结果，注意指针的使用方式（逃）\n");
    int a[6]={1,2,3,4};
    int i,s=1;
    int *p=NULL;
    p=a;
    for (i=0; i<6; i++)
        s*= *(p+i);
    printf("%d\n",s);
    printf("输出数组累乘，1*2*3*4*0*0（逃）\n");
}

void InputIntArray_Pointer(int *p,int length)
{
    printf("当前整形数组长度为：%d\n",length);
    memset(p, 0, sizeof(int)*length);
    printf("请初始化数组：\n");
    for (int i=0; i<length; i++)
        scanf("%d",p+i);
}

void OutputIntArray_Pointer(int *p,int length)
{
    printf("正在输出长度为%d的整形数组...\n",length);
    for (int i=0; i<length; i++)
        printf("%d ",*(p+i));
    printf("输出完毕\n");
}


void exe_12()
{
    printf("8.2.12 定义一个一维数组，编写两个函数，分别输入、输出数组全部元素的值，用指针的方法实现（哭）\n");
    int array[3];
    InputIntArray_Pointer(array,3);
    OutputIntArray_Pointer(array,3);
}

void exe_13()
{
    printf("8.2.13 运行下面的程序，写出运行结果，注意指针的使用方式（逃）\n");
    int a[]={1,3,5};
    int *p=NULL;
    p=a;
    printf("*p\t->\t%d\n",*p);
    printf("*(++p)\t->\t%d\n",*(++p));
    printf("*++p\t->\t%d\n",*++p);
    printf("*(p--)\t->\t%d\n",*(p--));
    printf("*p--\t->\t%d\n",*p--);
    printf("*p++\t->\t%d\n",*p++);
    printf("++(*p)\t->\t%d\n",++(*p));
    printf("*p\t->\t%d\n",*p);
    printf("(*p)++\t->\t%d\n",(*p)++);
    printf("*p\t->\t%d\n\n",*p);
    
    p=&a[2];
    printf("p=&a[2]\n");
    printf("*p\t->\t%d\n",*p);
    printf("*(++p)\t->\t%d\n神越界，哈哈！\n",*(++p));
    p++;
    printf("p++\n");
    printf("*p\t->\t%d\n",*p);
   
}

#define FIFTEEN 15

void exe_14()
{
    printf("8.3.1 用冒泡排序法对15个整数由大到小进行排序\n");
    int array[FIFTEEN];
    int *p;
    p=array;
    InputIntArray_Pointer(array, FIFTEEN);
    
    for (int i=0; i<FIFTEEN-1; i++)
        for (int j=0; j<FIFTEEN-1-i; j++)
            if (p+j<p+j+1)
                SwapInt(p+j, p+j+1);
    
    OutputIntArray_Pointer(array, FIFTEEN);
}

#define TWENTY 20

void exe_15()
{
    printf("8.3.2 输入a1,a2,a3, ... , a20 将它们用从小到大排序后输出，并给出现在每个元素所对应的原来次序。\n");
    int array[TWENTY][2];
    int i;
    for (i=0; i<TWENTY; i++)
    {
        scanf("%d",&array[i][0]);
        array[i][1]=i+1;
    }
    for (int j=0; j<TWENTY-1; j++)
    {
        for (int k=0; k<TWENTY-1-j; k++)
        {
            if (array[k][0]>array[k+1][0])
            {
                SwapInt(&array[k][0], &array[k+1][0]);
                SwapInt(&array[k][1], &array[k+1][1]);
            }
        }
    }
    for (i=0; i<TWENTY; i++)
    {
        printf("%d\t%d\n",array[i][0],array[i][1]);
    }
}

void exe_16()
{
    printf("8.3.3 将一个数组的值按逆序重新存放。\n");
    int array[5]={8,6,5,4,1};
    for (int i=0; i<5/2; i++)
        SwapInt(&array[i], &array[4-i]);
    OutputIntArray(array, 5);
}

void exe_17()
{
    printf("8.3.4 将一个数组的元素初始化为有序的，要求输入一个数后，按原来排序的规律将它插入数组中。\n");
    int array[100];
    memset(array, 0, sizeof(int)*100);
    InputIntArray_Pointer(array, 7);
    int input,i,sign=0;
    //int *p=&sign;
    scanf("%d",&input);
    if (array[0]<array[6])
    {
        for (i=0; i<7; i++)
        {
            if (input<array[i])
            {
                sign=i;
                break;
            }
        }
    }
    else
    {
        for (i=0; i<7; i++)
        {
            if (input>array[i])
            {
                sign=i;
                break;
            }
        }
    }
    for(int j=8;j>sign;j--)
        array[j]=array[j-1];
    
    
    array[sign]=input;
    
    OutputIntArray_Pointer(array, 8);
}

void exe_18()
{
    printf("8.3.5 已知5个学生的3门功课的成绩。计算每一个学生的总分及平均分，统计平均成绩低于60分的学生人数。\n");
    float arr[5][5]={{70,53.5,90},{34.5,78,94},{98,99,100},{45,85.5,34}};
    int sum=0;
    for (int i=0; i<5; i++)
    {
        arr[i][3]=arr[i][0]+arr[i][1]+arr[i][2];
        arr[i][4]=arr[i][3]/3.0;
        if (arr[i][4]<60)
            sum++;
    }
    printf("sum=%d\n",sum);
}

void InputIntTwoDArray_5(int array[][5],int line,int column)
{
    
    for (int i=0; i<line; i++)
    {
        printf("请依次输入二维数组第%d行的值\n",i+1);
        for (int j=0; j<column; j++)
            scanf("%d",&array[i][j]);
    }
    printf("输入完毕！\n");
}

void OutputIntTwoDArray_5(int array[][5],int line,int column)
{
    
    for (int i=0; i<line; i++)
    {
        printf("正在输出二维数组第%d行的值\n",i+1);
        for (int j=0; j<column; j++)
            printf("%d\t",array[i][j]);
    }
    printf("输出完毕！\n");
}


void exe_19()
{
    printf("8.3.6 输入矩阵5行5列，完成下列要求\n1.输出矩阵a\n2.将a的第二行和第五行元素对调后，形成新的矩阵a并输出\n3.将对角线（左上到右下）的元素分别去除相应行的元素，又形成一个新的矩阵a并输出（哭）\n");
    int arr[5][5];
    InputIntTwoDArray_5(arr, 5, 5);
    
    OutputIntTwoDArray_5(arr, 5, 5);
    
    for (int i=0; i<5; i++)
        SwapInt(&arr[1][i], &arr[4][i]);
    
    OutputIntTwoDArray_5(arr, 5, 5);
    
    for (int j=0; j<5; j++)
    {
        for (int k=j; k<4; k++)
        {
            arr[j][k]=arr[j][k+1];
        }
    }
    
    OutputIntTwoDArray_5(arr, 5, 4);
}

#define FIVE 5

void exe_20()
{
    printf("8.3.7 输出二维数组(5*5)每行最大的数之间的最小值（哭）\n");
    int a[FIVE][FIVE];
    InputIntTwoDArray_5(a, 5, 5);
    int row,col,max,min;
    //为了忽略xcode警告，加一句min=0。实际上并不需要。
    min=0;
    for (row=0; row<FIVE; row++)
    {
        for (max=a[row][0],col=1; col<FIVE; col++)
            if (a[row][col]>max)
                max=a[row][col];
        if (row==0)
            min=max;
        else if(min>max)
            min=max;
    }
    printf("The min of max numbers is %d\n",min);
}

void BubbleSort(int arr[],int len)
{
    int sign;
    for (int i=0; i<len-1; i++)
    {
        sign=1;
        for (int j=0; j<len-1-i; j++)
        {
            if (arr[j]>arr[j+1])
            {
                SwapInt(&arr[j], &arr[j+1]);
                sign=0;
            }
        }
        if (sign)
            break;
    }
}

void SelectionSort(int arr[],int len)
{
    int sign,temp;
    for (int i=0; i<len-1; i++)
    {
        sign=1;
        temp=i;
        for (int j=i+1; j<len-1; j++)
        {
            if (arr[j]>arr[temp])
            {
                temp=j;
                sign=0;
            }
        }
        if (sign)
                break;
        SwapInt(&arr[i], &arr[temp]);
    }
}

void exe_21()
{
    printf("8.3.8 输入a1,a2, ... ,a10\n1.将它们从小到大排序输出：用改进的冒泡排序完成\n2.将它们从大到小排序输出：用选择排序和改进的选择排序完成（哭）\n");
    int arr_1[10]={47,-8,92,0,7,42,-74,89,-34,3};
    BubbleSort(arr_1,10);
    OutputIntArray(arr_1, 10);
    int arr_2[10]={47,-8,92,0,7,42,-74,89,-34,3};
    SelectionSort(arr_2, 10);
    OutputIntArray(arr_2, 10);
}

void exe_22()
{
    printf("8.3.9 编写程序，将两个两位数的正整数a、b合并形成一个整数放在c中。合并的方式是：将a数的十位和个位数依次放在c数的十位和千位上，b数的十位和个位数依次放在c数的个位和百位上。（晕）\n");
    int a=45,b=12;
    int c=a/10*10+a%10*1000+b/10+b%10*100;
    printf("a=%d\tb=%d\tc=%d\n",a,b,c);
}

int IsPrime(int *data,int *primes,int len)
{
    //data数组存放素数，primes数组存放素数在data中的下标，len表示data数组长度
    int i,a,num,sign;
    int count=0;
    for (i=0; i<len; i++)
    {
        num=*(data+i);
        
        sign=1;
        if (num==1)
            continue;
        
        for (a=2; a<=sqrt(num); a++)
        {
            if (num%a==0)
            {
                sign=0;
                break;
            }
        }
        if (sign)
        {
            *primes=i;
            primes++;
            count++;
        }
    }
    return count;
}

void exe_23()
{
    printf("8.3.10 在一个数组data中存放n(n<=1024)个素数，编写函数，判断该数组中哪些是素数，并统计素数的个数，在主函数中输出素数的个数和这些素数。（哭）\n");
    
    int data[1024]={0};
    int primes[1024]={0};
    
    int len,i;
    printf("你将要输入多少个数字?\n");
    scanf("%d",&len);
    for (i=0; i<len; i++)
        scanf("%d",data+i);
    
    int a;
    a=IsPrime(data, primes, len);
    printf("素数的个数是%d\n下面输出这些素数:\n",a);
    for (i=0; i<a; i++)
        printf("%d ",data[*(primes+i)]);
    
    printf("输出完毕\n");
    
}

#define N 5

void InputDoubleTwoDArray_N_N(double array[N][N],int line,int column)
{
    
    for (int i=0; i<line; i++)
    {
        printf("请依次输入二维数组第%d行的值\n",i+1);
        for (int j=0; j<column; j++)
            scanf("%lf",&array[i][j]);
    }
    printf("输入完毕！\n");
}


void MatrixSearch(double maxtrix[][N],double *pMax,double *pMin,int n)
{
    *pMax=*pMin=maxtrix[0][0];
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (maxtrix[i][j]>*pMax)
                *pMax=maxtrix[i][j];
            if (maxtrix[i][j]<*pMin)
                *pMin=maxtrix[i][j];
        }
    }
}

void exe_24()
{
    printf("8.3.11 编写函数，求n阶矩阵中最大元素与最小元素的值。（哭）\n");
    double max,min;
    double *pMax,*pMin;
    pMax=&max,pMin=&min;
    double arr[N][N];
    InputDoubleTwoDArray_N_N(arr,N,N);
    MatrixSearch(arr,pMax,pMin,N);
    printf("Max=%g,Min=%g\n",*pMax,*pMin);
}

#include <stdlib.h>
#include <time.h>

void Sort(int intArray[],int intLength)
{
    for (int i=0; i<intLength-1; i++)
        for (int j=0; j<intLength-1-i; j++)
            if (intArray[j]>intArray[j+1])
                SwapInt(&intArray[j], &intArray[j+1]);
}

void exe_25()
{
    printf("8.3.12 写一个函数，用“冒泡排序法”对n个整数从小到大排序。编写主函数main，使用随机函数产生大小处于100-350之间的20个随机整数，调用该函数进行排序并输出排序后的结果（随机函数是啥子？能吃吗？）\n");
    int arr[20];
    srand((unsigned) time(NULL)); //用时间做种，每次产生随机数不一样
    printf("下面输出产生的随机数...\n");
    for (int i=0; i<20; i++)
    {
        int number = rand() % 250 + 100;  //产生100-350的随机数
        printf("%d ", number);
        arr[i]=number;
    }
    printf("输出完毕\n");
    Sort(arr, 20);
    OutputIntArray(arr, 20);
}

int search(char *list,char c,int len)
{
    int low=0,high=len-1,k;
    //printf("%c ",*list+1);
    while (high>=low)
    {
        k=(low+high)/2;
        //printf("high=%d,low=%d,k=%d ",high,low,k);
        if (*list+k ==c)
            return k;
        else if (*list+k >c)
            high=k-1;
        else
            low=k+1;
    }
    return -1;
}

void exe_26()
{
    printf("8.3.13 在已按字母次序...二分法是啥子？能分我一半吗？\n");
    char arr[26];
    for (int i=0; i<26; i++)
    {
        arr[i]='a'+i;
        printf("%c ",arr[i]);
    }
    printf("初始化完毕\n请输入要查找的元素...\n");
    char temp;
    do
    {
        scanf("%c",&temp);
        
    }while (temp=='\n');
    printf("Finding %c,please wait...\n",temp);
    printf("%d\n",search(arr, temp, 26));
    
}

// 下面是 demo 函数

void demo()
{
    int sum;
    while (1)
    {
        printf("Please input num :\n");
        scanf("%d",&sum);
        switch (sum)
        {
            case 1:exe_1();continue;
            case 2:exe_2();continue;
            case 3:exe_3();continue;
            case 4:exe_4();continue;
            case 5:exe_5();continue;
            case 6:exe_6();continue;
            case 7:exe_7();continue;
            case 8:exe_8();continue;
            case 9:exe_9();continue;
            case 10:exe_10();continue;
            case 11:exe_11();continue;
            case 12:exe_12();continue;
            case 13:exe_13();continue;
            case 14:exe_14();continue;
            case 15:exe_15();continue;
            case 16:exe_16();continue;
            case 17:exe_17();continue;
            case 18:exe_18();continue;
            case 19:exe_19();continue;
            case 20:exe_20();continue;
            case 21:exe_21();continue;
            case 22:exe_22();continue;
            case 23:exe_23();continue;
            case 24:exe_24();continue;
            case 25:exe_25();continue;
            case 26:exe_26();continue;
            default:break;
        }
        break;
    }
}

// 下面是 main 函数

int main()
{
    demo();
    //TestIntArray();
    //TestDoubleArray();
   
    return 0;
}