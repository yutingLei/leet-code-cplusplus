//
//  insert_sort.cpp
//  leet-code-cplusplus
//
//  Created by Tomas on 2022/5/21.
//

#include "insert_sort.hpp"
#include "swap.hpp"

void insertSort(vector<int>& arr) {
    if (arr.empty() || arr.size() < 2) {
        return;
    }
    for (int i = 1; i < arr.size(); i++) {
//        int curNumIndex = i;
//        while (curNumIndex - 1 >= 0 && arr[curNumIndex] > arr[curNumIndex - 1]) {
//            swap(arr, curNumIndex, curNumIndex - 1);
//            curNumIndex--;
//        }
        for (int pre = i - 1; pre >= 0 && arr[pre] > arr[pre + 1]; pre--) {
            swap(arr, pre, pre + 1);
        }
    }
}
