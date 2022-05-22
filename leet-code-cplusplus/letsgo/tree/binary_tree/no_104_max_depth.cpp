//
//  no_104_max_depth.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/16.
//

#include <queue>
#include "no_104_max_depth.hpp"

using namespace std;

/**
 * 考察二叉树最大深度
 *
 * 解题思路:
 *      一: 可以通过广度优先遍历, 遍历最后一层时, 就可以获取深度.
 *      二: 判断节点的左右子树的深度, 然后加上自己, 即深度. 左右子树又可以分割为求它们的子树深度.
 */

int No104Solution::maxDepth(TreeNode* root) {
    // 方法一: 使用广度优先遍历一次二叉树
//    int depth = 0;
//    if (!root) return depth;
//    queue<TreeNode*> q;
//    q.push(root);
//    while (!q.empty()) {
//        size_t qsize = q.size();
//        for (int i = 0; i < qsize; i++) {
//            TreeNode* node = q.front();
//            q.pop();
//            if (node->left)
//                q.push(node->left);
//            if (node->right) {
//                q.push(node->right);
//            }
//        }
//        depth++;
//    }
//    return depth;
    
    // 方法二: 计算左右子树深度, 求取两者最大值
    if (!root) {
        return 0;
    }
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
