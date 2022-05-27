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
#include "no_61_rotate_right.hpp"
#include "no_82_delete_duplicates.hpp"
#include "no_147_insertion_sort_list.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    LLGenerator generator = LLGenerator();
    
    // 创建一个链表
    ListNode* head = generator.create(vector<int> {3,1,2,5,4});
    generator.print(head);
    ListNode* reversedK = No147Solution().insertionSortList(head);
    generator.print(reversedK);
    generator.destroy(reversedK);
    
    return 0;
}
