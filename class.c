#include "class.h"

int addClass(Classes *c){
	printf("\n");
	printf("과목명은? ");
	scanf("%[^/n]s",c->name);

	printf("교수님 성함은? ");
	scanf("%[^/n]s",c->prof);

	printf("분반은? ");
	scanf("%d",&c->class_no);

	printf("수업 요일은? ");
	scanf("%[^/n]s",c->day);

	printf("수업 교시는? ");
	scanf("%d",&c->time);

	printf("==> 추가\n");
	return 1;
}
