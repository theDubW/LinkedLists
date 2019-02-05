#include "slist.h"
#include <string>
#include <iostream>
using namespace std;
#define TemplateClass template<class T>
/*

Class Library File

*/


// Constructor
TemplateClass LinkedList<T>::LinkedList(){
    this->length = 0;
    this->head = NULL;
}
// Destructor
TemplateClass LinkedList<T>::~LinkedList(){
   Node<T> * current = this->head;
    while(current){
        this->head = current->next;
        this->length -= 1;
		    delete current;
		    current = this->head;
    }
    cout << "LIST DELETED: " << this->length << endl;
}
// add(value)				//Adds a new value to the end of this list.
TemplateClass void LinkedList<T>::add(T * node){
  Node<T> * head = this->head;
  Node<T> * toBeInserted = new Node<T>();
  toBeInserted->data = node;
  toBeInserted->next = NULL;
  if(this->length == 0){
    this->head = toBeInserted;
  }
  else{
    while(head->next!=NULL){
      head = head->next;
    }
    head->next = toBeInserted;
  }
  this->length++;
}
// clear()					//Removes all elements from this list.
TemplateClass void LinkedList<T>::clear(){
    Node<T>* current = this->head;
    current = current->next;
    int index = (this->length)-1;
    while(current->next){
      delete current;
      current = current->next;
    }
    this->length = 0;
    std::cout << "LIST DELETED: " << this->length << std::endl;
}
// equals(list)				//Returns true if the two lists contain the same elements in the same order.
TemplateClass bool LinkedList<T>::equals(LinkedList * linked){
  Node<T> * current = this->head;
  Node<T> * compared = linked->head;
  if(this->length!=linked->length){
    return false;
  }
  for(int i = 0; i<this->length;i++){
    Node<T> * list1 = this->get(i);
    Node<T> * list2 = linked->get(i);
    if(list1->code!=list2->code){
      return false;
    }
  }
  return true;
}
//get(index)				//Returns the element at the specified index in this list.
TemplateClass T* LinkedList<T>::get(int index){
  Node<T> * cur = this->head;
  for(int i = 0; i<index; i++){
    cur = cur->next;
  }
  return cur->data;
}
//insert(index, value)		//Inserts the element into this list before the specified index.
TemplateClass void LinkedList<T>::insert(int index, T node){
  Node<T> * head = this->head;
  int i = 0;
  while(i<=index){
    if(i==index-1){
      head->next = node;
    }
    if(i==index){
      node->next = head->next;
    }
    head = head->next;
    i++;
  }
  this->length++;
}
//exchg(index1, index2)		//Switches the payload data of specified indexex.
//in main
//swap(index1,index2)		//Swaps node located at index1 with node at index2
TemplateClass void LinkedList<T>::swap(int index1, int index2){
  int smallerIndex = index1<index2?index1:index2;
  int largerIndex = index2>index1?index2:index1;
  if(abs(index1-index2)==1){
      Node<T> * first = this->get(smallerIndex);
      Node<T> * second = this->get(largerIndex);
      first->next = second->next;
      second->next = first;
      if(index1==0){
        this->head = second;
      }else{
        Node<T> * beforeFirst = this->get(smallerIndex-1);
        beforeFirst->next = second;
      }
  }else{
      Node<T> * first = this->get(smallerIndex);
      Node<T> * second = this->get(largerIndex);
      Node<T> * swapper = first->next;
      first->next = second->next;
      second->next = swapper;
      if(smallerIndex==0){
        this->head = second;
        Node<T> * pointToSecond = this->get(largerIndex-1);
        pointToSecond->next = first;
      }else{
        Node<T> * pointToFirst = this->get(smallerIndex-1);
        Node<T> * pointToSecond = this->get(largerIndex-1);
        pointToFirst->next = second;
        pointToSecond->next = first;
      }
  }
}
// isEmpty()				//Returns true if this list contains no elements.
TemplateClass bool LinkedList<T>::isEmpty(){
  return this->head==NULL?true:false;
}
// remove(index)			//Removes the element at the specified index from this list.
TemplateClass void LinkedList<T>::remove(int index){
  Node<T> * toBeDeleted = this->get(index);
  if(this->size()==1){
    this->head = NULL;
    delete(toBeDeleted);
  }
  else if(index==0){
    this->head = toBeDeleted->next;
    delete(toBeDeleted);
  }else if(toBeDeleted->next == NULL){
    Node<T> * oneLess = this->get(index-1);
    oneLess->next = NULL;
    delete(toBeDeleted);
  }else{
    Node<T> * oneLess = this->get(index-1);
    oneLess->next = toBeDeleted->next;
    delete(toBeDeleted);
  }
}
// set(index, value)		//Replaces the element at the specified index in this list with a new value.
TemplateClass void LinkedList<T>::set(int index,  T * node){
  Node<T> * changeValue = this->get(index);
  changeValue = node;
}
// size()					//Returns the number of elements in this list.
TemplateClass int LinkedList<T>::size(){
  int i = 0;
  Node<T> * starter = this->head;
  while(starter){
    starter = starter->next;
    i++;
  }
  return i;
}
TemplateClass void LinkedList<T>::exchg(int index1, int index2){
  Node<T> * first = this->get(index1);
  Node<T> * second = this->get(index2);
  Node<T> * swapper = &(first->air);
  first = second;
  second = swapper;
}
// subList(start, length)	//Returns a new list containing elements from a sub-range of this list.
TemplateClass LinkedList<T>* LinkedList<T>::subList(int start, int length){
  LinkedList<T> * list = new LinkedList();
  for(int i = start; i<=length; i++){
    list->add(this->get(i));
  }
  return list;
}
// toString()				//Converts the list to a printable string representation.
TemplateClass string LinkedList<T>::toString(){
  string output = "";
  for(int i = 0; i<this->size();i++){
    Node<T> * tempAir =(this->get(i));
    //string myCode = tempAir->code;
    output+=string("Code: ")+string(tempAir->code)+string(", Longitude: ")+to_string(tempAir->longitude)+string(", Latitude: ")+to_string(tempAir->latitude);
  }
  return output;
}
