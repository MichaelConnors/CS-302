#include <fstream>
#include "Customer.cpp"
#include "Event.cpp"
#include "Queue.cpp"
#include "PriorityQueue.cpp"

using namespace std;

int main(){

    ifstream infile;
    int arrivalTime = 0;
    int transactionLength = 0;
    int currentTime = 0;
    int departureTime = 0;
    int totalTime = 0;
    int processingTime = 0;
    double waitTime = 0.0;
    int events = 0;
    int dTime = 0;
    bool tellerOpen = true;
    PriorityQueue<Event> eventQueue;
    Queue<Customer> customerQueue;

    infile.open("inputFile.txt");

    while(!infile.eof()){

            infile >> arrivalTime >> transactionLength;

            Event tmp_event('A',arrivalTime,transactionLength);
            eventQueue.enqueue(tmp_event);
    }
    infile.close();
    cout << "Simulation Begins" << endl;
    while(!eventQueue.isEmpty()){
        Event newEvent = eventQueue.front();
        currentTime = newEvent.getTime();
        if(newEvent.getType() == 'A'){

                eventQueue.dequeue();
                Customer customer(newEvent.getTime(),newEvent.getLength());
                if(customerQueue.isEmpty() && tellerOpen){
                    departureTime = currentTime + newEvent.getLength();
                    Event dEvent('D',departureTime,0);
                    eventQueue.enqueue(dEvent);
                    tellerOpen = false;
                }else{
                    customerQueue.enqueue(customer);
                }
        cout << "Processing an Arrival Event at time: " << customer.getArrivalTime() << endl;
        events++;
        totalTime += customer.getArrivalTime();
        processingTime += customer.getDuration();
    }else{
            eventQueue.dequeue();
            if(!customerQueue.isEmpty()){
                Customer customer = customerQueue.front();
                customerQueue.dequeue();
                departureTime = currentTime + customer.getDuration();
                Event dEvent('D',departureTime,0);
                eventQueue.enqueue(dEvent);
                cout << "Processing a Departure event at time: " << currentTime << endl;
                dTime += currentTime;
            }else{
                tellerOpen = true;
            }

    }
    }

    cout << "Simulation ends" << endl;

    waitTime = (double)(dTime - (processingTime - totalTime))/events;
    cout << endl << "Final Statistics: " << endl;
    cout << "Total Number of customers: " << events << endl;
    cout << "Average Customer Wait Time: " << waitTime << endl;
}
