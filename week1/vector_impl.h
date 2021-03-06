// vector.cpp
//
// Implements the remedial template library vector interface
//

#include <algorithm>
#include <cstring>
#include <limits>
#include <iterator>

#include "vector.h"
//#include "tests.h"

namespace rtl
{


// ============================================================================
// vector implementation
// ============================================================================

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
	m_data(nullptr),
	m_capacity(v.m_capacity),
	m_size(v.m_size)
{
	if(m_size > m_capacity)
		throw new std::exception; // TODO: This should never happen.  throw the right exception.

	m_data = m_alloc.allocate(m_capacity);

	for (size_type i = 0; i < m_size; ++i)
		m_alloc.construct(m_data + i, v.m_data[i]);
}


template <typename T>
template <typename I>
vector<T>::vector(I first, I last) :
	m_data(nullptr),
	m_capacity(0),
	m_size(0)
{
	auto size = std::distance(first, last);
	if (size > 0)
	{
		resize(size);
		std::copy<I, iterator>(first, last, begin());
	}
}


template <typename T>
vector<T>::~vector()
{
	// Destruct all elements
	for (iterator i = begin(); i < end(); ++i)
		m_alloc.destroy(i);

	// Free the memory.
	m_alloc.deallocate(m_data, m_capacity);

	m_size = 0;
	m_capacity = 0;
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
	return m_alloc.max_size();
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

	// Fill out any empty slots with the default data, or destruct old slots being removed.
	if (m_size < size)
		std::fill(m_data + m_size, m_data + size, copy);
	else if (size < m_size)
		for (iterator i = m_data + size; i < m_data + m_size; ++i)
			m_alloc.destroy(i);

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
	if (n >= m_size)
		throw new std::exception; // TODO: use the right exception.
	
	return m_data[n];
}


template <typename T>
const T& vector<T>::at(size_type n) const
{
	if (n >= m_size)
		throw new std::exception; // TODO: use the right exception.

	return m_data[n];
}


template <typename T>
T& vector<T>::front()
{
	return const_cast<T&>( const_cast<const vector<T>* >( this )->front() );
}


template <typename T>
const T& vector<T>::front() const
{
	if (m_size == 0)
		throw new std::exception; // TODO: throw the right exception.

	return *begin();
}


template <typename T>
T& vector<T>::back()
{
	return const_cast<T&>( const_cast<const vector<T>* >( this )->back() );
}


template <typename T>
const T& vector<T>::back() const
{
	if (m_size == 0)
		throw new std::exception; // TODO: throw the right exception.

	return *(end() - 1);
}


template <typename T>
template <typename I>
void vector<T>::assign(I first, I last)
{
	resize(last - first);
	std::copy_backward(first, last, end());
}


template <typename T>
void vector<T>::assign(size_type n, const T& x)
{
	size_type origSize = m_size;
	resize(n, x);
	std::fill_n(begin(), (origSize < n) ? origSize : n, x);
}


template <typename T>
void vector<T>::push_back(const T& x)
{
	// Reserve space for another element.  Note: don't use resize because it
	// would do an extra copy of x.
	reserve(m_size + 1);

	// Copy-construct the new T.
	m_alloc.construct(m_data + m_size, x);
	m_size++;
}


template <typename T>
void vector<T>::pop_back()
{
	resize(m_size - 1);
}


template <typename T>
typename vector<T>::iterator vector<T>::insert(typename vector<T>::iterator p, const T& x)
{
	return insert(p, 1u, x);
}


template <typename T>
typename vector<T>::iterator vector<T>::insert(typename vector<T>::iterator p, size_type n, const T& x)
{
	if (n == 0)
		return p; // Nothing to do.

	iterator last = end();
	resize(m_size + n);
	iterator destination = end();

	std::copy_backward(p, last, destination); // Move all the elements up n slots.
	std::fill_n(p, n, x);

	return p;
}


template <typename T>
template <typename I>
typename vector<T>::iterator vector<T>::insert(typename vector<T>::iterator p, I first, I last)
{
	if (first >= last)
		return p; // Nothing to do.

	std::iterator_traits<I>::difference_type n = std::distance(first, last);
	iterator currentLast = end();
	resize(m_size + n);
	iterator newLast = end();
	std::copy_backward(p, currentLast, newLast); // Move all the elements up n slots.
	
	// Copy the elements from first and last into our data at p.
	std::copy(first, last, p);
	return p;
}


template <typename T>
typename vector<T>::iterator vector<T>::erase(typename vector<T>::iterator p)
{
	return erase(p, p + 1);
}


template <typename T>
typename vector<T>::iterator vector<T>::erase(typename vector<T>::iterator first, typename vector<T>::iterator last)
{
	for (iterator i = first; i < last; ++i)
		m_alloc.destroy(i);

	std::memmove(first, last, (end() - last) * sizeof(T));
	m_size -= last - first;
	return first;
}


template <typename T>
void vector<T>::swap(vector<T>& v)
{
	std::swap(m_data, v.m_data);
	std::swap(m_capacity, v.m_capacity);
	std::swap(m_size, v.m_size);
}


// Create dummy template use so the template code actually gets compiled.

template class vector<int>; // TODO: I wish I didn't have to instantiate this here...
//template class vector<tests::RefCounter>;


}
