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

template <class Type>
Array<Type> :: Array(int size)
{
    assert(size > 0);
    this->size = size;
    internalArray = new Type[size];
}

template <class Type>
Array<Type> :: Array(const Array<Type> & toCopy)
{
    this->size = toCopy.getSize();
    internalArray = new Type[size];
    for(int i = 0; i < size; i++)
    {
        internalArray[i] = toCopy[i];
    }
}

template <class Type>
Array<Type> :: ~Array()
{
    delete [] internalArray;
}


#endif /* Array_hpp */
