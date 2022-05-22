//
//  no_113_path_sum.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/19.
//

#ifndef no_113_path_sum_hpp
#define no_113_path_sum_hpp

#include <stdio.h>
#include <vector>
#include "tree_node.hpp"

using namespace std;

/**
 * 题目113: 路径总和II
 *
 * 描述:
 *      给你二叉树的根节点 root 和一个整数目标和 targetSum,
 *      找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径.
 *
 * 注: 叶子节点 是指没有子节点的节点.
 */

class No113Solution {
private:
    // 用于保存最终结果
    vector<vector<int>> ans;
    // 用于保存每一次尝试的路径值
    vector<int>path;
    void helper(TreeNode* node, int targetSum);
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum);
};
#endif /* no_113_path_sum_hpp */
