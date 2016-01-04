
//all.h created time 2016-1-3 18:08:44


#include <stdio.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>


//------------------------------------------

//A=0,B=1,C=2,D=3;
#define A 1
#define B 2
#define C 3
#define D 4

struct info {
	int no;//题目编号
	int lever;//题目难度1-10
	int score;//题目分数1-5
	int rightAnswer;//正确选项
	time_t timeAdd;//题目添加的时间
	time_t timeModify;//最后修改时间
	
	char keyWords[5][40];//每道题有5个关键字
	char options[4][100];//题目的四个选项
	char answers[4][300];//每个选项的错误原因
	char statement[1000];//题目描述
	
	struct info * next;
};



//main.cpp
void main(void);
int move_1(int num,void (*p)(int) );
void menuPrint(int a);
void printLaugh(int x, int y);
void goto_pos(int x, int y);

//admin.cpp
void admin();
void question_admin();
void auto_paper();
void user_admin();
void situation_analysis();
void menuPrint_2(int a);

//question.cpp
void question();
void menuPrint_3(int a);
struct info * solo_info();
void input_info(struct info * tail);
struct info * find_info_tail(struct info * head);
void add_info(struct info * head);
void write_info(struct info * head);
void read_info(struct info * head);
void free_info(struct info * head);
