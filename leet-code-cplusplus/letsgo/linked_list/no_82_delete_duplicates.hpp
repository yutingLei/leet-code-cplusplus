//
//  no_82_delete_duplicates.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/26.
//

#ifndef no_82_delete_duplicates_hpp
#define no_82_delete_duplicates_hpp

#include <stdio.h>
#include "list_node.hpp"

/**
 * 题目82: 删除重复元素
 *
 * 描述:
 *      给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。
 */

class No82Solution {
public:
    ListNode* deleteDuplicates(ListNode* head);
};
#endif /* no_82_delete_duplicates_hpp */
