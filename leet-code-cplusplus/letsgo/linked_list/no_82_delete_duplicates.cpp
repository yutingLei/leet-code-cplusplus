//
//  no_82_delete_duplicates.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/26.
//

#include <queue>
#include "no_82_delete_duplicates.hpp"

using namespace std;

/**
 * 解题思路:
 *      方法一: 因为规定取值范围为[-100,100], 我们可以申请一个200长度的数组, 记录出现在节点中的值的个数.
 *             然后在遍历链表时, 发现当前链表出现的值在数组中个数大于0, 删除当前节点.
 *
 *      方法二: 不使用额外的控件存储节点中值出现的个数, 我们在遍历时, 判断当前节点与下一个节点的值是否一样,
 *             若不一样, cur直接向下移动; 若一样, 删除下一个节点, 且用标志为标记, 在移动之前需删除当前节点.
 */

ListNode* No82Solution::deleteDuplicates(ListNode *head) {
    if (!head || !head->next) return head;
    
    // 方法一
//    vector<int> cnts(200);
//    ListNode* pre = head;
//    while (pre) {
//        cnts[pre->val + 100]++;
//        pre = pre->next;
//    }
//
//    ListNode* last = nullptr;
//    pre = head;
//    while (pre) {
//        if (cnts[pre->val + 100] > 1) {
//            if (!last) {
//                head = pre->next;
//                delete pre;
//                pre = head;
//            } else {
//                last->next = pre->next;
//                delete pre;
//                pre = last->next;
//            }
//        } else {
//            last = pre;
//            pre = pre->next;
//        }
//    }
    
    // 方法二
    ListNode* last = nullptr;
    ListNode* cur = head;
    bool flag = false;
    while (cur) {
        // 如果与下一个节点值相同, 删除下一个值
        if (cur->next && cur->val == cur->next->val) {
            flag = true;
            ListNode* next = cur->next->next;
            delete cur->next;
            if (!last) {
                head = next;
            }
            cur->next = next;
            continue;
        }
        // 如果与下一个值不相同
        if (flag) {
            flag = false;
            ListNode* next = cur->next;
            delete cur;
            cur = next;
            if (last) {
                last->next = cur;
            }
            continue;
        }
        last = cur;
        cur = cur->next;
    }
    
    return head;
}

