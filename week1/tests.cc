// Implementation of RTL tests
#include <iostream>

#include "tests.h"
#include "vector.h"

namespace rtl
{
namespace tests
{



#define TESTINIT \
	bool success = true; \

#define CHK(x) \
	success = success && (x); \
	if (!success) return false; \

#define CHKS(x,s) \
	success = success && (x); \
	if (!success) \
	{ \
		std::cerr << s << std::endl; \
		return false; \
	} \

#define SUCCESSMSG(s) \
	if (success) \
		std::cerr << s << std::endl; \

#define TESTRETURN \
	return success; \


bool RunVectorTests()
{
	TESTINIT;

	CHK(VectorIntConstructorTest());
	CHK(VectorIntInsertTest());
	CHK(VectorPushPopTest());

	SUCCESSMSG("All tests completed successfully!");

	TESTRETURN;
}


bool VectorIntConstructorTest()
{
	TESTINIT;

	vector<int> dut0(5);
	CHKS(dut0.capacity() >= 5, "1 param constructor: The initializing constructor didn't create a vector with enough capacity.");

	vector<int> dut1(3u, 42);
	CHKS(dut1.capacity() >= 3, "2 param constructor: The initializing constructor didn't create a vector with enough capacity.");
	for (size_t i = 0; i < 3u; ++i)
		CHKS(dut1[i] == 42, "The initializing constructor didn't initialize the vector entries correctly.");

	vector<int> dut2(dut1);
	CHKS(dut2.size() == dut1.size(), "The copy constructor did not create vectors of the same size.");
	CHKS(dut2.capacity() == dut1.capacity(), "The copy constructor did not create vectors of the same capacity.");
	for (size_t i = 0; i < dut2.size(); ++i)
		CHK(dut2[i] == dut1[i]);

	// TODO: Iterator constructor

	SUCCESSMSG("The constructor tests for vector<int> completed successfully!");

	TESTRETURN;
}


bool VectorIntInsertTest()
{
	TESTINIT;

	int testints[] = {2, 3, 4, 1, 2};

	vector<int> dut(sizeof(testints));
	for (size_t i = 0; i < sizeof(testints); ++i)
		dut.push_back(testints[i]);

	CHKS(dut.size() == sizeof(testints), "The vector<int>::push_back function didn't increase the array to the right size.");
	for (size_t i = 0; i < sizeof(testints); ++i)
		CHKS(dut[i] == testints[i], "Copying by calling vector<int>::push_back left an incorrect element.");

	SUCCESSMSG("The insertion tests for vector<int> completed successfully!");

	TESTRETURN;
}


bool VectorPushPopTest()
{
	TESTINIT;

	vector<RefCounter> dut;
	{
		dut.push_back(RefCounter());
		dut.push_back(RefCounter());
	}

	CHKS(dut.size() == 2, "The vector has the wrong size.");
	CHKS(RefCounter::GetCount() == 2, "push_back did not do construction properly.  Count is " << RefCounter::GetCount());

	SUCCESSMSG("The push/pop tests completed successfully.");

	TESTRETURN;
}


int RefCounter::count = 0;


}
}