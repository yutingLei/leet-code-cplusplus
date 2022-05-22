//
//  no_105_build_tree.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/16.
//

#ifndef no_105_build_tree_hpp
#define no_105_build_tree_hpp

#include <stdio.h>
#include <vector>
#include "tree_node.hpp"

using namespace std;

/**
 * 题目105: 从前序与中序遍历序列构造二叉树
 *
 * 描述: 给定两个整数数组 preorder 和 inorder, 其中 preorder 是二叉树的先序遍历,
 *      inorder 是同一棵树的中序遍历, 请构造二叉树并返回其根节点.
 *
 */

class No105Solution {
private:
    // 记录中序遍历中元素与位置对应关系
    unordered_map<int, int> records;
    TreeNode* buildTree(int pl, int pr, int il, int ir, vector<int>& preorder);
public:
    TreeNode* buildTree(vector<int> preorder, vector<int> inorder);
};
#endif /* no_105_build_tree_hpp */
