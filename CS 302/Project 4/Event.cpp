#include "Event.h"

Event::Event():eventType('A'),eventTime(0),eventLength(0){}

Event::Event(char type,int time,int length):eventType(type),eventTime(time),eventLength(length){

}

bool operator>(Event e1,Event e2){
    if(e1.getTime() > e2.getTime()){
        return true;
    }else{
        return false;
    }

}

bool operator<(Event e1,Event e2){
    if(e1.getTime() < e2.getTime()){
        return true;
    }else{
        return false;
    }

}
Event& Event::operator=(const Event& e1){
    eventType = e1.getType();
    eventTime = e1.getTime();
    eventLength = e1.getLength();
}
const bool Event::operator==(const Event& e1){
    if(eventTime == e1.getTime() && eventType == 'D' && e1.getType() == 'A'){
        return true;
    }else{
        return false;
    }
}

const char Event::getType()const {return eventType;}
const int Event::getTime()const{return eventTime;}
const int Event::getLength()const {return eventLength;}
