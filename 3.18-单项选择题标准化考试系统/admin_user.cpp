/*
(1) 管理员功能

	用户管理：对用户信息进行添加、删除、修改、查询、保存、浏览等操作。

	(用户答题情况管理：指定用户，统计其做试卷的总次数，以及每次所得的总分。)
*/

//admin_user.cpp created time 2016-1-8 10:06:12

#include "all.h"

void admin_user() {
		
	int a;
	struct user * head = NULL;
	head=read_user();

	while (1) {

		system("mode con cols=57 lines=20");
		system("color 3F");

		a = move_1(6,menuPrint_5);
		switch (a) {
			//1.
			//case 1:find_user(head);continue;
			case 2:input_user(head);continue;
			//case 3:find_user(head);continue;
			//case 4:find_user(head);continue;
			case 5:
				system("cls");
				print_user(head->next);
				system("pause");
				continue;
			case 0:
			default:break;
		}
		break;
	}
	write_user(head);
	free_user(head);  //save
}

/*

            学生信息管理界面       admin


               1.查找学生

               2.添加学生     

               3.移除学生信息(请先查找)

               4.修改学生信息(请先查找)

               5.浏览学生信息    

               0.保存并退出
                       
*/

void menuPrint_5(int a) {

	system("cls");
	char name[15]={"menu_5.txt"};

	
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
		case 1:printLaugh(40,6);break;
		case 2:printLaugh(40,8);break;
		case 3:printLaugh(40,10);break;
		case 4:printLaugh(40,12);break;
		case 5:printLaugh(40,14);break;
		case 0:printLaugh(40,16);break;
		default:break;
	}
	
}

//不带头结点的尾插法

struct user * solo_user() {

    struct user * node = NULL;
    node = (struct user *)malloc(sizeof(struct user));
    memset(node, 0, sizeof(struct user));
    if (node == NULL) {
        printf("申请内存失败!");
        exit(-1);
    }else{
		node->next=NULL;
	}
    return node;
}



void input_user(struct user * head) {

	int i;
	struct user * node = NULL;
	struct user * tail = head;
	
	node = solo_user();
	while(tail->next!=NULL)
		tail = tail->next;
	tail->next = node;

	system("mode con cols=37 lines=27");
	system("color 3A");

	//char name[10]={"admin"},password[10]={"admin"};

	for(i=0;i<3;i++) {
		system("cls");
		printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
		printf("           学生注册\n\n");
		printf("     --------------------------\n");
		printf("     | 学号: |                |\n");
		printf("     --------------------------\n");
		printf("\n");
		printf("     --------------------------\n");
		printf("     | 密码: |                |\n");
		printf("     --------------------------\n");
		printf("\n");
		printf("     --------------------------\n");
		printf("       | 学号必须是10位数字|\n");
		printf("       | 密码之间不能有空格|\n");
		printf("       | 按回车键完成输入..|\n");
		printf("     --------------------------\n");
		printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		fflush(stdin);
		goto_pos(16,6);
		scanf("%20s",node->no);
		fflush(stdin);
		goto_pos(16,10);
		scanf("%30s",node->password);
		
		if(strlen(node->no)==11&&strlen(node->password)>=6) {
			goto_pos(11,21);
			printf("注册成功!");
			{
				//开始初始化学生个人信息



			}
			Sleep(1800);
			return ;
		}else{
			goto_pos(13,21);
			printf("注册失败\n      请重新注册 (剩余次数:%d)",2-i);
			goto_pos(9,23);
			if(strlen(node->no)!=11)
				printf("学号不是11位,无效!");
			else
				printf("密码过于简单!");
			Sleep(2100);
		}
	}
	free(node);
}

void write_user(struct user * head) {

	FILE * fp;
	if ((fp = fopen("user.txt", "w")) == NULL) {
		printf("打开文件失败");
		exit(-2);
	}
    printf("写入文件中");
    while(head->next!=NULL)
    {
        printf(".");
		head = head->next;
        if(fwrite(head, sizeof(struct user), 1, fp)!=1) {
            printf("写入文件失败");
            exit(-2);
        }
		
    }
    //printf("写入完成\n");
	fclose(fp);
}

struct user * read_user() {

	int i=0;
	FILE * fp;
	struct user * head = NULL;
	struct user * node = NULL;
	struct user * tail = NULL;

	//head=solo_user();

	if ((fp = fopen("user.txt", "r")) == NULL) {
		system("cls");
		printf("读取文件失败");
		exit(-3);
	}
	tail=head=solo_user();
	while(!feof(fp)){

		node=solo_user();
		if(fread(node, sizeof(struct user),1 , fp)==1){
			tail->next=node;
			tail=node;
		}
	}

	//!@#$%^&*()_)(*&^%$#@!@#$%^&*())(*&^%$#@!#$%^&*()(*&^%$#@

	fclose(fp);
	return head;
}

void free_user(struct user * head) {
    
    struct user * p = NULL;
    while (head!=NULL) {
        p = head->next;
        free(head);
        head = p;
    }
    return ;
}

void print_user(struct user * node) {

	system("mode con cols=80 lines=1000");
	
	printf("正在读取数据...\n");
	if (node==NULL) {
		printf("没有任何学生信息!");
	}else{
		printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		struct user * p = node;
		while (p!=NULL) {
			print_user_solo(p);
			p=p->next;
		}
	}
}


void print_user_solo(struct user * node) {


	if (node==NULL) {
		printf("当前结点为空!");
	}else{
		struct user * p = node;
		{	//基本信息		
			printf(" 学号:%s ",p->no);
			printf(" password:%s ",p->password);
			printf("\n");
		}
		{	//练习信息
			printf("用户练习次数:%d\t",p->exerciseTime);
			printf("总计练习题目数量:%d\t",p->exercise);
			printf("正确数量:%d\t",p->exerciseRight);
			printf("正确率:%.1f%%\t",((p->exerciseRight+0.0)/p->exercise)*100);
		}
		{	//考试信息
			printf("用户考试次数:%d\t",p->examTime);
			printf("总计考试题目数量:%d\t",p->exam);
		
		int right,i;
		for(i=0,right=0;(p->examRight[i][0]+p->examRight[i][1])!=0;i++){
			right+=p->examRight[i][0];
		}
			printf("正确数量:%d\t",right);
			printf("正确率:%.1f%%\t",((right+0.0)/p->exam)*100);

			printf("用户历次考试分数:\n");
		int j
		for(i=0;
			int examScore[300];//用户考试每次考试分数
	

			time_t timeAdd;//用户注册时间
			time_t timeOnline;//用户在线时间
			time_t timeLogin;//用户最后登录时间
			time_t timeLogout;//用户最后登出时间
			int last;//最后一次访问的是练习系统还是考试系统,练习为1,考试为2
			
			int errorHistory[300];//错误历史题号
			int errorTime[300];//易错点栽了几次跟头
			char error[300][40];//每错一道题,题目的几个关键字会自动算入用户易错点
			
	}
}









