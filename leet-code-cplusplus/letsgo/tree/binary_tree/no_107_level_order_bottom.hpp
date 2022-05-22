//
//  no_107_level_order_bottom.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/17.
//

#ifndef no_107_level_order_bottom_hpp
#define no_107_level_order_bottom_hpp

#include <stdio.h>
#include <vector>
#include "tree_node.hpp"

using namespace std;

/**
 * 题目107: 二叉树的层序遍历 II
 *
 * 描述: 给你二叉树的根节点 root, 返回其节点值 自底向上的层序遍历.
 *      (即按从叶子节点所在层到根节点所在的层, 逐层从左向右遍历)
 */

class No107Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root);
};

#endif /* no_107_level_order_bottom_hpp */
