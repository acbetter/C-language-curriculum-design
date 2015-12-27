/*
1.11-xxx 24点游戏（难度等级：5级）
【任务描述】
任意给出4张牌，计算能否用＋、－、×、÷将其组合成24。
输出其可能的组合式。
*/

//由于调用getch()和fflush(stdin),程序的移植性较差,请尽量在vc++6.0中编译运行.

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

//------------------------------------------全局变量

struct temp_set {
	int mode;//当前模式 1.帮我计算(容许小数) 2.练习模式(无尽模式) 3.天梯模式 4.双人模式 5.设置 6.帮助 0.exit
	//int isPrint;//是否输出结果 1.输出 0.不输出
};

struct temp_set settings;

struct saved_set {
	int low;//下限
	int high;//上限
	int saveSettings;//是否保存当前设置
};

struct saved_set saved;


int N = 24;



char op[4]={'+','-','*','/'};

float arr[4]={0};//arr用来存放计算结果
float cur[4]={0};//cur用来存放当前数组
float con[4]={0};//con用来存放原始数据


//------------------------------------------函数列表

char key_to_char(int key);
void read_settings();
void save_settings();
void print_settings();
float poker_to_number(char *poker);
void resetting();
char* number_to_poker(float number);
void initSettings_temp();
float calc(float n1, float n2, char o);
void initAllFromCon();
void randomGet();
void userGet();
int userGetIn();
void printResult_1(int a,int b,int c);
void printResult_2(int a,int b,int c);
void initArrFromCur();
void exercise();
void change_settings(int num);


int s_first(int isPrint);	//模拟平衡二叉树之单挂
int s_second(int isPrint);	//模拟平衡二叉树之双链

int test(void);
void menuPrint();

int move();
void exitGame(void);


//------------------------------------------主函数及菜单函数


void main(void) {

	
	system("color 0A");
	resetting();
	read_settings();
	initSettings_temp();
	srand((unsigned)time(NULL));
	int a;
	
	while (1) {

		menuPrint();
		a=move();
		switch (a) {
			//1.帮我计算 2.练习模式 3.天梯模式 4.双人模式 5.设置 6.帮助 0.exit
			case 1:userGet();continue;
			case 2:exercise();continue;
			case 5:print_settings();continue;
			default:break;
		}
	}
}

void menuPrint() {

	system("cls");
	char name[10][sizeof(char)*15]={
		"exit.txt",
		"menu_1.txt",
		"menu_2.txt",
		"menu_3.txt",
		"menu_4.txt",
		"menu_5.txt",
		"menu_6.txt",
	};

	char ch;
	FILE *fp;
	fp=fopen(name[settings.mode],"r");

	if(fp==NULL) {
		printf("cannot open %s\n",name[settings.mode]);
		exit (0);
	}
	while(!feof(fp)) {
		ch=fgetc(fp);
		putchar(ch);
	}
	fclose(fp);
}

int move() {
	
	char key = 0;

	while (1) {

		fflush(stdin); //清除缓存数据 
		key = getch();
		if(key==0||key==-32)
			key = getch();
		if (key==72)
			settings.mode--;//...
		else if (key==80)
			settings.mode++;
		else if (key>=49&&key<=54)
			return key-48;
		else if (key==48||key==27) 
			exitGame();
		else if (key==13)
			if(settings.mode)
				return settings.mode;
			else
				exitGame();
		else
			key=0;
		
		if(settings.mode<0)
			settings.mode=settings.mode+7;
		if(settings.mode>6)
			settings.mode=settings.mode-7;
		
		menuPrint();
	}

	return settings.mode;
}

void exitGame(void) {
	
	printf("\n\t\t正在退出游戏...");
	if(saved.saveSettings)
		save_settings();
	Sleep(1000);
	exit(0);

}

//------------------------------------------一级函数

void userGet() {

	int a=1;
	//如果userGetIn()的返回值为0则返回主菜单,否则继续执行userGetIn()
	while (a) {
		printf("计算%d点\n",N);
		a=userGetIn();
		//system("pause");
	}
	
}

void exercise() {

	system("cls");
	randomGet();
	
	//这里有个控制菜单
	system("pause");
}


void print_settings() {

	char isSave[2][10]={"否","是"};

	int key=0;
	while (1) {

		system("cls");
		printf("\n\n");
		printf("\t由于 C 语言 写出界面比较繁琐\n");
		printf("\t这个设置界面暂时不支持上下滑动及回车选中\n");
		printf("\t请输入1~9修改设置项,输入0即可回到主菜单\n");
		printf("\t1.当前下限(最小的扑克牌):%s\n",number_to_poker(float(saved.low)));
		printf("\t2.当前上限(最大的扑克牌):%s\n",number_to_poker(float(saved.high)));
		//printf("3.%d\n",);
		printf("\t8.重置所有设置(程序有bug时也可以重置)\n");
		printf("\t9.下次运行游戏是否载入当前设置:%s\n",isSave[saved.saveSettings]);
		printf("\t0.返回菜单\n\t");


		fflush(stdin);
		key = getch();
		if (key>=49&&key<=59)
			change_settings(key-48);
		else if(key==48)
			return ;//esc未加入
		else
			;
	}
}


//------------------------------------------二级函数


