#pragma once

#include <iostream>
#include <string>

using namespace std;

template<class T>
class Vector {
public:
    Vector(): count(0), capacity(1), arr(new T[1]) {
    }

    ~Vector() {
        clear();
    }

    void push_back(T item) {
        // implement push_back here
        if (count == capacity){
            resize();
        }
        arr[count] = item;
        count++;
    }

    void insert(T item, int position) {
        // implement insert here
        if (count == 0 && position > 0){
            throw out_of_range("vec empty");
        }
        else if (position < 0 || position > count){
            throw out_of_range("position out of bounds");
        }
        else{
            if (position == count){
                resize();
            }
            for (size_t i = count; i > position; i--){
                arr[i] = arr[i-1];
            }
            arr[position] = item;
            count ++;
        }
    }

    void remove(int position) {
        // implement remove here
        if (count == 0){
            throw out_of_range("empty vec");
        }
        else if ((position >= 0) & (position <= count)){
            size_t shiftStart = position;
            size_t shiftEnd = count-1;

            for (size_t i = shiftStart; i < shiftEnd; i++){
                arr[i] = arr[i+1];
            }
            count --;
        }
        else{
            throw out_of_range("position out of bounds");
        }
    }

    T& operator[](int index) {
        // implement operator[] here
        if ((index >= 0) & (index < count)){
            return arr[index];
        }
        else{
            throw out_of_range("out of bounds");
        }
    }

    int size() const {
        // implement size here
        return count;
    }

    void clear() {
        // implement clear here

        count = 0;
    }
    void print() const {
        cout << "Vector elements: ";
        for (int i = 0; i < count; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
private:
    int count;
    T* arr;
    size_t capacity;

    void resize(){
        capacity = 2 * capacity;
        T* newArr = new T[capacity];
        for (size_t i = 0; i < count; i++){
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }
};
