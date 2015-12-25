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

	char first[MAX_READ];//first用来存放文件数据
	memset(first,0,sizeof(char)*MAX_READ);
	printf("正在读取 %s ...\n",name);

	for (i=0; (!feof(fp))&&i<MAX_READ; i++) {

		if(fread(first+i, sizeof(char), 1, fp)!=1) {
            printf("共计读取%d个字符\n",i+1);
		}
	}
	fclose(fp);
	


/****************************************************************/


	FILE * second; //second用来存放源代码

	quit = 1;
	char name_1[70];
	memset(name_1,0,sizeof(char)*70);

	while (quit) {

		printf("请输入要存放源代码的文件名...默认后缀: *.cpp\n");
		scanf("%50s",name_1);
		
		printf("您输入的是: ");
		j=printf("%s",name_1);
		printf("\n");
		if(j==0) {
			printf("输入为空,请重新输入!\n");
			continue;
		}
		for(i=0;i<j;i++)
			if(name_1[i]=='.')
				break;
		if(i==j)
			strcpy(&name_1[i],".cpp");
		
		if ((second = fopen(name_1, "w")) == NULL) {

			printf("文件 %s 创建或读取文件失败\n请检查当前用户权限!\n",name_1);
			exit(-2);
		}
		
		quit=0;
		
	}


/****************************************************************/



	FILE * third; //third用来存放注释部分

	quit=1;
	char name_2[70];
	memset(name_2,0,sizeof(char)*70);

	while (quit) {

	printf("请输入要存放注释的文件名...默认后缀: *.txt\n");
	scanf("%50s",name_2);
	
		printf("您输入的是: ");
		j=printf("%s",name_2);
		printf("\n");
		if(j==0) {
			printf("输入为空,请重新输入!\n");
			continue;
		}
		for(i=0;i<j;i++)
			if(name_2[i]=='.')
				break;
		if(i==j)
			strcpy(&name_2[i],".txt");
		
		if ((third = fopen(name_2, "w")) == NULL) {

			printf("文件 %s 创建或读取文件失败\n请检查当前用户权限!\n",name_2);
			exit(-2);
		}

		quit=0;
	
	}
	

/****************************************************************/


	//开始输出源代码到name_1.cpp
	
	int sign = 0;
	int count = 0;
	char * p = NULL;
	char * q = NULL;
	p = first;
	q = first+1;

	while (*p!='\0') {

		if (*p=='/'&&*q=='/') {

			for(;;p++,q++,count++) {

				//fwrite(p,sizeof(char),1,third);
				fputc(*p,third);
				if(*p=='\n'||*p=='\0')
					break;

			}

		} else if (*p=='/'&&*q=='*') {

			for(;*p!='\0';p++,q++,count++) {

				fputc(*p,third);

				if(*p=='*'&&*q=='/') {

					//fwrite(p,sizeof(char),1,third);
					//fwrite(q,sizeof(char),1,third);
					fputc(*q,third);
					fputc('\n',third);
					p++;
					q=p+1;
					break;
				}

			}
			
		} else
			//fprintf(second,"%c",p);
			fputc(*p,second);

		p++;
		q++;
	}



	fclose(second);
	fclose(third);

	return 0;
}