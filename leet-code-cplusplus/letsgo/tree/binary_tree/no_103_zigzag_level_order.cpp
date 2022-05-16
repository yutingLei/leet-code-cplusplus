//
//  no_103_zigzag_level_order.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/16.
//

#include <stack>
#include "no_103_zigzag_level_order.hpp"

/**
 * 本题是层序遍历的变种
 *
 * 解题思路:
 *      基本思路还是层序遍历, 不过需要增加一个标记, 而且使用队列的地方我们换为了栈
 */
void zigzagLevelOrder(int deep, bool l2r, TreeNode* node, vector<vector<int>>& ans) {
    if (!node) {
        return;
    }
    if (deep == ans.size()) {
        ans.emplace_back(vector<int>{});
    }
    if (l2r) {
        ans[deep].emplace_back(node->val);
    } else {
        ans[deep].insert(ans[deep].begin(), node->val);
    }
    if (node->left)
        zigzagLevelOrder(deep + 1, !l2r, node->left, ans);
    if (node->right) {
        zigzagLevelOrder(deep + 1, !l2r, node->right, ans);
    }
}
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    
    vector<vector<int>> ans;
    if (!root) return ans;
    
    //1. 迭代
//    stack<TreeNode*> stk;
//    stk.push(root);
//    bool l2r = true; // true: left to right, false: right to left
//    while (!stk.empty()) {
//        size_t ssize = stk.size();
//        vector<int> tmp;
//        vector<TreeNode*> nodes;
//        for (int i = 0; i < ssize; i++) {
//            TreeNode* node = stk.top();
//            stk.pop();
//            tmp.emplace_back(node->val);
//            nodes.emplace_back(node);
//        }
//        ans.emplace_back(tmp);
//
//        // 根据方向, 确认先后入栈顺序
//        for (auto& node: nodes) {
//            if (l2r) {
//                if (node->left)
//                    stk.push(node->left);
//                if (node->right)
//                    stk.push(node->right);
//            } else {
//                if (node->right)
//                    stk.push(node->right);
//                if (node->left)
//                    stk.push(node->left);
//            }
//        }
//        l2r = !l2r;
//    }
    
    //2. 递归
    zigzagLevelOrder(0, true, root, ans);
    return ans;
}
