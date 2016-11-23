//  C_playground6_LinkedList main.c
//  链表与文件
//  Created by  Reign on 15/12/16.
//  本文件采用utf-8编码

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct birthday
{
    unsigned int year;
    unsigned int month;
    unsigned int day;
};

struct info
{
    char name[20];
    char no[10];
    struct birthday date;
    struct info *next;
};

//solo -> 单个初始化(申请内存)

struct info *solo()
{
    struct info *node = NULL;
    node = (struct info *)malloc(sizeof(struct info));
    memset(node, 0, sizeof(struct info));
    if (node == NULL)
    {
	printf("申请内存失败!");
	exit(-1);
    }
    return node;
}

//initialization -> 初始化(申请内存) 暂不使用 仅作参照

struct info *initialization(int len)
{
    struct info *head = NULL;
    struct info *node = NULL;
    int i;
    for (i = 0; i < len; i++)
    {
	node = solo();
	node->next = head;
	head = node;
    }
    printf("初始化链表完毕!\n");
    return head;
}

//traversal -> 遍历(不含头结点的头插法)

struct info *traversal()
{

    struct info *head = NULL;
    struct info *node = NULL;

    int i, len;
    char ch = 'c';
    printf("学生的个数是: ");
    scanf("%300d", &len);
    for (i = 0; i < len; i++)
    {
	node = solo();
	while ((ch = getchar()) != '\n' && ch != ' ')
	    ; //使用ch大法吃回车和空格...
	printf("请输入名字: ");
	scanf("%20s", node->name);
	printf("请输入学号: ");
	scanf("%10s", node->no);
	printf("请输入生日: 如 1666 06 06\n");
	scanf("%d%d%d", &node->date.year, &node->date.month, &node->date.day);
	node->next = head;
	head = node;
    }
    return head;
}

//traversal_1 -> 遍历(不含头结点的尾插法)

struct info *traversal_1()
{

    struct info *tail = NULL;
    struct info *head = NULL;
    struct info *node = NULL;

    int i, len;
    char ch = 'c';
    printf("学生的个数是: ");
    scanf("%300d", &len);
    for (i = 0; i < len; i++)
    {

	node = solo();

	while ((ch = getchar()) != '\n' && ch != ' ')
	    ; //使用ch大法吃回车和空格...
	printf("请输入名字: ");
	scanf("%20s", node->name);
	printf("请输入学号: ");
	scanf("%10s", node->no);
	printf("请输入生日: 如 1666 06 06\n");
	scanf("%d%d%d", &node->date.year, &node->date.month, &node->date.day);

	if (i == 0)
	    head = tail = node;
	else
	{
	    tail->next = node;
	    tail = node;
	}
    }
    return head;
}

//print -> 输出到屏幕

void print(struct info *head)
{

    while (head != NULL)
    {
	printf("%s\t", head->name);
	printf("%s\t", head->no);
	printf("%d-%d-%d\n", head->date.year, head->date.month, head->date.day);
	head = head->next;
    }
    printf("输出完毕\n");
}

//output -> 输出到文件

void output(struct info *head)
{
    FILE *fp;
    if ((fp = fopen("test.txt", "w")) == NULL)
    {
	printf("打开文件失败");
	exit(-2);
    }
    printf("写入文件中");
    while (head != NULL)
    {
	printf(".");
	if (fwrite(head, sizeof(struct info), 1, fp) != 1)
	{
	    printf("写入文件失败");
	    exit(-2);
	}
	head = head->next;
    }
    printf("写入完成\n");
    fclose(fp);
}

//readFromFile -> 从文件中读取(不含头结点的头插法)

struct info *readFromFile()
{
    struct info *head = NULL;
    struct info *node = NULL;

    FILE *fp;

    int temp = 0;
    int i;
    if ((fp = fopen("test.txt", "r")) == NULL)
    {
	printf("读取文件失败");
	exit(-3);
    }

    printf("读取的数目： ");
    scanf("%4d", &temp);

