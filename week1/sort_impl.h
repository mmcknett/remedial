#include "vector.h"

namespace rtl
{

template <typename Iter, typename Comp>
void mergesort(Iter first, Iter last, Comp comp)
{
	// Base case -- list of size 1
	if (first == last)
		return;

	// Recursively sort the first half of the list and the second half of the
	// list, then merge the two halves of the list.
	Iter mid = first + (last - first) / 2;

}

template <typename Iter, typename Comp>
void quicksort(Iter first, Iter last, Comp comp)
{
}

}