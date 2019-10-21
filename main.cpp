#include <iostream>
#include "Driver.h"



int main(){
	Driver * driver = new Driver;
	driver->run();
	delete driver;
	return 0;
}
