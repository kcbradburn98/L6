#include <iostream>
#include "Driver.h"



int main(){
	// Driver * driver;
	// driver->run();
	// return 0;
	Heap* myHeap = new Heap;
	myHeap->insert(18);
	myHeap->insert(5);
	myHeap->insert(3);
	myHeap->insert(8);
	myHeap->insert(15);
	myHeap->insert(25);
	myHeap->remove(25);
	myHeap->remove(3);
	myHeap->remove(18);
	myHeap->levelOrder();
	
}
