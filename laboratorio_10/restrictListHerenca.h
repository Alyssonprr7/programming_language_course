//
// Created by calindra on 29/05/2021.
//

#ifndef LABORATORIO_10_RESTRICTLIST_H
#define LABORATORIO_10_RESTRICTLIST_H
#include <vector>
#include <string>

using namespace std;


template <class T>
class RestrictList {
    private:
        int maxSize, top;
        T *ptr;
        bool isFull();
        bool isEmpty();

    public:
        RestrictList(int maxSize);
//        ~RestrictList();
        bool push_back(T element);
        bool push_front(T element);
        bool pop_back(T &element);
        bool pop_front(T &element);
        T front () { return ptr [0]; }
        T back () { return ptr [top]; }
};

template<class T>
RestrictList<T>::RestrictList(int maxSize) : maxSize(maxSize), top(-1), ptr(new T[maxSize]) {}

//template<class T>
//RestrictList<T>::~RestrictList() {delete [] ptr; }

template<class T>
bool RestrictList<T>::push_back(T element) {
    if (!isFull()) {
        ptr [++top] = element;
        return true;
    }
    return false;
}

template<class T>
bool RestrictList<T>::isFull() {
    bool teste = top == maxSize - 1;
    return teste;
}

template<class T>
bool RestrictList<T>::isEmpty() {
    return top == -1;
}

template<class T>
bool RestrictList<T>::push_front(T element) {
    if(!isFull()) {
        int index = top++;
        while(index > 0) {
            ptr[index] = ptr[index--];
        }
        ptr[0] = element;
        return true;
    }
    return false;
}

template<class T>
bool RestrictList<T>::pop_back(T &element) {
    if(!isEmpty()) {
        element = ptr[top--];
        return true;
    }
    return false;
}

template<class T>
bool RestrictList<T>::pop_front(T &element) {
    if (!isEmpty()) {
        int idx = 1;
        element = ptr [0];
        while (idx <= top) {
            ptr [idx - 1] = ptr [idx++];

        }
        top--;
        return true;
    }
    return false;
}


#endif //LABORATORIO_10_RESTRICTLIST_H