void change_settings(int num) {

	char poker[5];
	memset(poker,0,sizeof(char)*5);
	fflush(stdin);
	switch (num) {
		case 1:
			printf("请输入当前下限(最小的扑克牌):");
			scanf("%s",poker);
			saved.low=(int)(poker_to_number(poker));
			break;
		case 2:
			printf("请输入当前上限(最大的扑克牌):");
			scanf("%s",poker);
			saved.high=(int)(poker_to_number(poker));
			break;
		case 8:
			resetting();
			save_settings();
			break;
		case 9:
			if(saved.saveSettings)
				saved.saveSettings=0;
			else
				saved.saveSettings=1;
			break;
		default:
			break;
	}

}

void save_settings() {

	FILE *fp;
	if( (fp=fopen("is24.set","w"))!=NULL )
		fwrite(&saved,sizeof(struct saved_set),1,fp);

}

void initSettings_temp() {

	settings.mode=1;

}

void resetting() {

	settings.mode=1;//模式 帮我计算
	saved.low=1;//下限为1
	saved.high=13;//上限为13
	saved.saveSettings=0;//是否保存当前设置
}

void read_settings() {

	FILE *fp;
	resetting();
	if( (fp=fopen("is24.set","r"))==NULL ) {
		save_settings();
		//未完成->显示帮助界面
	} else {
		if( (fread(&saved,sizeof(saved_set),1,fp) )!=1 )
			resetting();
	}

}


char * number_to_poker(float number) {

	char temp[11];
	memset(temp,0,sizeof(char)*11);

	if(number==1)
		return "A";
	else if(number==11)
		return "J";
	else if(number==12)
		return "Q";
	else if(number==13)
		return "K";
	else if(number==10)
		return "10";
	else if(number>1&&number<10)
		return itoa((int)number,temp,10);
	else
		return NULL;
}

float poker_to_number(char *poker) {

	if(*poker=='j'||*poker=='J')
		return 11;
	else if(*poker=='q'||*poker=='Q')
		return 12;
	else if(*poker=='k'||*poker=='K')
		return 13;
	else if(*poker=='a'||*poker=='A')
		return 1;
	else
		return (float)(atof(poker));
}


void initAllFromCon() {

	int i;
	for(i=0;i<4;i++) {
		arr[i]=con[i];
		cur[i]=con[i];
	}
}

void initArrFromCur() {

	int g;
	for(g=0;g<4;g++)
		arr[g]=cur[g];

}

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


void randomGet() {


	
	int i;
	while (1) {
		
		for(i=0;i<4;i++)
			con[i]=(float)(rand()%saved.high+saved.low);
		if(s_first(0)||s_second(0)) {
			for(i=0;i<4;i++)
				printf("%g ",con[i]);
			break;
		}
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



//模拟平衡二叉树之单挂

int s_first(int isPrint) {

	int result = 0;

	int a,b,c;
	int j,k;

	int sort[4][4]={
			{1,2,3,4},
			{2,3,4,1},
			{2,3,1,4},
			{3,4,2,1},
		};

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
				if(fabs(arr[3]-N)<=0.1) {
					result=1;
					if(isPrint)
						printResult_1(a,b,c);
					else
						return result;
				}

				}
			}
		}
	}

	initAllFromCon();
	return result;
}


//模拟平衡二叉树之双链

int s_second(int isPrint) {

	int result = 0;

	int a,b,c;
	int j,k;

	int sort[3][4]={
			{1,2,3,4},
			{1,3,2,4},
			{1,4,2,3},
		};

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
				if(fabs(arr[3]-N)<=0.1) {
					result=1;
					if(isPrint)
						printResult_2(a,b,c);
					else
						return result;
				}

				}
			}
		}
	}

	initAllFromCon();
	return result;
}

int userGetIn() {
	
	system("cls");
	int i;
	int key=0;
	int sign=0;
	char input[4][10];
	for(i=0;i<4;i++)
		memset(input[i],0,sizeof(char)*10);
	//雕虫小技,下面有个 可以识别 JQKA jqka space enter 的函数,让使用着随心输入
	fflush(stdin); //清除缓存数据
	printf("请输入四张牌,并用空格隔开.按esc键返回主菜单,按其他键开始输入");
	key=getch();
	if(key==27)
			return 0;
	printf("\n请输入: ");
	for(i=0;i<4;i++) {
		scanf("%10s",input[i]);
	}
	for(i=0;i<4;i++) {
		con[i]=poker_to_number(input[i]);
		if(con[i]<saved.low||con[i]>saved.high) {
			printf("第%d组数据输入失败!请重新输入四张牌\n",i+1);
			system("pause");
			return -1;
		}
	}


	initAllFromCon();
	if(s_first(1))
		sign=1;
	if(s_second(1))
		sign=1;
	if(sign)
		printf("计算完成!\n");
	else
		printf("噫,算不出来哦\n");
	printf("是否继续帮我计算%d点?",N);
	fflush(stdin);
	Sleep(1000);

	//未完成
	return 0;
}


//------------------------------------------逗比函数

char key_to_char(int key) {

	if(key>=48&&key<=57)
		return '0'+key-48;//键盘数字0->9
	else if(key>=96&&key<=105)
		return '0'+key-96;//小键盘数字0->9
	else if(key>=65&&key<=90)
		return 'A'+key-65;//小键盘数字0->9
	else if(key>=97&&key<=122)
		return 'a'+key-97;//小键盘数字0->9
	else if(key==43)
		return '+';
	else if(key==45)
		return '-';
	else if(key==42)
		return '*';
	else if(key==47)
		return '/';
	else if(key==61)
		return '=';
	else if(key==40)
		return '(';
	else if(key==41)
		return ')';
	else
		return NULL;

}




//------------------------------------------测试函数

int test(void)
{
	
	randomGet();
	
	initAllFromCon();
	
	s_first(1);
	s_second(1);
	system("pause");

	return 0;
}










