//
//  no_96_different_tree.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/16.
//

#ifndef no_96_different_tree_hpp
#define no_96_different_tree_hpp

#include <stdio.h>

/**
 * 题目96: 不同的二叉搜索树
 *
 * 描述: 给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？
 *      返回满足题意的二叉搜索树的种数。
 **/

class No96Solution {
private:
    int numTrees(int start, int end);
public:
    int numTrees(int n);
};

#endif /* no_96_different_tree_hpp */
