// Test methods for RTL classes
#pragma once

namespace rtl
{
namespace tests
{

// sort tests
bool RunSortTests();

bool MergeSortTest();

// vector tests
bool RunVectorTests();


// Tests the various vector constructors.
bool VectorIntConstructorTest();

// Makes a vector<int> and inserts 5 numbers.
bool VectorIntInsertEraseTest();

// Checks push_back and pop_back.
bool VectorPushPopTest();


class RefCounter
{
public:
	RefCounter(bool enableLogging = false);
	RefCounter(const RefCounter& other);
	~RefCounter();

	static int GetCount();

private:
	void PrintBeforeLog(char* prefix = "");
	void PrintAfterLog();

	bool m_enableLogging;

	static int s_count;
};

class VerboseLogging
{
public:
	VerboseLogging();
	~VerboseLogging();

	static bool Enabled();

private:
	static int s_verboseLoggingEnabled;
};

class StopWatch
{
public:
	StopWatch();
	void Reset();
	__int64 GetTickCount();

private:
	__int64 m_startTickCount;
};

}
}