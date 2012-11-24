// Test methods for RTL classes
#pragma once

namespace rtl
{
namespace tests
{

// vector tests
bool RunVectorTests();


// Tests the various vector constructors.
bool VectorIntConstructorTest();

// Makes a vector<int> and inserts 5 numbers.
bool VectorIntInsertTest();

// Checks push_back and pop_back.
bool VectorPushPopTest();


class RefCounter
{
public:
	RefCounter()
	{
		++count;
	}

	RefCounter(const RefCounter& other)
	{
		++count;
	}

	~RefCounter()
	{
		--count;
	}

	static int GetCount()
	{
		return count;
	}

private:
	static int count;
};

}
}