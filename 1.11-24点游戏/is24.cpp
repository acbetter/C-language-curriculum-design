/*
1.11-xxx 24点游戏（难度等级：5级）
【任务描述】
任意给出4张牌，计算能否用＋、－、×、÷将其组合成24。
输出其可能的组合式。
*/

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>

#define N 24

float calc(float n1, float n2, char o) {

    switch(o) {
        case '+': return (n1+n2);
        case '-': return (n1-n2);
        case '*': return (n1*n2);
        case '/': 
			if(n2==0)
				return -30000;
			else
				return (n1/n2);
		default: exit(-1);
    }
}



int a,b,c;

int low=1;//下限为1
int high=13;//上限为13

char op[4]={'+','-','*','/'};
float T=0;//T用来存放临时结果

float arr[4]={0};//arr用来存放计算结果
float cur[4]={0};//cur用来存放当前数组
float con[4]={0};//con用来存放原始数据

void initAllFromCon() {

	int i;
	for(i=0;i<4;i++) {
		arr[i]=con[i];
		cur[i]=con[i];
	}
}

void randomGet(int arr[]) {

	srand((unsigned)time(NULL));
	
	printf("随机输出的四张牌分别是 ");

	int i;
	for(i=0;i<4;i++)
	{
		arr[i]=rand()%high+low;
		printf("%d ",arr[i]);
	}

	printf("随机生成四张牌成功！\n");

}

void userGet(int arr[]) {

	int i,sign;
	int temp=0;

	while(1)
	{
		sign=0;//输入检测
		
		printf("请输入四张牌，每张牌之间用空格隔开，按回车键完成输入。\n输入样例：4 12 5 1 回车\n");
		printf("请输入: ");
		
		fflush(stdin);
		for(i=0;i<4;i++)
			scanf("%5d",&arr[i]);
		//这种写法在输入 ^ & ( ) 后会出现死循环 !@#$%^&...
	
		printf("您输入的四张牌是: ");
		for(i=0;i<4;i++)
		{
			if(arr[i]>=low&&arr[i]<=high)
			{
				printf("%d ",arr[i]);
				sign++;
			}
			else
			{
				printf("?\n第%d张牌输入有误，",i+1);
				break;
			}
			sign=i+1;
		}
		if(sign==4)
			break;
		else
			continue;
	}
}

void printResult_1(int a,int b,int c) {
	
	if( (a==0||a==1)&&(b==2||b==3) )
		printf("(%g%c%g)%c%g%c%g=%d\n",cur[0],op[a],cur[1],op[b],cur[2],op[c],cur[3],N);
	else if ( (b==0||b==1)&&(c==2||c==3) )
		printf("(%g%c%g%c%g)%c%g=%d\n",cur[0],op[a],cur[1],op[b],cur[2],op[c],cur[3],N);
	else
		printf("%g%c%g%c%g%c%g=%d\n",cur[0],op[a],cur[1],op[b],cur[2],op[c],cur[3],N);
}

void printResult_2(int a,int b,int c) {
	
		printf("(%g%c%g)%c(%g%c%g)=%d\n",cur[0],op[a],cur[1],op[c],cur[2],op[b],cur[3],N);
}

void initArrFromCur() {

	int g;
	for(g=0;g<4;g++)
		arr[g]=cur[g];

}


void s_first() {

	int j,k;

	int sort[4][4]={
			{1,2,3,4},
			{2,3,4,1},
			{2,3,1,4},
			{3,4,2,1},
		};
	//模拟平衡二叉树之单挂
	for(j=0;j<4;j++) {

		for(k=0;k<4;k++) 
			cur[k]=con[sort[j][k]-1];

		for(a=0;a<4;a++)  {
			for(b=0;b<4;b++) {
				for(c=0;c<4;c++) {

				initArrFromCur();

				arr[1]=calc(arr[0],arr[1],op[a]);
				arr[2]=calc(arr[1],arr[2],op[b]);
				arr[3]=calc(arr[2],arr[3],op[c]);
				if(fabs(arr[3]-N)<=0.1)
					printResult_1(a,b,c);
				}
			}
		}
	}

	initAllFromCon();
}


void s_second() {

	int j,k;

	int sort[3][4]={
			{1,2,3,4},
			{1,3,2,4},
			{1,4,2,3},
		};
	//模拟平衡二叉树之双链
	for(j=0;j<3;j++) {

		for(k=0;k<4;k++) 
			cur[k]=con[sort[j][k]-1];

		for(a=0;a<2;a++)  {
			for(b=0;b<2;b++) {
				for(c=2;c<4;c++) {

				initArrFromCur();

				arr[1]=calc(arr[0],arr[1],op[a]);
				arr[2]=calc(arr[2],arr[3],op[b]);
				arr[3]=calc(arr[1],arr[2],op[c]);
				if(fabs(arr[3]-N)<=0.1)
					printResult_2(a,b,c);
				}
			}
		}
	}

	initAllFromCon();
}

int main(void)
{
	int pai[4]={0};
	//float arr[4]={0};已经全局定义
	//randomGet(pai);
	userGet(pai);
	int i;
	for(i=0;i<4;i++)
		con[i]=(float)pai[i];//转换为浮点数组方便除法运算.避免用户输入浮点数

	initAllFromCon();
	
	//system("pause");
	s_first();
	s_second();



	return 0;
}