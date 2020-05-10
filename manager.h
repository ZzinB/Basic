#include "class.h"

int selectMenu();	//메뉴함수
void listSubject(Classes *c, int count);	//리스트출력함수
int selectDataNo(Classes *c, int count);	//숫자선택함수

void saveData(Classes *c, int count);	//파일저장함수
int loadData(Classes *c);	//파일로드함수

void Calculation(Classes *c, int count);	//학점계산함수
void ReadDayList(Classes *c, int count);	//요일별과목리스트함수
void SearchSameTime(Classes *c, int count);	//겹치는시간과목찾는함수
