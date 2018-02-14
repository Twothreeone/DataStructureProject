//
//  LinkedListTester.hpp
//  DataStructureProject
//
//  Created by Charlesworth, Benjamin on 2/14/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef LinkedListTester_hpp
#define LinkedListTester_hpp

#include "../Model/Structures/LinkedList.hpp"
#include "../Controller/FileController.cpp"
#include "../Controller/Tools/Timer.hpp"
#include "../Data/CrimeData.hpp"
#include <iostream>

class LinkedListTester
{
public:
    void testListBasics();
    void testListWithData();
};

#endif /* LinkedListTester_hpp */
