#include <stdio.h>
#include <conio.h>
int main(void) 
{
	printf("\n\t\t\t死循环,退出时请直接叉掉\n\n\t\t\t\t");
	int key=0;
	while (1) {
		key=getch();
		printf("%d\n\t\t\t\t",key);
	}
	return 0;
}