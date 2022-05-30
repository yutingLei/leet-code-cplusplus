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
#include "no_22_generate_parenthesis.hpp"
#include "no_10_is_match.hpp"
#include "no_198_rob.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    No198Solution so = No198Solution();
    vector<int> input = {1, 2, 3, 1};
    cout << so.rob(input) << endl;
    
    
    return 0;
}
