#include "Struct.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Cola * col = new Cola();
	col->push(1);
	col->push(2);
	col->push(3);
	col->push(4);
	col->push(5);
	col->print();
	
	return 0;
}
