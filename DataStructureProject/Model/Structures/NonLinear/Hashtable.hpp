//
//  Hashtable.hpp
//  DataStructureProject
//
//  Created by Charlesworth, Benjamin on 4/27/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef Hashtable_hpp
#define Hashtable_hpp

#include "../Nodes/HashNode.hpp"
#include <cmath>
#include <assert.h>

template <class Type>
class Hashtable
{
private:
    HashNode<Type>** internalStorage;
    long size;
    long capacity;
    double loadFactor;
    long getNextPrime();
    bool isPrime(long current);
    void resize();
    long findPosition(HashNode<Type>* insertedNode);
    long handleCollision(long index);
public:
    Hashtable();
    ~HashTable();
    void insert(Type data);
    long getSize();
    HashNode<Type> * get(long index);
    bool contains(HashNode<Type> * value);
};

template <class Type>
Hashtable<Type> :: Hashtable()
{
    capacity = 101;
    internalStorage = new HashNode<Type>*[capacity];
    size = 0;
    loadFactor = .80;
}

template <class Type>
Hashtable<Type> :: ~Hashtable()
{
    delete [] internalStorage;
}

template <class Type>
long Hashtable<Type> :: getNextPrime()
{
    long nextPrime = (this->capacity * 2) + 1;
    while (!isPrime(nextPrime))
    {
        nextPrime += 2;
    }
    return nextPrime;
}

template <class Type>
bool Hashtable<Type> :: isPrime(long current)
{
    if (current <= 1)
    {
        return false;
    }
    else if (current == 2 || current == 3)
    {
        return true;
    }
    else if (current % 2 == 0)
    {
        return false;
    }
    else
    {
        for (int next = 3; next <= sqrt(current) + 1; next += 2)
        {
            if (current % next == 0)
            {
                return false;
            }
        }
        return true;
    }
}

template <class Type>
void Hashtable<Type> :: resize()
{
    long updatedCapacity = getNextPrime();
    HashNode<Type> ** tempStorage = new HashNode<Type> * [updatedCapacity];
    std :: fill_n(tempStorage, updatedCapacity, nullptr);
    long oldCapacity = this->capacity;
    this->capacity = updatedCapacity;
    for (long i = 0; i < oldCapacity; i++)
    {
        if (internalStorage[i] != nullptr)
        {
            HashNode<Type> * temp = internalStorage[i];
            long position = findPosition(temp);
            if (tempStorage[position] == nullptr)
            {
                tempStorage[position] = temp;
            }
            else
            {
                long updatedPosition = handleCollision(position);
                if (updatedPosition != -1)
                {
                    tempStorage[updatedPosition] = temp;
                }
            }
        }
    }
    internalStorage = tempStorage;
}

template <class Type>
long Hashtable<Type> :: findPosition(HashNode<Type>* insertedNode)
{
    long insertPosition = insert->getKey() % this->capacity;
    return insertPosition;
}

template <class Type>
long Hashtable<Type> :: handleCollision(long index)
{
    long shift = 17;
    for (long i = index + shift; i != index; i += shift)
    {
        if (i >= capacity)
        {
            i = i % capacity;
        }
        if (internalStorage[i] == nullptr)
        {
            return i;
        }
    }
    return -1;
}

template <class Type>
void Hashtable<Type> :: insert(Type data)
{
    this->size++;
    if (((this->size * 1.000) / this->capacity) > this->loadFactor)
    {
        resize();
    }
    HashNode<Type> * temp = new HashNode<Type>(value);
    long index = findPosition(temp);
    if (internalStorage[index] == nullptr)
    {
        internalStorage[index] = temp;
    }
    else
    {
        long updatedPosition = handleCollision(index);
        if (updatedPosition != -1)
        {
            internal[updatedPosition] = temp;
        }
    }
}

template <class Type>
HashNode<Type> * Hashtable<Type> :: get(long index)
{
    assert(index < capacity);
    return internalStorage[index];
}

template <class Type>
bool Hashtable<Type> :: contains(HashNode<Type> * value)
{
    if (internalStorage[findPosition(value)]->getData() == value->getData())
    {
        return true;
    }
    long other = handleCollision(findPosition(value));
    if (internalStorage[other]->getData() == value->getData())
    {
        return true;
    }
    return false;
}

template <class Type>
long Hashtable<Type> :: getSize()
{
    return this->size;
}

#endif /* Hashtable_hpp */
