#include "vector.h"

namespace rtl
{

template <typename Iter, typename Comp>
void mergesort(Iter first, Iter last, Comp comp)
{
	typedef std::iterator_traits<Iter>::value_type Type;

	// Base case -- list of size 1
	if (std::distance(first, last) == 1)
		return;

	// Recursively sort the first half of the list and the second half of the
	// list, then merge the two halves of the list.
	Iter mid = first + std::distance(first, last) / 2;
	vector<Type> lower(first, mid);
	vector<Type> upper(mid, last);

	mergesort(lower.begin(), lower.end(), comp);
	mergesort(upper.begin(), upper.end(), comp);

	vector<Type> result(lower.size() + upper.size());

	auto lowerI = lower.begin();
	auto upperI = upper.begin();
	size_t idx = 0;
	while(lowerI != lower.end() && upperI != upper.end())
	{
		if(comp(*lowerI, *upperI))
			result[idx++] = *lowerI++;
		else
			result[idx++] = *upperI++;
	}

	while(lowerI != lower.end())
		result[idx++] = *lowerI++;

	while(upperI != upper.end())
		result[idx++] = *upperI++;

	std::copy(result.begin(), result.end(), first);
}

template <typename Iter, typename Comp>
void quicksort(Iter first, Iter last, Comp comp)
{
}

}