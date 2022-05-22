//
//  no_100_same_tree.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/16.
//

#ifndef no_100_same_tree_hpp
#define no_100_same_tree_hpp

#include <stdio.h>
#include "tree_node.hpp"

/**
 * 题目100: 相同的树
 *
 * 描述: 给你两棵二叉树的根节点 p 和 q, 编写一个函数来检验这两棵树是否相同.
 *      如果两个树在结构上相同, 并且节点具有相同的值, 则认为它们是相同的.
 */

class No100Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q);
};
#endif /* no_100_same_tree_hpp */
