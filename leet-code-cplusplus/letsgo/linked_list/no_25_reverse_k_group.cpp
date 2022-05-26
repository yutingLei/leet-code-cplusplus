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

// 翻转[start...end]之间的链表
ListNode* No25Solution::reverse(ListNode* start, ListNode* end) {
    if (!start) return nullptr;
    if (start == end) return start;
    
    /// 将end记录它的下一个节点
    end = end->next;
    
    /// 申明几个变量, 用于两两交换节点
    ListNode* pre = nullptr;
    ListNode* cur = start;
    ListNode* next = nullptr;
    
    /// 开始逆序
    while (cur != end) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    start->next = end;
    return pre;
}

// 知道一个起点, 获取它之后第k个节点
ListNode* No25Solution::groupKNodes(ListNode* start, int k) {
    if (!start) return nullptr;
    while (--k > 0 && start) {
        start = start->next;
    }
    return start;
}

ListNode* No25Solution::reverseKGroup(ListNode *head, int k) {
    if (!head) return head;
    // 记录每次翻转后的最后一个节点
    ListNode* pre = head;
    
    // 处理第一组, 用于获取head节点
    ListNode* end = groupKNodes(head, k);
    if (!end) {
        return head;
    }
    head = reverse(head, end);
    
    // 记录当前
    ListNode* cur = pre->next;
    while (cur) {
        end = groupKNodes(cur, k);
        if (!end) {
            break;
        }
        pre->next = reverse(cur, end);
        pre = cur;
        cur = cur->next;
    }
    return head;
}
