#include <time.h>
#include <stdio.h>

int main(void) {

	struct tm *ptr;
	time_t lt;
	time_t nowtime;
	lt =time(&nowtime);
	printf("The Calendar Time now is %d,nowtime is %d\n",lt,nowtime);
	return 0;
}