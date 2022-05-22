//
//  no_111_min_depth.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/18.
//

#ifndef no_111_min_depth_hpp
#define no_111_min_depth_hpp

#include <stdio.h>
#include "tree_node.hpp"

/**
 * 题目111: 二叉树的最小深度
 *
 * 描述: 给定一个二叉树, 找出其最小深度.
 *      最小深度是从根节点到最近叶子节点的最短路径上的节点数量.
 *      说明: 叶子节点是指没有子节点的节点.
 */

class No111Solution {
public:
    int minDepth(TreeNode* root);
};
#endif /* no_111_min_depth_hpp */
