//
//  no_102_level_order.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/16.
//

#include <queue>
#include "no_102_level_order.hpp"

/**
 * 本题考察二叉树的层序遍历
 *
 * 解题思路:
 *      1. 迭代法, 使用广度优先算法即可达到目的.
 *      2. 递归法, 使用深度优先
 */

void No102Solution::levelOrder(int deep, TreeNode* node, vector<vector<int>>& ans) {
    if (!node) {
        return;
    }
    if (deep == ans.size()) {
        ans.emplace_back(vector<int>{});
    }
    ans[deep].emplace_back(node->val);
    if (node->left)
        levelOrder(deep + 1, node->left, ans);
    if (node->right)
        levelOrder(deep + 1, node->right, ans);
}

vector<vector<int>> No102Solution::levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) {
        return ans;
    }
    
    // 1. 迭代法
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        size_t qsize = q.size();
        vector<int> tmp;
        for (int i = 0; i < qsize; i++) {
            TreeNode* node = q.front();
            q.pop();
            tmp.emplace_back(node->val);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        ans.emplace_back(tmp);
    }
    
    return ans;
}
