/*
2.4-xxx 高级语言源程序注释部分的处理（难度系数：4级）
【任务描述】
将C语言程序中的所有注释都去掉，并将去掉注释的文件和注释分别放入一个新的文件中。

【功能描述】
（1）读取用户指定名字的源程序，例如，用户输入：exercise.cpp，程序能读取该文件进行处理。
（2）将文件中的注释
（3）将去掉的注释部分和删除注释后的C语言程序，分别保存到两个不同的文件中，文件名允许用户指定。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_READ 30000

int main(void) {
	
	printf("高级语言源程序注释部分的处理\n");

	FILE * fp;

	int i,j;
	int quit = 1;
	char ch;
	char name[70];
	memset(name,0,sizeof(char)*70);
	
	while (quit) {

		printf("请输入文件名称...默认后缀: *.cpp\n");
		scanf("%50s",name);
		
		printf("您输入的是: ");
		j=printf("%s",name);
		printf("\n");
		if(j==0) {
			printf("输入为空,请重新输入!\n");
			continue;
		}
		for(i=0;i<j;i++)
			if(name[i]=='.')
				break;
		if(i==j)
			strcpy(&name[i],".cpp");
		
		if ((fp = fopen(name, "r")) == NULL) {

			printf("文件没有找到 %s ,读取文件失败\n",name);
			printf("是否重新输入文件名? y/n ? ");
			fflush(stdin);
			if( (ch=getchar())==124)
				continue;
			else
				quit=0;
		}
		
		quit = 0; //读取成功了...下次不再进行死循环
	}

	char first[MAX_READ];
	printf("正在读取 %s ...\n",name);

	for (i=0; (!feof(fp))&&i<MAX_READ; i++) {

		if(fread(first, sizeof(char), 1, fp)!=1) {
            printf("共计读取%d个字符\n",i+1);
		}
	}
	fclose(fp);
	
	FILE * second; //second用来存放源代码

	printf("请输入要存放源代码的文件名...默认后缀: *.cpp\n");

	if ((fp = fopen(, "w")) == NULL) {

			printf("文件没有找到 %s ,读取文件失败\n",name);
			printf("是否重新输入文件名? y/n ? ");
			fflush(stdin);
			if( (ch=getchar())==124)
				continue;
			else
				quit=0;
		}




	return 0;
}