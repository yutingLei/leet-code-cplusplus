//
//  no_109_sorted_list_2_bst.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/17.
//

#include "no_109_sorted_list_2_bst.hpp"

/**
 * 本地高度相似题目108, 只不过将有序数组改为有序链表.
 *
 * 解题思路:
 *      一: 将有序链表遍历, 保存到一个数组中, 然后可以用有序数组参考108题构建高度平衡二叉树.
 *          该方法会使用额外的O(N)空间.
 *      二: 预先遍历链表, 获取长度, 然后直接通过长度构建链表; 因为创建节点的时候不知道根节点,
 *          但可以先创建节点, 事后在填充节点的值.
 *
 */
TreeNode* No109Solution::buildBST(int l, int r, vector<int>& nums) {
    if (l > r) {
        return nullptr;
    }
    // 找到中点, 构建节点
    int m = (r + l) / 2;
    TreeNode* root = new TreeNode{ nums[m] };
    root->left = buildBST(l, m - 1, nums);
    root->right = buildBST(m + 1, r, nums);
    return root;
}

TreeNode* No109Solution::buildBST1(ListNode* head, int l, int r) {
    if (l > r) {
        return nullptr;
    }
    int m = (r + l + 1) / 2;
    TreeNode* root = new TreeNode();
    root->left = buildBST1(head, l, m - 1);
    root->val = head->val;
    head = head->next;
    root->right = buildBST1(head, m + 1, r);
    return root;
}

TreeNode* No109Solution::sortedListToBST(ListNode* head) {
    if (!head) return nullptr;
    // 方法一
//    vector<int> arr;
//    while (head) {
//        arr.emplace_back(head->val);
//        head = head->next;
//    }
//    return buildBST(0, arr.size() - 1, arr);
    
    // 方法二
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return buildBST1(head, 0, len - 1);
}
