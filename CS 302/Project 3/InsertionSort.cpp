#include "InsertionSort.h"

template<class T>
InsertionSort<T>::InsertionSort():swaps(0),comparisons(0){}

template<class T>
void InsertionSort<T>::insertionSort(T arr1[],int arrSize){
    int tmp = 0;
    for(int i = 1;i < arrSize;i++){
    int j = i;
    while((j > 0) && (arr1[j] < arr1[j-1])){
        tmp = arr1[j];
        arr1[j] = arr1[j-1];
        arr1[j-1] = tmp;
        j = j-1;
        swaps++;
        comparisons++;
    }
    }


}

template<class T>
size_t InsertionSort<T>::getSwaps()const{return swaps;}

template<class T>
size_t InsertionSort<T>::getComparisons()const{return comparisons;}

