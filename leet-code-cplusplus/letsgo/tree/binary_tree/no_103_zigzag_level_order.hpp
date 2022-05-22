//
//  no_103_zigzag_level_order.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/16.
//

#ifndef no_103_zigzag_level_order_hpp
#define no_103_zigzag_level_order_hpp

#include <stdio.h>
#include <vector>
#include "tree_node.hpp"

using namespace std;

/**
 * 题目103: 二叉树的锯齿形遍历
 *
 * 描述: 给你二叉树的根节点 root, 返回其节点值的 锯齿形层序遍历.
 *      (即先从左往右, 再从右往左进行下一层遍历, 以此类推, 层与层之间交替进行).
 */

class No103Solution {
private:
    void zigzagLevelOrder(int deep, bool l2r, TreeNode* node, vector<vector<int>>& ans);
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root);
};
#endif /* no_103_zigzag_level_order_hpp */
