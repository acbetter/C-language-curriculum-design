/*
1.11-xxx 24点游戏（难度等级：5级）
【任务描述】
任意给出4张牌，计算能否用＋、－、×、÷将其组合成24。
输出其可能的组合式。
*/

#include<stdio.h>
#include<time.h>
#include<math.h>
#include<windows.h>
#include<stdlib.h>

/*
#define add Q
#define minus W
#define multiply E
#define divide R
*/

float add(float a,float b) {
	return a+b;
}
float minus(float a,float b) {
	return a-b;
}
float multiply(float a,float b) {
	return a*b;
}
float divide(float a,float b) {
	if(b==0)
		return 30000;
	else
		return a/b;
}
//...
float *Q(float a,float b);
//Q=add,Q=minus;Q=multiply;Q=divide;


int i;

int low=1;//下限为1
int high=13;//上限为13

float T=0;//T用来存放临时结果

void randomGet(int arr[]) {

	srand((unsigned)time(NULL));
	
	printf("随机输出的四张牌分别是 ");

	for(i=0;i<4;i++)
	{
		arr[i]=rand()%high+low;
		printf("%d ",arr[i]);
	}

	printf("随机生成四张牌成功！\n");

}

void userGet(int arr[]) {

	int sign;
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

void s_first(float *p) {

	T=0;//开始
	//T=T+*p+*p+1

}



int main(void)
{
	int pai[4]={0};
	float arr[4]={0};
	randomGet(pai);
	//userGet(pai);
	for(i=0;i<4;i++)
		arr[i]=(float)pai[i];//转换为浮点数组方便除法运算

	return 0;
}