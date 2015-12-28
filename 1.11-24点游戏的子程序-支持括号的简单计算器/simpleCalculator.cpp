#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char op[4]={'+','-','*','/'};

float calc(float n1, float n2, char o) {

    switch(o) {
        case '+': return (n1+n2);
        case '-': return (n1-n2);
        case '*': return (n1*n2);
        case '/': 
			if(n2==0) {
				//printf("除数不能为0哦亲");
				return -30000;
			}else
				return (n1/n2);
		default: exit(-1);
    }
}

//(3+5)*(2+4)



float sum(char *p,float last) {

	float result=0;
	float a=0,b=0;
	char *q=NULL;

	while(*p!='\0'&&*p!='=') {
		if(*p=='(')
			result+=sum(p+1,0);
		a=result+(float)atof(p);
		while( (*p>='0'&&*p<='9')||*p=='.')
			p++;
		b=(float)atof(p);
		result+=calc(result+a,b,*p);

		return sum(p+1,result);
	}
	return result;
}
//(4+6)*9+5

int main() {

	char equations[30];
	memset(equations,0,sizeof(char));
	scanf("%30s",equations);

	printf("%g",sum(equations,0));
	//fail
	return 0;
}