//
//  no_55_can_jump.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/6/6.
//

#include "no_55_can_jump.hpp"

bool No55Solution::canJump(vector<int> &nums) {
    //    return process1(nums, 0);
    
    //    records = vector<bool>(nums.size(), false);
    //    return process2(nums, 0);
    
    return process3(nums);
}

// 暴力递归法
// 当走到index下标位置时, 能否跳到最后一个位置
bool No55Solution::process1(vector<int> &nums, int index) {
    // base case
    // 1. 如果当前下标已经超过或处于末尾位置, 直接返回true.
    // 2. 如果当前位置与它可跳跃最大步数超过或处于末尾位置, 也直接返回true.
    if ((index >= nums.size() - 1) || (nums[index] + index) >= nums.size() - 1)
        return true;
    
    // 否则, 给我尝试所有可能.
    bool canJump = false;
    for (int i = nums[index]; i >= 1; i--) {
        if (process1(nums, index + i)) {
            canJump = true;
            break;
        }
    }
    return canJump;
}

// 暴力递归+记忆搜索
bool No55Solution::process2(vector<int> &nums, int index) {
    // base case
    // 1. 如果当前下标已经超过或处于末尾位置, 直接返回true.
    // 2. 如果当前位置与它可跳跃最大步数超过或处于末尾位置, 也直接返回true.
    if ((index >= nums.size() - 1) || (nums[index] + index) >= nums.size() - 1) {
        records[index] = true;
        return true;
    }
    
    // 如果已经有记录了, 直接返回
    if (records[index]) return true;
    
    // 否则, 给我尝试所有可能.
    bool canJump = false;
    for (int i = nums[index]; i >= 1; i--) {
        if (process2(nums, index + i)) {
            canJump = true;
            break;
        }
    }
    if (canJump) records[index] = true;
    return canJump;
}

// 动态规划
// 在枚举所有元素时, 每次都找到能够跳到最远的地方, 如果最远的地方小于了当前位置,
// 表明不能够跳到末尾
bool No55Solution::process3(vector<int>& nums) {
    int maxPos = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i > maxPos) return false;
        maxPos = max(maxPos, nums[i] + i);
    }
    return true;
}
