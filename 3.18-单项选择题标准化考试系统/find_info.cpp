//find_info.cpp created time 2016-1-6 14:33:22

#include "all.h"

void find_info() {

	int a;
		
	while (1) {

		system("mode con cols=57 lines=20");
		system("color 47");

		a = move_1(3,menuPrint_4);
		switch (a) {
			//1.
			case 1:;continue;
			case 2:;continue;
			case 3:;continue;
			case 4:;continue;
			case 5:;continue;
			case 6:;continue;
			case 0:
			default:break;
		}
		break;
	}

}

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

	char key[20]={'0'};
	printf(" 请输入关键字:\n");
	printf(" 正在查找...\n");
	while(head!=NULL);//

	return head;
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