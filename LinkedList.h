/**
 * A doubly-linked list.
 * Stub written by James Daly, 5 Sept 2014
 * Completed by Michael H. Wright
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"
#include <iostream>
#include <functional>

template<class T> class LinkedList
{
    public:
        LinkedList();
        LinkedList(const LinkedList<T>& other);
        ~LinkedList();

        void operator=(const LinkedList<T>& other);

        // These methods are provided for you
        void Clear();
        void Display() const;
        bool IsEmpty() const;
        int Size() const;

        // Methods to add data to the front or the back of the list
        // These should run in O(1) time
        void PushFront(const T &t);
        void PushBack(const T &t);
        void PopFront();
        void PopBack();

        // These methods can run in O(n) time
        void Filter(std::function<bool (const T)> isIn);
        void ForEach(std::function<void (const T)> func) const;

    private:
        Node<T>* head;
        Node<T>* tail;
        int size;

        // You can put helper methods here
};

/**
 * Default constructor
 * Creates an empty list
 * You are allowed (but not required) to change this method
 */
template <class T> LinkedList<T>::LinkedList():
    head(nullptr),
    tail(nullptr),
    size(0)
{
    // Empty
}

/**
 * Copy Constructor
 * Creates a shallow copy of the other list
 */
template <class T> LinkedList<T>::LinkedList(const LinkedList<T> & other) : LinkedList() {
    auto insertItem = [=](T x){ this->PushBack(x); };
    other.ForEach(insertItem);
}

template <class T> LinkedList<T>::~LinkedList() {
    Clear();
}

/**
 * Assignment operator
 * Creates a shallow copy of the other list
 */
template <class T> void LinkedList<T>::operator=(const LinkedList<T> & other) {
    if (this != &other) {
        Clear();
        auto insertItem = [=](T x){ this->PushBack(x); };
        other.ForEach(insertItem);
    }
}

/**
 * Removes all elements from this list
 */
template <class T> void LinkedList<T>::Clear() {
    while(!IsEmpty()) {
        PopFront();
    }
}

/**
 * Prints the contents of this list to the console
 */
template <class T> void LinkedList<T>::Display() const {
    using namespace std;
    auto printItem = [](T x) { cout << x << " "; };
    ForEach(printItem);
    cout << endl;
}

/**
 * Checks if the list contains no items
 */
template <class T> bool LinkedList<T>::IsEmpty() const{
    return size == 0;
}

/**
 * Counts the number of items in the list
 */
template <class T> int LinkedList<T>::Size() const {
    return size;
}

/**
 * Adds the item to the front of the list
 */
template <class T> void LinkedList<T>::PushFront(const T &t) {
    // TODO
    Node<T> *append_node = new Node<T> (t);
    if (head == nullptr)
    {
        append_node->next = nullptr;
        append_node->prev = nullptr;
        head = append_node;
        tail = append_node;
    }//of if
    // if the list is empty to start
    else
    {
        append_node->next = head;
        append_node->prev = nullptr;
        head->prev = append_node;
        head = append_node;
    }//of else
    size++;
}

//different
//  if head == tail --> 1 item OR if size = 1;

/**
 * Adds the item to the back of the list
 */
template <class T> void LinkedList<T>::PushBack(const T &t) {
    // TODO
    // append new node to the end of the list
    Node<T> *append_node = new Node<T> (t);
    if (tail == nullptr)
    {
        append_node->prev = nullptr;
        append_node->next = nullptr;
        head = append_node;
        tail = append_node;
    }//of if
    // if the list is empty to start
    else
    {
        tail->next = append_node; 
        append_node->prev = tail;
        append_node->next = nullptr;
        tail = append_node;
    }//of else
    size++;
}

/**
 * Removes the item at the front of the list
 */
template <class T> void LinkedList<T>::PopFront() {
    // TODO
    Node<T> *temp_ptr = head;
    if (head == nullptr)
    {
        // do nothing; nothing to delete!
        delete(temp_ptr);
    }
    if (head->next == nullptr)
    {
        // whenever you are deleting, first create a node pointing 
        // to the node you want to delete.
        head = nullptr;
        tail = nullptr;
        delete(temp_ptr);
    }
    // if the list is more than one item long.
    else
    {
        head = head->next;
        head->prev = nullptr;
        delete(temp_ptr);
    }
    size--;
}

/**
 * Removes the item at the back of the list
 */
template <class T> void LinkedList<T>::PopBack() {
    // TODO
    Node<T> *temp_ptr = tail;
    if (tail == nullptr)
    {
        delete(temp_ptr);
    }
    if (tail->next == nullptr)
    {
        head = nullptr;
        head = nullptr;
        delete(temp_ptr);
    }
    else
    {
        temp_ptr = tail->prev;
        tail->next = nullptr;
        delete(temp_ptr);
    }
}

/**
 * Edits this list to keep only the items where isIn(x) returns true
 * Other items are deleted
 */
template <class T> void LinkedList<T>::Filter(std::function<bool (const T)> isIn) {
    // TODO
    Node<T> *moving_node = head;
    while (moving_node != nullptr)
    {
       if (! isIn)
       {
        // TODO 
        // Delete function
       } 
    }

}

/**
 * Executes func(x) on each x in the list
 */
template <class T> void LinkedList<T>::ForEach(std::function<void (const T)> func) const {
    // TODO
    Node<T> *moving_node = head;
    while (moving_node != nullptr)
    {
        func(moving_node->Data());
        moving_node = moving_node->next;
    }
}

#endif
