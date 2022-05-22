//
//  no_95_different_tree_2.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/16.
//

#include "no_95_different_tree_2.hpp"

/**
 * 本题考察二叉搜索数的构建
 *
 * 本题思路:
 *      1. 已知二叉搜索数数值范围 [1, n].
 *      2. 要构建所有的二叉搜索树可能, 那么需要将 [1, n] 中每个元素作为根节点来构建.
 *      3. 已知根节点 i (1 <= i <= n), 那么就可以知道左子树范围 [1, i - 1], 右子树范围 [i + 1, n].
 *      4. 左子树有所少中构建方法? 需要将[1, i - 1]中每个元素作为左子树的根节点, 创建左子树; 同理创建右子树,
 *         不过右子树范围为[i + 1, n].
 *      5. 这样, 假设构建左子树有x种方案, 构建右子树有y种方案, 分别从x中取一种, 从y中取一种, 可以构成一种二叉搜索树.
 *      6. 将所有的组合添加到结果中, 即可获取构建方案.
 */

/**
 * start: 元素开始范围
 * end  : 元素结束范围
 */
vector<TreeNode*> No95Solution::buildTrees(int start, int end) {
    // 如果范围错误, 直接退出
    if (start > end) {
        return { nullptr };
    }
    
    vector<TreeNode*> allTrees;
    // 每个元素都要当一次根节点
    for (int i = start; i <= end; i++) {
        // 能构建的左子树可能
        vector<TreeNode*> leftTrees = buildTrees(start, i - 1);
        // 能构建的右子树可能
        vector<TreeNode*> rightTrees = buildTrees(i + 1, end);
        // 分别从左右子树中取一种可能, 构建二叉搜索树
        for (auto& l: leftTrees) {
            for (auto& r: rightTrees) {
                // 当前根节点能构建的树
                TreeNode* root = new TreeNode{ i };
                root->left = l;
                root->right = r;
                allTrees.emplace_back(root);
            }
        }
    }
    return allTrees;
}

vector<TreeNode*> No95Solution::generateTrees(int n) {
    if (n <= 0) {
        return {};
    }
    return buildTrees(1, n);
}
