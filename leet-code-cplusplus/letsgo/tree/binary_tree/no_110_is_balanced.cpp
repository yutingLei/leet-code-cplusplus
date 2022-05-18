//
//  no_110_is_balanced.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/18.
//

#include <iostream>
#include "no_110_is_balanced.hpp"

using namespace std;

/**
 * 本地考察二叉平衡树的基础知识点
 *
 * 解题思路:
 *      二叉平衡树有左右子树最大高度差不大于1; 且它的左右子树同样是二叉平衡树.
 *      先求左右子树的高度, 而左右子树的高度又可以由它们的左右子树决定, 所以
 *      求子树高度过程中, 就可以判断它的左右子树是否是平衡二叉树, 如果是, 返回
 *      左右子树的高度+1, 1是该节点的高度; 如果不是, 直接返回-1, 这表示整颗
 *      树都不是平衡二叉树.
 *
 */

int helper(TreeNode* node) {
    if (!node) {
        return 0;
    }
    // 左子树高度
    int left = helper(node->left);
    // 如果子树高度-1, 表示左子树不是平衡树, 表示整颗树也不是平衡树
    if (left == -1) {
        return -1;
    }
    // 右子树高度
    int right = helper(node->right);
    // 同左子树一样的道理
    if (right == -1) {
        return -1;
    }
    // 如果此时左右子树高度差大于了1, 表示整颗树也不是平衡树.
    if (abs(left - right) > 1) {
        return -1;
    }
    // 当前节点是平衡树, 高度返回左右子树最大高度+1(1是自己).
    return max(left, right) + 1;
}

bool isBalanced(TreeNode* root) {
    return helper(root) != -1;
}
