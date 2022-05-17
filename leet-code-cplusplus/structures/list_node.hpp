//
//  list_node.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/17.
//

#ifndef list_node_hpp
#define list_node_hpp

#include <stdio.h>

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int _val): val(_val), next(nullptr) {}
    ListNode(int _val, ListNode* _next): val(_val), next(_next) {}
};

#endif /* list_node_hpp */
