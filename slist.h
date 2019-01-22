#include <string>
using namespace std;
/*

Header file for single linked list class library

*/
class Airport
{
public:
    char    code[5];
    double   longitude;
    double   latitude;

};
class Node{
  public:
    Node * next;
    Airport * air;
    string toString();
};
string toString();
class LinkedList{
  public:
    int length;
    Node* head;

    LinkedList();
    ~LinkedList();
    void add(Airport * air);
    void clear();
    bool equals(LinkedList * linked);
    Node* get(int index);
    void insert(int index, Node * node) ;
    void exchg(int index1, int index2);
    void swap(int index1, int index2);
    bool isEmpty();
    void remove(int index);
    void set(int index,  Airport * air);
    int size();
    LinkedList * subList(int start, int length);
    string toString();
};
// add(value)				//Adds a new value to the end of this list.
void add(Airport * air);
// clear()					//Removes all elements from this list.
void clear();
// equals(list)				//Returns true if the two lists contain the same elements in the same order.
bool equals(LinkedList * linked);
//get(index)				//Returns the element at the specified index in this list.
Node* get(int index);
//insert(index, value)		//Inserts the element into this list before the specified index.
void insert(int index, Node * node);
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
void set(int index,  Airport * air);
// size()					//Returns the number of elements in this list.
int size();
// subList(start, length)	//Returns a new list containing elements from a sub-range of this list.
LinkedList * subList(int start, int length);
// toString()				//Converts the list to a printable string representation.
string toString();
