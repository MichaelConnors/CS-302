#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED

#include <iostream>

template<class T>
class QuickSort{
public:
    QuickSort();

    void quickSort(T arr[],int low, int high);
    int partition(T arr[],int low,int high);

    int getSwaps()const;
    int getComparisons()const;

private:
    int swaps;
    int comparisons;
};

#endif // QUICKSORT_H_INCLUDED
