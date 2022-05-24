//
//  generate_linked_list.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/24.
//

#ifndef generate_linked_list_hpp
#define generate_linked_list_hpp

#include <stdio.h>
#include <vector>
#include "list_node.hpp"

using namespace std;

// 链表生成器
class LLGenerator {
public:
    LLGenerator() {};
    
    // 获取链表
    ListNode* create(vector<int> values);
    
    // 打印链表
    void print(ListNode* head);
    
    // 销毁链表
    void destroy(ListNode* head);
};

#endif /* generate_linked_list_hpp */
