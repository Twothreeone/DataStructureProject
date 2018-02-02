//
//  Array.hpp
//  DataStructureProject
//
//  Created by Charlesworth, Benjamin on 2/2/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef Array_hpp
#define Array_hpp

#include <assert.h>
#include <iostream>

using namespace std;

template <class Type>
class Array
{
private:
    Type * internalArray;
    int size;
public:
    Array<Type>(int size);
    Array<Type>(const Array<Type> & toCopy);
    ~Array<Type>();
    Array<Type> & operator = (const Array<Type> & toReplace);
    Type& operator [] (int index);
    Type operator [] (int index) const;
    int getSize() const;
    Type getFromIndex(int index);
    void setAtIndex(int index, Type data);
}

#endif /* Array_hpp */
