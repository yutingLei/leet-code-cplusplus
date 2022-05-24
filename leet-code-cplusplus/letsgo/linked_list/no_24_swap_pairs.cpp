//
//  no_24_swap_pairs.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/24.
//

#include "no_24_swap_pairs.hpp"

/**
 * 解题思路:
 *
 *      方法一: 两两交换, 申明两个指针, 用于交换两个节点. 另外申明一个指针, 用于保存之前交换后的最后一个节点.
 *      方法二: 队列
 */

ListNode* No24Solution::swapPairs(ListNode *head) {
    // 边界判定
    if (!head) return head;
    if (!head->next) return head;
    
    
    // 新头节点
    ListNode* newHead = head->next;
    
    // 左右指针, 用于交换
    ListNode* left = head;
    ListNode* right = head->next;
    ListNode* last = nullptr;
    while (left && right) {
        ListNode* rightNext = right->next;
        right->next = left;
        left->next = rightNext;
        if (last) {
            last->next = right;
        }
        last = left;
        if (rightNext) {
            right = rightNext->next;
            left = left->next;
        } else {
            break;
        }
    }
    return newHead;
}
