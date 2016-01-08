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
	//head=read_user();

	while (1) {

		system("mode con cols=57 lines=20");
		system("color 3F");

		a = move_1(6,menuPrint_5);
		switch (a) {
			//1.
			//case 1:find_user(head);continue;
			//case 2:input_user(head);continue;
			//case 3:find_user(head);continue;
			//case 4:find_user(head);continue;
			case 5:
				system("cls");
			//	print_user(head->next);
				system("pause");
				continue;
			case 0:
			default:break;
		}
		break;
	}
	//write_user(head);
	//free_user(head);  //save
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

	int i,j;
	char ch;
	struct user * node = NULL;
	struct user * tail = head;
	
	node = solo_user();
	while(tail->next!=NULL)
		tail = tail->next;
	tail->next = node;

	system("mode con cols=30 lines=22");
	system("color 3A");

	//char name[10]={"admin"},password[10]={"admin"};

	for(i=0;i<3;i++) {
		system("cls");
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
		printf("           学生注册\n\n");
		printf("     ---------------------\n");
		printf("     | 学号: |           |\n");
		printf("     ---------------------\n");
		printf("\n");
		printf("     ---------------------\n");
		printf("     | 密码: |           |\n");
		printf("     ---------------------\n");
		printf("\n");
		printf("     ---------------------\n");
		printf("     | 学号必须是10位数字|\n");
		printf("     | 密码之间不能有空格|\n");
		printf("     | 按回车键完成输入..|\n");
		printf("     ---------------------\n");
		printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		fflush(stdin);
		goto_pos(16,7);
		scanf("%10s",);
		fflush(stdin);
		goto_pos(16,11);
		scanf("%10s",get_2);
		
		if(strlen(node->no)==11&&strlen(){
			goto_pos(11,17);
			printf("注册成功!");
			Sleep(1800);
			return ;
		}else{
			goto_pos(11,17);
			printf("注册失败\n    请重新注册 (剩余次数:%d)",2-i);
			free(node);
			Sleep(1300);
		}
	}
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

	int i;
	system("mode con cols=80 lines=1000");
	
	printf("正在读取数据...\n");
	if (node==NULL) {
		printf("没有任何学生信息!");
	}else{
		struct user * p = node;
		while (p!=NULL) {


		}
	}
}


void print_user_solo(struct user * node) {

	int i;

	
	if (node==NULL) {
		printf("当前结点为空!");
	}else{
		struct user * p = node;
		
			printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf(" no:%3d ",p->no);
			printf(" lever:%2d ",p->lever);
			
	}
}









