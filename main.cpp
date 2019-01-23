//
//  main.cpp
//  LLTemplate
//
//  Created by James Shockey on 12/6/16.
//  Copyright © 2016 James Shockey. All rights reserved.
//


/*
 *
 *	Linked List lab.
 *	- Build a library for singly linked list.
 *	- Replace the airport array in main with a Linked List.
 *  - sort the array.
 *
 */
#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0
#include <iostream>
#include <fstream>
#include <cmath>
#include "slist.h"

using namespace std;




void simpleSortTotal(LinkedList* s, int c);
void mergeSort(Node ** headRef);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);
LinkedList * link = new LinkedList();

int main()
{
    ifstream infile;
    int i=0;
    char cNum[10] ;
    // Replace array with Linked List
    int   airportCount;
  //  Airport* airportArr[13500];

    infile.open ("./USAirportCodes.csv", ifstream::in);
    if (infile.is_open())
    {
        int   c=0;
        while (infile.good())
        {
            Airport * c = new Airport();
            infile.getline(c->code, 256, ',');
            infile.getline(cNum, 256, ',');
            c->longitude = atof(cNum);
            infile.getline(cNum, 256, '\n');
            c->latitude = atof(cNum);
            link->add(c);
            i++ ;
            c++;
        }
        airportCount = c-1;
        infile.close();
      mergeSort(&(link->head));
      cout<<link->size()<<endl;
      int j = 13428;
      cout<<"Farthest Airport: "<<link->get(j)->toString()<<", Distance: "<< 0.621371*distanceEarth(30.1944, 97.67, ((link->get(j))->air)->longitude, ((link->get(j))->air)->latitude  )<<endl;
      printf("% 10s\n", "Airports Within 100 Miles: ");
      int g = 1;
      for(i = 0; i<=link->size();i++){
          //cout<<"WTF";
          double distanceInMiles = 0.621371*distanceEarth(30.1944, 97.67, ((link->get(i))->air)->longitude, ((link->get(i))->air)->latitude);
          if(distanceInMiles>100.0) break;
          cout<<g<<". "<<link->get(i)->toString()<<", Distance in Miles: "<<distanceInMiles<<endl;
          g++;
        }


    }
    else
    {
        cout << "Error opening file";
    }




}

// This function converts decimal degrees to radians
double deg2rad(double deg) {
  return (deg * pi / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
  return (rad * 180 / pi);
}


/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}


/*
	Provide sort routine on linked list
*/
void FrontBackSplit(Node * source, Node** front, Node ** back){
  Node * fast;
  Node * slow;
  slow = source;
  fast = source->next;
  while(fast!=NULL){
    fast = fast->next;
    if(fast!=NULL){
      slow = slow->next;
      fast = fast->next;
    }
  }
  *front = source;
  *back = slow->next;
  slow->next = NULL;
}
Node * sortedMerge(Node * a, Node *b){
  Node * result = NULL;
  if(a==NULL) return(b);
  else if(b==NULL) return(a);
  double distanceA = distanceEarth(30.197, 97.66, (a->air)->longitude, (a->air)->latitude);
  double distanceB = distanceEarth(30.197, 97.66, (b->air)->longitude, (b->air)->latitude);
  if(distanceA<=distanceB){
  //  cout<<"AM SORTING>>>   ";
    result = a;
    result->next = sortedMerge(a->next, b);
  }else{
    result = b;
    result->next = sortedMerge(a, b->next);
  }
  return result;
}
void mergeSort(Node ** headRef){
  Node * head = *headRef;
  Node * a;
  Node * b;
  if(head==NULL||head->next==NULL){
    return;
  }
    FrontBackSplit(head, &a, &b);
    mergeSort(&a);
    mergeSort(&b);
    *headRef = sortedMerge(a, b);
}
