#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED

#include <iostream>

class Event{
public:
    Event();
    Event(char type,int time,int length);

    friend bool operator>(Event& e1,Event& e2);
    friend bool operator<(Event& e1,Event& e2);
    Event& operator=(const Event& e1);
    const bool operator==(const Event& e1);

    const char getType()const;
    const int getTime()const;
    const int getLength()const;

private:
    char eventType;
    int eventTime;
    int eventLength;
};


#endif // EVENT_H_INCLUDED
