#pragma once
#include <vector>
#include <array>

using namespace std;

template<class T>

int medianOfThree(std::vector<T>& array, int left, int right) {
    int mid = (right + left)/2;
    if (array[left] > array[mid]){
        swap(array[mid],array[left]);
    }
    if (array[mid] > array[right]){
        swap(array[mid],array[right]);
    }
    if (array[left] > array[right]){
        swap(array[left],array[right]);
    }
    return mid;
}

template<class T>
int partition(std::vector<T>& array, int left, int right) {
    int pivot = medianOfThree(array, left, right);
    T pivot_val = array[pivot];
    int up = left + 1;
    int down = right;
    while (up <= down) {
        while (up <= down && array[up] <= pivot_val) {
            up++;
        }
        while (array[down] > pivot_val) {
            down--;
        }
        if (up < down) {
            swap(array[down], array[up]);
        }
    }
    swap(array[left], array[down]);
    return down;
}

template<class T>
void QS(vector<T>& array, int low, int high){
     if (high > low ){
         int pivot = partition(array, low, high);
         QS(array, low, pivot -1);
         QS(array, pivot + 1, high);
     }
 }

template<class T>
void sort(std::vector<T>& array) {
    int low = 0;
    int high = array.size() -1;
    if ((high - low )> 3){
        int mid = partition(array, low, high); //divide groups in half
        QS(array, low, mid-1); //bad (low numbers)
        QS(array, mid+1, high); //good (high numbers)
    }
    else{
        medianOfThree(array, low, high);
    }
}


