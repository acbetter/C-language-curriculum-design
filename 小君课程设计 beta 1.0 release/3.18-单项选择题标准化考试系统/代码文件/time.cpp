//time.cpp created time 2016-1-6 14:02:55

#include "all.h"

void print_time(long lt) {
	struct tm *t;
	t=localtime(&lt);
	printf("%4dÄê%02dÔÂ%02dÈÕ %02d:%02d:%02d\n",t->tm_year+1900,t->tm_mon+1,t->tm_mday,t->tm_hour,t->tm_min,t->tm_sec);
}

