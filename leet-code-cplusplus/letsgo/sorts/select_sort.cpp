//
//  select_sort.cpp
//  leet-code-cplusplus
//
//  Created by Tomas on 2022/5/21.
//

#include "select_sort.hpp"
#include "swap.hpp"

void selectSort(vector<int>& arr) {
    if (arr.empty() || arr.size() < 2) {
        return;
    }
    size_t len = arr.size();
    for (int i = 0; i < len; i++) {
        int minNumIndex = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[minNumIndex]) {
                minNumIndex = j;
            }
        }
        swap(arr, i, minNumIndex);
    }
}
