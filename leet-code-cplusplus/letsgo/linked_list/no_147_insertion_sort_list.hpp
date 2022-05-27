//
//  no_147_insertion_sort_list.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/27.
//

#ifndef no_147_insertion_sort_list_hpp
#define no_147_insertion_sort_list_hpp

#include <stdio.h>
#include "list_node.hpp"

/**
 * 题目147: 对链表进行插入排序
 *
 * 描述: 给定单个链表的头 head ，使用 插入排序 对链表进行排序，并返回 排序后链表的头 。
 */

class No147Solution {
public:
    ListNode* insertionSortList(ListNode* head);
};
#endif /* no_147_insertion_sort_list_hpp */
