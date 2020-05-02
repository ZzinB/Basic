#include <stdio.h>
#include <string.h>

typedef struct{
	char name[20]; //과목명
	char prof[10]; //교수님
	int class_no; //분반
	char day[5]; // 수업 요일
	int itme; //교시
} Classes;
//CRUD
int addClass(Classes *c);
void readClass(Classes *c);
int updateClass(Classes *c);
int delteClass(Classes *c);
//Search
void SearchSubject(Classes *c, int count);
