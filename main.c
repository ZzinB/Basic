#include <stdio.h>
#include <string.h>
#include "class.h"

int main(void){
	Classes clist[30]; //class list
	int curcount=0;
	int count=0, menu;
	
	//count = loadData(clist);
	curcount=count;

	while(1){
		printf("메뉴 선택");
		scanf("%d",&menu);
		fflush(stdin);
		if(menu==0) break;
		else if(menu==1) printf("add class\n");
		else if(menu==3) printf("update\n");
		else if(menu==4) printf("delete\n");
		else if(menu==5) printf("save\n");
		else if(menu==6) printf("search\n");
	}
	return 0;
}
