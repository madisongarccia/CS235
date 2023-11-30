#pragma once
#include <string>
#include<vector>
#include<algorithm>

using namespace std;

template<class T>
class HashSet {

private:
    unsigned tableSize;
    unsigned numElements;
    vector<std::vector<T>> table;
    int count;
    const double loadFactor = 1;

    void reHash(){
        unsigned newTableSize = tableSize * 2;
        vector<vector<T>> newTable(newTableSize);

        for (const auto& holder : table){
            for (const T& item : holder){
                unsigned newIndex = hashCode(item, newTableSize);
                newTable[newIndex].push_back(item);
            }
        }
        table = std::move(newTable);
        tableSize = newTableSize;

    }

    unsigned hashCode(const string& item, unsigned tableSize)const{
        unsigned hash = 0;
        for (size_t i = 0; i < item.length(); i++){
            hash = hash*31 + static_cast<unsigned>(item.at(i));
        }
        return hash%tableSize;
    }

    unsigned hashCode(const char& item, unsigned tableSize)const{
        return static_cast<unsigned>(item) %tableSize;
    }

    unsigned hashCode(const int& item, unsigned tableSize)const{
        return static_cast<unsigned>(item)%tableSize;
    }


public:
    HashSet() : tableSize(10), numElements(0), count(0){
        table.resize(10);
    }


    ~HashSet() {}



    bool insert(const T& item) {
        // implement insert here
        // return true if item was inserted, false if item was already in the set
        unsigned index = hashCode(item, tableSize);
        //is item in set already
        if (find(table[index].begin(), table[index].end(), item) != table[index].end()){
            return false;
        }
        else{
            table[index].push_back(item);
            ++count;
            if (static_cast<double>(count) / tableSize > loadFactor){
                reHash();
            }
            return true;
        }

    }

    bool remove(const T& item) {
        // implement remove here
        // return true if item was removed, false if item wasn't in the set
        unsigned index = hashCode(item, tableSize);
        auto& hold = table[index];

        auto it = find(hold.begin(), hold.end(), item);
        if (it != hold.end()) {
            hold.erase(it);
            --count;
            return true;
        } else {
            return false;
        }
    }

    bool contains(T item) const {
        // implement contains here
        // return true if item is in the set, false otherwise
        unsigned index = hashCode(item, tableSize);
        const auto& hold = table[index];
        if (find(hold.begin(), hold.end(), item) != hold.end()){
            return true;
        }
        return false;
    }

    void clear() {
        // implement clear here
        // remove all elements from the set
        for (auto& hold : table){
            hold.clear();
        }
        count = 0;
    }

    int size() const {
        // implement size here
        // return the number of elements in the set
        return count;
    }
};
