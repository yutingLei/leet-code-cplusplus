//
//  node.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/19.
//

#ifndef node_hpp
#define node_hpp

#include <stdio.h>

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node(): val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val): val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val, Node* _left, Node* _right, Node* _next):
    val(_val),
    left(_left),
    right(_right),
    next(_next) {}
};

#endif /* node_hpp */
