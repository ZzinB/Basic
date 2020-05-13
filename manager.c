#include "manager.h"

int selectMenu(){
	int menu;
	printf("\n** 예비시간표관리**\n");
	printf("1. 시간표조회\n");
	printf("2. 과목추가\n");
	printf("3. 과목수정\n");
	printf("4. 과목삭제\n");
	printf("5. 파일저장\n");
	printf("6. 검색 기능\n");
	printf("0. 종료\n\n");
	printf("=> 원하는 메뉴는? ");
	scanf("%d", &menu);
	printf("\n");
	return menu;
}

void listSubject(Classes *c, int count){
	printf("//class 교시, Day 요일, Section 분반, Kind 전공1/교양2, Credit 학점//\n");
	printf("\nNo.  Subject   Professor   Class  Day  Section  Kind  Credit\n");	 
	printf("==============================================================\n");
	for(int i=0 ; i<count ; i++){
		if(c[i].time == -1 || c[i].class_no == -1) continue;
		printf("%2d. ", i+1);
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
			fprintf(fp, "%3.1f %3d %3d %10s %3d %10s %10s\n",c[i].credit, c[i].kind, c[i].class_no, c[i].day, c[i].time, c[i].prof, c[i].name);
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
		fscanf(fp, "%f %3d %3d %10s %3d %10s %[^\n]s\n", &c[count].credit, &c[count].kind, &c[count].class_no, c[count].day, &c[count].time, c[count].prof, c[count].name ); 
		if(feof(fp)) break;
	}
	fclose(fp);
	printf("=> 로딩성공!\n");
	return count;
}

int Search_control(Classes *c, int count){
	int menu;
	printf("\n** 검색 기능**\n");
	printf("1. 과목이름 검색\n");
	printf("2. 요일별 검색\n");
	printf("3. 교수님 성함 검색\n");
	printf("4. 학점계산기\n");
	printf("5. 겹치는 시간 검색\n");
	printf("6. 전공/교양조회\n");
	printf("7. 뒤로가기\n\n");
	printf("=> 원하는 메뉴는? ");
	scanf("%d", &menu);
	printf("\n");
	getchar();

	if(menu==1) SearchSubject(c,count);
	else if(menu==2) ReadDayList(c,count);
	else if(menu==3) SearchProf(c, count);
	else if(menu==4) Calculation(c, count);
	else if(menu==5) SearchSameTime(c, count);
	else if(menu==6) ListSubjectType(c,count);
	else if(menu==7) return 0; 
	else printf("잘못 누르셨습니다!\n");
	printf("\n");
}

void SearchSubject(Classes *c, int count){
	int scount = 0;
	char search[20];

	printf("검색할과목명은? ");
	scanf(" %[^\n]s", search);
	Classes *s = c;

 	printf("\n Subject   Professor   Class  Day  Section  Kind  Credit\n");
    printf("===========================================================\n");
	for(int i=0 ; i<count ; i++){
		if(c[i].class_no != -1){
			if(strstr(c[i].name, search)){
				readClass(&c[i]);
				scount++;
			}
		}
	}
	if(scount == 0) printf("=>검색된 데이터 없음!");
	printf("\n");
}

void Calculation(Classes *c, int count){
	float sum = 0;
	float over = 0; 
	float more = 0;
	int choice;

	printf("선택할 수 있는 학점은?(21학점:1, 18학점:2, 15학점:3) ");
	scanf(" %d", &choice);
	printf("\n");

	for(int i=0 ; i<count ; i++){
		if(c[i].class_no != -1)
				sum += c[i].credit;
	}
	if(choice != 1 && choice !=2 && choice !=3)
		printf("=> 잘못입력하셨습니다!\n");
	if(choice == 1 || choice == 2 || choice == 3){
	if(choice == 1){
		if(sum <= 21)
			more = 21 - sum;
		else
			over = sum - 21;
	}
	if(choice == 2){
		if(sum <= 18)
			more = 18 - sum;
		else 
			over = sum - 18;
	}
	if(choice == 3){
		if(sum <= 15)
			more = 15 - sum;
		else 
			over = sum - 15;
	}
	printf("-총 학점 : %.1f,\n-남은학점 : %.1f,\n-초과 된 학점 : %.1f\n", sum, more, over);
	}
}
 

void ReadDayList(Classes *c, int count){
	int scount = 0;
	char search[20];

	int a[20];
	char b[20];

	printf("요일을 입력하세요.(월금:월, 화목:화, 수:수)");
	scanf("%s", search);

	printf("\nSubject   Professor   Class  Day  Section  Kind  Credit\n");

	printf("==========================================================\n");
	
	for(int i=0 ; i<count ; i++){
		if(c[i].class_no != -1){
			if(strstr(c[i].day,search)){
				readClass(&c[i]);
				scount++;
			}
		}
	} 

	if(scount == 0) printf("=>검색된 데이터 없음!\n");
	printf("\n");
}
void SearchProf(Classes *c, int count){
	int scount = 0;
	char search[20];

	printf("검색할 교수님 성함은? ");
	scanf(" %[^\n]s", search);


 	printf("\nSubject   Professor   Class  Day  Section  Kind  Credit\n ");

    printf("==========================================================\n");
	for(int i=0 ; i<count ; i++){
		if(c[i].class_no != -1){
			if(strstr(c[i].prof, search)){
				readClass(&c[i]);
				scount++;
			}
		}
	}
	if(scount == 0) printf("=>검색된 데이터 없음!");
	printf("\n");
}

void SearchSameTime(Classes *c, int count){
	Classes *s = c;
	int scount = 0;
	int n[20];	
	
	for(int i=0 ; i<count ; i++){
		for(int j = i+1 ; j<count ; j++){
			if((s[j].time == c[i].time) && (strcmp(s[j].day, c[i].day)==0)){
					printf("!! %s요일 %d교시 !!\n", s[j].day, s[j].time);
					scount++;
			}
		}	
	}
	printf("시간이 겹치는 과목은 총 %d개 입니다.\n", scount);
	if(scount == 0) printf("=>중복되는 데이터 없음!");
	printf("\n");
}

void ListSubjectType(Classes *c, int count){
	int scount = 0;
	printf("!!!전공 수업 리스트!!!");
 	printf("\nSubject   Professor   Class  Day  Section  Kind  Credit\n ");

    printf("==========================================================\n");
	for(int i=0 ; i<count ; i++){
		if(c[i].class_no != -1){
			if(c[i].kind==1){
				readClass(&c[i]);
				scount++;
			}
		}
	}
	if (scount==0) printf("==>검색된 데이터 없음!\n\n");
	scount=0;
	printf("!!!교양 수업 리스트!!!");
 	printf("\nSubject   Professor   Class  Day  Section  Kind  Credit\n ");

    printf("==========================================================\n");
	for (int i=0;i<count ; i++){
		if(c[i].class_no != -1){
			if(c[i].kind==2){
				readClass(&c[i]);
				scount++;
			}
		}
	} 
	if(scount == 0) printf("=>검색된 데이터 없음!");
	printf("\n");
}
