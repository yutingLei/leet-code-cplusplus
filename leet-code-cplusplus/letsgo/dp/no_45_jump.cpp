//
//  no_45_jump.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/6/2.
//

#include "no_45_jump.hpp"

// 暴力递归+记忆化搜索
// 处于index位置时, 还需要最少多少步才能到达末尾位置
int No45Solution::process(vector<int>& nums, int index) {
    if (dp.find(index) != dp.end())
        return dp[index];
    
    // 刚好在末尾位置, 跳0步
    if (index == nums.size() - 1) return 0;
    
    // 尝试
    int minStep = INT_MAX;
    for (int i = nums[index]; i >= 1; i--) {
        if (index + i < nums.size()) {
            int step = process(nums, index + i);
            if (step >= 0) {
                minStep = min(minStep, step + 1);
            }
        }
    }
    dp[index] = minStep == INT_MAX ? -1 : minStep;
    return dp[index];
}

// 动态规划
int No45Solution::process1(vector<int> &nums) {
    int len = (int)nums.size();
    vector<int> dp(len, -1);
    dp[len - 1] = 0;
    for (int i = len - 2; i >= 0; i--) {
        int minStep = INT_MAX;
        for (int j = nums[i]; j >= 1; j--) {
            if (i + j < len) {
                int step = dp[i + j];
                if (step >= 0) {
                    minStep = min(minStep, step + 1);
                }
            }
        }
        dp[i] = minStep == INT_MAX ? -1 : minStep;
    }
    
    return dp[0];
}

int No45Solution::jump(vector<int> &nums) {
    return process1(nums);
}
