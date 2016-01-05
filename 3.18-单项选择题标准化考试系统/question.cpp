/*
(1) 管理员功能

    试题管理：每个试题包括题干、4个备选答案、标准答案等信息。
	可进行试题添加、删除、修改、查询、保存、浏览等操作。

*/

//question.cpp created time 2016-1-3 23:45:41

#include "all.h"

void question() {
		
	int a;
	struct info * head = NULL;
	read_info(head);

	while (1) {

		system("mode con cols=57 lines=20");
		system("color 3F");

		a = move_1(6,menuPrint_3);
		switch (a) {
			//1.
			case 1:;continue;
			case 2:input_info(head);continue;
			case 3:;continue;
			case 4:;continue;
			case 5:print_info(head);continue;
			case 6:;continue;
			case 0:
			default:break;
		}
		break;
	}
	write_info(head);
	free_info(head);  //save
}

void menuPrint_3(int a) {

	system("cls");
	char name[15]={"menu_3.txt"};

	
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

struct info * solo_info() {

    struct info * node = NULL;
    node = (struct info *)malloc(sizeof(struct info));
    memset(node, 0, sizeof(struct info));
    if (node == NULL) {
        printf("申请内存失败!");
        exit(-1);
    }else{
		node->next=NULL;
	}
    return node;
}

void input_info(struct info * head) {

	int i,j;
	char ch;
	struct info * node = NULL;
	struct info * tail = head;
	
	node = solo_info();
	while(tail->next!=NULL)
		tail = tail->next;
	tail->next = node;

	system("mode con cols=50 lines=40");
	system("color 0F");

	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	printf("       输入题目信息\n\n");
	printf("     ---------------------\n");
	printf("     | 难度(1-10): |     |\n");
	printf("     ---------------------\n");
	printf("\n");
	printf("     ---------------------\n");
	printf("     | 分值 (1-5): |     |\n");
	printf("     ---------------------\n");
	printf("\n");
	printf("     ---------------------\n");
	printf("     | 正确选项: |       |\n");
	printf("     |   A---D   |       |\n");
	printf("     ---------------------\n");
	printf("\n");
	
	node->no = tail->no+1;

	fflush(stdin);
	goto_pos(22,6);
	scanf("%2d",&node->lever);

	fflush(stdin);
	goto_pos(22,10);
	scanf("%2d",&node->score);

	fflush(stdin);
	goto_pos(22,14);
	ch=getchar();
	node->rightAnswer=ch-'A';

	system("cls");
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	printf("       输入题目信息\n\n");
	printf("     ---------------------\n");
	printf("      请输入题目描述:\n");
	fflush(stdin);
	for(j=0;j<1000;j++) {
		ch=getchar();
		if(ch!='\n')
			node->statement[j]=ch;
		else
			break;
	}

	for(i=0;i<4;i++) {
		printf("请输入%c选项内容",'A'+i);
		fflush(stdin);
		for(j=0;j<100;j++) {
			ch=getchar();
			if(ch!='\n')
				node->options[i][j]=ch;
			else
				break;
		}
	}

	printf("请输入5个关键字,并用空格隔开,或以 @+回车 结束关键字的输入.\n");
	fflush(stdin);
	for(i=0;i<4;i++) {
		for(j=0;j<40;j++) {
			ch=getchar();
			if(ch!='\n'&&ch!=' ')
				node->keyWords[i][j]=ch;
			else
				break;
		}
		if(node->keyWords[i][0]=='@')
			break;
	}

	printf("请输入%c选项的正确原因:\n",'A'+node->rightAnswer);
	fflush(stdin);
	scanf("%300s",node->answers[node->rightAnswer]);

	for(i=0;i<4;i++) {
		if(i==node->rightAnswer)
			continue;
		printf("请输入%c选项的错误原因:\n",'A'+i);
		fflush(stdin);
		scanf("%300s",node->answers[i]);
	}

	node->timeAdd=node->timeModify=time(NULL);

	printf("添加试题成功!正在返回主菜单...");
	Sleep(1300);

}

//已废
struct info * find_info_tail(struct info * head) {

	struct info * node = NULL;
	node = solo_info();
	while(head->next!=NULL)
		head = head->next;
	head->next = node;
	return node;

}

//已废
void add_info(struct info * node) {

	struct info * tail = NULL;
	//struct info * node = NULL;
	node = solo_info();
	input_info(node);

	tail->next = node;
}

void write_info(struct info * head) {

	FILE * fp;
	if ((fp = fopen("info.txt", "w")) == NULL) {
		printf("打开文件失败");
		exit(-2);
	}
    printf("写入文件中");
    while(head->next!=NULL)
    {
        printf(".");
		head = head->next;
        if(fwrite(head, sizeof(struct info), 1, fp)!=1) {
            printf("写入文件失败");
            exit(-2);
        }
		
    }
    //printf("写入完成\n");
	fclose(fp);
}

void read_info(struct info * head) {

	int i=0;
	FILE * fp;
	struct info * node = NULL;
	struct info * tail = NULL;

	//head=solo_info();

	if ((fp = fopen("info.txt", "r")) == NULL) {
		system("cls");
		printf("读取文件失败");
		exit(-3);
	}
	tail=head=solo_info();
	while(!feof(fp)){

		node=solo_info();
		if(fread(node, sizeof(struct info),1 , fp)==1){
			tail->next=node;
			tail=node;
		}
	}

	//!@#$%^&*()_)(*&^%$#@!@#$%^&*())(*&^%$#@!#$%^&*()(*&^%$#@

	fclose(fp);
}

void free_info(struct info * head) {
    
    struct info * p = NULL;
    while (head!=NULL) {
        p = head->next;
        free(head);
        head = p;
    }
    return ;
}

void print_info(struct info * head) {

	system("cls");
	printf("正在读取数据...\n");
	if (head->next==NULL) {
		printf("当前题库为空!");
	}else{
		struct info * p = head->next;
		while (p!=NULL) {

			printf("试题编号: %3d",p->no);
			printf("题目难度: %2d",p->lever);

			p=p->next;
		}
	}
	printf("\n请按任意键返回菜单...");
	getch();
}