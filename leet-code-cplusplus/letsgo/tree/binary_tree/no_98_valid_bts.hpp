//
//  no_98_valid_bts.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/16.
//

#ifndef no_98_valid_bts_hpp
#define no_98_valid_bts_hpp

#include <stdio.h>
#include "tree_node.hpp"

/**
 * 题目98: 验证二叉搜索树
 *
 * 描述: 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
 *
 *      有效二叉搜索树定义如下:
 *          节点的左子树只包含 小于 当前节点的数。
 *          节点的右子树只包含 大于 当前节点的数。
 *          所有左子树和右子树自身必须也是二叉搜索树。
 */
bool isValidBTS(TreeNode* root);

#endif /* no_98_valid_bts_hpp */
