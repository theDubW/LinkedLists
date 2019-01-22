#include "slist.h"
#include <string>
#include <iostream>
using namespace std;
/*

Class Library File

*/

string Node::toString(){
  string output = "";
  output = string("Code: ")+string((this->air)->code)+string(", Longitude: ")+to_string((this->air)->longitude)+string(", Latitude: ")+to_string((this->air)->latitude);
  return output;
}
// Constructor
LinkedList::LinkedList(){
    this->length = 0;
    this->head = NULL;
}
// Destructor
LinkedList::~LinkedList(){
   Node* current = this->head;
    while(current){
        this->head = current->next;
        this->length -= 1;
		    delete current;
		    current = this->head;
    }
    cout << "LIST DELETED: " << this->length << endl;
}
// add(value)				//Adds a new value to the end of this list.
void LinkedList::add(Airport * airport){
  Node * head = this->head;
  Node * addedElement = new Node;
  addedElement->air = airport;
  addedElement->next = NULL;
  if(this->length == 0){
    this->head = addedElement;
  }
  else{
    get((this->length)-1)->next = addedElement;
  }
  this->length++;
}
// clear()					//Removes all elements from this list.
void LinkedList::clear(){
    Node* current = this->head;
    current = current->next;
    int index = (this->length)-1;
    while(current->next){
      delete current;
      current = current->next;
    }
    std::cout << "LIST DELETED: " << this->length << std::endl;
}
// equals(list)				//Returns true if the two lists contain the same elements in the same order.
bool LinkedList::equals(LinkedList * linked){
  Node * current = this->head;
  Node * compared = linked->head;
  if(this->length!=linked->length){
    return false;
  }
  for(int i = 0; i<this->length;i++){
    Node * list1 = this->get(i);
    Node * list2 = linked->get(i);
    Airport * air1 = list1->air;
    Airport * air2 = list2->air;
    if(air1->code!=air2->code){
      return false;
    }
  }
  return true;
}
//get(index)				//Returns the element at the specified index in this list.
Node* LinkedList::get(int index){
  Node * head = this->head;
  int i = 0;
  while(i<=index){
    if(i==index){
      return head;
    }
    head = head->next;
    i++;
  }
  return NULL;
}
//insert(index, value)		//Inserts the element into this list before the specified index.
void LinkedList::insert(int index, Node * node){
  Node * head = this->head;
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
void LinkedList::exchg(int index1, int index2){
  Node * first = this->get(index1);
  Node * second = this->get(index2);
  Airport * swapper = first->air;
  first->air = second->air;
  second->air = swapper;
}
//swap(index1,index2)		//Swaps node located at index1 with node at index2
void LinkedList::swap(int index1, int index2){
  int smallerIndex = index1<index2?index1:index2;
  int largerIndex = index2>index1?index2:index1;
  if(abs(index1-index2)==1){
      Node * first = this->get(smallerIndex);
      Node * second = this->get(largerIndex);
      first->next = second->next;
      second->next = first;
      if(index1==0){
        this->head = second;
      }else{
        Node * beforeFirst = this->get(smallerIndex-1);
        beforeFirst->next = second;
      }
  }else{
      Node * first = this->get(smallerIndex);
      Node * second = this->get(largerIndex);
      Node * swapper = first->next;
      first->next = second->next;
      second->next = swapper;
      if(smallerIndex==0){
        this->head = second;
        Node * pointToSecond = this->get(largerIndex-1);
        pointToSecond->next = first;
      }else{
        Node * pointToFirst = this->get(smallerIndex-1);
        Node * pointToSecond = this->get(largerIndex-1);
        pointToFirst->next = second;
        pointToSecond->next = first;
      }
  }
}
// isEmpty()				//Returns true if this list contains no elements.
bool LinkedList::isEmpty(){
  return this->head==NULL?true:false;
}
// remove(index)			//Removes the element at the specified index from this list.
void LinkedList::remove(int index){
  Node * toBeDeleted = this->get(index);
  if(this->size()==1){
    this->head = NULL;
    delete(toBeDeleted);
  }
  else if(index==0){
    this->head = toBeDeleted->next;
    delete(toBeDeleted);
  }else if(toBeDeleted->next == NULL){
    Node * oneLess = this->get(index-1);
    oneLess->next = NULL;
    delete(toBeDeleted);
  }else{
    Node * oneLess = this->get(index-1);
    oneLess->next = toBeDeleted->next;
    delete(toBeDeleted);
  }
}
// set(index, value)		//Replaces the element at the specified index in this list with a new value.
void LinkedList::set(int index,  Airport * air){
  Node * changeValue = this->get(index);
  changeValue->air = air;
}
// size()					//Returns the number of elements in this list.
int LinkedList::size(){
  int i = 0;
  Node * starter = this->head;
  while(starter){
    starter = starter->next;
    i++;
  }
  return i;
}
// subList(start, length)	//Returns a new list containing elements from a sub-range of this list.
LinkedList * LinkedList::subList(int start, int length){
  LinkedList * list = new LinkedList();
  for(int i = start; i<=length; i++){
    list->add((this->get(i))->air);
  }
  return list;
}
// toString()				//Converts the list to a printable string representation.
string LinkedList::toString(){
  string output = "";
  for(int i = 0; i<this->size();i++){
    Airport * tempAir =(this->get(i))->air;
    //string myCode = tempAir->code;
    output+=string("Code: ")+string(tempAir->code)+string(", Longitude: ")+to_string(tempAir->longitude)+string(", Latitude: ")+to_string(tempAir->latitude);
  }
  return output;
}
