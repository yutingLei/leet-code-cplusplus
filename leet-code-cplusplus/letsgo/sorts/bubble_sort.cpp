//
//  bubble_sort.cpp
//  leet-code-cplusplus
//
//  Created by Tomas on 2022/5/21.
//

#include "bubble_sort.hpp"
#include "swap.hpp"

void bublleSort(vector<int>& arr) {
    if (arr.empty() || arr.size() < 2) {
        return;
    }
    size_t N = arr.size();
    for (int end = N - 1; end >= 0; end--) {
        for (int second = 1; second <= end; second++) {
            if (arr[second] < arr[second - 1]) {
                swap(arr, second, second - 1);
            }
        }
    }
}
