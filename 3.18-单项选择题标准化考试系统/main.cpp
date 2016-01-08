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


#include "all.h"


void main(void) {

	printf("正在载入程序,请稍候...");

	srand((unsigned)time(NULL));
	int a;
	struct user * head = NULL;
	
	while (1) {

		system("mode con cols=57 lines=20");
		system("color 0A");

		a = move_1(6,menuPrint);
		switch (a) {
			//1.
			case 1:
				admin();
				continue;
			case 2:
				;
				continue;
			case 3:
				head=read_user();
				input_user(head);
				write_user(head);
				free_user(head);
				continue;
			case 6:;continue;
			case 0:exit(0);
			default:break;
		}
	}
}


int move_1(int num,void (*p)(int) ) {

	int a = 1;
	int key = 1;

	while(1) {

		(*p)(a);
		fflush(stdin);
		key=getch();
		if(key==244||key==0)
			key=getch();
		if(key==72)
			a--;//up
		else if(key==80)
			a++;
		else if(key>=48&&key<=57)
			return key-48;
		else if(key==27)
			return 0;//Esc
		else if(key==13)
			return a;
		else
			;

		if(a==num)
			a=0;
		if(a==-1)
			a=num-1;
	}
}


void menuPrint(int a) {

	system("cls");
	char name[15]={"menu_1.txt"};

	
	char arr[1500];//这里1000最为合适~2333
	memset(arr,0,sizeof(char)*1500);
	FILE *fp;
	fp=fopen(name,"r");

	if(fp==NULL) {
		printf("cannot open %s\n",name);
		exit (0);
	}

	int h=0;
	while(!feof(fp)) {
		fread(arr+h,sizeof(char),1,fp);
		h++;
	}
	printf("%s",arr);

	fclose(fp);

	switch (a) {
		//显示光标
		case 1:printLaugh(32,6);break;
		case 2:printLaugh(32,8);break;
		case 3:printLaugh(32,10);break;
		case 4:printLaugh(32,12);break;
		case 5:printLaugh(32,14);break;
		case 0:printLaugh(32,16);break;
		default:break;
	}
	
}

void printLaugh(int x, int y) {

	goto_pos(x,y);
	printf("(*^_^*)");
	goto_pos(x+3,y);

}

void goto_pos(int x, int y) {
	//(列,行)
	COORD coord = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}