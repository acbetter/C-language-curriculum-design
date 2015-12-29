
//afdsughakjfshalsdfh

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

float calc(float n1, float n2, char o) {

    switch(o) {
        case '+': return (n1+n2);
        case '-': return (n1-n2);
        case '*': return (n1*n2);
        case '/': return (n1/n2);
		default: exit(-1);
    }
}


int i;

int low=1;//下限为1
int high=13;//上限为13

char op[4]={'+','-','*','/'};
float T=0;//T用来存放临时结果

float arr[4]={0};

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

void s_first() {

	T=0;

}



int main(void)
{
	int pai[4]={0};
	//float arr[4]={0};已经全局定义
	randomGet(pai);
	//userGet(pai);
	for(i=0;i<4;i++)
		arr[i]=(float)pai[i];//转换为浮点数组方便除法运算.避免用户输入浮点数
	system("pause");



	return 0;
}