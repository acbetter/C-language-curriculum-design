#include <time.h>
#include <stdio.h>

void print_time(long lt) {
	struct tm *t;
	t=localtime(&lt);
	printf("%4dÄê%02dÔÂ%02dÈÕ %02d:%02d:%02d\n",t->tm_year+1900,t->tm_mon+1,t->tm_mday,t->tm_hour,t->tm_min,t->tm_sec);
}

int main(void) {

	time_t lt;
	//time_t nowtime;
	lt =time(NULL);
	//printf("The Calendar Time now is %d,nowtime is %d\n",lt,nowtime);

	print_time(lt);
	return 0;
}


