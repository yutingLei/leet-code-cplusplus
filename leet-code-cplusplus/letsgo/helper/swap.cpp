//
//  swap.cpp
//  leet-code-cplusplus
//
//  Created by Tomas on 2022/5/21.
//

#include "swap.hpp"

void swap(vector<int>& arr, int a, int b) {
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}
