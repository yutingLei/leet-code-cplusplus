//
//  select_sort.hpp
//  leet-code-cplusplus
//
//  Created by Tomas on 2022/5/21.
//

#ifndef select_sort_hpp
#define select_sort_hpp

#include <stdio.h>
#include <vector>

using namespace std;

/**
 * 选择排序
 *
 * 排序思想:
 *      1. 在0～n中选择一个最小的值, 将其放在0位置
 *      2. 在1～n中选择一个最小的值, 将其放在1位置
 *      3. 在2～n中选择一个最小的值, 将其放在2位置
 *      ...
 *      i. 在(i-1)~n中选择一个最小的值, 将其放在i-1位置
 *      ...
 *      n. 在(n-1)~n中选择一个最小的值, 将其放在n-1位置
 *
 */
void selectSort(vector<int>& arr);
#endif /* select_sort_hpp */
