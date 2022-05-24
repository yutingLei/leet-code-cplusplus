//
//  no_19_remove_nth_from_end.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/24.
//

#ifndef no_19_remove_nth_from_end_hpp
#define no_19_remove_nth_from_end_hpp

#include <stdio.h>
#include "list_node.hpp"

/**
 * 题目19: 删除倒数第N个节点
 *
 * 描述:
 *  给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 */

class No19Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n);
};

#endif /* no_19_remove_nth_from_end_hpp */
