//
//  LinkedList.hpp
//  DataStructureProject
//
//  Created by Charlesworth, Benjamin on 2/14/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include "List.hpp"

using namespace std;

template <class Type>
class LinkedList : public List<Type>
{
protected:
    LinearNode<Type> * front;
    LinearNode<Type> * end;
public:
    LinkedList();
    virtual ~LinkedList();
    int getSize() const;
    LinearNode<Type> * getFront();
    LinearNode<Type> * getEnd();
    void add(Type item);
    void addAtIndex(int index, Type item);
    Type getFromIndex(int index);
    Type remove(int index);
};



#endif /* LinkedList_hpp */
