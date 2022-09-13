#include "SelectionSort.h"

template<class T>
SelectionSort<T>::SelectionSort():swaps(0),comparisons(0){}

template<class T>
void SelectionSort<T>::selectionSort(T arr[],int arrSize){
    for(int i = 0;i < arrSize; i++){
        int sub = i;
        int tmp = 0;
        for(int j = i+1;j < arrSize;j++){
            if(arr[sub] > arr[j]){
                sub = j;
                comparisons++;
                swaps++;
            }
        }
        tmp = arr[i];
        arr[i] = arr[sub];
        arr[sub] = tmp;
    }
}
template<class T>
int SelectionSort<T>::getComparisons()const{return comparisons;}
template<class T>
int SelectionSort<T>::getSwaps()const{return swaps;}
