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
		std::cerr << (s) << std::endl; \
		return false; \
	} \

#define TESTRETURN \
	return success; \


bool RunVectorTests()
{
	TESTINIT;

	CHK(VectorIntInsertTest());

	TESTRETURN;
}


bool VectorIntConstructorTest()
{
	TESTINIT;

	vector<int> dut0(5);
	CHKS(dut0.capacity() == 5, "The initializing constructor didn't create a vector with the right capacity.");

	vector<int> dut1(3, 42);
	CHKS(dut0.capacity() == 3, "The initializing constructor didn't create a vector with the right capacity.");
	for (size_t i = 0; i < 3; ++i)
		CHKS(dut1[i] == 42, "The initializing constructor didn't initialize the vector entries correctly.");

	vector<int> dut2(dut1);
	CHKS(dut2.size() == dut1.size(), "The copy constructor did not create vectors of the same size.");
	CHKS(dut2.capacity() == dut2.capacity(), "The copy constructor did not create vectors of the same capacity.");
	for (size_t i = 0; i < dut2.size(); ++i)
		CHK(dut2[i] == dut1[i]);

	TESTRETURN;
}


bool VectorIntInsertTest()
{
	TESTINIT;

	int testints[] = {2, 3, 4, 1, 2};

	vector<int> dut(5);
	for (size_t i = 0; i < sizeof(testints); ++i)
		dut.push_back(testints[i]);

	CHK(dut.size() == 5);
	for (size_t i = 0; i < sizeof(testints); ++i)
		CHK(dut[i] == testints[i]);

	TESTRETURN;
}


}
}