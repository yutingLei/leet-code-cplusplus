//
//  no2_add_two_numbers.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/24.
//

#include "no_2_add_two_numbers.hpp"

/**
 * 求解两个链表的和
 *
 * 解题思路:
 *  链表求和最难的点在于进位, 处理好进位后, 找到最长的链表, 然后以该链表为基, 求和并且更新它的值即可.
 *  若最后有进位, 再生产一个新节点拼接上即可.
 */

// 求链表的长度
int lengthOfListNode(ListNode* head) {
    int len = 0;
    while (head) {
        head = head->next;
        len++;
    }
    return len;
}

ListNode* No2Solution::addTwoNumbers(ListNode *l1, ListNode *l2) {
    // 虽然题目给定非空链表, 此处还是做一个边界处理
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;
    
    // 找到最长链表
    size_t len1 = lengthOfListNode(l1);
    size_t len2 = lengthOfListNode(l2);
    ListNode* head = len1 > len2 ? l1 : l2;
    ListNode* last = nullptr;
    
    // 遍历求和
    int carry = 0;
    ListNode* pre = head;
    while (pre) {
        int l1_v = l1 ? l1->val : 0;
        int l2_v = l2 ? l2->val : 0;
        int sum = carry + l1_v + l2_v;
        pre->val = sum % 10;
        carry = sum / 10;
        last = pre;
        pre = pre->next;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    if (carry > 0) {
        last->next = new ListNode(carry);
    }
    return head;
}
