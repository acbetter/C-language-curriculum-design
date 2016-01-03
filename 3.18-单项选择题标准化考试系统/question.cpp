/*
(1) 管理员功能

    试题管理：每个试题包括题干、4个备选答案、标准答案等信息。
	可进行试题添加、删除、修改、查询、保存、浏览等操作。

*/

//question.cpp created time 2016-1-3 23:45:41

#include "all.h"

void question() {
		
	int a;
	struct info * tail = NULL;

	while (1) {

		system("mode con cols=57 lines=20");
		system("color 3F");

		a = move_1(5,menuPrint_3);
		switch (a) {
			//1.
			case 1:;continue;
			case 2:;continue;
			case 3:;continue;
			case 4:;continue;
			case 6:;continue;
			case 0:
			default:break;
		}
		break;
	}
	//save

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

//带头结点的尾插法

struct info * solo() {

    struct info * node = NULL;
    node = (struct info *)malloc(sizeof(struct info));
    memset(node, 0, sizeof(struct info));
    if (node == NULL) {
        printf("申请内存失败!");
        exit(-1);
    }
    return node;
}

void input_info(struct info * tail) {

	int i;
	struct info * node = NULL;
	
	node = solo();

	system("mode con cols=50 lines=40");
	system("color 0F");

	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	printf("       输入题目信息\n\n");
	printf("     ---------------------\n");
	printf("     | 难度(1-10): |           |\n");
	printf("     ---------------------\n");
	printf("\n");
	printf("     ---------------------\n");
	printf("     | 分值 (1-5): |           |\n");
	printf("     ---------------------\n");
	printf("\n");
	printf("     ---------------------\n");
	printf("     | 正确选项:  |       |\n");
	printf("     |   A---D	|       |\n");
	printf("     ---------------------\n");
	printf("\n");
	
	node->no = tail->no+1;

	fflush(stdin);
	goto_pos(16,7);
	scanf("%d",node->lever);
	fflush(stdin);
	goto_pos(16,11);
	scanf("%d",node->score);

	system("cls");
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	printf("       输入题目信息\n\n");
	printf("     ---------------------\n");
	printf("      请输入题目描述:\n");
	fflush(stdin);
	scanf("%1000s",node->statement);

	printf("请输入5个关键字,并用空格隔开,或以 @+回车 结束关键字的输入.\n");
	for(i=0;i<4;i++) {
		scanf("%40s",node->keyWords[i]);
		if( *(node->keyWords[i])=='@' )
			break;
	}

	printf("请输入%c选项的正确原因:\n",'A'+node->rightAnswer);
	fflush(stdin);
	scanf("%300s",node->answers[node->rightAnswer]);

	for(i=0;i<3;i++) {
		if(i==node->rightAnswer)
			continue;
		printf("请输入%c选项的错误原因:\n",'A'+i);
		fflush(stdin);
		scanf("%300s",node->answers[i]);
	}

	node->timeAdd=node->timeModify=time(NULL);

	


}

void add(struct info * tail) {

	struct info * node = NULL;
	input_info(tail);
	

}
