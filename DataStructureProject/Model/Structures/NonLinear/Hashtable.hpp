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
    return -1;
}

template <class Type>
bool Hashtable<Type> :: isPrime(long current)
{
    return false;
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
    
}

template <class Type>
long Hashtable<Type> :: getSize()
{
    return this->size;
}

#endif /* Hashtable_hpp */
