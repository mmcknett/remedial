#include <iostream>

#include "vector.h"
#include "sort.h"
#include "tests.h"

using namespace rtl;

void WaitForKey()
{
	std::cout << "\nPress any key to continue..." << std::endl;
	std::cin.ignore();
}

int main(int argc, char **argv) {
	
	// Run vector tests
	//tests::VerboseLogging enableVerboseLogging;
	bool vectorTestsSucceeded = tests::RunVectorTests();

	if (vectorTestsSucceeded)
		std::cout << "vector<T> tests passed." << std::endl;
	else
		std::cout << "vector<T> tests failed." << std::endl;

	// Press any key to continue...
	WaitForKey();
	return 0;
}
