#include "manager.h"

int selectDataNo(Classes *c, int count){
	int no;
//list보여주는코드
	printf("번호는(취소:0)?");
	scanf("%d", &no);
	getchar();
	return no;
}
