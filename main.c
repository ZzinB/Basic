#include <stdio.h>
#include <string.h>
#include "manager.h"

int main(void){
	Classes clist[30]; //class list
	int curcount=0;
	int count=0, menu;
	
	count = loadData(clist);
	curcount=count;

	while(1){
		menu=selectMenu();
		fflush(stdin);
		if(menu==0) break;
		if(menu == 1 || menu == 3 || menu == 4){
			if(count == 0){
			printf("데이터가 없습니다\n");
			continue;
			}
		}
		if(menu==1){
			listSubject(clist,curcount);
		}
		else if(menu==2){
			getchar();
			count+=addClass(&clist[curcount++]);
		}
		else if(menu==3){
			getchar();
			int no=selectDataNo(clist, curcount);
			if(no==0){
				printf("==> 취소됨!");
				continue;
			}
			updateClass(&clist[no-1]);
		}
		else if(menu==4){
			getchar();
			int no=selectDataNo(clist, curcount);
			if(no==0){
				printf("==> 취소됨!");
				continue;
			}
			int deleteok;
			printf("정말로 삭제하시겠습니까?(삭제: 1) ");
			scanf("%d",&deleteok);
			if(deleteok==1){
				if(deleteClass(&clist[no-1])) count--;
			}
		}
		else if(menu==5){
			if (count==0) printf("데이터가 없습니다!\n");
			else saveData(clist, curcount);
		}
		else if(menu==6) SearchSubject(clist, curcount);

		else if(menu==9) printf("특정 기능\n");

		else if(menu==7) ReadDayList(clist, curcount);
		else if(menu==8) Calculation(clist, curcount);
	}
	printf("종료됨!\n");
	return 0;
}
