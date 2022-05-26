//
//  no_61_rotate_right.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/26.
//

#include <unordered_map>
#include "no_61_rotate_right.hpp"

using namespace std;

/**
 * 解题思路:
 *      方法一: 用一个map记录一个节点之前的节点位置（会超时）
 *      方法二: 将链表首尾相连, 申明一个指针指向尾节点, 每次一旋转将指针指向它的下一个节点.
 *             当停止旋转时,
 */

ListNode* No61Solution::rotateRight(ListNode *head, int k) {
    // 如果为空或者只有一个节点, 直接返回
    if (!head || !head->next) return head;
    
    // 获取链表长度同时记录尾节点
    int len = 0;
    ListNode* pre = head;
    ListNode* tail = nullptr;
    while (pre) {
        if (pre->next) {
            tail = pre->next;
        }
        pre = pre->next;
        len++;
    }
    
    // 如果旋转次数刚好是链表长度的整数倍, 就是原来的链表
    if (k % len == 0) return head;

    
    // 6
    // 123456
    //
    // 612345
    // 561234
    // 456123
    // 345612
    // 234561
    // 123456
    // 如上面示例:
    //      1. 取模后, 表示具体旋转了几次
    //      2. 通过链表长度减去旋转次数, 可以找到旋转后的尾节点
    //      3. 停止旋转后, pre指向尾节点
    int times = len - (k % len);
    pre = head;
    while (--times) {
        pre = pre->next;
    }
    // 1.此时我们将原链表首尾相连形成环
    // 2.pre->next一定是头节点
    // 3.打破环
    tail->next = head;
    head = pre->next;
    pre->next = nullptr;
    return head;
}
