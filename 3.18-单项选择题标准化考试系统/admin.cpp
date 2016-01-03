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
			case 1:;continue;
			case 2:;continue;
			case 3:;continue;
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


}

void auto_paper() {


}

void user_admin() {


}

void situation_analysis() {


}


