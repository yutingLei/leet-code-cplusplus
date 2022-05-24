//
//  no_24_swap_pairs.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/24.
//

#ifndef no_24_swap_pairs_hpp
#define no_24_swap_pairs_hpp

#include <stdio.h>
#include "list_node.hpp"

/**
 * 题目24: 两两交换节点
 *
 * 描述: 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
 */

class No24Solution {
public:
    ListNode* swapPairs(ListNode* head);
};

#endif /* no_24_swap_pairs_hpp */
