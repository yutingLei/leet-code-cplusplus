//
//  no_101_symmetric.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/16.
//

#include "no_101_symmetric.hpp"

/**
 * 本题考察搜索二叉树的遍历
 *
 * 解题思路:
 *      二叉搜索树轴对称, 那么左右节点也按根节点对称.
 *      两个根节点是否对称, 有节点1的左儿子等于节点2的右儿子, 节点1的右儿子等于节点1的左儿子
 */

bool isSymmetric(TreeNode* node1, TreeNode* node2) {
    if (node1 == nullptr || node2 == nullptr)
        return node1 == node2;
    if (node1->val != node2->val)
        return false;
    return isSymmetric(node1->left, node2->right) && isSymmetric(node1->right, node2->left);
}

bool isSymmetric(TreeNode* root) {
    if (!root)
        return true;
    return isSymmetric(root->left, root->right);
}
