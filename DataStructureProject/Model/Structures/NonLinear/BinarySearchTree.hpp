//
//  BinarySearchTree.hpp
//  DataStructureProject
//
//  Created by Charlesworth, Benjamin on 3/29/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include "Tree.hpp"
#include <iostream>

using namespace std;

template <class Type>
class BinarySearchTree : public Tree<Type>
{
protected:
    int calculateSize(BinaryTreeNode<Type> * startNode);
    int calculateHeight(BinaryTreeNode<Type> * startNode);
    bool isBalanced(BinaryTreeNode<Type> * startNode);
    bool isComplete(BinaryTreeNode<Type> * startNode, int index, int size);
    void inOrderTraversal(BinaryTreeNode<Type> * inStart);
    void preOrderTraversal(BinaryTreeNode<Type> * preStart);
    void postOrderTraversal(BinaryTreeNode<Type> * postStart);
    void demoTraversalSteps(BinaryTreeNode<Type> * start);
    BinaryTreeNode<Type> * getRightMostChild(BinaryTreeNode<Type> * current);
    BinaryTreeNode<Type> * getLeftMostChild(BinaryTreeNode<Type> * current);
    void removeNode(BinaryTreeNode<Type> * removeMe);
    void destroyTree(BinaryTreeNode<Type> * node);
public:
    BinarySearchTree();
    ~BinarySearchTree();
    BinaryTreeNode<Type> * getRoot();
    void setRoot(BinaryTreeNode<Type> * root);
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
    void demoTraversalSteps();
    int getSize();
    int getHeight();
    bool isComplete();
    bool isBalanced();
    bool contains(Type value);
    void insert(Type itemToInsert);
    void remove(Type value);
    Type findMinimum();
    Type findMaximum();
};

template <class Type>
BinarySearchTree<Type> :: BinarySearchTree()
{
    this->root = nullptr;
}

template <class Type>
BinarySearchTree<Type> :: ~BinarySearchTree()
{
    destroyTree(this->root);
}

template <class Type>
void BinarySearchTree<Type> :: destroyTree(BinaryTreeNode<Type> * node)
{
    if (node != nullptr)
    {
        destroyTree(node->getLeftNode());
        destroyTree(node->getRightNode());
        delete node;
    }
}

template <class Type>
BinaryTreeNode<Type> * BinarySearchTree<Type> :: getRoot()
{
    return nullptr;
}

template <class Type>
void BinarySearchTree<Type> :: setRoot(BinaryTreeNode<Type> * root)
{
    
}

template <class Type>
void BinarySearchTree<Type> :: inOrderTraversal()
{
    inOrderTraversal(this->root);
}

template <class Type>
void BinarySearchTree<Type> :: preOrderTraversal()
{
    preOrderTraversal(this->root);
}

template <class Type>
void BinarySearchTree<Type> :: postOrderTraversal()
{
    postOrderTraversal(this->root);
}

template <class Type>
void BinarySearchTree<Type> :: demoTraversalSteps()
{
    demoTraversalSteps(this->root);
}

template <class Type>
int BinarySearchTree<Type> :: getSize()
{
    return calculateSize(this->root);
}

template <class Type>
int BinarySearchTree<Type> :: getHeight()
{
    return calculateHeight(this->root);
}

template <class Type>
bool BinarySearchTree<Type> :: isComplete()
{
    return isComplete(this->root, 0, getSize());
}

template <class Type>
bool BinarySearchTree<Type> :: isBalanced()
{
    return isBalanced(this->root);
}

template <class Type>
bool BinarySearchTree<Type> :: contains(Type value)
{
    BinaryTreeNode<Type> * current = this->root;
    if (current == nullptr)
    {
        return false;
    }
    else
    {
        while (current != nullptr)
        {
            if (value == current->getData())
            {
                return true;
            }
            else if (value < current->getData())
            {
                current = current->getLeftNode();
            }
            else
            {
                current = current->getRightNode();
            }
        }
        return false;
    }
}

