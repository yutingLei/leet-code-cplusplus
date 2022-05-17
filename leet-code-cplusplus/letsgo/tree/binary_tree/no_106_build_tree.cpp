//
//  no_106_build_tree.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/16.
//

#include <unordered_map>
#include "no_106_build_tree.hpp"


/**
 * 本题考察中序遍历与后序遍历特性
 *
 * 本题深度类似(题105)
 *
 * 解题思路:
 *      1. 后序遍历(左右根), 最后一个节点一定是根节点.
 *      2. 中序遍历(左根右), 知道根节点, 可以获取左子树与右子树的值.
 *      3. 从后序中获取根节点, 在中序中找到根节点位置, 那么左右子树就可以确定.
 *      4. 从中序中已知左右子树长度, 从新在后序中找到左右子树根节点, 然后重复2~3步骤.
 */

// 记录中序遍历中元素与位置对应关系
unordered_map<int, int> records;

// il/ir: 中序序列下标, 计算这棵树的左右子树长度用.
// pl/pr: 后序序列下标, 标识构建这棵树的取值范围.
// preorder: 前序遍历序列.
TreeNode* buildTree(int il, int ir, int pl, int pr, vector<int>& postorder) {
    //1. 退出条件就是取值范围错误
    if (pl > pr) {
        return nullptr;
    }
    //2. 构建根节点, 后序最后一个点一定是根节点
    TreeNode* root = new TreeNode{ postorder[pr] };
    //3. 通过后序根节点找到中序中根节点的位置
    int index = records[postorder[pr]];
    //4. 计算左子树长度
    int llen = index - il;
    //5. 构建左子树
    root->left = buildTree(il, index - 1, pl, pl+ llen - 1, postorder);
    //6. 构建右子树
    root->right = buildTree(index + 1, ir, pl + llen, pr - 1, postorder);
    return root;
}

TreeNode* buildTree(vector<int> inorder, vector<int> postorder) {
    for (int i = 0; i < inorder.size(); i++) {
        records[inorder[i]] = i;
    }
    return buildTree(0, inorder.size() - 1, 0, postorder.size() - 1, postorder);
}
