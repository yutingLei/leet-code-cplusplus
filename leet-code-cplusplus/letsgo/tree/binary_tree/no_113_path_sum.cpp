//
//  no_113_path_sum.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/19.
//

#include <queue>
#include <unordered_map>
#include "no_113_path_sum.hpp"

using namespace std;

/**
 * 本地是题112的升级版
 *
 * 解题思路:
 *      可以参考112的思路, 通过递归的方式, 可以确认是否有这么一条路, 在确认的过程
 *      中需要保存路径的值.
 */

// 用于保存最终结果
vector<vector<int>> ans;
// 用于保存每一次尝试的路径值
vector<int>path;
// 开始尝试
void helper(TreeNode* node, int targetSum) {
    // 如果当前节点为空, 直接返回
    if (!node) {
        return;
    }
    // 把当前值装进路径中
    path.emplace_back(node->val);
    int target = targetSum - node->val;
    // 如果当前节点是叶节点
    if (!node->left && !node->right && target == 0) {
        ans.emplace_back(path);
    }
    // 去左右子树中寻找
    helper(node->left, target);
    helper(node->right, target);
    // 回溯的时候, 需要推出当前值
    path.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    helper(root, targetSum);
    return ans;
}

void helperR(TreeNode* node, int num) {
    if (!node) return;
    path.emplace_back(node->val);
    num -= node->val;
    if (!node->left && !node->right && num == 0) {
        ans.emplace_back(path);
    }
    helperR(node->left, num);
    helperR(node->right, num);
    path.pop_back();
}

unordered_map<TreeNode*, TreeNode*> records;
vector<int> getPath(TreeNode* node) {
    vector<int> tmp;
    while (node) {
        tmp.emplace_back(node->val);
        node = records[node];
    }
    reverse(tmp.begin(), tmp.end());
    return tmp;
}
vector<vector<int>> pathSumR(TreeNode* root, int targetNum) {
    // 递归法
//    helperR(root, targetNum);
//    return ans;
    
    // 迭代
    
    if (!root) return ans;
    queue<TreeNode*> nodeq;
    nodeq.push(root);
    queue<int> numq;
    numq.push(targetNum);
    while (!nodeq.empty()) {
        size_t qsize = nodeq.size();
        for (int i = 0; i < qsize; i++) {
            TreeNode* node = nodeq.front();
            nodeq.pop();
            int num = numq.front();
            numq.pop();
            if (!node->left && !node->right && node->val == num) {
                ans.emplace_back(getPath(node));
            }
            if (node->left) {
                nodeq.push(node->left);
                numq.push(num - node->val);
                records[node->left] = node;
            }
            if (node->right) {
                nodeq.push(node->right);
                numq.push(num - node->val);
                records[node->right] = node;
            }
        }
    }
    return ans;
}
