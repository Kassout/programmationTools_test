//
// Created by maxim on 23/04/2021.
//

#include <iostream>
#include "llist.h"

template <typename T>
template<int N>
DoubleLinkedList<T>::DoubleLinkedList(T (&arr) [N]) : _head(NULL), _tail(NULL) {
    for (int i = 0; i != N; ++i) {
        push_back(arr[i]);
    }
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList() {
    while(_head)
    {
        Node* temp(_head);
        _head=_head->next;
        delete temp;
    }
}

template <typename T>
bool DoubleLinkedList<T>::empty() const {
    return (!_head || !_tail);
}

template <typename T>
DoubleLinkedList<T>::operator bool() const {
    return !empty();
}

template <typename T>
void DoubleLinkedList<T>::push_back(T data)
{
    _tail = new Node(data, _tail, NULL);
    if (_tail->_prev) {
        _tail->_prev->_next = _tail;
    }

    if (empty()) {
        _head = _tail;
    }
}

template <typename T>
void DoubleLinkedList<T>::push_front(T data)
{
    _head = new Node(data, NULL, _head);
    if (_head->_next) {
        _head->_next->_prev = _head;
    }

    if (empty()) {
        _tail = _head;
    }
}

template<typename T>
T DoubleLinkedList<T>::pop_back()
{
    if (empty()) {
        throw("DoubleLinkedList : list empty");
    }

    Node* temp(_tail);
    T data(_tail->data);
    _tail = _tail->prev;

    if (_tail) {
        _tail->next = NULL;
    } else {
        _head = NULL;
    }

    delete temp;
    return data;
}

template<typename T>
T DoubleLinkedList<T>::pop_front()
{
    if (empty()) {
        throw("DoubleLinkedList : list empty");
    }

    Node* temp(_head);
    T data(_head->data);
    _head = _head->next;

    if (_head) {
        _head->prev = NULL;
    } else {
        _tail = NULL;
    }

    delete temp;
    return data;
}
