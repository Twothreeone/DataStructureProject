//
//  LinkedListTester.cpp
//  DataStructureProject
//
//  Created by Charlesworth, Benjamin on 2/14/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#include "LinkedListTester.hpp"

using namespace std;

void LinkedListTester :: testListBasics()
{
    LinkedList<int> numbers;
    numbers.add(9);
    cout << numbers.getFront()->getData() << " is at the front of the list and should be 9" << endl;
    cout << numbers.getEnd()->getData() << " is at the end of the list and should be 9" << endl;
    numbers.add(0);
    cout << numbers.getFront()->getData() << " is at the front of the list and should be 9" << endl;
    cout << numbers.getEnd()->getData() << " is at the end of the list and should be 0" << endl;
    numbers.addAtIndex(1, 2);
    numbers.add(324);
    cout << numbers.getFront()->getData() << " is at the front of the list and should be 9" << endl;
    cout << numbers.getEnd()->getData() << " is at the end of the list and should be 324" << endl;
    cout << "This loop should print 4 lines" << endl;
    for (int i = 0; i < numbers.getSize(); i++)
    {
        cout << numbers.getFromIndex(i) << endl;
    }
    numbers.remove(0);
    numbers.add(32567);
    numbers.addAtIndex(0, 2312);
    cout << numbers.getFront()->getData() << " is at the front of the list and should be 2312" << endl;
    cout << numbers.getEnd()->getData() << " is at the end of the list and should be 32567" << endl;
    
    LinkedList<string> words;
    words.add("hi");
    cout << words.getFront()->getData() << " is at the front of the list and should be hi" << endl;
    cout << words.getEnd()->getData() << " is at the end of the list and should be hi" << endl;
    words.add("bye");
    cout << words.getFront()->getData() << " is at the front of the list and should be hi" << endl;
    cout << words.getEnd()->getData() << " is at the end of the list and should be bye" << endl;
    words.addAtIndex(1, "word");
    words.add("thing");
    cout << words.getFront()->getData() << " is at the front of the list and should be hi" << endl;
    cout << words.getEnd()->getData() << " is at the end of the list and should be thing" << endl;
    cout << "This loop should print 4 lines" << endl;
    for (int i = 0; i < words.getSize(); i++)
    {
        cout << words.getFromIndex(i) << endl;
    }
    words.remove(0);
    words.add("asdfjkl;");
    words.addAtIndex(0, ";lkjfdsa");
    cout << words.getFront()->getData() << " is at the front of the list and should be ;lkjfdsa" << endl;
    cout << words.getEnd()->getData() << " is at the end of the list and should be asdfjkl;" << endl;
}

void LinkedListTester :: testListWithData()
{
    Timer listTimer;
    
    listTimer.startTimer();
    LinkedList<CrimeData> crimes = FileController :: readDataToList("/Users/bcha1422/Documents/C++ Projects/DataStructureProject/DataStructureProject/Data/crime.csv");
    
    listTimer.stopTimer();
    cout << "This is how long it took to read the structure into our custom data structure" << endl;
    listTimer.displayInformation();
    
    listTimer.resetTimer();
    cout << "Here is how long it takes to access a random data value" << endl;
    listTimer.startTimer();
    int randomLocation = (rand() * rand()) % crimes.getSize();
    cout << "The random index is: " << randomLocation << endl;
    double totalViolentRate = crimes.getFromIndex(randomLocation).getAllViolentRates();
    listTimer.stopTimer();
    cout << "The random crimes stat is: " << totalViolentRate << " , and here is the timer" << endl;
    listTimer.displayInformation();
}

