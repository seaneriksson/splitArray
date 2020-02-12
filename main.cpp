#include <iostream>

using namespace std;

class UnsortedList
{
    private:;
        int listOfItems[5];
        int subListPart1[3];
        int subListPart2[2];
    public:
        void getItem(int item);
        void addItems(UnsortedList & list1, int item);
        void splitList(int);
        void printOriginalArray() const;
        void printSubListPart1() const;
        void printSubListPart2() const;
};

void UnsortedList::getItem(int itemWanted)
{
    //flag to identify if the item has been found
    bool itemFound = false;

    //counter used when searching for the item
    int step = 0;

    //search the array for the item
    while (step < 5)
    {
        if (listOfItems[step] == itemWanted)
         {
            itemFound = true;
            cout << "The item has been found" << endl;
            cout << listOfItems[step] << endl;
            break;
         }
        step++;  //increase the step until the item is found
    }

}

void UnsortedList::addItems(UnsortedList & list1, int item)
{
    //counter to keep track in the while loop
    int step = 0;

    while (step < 5)
    {
        list1.listOfItems[step] = item;
        step++;
        item++;
    }
}

void UnsortedList::splitList (int splitLocation)
{
    //flag to identify if the split location has been found
    bool itemFound = false;

    //counter for the while search
    int step = 0;

    //begin the search for the location
    while (step < 5)
    {
        if (listOfItems[step] == splitLocation)
         {
            itemFound = true;
            //cout << "The item has been found at step: " << step << endl;
            break;
         }
        step++;  //if not found move to the next step in the array
    }

    if (itemFound = false)
    {
        cout << "The item does not exist in the list" << endl;
    }

    //counter to keep track of place in the sub-lists
    int counterForSubListPart1 = 0;
    int counterForSubListPart2 = 0;

    if (itemFound = true)
    {
        while (counterForSubListPart1 <= step)
        {
            //write the items into sub list 1
            subListPart1[counterForSubListPart1] = listOfItems[counterForSubListPart1];
            counterForSubListPart1++;
        }
        while (counterForSubListPart1 > step && counterForSubListPart1 < 5)
        {
            //write the items in to sub list 2
            subListPart2[counterForSubListPart2] = listOfItems[counterForSubListPart1];
            counterForSubListPart2++;
            counterForSubListPart1++;
        }

    }
}



void UnsortedList::printOriginalArray() const
{
    int step = 0;
    while (step < 5)
    {
        cout << listOfItems[step] << endl;
        step++;
    }
    cout << "" << endl;
}

void UnsortedList::printSubListPart1() const
{
    cout << "Part 1 of the split list is: " << endl;

    int step = 0;
    while (step < 3)
    {
        cout << subListPart1[step] << endl;
        step++;
    }
    cout << "" << endl;
}

void UnsortedList::printSubListPart2() const
{
    cout << "Part 2 of the split list is: " << endl;

    int step = 0;
    while (step < 2)
    {
        cout << subListPart2[step] << endl;
        step++;
    }
    cout << "" << endl;
}



int main()
{
    //create the list object
    UnsortedList list1;

    //add the integers 1-5
    list1.addItems(list1, 1);

    //print out the original list
    cout << "The original list is: " << endl;
    list1.printOriginalArray();

    //split the list at 3
    list1.splitList(3);

    //print out the split lists
    list1.printSubListPart1();
    list1.printSubListPart2();

    return 0;
}
