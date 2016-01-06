//find_info_next.cpp created time 2016-1-6 22:47:45

#include "all.h"

void find_info_next() {
		
	int a;
	struct info * head = NULL;
	head=read_info();

	while (1) {

		system("mode con cols=57 lines=20");
		system("color 3F");

		a = move_1(6,menuPrint_3);
		switch (a) {
			//1.
			case 1:find_info(head);continue;
			case 2:input_info(head);continue;
			case 3:;continue;
			case 4:;continue;
			case 5:print_info(head);continue;
			case 6:;continue;
			case 0:
			default:break;
		}
		break;
	}
	write_info(head);
	free_info(head);  //save
}
