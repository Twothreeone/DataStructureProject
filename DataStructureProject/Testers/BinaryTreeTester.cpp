//
//  BinaryTreeTester.cpp
//  DataStructureProject
//
//  Created by Charlesworth, Benjamin on 3/27/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#include "BinaryTreeTester.hpp"

void BinaryTreeTester :: doTreeStuff()
{
    intTree.insert(3);
    intTree.insert(1);
    intTree.insert(2);
    intTree.insert(-3246000);
    intTree.insert(-12);
    intTree.insert(7);
    intTree.insert(5);
    intTree.insert(8);
    intTree.insert(9001);
    intTree.demoTraversalSteps();
    cout << endl;
    intTree.inOrderTraversal();
    cout << endl;
    intTree.preOrderTraversal();
    cout << endl;
    intTree.postOrderTraversal();
    cout << endl;
    stringTree.insert("hello");
    stringTree.insert("this");
    stringTree.insert("is");
    stringTree.insert("some");
    stringTree.insert("data");
    stringTree.insert("for");
    stringTree.insert("a");
    stringTree.insert("tree");
    stringTree.demoTraversalSteps();
    cout << endl;
    stringTree.inOrderTraversal();
    cout << endl;
    stringTree.preOrderTraversal();
    cout << endl;
    stringTree.postOrderTraversal();
    cout << endl;
}
