//
//  no_94_inorder_traversal.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/16.
//

#ifndef no_94_inorder_traversal_hpp
#define no_94_inorder_traversal_hpp

#include <stdio.h>
#include <vector>
#include "tree_node.hpp"

using namespace std;
/**
 * 94题: 二叉树的中序遍历
 *
 * 描述: 给定一个二叉树的根节点 root ，返回它的 中序 遍历 。
 */
class No94Solution {
private:
    void classicTraversal(TreeNode* node, vector<int>& ans);
public:
    vector<int> inorderTraversal(TreeNode* root);
};

#endif /* no_94_inorder_traversal_hpp */
