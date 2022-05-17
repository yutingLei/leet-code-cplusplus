//
//  no_109_sorted_list_2_bst.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/17.
//

#ifndef no_109_sorted_list_2_bst_hpp
#define no_109_sorted_list_2_bst_hpp

#include <stdio.h>
#include "list_node.hpp"
#include "tree_node.hpp"

/**
 * 题目109: 有序链表转换二叉搜索树
 *
 * 题目描述: 给定一个单链表的头节点  head, 其中的元素 按升序排序, 将其转换为高度平衡的二叉搜索树.
 *         本题中, 一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差不超过 1.
 */
TreeNode* sortedListToBST(ListNode* head);
#endif /* no_109_sorted_list_2_bst_hpp */
