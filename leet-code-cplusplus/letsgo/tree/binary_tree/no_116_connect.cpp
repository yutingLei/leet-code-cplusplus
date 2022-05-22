//
//  no_116_connect.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/19.
//

#include <queue>
#include "no_116_connect.hpp"

using namespace std;

/**
 * 解题思路:
 *      方法一: 通过层序遍历, 将每一层的值保存, 且将这些节点连接起来即可.
 *      方法二: 递归法, 判断当前节点是否是叶节点, 如果是, 直接退出;如果不是叶节点
 *             直接将该节点的左右子树连接起来; 同时判断当前节点的next值, 如果不为空,
 *             将该节点的右子树的next连接到该节点next的左子树, 即同一层连接起来.
 *      方法三: 还是层序遍历, 不过只需使用额外的指针, 在每一层遍历时, 通过每个节点的next
 *             是否为空来遍历这一层.
 */

void No116Solution::helper(Node* node) {
    // 节点为空
    if (!node) return;
    // 是叶节点
    if (!node->left) return;
    // 连接左右子树
    node->left->next = node->right;
    // 如果当前节点与其它子树有连接, 连接这两个东东
    if (node->next) {
        node->right->next = node->next->left;
    }
    // 走左子树
    helper(node->left);
    // 走右子树
    helper(node->right);
}

Node* No116Solution::connect(Node* root) {
    // 1. 方法一:层序遍历法
//    if (!root) return root;
//    queue<Node*> q;
//    q.push(root);
//    Node* tmp = nullptr;
//    while (!q.empty()) {
//        tmp = nullptr;
//        size_t qsize = q.size();
//        for (int i = 0; i < qsize; i++) {
//            Node* node = q.front();
//            q.pop();
//            if (!tmp) {
//                tmp = node;
//            } else {
//                tmp->next = node;
//                tmp = tmp->next;
//            }
//            if (node->left && node->right) {
//                q.push(node->left);
//                q.push(node->right);
//            }
//        }
//    }
//    return root;
    
    // 2. 方法二: 递归
//    helper(root);
//    return root;
    
    // 3. 方法三: 层序遍历+额外指针
    if (!root) return root;
    Node* p = root;
    while (p->left) {
        // 遍历这一层
        Node* head = p;
        while (head) {
            head->left->next = head->right;
            if (head->next) {
                head->right->next = head->next->left;
            }
            head = head->next;
        }
        p = p->left;
    }
    return root;
}
