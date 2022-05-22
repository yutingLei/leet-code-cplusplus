//
//  no_98_valid_bts.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/16.
//

#include <stack>
#include "no_98_valid_bts.hpp"

using namespace std;

/**
 * 本题考察二叉搜索树基本定义
 *
 * 本题思路:
 *      1. 二叉搜索树中序遍历一定是升序排列.
 *      2. 在中序遍历过程中, 当前节点的值一定大于前一个节点的值, 若不, 则不是合法的二叉搜索树.
 */
bool No98Solution::isValidBTS(TreeNode* root) {
    
    stack<TreeNode*> stk;
    TreeNode* cur = root;
    TreeNode* pre = nullptr;
    while (!stk.empty() || cur) {
        if (cur) {
            stk.push(cur);
            cur = cur->left;
        }
        TreeNode* node = stk.top();
        stk.pop();
        if (pre && pre->val > node->val) {
            return false;
        }
        pre = node;
        cur = node->right;
    }
    return true;
}
