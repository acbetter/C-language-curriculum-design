//find_info.cpp created time 2016-1-6 14:33:22

#include "all.h"

struct info * find_info(struct info * head) {

	int a;
	struct info * find = NULL;
		
	while (1) {

		system("mode con cols=57 lines=20");
		system("color 47");

		a = move_1(3,menuPrint_4);
		system("cls");
		switch (a) {
			//1.
			case 1:find=find_info_key(head);break;
			case 2:find=find_info_no(head);break;
			case 3:find=find_info_lever(head);break;
			case 4:find=find_info_score(head);break;
			case 5:find=find_info_time(head);break;
			case 0:
			default:break;
		}
		if(find!=NULL)
			find_info_next(find);
		break;
	}
	return find;
}

/*
               查找试题界面       admin


               1.按关键字查找

               2.按题号查找     

               3.按难度查找

               4.按分值查找

               5.最近添加/修改   

               0.返回上一层
*/

void menuPrint_4(int a) {

	system("cls");
	char name[15]={"menu_4.txt"};

	
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

struct info * find_info_key(struct info * head) {

	int count=0,sign=0;
	struct info * node = head;
	struct info * find = NULL;
	char key[20];
	memset(key,0,sizeof(char)*20);

	system("cls");
	printf(" 请输入关键字:\n");
	fflush(stdin);
	scanf("%19s",key);
	printf(" 正在查找...\n");
	system("mode con cols=80 lines=1000");
	while(node->next!=NULL){
		if(fuzzy_search(node->next->statement,key)){
			print_info_solo(node->next);
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
		return find_info_no(head);
	else{
		printf(" 没有找到结果,正在返回上一级菜单...");
		Sleep(3000);
		return NULL;
	}
	return NULL;
}

int fuzzy_search(char str[] , char str2[]) {
	//char str[]为源字符串
	//char str2[]为查找的关键字
	char *res;
	res = (char *)memchr(str, str2[0], strlen(str));
	//根据要查找的字符串第一个字符，切割源字符串
	if (res == NULL)
		return 0;

	int n;
	while (1)
	{
		n = memcmp(res, str2, strlen(str2) - 1); //比较
		if (n != 0) {

			if (strlen(res) <= strlen(str2))  //切割出的字符串小于要查找字符串的长度
				return 0;
			else
			{  
				//根据要查找的第一个字符继续切割
				res = (char *)memchr(res + 1, str2[0], strlen(res));  
				if (res == NULL)
					return 0;
			}
		} else//如果n = 0，找到
			return 1;
	}
}

void delete_info_no(struct info * find) {

	int num;
	struct info * node = find->next;
	num=node->no;
	find->next=node->next;
	free(node);
	node=NULL;
	printf(" 删除题目%d成功!\n",num);
}

struct info * find_info_no(struct info * head) {

	int num;
	struct info * node = head;

	printf(" 请输入题号(输入0则退出):\n");
	scanf("%4d",&num);
	printf(" 正在定位...\n");
	system("mode con cols=80 lines=30");
	while(node->next!=NULL){
		if(node->next->no==num){
			print_info_solo(node->next);
			return node;
		}
		node=node->next;
	}
	return NULL;
}

void change_info(struct info * node) {

	int j;
	int s = 2;
	char ch,ch1;
	node=node->next;
	while (s!=0) {

		printf("\n 请输入相应的数字,按回车结束...\n");
		printf(" 1.lever -> 修改题目难度\n");
		printf(" 2.score -> 修改题目分数\n");
		printf(" 3.rightAnswer -> 修改题目正确答案\n");
		printf(" 4.options -> 修改题目选项\n");
		printf(" 5.answers -> 修改选项答案错误/正确原因\n");
		printf(" 6.statement -> 修改题目描述\n");

		printf(" 0.return -> 返回菜单\n\t\t");

		fflush(stdin);
		scanf("%d", &s);
		fflush(stdin);
		switch (s) {
			case 1:
				printf("请输入题目难度: ");
				scanf("%2d",&node->lever);
				break;
			case 2:
				printf("请输入题目分数: ");
				scanf("%2d",&node->score);
				break;
			case 3:
				printf("请输入题目正确答案: ");
				ch=getchar();
				node->rightAnswer=ch-'A';
				break;
			case 4:
				printf("请输入选项: ");
				ch=getchar(); 
				fflush(stdin);
				printf("您输入的选项是%c,请输入新的内容:",ch);
				for(j=0;j<100;j++) {
					ch1=getchar();
					if(ch1!='\n')
						node->options[ch-'A'][j]=ch1;
					else
						break;
				}
				break;
			case 5:
				printf("请输入选项: ");
				ch=getchar(); 
				fflush(stdin);
				printf("您输入的选项是%c,请输入新的正确/错误原因:",ch);
				for(j=0;j<300;j++) {
					ch1=getchar();
					if(ch1!='\n')
						node->answers[ch-'A'][j]=ch1;
					else
						break;
				}
				break;
			case 6:
				printf("请输入题目描述: ");
				for(j=0;j<1000;j++) {
					ch=getchar();
					if(ch!='\n')
						node->statement[j]=ch;
					else
						break;
				}
				break;
			default:break;
		}

		node->timeModify=time(NULL);
		print_info_solo(node);

	}
}


void find_info_next(struct info * node) {

	int s = 2;
	while (s!=0) {

		printf("\n 请输入相应的数字,按回车结束...\n");
		printf(" 1.change -> 修改\n");
		printf(" 2.delete -> 删除\n");
		printf(" 0.return -> 返回菜单\n\t\t");

		fflush(stdin);
		scanf("%d", &s);
		switch (s) {
			case 1:change_info(node); break;
			case 2:delete_info_no(node); break;
			default:break;
		}
	}
}


struct info * find_info_lever(struct info * head) {

	int count=0,sign=0;
	struct info * node = head;
	struct info * find = NULL;
	int lev;

	system("cls");
	printf(" 请输入题目难度:\n");
	fflush(stdin);
	scanf("%2d",&lev);
	printf(" 正在查找...\n");
	system("mode con cols=80 lines=1000");
	while(node->next!=NULL){
		if(node->next->lever==lev){
			print_info_solo(node->next);
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
		return find_info_no(head);
	else{
		printf(" 没有找到结果,正在返回上一级菜单...");
		Sleep(3000);
		return NULL;
	}
	return NULL;
}


struct info * find_info_score(struct info * head) {

	int count=0,sign=0;
	struct info * node = head;
	struct info * find = NULL;
	int lev;

	system("cls");
	printf(" 请输入题目难度:\n");
	fflush(stdin);
	scanf("%2d",&lev);
	printf(" 正在查找...\n");
	system("mode con cols=80 lines=1000");
	while(node->next!=NULL){
		if(node->next->score==lev){
			print_info_solo(node->next);
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
		return find_info_no(head);
	else{
		printf(" 没有找到结果,正在返回上一级菜单...");
		Sleep(3000);
		return NULL;
	}
	return NULL;
}

struct info * find_info_time(struct info * head) {

	int count=0,sign=0;
	struct info * node = head;
	struct info * find = NULL;

	system("cls");
	printf(" 正在查找...\n");
	system("mode con cols=80 lines=1000");
	while(node->next!=NULL){
		if( (time(NULL)-node->next->timeModify)<=250942){
			print_info_solo(node->next);
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
		return find_info_no(head);
	else{
		printf(" 没有找到结果,正在返回上一级菜单...");
		Sleep(3000);
		return NULL;
	}
	return NULL;
}
