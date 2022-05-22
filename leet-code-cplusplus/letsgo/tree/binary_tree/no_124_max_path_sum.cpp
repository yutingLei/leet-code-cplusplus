//
//  no_124_max_path_sum.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/17.
//

#include <iostream>
#include "no_124_max_path_sum.hpp"

using namespace std;

/**
 * 本题考察深度优先算法.
 *
 * 解题思路:
 *      任意节点i, 假设已知左右子树可以组成的最大的路径和为x和y.
 *      那么与i节点组成的最大路径和仅有以下三种情况:
 *          a. 当前节点i的值+左子树最大路径和+右子树最大路径和 (i.val + x + y).
 *          b. 当前节点i的值+左子树最大路径和(i.val + x)
 *          c. 当前节点i的值+右子树最大路径和(i.val + y)
 *
 *      通过对比a/b/c三种情况, 我们可以计算出通过 i 节点的可以组成的最大路径和, 计算出i节点最大路径和就可以供它父节点使用.
 *      反过来说: 已知根节点, 要求通过根节点组成的最大路径和, 那么我们需要求得左右子树能组成的最大路径和.
 *      同理: 左右子树最大路径和又可以分解为求它们的左右子树的最大路径和, 所以可以通过递归去求得它们的左右子树最大路径和.
 *
 *      问题回归到如何求出一个节点的左右子树最大路径和？
 *      0. 声明一个全局变量, 用于保存递归中取得路径的最大值 v.
 *      1. 如何一个节点没有左右子树, 那么最大路径和就是它自己.
 *      2. 如果一个节点为空, 那么它的最大路径和为0.
 *      3. 如果一个节点的值为val, 且左右子树最大路径和为x/y, 那么该节点能组成的最大路径和为
 *          a. v = max(v, val + x + y)
 */

int maxSum = INT_MIN;

int No124Solution::helper(TreeNode* node) {
//    // 如果节点为空, 直接返回0
//    if (!node) {
//        return 0;
//    }
//    // 求取该节点的左子树最大路径和, 如果路径和为负, 还不如不用
//    int maxLeft = max(helper(node->left), 0);
//    // 求取该节点的右子树最大路径和, 如果路径和为负, 还不如不用
//    int maxRight = max(helper(node->right), 0);
//    // 对比已知最大路径和与 left->root->right之间, 那个大, 保存最大值.
//    maxSum = max(maxSum, node->val + maxLeft + maxRight);
//    // 返回当前节点最大路径和供它父节点使用.
//    return node->val + max(maxLeft, maxRight);
    if (!node) return 0;
    // 求得左子树路径和
    int left = helper(node->left);
    // 求得右子树路径和
    int right = helper(node->right);
    // 取当前节点结合左右子树的值与已知的值中最大值
    maxSum = max(maxSum, left + right + node->val);
    // 如果当前节点分别与左右子树结合后, 其值为负, 还不如放弃.
    return max(0, node->val + max(left, right));
}

int No124Solution::maxPathSum(TreeNode* root) {
    helper(root);
    return maxSum;
}
