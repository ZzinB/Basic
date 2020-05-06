#include <stdio.h>
#include <string.h>
#include "manager.h"

int main(void){
	Classes clist[30]; //class list
	int curcount=0;
	int count=0, menu;
	
	//count = loadData(clist);
	curcount=count;

	while(1){
		menu=selectMenu();
		fflush(stdin);
		if(menu==0) break;
		else if(menu==1){
			readClass(&clist[0]);
		}
		else if(menu==2){
			getchar();
			count+=addClass(&clist[curcount++]);
		}
		else if(menu==3){
			getchar();
			updateClass(&clist[count-1]);
			
		}
		else if(menu==4) printf("delete\n");
		else if(menu==5) printf("save\n");
		else if(menu==6) printf("search\n");
	}
	return 0;
}
