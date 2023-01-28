#ifndef NODE
#define NODE
template <class DataType>
struct Node {
    DataType value;
    Node<DataType>* next;
};
#endif


#ifndef UNSORTED_LISTS_LINKEDADTLIST_H
#define UNSORTED_LISTS_LINKEDADTLIST_H

template <class DataType>
class LinkedADTList {

public:

    LinkedADTList();
    LinkedADTList(const LinkedADTList<DataType> &rhs);
    ~LinkedADTList();

    int getLength() const;
    void putItem(const DataType &item);
    bool getItem(const DataType &item, DataType &found_item) const;
    bool isFull() const;
    void makeEmpty();
    bool deleteItem(const int &item);
    bool getNextItem(DataType &item); //delete const in cpp too!!
    void resetList();
    void operator=(const LinkedADTList<DataType>&rhs);


private:
    Node<DataType>* start = nullptr;
    long length = 0;                  // Use this property to keep track of the list length
    Node<DataType>* cursor = start;   // Use this property only in getNextItem and Reset list
};




#endif //UNSORTED_LISTS_LINKEDADTLIST_H
