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

void  readClass(Classes *c){
	printf("%4s %4s %3d %3s %3d\n",c->name, c->prof, c->class_no, c->day, c->time); 
}
