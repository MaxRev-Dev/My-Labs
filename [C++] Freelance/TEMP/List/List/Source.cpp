#include <iostream>
#include <stdio.h>

using namespace std;

typedef int  ELEMT;
typedef struct list {
	ELEMT element;
	struct list *next;
}DLIST;

ELEMT insertFirst(DLIST **ppH, ELEMT nELEM) {
	DLIST temp;
	temp.element = nELEM;
	temp.next = ppH[0];	
	ppH[0] = &temp;
	
	return ppH[0][0].element;
}
int main() {
	ELEMT l1 = 3;
	DLIST **ppH=new DLIST*[1];
	ppH[0] = new DLIST;
	ppH[0]->element = l1;
	ppH[0]->next = NULL;
	ELEMT el = 1;
	
ppH[0]->element=	insertFirst(ppH, el);
	printf("%d %d\n", ppH[0]->element, ppH[0]->next->element);
	system("pause");
	return 0;
}