template <class Type>
void BinarySearchTree<Type> :: insert(Type itemToInsert)
{
    BinaryTreeNode<Type> * insertMe = new BinaryTreeNode<Type>(itemToInsert);
    BinaryTreeNode<Type> * previous = nullptr;
    BinaryTreeNode<Type> * current = this->root;
    if (current == nullptr)
    {
        this->root = insertMe;
    }
    else
    {
        while (current != nullptr)
        {
            previous = current;
            if (itemToInsert < current->getData())
            {
                current = current->getLeftNode();
            }
            else if (itemToInsert > current->getData())
            {
                current = current->getRightNode();
            }
            else
            {
                cerr << "Item exists already - Exiting insert" << endl;
                delete insertMe;
                return;
            }
        }
        if (previous->getData() > itemToInsert)
        {
            previous->setLeftNode(insertMe);
        }
        else
        {
            previous->setRightNode(insertMe);
        }
        insertMe->setRootNode(previous);
    }
}

template <class Type>
void BinarySearchTree<Type> :: remove(Type value)
{
    if (this->root == nullptr)
    {
        cout << "Empty tree so removal is not possible" << endl;
    }
    else
    {
        BinaryTreeNode<Type> * current = this->root;
        BinaryTreeNode<Type> * previous = nullptr;
        bool hasBeenFound = false;
        while (current != nullptr && !hasBeenFound)
        {
            if (current->getData() == value)
            {
                hasBeenFound = true;
            }
            else
            {
                previous = current;
                if (value < current->getData())
                {
                    current = current->getLeftNode();
                }
                else
                {
                    current = current->getRightNode();
                }
            }
        }
        if (current == nullptr)
        {
            cerr << "Item not found, removal unsuccessful" << endl;
        }
        else if (hasBeenFound)
        {
            if (current == this->root)
            {
                removeNode(this->root);
            }
            else if (value < previous->getData())
            {
                removeNode(previous->getLeftNode());
            }
            else
            {
                removeNode(previous->getRightNode());
            }
        }
    }
}

template <class Type>
Type BinarySearchTree<Type> :: findMinimum()
{
    assert(this->root != nullptr);
    return getLeftMostChild(this->root)->getData();
}

template <class Type>
Type BinarySearchTree<Type> :: findMaximum()
{
    assert(this->root != nullptr);
    return getRightMostChild(this->root)->getData();
}

template <class Type>
int BinarySearchTree<Type> :: calculateSize(BinaryTreeNode<Type> * startNode)
{
    if (startNode != nullptr)
    {
        return calculateSize(startNode->getLeftNode()) + calculateSize(startNode->getRightNode()) + 1;
    }
    return 0;
}

template <class Type>
int BinarySearchTree<Type> :: calculateHeight(BinaryTreeNode<Type> * startNode)
{
    if (startNode != nullptr)
    {
        return max(calculateHeight(startNode->getLeftNode()), calculateHeight(startNode->getRightNode())) + 1;
    }
    return 0;
}

template <class Type>
bool BinarySearchTree<Type> :: isBalanced(BinaryTreeNode<Type> * startNode)
{
    int leftHeight = 0;
    int rightHeight = 0;
    if (startNode == nullptr)
    {
        return true;
    }
    leftHeight = calculateHeight(startNode->getLeftNode());
    rightHeight = calculateHeight(startNode->getRightNode());
    int heightDifference = abs(leftHeight - rightHeight);
    bool leftBalanced = isBalanced(startNode->getLeftNode());
    bool rightBalanced = isBalanced(startNode->getRightNode());
    if (heightDifference <= 1 && leftBalanced && rightBalanced)
    {
        return true;
    }
    return false;
}

template <class Type>
bool BinarySearchTree<Type> :: isComplete(BinaryTreeNode<Type> * startNode, int index, int size)
{
    if (startNode == nullptr)
    {
        return true;
    }
    if (index >= size)
    {
        return false;
    }
    return isComplete(startNode->getLeftNode(), 2 * index + 1, size) && isComplete(startNode->getRightNode(), 2 * index + 2, size);
}

template <class Type>
void BinarySearchTree<Type> :: inOrderTraversal(BinaryTreeNode<Type> * inStart)
{
    if (inStart != nullptr)
    {
        inOrderTraversal(inStart->getLeftNode());
        cout << inStart->getData() << endl;
        inOrderTraversal(inStart->getRightNode());
    }
}

