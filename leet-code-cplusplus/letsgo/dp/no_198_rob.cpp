//
//  no_198_rob.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/30.
//

#include "no_198_rob.hpp"

/// 暴力递归
int No198Solution::process(vector<int>& nums, int index) {
    if (index >= nums.size()) {
        return 0;
    }
    if (index == nums.size() - 1) {
        return nums[index];
    }
    // 选择不偷当前的房子
    int v1 = process(nums, index + 1);
    // 选择偷当前的房子
    int v2 = nums[index] + process(nums, index + 2);
    return max(v1, v2);
}

/// 暴力递归+记忆化搜索
int No198Solution::process1(vector<int>& nums, int index) {
    if (records.find(index) != records.end()) {
        return records[index];
    }
    if (index >= nums.size()) {
        return 0;
    }
    if (index == nums.size() - 1) {
        return nums[index];
    }
    // 选择不偷当前的房子
    int v1 = process(nums, index + 1);
    // 选择偷当前的房子
    int v2 = nums[index] + process(nums, index + 2);
    records[index] = max(v1, v2);
    return records[index];
}

/// 动态规划
int No198Solution::process2(vector<int> &nums) {
    size_t N = nums.size();
    // 定义dp[i]表示, 有i间房子, 可以获得的最大偷窃金额.
    vector<int> dp(N);
    dp[0] = nums[0];                // 一间房
    dp[1] = max(nums[1], nums[0]);  // 两间房
    for (int i = 2; i <= N; i++) {
        dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
    }
    return dp[N - 1];
}

int No198Solution::rob(vector<int> &nums) {
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];
    return process2(nums);
}
