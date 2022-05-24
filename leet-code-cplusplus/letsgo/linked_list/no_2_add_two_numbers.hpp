//
//  no2_add_two_numbers.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/24.
//

#ifndef no_2_add_two_numbers_hpp
#define no_2_add_two_numbers_hpp

#include <stdio.h>
#include "list_node.hpp"

/**
 * 题目2: 两数相加
 *
 * 描述:
 * 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
 * 请你将两个数相加，并以相同形式返回一个表示和的链表。
 * 你可以假设除了数字 0 之外，这两个数都不会以 0 开头
 */
class No2Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};
#endif /* no2_add_two_numbers_hpp */
