#include "class.h"

int selectMenu();	//메뉴함수
void listSubject(Classes *c, int count);	//리스트출력함수
int selectDataNo(Classes *c, int count);	//숫자선택함수
void saveData(Classes *c, int count);	//파일저장함수
int loadData(Classes *c);	//파일로드함수
void Read(Classes *c, int count); //조회를 총괄하는 함수
void  Search_control(Classes *c, int count); // 검색을 총괄하는 함수
void Calculation(Classes *c, int count);	//학점계산함수
void ReadDayList(Classes *c, int count);	//요일별검색함수
void SearchSameTime(Classes *c, int count);	//겹치는시간과목찾는함수
void SearchProf(Classes *c, int count);		//교수님이름검색함수
void SearchSubject(Classes *c, int count);	//과목이름검색함수
void ListSubjectType(Classes *c, int count);//교양/전공검색함수
