//
//  no_102_level_order.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/16.
//

#ifndef no_102_level_order_hpp
#define no_102_level_order_hpp

#include <stdio.h>
#include <vector>
#include "tree_node.hpp"

using namespace std;

/**
 * 题目102: 二叉树层序遍历
 *
 * 描述: 给你二叉树的根节点 root, 返回其节点值的 层序遍历. (即逐层地，从左到右访问所有节点).
 */
vector<vector<int>> levelOrder(TreeNode* root);
#endif /* no_102_level_order_hpp */
