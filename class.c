#include "class.h"

int addClass(Classes *c){

	printf("\n");
	printf("과목명은? ");
	scanf("%[^\n]s",c->name);
	getchar();
	printf("교수님 성함은? ");
	scanf("%[^\n]s",c->prof);
	getchar();
	printf("분반은? ");
	scanf("%d",&c->class_no);
	getchar();
	printf("수업 요일은? ");
	scanf("%[^\n]s",c->day);
	getchar();
	printf("수업 교시는? ");
	scanf("%d",&c->time);
	getchar();
	printf("==> 추가\n");
	return 1;
}

void  readClass(Classes *c){
	printf("%4s %4s %3d %3s %3d\n",c->name, c->prof, c->class_no, c->day, c->time); 
}

int updateClass(Classes *c){

	printf("\n");
	printf("과목명은? ");
	scanf("%[^\n]s",c->name);
	getchar();
	printf("교수님 성함은? ");
	scanf("%[^\n]s",c->prof);
	getchar();
	printf("분반은? ");
	scanf("%d",&c->class_no);
	getchar();
	printf("수업 요일은? ");
	scanf("%[^\n]s",c->day);
	getchar();
	printf("수업 교시는? ");
	scanf("%d",&c->time);
	getchar();
	printf("==> 수정됨\n");
	return 1;
}
