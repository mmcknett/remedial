// vector.cpp
//
// Implements the remedial template library vector interface
//

#include <limits>

#include "vector.h"

namespace rtl
{


template <typename T>
vector<T>::vector(size_type n = 0, const T& x = T())
{

}


template <typename T>
vector<T>::vector(const vector<T>& v)
{

}


template <typename T>
template <typename I>
vector<T>::vector(I first, I last)
{

}


template <typename T>
vector<T>::iterator vector<T>::begin()
{

}

template <typename T>
vector<T>::const_iterator vector<T>::begin() const
{

}

template <typename T>
vector<T>::iterator vector<T>::end()
{
}

template <typename T>
vector<T>::const_iterator vector<T>::end() const
{
}


template <typename T>
vector<T>::reverse_iterator vector<T>::rbegin()
{
}

template <typename T>
vector<T>::const_reverse_iterator vector<T>::rbegin() const
{
}

template <typename T>
vector<T>::reverse_iterator vector<T>::rend()
{
}

template <typename T>
vector<T>::const_reverse_iterator vector<T>::rend() const
{
}


template <typename T>
vector<T>::size_type vector<T>::size() const
{
}


template <typename T>
vector<T>::size_type vector<T>::max_size() const
{
	return std::numeric_limits<size_type>::max();
}

template <typename T>
void vector<T>::resize(size_type size, T copy = T())
{

}


template <typename T>
vector<T>::size_type vector<T>::capacity() const
{

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

template <typename T, typename I>
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


void vector<T>::pop_back()
{
}


template <typename T>
iterator vector<T>::insert(iterator p, const T& x)
{
}


template <typename T>
void vector<T>::insert(iterator p, size_type n, const T& x)
{
}


template <typename T, typename I> void vector<T>::insert(I p, I first, I last)
{
}


template <typename T>
iterator vector<T>::erase(iterator p)
{
}


template <typename T>
iterator vector<T>::erase(iterator first, iterator last)
{
}


template <typename T>
void vector<T>::swap(vector<T>& v)
{
}


}