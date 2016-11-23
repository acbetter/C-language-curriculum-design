//time.cpp created time 2016-1-6 14:02:55

#include "all.h"

void print_time(long lt) {
	struct tm *t;
	t=localtime(&lt);
	printf("%4d年%02d月%02d日 %02d:%02d:%02d\n",t->tm_year+1900,t->tm_mon+1,t->tm_mday,t->tm_hour,t->tm_min,t->tm_sec);
}

void sprint_time(char * buf) {
	struct tm *t;
	long lt=time(NULL);
	t=localtime(&lt);
	sprintf(buf,"_%4d-%02d-%02d_%02d-%02d-%02d",t->tm_year+1900,t->tm_mon+1,t->tm_mday,t->tm_hour,t->tm_min,t->tm_sec);
}