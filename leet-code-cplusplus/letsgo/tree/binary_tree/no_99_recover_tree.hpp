//
//  no_99_recover_tree.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/16.
//

#ifndef no_99_recover_tree_hpp
#define no_99_recover_tree_hpp

#include <stdio.h>
#include "tree_node.hpp"

/**
 * 题目99: 恢复二叉搜索树
 *
 * 描述: 给你二叉搜索树的根节点 root ，该树中的 恰好 两个节点的值被错误地交换。
 *      请在不改变其结构的情况下，恢复这棵树 。
 *
 * 进阶: 使用 O(n) 空间复杂度的解法很容易实现。你能想出一个只使用 O(1) 空间的解决方案吗？
 */
void recoverTree(TreeNode* root);

#endif /* no_99_recover_tree_hpp */
