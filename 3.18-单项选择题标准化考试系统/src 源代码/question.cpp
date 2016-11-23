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
	head=read_info();

	while (1) {

		system("mode con cols=57 lines=20");
		system("color 3F");

		a = move_1(6,menuPrint_3);
		switch (a) {
			//1.
			case 1:find_info(head);continue;
			case 2:input_info(head);continue;
			case 3:find_info(head);continue;
			case 4:find_info(head);continue;
			case 5:
				system("cls");
				print_info(head->next);
				system("pause");
				continue;
			case 0:
			default:break;
		}
		break;
	}
	write_info(head);
	free_info(head);  //save
}

/*
 试题管理界面       admin


               1.查找试题

               2.添加试题     

               3.删除试题

               4.修改试题

               5.浏览试题    

               0.保存并退出
*/

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

	system("mode con cols=30 lines=20");
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
	goto_pos(22,7);
	scanf("%2d",&node->lever);

	fflush(stdin);
	goto_pos(22,11);
	scanf("%2d",&node->score);

	fflush(stdin);
	goto_pos(22,15);
	ch=getchar();
	node->rightAnswer=ch-'A';

	system("cls");
	system("mode con cols=50 lines=40");
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	printf("                  输入题目信息\n\n");
	printf("              ---------------------\n\n");
	printf("请输入题目描述(支持换行,请用@结束输入):\n");
	fflush(stdin);
	for(j=0;j<1000;j++) {
		ch=getchar();
		if(ch!='@')
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
	for(i=0;i<5;i++) {
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
	node->next=NULL;

	printf("添加试题成功!正在返回主菜单...");
	Sleep(1300);

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

struct info * read_info() {

	int i=0;
	FILE * fp;
	struct info * head = NULL;
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
	return head;
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

void print_info(struct info * node) {

	int i;
	system("mode con cols=80 lines=1000");
	
	printf("正在读取数据...\n");
	if (node==NULL) {
		printf("当前题库为空!");
	}else{
		struct info * p = node;
		while (p!=NULL) {
			printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf(" no:%3d ",p->no);
			printf(" lever:%2d ",p->lever);
			printf(" score:%d ",p->score);
			printf("\n statement:\n\t%s\n\n",p->statement);

			printf(" keyWords:");
			for(i=0;i<5;i++)
				if(p->keyWords[i][0]!='@')
					printf("%s ",p->keyWords[i]);
				else
					break;
			printf("\n");

			printf(" A:%s\t",p->options[0]);
			printf(" B:%s\n",p->options[1]);
			printf(" C:%s\t",p->options[2]);
			printf(" D:%s\n",p->options[3]);
			//printf("rightAnswer:%c",'A'+p->rightAnswer);
			printf(" %c right,because %s\n",'A'+p->rightAnswer,p->answers[p->rightAnswer]);
			for(i=0;i<4;i++) {
				if(i==p->rightAnswer)
					continue;
				printf(" %c wrong,because %s\n",'A'+i,p->answers[i]);
			}
			printf(" timeAdd:   ");
			print_time(p->timeAdd);
			printf(" timeModify:");
			print_time(p->timeModify);

			p=p->next;
		}
	}
}


void print_info_solo(struct info * node) {

	int i;

	
	if (node==NULL) {
		printf("当前结点为空!");
	}else{
		struct info * p = node;
		
			printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf(" no:%3d ",p->no);
			printf(" lever:%2d ",p->lever);
			printf(" score:%d ",p->score);
			printf("\n statement:\n\t%s\n\n",p->statement);

			printf(" keyWords:");
			for(i=0;i<5;i++)
				if(p->keyWords[i][0]!='@')
					printf("%s ",p->keyWords[i]);
				else
					break;
			printf("\n");

			printf(" A:%s\t",p->options[0]);
			printf(" B:%s\n",p->options[1]);
			printf(" C:%s\t",p->options[2]);
			printf(" D:%s\n",p->options[3]);
			//printf("rightAnswer:%c",'A'+p->rightAnswer);
			printf(" %c right,because %s\n",'A'+p->rightAnswer,p->answers[p->rightAnswer]);
			for(i=0;i<4;i++) {
				if(i==p->rightAnswer)
					continue;
				printf(" %c wrong,because %s\n",'A'+i,p->answers[i]);
			}
			printf(" timeAdd:   ");
			print_time(p->timeAdd);
			printf(" timeModify:");
			print_time(p->timeModify);			
		
	}
}

void fprint_info_solo(FILE *fp,struct info * node) {

	int i;
	
	if (node==NULL) {
		printf("当前结点为空!");
	}else{
		struct info * p = node;
		
			fprintf(fp,"%s","\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			fprintf(fp," no:%3d ",p->no);
			fprintf(fp," lever:%2d ",p->lever);
			fprintf(fp," score:%d ",p->score);
			fprintf(fp,"\n statement:\n\t%s\n\n",p->statement);

			fprintf(fp,"%s"," keyWords:");
			for(i=0;i<5;i++)
				if(p->keyWords[i][0]!='@')
					fprintf(fp,"%s ",p->keyWords[i]);
				else
					break;
			fprintf(fp,"%s","\n");

			fprintf(fp," A:%s\t",p->options[0]);
			fprintf(fp," B:%s\n",p->options[1]);
			fprintf(fp," C:%s\t",p->options[2]);
			fprintf(fp," D:%s\n",p->options[3]);
			
			fprintf(fp," %c right,because %s\n",'A'+p->rightAnswer,p->answers[p->rightAnswer]);
			for(i=0;i<4;i++) {
				if(i==p->rightAnswer)
					continue;
				fprintf(fp," %c wrong,because %s\n",'A'+i,p->answers[i]);
			}		
		
	}
}
