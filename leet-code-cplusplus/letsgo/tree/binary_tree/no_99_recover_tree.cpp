//
//  no_99_recover_tree.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/16.
//

#include <stack>
#include "no_99_recover_tree.hpp"

using namespace std;

/**
 * 本题考察二叉搜索树在两个节点错误交换后如何恢复
 *
 * 本题思路:
 *      1. 二叉搜索树中序遍历一定是升序排列.
 *      2. 两个节点错误交换, 分两种情况, 第一种两个错误交换的节点相邻; 第二种, 两个错误的节点不相邻.
 *      3. 需要两个指针, 指出错误交换的两个节点.
 *
 * 进阶内容:
 *      上述解题思路需要O(N)内存空间, 想要达到O(1)空间, 此处需要了解Morris遍历法.
 *      中序遍历时利用栈特性, 我们可以发现, 最后出栈的一定是根节点, 通过最后的根节点可以找到右节点.
 *
 *      Morris 遍历法:
 *          1. 找到根节点, 判断是否有左儿子
 *              a. 有左儿子, 向左走一步, 然后找到左儿子的最右节点, 然后让该节点指向根节点.
 *              b. 没有左儿子,直接指向右儿子.
 *          2. 指向左儿子, 重复上述步骤.
 *          3. 当发现左儿子的最右节点的右儿子指向了根节点, 此时应该断开节点, 并且指向根节点的右儿子
 *
 *      核心就是通过两次遍历达到遍历所有节点:
 *          第一次遍历: 主要是设置遍历顺序, 能够回到根节点.
 *          第二次遍历: 第二次遍历就是遍历所有节点并且处理逻辑, 还有就是断开第一次遍历设置的循环.
 */
void No99Solution::recoverTree(TreeNode* root) {
    
    // 中序遍历
    stack<TreeNode*> stk;
    TreeNode* cur = root;
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* pre = nullptr;
    TreeNode* predessor = nullptr;
//    while (!stk.empty() || cur) {
//        if (cur) {
//            stk.push(cur);
//            cur = cur->left;
//        }
//        TreeNode* node = stk.top();
//        stk.pop();
//        // 找到错误交换的位置
//        // 为什么判断first是否赋值?
//        // 情况一: 两个错误位置相邻, 那么恰好赋值了这两个位置
//        // 情况二: 若两个位置不相邻, 那么一定还能找到另外一个位置并且赋值给second,
//        //        此时已经找到了两个位置, 所以可以直接退出循环
//        if (pre && pre->val > node->val) {
//            second = node;
//            if (!first)
//                first = pre;
//            else
//                break;
//        }
//        pre = node;
//        cur = node->right;
//    }
    
    while (cur) {
        // 1. 判断是否有左儿子
        if (cur->left) {
            // 2. 向左走一步
            predessor = cur->left;
            // 3. 找到左儿子的最右节点
            while (predessor->right && predessor->right != cur) {
                predessor = predessor->right;
            }
            // 4. 判断最右节点是否为空,为空则指向根节点, 然后继续向左
            if (predessor->right == nullptr) {
                predessor->right = cur;
                cur = cur->left;
            }
            // 5. 最右节点不为空, 那么一定是指向了根节点, 此时应该断开
            else {
                if (pre && pre->val > cur->val) {
                    second = cur;
                    if (!first)
                        first = pre;
                    else
                        break;
                }
                
                predessor->right = nullptr;
                pre = cur;
                cur = cur->right;
            }
        }
        // 没有左儿子, 直接指向右儿子
        else {
            if (pre && pre->val > cur->val) {
                second = cur;
                if (!first)
                    first = pre;
                else
                    break;
            }
            pre = cur;
            cur = cur->right;
        }
    }
    
    if (first && second) {
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
}
