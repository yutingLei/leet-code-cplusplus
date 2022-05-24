//
//  no_19_remove_nth_from_end.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/24.
//

#include "no_19_remove_nth_from_end.hpp"

/**
 * 解题思路:
 *      移除倒数第N个节点, 难点在于如何找到倒数第N个节点.
 *      本题可以使用快慢指针, 先让快指针先走N步, 然后快慢指针一起走, 最后当快指针指向最后一个节点时停止,
 *      此时慢指针指向的就是倒数第N个节点的前一个节点.
 *
 *      为何要在倒数N个节点的前一个节点停止?
 *      只有这样才能通过慢指针删除倒数第N个节点, 如果慢指针指向第N个节点, 那删除就无从谈起, 根本
 *      找不到前一个指针.
 */

ListNode* No19Solution::removeNthFromEnd(ListNode *head, int n) {
    // 边界判定
    if (!head) return nullptr;
    
    // 申明快慢指针
    ListNode* fast = head;
    ListNode* slow = head;
    
    // fast先走N步
    while (fast && n-- > 0) {
        fast = fast->next;
    }
    
    // 如果fast为空, 那么肯定是删除头节点
    if (!fast) {
        return head->next;
    }
    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
}
