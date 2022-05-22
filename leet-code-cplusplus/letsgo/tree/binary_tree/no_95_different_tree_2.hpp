//
//  no_95_different_tree_2.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/16.
//

#ifndef no_95_different_tree_2_hpp
#define no_95_different_tree_2_hpp

#include <stdio.h>
#include <vector>
#include "tree_node.hpp"

using namespace std;
/**
 * 95题: 不同的二叉搜索树 II
 *
 * 描述: 给你一个整数 n ，请你生成并返回所有由 n 个节点组成且节点值从 1 到 n 互不相同的不同 二叉搜索树 。
 *      可以按 任意顺序 返回答案。
 */

class No95Solution {
private:
    vector<TreeNode*> buildTrees(int start, int end);
public:
    vector<TreeNode*> generateTrees(int n);
};

#endif /* no_95_different_tree_2_hpp */
