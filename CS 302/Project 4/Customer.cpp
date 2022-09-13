#include "Customer.h"

Customer::Customer():arrivalTime(0),duration(0){}

Customer::Customer(int time,int length):arrivalTime(time),duration(length){}

const int Customer::getArrivalTime()const{return arrivalTime;}

const int Customer::getDuration()const{return duration;}
