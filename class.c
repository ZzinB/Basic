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
	printf("수업 요일은(월~금 중 택 1)? ");
	scanf("%[^\n]s",c->day);
	getchar();
	printf("수업 교시는? ");
	scanf("%d",&c->time);
	getchar();
	printf("전공(1) / 교양(2)? ");
	scanf("%d",&c->kind);
	getchar();
	printf("학점은? ");
	scanf("%d",&c->credit);
	printf("==> 추가\n");
	return 1;
}

void  readClass(Classes *c){
	printf("%10s %10s %8d %10s %8d\n",c->name, c->prof, c->class_no, c->day, c->time); 
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
	printf("전공(1) / 교양(2)? ");
	scanf("%d",&c->kind);
	getchar();
	printf("학점은? ");
	scanf("%d",&c->credit);
	printf("==> 수정됨\n");
	return 1;
}

int deleteClass(Classes *c){
	c->class_no=-1;
	printf("==> 삭제됨!\n");
	return 1;
}

/*
void overlapClass(Classes *c, int count){
	int scount = 0;
	int overlap_list[10];
	printf("%d",
	printf("\nNo.  Subject   Professor   Class  Day  Section\n");
    printf("==================================================\n");
	for(int i=0 ; i<count ; i++){
		if(c[i].class_no != -1){
			if(strstr(c[i].name, search)){
				printf("%2d", i+1);
				readClass(&c[i]);
				scount++;
			}
		}
	}
	if(scount == 0) printf("=>검색된 데이터 없음!");
	printf("\n");

}*/
