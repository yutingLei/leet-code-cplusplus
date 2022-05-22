//
//  no_100_same_tree.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/16.
//

#include "no_100_same_tree.hpp"

/** 本题相对简单
 *
 *  思路: 分别对比左右节点, 然后一次对比节点的节点.
 */
bool No100Solution::isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr || q == nullptr)
        return p == q;
    if (p->val != q->val)
        return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
