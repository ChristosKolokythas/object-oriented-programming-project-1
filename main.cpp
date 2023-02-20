#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "classes.h"

using namespace std;

int main() {
	Queue queue;
	Teacher *teacher;
	unsigned int teachersnum, parentsnum,i,L,rest,tmp,j;

	/* initialize random seed: */
	srand(time(NULL));

	cout << "Give the number of teachers" << endl;
	cin >> teachersnum;
	cout << "Give number of parents" << endl;
	cin >> parentsnum;
	teacher = new Teacher[teachersnum];

	for (i = 0; i < teachersnum; i++) { //creates teachers
		teacher[i].setnum(i);
		teacher[i].setbusy(0);
	}

	L = rand() % parentsnum + 1;
	rest = parentsnum - L;

	for (i = 1; i <= L; i++) { //creates queue until L
		queue.push(i,teachersnum);
	}

	while (queue.queueEmpty() != 0){

		for (i = 0; i < teachersnum; i++) { //engages parents with teachers
			if (queue.returnNode(i)!= 0) {
				teacher[i].setparent(queue.pop(queue.returnNode(i)));
				cout << "a parent finds teacher "<< i+1 << endl;
			}
		}

		if (rest > 0) { //adds the rest of parents
			tmp = rand() % rest + 1;

			for (i = 1; i <= tmp; i++) {
				queue.push(i + parentsnum-rest, teachersnum);
			}
			rest = rest - tmp;
		}
		
		for (i = 0; i < teachersnum; i++) { //parents done with teachers
			if (teacher[i].getparent() != NULL) {
				(teacher[i].getparent())->parent->setArray(i, 0);

				if (teacher[i].getparentarray(teachersnum) == 1) {
					queue.push2(teacher[i].getparent());
					
				}
			}	

			if (teacher[i].getparent() != NULL) {
				if (teacher[i].getparentarray(teachersnum) == 0)
					cout << "a parent left the briefing" << endl;
			}

				teacher[i].setparent(NULL);
		}

		j = queue.returnNode2(teachersnum);
		if (j != 0) { //if a parent was created with 000 array leaves
			queue.pop(j);
			cout << "a parent left the briefing" << endl;
		}
	}

	for (i = 0; i < teachersnum; i++) { //teacher destructor
		teacher[i].~Teacher();
	}
	cout << "done!!!" << endl;
	
}