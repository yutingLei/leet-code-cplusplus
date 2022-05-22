//
//  no_114_flatten.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/19.
//

#ifndef no_114_flatten_hpp
#define no_114_flatten_hpp

#include <stdio.h>
#include <vector>
#include "tree_node.hpp"

using namespace std;

/**
 * 题目114: 二叉树展开为链表
 *
 * 描述:
 *      给你二叉树的根结点 root ，请你将它展开为一个单链表:
 *      展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点, 而左子指针始终为 null.
 *      展开后的单链表应该与二叉树 先序遍历 顺序相同.
 */

class No114Solution {
private:
    void traversal(TreeNode* node, vector<TreeNode*>& vec);
public:
    void flatten(TreeNode* root);
};
#endif /* no_114_flatten_hpp */
