/*
3.18-xxx 单项选择题标准化考试系统（难度系数：5级）
【任务描述】
设计一个单项选择题的考试系统，可实现自动组卷功能。
【功能描述】
（1）管理员功能
    试题管理：每个试题包括题干、4个备选答案、标准答案等信息。可进行试题添加、删除、修改、查询、保存、浏览等操作。
    组卷功能：指定题目数、题目总分，生成试卷。将试卷输出到文件，将答案输出到另一个文件。
	用户管理：对用户信息进行添加、删除、修改、查询、保存、浏览等操作。
	用户答题情况管理：指定用户，统计其做试卷的总次数，以及每次所得的总分。
（2）用户功能
	练习功能：用户指定题目数，随机选题。对用户的答案与标准答案进行对比，并最终给出成绩。对错误题目，要能给出正确答案。
	考试功能：用户指定题目数，随机生成总分100分的试卷，系统可根据用户答案与标准答案的对比实现判卷，并给出成绩。并将用户所答试卷、用户的答案、用户所得总分，输出到磁盘文件保存。进行基本试题分析。
（3）设计提示
    管理员和用户分别通过密码登录，进行题目维护和答题操作。用户产生的答题文件，应以用户名+系统时间.txt的形式存储，以便于进行管理。
*/


#include <stdio.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>


enum {A,B,C,D} option; //A=0,B=1,C=2,D=3;

struct information {
    
    int no;//题目编号
    int lever;//题目难度
	int score;//题目分数
    char timeAdd[20];//题目添加的时间
    char timeModify[20];//最后修改时间
    char statement[1000];//题目描述
    char keyWords[5][40];//每道题有5个关键字

	char options[4][100];//题目的四个选项
    int rightAnswer;//正确选项
    char answers[4][300];//每个选项的错误原因
	struct information * next;
};



void menuPrint(int a);
int move();

//------------------------------------------主函数及菜单函数


void main(void) {

	system("mode con cols=57 lines=30");
	system("color 0A");

	srand((unsigned)time(NULL));
	int a=1;
	
	while (1) {

		menuPrint(a);
		a=move();
		switch (a) {
			//1.
			case 1:;continue;
			case 2:;continue;
			case 3:;continue;	
			case 6:;continue;
			default:break;
		}
	}
}

void menuPrint(int a) {

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

	
	char arr[1500];//这里1000最为合适~2333
	memset(arr,0,sizeof(char)*1500);
	FILE *fp;
	fp=fopen(name[a],"r");

	if(fp==NULL) {
		printf("cannot open %s\n",name[a]);
		exit (0);
	}

	int h=0;
	while(!feof(fp)) {
		fread(arr+h,sizeof(char),1,fp);
		h++;
	}
	printf("%s",arr);

	fclose(fp);
}

int move() {
	
	int i = 1;
	char key = 0;

	while (1) {

		fflush(stdin); //清除缓存数据 
		key = getch();
		if(key==0||key==-32)
			key = getch();
		if (key==72)
			i--;//...
		else if (key==80)
			i++;
		else if (key>=49&&key<=54)
			return key-48;
		else if (key==48||key==27) 
			exit(0);
		else if (key==13)
			if(i)
				return i;
			else
				exit(0);
		else
			key=0;
		
		if(i<0)
			i=i+7;
		if(i>6)
			i=i-7;
		
		menuPrint(i);
	}

	return i;
}
