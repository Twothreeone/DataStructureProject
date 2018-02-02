//
//  Controller.cpp
//  DataStructureProject
//
//  Created by Charlesworth, Benjamin on 1/31/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#include "Controller.hpp"

using namespace std;

void Controller :: start()
{
    Timer codeTimer;
    codeTimer.startTimer();
    codeTimer.stopTimer();
    codeTimer.displayInformation();
    codeTimer.resetTimer();
    codeTimer.startTimer();
    vector<CrimeData> myData = FileController :: readCrimeDataToVector("/Users/bcha1422/Documents/C++ Projects/DataStructureProject/DataStructureProject/Data/crime.csv");
    codeTimer.stopTimer();
    codeTimer.displayInformation();
    for (int i = 200; i <= 215; i++)
    {
        cout << i << " is " << myData[i] << endl;
    }
}

void Controller :: findMaxAndMin()
{
    Timer searchTimer;
    searchTimer.startTimer();
    vector<CrimeData> myData = FileController :: readCrimeDataToVector("/Users/bcha1422/Documents/C++ Projects/DataStructureProject/DataStructureProject/Data/crime.csv");
    int minIndex = 0;
    int maxIndex = 0;
    for (int i = 1; i < myData.size(); i++)
    {
        if (myData[minIndex] > myData[i])
        {
            minIndex = i;
        }
        if (myData[maxIndex] < myData[i])
        {
            maxIndex = i;
        }
    }
    searchTimer.stopTimer();
    cout << "The smallest Crime stat is at " << minIndex << " and it is: " << myData[minIndex] << endl;
    cout << "The largest Crime stat is at " << maxIndex << " and it is: " << myData[maxIndex] << endl;
    searchTimer.displayInformation();
}
