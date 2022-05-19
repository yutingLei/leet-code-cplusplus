//
//  no_111_min_depth.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/18.
//

#include <queue>
#include "no_111_min_depth.hpp"

using namespace std;

/**
 * 本题考察的其实就是二叉树的遍历
 *
 * 解题思路:
 *      求二叉树的最小深度, 可以理解为找到第一个叶节点, 叶节点是指没有左右儿子的节点.
 *      求第一个没有页节点的左右儿子, 应该由自顶向下遍历.
 *
 */

int minDepth(TreeNode* root) {
    if (!root) { return 0; }
    queue<TreeNode*> q;
    q.push(root);
    int ans = 1;
    while (!q.empty()) {
        size_t qsize = q.size();
        for (int i = 0; i < qsize; i++) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left == nullptr && node->right == nullptr) {
                return ans;
            }
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        ans++;
    }
    return ans;
}
