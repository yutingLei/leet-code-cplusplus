//
//  no_114_flatten.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/19.
//

#include "no_114_flatten.hpp"

/**
 * 解题思路:
 *      一: 直接前序遍历树, 保存所有节点, 然后根据顺序重新构建这棵树.
 *          该方法需要额外的O(N)空间, N为这棵树的节点数.
 */

void No114Solution::traversal(TreeNode* node, vector<TreeNode*>& vec) {
    if (!node) return;
    vec.emplace_back(node);
    traversal(node->left, vec);
    traversal(node->right, vec);
}

void No114Solution::flatten(TreeNode* root) {
    // 1. 前序遍历法
//    vector<TreeNode*> vec;
//    traversal(root, vec);
//    if (vec.empty()) {
//        return;
//    }
//    size_t size = vec.size();
//    TreeNode* pre = root;
//    for (int i = 1; i < size - 1; i++) {
//        pre->left = nullptr;
//        pre->right = vec[i];
//        pre = pre->right;
//    }
    
    // 2. 原地法(Morris遍历法)
    TreeNode* predessor = nullptr;
    while (root) {
        // 1. 先向左走一步
        if (root->left) {
            predessor = root->left;
            // 2. 找到左子树最右叶节点
            while (predessor->right) {
                predessor = predessor->right;
            }
            // 3. 这一步很重要
            //    a. 将最右叶节点指向根节点的右子树.
            //    b. 将根节点的右子树指向左子树, 这一步是将左子树切换到右子树来.
            //    c. 将根节点的左子树设置为null.
            //    d. 此时又将遍历位置指向根节点的右儿子.
            if (!predessor->right) {
                predessor->right = root->right;
                root->right = root->left;
                root->left = nullptr;
                root = root->right;
            }
        } else {
            root = root->right;
        }
    }
}
