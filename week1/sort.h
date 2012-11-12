// Sorting algorithms.
#pragma once

namespace rtl {

template <typename Iter, typename Comp>
void mergesort(Iter first, Iter last, Comp comp);

template <typename Iter, typename Comp>
void quicksort(Iter first, Iter last, Comp comp);

}  // namespace rtl
