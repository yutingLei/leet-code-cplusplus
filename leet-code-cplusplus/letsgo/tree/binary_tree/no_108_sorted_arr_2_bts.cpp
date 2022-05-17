//
//  no_108_sorted_arr_2_bts.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/17.
//

#include "no_108_sorted_arr_2_bts.hpp"

/**
 * 本题考察构建平衡二叉树
 *
 * 解题思路:
 *      平衡二叉树要求左右子节点高度最大不超过1, 那么创建左右节点时, 尽可能的使左右节点数量保持一致.
 *      或相差不超过1.
 *      所以题目核心就是找到合适的根节点, 使左右节点数尽量相等或相差个数最少.
 */
TreeNode* buildBST(int l, int r, vector<int>& nums) {
    if (l > r) {
        return nullptr;
    }
    // 找到中点, 构建节点
    int m = (r - l) / 2;
    TreeNode* root = new TreeNode{ nums[m + l] };
    root->left = buildBST(l, m - 1, nums);
    root->right = buildBST(m + 1, r, nums);
    return root;
}

TreeNode* sortedArrayToBTS(vector<int>& nums) {
    return buildBST(0, nums.size() - 1, nums);
}
