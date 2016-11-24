//  C_playground6_LinkedList main.c
//  链表与文件
//  Created by  Reign on 15/12/16.
//  本文件采用utf-8编码

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct birthday {
	unsigned int year;
	unsigned int month;
	unsigned int day;
};

struct info {
	char name[20];
	char no[10];
	struct birthday date;
	struct info * next;
};

//solo -> 单个初始化(申请内存)

struct info * solo() {
    struct info * node=NULL;
    node = (struct info *)malloc(sizeof(struct info));
    memset(node, 0, sizeof(struct info));
    if (node == NULL) {
        printf("申请内存失败!");
        exit(-1);
    }
    return node;
}

//initialization -> 初始化(申请内存) 暂不使用 仅作参照

struct info * initialization(int len) {
	struct info * head = NULL;
	struct info * node = NULL;
	int i;
	for (i = 0; i<len; i++) {
        node=solo();
		node->next = head;
		head = node;
	}
    printf("初始化链表完毕!\n");
	return head;
}

//traversal -> 遍历

struct info * traversal() {
    
    struct info * head = NULL;
    struct info * node = NULL;
    
    int i,len;
	char ch='c';
    printf("学生的个数是: ");
    scanf("%d",&len);
	for (i = 0; i<len; i++) {
        node = solo();
		while ((ch = getchar()) != '\n' && ch !=' ');//使用ch大法吃回车和空格...
		printf("请输入名字: ");
		scanf("%20s",node->name);
		printf("请输入学号: ");
		scanf("%10s",node->no);
		printf("请输入生日: 如 1666 06 06\n");
		scanf("%d%d%d", &node->date.year, &node->date.month, &node->date.day);
		node->next = head;
        head = node;
        
	}
    return head;
}

//print -> 输出到屏幕

void print(struct info * head) {

	while(head!=NULL)
    {
		printf("%s\t",head->name);
		printf("%s\t",head->no);
		printf("%d-%d-%d\n", head->date.year, head->date.month, head->date.day);
		head = head->next;
	}
    printf("输出完毕\n");
}

//output -> 输出到文件

void output(struct info * head) {
	FILE * fp;
	if ((fp = fopen("test.txt", "w")) == NULL) {
		printf("打开文件失败");
		exit(-2);
	}
    printf("写入文件中");
    while(head!=NULL)
    {
        printf(".");
        if(fwrite(head, sizeof(struct info), 1, fp)!=1) {
            printf("写入文件失败");
            exit(-2);
        }
		head = head->next;
    }
    printf("写入完成\n");
	fclose(fp);
}

//readFromFile -> 从文件中读取

struct info * readFromFile() {
	struct info * head = NULL;
	struct info * node = NULL;

	FILE * fp;
	
	if ((fp = fopen("test.txt", "r")) == NULL) {
		printf("读取文件失败");
		exit(-3);
	}
	int temp = 0;
	int i;
	printf("读取的数目： ");
	scanf("%d", &temp);

	for (i = 0; i<temp&&(!feof(fp)); i++) {
	
			printf("读取文件中...\n");
            node = solo();
			
			if(fread(node, sizeof(struct info),1 , fp)!=1)
                printf("第%d->%d组数据存放链表失败\n",i+1,temp);
            
			node->next = head;
			head = node;
	}
	fclose(fp);
	return head;
}

//freeAll -> 释放当前链表内存

void freeAll(struct info * head) {
    
    struct info * p = NULL;
    while (head!=NULL) {
        p = head->next;
        free(head);
        head = p;
    }
    printf("释放内存完毕\n");
}

int main() {
	
	struct info * p = NULL;
	
	int s = 1;
	while (s != 0) {

		printf("0.exit -> 退出程序\n");
		printf("1.traversal -> 遍历\n");
		printf("2.print -> 输出到屏幕\n");
		printf("3.output -> 输出到文件\n");
		printf("4.readFromFile -> 从文件中读取\n");
		printf("5.freeAll -> 释放当前链表内存\n");
		scanf("%d", &s);
		switch (s) {
		case 1:p=traversal(); break;
		case 2:print(p); break;
		case 3:output(p); break;
		case 4:p=readFromFile(); break;
		case 5:freeAll(p);p=NULL; break;
		default:break;
		}
	}

	return 0;
}

