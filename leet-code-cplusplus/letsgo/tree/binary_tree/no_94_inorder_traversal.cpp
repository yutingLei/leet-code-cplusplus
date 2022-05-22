//
//  no_94_inorder_traversal.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/16.
//

#include <stack>
#include "no_94_inorder_traversal.hpp"

/**
 * 本题考察二叉树的中序遍历
 *
 * 二叉树中序遍历, 遵循 "左根右" 的顺序, 即先遍历左子树, 其次根节点, 再其次右子树.
 *
 * 本题两种解法: 递归法和迭代法
 *
 *  1. 递归法: 经典二叉树遍历模板.
 *  2. 迭代法: 利用栈特性进行中序遍历.
 **/

/** 二叉树遍历经典模板 */
void No94Solution::classicTraversal(TreeNode* node, vector<int>& ans) {
    if (!node) {
        return;
    }
    // 前序遍历
    // ans.emplace_back(node->val);
    // 向左
    classicTraversal(node->left, ans);
    // 中序遍历
    ans.emplace_back(node->val);
    // 向右
    classicTraversal(node->right, ans);
    // 后序遍历
    // ans.emplace_back(node->val);
}

vector<int> No94Solution::inorderTraversal(TreeNode* root) {
    vector<int> ans;
    
    // 1. 递归法
    // classicTraversal(root, ans);
    
    // 2. 迭代法
    // a. 迭代法原理, 先指向根节点, 然后依次将左子树以及左子树的左子树...入栈.
    // b. 然后出栈一个元素, 将出栈元素添加到结果里, 此时将cur指针指向出栈节点的右儿子
    // c. 重复a, b两步, 直到栈为空或者cur为空.
    stack<TreeNode*> stk;
    // a. 指向根节点
    TreeNode* cur = root;
    while (!stk.empty() || cur) {
        // a. 将左子树一次入栈
        if (cur) {
            stk.push(cur);
            cur = cur->left;
        }
        // b. 出栈一个元素, 添加结果, cur指向右儿子
        TreeNode* node = stk.top();
        stk.pop();
        ans.emplace_back(node->val);
        cur = node->right;
    }
    
    return ans;
}