template <class Type>
void BinarySearchTree<Type> :: preOrderTraversal(BinaryTreeNode<Type> * preStart)
{
    if (preStart != nullptr)
    {
        cout << preStart->getData() << endl;
        preOrderTraversal(preStart->getLeftNode());
        preOrderTraversal(preStart->getRightNode());
    }
}

template <class Type>
void BinarySearchTree<Type> :: postOrderTraversal(BinaryTreeNode<Type> * postStart)
{
    if (postStart != nullptr)
    {
        postOrderTraversal(postStart->getLeftNode());
        postOrderTraversal(postStart->getRightNode());
        cout << postStart->getData() << endl;
    }
}

template <class Type>
void BinarySearchTree<Type> :: demoTraversalSteps(BinaryTreeNode<Type> * start)
{
    if (start != nullptr)
    {
        cout << "check if left is here" << endl;
        demoTraversalSteps(start->getLeftNode());
        cout << "return to root" << endl;
        cout << "check if right is here" << endl;
        demoTraversalSteps(start->getRightNode());
    }
    else
    {
        cout << "reached nullptr - if on right its back up the recursive call stack" << endl;
    }
}

template <class Type>
BinaryTreeNode<Type> * BinarySearchTree<Type> :: getRightMostChild(BinaryTreeNode<Type> * current)
{
    BinaryTreeNode<Type> * currentNode = current;
    BinaryTreeNode<Type> * previous = nullptr;
    while (currentNode != nullptr)
    {
        previous = currentNode;
        currentNode = currentNode->getRightNode();
    }
    return previous;
}

template <class Type>
BinaryTreeNode<Type> * BinarySearchTree<Type> :: getLeftMostChild(BinaryTreeNode<Type> * current)
{
    BinaryTreeNode<Type> * currentNode = current;
    BinaryTreeNode<Type> * previous = nullptr;
    while (currentNode != nullptr)
    {
        previous = currentNode;
        currentNode = currentNode->getLeftNode();
    }
    return previous;
}

template <class Type>
void BinarySearchTree<Type> :: removeNode(BinaryTreeNode<Type> * removeMe)
{
    BinaryTreeNode<Type> * current;
    BinaryTreeNode<Type> * previous;
    BinaryTreeNode<Type> * temp;
    previous = removeMe->getRootNode();
    if (removeMe->getRightNode() == nullptr && removeMe->getLeftNode() == nullptr)
    {
        temp = removeMe;
        removeMe = nullptr;
        if (previous != nullptr && removeMe->getData() < previous->getData())
        {
            previous->setLeftNode(removeMe);
        }
        else if (previous != nullptr && removeMe->getData() > previous->getData())
        {
            previous->setRightNode(removeMe);
        }
        delete temp;
    }
    else if (removeMe->getRightNode() == nullptr)
    {
        temp = removeMe;
        removeMe = removeMe->getLeftNode();
        if (previous != nullptr && temp->getData() < previous->getData())
        {
            previous->setLeftNode(removeMe);
        }
        else if (previous != nullptr && temp->getData() > previous->getData())
        {
            previous->setRightNode(removeMe);
        }
        removeMe->setRootNode(previous);
        delete temp;
    }
    else if (removeMe->getLeftNode() == nullptr)
    {
        temp = removeMe;
        removeMe = removeMe->getRightNode();
        if (previous != nullptr && removeMe->getData() < previous->getData())
        {
            previous->setLeftNode(removeMe);
        }
        else if (previous != nullptr && removeMe->getData() > previous->getData())
        {
            previous->setRightNode(removeMe);
        }
        removeMe->setRootNode(previous);
        delete temp;
    }
    else
    {
        current = getRightMostChild(removeMe->getLeftNode());
        previous = current->getRootNode();
        removeMe->setData(current->getData());
        if (previous == nullptr)
        {
            removeMe->setLeftNode(current->getLeftNode());
        }
        else
        {
            previous->setRightNode(current->getLeftNode());
        }
        if (current->getLeftNode() != nullptr)
        {
            current->getLeftNode()->setRootNode(removeMe);
        }
        delete current;
    }
    if (removeMe == nullptr || removeMe->getRootNode() == nullptr)
    {
        this->root = removeMe;
    }
}

#endif /* BinarySearchTree_hpp */
