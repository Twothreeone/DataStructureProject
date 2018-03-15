//
//  SortingTester.cpp
//  DataStructureProject
//
//  Created by Charlesworth, Benjamin on 3/15/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#include "SortingTester.hpp"

void SortingTester :: quickSort(vector<CrimeData> & data, int low, int high)
{
    if (low < high)
    {
        int partitionPoint = partition(data, low, high);
        quickSort(data, low, partitionPoint - 1);
        quickSort(data, partitionPoint + 1, high);
    }
}

int SortingTester :: partition(vector<CrimeData> & data, int low, int high)
{
    CrimeData pivotValue = data[high];
    int smallest = low - 1;
    for (int i = low; i < high - 1; i++)
    {
        if (data[i] < pivotValue)
        {
            smallest++;
            swap(data, smallest, i);
        }
    }
    swap(data, smallest + 1, high);
    return smallest + 1;
}

void SortingTester :: swap(vector<CrimeData> & data, int low, int high)
{
    CrimeData temp = data[low];
    data[low] = data[high];
    data[high] = temp;
    swapCount++;
}

void SortingTester :: testSorts()
{
    Timer sortTimer;
    swapCount = 0;
    vector<CrimeData> data = FileController::readCrimeDataToVector("/Users/bcha1422/Documents/C++ Projects/DataStructureProject/DataStructureProject/Data/crime.csv");
    vector<CrimeData> smaller;
    for (int i = 0; i < 10000; i++)
    {
        smaller.push_back(data[i]);
    }
    sortTimer.startTimer();
    quickSort(smaller, 0, smaller.size());
    sortTimer.stopTimer();
    sortTimer.displayInformation();
    cout << "The number of swaps were: " << swapCount << endl;
}
