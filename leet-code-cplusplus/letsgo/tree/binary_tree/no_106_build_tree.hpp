//
//  no_106_build_tree.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/16.
//

#ifndef no_106_build_tree_hpp
#define no_106_build_tree_hpp

#include <stdio.h>
#include <vector>
#include "tree_node.hpp"

using namespace std;

/**
 * 题目106: 从中序与后序遍历序列构造二叉树
 *
 * 描述: 给定两个整数数组 inorder 和 postorder, 其中 inorder 是二叉树的中序遍历,
 *      postorder 是同一棵树的后序遍历, 请构造二叉树并返回其根节点.
 *
 */
TreeNode* buildTree(vector<int> inorder, vector<int> postorder);

#endif /* no_106_build_tree_hpp */
