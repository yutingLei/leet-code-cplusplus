//
//  no_23_merge_k_lists.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/24.
//

#ifndef no_23_merge_k_lists_hpp
#define no_23_merge_k_lists_hpp

#include <stdio.h>
#include <vector>
#include "list_node.hpp"
#include "no_21_merge_two_list.hpp"

using namespace std;

/**
 * 题目23: 合并K个升序链表
 *
 * 描述:
 *      给你一个链表数组，每个链表都已经按升序排列。
 *      请你将所有链表合并到一个升序链表中，返回合并后的链表。
 */

class No23Solution {
private:
    No21Solution no21Solution;
    ListNode* mergeTwoLists(int l, int r, vector<ListNode*>& lists);
public:
    No23Solution() {}
    ListNode* mergeKLists(vector<ListNode*>& lists);
};
#endif /* no_23_merge_k_lists_hpp */
