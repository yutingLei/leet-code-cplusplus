//
//  no_107_level_order_bottom.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/17.
//

#include <queue>
#include "no_107_level_order_bottom.hpp"

/**
 * 本题考察层序遍历, 与题目102相似.
 *
 * 解题思路:
 *      二叉树的层序遍历使用广度优先方法可以获得, 本题要求从底部开始遍历, 即将
 *      获得的结果反向即可.
 */

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) return ans;
    
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
    reverse(ans.begin(), ans.end());
    return ans;
}
