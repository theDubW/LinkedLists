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



class Airport
{
public:
    char    code[5];
    double   longitude;
    double   latitude;
    string toString(){
      string output = "";
      output = string("Code: ")+string((this)->code)+string(", Longitude: ")+to_string((this)->longitude)+string(", Latitude: ")+to_string((this)->latitude);
      return output;
    }
    bool equals(Airport * air){
      if(air->code!=this->code)
        return false;
      if(air->longitude!=this->longitude)
        return false;
      if(air->latitude!=this->latitude)
        return false;
      return true;
    }

};
void mergeSort(Node<Airport> ** headRef);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);
LinkedList<Airport> * link = new LinkedList<Airport>();

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
            c->latitude = atof(cNum);
            infile.getline(cNum, 256, '\n');
            c->longitude = atof(cNum);
            link->add(c);
            i++ ;
            c++;
        }
        airportCount = c-1;
        infile.close();
      mergeSort(&(link->head));
      int j = 13428;
      cout<<"Farthest Airport: "<<(link->get(j))->toString()<<", Distance: "<< 0.621371*distanceEarth(30.1944, 97.67, (link->get(j))->longitude, (link->get(j))->latitude)<<endl;
      printf("% 10s\n", "Airports Within 100 Miles: ");
      for(i = 0; i<link->size();i++){
          //cout<<"WTF";
          double longitudeA = (link->get(i))->longitude;
          double latitudeA = (link->get(i))->latitude;
          double distanceInMiles = distanceEarth(30.1944, 97.6700, latitudeA, longitudeA)/1.61;
          if(distanceInMiles<=100.0)
            cout<<i+1<<". "<<(link->get(i))->toString()<<", Distance in Miles: "<<distanceInMiles<<endl;
          else
            break;
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
void FrontBackSplit(Node<Airport> * source, Node<Airport>** front, Node<Airport> ** back){
  Node<Airport> * fast;
  Node<Airport> * slow;
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
  Node<Airport> * sortedMerge(Node<Airport> * a, Node<Airport> *b){
  Node<Airport> * result = NULL;
  if(a==NULL) return(b);
  else if(b==NULL) return(a);
  double longitudeA = (a)->data->longitude;
  double latitudeA = (a)->data->latitude;
  double longitudeB = (b)->data->longitude;
  double latitudeB = (b)->data->latitude;
  double distanceA = distanceEarth(30.1944, 97.6700, latitudeA, longitudeA)/1.61;
  double distanceB = distanceEarth(30.1944, 97.6700, latitudeB, longitudeB)/1.61;
  if(distanceA<=distanceB){
    result = a;
    result->next = sortedMerge(a->next, b);
  }else{
    result = b;
    result->next = sortedMerge(a, b->next);
  }
  return result;
}
void mergeSort(Node<Airport> ** headRef){
  Node<Airport> * head = *headRef;
  Node<Airport> * a;
  Node<Airport> * b;
  if(head==NULL||head->next==NULL){
    return;
  }
    FrontBackSplit(head, &a, &b);
    mergeSort(&a);
    mergeSort(&b);
    *headRef = sortedMerge(a, b);
}
