//
//  no_21_merge_two_list.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/24.
//

#include "no_21_merge_two_list.hpp"

/**
 * 解题思路:
 *      既然两个链表都是升序链表, 那么我们使用两个指针, 分别指向l1和l2, 谁小谁先拼接.
 *      然后移动相对较小值的那个指针.
 */

ListNode* No21Solution::mergeTwoLists(ListNode *l1, ListNode *l2) {
    /// 处理边界
    if (!l1) return l2;
    if (!l2) return l1;
    
    // 第一个节点, 谁小指向谁
    ListNode* head = l1->val > l2->val ? l2 : l1;
    
    // 申明连个指针,用于指定l1/l2
    ListNode* p1 = l1 == head ? l1->next : l1;
    ListNode* p2 = l2 == head ? l2->next : l2;
    ListNode* pre = head;
    
    while (p1 && p2) {
        if (p1->val < p2->val) {
            pre->next = p1;
            p1 = p1->next;
        } else {
            pre->next = p2;
            p2 = p2->next;
        }
        pre = pre->next;
    }
    pre->next = p1 ? p1 : p2;
    return head;
}
