#ifndef SLIST_H
#define SLIST_H
#include <string>
#define TemplateClass template<class T>
using namespace std;
/*

Header file for single linked list class library

*/

TemplateClass class Node{
  public:
    Node<T> * next;
    T * data;
    string toString();
    bool equals;
};
TemplateClass class LinkedList{
  public:
    int length;
    Node<T> * head;

    LinkedList();
    ~LinkedList();
    // add(value)				//Adds a new value to the end of this list.
    void add(T * node);
    // clear()					//Removes all elements from this list.
    void clear();
    // equals(list)				//Returns true if the two lists contain the same elements in the same order.
    bool equals(LinkedList<T> * linked);
    //get(index)				//Returns the element at the specified index in this list.
    T* get(int index);
    //insert(index, value)		//Inserts the element into this list before the specified index.
    void insert(int index, T node);
    //exchg(index1, index2)		//Switches the payload data of specified indexex.
    void exchg(int index1, int index2);
    //swap(index1,index2)		//Swaps node located at index1 with node at index2
    void swap(int index1, int index2);
    // isEmpty()				//Returns true if this list contains no elements.
    bool isEmpty();
    // mapAll(fn)				//Calls the specified function on each element of the linkedlist in ascending index order.

    // remove(index)			//Removes the element at the specified index from this list.
    void remove(int index);
    // set(index, value)		//Replaces the element at the specified index in this list with a new value.
    void set(int index,  T * node);
    // size()					//Returns the number of elements in this list.
    int size();
    // subList(start, length)	//Returns a new list containing elements from a sub-range of this list.
    LinkedList<T> * subList(int start, int length);
    // toString()				//Converts the list to a printable string representation.
    string toString();
};
#include "slist.tpp"
#endif
