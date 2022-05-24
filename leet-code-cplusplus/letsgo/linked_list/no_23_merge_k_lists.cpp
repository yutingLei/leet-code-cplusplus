//
//  no_23_merge_k_lists.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/24.
//

#include "no_23_merge_k_lists.hpp"


/**
 * 解题思路:
 *
 *   方法一: 很容易想到两个链表合并, 两个链表可以用两个指针, 那么K个链表是否可以用K个指针呢?
 *          那么空间复杂度为O(K), 时间复杂度为O(K^N)
 *   方法二: 我们可以先将链表两两合并, 然后再两两合并, 直到只有一个链表即可.
 */

ListNode* No23Solution::mergeTwoLists(int l1, int l2, vector<ListNode*>& lists) {
    if (l1 > l2) return nullptr;
    if (l1 == l2) return lists[l1];
    int mid = (l1 + l2) >> 1;
    return no21Solution.mergeTwoLists(mergeTwoLists(l1, mid, lists), mergeTwoLists(mid + 1, l2, lists));
}

ListNode* No23Solution::mergeKLists(vector<ListNode *>& lists) {
    if (lists.empty()) return nullptr;
    return mergeTwoLists(0, lists.size() - 1, lists);
}
