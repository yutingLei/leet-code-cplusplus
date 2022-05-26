//
//  no_25_reverse_k_group.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/24.
//

#ifndef no_25_reverse_k_group_hpp
#define no_25_reverse_k_group_hpp

#include <stdio.h>
#include "list_node.hpp"

/**
 * 题目25:  K 个一组翻转链表
 *
 * 描述:
 *      给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
 *      k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 *      你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 */

class No25Solution {
private:
    ListNode* reverse(ListNode* start, ListNode* end);
    ListNode* groupKNodes(ListNode* start, int k);
public:
    ListNode* reverseKGroup(ListNode* head, int k);
};
#endif /* no_25_reverse_k_group_hpp */
