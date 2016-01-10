//user.cpp created time 2016-1-9 17:57:32

#include "all.h"

void user() {

	system("mode con cols=34 lines=22");
	system("color 3A");

	int i;
	struct user * head = NULL;
	head=read_user();
	struct user * temp = NULL;

	char get_1[10],get_2[10];
	for(i=0;i<3;i++) {
		system("cls");
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
		printf("           学生登录界面\n\n");
		printf("     -------------------------\n");
		printf("     | 学号: |               |\n");
		printf("     -------------------------\n");
		printf("\n");
		printf("     -------------------------\n");
		printf("     | 密码: |               |\n");
		printf("     -------------------------\n");
		printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		fflush(stdin);
		goto_pos(16,7);
		scanf("%20s",get_1);
		fflush(stdin);
		goto_pos(16,11);
		scanf("%20s",get_2);

		temp=head;
		while(temp!=NULL){
			if(strcmp(temp->no,get_1)==0&&strcmp(temp->password,get_2)==0){
				goto_pos(11,17);
				printf("登录成功!");
				Sleep(800);
				user_login(head,temp);
				//->登录成功后进入user_login函数
				return ;
			}else
				temp=temp->next;
		}
		goto_pos(11,17);
		printf("密码错误\n    请重新输入 (剩余次数:%d)",2-i);
		Sleep(1300);
	}
	exit(-1);
}

void user_login(struct user * head,struct user * node) {
		
	int a;
	time_t in,out;
	in=time(NULL);
	system("color 07");
	while (1) {

		system("mode con cols=70 lines=22");
		a = move_1(5,menuPrint_7);

		switch (a) {
			case 1:exam(node);continue;
			case 2:execrise(node);continue;
			case 3:
				system("cls");
				print_user_solo(node);
				system("pause");
				continue;
			case 4:
				system("cls");
				print_user_solo(node);
				change_user(node);
				system("pause");
				continue;
			case 0:
			default:break;
		}
		break;
	}
	out=time(NULL);
	node->timeOnline+=(out-in);
	write_user(head);
	free_user(head);  //save
}

/*

 *******************************************************

               单项选择题标准化考试系统      
 
       欢迎您,
                                             -------------------
             -------------------          | 1 开始考试  |
             | 2 开始练习  |          -------------------
             -------------------
                              --------------------
                              | 3  查看信息  |
                              --------------------
                --------------------
                | 4  修改密码  |
                --------------------          --------------------
                                                  | 0  退出登录  |
                                                  --------------------
  2016-1-9 coded by Reigning...
*/

void menuPrint_7(int a) {

	system("cls");
	
	char name[15]={"menu_7.txt"};

	
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
		case 1:printRectangle(42,6);break;
		case 2:printRectangle(13,7);break;
		case 3:printRectangle(30,10);break;
		case 4:printRectangle(16,13);break;
		case 0:printRectangle(50,15);break;
		default:break;
	}
	
}

void printRectangle(int x, int y) {

	color(14);
	goto_pos(x,y);
	printf("---------------");
	goto_pos(x,y+1);
	printf("|");
	goto_pos(x+14,y+1);
	printf("|");
	goto_pos(x,y+2);
	printf("---------------");
	goto_pos(x+2,y+1);
	color(7);

}

/*颜色对应值： 
　　0=黑色                8=灰色　　
  　 1=蓝色                9=淡蓝色                　　                        
　　2=绿色                10=淡绿色       0xa        　　
　　3=湖蓝色          11=淡浅绿色        0xb　
　　4=红色                12=淡红色        0xc　　
　　5=紫色                13=淡紫色        0xd        　　
　　6=黄色                14=淡黄色        0xe        　　
　　7=白色                15=亮白色        0xf 
　　也可以吧这些值设置成常量。
*/
void color(const unsigned short color1)
{        
	/*仅限改变0-15的颜色;如果在0-15那么实现他的颜色   因为如果超过15后面的改变的是文本背景色。*/
    if(color1>=0&&color1<=15)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    /*如果不在0-15的范围颜色，那么改为默认的颜色白色；*/
    else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}


