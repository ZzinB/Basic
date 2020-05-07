#include "manager.h"

int selectMenu(){
	int menu;
	printf("\n** 예비시간표관리**\n");
	printf("1. 시간표조회\n");
	printf("2. 과목추가\n");
	printf("3. 과목수정\n");
	printf("4. 과목삭제\n");
	printf("5. 파일저장\n");
	printf("6. 과목검색\n");
	printf("0. 종료\n");
	scanf("%d", &menu);
	return menu;
}

void listSubject(Classes *c, int count){
//class는 교시, Day는 요일, Section은 분반
	printf("\nNo.  Subject   Professor   Class  Day  Section\n");	 
	printf("==================================================\n");
	for(int i=0 ; i<count ; i++){
		if(c[i].time == -1 || c[i].class_no == -1) continue;
		printf("%2d.", i+1);
		readClass(&c[i]);
	}
	printf("\n");
}

int selectDataNo(Classes *c, int count){
	int no;
	listSubject(c, count);
	printf("번호는(취소:0)?");
	scanf("%d", &no);
	getchar();
	return no;
}

void saveData(Classes *c, int count){
	FILE* fp;
	fp = fopen("Classes.txt", "wt");
	for(int i=0 ; i<count ; i++){
			fprintf(fp, "%3d %10s %3d %10s %10s\n", c[i].class_no, c[i].day, c[i].time, c[i].prof, c[i].name);
	}
	fclose(fp);
	printf("저장됨\n");
}

int loadData(Classes *c){
	int count = 0;
	FILE* fp;

	fp = fopen("Classes.txt", "rt");
	if(fp == NULL){
		printf("파일없음\n");
		return 0;
	}
	for(;;count++){
		fscanf(fp, "%3d %10s %3d %10s %[^\n]s\n",&c[count].class_no, c[count].day, &c[count].time, c[count].prof, c[count].name ); 
		if(feof(fp)) break;
	}
	fclose(fp);
	printf("=> 로딩성공!\n");
	return count;
}
