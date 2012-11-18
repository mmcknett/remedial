// vector.cpp
//
// Implements the remedial template library vector interface
//

#include <limits>
#include <cstring>

#include "vector.h"

namespace rtl
{


// ============================================================================
// listIterator implementation
// ============================================================================
template <typename L, typename T>
listIterator<L, T>::listIterator(L& list) :
	m_list(list),
	m_idxCur(0)
{
}

template <typename L, typename T>
listIterator<L, T>::listIterator(const listIterator<L, T>& other) :
	m_list(other.m_list),
	m_idxCur(other.m_idxCur)
{
}


template <typename L, typename T>
bool listIterator<L, T>::end() const
{
	return m_list.size() == m_idxCur;
}

template <typename L, typename T>
listIterator<L, T>& listIterator<L, T>::operator++()
{
	++m_idxCur;
	return *this;
}


template <typename L, typename T>
T& listIterator<L, T>::operator*()
{
	return m_list[m_idxCur];
}

template <typename L, typename T>
bool listIterator<L, T>::operator==(const listIterator<L, T>& other) const
{
	return	m_list == other.m_list &&
			m_idxCur == other.m_idxCur;
}


// ============================================================================
// reverseListIterator implementation
// ============================================================================
template <typename L, typename T>
reverseListIterator<L, T>::reverseListIterator(L& list) :
	listIterator<L, T>(list)
{
	m_idxCur = list.size() - 1;
}


template <typename L, typename T>
reverseListIterator<L,T>::reverseListIterator(const reverseListIterator<L, T>& other) :
	m_list(other.m_list),
	m_idxCur(other.m_idxCur)
{
}


template <typename L, typename T>
bool reverseListIterator<L,T>::end() const
{
	// TODO: That's just incorrect.  m_idxCur is unsigned!
	//return m_idxCur == -1;
	return true; // I'm just breaking it for now.
}

template <typename L, typename T>
reverseListIterator<L, T>& reverseListIterator<L,T>::operator++()
{
	--m_idxCur;
	return *this;
}


// ============================================================================
// vector implementation
// ============================================================================

template <typename T>
vector<T>::vector(size_type n = 0, const T& x = T()) :
	m_capacity(n),
	m_size(n)
{
	m_data = new T[m_size];
	std::memset(m_data, x, m_size);
}


template <typename T>
vector<T>::vector(const vector<T>& v) :
	m_capacity(v.m_capacity),
	m_size(v.m_size)
{
	if(m_size > m_capacity)
		; // TODO: This should never happen.  throw the right exception.

	m_data = new T[m_capacity];
	std::memcpy(m_data, v.m_data, m_size);
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

}

template <typename T>
typename vector<T>::const_iterator vector<T>::begin() const
{

}

template <typename T>
typename vector<T>::iterator vector<T>::end()
{
}

template <typename T>
typename vector<T>::const_iterator vector<T>::end() const
{
}


template <typename T>
typename vector<T>::reverse_iterator vector<T>::rbegin()
{
}

template <typename T>
typename vector<T>::const_reverse_iterator vector<T>::rbegin() const
{
}

template <typename T>
typename vector<T>::reverse_iterator vector<T>::rend()
{
}

template <typename T>
typename vector<T>::const_reverse_iterator vector<T>::rend() const
{
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

}


template <typename T>
typename vector<T>::size_type vector<T>::capacity() const
{
	return m_capacity;
}


template <typename T>
bool vector<T>::empty() const
{

}


template <typename T>
void vector<T>::clear()
{
}


template <typename T>
void vector<T>::reserve(size_type n)
{

}


template <typename T>
T& vector<T>::operator[](size_type n)
{

}


template <typename T>
const T& vector<T>::operator[](size_type n) const
{
}


template <typename T>
T& vector<T>::at(size_type n)
{
}


template <typename T>
const T& vector<T>::at(size_type n) const
{

}


template <typename T>
T& vector<T>::front()
{
}


template <typename T>
const T& vector<T>::front() const
{
}


template <typename T>
T& vector<T>::back()
{
}


template <typename T>
const T& vector<T>::back() const
{
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
}


template <typename T>
typename vector<T>::iterator vector<T>::erase(typename vector<T>::iterator first, typename vector<T>::iterator last)
{
}


template <typename T>
void vector<T>::swap(vector<T>& v)
{
}


// Create dummy template use so the template code actually gets copmiled.
// TODO: Remove when tests are in place.
vector<int> dummyVector;
listIterator<vector<int>, int> dummyIntListIter(dummyVector);
reverseListIterator<vector<int>, int> dummyIntReverseListIter(dummyVector);


}