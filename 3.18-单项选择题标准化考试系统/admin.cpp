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
/*
void admin() {

	system("mode con cols=57 lines=20");
	system("color 0A");

	int a;
		
	while (1) {

		a = move(5);
		switch (a) {
			//1.
			case 1:admin();continue;
			case 2:;continue;
			case 3:;continue;
			case 6:;continue;
			case 0:exit(0);
			default:break;
		}
	}

}

void menuPrint_2() {

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
		case 1:printLaugh(32,6);break;
		case 2:printLaugh(32,8);break;
		case 3:printLaugh(32,10);break;
		case 4:printLaugh(32,12);break;
		case 5:printLaugh(32,14);break;
		case 0:printLaugh(32,16);break;
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


*/