#include "SelectionSort.cpp"
#include "InsertionSort.cpp"
#include "QuickSort.cpp"

#include <cstdlib>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(){
    ifstream infile;
    ofstream ofile;
    int arr1[1000];
    int i = 0;
    SelectionSort<int> s1;
    InsertionSort<int> i1;
    QuickSort<int> q1;

    infile.open("1000Unsorted.txt");
    while(!infile.eof()){
        infile >> arr1[i];
        i++;
    }
    infile.close();
    auto start = high_resolution_clock::now();
    s1.selectionSort(arr1,999);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    ofile.open("SS1000WorstCase.csv");
    ofile << "Execution Time: " << duration.count() << endl;
    ofile << "Number of Swaps: " << s1.getSwaps() << endl;
    ofile << "Number of Comparisons: " << s1.getComparisons() << endl;
    ofile << endl;
}
