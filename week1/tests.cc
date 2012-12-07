// Implementation of RTL tests
#include <iostream>

#include "tests.h"
#include "vector.h"

namespace rtl
{
namespace tests
{



#define TESTINIT(s) \
	bool success = true; \
	std::cerr << s << std::endl; \

#define CHK(x) \
	success = success && (x); \
	if (!success) return false; \

#define CHKS(x,s) \
	success = success && (x); \
	if (!success) \
	{ \
		std::cerr << "\nFAIL: " << s << std::endl << std::endl; \
		return false; \
	} \

// For Verbose logging
#define VRBSLOG(s) \
	if (VerboseLogging::Enabled()) \
		std::cerr << "\t" << s << std::endl; \

#define SUCCESSMSG(s) \
	if (success) \
		std::cerr << s << std::endl; \

#define TESTRETURN \
	return success; \


bool RunVectorTests()
{
	TESTINIT("Running all rtl::vector<T> tests.\n");

	CHK(VectorIntConstructorTest());
	CHK(VectorIntInsertEraseTest());
	CHK(VectorPushPopTest());

	SUCCESSMSG("\nAll tests completed successfully!\n");

	TESTRETURN;
}


bool VectorIntConstructorTest()
{
	TESTINIT("Running rtl::vector<int> constructor tests.");

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
		CHKS(dut2[i] == dut1[i], "The copy constructor din't initialize the vector entries correctly.");

	int dut3Array[] = {2,1,4,3,5};
	vector<int> dut3(dut3Array, dut3Array + sizeof(dut3Array)/sizeof(int));
	CHKS(dut3.size() == sizeof(dut3Array)/sizeof(int), "Iterator constructor: Did not create a vector of the correct size.");
	CHKS(dut3.capacity() >= sizeof(dut3Array)/sizeof(int), "Iterator constructor: Did not create a vector with enough capacity.");
	for (size_t i = 0; i < dut3.size(); ++i)
		CHKS(dut3[i] == dut3Array[i], "Iterator constructor: Did not initialize the vector entries correctly.");

	SUCCESSMSG("The constructor tests for vector<int> completed successfully!");

	TESTRETURN;
}


bool VectorIntInsertEraseTest()
{
	TESTINIT("Running rtl::vector<int> insertion tests.");

	int testInts[] = {2, 3, 4, 1, 2};
	size_t cTestInts = 5;
	int expected[] = {2, 3, 5, 4, 1, 2};
	size_t cExpected = 6;
	int expected2[] = {5, 2, 3, 4, 1, 2};
	int expected3[] = {2, 3, 4, 1, 2, 5};

	// Check inserting in the middle.
	vector<int> dut(testInts, testInts + sizeof(testInts)/sizeof(int));
	CHK(dut.size() == cTestInts && std::equal(dut.begin(), dut.end(), testInts));

	vector<int>::iterator i = dut.begin();
	++i;
	++i;
	vector<int>::iterator result = dut.insert(i, 5);

	CHKS(i == result, "The iterator given to insert should match the returned iterator.");
	CHKS(*result == 5, "The inserted element was not correct.");
	CHKS(dut.size() == cExpected && std::equal(dut.begin(), dut.end(), expected),
		 "After middle insertion, the vector does not contain the expected values.");


	// Check erase
	dut.erase(result);
	CHKS(dut.size() == cTestInts && std::equal(dut.begin(), dut.end(), testInts),
		 "After middle erase, the vector is not the original vector.");

	// Check inserting at the front.
	result = dut.insert(dut.begin(), 5);
	CHKS(*result == 5, "The inserted element was not correct.");
	CHKS(dut.size() == cExpected && std::equal(dut.begin(), dut.end(), expected2),
		 "After front insertion, the vector does not contain the expected values.");

	// Check erase
	dut.erase(result);
	CHKS(dut.size() == cTestInts && std::equal(dut.begin(), dut.end(), testInts),
		 "After front erase, the vector is not the original vector.");

	// Check inserting at the end.
	result = dut.insert(dut.end(), 5);
	CHKS(*result == 5, "The inserted element was not correct.");
	CHKS(dut.size() == cExpected && std::equal(dut.begin(), dut.end(), expected3),
		 "After end insertion, the vector does not contain the expected values.");

	// Check erase
	dut.erase(result);
	CHKS(dut.size() == cTestInts && std::equal(dut.begin(), dut.end(), testInts),
		 "After end erase, the vector is not the original vector.");

	SUCCESSMSG("The insertion tests for vector<int> completed successfully!");

	TESTRETURN;
}


bool VectorPushPopTest()
{
	TESTINIT("Running rtl::vector push/pop tests");


	// Push a couple of elements, and then pop them.  The RefCounter object
	// will at the very least verify that the resulting number of ctor and dtor
	// calls is as expected.
	vector<RefCounter> dut;
	{
		RefCounter obj(VerboseLogging::Enabled() /*enableLogging*/);
		dut.push_back(obj);
		dut.push_back(obj);
	}

	CHKS(dut.size() == 2, "The vector has the wrong size.");
	CHKS(RefCounter::GetCount() == 2, "push_back did not do construction properly.  Count is " << RefCounter::GetCount());

	dut.pop_back();
	dut.pop_back();

	CHKS(dut.size() == 0, "The vector has the wrong size.");
	CHKS(RefCounter::GetCount() == 0, "push_back did not do construction properly.  Count is " << RefCounter::GetCount());

	VRBSLOG("");

	// Start with a default list and add/remove elements.
	int testInts[] = {2,1,3,4,5};
	size_t testIntsSize = 5;
	int expected[] = {2,1,3,4,5,7,9};
	size_t expectedSize = 7;
	vector<int> dut1(testInts, testInts + sizeof(testInts)/sizeof(int));
	VRBSLOG("Created a vector of size " << dut1.size() << " when " << testIntsSize << " was expected.");
	CHKS(dut1.size() == testIntsSize, "push_back: iterator constructor didn't work.");

	dut1.push_back(7);
	VRBSLOG("Added 7 to the vector, and " << dut1.back() << " is there now.");
	dut1.push_back(9);
	VRBSLOG("Added 9 to the vector, and " << dut1.back() << " is there now.");

	VRBSLOG("Now the vector has " << dut1.size() << " objects and " << expectedSize << " was expected.");
	CHKS(dut1.size() == expectedSize, "push_back: push_back did not increase the vector size correctly.");
	CHKS(std::equal(dut1.begin(), dut1.end(), expected), "push_back did not modify the vector as expected.");

	dut1.pop_back();
	VRBSLOG("Popped 9 off; 7 should be the back and what's there is " << dut1.back());
	dut1.pop_back();
	VRBSLOG("Popped 7 off; 5 should be the back and what's there is " << dut1.back());

	CHK(dut1.size() == testIntsSize);
	CHKS(std::equal(dut1.begin(), dut1.end(), testInts), "pop_back did not modify the vector as expected.");


	SUCCESSMSG("The push/pop tests completed successfully.");

	TESTRETURN;
}



//
// RefCounter test class implementation
//

RefCounter::RefCounter(bool enableLogging /*= false*/) :
	m_enableLogging(enableLogging)
{
	PrintBeforeLog("\t(ctor): ");

	++s_count;

	PrintAfterLog();
}

RefCounter::RefCounter(const RefCounter& other) :
	m_enableLogging(other.m_enableLogging)
{
	PrintBeforeLog("\t(copyctor): ");

	++s_count;
	
	PrintAfterLog();
}

RefCounter::~RefCounter()
{
	PrintBeforeLog("\t(dtor): ");

	--s_count;

	PrintAfterLog();
}

void RefCounter::PrintBeforeLog(char* prefix /*= ""*/)
{
	if (m_enableLogging)
		std::cerr << prefix << "RefCount: The count was " << GetCount();
}

void RefCounter::PrintAfterLog()
{
	if (m_enableLogging)
		std::cerr << " and became " << GetCount() << std::endl;
}

/*static*/ int RefCounter::GetCount()
{
	return s_count;
}

int RefCounter::s_count = 0;


//
// VerboseLogging implementation
//

VerboseLogging::VerboseLogging()
{
	s_verboseLoggingEnabled++;
}

VerboseLogging::~VerboseLogging()
{
	s_verboseLoggingEnabled--;
}

/*static*/ bool VerboseLogging::Enabled()
{
	return s_verboseLoggingEnabled != 0;
}

/*static*/ int VerboseLogging::s_verboseLoggingEnabled = 0;


}
}