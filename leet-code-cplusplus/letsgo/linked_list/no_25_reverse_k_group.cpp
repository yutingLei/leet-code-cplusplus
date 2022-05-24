//
//  no_25_reverse_k_group.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/24.
//

#include <stack>
#include "no_25_reverse_k_group.hpp"

using namespace std;

/**
 * 解题思路:
 *      使用一个辅助方法, 给定一个头, 将它K个节点进行翻转.
 */

// 我知道链表的头和尾, 实现链表的翻转.
// 例如: 1->2->3->4->5, 有head指向1节点, tail指向5节点
//      翻转结果为:  5->4->3->2->1
void No25Solution::reverseListNode(ListNode* forward, ListNode* head, ListNode* tail) {
    if (!head) return;
    if (head == tail) return;
    
    ListNode* pre = head;
    stack<ListNode*> nodes;
    while (pre != tail) {
        nodes.push(pre);
        pre = pre->next;
    }
    nodes.push(tail);
    
    ListNode* last = tail->next;
    while (!nodes.empty()) {
        if (!forward) {
            forward = nodes.top();
            nodes.pop();
            continue;
        }
        forward->next = nodes.top();
        nodes.pop();
        forward = forward->next;
    }
    forward->next = last;
}

ListNode* No25Solution::reverseKGroup(ListNode *head, int k) {
    ListNode* pre = head;
    ListNode* newHead = nullptr;
    ListNode* forward = nullptr;
    int num = k;
    while (pre) {
        ListNode* first = pre;
        ListNode* second = nullptr;
        while (pre && --num > 0) {
            pre = pre->next;
        }
        second = pre;
        // 重置k, pre指向下一个节点
        num = k;
        if (pre)
            pre = pre->next;
        // 已经不够K个节点了, 直接断开
        if (!second) {
            break;
        } else {
            // 逆序这一段节点
            reverseListNode(forward, first, second);
            forward = first;
        }
    }
    return newHead;
}
