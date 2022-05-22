//
//  no_124_max_path_sum.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/17.
//

#ifndef no_124_max_path_sum_hpp
#define no_124_max_path_sum_hpp

#include <stdio.h>
#include "tree_node.hpp"

/**
 * 题目124: 二叉树中的最大路径和
 *
 * 描述: 路径 被定义为一条从树中任意节点出发, 沿父节点-子节点连接, 达到任意节点的序列.
 *      同一个节点在一条路径序列中 至多出现一次. 该路径 至少包含一个 节点, 且不一定经过根节点.
 *      路径和 是路径中各节点值的总和.
 *      给你一个二叉树的根节点 root, 返回其 最大路径和.
 */

class No124Solution {
private:
    int helper(TreeNode* node);
public:
    int maxPathSum(TreeNode* root);
};
#endif /* no_124_max_path_sum_hpp */
