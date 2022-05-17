//
//  no_108_sorted_arr_2_bts.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/17.
//

#ifndef no_108_sorted_arr_2_bts_hpp
#define no_108_sorted_arr_2_bts_hpp

#include <stdio.h>
#include <vector>
#include "tree_node.hpp"

using namespace std;

/**
 * 题目108: 将有序数组转换为二叉搜索树
 *
 * 描述: 给你一个整数数组 nums, 其中元素已经按 升序 排列, 请你将其转换为一棵 高度平衡 二叉搜索树.
 *      高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树.
 */
TreeNode* sortedArrayToBTS(vector<int>& nums);
#endif /* no_108_sorted_arr_2_bts_hpp */