    for (i = 0; i < temp && (!feof(fp)); i++)
    {

	printf("读取文件中...\n");
	node = solo();

	if (fread(node, sizeof(struct info), 1, fp) != 1)
	{
	    printf("第%d->%d组数据存放链表失败\n", i + 1, temp);
	    free(NULL);
	    node = NULL;
	}

	node->next = head;
	head = node;
    }
    fclose(fp);
    return head;
}

//readFromFile_1 -> 从文件中读取(不含头结点的尾插法)

struct info *readFromFile_1()
{
    struct info *head = NULL;
    struct info *tail = NULL;
    struct info *node = NULL;

    FILE *fp;

    int temp = 0;
    int i;
    if ((fp = fopen("test.txt", "r")) == NULL)
    {
	printf("读取文件失败");
	exit(-3);
    }

    printf("读取的数目： ");
    scanf("%d", &temp);

    for (i = 0; i < temp && (!feof(fp)); i++)
    {

	printf("读取文件中...\n");
	node = solo();

	if (fread(node, sizeof(struct info), 1, fp) != 1)
	{
	    printf("第%d->%d组数据存放链表失败\n", i + 1, temp);
	    free(NULL);
	    node = NULL;
	}
	if (i == 0)
	    head = tail = node;
	else
	{
	    tail->next = node;
	    tail = node;
	}
    }
    fclose(fp);
    return head;
}

//deleteWithNo -> 通过学号删除指定链表

void deleteWithNo(struct info *head)
{

    int i;
    char ch;
    char *p = (char *)malloc(sizeof(char) * 30);
    memset(p, 0, sizeof(char) * 30);
    struct info *node = head;
    struct info *temp = NULL;

    printf("请输入要删除学生的学号: ");
    fflush(stdin);
    //	while ((ch = getchar()) != '\n' && ch !=' ');//使用ch大法吃回车和空格...
    scanf("%s", p);
    printf("要删除学生的学号是: %s\n", p);
    for (i = 0;; i++)
    {

	if (head != NULL && head->next != NULL && strcmp(node->next->no, p) == 0)
	{
	    temp = node->next;
	    node->next = node->next->next;
	    free(temp);
	    printf("删除完毕,累计查找%d次\n", i + 1);
	    return;
	}
	else
	    node = node->next;
    }
    printf("对不起,查找了%d次后,依然没有查找到该学生.\n", i + 1);
    return;
}

//freeAll -> 释放当前链表内存

void freeAll(struct info *head)
{

    struct info *p = NULL;
    while (head != NULL)
    {
	p = head->next;
	free(head);
	head = p;
    }
    printf("释放内存完毕\n");
}

int main()
{

    struct info *p = NULL;

    int s = 2;
    while (s != 0)
    {

	printf("0.exit -> 退出程序\n");

	printf("1.traversal -> 遍历(不含头结点的头插法)\n");
	printf("2.traversal_1 -> 遍历(不含头结点的尾插法)\n");

	printf("3.readFromFile -> 从文件中读取(不含头结点的头插法)\n");
	printf("4.readFromFile_1 -> 从文件中读取(不含头结点的尾插法)\n");

	printf("5.print -> 输出到屏幕\n");
	printf("6.output -> 输出到文件\n");

	printf("8.deleteWithNo -> 通过学号删除指定链表\n");

	printf("9.freeAll -> 释放当前链表内存\n");

	scanf("%d", &s);
	switch (s)
	{
	case 1:
	    p = traversal();
	    break;
	case 2:
	    p = traversal_1();
	    break;
	case 3:
	    p = readFromFile();
	    break;
	case 4:
	    p = readFromFile_1();
	    break;
	case 5:
	    print(p);
	    break;
	case 6:
	    output(p);
	    break;
	case 8:
	    deleteWithNo(p);
	    break;
	case 9:
	    freeAll(p);
	    p = NULL;
	    break;
	default:
	    break;
	}
    }

    return 0;
}
