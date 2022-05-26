//
//  no_61_rotate_right.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/26.
//

#ifndef no_61_rotate_right_hpp
#define no_61_rotate_right_hpp

#include <stdio.h>
#include "list_node.hpp"

/**
 * 题目61: 旋转链表
 *
 * 描述:
 *      给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
 */

class No61Solution {
public:
    ListNode* rotateRight(ListNode* head, int k);
};
#endif /* no_61_rotate_right_hpp */
