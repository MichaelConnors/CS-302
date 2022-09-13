#ifndef SELECTIONSORT_H_INCLUDED
#define SELECTIONSORT_H_INCLUDED

#include <iostream>

template<class T>
class SelectionSort{
public:
    SelectionSort();

    void selectionSort(T arr[],int arrSize);
    int getSwaps()const;
    int getComparisons()const;

private:
    int swaps;
    int comparisons;
};

#endif // SELECTIONSORT_H_INCLUDED
