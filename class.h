#include <stdio.h>
#include <string.h>

typedef struct{
	char name[20]; //과목명
	char prof[10]; //교수님
	int class_no; //분반
	char day[5]; // 수업 요일
	int time; //교시
	int kind; //전공(1) 교양(2)
	float credit; //학점
} Classes;
//CRUD
int addClass(Classes *c);
void readClass(Classes *c);
int updateClass(Classes *c);
int deleteClass(Classes *c);
//Search
void SearchProf(Classes *c, int count);
void SearcjSubject(Classes *c, int count);
