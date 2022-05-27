//
//  no_147_insertion_sort_list.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/27.
//

#include "no_147_insertion_sort_list.hpp"

/**
 * 插入排序原理: 已有序中, 将新加入的元素插入.
 */

ListNode* No147Solution::insertionSortList(ListNode *head) {
    if (!head || !head->next) return head;
    
    ListNode* dummy = new ListNode(0);
    ListNode* cur = head;
    
    // 开始排序
    while (cur) {
        head = dummy;
        ListNode* next = cur->next;
        cur->next = nullptr;
        
        if (!head->next) {
            head->next = cur;
        } else {
            while (head->next) {
                if (head->next->val >= cur->val) {
                    cur->next = head->next;
                    head->next = cur;
                    break;
                }
                head = head->next;
            }
            if (!head->next) {
                head->next = cur;
            }
        }
        cur = next;
    }
    
    head = dummy->next;
    delete dummy;
    return head;
}

#include <string>
#include <unordered_map>

using namespace std;

class AllOne {
    // hash map 记录数量
    unordered_map<string, int> cnts;
    pair<string, int> maxRcd;
    pair<string, int> minRcd;
public:
    AllOne() {
    }
    
    void inc(string key) {
        cnts[key]++;
    }
    
    void dec(string key) {
        int cnt = cnts[key];
        if (cnt == 0) {
            cnts.erase(key);
        } else {
            cnts[key]--;
        }
    }
    
    string getMaxKey() {
        return maxRcd.first;
    }
    
    string getMinKey() {
        return minRcd.first;
    }
};
