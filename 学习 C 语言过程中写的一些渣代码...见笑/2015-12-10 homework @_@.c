//
//  main.c
//  C_playground5_homework_9
//
//  Created by Reign on 15/12/3.
//  基于C99编写，请尽量不要使用vc++6.0等编译器编译
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stringContact(char *str1,char *str)
{
    //void exe_11()
    int a=0;
    while (1)
    {
        if (*(str1+a)=='\0')
            break;
        a++;
    }
    int b=0;
    while (1)
    {
        *(str1+a+b)=*(str+b);
        if (*(str+b)=='\0')
            break;
        b++;
    }
    
    
}
#define ELEVEN 100
void exe_11()
{
    printf("9.3.2 编写一个函数,将两个字符串连接起来.\n");
    unsigned long M = 100;
    char *p = NULL;
    p=(char *)malloc(sizeof(char)* M);
    char *q = NULL;
    q=(char *)malloc(sizeof(char)* M);
    
    printf("请输入第一个字符串: ");
    scanf("%99s",p);
    printf("请输入第二个字符串: ");
    scanf("%99s",q);
    printf("第一个字符串是: %s\n第二个字符串是: %s\n",p,q);
    stringContact(p,q);
    printf("连接之后是: %s\n",p);
    
    free(p);
    p = NULL;
    free(q);
    q = NULL;

}

void charSwap(char *p,char *q)
{
    //void exe_12()
    char c;
    char *r=&c;
    *r=*q;
    *q=*p;
    *p=*r;
}

void stringInvert(char *str)
{
    //void exe_12()
    unsigned long a=strlen(str);
    int i;
    for (i=0; i<(a/2); i++)
    {
        charSwap(str+i,str+a-i-1);
    }
}

void exe_12()
{
    printf("9.3.3 编写一个函数,使字符串反序.\n");
    unsigned long M = 100;
    char *p=NULL;
    p=(char *)malloc(sizeof(char)* M);
    printf("请输入字符串: ");
    scanf("%99s",p);
    printf("反序之前是: %s\n",p);
    stringInvert(p);
    printf("反序之后是: %s\n",p);
}

void exe_13()
{
    printf("9.3.4 编写一个函数,将一个字符串中的元音字母复制到另一个字符串,然后输出.\n");
    unsigned long M = 100;
    char *p=NULL;
    p=(char *)malloc(sizeof(char)* M);
    char *q=NULL;
    q=(char *)malloc(sizeof(char)* M);
    
    printf("请输入字符串: ");
    scanf("%99s",p);
    int i,j;
    
    for(i=0,j=0;*(p+i)!='\0';i++)
    {
        switch (*(p+i))
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                *(q+j)=*(p+i);
                j++;
                break;
            default:break;
        }
    }
    printf("输出的字符串是: %s\n",q);
    free(p);
    p = NULL;
    free(q);
    q = NULL;
}

void strStatistics(char strings[],int pNum[])
{
    int i;
    printf("正在初始化计数数组...\n");
    for (i=0; i<4; i++)
    {
        *(pNum+i)=0;
    }
    printf("正在统计字符串中字母 数字 空格和其它字符的个数...\n");
    for (i=0; strings[i]!='\0'; i++)
    {
        if ( (strings[i]>='A'&&strings[i]<='Z') || (strings[i]>='a'&&strings[i]<='z') )
            pNum[0]++;
        else if (strings[i]>='0'&&strings[i]<='9')
            pNum[1]++;
        else if (strings[i]==' ')
            pNum[2]++;
        else
            pNum[3]++;
    }
    printf("统计完毕!\n");
}

void exe_14()
{
    printf("9.3.5 编写一个函数,由实参传来一个字符串,统计该字符串中字母 数字 空格和其它字符的个数.\n");
    unsigned long M = 100;
    char *p=NULL;
    p=(char *)malloc(sizeof(char)* M);
    
    printf("请输入字符串: ");
    int len;
    char ch;
    //由于fflush(stdio)无法清空"输入缓冲区",所以使用吃回车大法!
    while((ch=getchar())!='\n'&&ch!=EOF);
    for (len=0;len<M && (ch=getchar() )!='\n';len++)
        p[len]=ch;
    
    int *pNum=NULL;
    pNum=(int *)malloc(sizeof(int)*5);

    strStatistics(p, pNum);
    int i;
    printf("正在输出字符串中字母 数字 空格和其它字符的个数...\n");
    char *r[20]={"字母","数字","空格","其它字符"};
    for (i=0; i<4; i++)
    {
        printf("%s:",r[i]);
        printf("%d \n",*(pNum+i));
    }
    printf("输出完毕!\n");
    free(p);
    p = NULL;
    free(pNum);
    pNum = NULL;
}



void exe_15()
{
    printf("9.3.6 输入一个字符串,统计各字母出现的次数,并按字母出现的多少输出(先输出字母出现多的,次数想同的按字母表顺序输出,不出现的字母不输出).\n");
    unsigned long M = 100;
    char *p=NULL;
    p=(char *)malloc(sizeof(char)* M);
    
    printf("请输入字符串: ");
    int len;
    char ch;
    //由于fflush(stdio)无法清空"输入缓冲区",所以使用吃回车大法!
    while((ch=getchar())!='\n'&&ch!=EOF);
    for (len=0;len<M && (ch=getchar() )!='\n';len++)
        p[len]=ch;
    
    //下面开始统计函数的调用
    int sum[26]={0};
    int i,temp;
    for(i=0;i<len;i++)
    {
        if(p[i]>='a'&&p[i]<='z')
        {
            temp=(int)(p[i]-'a');
            sum[temp]++;
        }
    
    }
    //下面开始输出各字母出现的次数
    
    int max,sign;
    int j;
    for(i=0;i<26;i++)
    {
        max=0;
        sign=0;
        for(j=0;j<26;j++)
        {
            if(max<sum[j])
            {
                max=sum[j];
                sign=j;
            }
    
        }
        if(max)
        {
            printf("%c: %d次\n",'a'+sign,max);
            sum[sign]=0;
        }
        else
            break;
    }
    free(p);
    p = NULL;
}


void demo()
{
    int a;
    while (1)
    {
        printf("11 -> 9.3.2 编写一个函数,将两个字符串连接起来.\n");
        printf("12 -> 9.3.3 编写一个函数,使字符串反序.\n");
        printf("13 -> 9.3.4 编写一个函数,将一个字符串中的元音字母复制到另一个字符串,然后输出.\n");
        printf("14 -> 9.3.5 编写一个函数,由实参传来一个字符串,统计该字符串中字母 数字 空格和其它字符的个数.\n");
        printf("15 -> 9.3.6 输入一个字符串,统计各字母出现的次数,并按字母出现的多少输出(先输出字母出现多的,次数想同的按字母表顺序输出,不出现的字母不输出).\n");
        printf("请输入运行的题号: ");
        scanf("%d",&a);
        switch (a)
        {
            case 11:exe_11();continue;
            case 12:exe_12();continue;
            case 13:exe_13();continue;
            case 14:exe_14();continue;
            case 15:exe_15();continue;
            default:break;
        }
        break;
    }
}

int main()
{
    demo();
    return 0;
}
