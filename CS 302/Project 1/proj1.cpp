#include "LinkedList.cpp"

using namespace std;

int main(){
    LinkedList<int> list1;
    int userInput = 0;
    bool runFlag = true;

    while(runFlag){
        cout << "Linked List Manipulation Menu" << endl <<
        "=============================" << endl <<
        "[1] Add an Item" << endl <<
        "[2] Remove an Item" << endl <<
        "[3] Display List Data" << endl <<
        "[4] Display List Size" << endl <<
        "[5] Exit Program" << endl <<
        "Select an option: ";
        cin >> userInput;
        if(userInput >= 1 && userInput <= 5){
            switch(userInput){
            case 1:
                cout << "Please enter an Item: ";
                cin >> userInput;
                list1.add(userInput);
                break;
            case 2:
                cout << endl << list1 << "Which item would you like to remove? ";
                cin >> userInput;
                list1.remove(userInput);
                break;
            case 3:
                cout << list1;
                break;
            case 4:
                cout << "The list contains " << list1.size() << " item(s)." << endl;
                break;
            case 5:
                cout << endl << "Goodbye :)" << endl;
                runFlag = false;
                break;
            default:
                cout << "Something went wrong :(" << endl;
            }
        }
    }

}
