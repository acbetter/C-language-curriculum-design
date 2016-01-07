/*
(1) 管理员功能

    试题管理：每个试题包括题干、4个备选答案、标准答案等信息。
	可进行试题添加、删除、修改、查询、保存、浏览等操作。

    组卷功能：指定题目数、题目总分，生成试卷。
	将试卷输出到文件，将答案输出到另一个文件。

	用户管理：对用户信息进行添加、删除、修改、查询、保存、浏览等操作。

	用户答题情况管理：指定用户，统计其做试卷的总次数，以及每次所得的总分。
*/

//admin.cpp created time 2016-1-3 17:58:13

#include "all.h"

int sign_in() {

	system("mode con cols=30 lines=22");
	system("color 3A");

	int i;
	//char name[10]={"admin"},password[10]={"admin"};
	char name[10]={"1"},password[10]={"1"};
	char get_1[10],get_2[10];
	for(i=0;i<3;i++) {
		system("cls");
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
		printf("       管理员登录界面\n\n");
		printf("     ---------------------\n");
		printf("     |登录名:|           |\n");
		printf("     ---------------------\n");
		printf("\n");
		printf("     ---------------------\n");
		printf("     | 密码: |           |\n");
		printf("     ---------------------\n");
		printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		fflush(stdin);
		goto_pos(16,7);
		scanf("%10s",get_1);
		fflush(stdin);
		goto_pos(16,11);
		scanf("%10s",get_2);
		
		if(strcmp(name,get_1)==0&&strcmp(password,get_2)==0){
			goto_pos(11,17);
			printf("登录成功!");
			Sleep(800);
			return 0;
		}else{
			goto_pos(11,17);
			printf("密码错误\n    请重新输入 (剩余次数:%d)",2-i);
			Sleep(1300);
		}
	}

	return -1;
}

/*
               管理员控制界面     admin


               1.试题管理(增删改查)

               2.组卷功能           

               3.用户账号管理

               4.用户答题情况管理

               ---------------     

               0.注销登录
*/

void admin() {

	if(sign_in()==-1)//如果登录失败则退出
		return ;

	int a;
		
	while (1) {

		system("mode con cols=57 lines=20");
		system("color 47");

		a = move_1(5,menuPrint_2);
		switch (a) {
			//1.
			case 1:question_admin();continue;
			case 2:auto_paper();continue;
			case 3:user_admin();continue;
			case 4:situation_analysis();continue;
			case 6:;continue;
			case 0:
			default:break;
		}
		break;
	}

}

void menuPrint_2(int a) {

	system("cls");
	char name[15]={"menu_2.txt"};

	
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

//------------------------------------------

void question_admin() {

	question(); // ->question.cpp

}

void auto_paper() {

	system("mode con cols=30 lines=12");
	system("color 0F");
	
	struct info * head = NULL;
	head=read_info();
	struct info * node = head;
	struct info * temp = NULL;
	if(node==NULL) {
		printf("当前题库为空!");
		return ;
	}

	fflush(stdin);
	int num,score;
	printf("请输入题目数:");
	scanf("%2d",&num);
	printf("请输入总分:");
	scanf("%3d",&score);

	int i,j;
	int *no;
	no=(int *)malloc(sizeof(int)*num);
	if(no==NULL)
		exit(-1);
	int count,success=1,time=0;
	while(success){
		time++;//尝试生成次数
		i=0,j=0,count=0;//count为随机生成的题号
		while(i<sum)
		{
			while(j<=score-5)
			{
				count++;
				if(rand()%2==0)
					if( (temp=find_info_num(head,count))!=NULL )
					{
						no[i++]=temp->no;
						j+=temp->score;
					}
			}

		}
		if(i==num&&j==score)
			success=0;
	}

	FILE * fp;
	fp=fopen("paper.txt","r");
	if(fp==NULL) {
		printf("cannot open %s\n",name);
		exit (0);
	}

}

void user_admin() {


}

void situation_analysis() {


}

//------------------------------------------

struct info * find_info_num(struct info * head,int num) {

	struct info * node = head;

	while(node->next!=NULL){
		if(node->next->no==num)
			return node;
		node=node->next;
	}
	return NULL;
}


struct info * find_info_score_num(struct info * head,int lev) {

	struct info * node = head;

	while(node->next!=NULL){
		if(node->next->score==lev)
			return node->next;
		node=node->next;
	}
	return NULL;
}