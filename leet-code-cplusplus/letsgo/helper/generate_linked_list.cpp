//
//  generate_linked_list.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/24.
//

#include <iostream>
#include "generate_linked_list.hpp"

ListNode* LLGenerator::create(vector<int> values) {
    ListNode* head = new ListNode();
    ListNode* pre  = head;
    for (auto& value: values) {
        pre->next = new ListNode(value);
        pre = pre->next;
    }
    ListNode* unused = head;
    head = head->next;
    delete unused;
    return head;
}

void LLGenerator::print(ListNode* head) {
    ListNode* pre = head;
    while (pre) {
        cout << pre->val << " -> ";
        pre = pre->next;
    }
    cout << "null" << endl;
}

void LLGenerator::destroy(ListNode *head) {
    if (!head) return;
    while (head) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}
