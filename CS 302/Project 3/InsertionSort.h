#ifndef INSERTIONSORT_H_INCLUDED
#define INSERTIONSORT_H_INCLUDED

#include <iostream>

template<class T>
class InsertionSort{
public:
    InsertionSort();

    void insertionSort(T arr1[],int arrSize);
    size_t getSwaps()const;
    size_t getComparisons()const;

private:
    size_t swaps;
    size_t comparisons;
};

#endif // INSERTIONSORT_H_INCLUDED
