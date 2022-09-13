#include "QuickSort.h"

template<class T>
QuickSort<T>::QuickSort():swaps(0),comparisons(0){}

template<class T>
int QuickSort<T>::partition(T arr[],int low,int high){
    int pivot = arr[high];
    int i = low;
    int tmp = 0;

    for(int j = low;j < high;j++){
        if(arr[j] < pivot){
            comparisons++;
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            swaps++;
            i = i+1;
        }
    }
    tmp = arr[i];
    arr[i] = arr[high];
    arr[high] = tmp;
    swaps++;
    return i;
}

template<class T>
void QuickSort<T>::quickSort(T arr[],int low,int high){
    if(low < high){
        int pi = partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

template<class T>
int QuickSort<T>::getSwaps()const{return swaps;}

template<class T>
int QuickSort<T>::getComparisons()const{return comparisons;}
