//
//  no_112_has_path_sum.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/19.
//

#ifndef no_112_has_path_sum_hpp
#define no_112_has_path_sum_hpp

#include <stdio.h>
#include "tree_node.hpp"

/**
 * 题目112: 路径总和
 *
 * 描述: 给你二叉树的根节点 root 和一个表示目标和的整数 targetSum.
 * 判断该树中是否存在 根节点到叶子节点 的路径, 这条路径上所有节点值相加
 * 等于目标和 targetSum. 如果存在, 返回 true; 否则, 返回 false.
 *
 * 注: 叶子节点 是指没有子节点的节点.
 */

class No112Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum);
};
#endif /* no_112_has_path_sum_hpp */
