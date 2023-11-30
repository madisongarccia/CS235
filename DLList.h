#pragma once

#include <iostream>
#include <string>

using namespace std;

template<class T>
class DLList {
public:
    struct Node {
        Node* prev;
        Node* next;
        T value;

        Node(T v) : prev(nullptr), next(nullptr), value(v) {}
    };

    DLList() : head(nullptr), tail(nullptr), count(0){}

    ~DLList() {
        clear();
    }

    const Node* get_head() const {
        // implement get_head here
        return head;
    }

    void push_front(T item) {
        // implement push_front here
        Node* nodeNew = new Node(item);
        if (head == nullptr){
            head = nodeNew;
            tail = nodeNew;
        }
        else{
            nodeNew->next = head;
            head->prev = nodeNew;
            head = nodeNew;
        }
        count ++;
    }

    void push_back(T item) {
        // implement push_back here
        Node* nodeNew = new Node(item); //new variable
        if (head == nullptr){
            head = nodeNew;
            tail = nodeNew;
        }
        else {
            tail->next = nodeNew;
            tail = nodeNew;
        }
        count++;
    }

    void insert(T item, int position) {
        // implement insert here
        //if position invalid
        if (position < 0 || position > count){
            throw std::out_of_range("Position out of range");
        }
        Node* nodeNew = new Node(item);
        if (position == 0){
            if (head == nullptr){
                head = nodeNew;
                tail = nodeNew;
            } else{
                nodeNew->next = head;
                head->prev = nodeNew;
                head = nodeNew;
            }
        }
        else if (position == count){
            nodeNew->prev = tail;
            tail->next = nodeNew;
            tail = nodeNew;
        }
        else{
            Node* current = head;
            for (int i = 0; i < position; i++){
                if (current == nullptr){
                    throw std::out_of_range("invalid position");
                }
                current = current->next;
            }
            nodeNew->prev = current->prev;
            nodeNew->next = current;
            current->prev->next = nodeNew;
            current->prev = nodeNew;
        }
        count ++;
    }

    void pop_front() {
        // implement pop_front here
        if (head == nullptr){
            throw std::length_error("List empty");
        }
        else if (head == tail){
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else{
            Node* newHead = head->next;
            if (newHead != nullptr){
                newHead->prev = nullptr;
                delete head;
                head = newHead;
            }
        }
        count --;
    }


    void pop_back() {
        // implement pop_back here
        if (tail == nullptr){
            throw std::length_error("Length of 0");
        }
        if (head == tail){
            delete head;
            head = nullptr;
            tail = nullptr;
            count --;
            return;
        }
        int position = size()-1;
        Node* itr = head;
        for (int i = 0; i < (position - 1); i++){
            itr = itr->next;
        }
        Node* tmp = tail;
        itr->next = nullptr;
        delete tmp;
        tail = itr;
        count --;
    }
    void remove(int position) {
        // implement remove here
        if (position >= size()){
            throw std::out_of_range("Length exception error");
        }
        if (position == 0){
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
        //if position = size (last)
        else if (position == size()-1){
            Node* tmp = tail;
            tail = tail->prev;
            delete tmp;
            if (tail != nullptr){
                tail->next = nullptr;
            }
        }
        //remove something in the middle
        else{
            Node* itr = head;
            for (int i = 0; i < (position - 1); i++){
                itr = itr->next;
            }
            Node* tmp = itr->next;
            itr->next = itr->next->next;
            if (itr->next != nullptr){
                itr->next->prev = itr;
            }
            delete tmp;
        }
        count --;
    }

    const T& front() const {
        // implement front here
        if (head == nullptr){
            throw std::length_error("List empty");
        }
        return head->value;
    }
    const T& back() const {
        // implement back here
        if (tail == nullptr){
            throw std::length_error("List empty");
        }
        return tail->value;
    }
    const T& at(int index) const {
        // implement at here
        if (index < 0 || index >= count){
            throw std::out_of_range("Index out of range");
        }
        Node* current = head;
        for (int i = 0; i < index; i++){
            current = current->next;
        }
        return current->value;
    }

    bool contains(const T& item) const {
        // implement contains here
        Node* current = head; //starts at first value
        while (current != nullptr){
            if (current->value == item){
                return true;
            }
            current = current->next;
        }
        return false;
    }

    int size() const {
        // implement size here
        return count;
    }

    void clear() {
        // implement clear here
        remove(0);
    }

private:
    Node* head;
    Node* tail;
    int count;
};




















