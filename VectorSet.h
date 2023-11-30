#pragma once
#include<vector>

using namespace std;

template<class T>
class VectorSet {
public:
    bool contains(T item) const {
        // implement contains here

        for (auto iter = v.begin(); iter != v.end(); ++iter){
            if (*iter == item){
                return true;
            }
        }
        return false;
        // return true if item is in the set and false if not
    }

    bool insert(T item) {
        // implement insert here
        for (auto iter = v.begin(); iter != v.end(); ++iter){
            if (*iter == item){
                return false;
            }
        }
        v.push_back(item);
        return true;
        // return true if item is inserted and false if item is already in the
        // set
    }

    bool remove(T item) {
        // implement remove here
        for (auto iter = v.begin(); iter != v.end(); ++iter){
            if (*iter == item){
                iter = v.erase(iter);
                return true;
            }
        }
        return false;
        // return true if item is removed and false if item wasn't in the set
    }

    int size() const {
        // implement size here
        return v.size();
        // return the number of items in the set
    }

    bool empty() const {
        // implement empty here
        int vecSize = v.size();
        if (vecSize > 0){
            return false;
        }
        return true;
        // return true if the set is empty and return false otherwise
    }

    void clear() {
        // implement clear here
        v.clear();
        // remove all items from the set
    }

private:
    vector<T> v;
};
