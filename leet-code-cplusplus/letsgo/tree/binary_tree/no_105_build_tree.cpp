//
//  no_105_build_tree.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/16.
//

#include <unordered_map>
#include "no_105_build_tree.hpp"

/**
 * 本题考察前序遍历与中序遍历特性
 *
 * 解题思路:
 *      1. 前序遍历(根左右), 第一个节点一定是根节点.
 *      2. 中序遍历(左根右), 知道根节点, 可以获取左子树与右子树的值.
 *      3. 从前序中获取根节点, 在中序中找到根节点位置, 那么左右子树就可以确定.
 *      4. 从中序中已知左右子树长度, 从新在前序中找到左右子树根节点, 然后重复2~3步骤.
 */

// pl/pr: 前序序列下标, 标识构建这棵树的取值范围.
// il/ir: 中序序列下标, 计算这棵树的左右子树长度用.
// preorder: 前序遍历序列.
TreeNode* No105Solution::buildTree(int pl, int pr, int il, int ir, vector<int>& preorder) {
    //1. 退出条件就是取值范围错误
    if (pl > pr) {
        return nullptr;
    }
    //2. 构建根节点, 前序第一个点一定是根节点
    TreeNode* root = new TreeNode{ preorder[pl] };
    //3. 通过前序根节点找到中序中根节点的位置
    int index = records[preorder[pl]];
    //4. 计算左子树长度
    int llen = index - il;
    //5. 构建左子树
    root->left = buildTree(pl + 1, pl + llen, il, index - 1, preorder);
    //6. 构建右子树
    root->right = buildTree(pl + llen + 1, pr, index + 1, ir, preorder);
    return root;
}

TreeNode* No105Solution::buildTree(vector<int> preorder, vector<int> inorder) {
    for (int i = 0; i < inorder.size(); i++) {
        records[inorder[i]] = i;
    }
    return buildTree(0, preorder.size() - 1, 0, inorder.size() - 1, preorder);
}
