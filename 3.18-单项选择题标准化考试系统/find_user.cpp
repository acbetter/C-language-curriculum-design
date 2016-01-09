//find_user.cpp created time 2016-1-9 11:01:10

#include "all.h"

struct user * find_user(struct user * head) {

	int a;
	struct user * find = NULL;
		
	while (1) {

		system("mode con cols=57 lines=20");
		system("color 4E");

		a = move_1(3,menuPrint_6);
		system("cls");
		switch (a) {
			//1.
			case 1:find=find_user_name_key(head);break;
			case 2:find=find_user_no_key(head);break;
			case 3:find=find_user_name(head);break;
			case 4:find=find_user_no(head);break;
			case 5:find=find_user_time(head);break;
			case 0:
			default:break;
		}
		if(find!=NULL)
			find_user_next(find);
		break;
	}
	return find;
}


/*
               查找学生界面       admin


               1.按名字(模糊)查找

               2.按学号(模糊)查找     

               3.按名字(精确)查找

               4.按学号(精确)查找

               5.最近登录的学生   

               0.返回上一层
*/

void menuPrint_6(int a) {

	system("cls");
	char name[15]={"menu_6.txt"};

	
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

struct user * find_user_name_key(struct user * head) {

	int count=0,sign=0;
	struct user * node = head;
	struct user * find = NULL;
	char key[20];
	memset(key,0,sizeof(char)*20);

	system("cls");
	printf(" ---按学生姓名(模糊)查找---\n 请输入关键字:\n");
	fflush(stdin);
	scanf("%19s",key);
	printf(" 正在查找...\n");
	system("mode con cols=80 lines=1000");
	while(node->next!=NULL){
		if(fuzzy_search(node->next->name,key)){
			print_user_solo(node->next);
			find=node;
			sign++;
		}
		count++;
		node=node->next;
	}
	printf("\n 查找完毕!累计查找%d次,查找结果%d条\n",count,sign);
	if(sign==1)
		return find;
	else if(sign>1)
		return find_user_no(head);
	else{
		printf(" 没有找到结果,正在返回上一级菜单...");
		Sleep(3000);
		return NULL;
	}
	return NULL;
}


struct user * find_user_no_key(struct user * head) {

	int count=0,sign=0;
	struct user * node = head;
	struct user * find = NULL;
	char key[20];
	memset(key,0,sizeof(char)*20);

	system("cls");
	printf(" ---按学生学号(模糊)查找---\n 请输入关键字:\n");
	fflush(stdin);
	scanf("%19s",key);
	printf(" 正在查找...\n");
	system("mode con cols=80 lines=1000");
	while(node->next!=NULL){
		if(fuzzy_search(node->next->no,key)){
			print_user_solo(node->next);
			find=node;
			sign++;
		}
		count++;
		node=node->next;
	}
	printf("\n 查找完毕!累计查找%d次,查找结果%d条\n",count,sign);
	if(sign==1)
		return find;
	else if(sign>1)
		return find_user_no(head);
	else{
		printf(" 没有找到结果,正在返回上一级菜单...");
		Sleep(3000);
		return NULL;
	}
	return NULL;
}



void delete_user_no(struct user * find) {

	struct user * node = find->next;
	printf(" 删除学生 %s %s 成功!\n",node->no,node->name);
	find->next=node->next;
	free(node);
	node=NULL;	
}

struct user * find_user_no(struct user * head) {

	char num[11];
	struct user * node = head;

	printf(" 请输入学号以选择单个学生(输入0则退出):\n");
	fflush(stdin);
	scanf("%s",num);
	printf(" 正在定位...\n");
	system("mode con cols=80 lines=30");
	while(node->next!=NULL){
		if( strcmp(node->next->no,num)==0 ){
			print_user_solo(node->next);
			return node;
		}
		node=node->next;
	}
	printf(" 没有找到结果,正在返回上一级菜单...");
	Sleep(3000);
	return NULL;
}

struct user * find_user_name(struct user * head) {

	char num[11];
	struct user * node = head;

	printf(" 请输入名字以查找单个学生(输入0则退出):\n");
	fflush(stdin);
	scanf("%s",num);
	printf(" 正在定位...\n");
	system("mode con cols=80 lines=30");
	while(node->next!=NULL){
		if( strcmp(node->next->name,num)==0 ){
			print_user_solo(node->next);
			return node;
		}
		node=node->next;
	}
	printf(" 没有找到结果,正在返回上一级菜单...");
	Sleep(3000);
	return NULL;
}

void change_user(struct user * node) {

	int s = 2;
	char ch[30];
	while (s!=0) {

		printf("\n 请输入相应的数字,按回车结束...\n");
		printf(" 1.no -> 修改学号\n");
		printf(" 2.password -> 修改密码\n");
		printf(" 3.name -> 修改名字\n");

		printf(" 0.return -> 返回菜单\n\t\t");

		fflush(stdin);
		scanf("%d", &s);
		fflush(stdin);

		switch(s) {
			case 1:
				printf("请输入新的学号: ");
				scanf("%20s",ch);
				if(strlen(ch)==11){
					strcpy(node->no,ch);
					printf("---修改成功!\n");
					s=0;
				}else{
					printf("---修改失败! 原因:输入的学号不是10位\n");
					Sleep(1300);
					s=0;
				}
				break;
			case 2:
				printf("请输入新的密码: ");
				scanf("%20s",ch);
				if(strlen(ch)>=6){
					strcpy(node->password,ch);
					printf("---修改成功!\n");
					s=0;
				}else{
					printf("---修改失败! 原因:密码过于简单\n");
					Sleep(1300);
					s=0;
				}
				break;
			case 3:
				printf("请输入新的名字: ");
				scanf("%20s",node->name);
				printf("---修改成功!\n");
				s=0;
				break;
			default:
				break;
		}//匹配switch
	}//匹配while

	print_user_solo(node);
}


void find_user_next(struct user * node) {

	int s = 2;
	while (s!=0) {

		printf("\n 请输入相应的数字,按回车结束...\n");
		printf(" 1.change -> 修改\n");
		printf(" 2.delete -> 删除\n");
		printf(" 0.return -> 返回菜单\n\t\t");

		fflush(stdin);
		scanf("%d", &s);
		switch (s) {
			case 1:change_user(node->next); break;
			case 2:delete_user_no(node); break;
			default:break;
		}
	}
}

/*

struct user * find_user_lever(struct user * head) {

	int count=0,sign=0;
	struct user * node = head;
	struct user * find = NULL;
	int lev;

	system("cls");
	printf(" 请输入题目难度:\n");
	fflush(stdin);
	scanf("%2d",&lev);
	printf(" 正在查找...\n");
	system("mode con cols=80 lines=1000");
	while(node->next!=NULL){
		if(node->next->lever==lev){
			print_user_solo(node->next);
			find=node;
			sign++;
		}
		count++;
		node=node->next;
	}
	printf("\n 查找完毕!累计查找%d次,查找结果%d条\n",count,sign);
	if(sign==1)
		return find;
	else if(sign>1)
		return find_user_no(head);
	else{
		printf(" 没有找到结果,正在返回上一级菜单...");
		Sleep(3000);
		return NULL;
	}
	return NULL;
}


struct user * find_user_score(struct user * head) {

	int count=0,sign=0;
	struct user * node = head;
	struct user * find = NULL;
	int lev;

	system("cls");
	printf(" 请输入题目难度:\n");
	fflush(stdin);
	scanf("%2d",&lev);
	printf(" 正在查找...\n");
	system("mode con cols=80 lines=1000");
	while(node->next!=NULL){
		if(node->next->score==lev){
			print_user_solo(node->next);
			find=node;
			sign++;
		}
		count++;
		node=node->next;
	}
	printf("\n 查找完毕!累计查找%d次,查找结果%d条\n",count,sign);
	if(sign==1)
		return find;
	else if(sign>1)
		return find_user_no(head);
	else{
		printf(" 没有找到结果,正在返回上一级菜单...");
		Sleep(3000);
		return NULL;
	}
	return NULL;
}

*/


struct user * find_user_time(struct user * head) {

	int count=0,sign=0;
	struct user * node = head;
	struct user * find = NULL;

	system("cls");
	printf(" 正在查找...\n");
	system("mode con cols=80 lines=1000");
	while(node->next!=NULL){
		if( (time(NULL)-node->next->timeLogin)<=250942){
			print_user_solo(node->next);
			find=node;
			sign++;
		}
		count++;
		node=node->next;
	}
	printf("\n 查找完毕!累计查找%d次,查找结果%d条\n",count,sign);
	if(sign==1)
		return find;
	else if(sign>1)
		return find_user_no(head);
	else{
		printf(" 没有找到结果,正在返回上一级菜单...");
		Sleep(3000);
		return NULL;
	}
	return NULL;
}
