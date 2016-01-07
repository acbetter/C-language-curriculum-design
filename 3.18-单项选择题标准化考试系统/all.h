
//all.h created time 2016-1-3 18:08:44


#include <stdio.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>


//------------------------------------------


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
struct info * find_info_num(struct info * head,int num);
struct info * find_info_score_num(struct info * head,int lev);

//question.cpp
void question();
void menuPrint_3(int a);
struct info * solo_info();
void input_info(struct info * head);
struct info * find_info_tail(struct info * head);
void add_info(struct info * node);
void write_info(struct info * head);
struct info * read_info(void);
void free_info(struct info * head);
void print_info(struct info * head);
void print_info_solo(struct info * node);


//time.cpp
void print_time(long lt);


//find_info.cpp
struct info * find_info(struct info * head);
void menuPrint_4(int a);
struct info * find_info_key(struct info * head);
int fuzzy_search(char str[] , char str2[]);
void delete_info_no(struct info * find);
struct info * find_info_no(struct info * head);
void change_info(struct info * node);
void find_info_next(struct info * node);
struct info * find_info_lever(struct info * head);
struct info * find_info_score(struct info * head);
struct info * find_info_time(struct info * head);



