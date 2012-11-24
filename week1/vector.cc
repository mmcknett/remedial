// vector.cpp
//
// Implements the remedial template library vector interface
//

//#include <algorithm>
#include <cstring>
#include <limits>

#include "vector.h"

namespace rtl
{


//// ============================================================================
//// listIterator implementation
//// ============================================================================
//template <typename L, typename T>
//listIterator<L, T>::listIterator(L& list) :
//	m_list(list),
//	m_idxCur(0)
//{
//}
//
//template <typename L, typename T>
//listIterator<L, T>::listIterator(const listIterator<L, T>& other) :
//	m_list(other.m_list),
//	m_idxCur(other.m_idxCur)
//{
//}
//
//
//template <typename L, typename T>
//bool listIterator<L, T>::end() const
//{
//	return m_list.size() == m_idxCur;
//}
//
//template <typename L, typename T>
//listIterator<L, T>& listIterator<L, T>::operator++()
//{
//	++m_idxCur;
//	return *this;
//}
//
//
//template <typename L, typename T>
//T& listIterator<L, T>::operator*()
//{
//	return m_list[m_idxCur];
//}
//
//template <typename L, typename T>
//bool listIterator<L, T>::operator==(const listIterator<L, T>& other) const
//{
//	return	&m_list == &other.m_list &&
//			m_idxCur == other.m_idxCur;
//}
//
//
//// ============================================================================
//// reverseListIterator implementation
//// ============================================================================
//template <typename L, typename T>
//reverseListIterator<L, T>::reverseListIterator(L& list) :
//	listIterator<L, T>(list)
//{
//	m_idxCur = list.size() - 1;
//}
//
//
//template <typename L, typename T>
//reverseListIterator<L,T>::reverseListIterator(const reverseListIterator<L, T>& other) :
//	listIterator<L, T>(other)
//{
//}
//
//
//template <typename L, typename T>
//bool reverseListIterator<L,T>::end() const
//{
//	// TODO: That's just incorrect.  m_idxCur is unsigned!
//	//return m_idxCur == -1;
//	return true; // I'm just breaking it for now.
//}
//
//template <typename L, typename T>
//reverseListIterator<L, T>& reverseListIterator<L,T>::operator++()
//{
//	--m_idxCur;
//	return *this;
//}


// ============================================================================
// vector implementation
// ============================================================================

template <typename T>
vector<T>::vector(size_type n) :
	m_data(nullptr),
	m_capacity(0),
	m_size(0)
{
	reserve(n);
}


template <typename T>
vector<T>::vector(size_type n, const T& x /*= T()*/) :
	m_data(nullptr),
	m_capacity(0),
	m_size(0)
{
	resize(n, x);
}


template <typename T>
vector<T>::vector(const vector<T>& v) :
	m_capacity(v.m_capacity),
	m_size(v.m_size)
{
	if(m_size > m_capacity)
		(void*)nullptr; //throw new exception; // TODO: This should never happen.  throw the right exception.

	m_data = m_alloc.allocate(m_capacity);

	for (size_type i = 0; i < m_size; ++i)
		m_alloc.construct(&m_data[i], v.m_data[i]);
}


template <typename T>
template <typename I>
vector<T>::vector(I first, I last) : 
	m_capacity(c_DefaultCapcity),
	m_size(0)
{
	for(; first == last; ++first)
		push_back(*first);
}


template <typename T>
vector<T>::~vector()
{
	m_size = 0;
	m_capacity = 0;
	delete[] m_data;
	m_data = nullptr;
}


template <typename T>
typename vector<T>::iterator vector<T>::begin()
{
	return m_data;
}

template <typename T>
typename vector<T>::const_iterator vector<T>::begin() const
{
	return m_data;
}

template <typename T>
typename vector<T>::iterator vector<T>::end()
{
	return m_data + m_size;
}

template <typename T>
typename vector<T>::const_iterator vector<T>::end() const
{
	return m_data + m_size;
}


template <typename T>
typename vector<T>::reverse_iterator vector<T>::rbegin()
{
	return std::reverse_iterator<vector<T>::iterator>(end());
}

template <typename T>
typename vector<T>::const_reverse_iterator vector<T>::rbegin() const
{
	return std::reverse_iterator<vector<T>::const_iterator>(end());
}

template <typename T>
typename vector<T>::reverse_iterator vector<T>::rend()
{
	return std::reverse_iterator<vector<T>::iterator>(begin());
}

template <typename T>
typename vector<T>::const_reverse_iterator vector<T>::rend() const
{
	return std::reverse_iterator<vector<T>::const_iterator>(begin());
}


template <typename T>
typename vector<T>::size_type vector<T>::size() const
{
	return m_size;
}


template <typename T>
typename vector<T>::size_type vector<T>::max_size() const
{
	return std::numeric_limits<size_type>::max();
}

template <typename T>
void vector<T>::resize(size_type size, T copy = T())
{
	// Nothing to do.
	if (size == m_size)
		return;

	// Reserve space for the new size (no-op if size < m_capacity).
	size_t oldSize = m_size; // Only for debugging
	reserve(size);

	if(oldSize != m_size)
		(void*)0; //throw new exception(); // Should never happen.

	// Fill out any empty slots with the default data.
	if (m_size < size)
		std::fill(m_data + m_size, m_data + size, copy);

	// Set the size.  If size is less than m_size, don't bother updating
	// the existing slots.
	m_size = size;
}


template <typename T>
typename vector<T>::size_type vector<T>::capacity() const
{
	return m_capacity;
}


template <typename T>
bool vector<T>::empty() const
{
	return m_size == 0;
}


template <typename T>
void vector<T>::clear()
{
}


template <typename T>
typename vector<T>::size_type vector<T>::nextLargestCapacity(typename vector<T>::size_type n)
{
	static bool s_useMathSolution = false;

	if (s_useMathSolution)
	{
		// TODO: This involves logs and ceilings or something
		return n;
	}
	else
	{
		// Iterative method
		size_type accumulator = c_DefaultCapacity;
		while(accumulator < n)
			accumulator *= c_DefaultGrowthFactor;
		return accumulator;
	}
}


template <typename T>
void vector<T>::reserve(size_type n)
{
	// If we already have the capcity, don't reserve anything.
	if (m_capacity >= n)
		return;

	// Find the smallest factor of the growth factor larger than n, and
	// create a new array for the data.
	size_t newCap = nextLargestCapacity(n);
	T* newData = m_alloc.allocate(newCap);

	if (newCap < m_capacity || m_size > m_capacity)
		(void*)nullptr; //throw new exception(); // TODO: Throw exception; This should never ever happen.

	// Copy the existing data into the new data array.
	std::copy<iterator, iterator>(begin(), end(), newData);

	// Assign the new array to the object and delete the old memory.
	T* oldData = m_data;
	m_data = newData;
	m_alloc.deallocate(oldData, m_capacity);

	// Set the capacity to the size of the new buffer.
	m_capacity = newCap;
}


template <typename T>
T& vector<T>::operator[](size_type n)
{
	return at(n);
}


template <typename T>
const T& vector<T>::operator[](size_type n) const
{
	return at(n);
}


template <typename T>
T& vector<T>::at(size_type n)
{
	if(n < m_size)
	{
		return m_data[n];
	}
	else
	{
		// TODO: Throw an exception.
		return s_default;
	}
}


template <typename T>
const T& vector<T>::at(size_type n) const
{
	if(n < m_size)
	{
		return m_data[n];
	}
	else
	{
		// TODO: Throw an exception.
		return s_default;
	}
}


template <typename T>
T& vector<T>::front()
{
	return s_default;
}


template <typename T>
const T& vector<T>::front() const
{
	return s_default;
}


template <typename T>
T& vector<T>::back()
{
	return s_default;
}


template <typename T>
const T& vector<T>::back() const
{
	return s_default;
}


template <typename T>
template <typename I>
void vector<T>::assign(I first, I last)
{
}


template <typename T>
void vector<T>::assign(size_type n, const T& x)
{
}


template <typename T>
void vector<T>::push_back(const T& x)
{
}


template <typename T>
void vector<T>::pop_back()
{
}


template <typename T>
typename vector<T>::iterator vector<T>::insert(typename vector<T>::iterator p, const T& x)
{
	return p;
}


template <typename T>
void vector<T>::insert(iterator p, size_type n, const T& x)
{
}


template <typename T>
template <typename I>
void vector<T>::insert(I p, I first, I last)
{
}


template <typename T>
typename vector<T>::iterator vector<T>::erase(typename vector<T>::iterator p)
{
	return p;
}


template <typename T>
typename vector<T>::iterator vector<T>::erase(typename vector<T>::iterator first, typename vector<T>::iterator last)
{
	return last;
}


template <typename T>
void vector<T>::swap(vector<T>& v)
{
}


// Create dummy template use so the template code actually gets compiled.

template class vector<int>; // TODO: I wish I didn't have to instantiate this here...
//template class listIterator<vector<char>, char>;
//template class reverseListIterator<vector<char>, char>;


}