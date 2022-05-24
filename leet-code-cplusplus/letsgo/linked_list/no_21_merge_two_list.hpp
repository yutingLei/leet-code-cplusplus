//
//  no_21_merge_two_list.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/24.
//

#ifndef no_21_merge_two_list_hpp
#define no_21_merge_two_list_hpp

#include <stdio.h>
#include "list_node.hpp"

/**
 * 题目21: 合并两个有序链表
 *
 * 描述:
 *  将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 */

class No21Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
};

#endif /* no_21_merge_two_list_hpp */
