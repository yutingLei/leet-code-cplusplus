//
//  no_375_get_money_amount.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/6/1.
//

#include <iostream>
#include <vector>
#include "no_375_get_money_amount.hpp"

/// 暴力递归
/// 在范围L...R上, 如何赢得游戏
int No375Solution::process(int L, int R, int cost) {
    // 无效
    if (L > R) return -1;
    // 只有两个数了, 猜最小的性价比最高
    if (R - L == 1) return cost + L;
    // 当猜到最后一个数, 结束
    if (L == R) return cost;
    int minCost = INT_MAX;
    for (int i = L; i <= R; i++) {
        int v1 = process(L, i - 1, cost + i);
        int v2 = process(i + 1, R, cost + i);
        minCost = min(minCost, max(v1, v2));
    }
    return minCost;
}

/// 暴力递归+记忆化搜索
/// 在范围L...R上, 如何赢得游戏
int No375Solution::process1(int L, int R) {
    // 无效
    if (L > R) return -1;
    // 如果已经有值, 直接返回
    if (dp[L][R] != 0) return dp[L][R];
    // 只有两个数了, 猜最小的性价比最高
    if (R - L == 1) {
        dp[L][R] = L;
        return L;
    }
    // 当猜到最后一个数, 结束
    if (L == R) {
        dp[L][R] = 0;
        return 0;
    }
    int minCost = INT_MAX;
    for (int i = L; i <= R; i++) {
        int v1 = process1(L, i - 1) + i;
        int v2 = process1(i + 1, R) + i;
        minCost = min(minCost, max(v1, v2));
    }
    dp[L][R] = minCost;
    return dp[L][R];
}

/// 动态规划
int No375Solution::process2(int n) {
    // 定义dp[i][j]表示范围[i...j]中, 猜数需要的最小金额
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
        if (i < n) {
            dp[i][i + 1] = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            dp[i][j - 1] + j;
            dp[j + 1][j] + j;
        }
    }
    return dp[1][n];
}

int No375Solution::getMoneyAmount(int n) {
    dp = vector<vector<int>>(n + 1, vector<int>(n + 1));
    return process1(1, n);
}
