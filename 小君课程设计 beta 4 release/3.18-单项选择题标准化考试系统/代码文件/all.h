
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

struct user {

	char no[15];//用户学号
	char name[30];//用户名
	char password[30];//用户密码
	

	int exercise;//用户练习题数目
	int exerciseTime;//用户练习次数
	int exerciseRight;//用户练习题正确数目

	int exam;//用户考试题数目
	int examTime;//用户考试次数
	float examScore[300];//用户考试每次考试分数
	int examRight[300][2];//用户考试正确/错误数目	

	time_t timeAdd;//用户注册时间
	time_t timeOnline;//用户在线时间
	time_t timeLogin;//用户最后登录时间
	time_t timeLogout;//用户最后登出时间
	int last;//最后一次访问的是练习系统还是考试系统,练习为1,考试为2
	
	int errorHistory[300];//错误历史题号
	int errorTime[300];//易错点栽了几次跟头
	char error[300][40];//每错一道题,题目的几个关键字会自动算入用户易错点
	
	struct user * next;
};


//main.cpp
void main(void);//程序入口
int move_1(int num,void (*p)(int) );//集大成的move_1函数 传入菜单选项的个数已经相应的void menuPrint_x(int a); 即可打印各种菜单
void menuPrint(int a);//菜单显示函数
void printLaugh(int x, int y);//打印(*^_^*)并把光标移动至笑脸的中央
void goto_pos(int x, int y);//光标移动函数
int fuzzy_search(char str[],char str2[]);//模糊查找函数,char str[]为源字符串,char str2[]为查找的关键字


//admin.cpp
int sign_in();//管理员登录界面
void admin();//管理员控制界面 1.试题管理(增删改查) 2.组卷功能 3.用户账号及答题情况管理 4.修改管理员密码 0.注销登录
void menuPrint_2(int a);//显示菜单~~管理员登录界面
void question_admin();//question() -> question.cpp
void auto_paper();//自动出卷
void user_admin();//进入函数admin_user()
void change_admin_password();//修改管理员密码
struct info * find_info_num(struct info * head,int num);//根据题号查找试题
struct info * find_info_score_num(struct info * head,int lev);//根据分数查找试题 多半是废了


//question.cpp
void question();//试题管理界面
void menuPrint_3(int a);//显示菜单~~试题管理界面
struct info * solo_info();//申请malloc单个题目
void input_info(struct info * head);//新建一个题目并初始化题目信息带头结点的尾插法
void write_info(struct info * head);//把题库写入到文件info.txt中
struct info * read_info();//从本地文件info.txt读入题库
void free_info(struct info * head);//释放链表
void print_info(struct info * node);//输出所有题目的信息
void print_info_solo(struct info * node);//输出一个题目全部信息到屏幕
void fprint_info_solo(FILE *fp,struct info * node);//输出一个题目全部信息到文件fp


//time.cpp
void print_time(long lt);//输出当前时间到屏幕
void sprint_time(char * buf);//输出当前时间到字符数组


//find_info.cpp
struct info * find_info(struct info * head);//查找试题界面
void menuPrint_4(int a);//显示菜单~~查找试题界面
struct info * find_info_key(struct info * head);//按照关键字查找题目,返回题目的上一个指针
void delete_info_no(struct info * find);//删除题目信息
struct info * find_info_no(struct info * head);//按照题目编号查找题目,返回题目的上一个指针
void change_info(struct info * node);//修改题目详细信息
void find_info_next(struct info * node);//选择修改题目信息或删除题目,传来的是题目的上一个节点
struct info * find_info_lever(struct info * head);//按题目难度查找
struct info * find_info_score(struct info * head);//按题目分值查找
struct info * find_info_time(struct info * head);//按最近添加/修改题目


//admin_user.cpp
void admin_user();//学生信息管理界面
void menuPrint_5(int a);//显示菜单~~学生信息管理界面
struct user * solo_user();//申请内存
void input_user(struct user * head);//学生注册不~带头结点的尾插法
void write_user(struct user * head);//把学生信息写入文件中
struct user * read_user();//从文件中读入学生信息
void free_user(struct user * head);//释放内存
void print_user(struct user * node);//输出所有学生信息
void print_user_solo(struct user * node);//单个输出学生信息


//find_user.cpp
struct user * find_user(struct user * head);//查找学生界面
void menuPrint_6(int a);//显示菜单~~查找学生界面
struct user * find_user_name_key(struct user * head);//按学生姓名(模糊)查找
struct user * find_user_no_key(struct user * head);//按学生学号(模糊)查找
void delete_user_no(struct user * find);//按照学号删除用户信息
struct user * find_user_no(struct user * head);//按照学号查找用户
struct user * find_user_name(struct user * head);//按照姓名查找用户
void change_user(struct user * node);//修改用户学号和密码
void find_user_next(struct user * node);//修改用户信息或删除用户
struct user * find_user_time(struct user * head);//最近登录的用户


//user.cpp
void user();//学生登录界面
void user_login(struct user * head,struct user * node);//用户登录后
void menuPrint_7(int a);//显示菜单~~单项选择题标准化考试系统
void printRectangle(int x, int y);//在指定位置输出黄色矩形
void color(const unsigned short color1);//改变颜色---
void exam(struct user * node);//考试
int isQusetion(struct info * node,char *p);//题目是否满足要求
int errorsNum(struct user * node);//计算用户错了多少题
void answerWrong(struct user * node,struct info * temp);//用户答题错误之后...
void execrise(struct user * node);//练习
