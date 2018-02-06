//
//  ArrayTester.cpp
//  DataStructureProject
//
//  Created by Charlesworth, Benjamin on 2/6/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#include "ArrayTester.hpp"

void ArrayTester :: testArrayUse()
{
    Array<int> firstArray(10);
    for (int i = 0; i < 10; i++)
    {
        firstArray.setAtIndex(i, i);
    }
    for (int i = 0; i < firstArray.getSize(); i++)
    {
        cout << firstArray[i] << endl;
    }
    Array<int> secondArray(400);
    cout << secondArray.getSize() << endl;
    cout << firstArray.getSize() << endl;
    Array<int> thirdArray(secondArray);
    cout << thirdArray.getSize() << endl;
    firstArray = thirdArray;
    cout << firstArray[4] << endl;
    thirdArray[5] = 123;
    cout << thirdArray[5] << endl;
}

void ArrayTester :: testAdvancedArray()
{
    Array<int> testArray(5);
    if (testArray.getSize() == 5)
    {
        cout << "getSize works" << endl;
    }
    testArray.setAtIndex(1, 5);
    if (testArray.getFromIndex(1) == 5)
    {
        cout << "setAtIndex and getFromIndex work" << endl;
    }
}
