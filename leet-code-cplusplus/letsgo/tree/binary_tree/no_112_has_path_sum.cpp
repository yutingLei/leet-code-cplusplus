//
//  no_112_has_path_sum.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/19.
//

#include <queue>
#include "no_112_has_path_sum.hpp"

using namespace std;

/**
 * 解题思路:
 *      需要找到这么一条从根节点到叶节点路劲, 它们的和与给定的值相同.
 *      分解一下就可以, 已知根节点的值, 那么只需要找到左或右子树是否
 *      有一条路径的和为targetSum-root->val, 如果有, 那么加上根节点
 *      的值就可以组成和为targetSum的路径.
 *      同理, 左右子树路径和又可以分解为找它们左右子树的和.
 */

bool hasPathSum(TreeNode* root, int targetSum) {
    /// 递归法
//    // 1. 如果节点为空, 直接返回false
//    if (!root) return false;
//    // 2. 如果是叶节点, 判断叶节点的值是否与目标值相同
//    if (!root->left && !root->right) {
//        return targetSum == root->val;
//    }
//    // 3. 寻找该节点子树是否存在目标和
//    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    
    /// 迭代法
    if (!root) return false;
    queue<TreeNode*> q;
    queue<int> targets;
    q.push(root);
    targets.push(targetSum);
    while (!q.empty()) {
        size_t qsize = q.size();
        for (int i = 0; i < qsize; i++) {
            TreeNode* node = q.front();
            q.pop();
            int target = targets.front();
            targets.pop();
            if (!node->left && !node->right && node->val == target) {
                return true;
            }
            if (node->left) {
                q.push(node->left);
                targets.push(target - node->val);
            }
            if (node->right) {
                q.push(node->right);
                targets.push(target - node->val);
            }
        }
    }
    return false;
}

bool hasSumPathR(TreeNode* root, int targetNum) {
    // 递归法
//    if (!root) return false;
//    if (!root->left && !root->right) return root->val == targetNum;
//    return hasSumPathR(root->left, targetNum - root->val) || hasSumPathR(root->right, targetNum - root->val);
    
    // 迭代法
    if (!root) return false;
    queue<TreeNode*> nodeq;
    nodeq.push(root);
    queue<int> numq;
    numq.push(targetNum);
    while (!nodeq.empty()) {
        size_t qsize = nodeq.size();
        for (int i = 0; i < qsize; i++) {
            TreeNode* node = nodeq.front();
            nodeq.pop();
            int num = numq.front();
            numq.pop();
            if (!node->left && !node->right && node->val == num) {
                return true;
            }
            if (node->left) {
                nodeq.push(node->left);
                numq.push(num - node->val);
            }
            if (node->right) {
                nodeq.push(node->right);
                numq.push(num - node->val);
            }
        }
    }
    return false;
}
