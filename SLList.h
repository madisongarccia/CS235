#pragma once
#include <iostream>

using namespace std;

template <class T>
class SLList {
public:
    struct Node {
        Node* next;
        T value;

        Node(T v) : next(nullptr), value(v) {}
    };

    SLList() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    ~SLList() {
        clear();
    }

    const Node* get_head() const {
        // implement get_head here
        return head;
    }

    void push_back(T item) {
        //if we don't already have anything in our list
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

    void print(){
        cout << "linkedList is: ";
        Node* itr = head;
        while (itr != nullptr){
            cout << itr->value << ", ";
            itr = itr->next;
        }

        cout << endl;
    }

    void pop_back() {
        // implement pop_back here
        //get position of last thing
        if (head == nullptr){
            return;
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

    const T& front() const {
        // implement front here
        return head->value;
    }

    int size() const {
       return count;
    }

    void clear() {
        // implement clear here
        while (head != nullptr) {
            Node *tmp = head;
            head = head->next;
            delete tmp;
            count--;
        }
    }

private:
    Node* head;
    Node* tail;
    int count;
};
