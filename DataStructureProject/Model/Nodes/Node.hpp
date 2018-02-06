//
//  Node.hpp
//  DataStructureProject
//
//  Created by Charlesworth, Benjamin on 2/6/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>

template <class Type>
class Node
{
protected:
    Type data;
public:
    Node();
    Node(Type data);
    void setData(Type data);
    Type getData;
};

#endif /* Node_hpp */