void exam(struct user * node) {

	int key,num,a,b=strlen(node->name);
	int i=0,lever=100,right=0;
	float score=0;
	time_t begin,temp,end;
	char ch[20];

	FILE *fp = NULL;
	char n[40];
	strcpy(n,node->name);
	for(a=0;a<b;a++)
		if(n[a]=='.')
			break;
	if(a==b)
		strcpy(&n[b],".txt");
		
	fp=fopen(n,"a+");
	if(fp==NULL) {
		printf("cannot attach %s\n",n);
		exit (0);
	}

	system("mode con cols=80 lines=300");
	printf("---------考试---------\n");
	printf("请输入题目数量: ");
	fflush(stdin);
	scanf("%d",&num);
	printf("请输入考试内容(如基础,拔高,数组,指针.无要求请直接按@+回车): ");
	fflush(stdin);
	scanf("%20s",ch);

	struct info * head = read_info();
	struct info * p = head->next;

	printf("考生须知:在作答过程中,按 0 放弃作答当前题目,按Esc则放弃剩余所有题目并交卷!\n");
	printf("按任意键考试开始!\n");
	
	node->examTime++;//用户考试次数++
	begin=time(NULL);
	key=getch();
	if(key==0||key==224||key==-32)
		key=getch();
	//开始
	while(i<num)
	{
		if(p==NULL){
			i=-1;
			break;
		}
		if(isQusetion(p,ch))
		{
			temp=time(NULL);
			printf("\n---------当前分数:%g 分---经过时间:%ld 秒------\n",score,temp-begin);
			printf("\n---第%d题:",i+1);
			printf("\n statement:\n\t%s\n\n",p->statement);
			printf(" A:%s\t",p->options[0]);
			printf(" B:%s\n",p->options[1]);
			printf(" C:%s\t",p->options[2]);
			printf(" D:%s\n",p->options[3]);
			fprint_info_solo(fp,p);
			printf("***请作答: ");
			fprintf(fp,"%s","我的答案是: ");
			fflush(stdin);
			key=getch();
			if(key==0||key==224||key==-32)
				key=getch();
			else if(key>=97&&key<=100){
				printf(" %c ",'A'+key-97);
				fprintf(fp," %c \n",'A'+key-97);
				if((key-97)==p->rightAnswer){
					right++;
					node->examRight[node->examTime-1][0]++;//用户考试正确数目
					score+=(float)(100.0/num);
					printf("答案正确!\n");
				}else{
					node->errorHistory[errorsNum(node)]=p->no;
					node->examRight[node->examTime-1][1]++;//用户考试错误数目
					answerWrong(node,p);
					printf("答案错误!\n");
				}
			}else if(key==27)
				break;//结算
			else{
				node->errorHistory[errorsNum(node)]=p->no;
				node->examRight[node->examTime-1][1]++;//用户考试错误数目
				printf("答案错误!\n");
			}
			i++;
			node->exam++;//用户考试题数目++
		}
		p=p->next;
	}//while
	if(i==-1)
		printf("当前题库数量有限,敬请谅解\n");
	else{
		end=time(NULL);
		printf("考试完成!\n");
		printf("你的分数是:%g\n",score);
		node->examScore[node->examTime-1]=score;//用户考试每次考试分数
		printf("你答对题目%d道,正确率为%g%%\n",right,right*100.0/num);
		node->examRight[node->examTime-1][0]=right;//用户考试正确数目
		node->examRight[node->examTime-1][1]=num-right;//用户考试错误数目
		printf("总计用时间 %ld minutes %ld seconds",(end-begin)/60,(end-begin)%60);
	}
	printf("\n");
	system("pause");
}

int isQusetion(struct info * node,char *p) {

	int i;
	if(strcmp(p,"基础")==0)
		if(node->lever>=5)
			return 0;
	else if(strcmp(p,"拔高")==0)
		if(node->lever<=5)
			return 0;
	else if(*p!='@')
	{
		for(i=0;i<4;i++)
			if(fuzzy_search(node->keyWords[i],p)==1)
				return 1;
		return 0;
	}
	else
		if(rand()%2==0)
			return 0;
	return 1;
}

int errorsNum(struct user * node) {
	int i,sum=0;
	for(i=0;i<300;i++)
		sum+=node->examRight[i][1];
	return node->exercise-node->exerciseRight+sum;
}

void answerWrong(struct user * node,struct info * temp) {

	int i,j,max;
	for(i=0;i<300;i++)
		if(node->error[i][0]=='\0'){
			max=i+1;
			break;
		}
	for(i=0;i<5;i++)
	{
		if(temp->keyWords[i][0]!='@'&&temp->keyWords[i][0]!='\0') {

			for(j=0;j<max;j++) {
				if(strcmp(node->error[j],temp->answers[i])==0) {
					node->errorTime[j]++;
					break;
				}
			}

			if(j==max) {
				strcpy(node->error[max-1],temp->keyWords[i]);
				node->errorTime[max-1]++;
			}

		}else
			break;
	}//for
}

void execrise(struct user * node) {

	int key;
	int i=0,lever=100,right=0,a=1;
	float score=0;
	char ch[20];

	system("mode con cols=80 lines=300");
	printf("---------练习---------\n");
	printf("请输入练习内容(如基础,拔高,数组,指针.无要求请直接按@+回车): ");
	fflush(stdin);
	scanf("%20s",ch);

	struct info * head = read_info();
	struct info * p = head->next;

	printf("练习提升:在作答过程中,按 0 放弃作答当前题目并查看当前题目答案,按Esc则返回主菜单!\n");
	printf("按任意键练习开始!\n");
	
	node->exerciseTime++;//用户练习次数++
	key=getch();
	if(key==0||key==224||key==-32)
		key=getch();
	//开始
	while(a)
	{
		if(p==NULL){
			a=-1;
			break;
		}
		if(isQusetion(p,ch))
		{
			printf("\n---第%d题---:",i+1);
			printf("\n statement:\n\t%s\n\n",p->statement);
			printf(" A:%s\t",p->options[0]);
			printf(" B:%s\n",p->options[1]);
			printf(" C:%s\t",p->options[2]);
			printf(" D:%s\n",p->options[3]);
			printf("***请作答: ");
			fflush(stdin);
			key=getch();
			if(key==0||key==224||key==-32)
				key=getch();
			else if(key>=97&&key<=100){
				printf(" %c ",'A'+key-97);
				if((key-97)==p->rightAnswer){
					node->exerciseRight++;
					printf("答案正确!\n");
				}else{
					answerWrong(node,p);
					printf("答案错误!\n");
					printf(" %c right,because %s\n",'A'+p->rightAnswer,p->answers[p->rightAnswer]);
					for(i=0;i<4;i++) {
						if(i==p->rightAnswer)
							continue;
						printf(" %c wrong,because %s\n",'A'+i,p->answers[i]);
					}
				}
			}else if(key==27)
				break;//结算
			else
				printf("输入有误\n");
			i++;
			node->exercise++;//用户考试题数目++
		}
		p=p->next;
	}//while
	if(a==-1)
		printf("当前题库数量有限,敬请谅解\n");
	else
		printf("总计练习%d道题~,继续努力");
	printf("\n");
	system("pause");
}