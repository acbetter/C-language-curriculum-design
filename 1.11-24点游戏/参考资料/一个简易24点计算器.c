#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char op[3], o[5]="+-*/";
float n[4], on[10];
int used[4] = {0}, top=0, tp=0, x;

void chk(float k);
void search24(int d);
float calc(float n1, float n2, char o);
void make(int i, float p, float q, char o, int d);

int main( void )
{
 printf("please input 4 card number:\n");
    scanf("%f%f%f%f", &n[0], &n[1], &n[2], &n[3]);

    search24(0);
    printf("No answer.\n");

    return 0;
}


void chk(float k)
{
    if( (tp != 3) || ( fabs(k-24.0) > 0.000001 )) //没有用完3个运算符或者结果不为24就退出.
  return;
    for(x=0; x<5; x+=2)                                            //这样设计是为了使3个选中的符号都可以得到输出.
        printf("%g%c%g=%g\n", on[x], op[x/2], on[x+1],         //分析得到的.
                               calc(on[x], on[x+1], op[x/2]));
 system("pause");
    exit(0);
}
float calc(float n1, float n2, char o)
{

    switch(o){
        case '+': return (n1+n2);
        case '-': return (n1-n2);
        case '*': return (n1*n2);
        case '/': return (n1/n2);
  default: exit(0);
    }

}
void make(int i, float p, float q, char o, int d)
{
    if(fabs(q)>0.000001 || o!='/')   //除数不为0,或者为0的时候不能为除数.
        n[i] = calc(p, q, o);
    op[tp++] = o; 

 chk(n[i]);
    search24(d+1);
 tp--;    //因为是全是全局变量,所以在做试验性的循环递归问题时,如果失败,要在递归函数后面重新恢复回原来的值
}

void search24(int d)
{
    int i, j, k;
    float p, q;
    if(d>=3)    //控制递归深度,就是运算符的输出个数.
  return;
    for(i=0; i<4; i++)
        for(j=0; j<4; j++)
            if( (i!=j)&& (used[i]+used[j] == 0) ) //i!=j是防止重复,(used[i]+used[j] == 0)是防止又再匹配已经用过的j,
                                      //但是i可以新来.
   {
                used[j] = 1;   //j得到匹配之后,赋值为1,表示已经使用
    p=n[i];
    q=n[j];
                on[top++] = p;
    on[top++] = q;
                for(k=0; k<4; k++)  //运算符的循环试用.
                    make(i, p, q, o[k], d);
                n[i] = p;        //因为是全是全局变量,所以在做试验性的循环递归问题时,
    used[j] = 0;     //如果失败,要在递归函数后面重新恢复回原来的值
                top -= 2;        //
            }

}