//
//  main.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/16.
//

#include <iostream>
#include "generate_linked_list.hpp"
#include "no_19_remove_nth_from_end.hpp"
#include "no_21_merge_two_list.hpp"
#include "no_24_swap_pairs.hpp"
#include "no_25_reverse_k_group.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    LLGenerator generator = LLGenerator();
    
    // 创建一个链表
    ListNode* head = generator.create(vector<int> {1, 2, 3, 4, 5, 6, 6});
    generator.print(head);
    ListNode* reversedK = No25Solution().reverseKGroup(head, 3);
    generator.print(reversedK);
    generator.destroy(reversedK);
    
    return 0;
}
