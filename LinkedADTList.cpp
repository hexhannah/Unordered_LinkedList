#include <iostream>
#include "LinkedADTList.h"

//Function Name: LinkedADTList()
//Parameters: none
//Return: none
//Purpose: This is a default constructor for the class
//LinkedADTList and it sets length to 0, and sets
//the pointers cursor & length set to nullptr
//BigO: 1
template<class DataType>
LinkedADTList<DataType>::LinkedADTList() {
    length = 0;                           //set variables
    cursor = nullptr;
    start = nullptr;

}

//Function Name: LinkedADTList
//Parameters: const LinkedADTList<DataType> &rhs
//Return: none
//Purpose: This is a copy constructor for the
//LinkedADTList class it also sets the pointers cursor
//and start to nullptr but it sets length to rhs.length
//and it sets the linked list up with the while loop.
//BigO: n
template<class DataType>
LinkedADTList<DataType>::LinkedADTList(const LinkedADTList<DataType> &rhs) {
    cursor = nullptr;                           //sets variables
    start = nullptr;
    length = rhs.length;
    Node<DataType> *curr = new Node<DataType>;  //create new list
    curr = rhs.start;                           //point at start
    while (curr != nullptr) {                   //until reaches end
        this->putItem(curr->value);        //put item into curr position
        curr = curr->next;                      //increase curr to point to next position
    }
}

//Function Name: getLength()
//Parameters: none
//Return: int Length
//Purpose: This is an accessor function for the
//LinkedADTList lab and it accesses the value
//with private variable length
//BigO: 1
template<class DataType>
int LinkedADTList<DataType>::getLength() const{
    return length;                              //return value of length
}

//Function Name: putItem
//Parameters: const DataType &item
//Return: void
//Purpose: put the passed in "item" in the front of the linked
//list by creating a temporary node.
//BigO: 1
template<class DataType>
void LinkedADTList<DataType>::putItem(const DataType &item) {
    Node<DataType> *temp = new Node<DataType>;              //create a temp node
    temp->value = item;                                     //have that node point to item value
    temp->next = start;                                     //have that temp node point to start
    start = temp;                                           //start is now the same as the temp
    cursor = start; // j added                              //point cursor at the start
    length++;                                               //increase length
}

//Function Name: getItem
//Parameters: const DataType &item, DataType &found_item
//Return: bool
//Purpose: Cycle through linked list to find item, if found set that
//item to found item and return true. if not found return false.
//BigO:n
template<class DataType>
bool LinkedADTList<DataType>::getItem(const DataType &item, DataType &found_item) const{
    Node<DataType> *curr = start;                           //create new node
    while(curr!=nullptr){                                   //cycle thru until points at end
        if(curr->value == item){                            //if found value in linked list = item
            found_item=curr->value;                         //set found item to that value
            return true;                                    //successfully found
        }
        curr = curr->next;                                  //set curr to next to keep going thru list
    }
    return false;                                           //unsuccessfully found
}

//Function Name: isFull()
//Parameters: none
//Return: bool
//Purpose: Return false bc in our lab the linked list does not have
//a limit of length
//BigO: 1
template<class DataType>
bool LinkedADTList<DataType>::isFull() const {
    return false;
}

//Function Name: makeEmpty
//Parameters: none
//Return: void so none
//Purpose: Delete each node in the list, set length to 0,
//and set cursor to end/nullptr
//BigO: n
template<class DataType>
void LinkedADTList<DataType>::makeEmpty() {
    Node<DataType> *temp = nullptr;         //create temp
    while(start != nullptr){                //while not at the end of linked list
        temp = start;                       //set temp to be the same as start
        start = start->next;                //start is now the next node
        delete temp;                        //delete the previous node that temp was set to
    }
    length = 0;                             //length is now 0 after stops looping
    cursor = nullptr;                       //set cursor to end
}

//Function Name: deleteItem
//Parameters: const int &item
//Return: bool
//Purpose: delete node that contains the value equal to item
//BigO: n
template<class DataType>
bool LinkedADTList<DataType>::deleteItem(const int &item) {
    Node<DataType> *temp = start;                   //create temp node
    Node<DataType> *prev = nullptr;                 //create prev node
    while(temp!=nullptr){                           //while temp does not point to the end
        if(temp->value == item){                    //if value in a node is equal to param item
            if(temp == start){                      //if that value is at the beginning of the list
                start = start->next;                //set start to point to the next node
            }
            else{                                   //if value is NOT at the beginning
                prev->next=temp->next;              //set prev equal to the node
            }
            length--;                               //decrease length by 1
            delete temp;                            //delete temp with the value that was equal to item
            return true;                            //successfully deleted
        }
        prev = temp;                                //prev and temp are now equivalent
        temp = temp->next;                          //have temp point to the next node and keep iterating thru the list
    }
    return false;                                   //unsuccessful, did not find value that is = item
}

//Function Name: getNextItem
//Parameters: DataType &item
//Return: bool
//Purpose: Return the value of node of the cursor
//BigO:1
template<class DataType>
bool LinkedADTList<DataType>::getNextItem(DataType &item){
    if (cursor == nullptr){                         //is cursor is at the end, we cannot return a value
        return false;                               //unsuccessful
    }
    item = cursor->value;                           //have item be equal to value of the  node cursor is pointing to
    cursor = cursor->next;                          //have cursor now point to the next node
    return true;                                    //successfully finished
}

//Function Name: resetList()
//Parameters: none
//Return: void so none
//Purpose: set cursor to the start
//BigO:1
template<class DataType>
void LinkedADTList<DataType>::resetList() {
    cursor = start;                      //set cursor to the front
}

//Function Name: ~LinkedADTList
//Parameters: none
//Return: none
//Purpose: This is the Deconstructor for the LinkedADTList
//class this deletes every node and sets length to 0
//BigO:n
template<class DataType>
LinkedADTList<DataType>::~LinkedADTList() {

    Node<DataType>* temp;                   //create temp node

    while(start != nullptr) {               //when the list is not empty
        temp = start;                       //set temp to be the same as the start node
        start = temp->next;                 //start is now the 2nd node in the list
        delete temp;                        //delete temp, along with the beginning node
    }
    length = 0;                             //length is now 0
    cursor = nullptr;                       //cursor is end
}

//Function Name: operator=
//Parameters: const LinkedADTList<DataType> &rhs
//Return: void so none
//Purpose: overloaded operator definition for assignment operator(=)
//basically define what = means for an Abstract Data Type because
//our computer is unfamiliar with how to work with our man made data type
template<class DataType>
void LinkedADTList<DataType>::operator= (const LinkedADTList<DataType> &rhs) {
    makeEmpty();                                //empty linked list
    Node<DataType>* current=rhs.start;          //create current node equal to the start

    while (current != nullptr) {                //while current is not at end
        putItem(current->value);           //insert item with value
        current = current->next;                //set current to next node
    }

    length = rhs.length;                        //length is equal to the length
    resetList();                                //reset cursor
}



