#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

#include<iostream>


class Customer{
public:
    Customer();
    Customer(int arrivalTime,int duration);

    const int getArrivalTime()const;
    const int getDuration()const;

private:
    int arrivalTime;
    int duration;
};

#endif // CUSTOMER_H_INCLUDED
