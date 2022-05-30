//
//  no_22_generate_parenthesis.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/30.
//

#include <iostream>
#include "no_22_generate_parenthesis.hpp"

/**
 *  阶梯思路:
 *
 *      1. 先暴力递归
 *      2. 动态规划
 */

void No22Solution::process(int N, int M, string path, vector<string>& ans) {
    // 当右括号数大于左括号数, 无效方案
    if (M > N) {
        return;
    }
    // 如果左右括号都为0了, 那么把答案加入ans
    if (N == 0 && M == 0) {
        ans.emplace_back(path);
        return;
    }
    // 放左括号
    if (N > 0)
        process(N - 1, M, path + "(", ans);
    // 不放左括号, 放右括号
    if (M > 0)
        process(N, M - 1, path + ")", ans);
}

// N/M表示使用了多少个左右括号了
void process1(int N, int M, int n, string path, vector<string>& ans) {
    // 当右括号用的比左括号多, 此方案直接无效
    if (M > N) {
        return;
    }
    // 当左括号或右括号超过了使用数量, 也是无效方案
    if (N > n || M > n) {
        return;
    }
    // 当左右括号使用同样的数量且都用完了, 把答案加入方案
    if (N == M && N == n) {
        ans.emplace_back(path);
        return;
    }
    // 使用左括号
    process1(N + 1, M, n, path + "(", ans);
    // 使用右括号
    process1(N, M + 1, n, path + ")", ans);
}

vector<string> No22Solution::generateParenthesis(int n) {
    if (n == 0) return vector<string>{""};
//    vector<string> ans;
//    process(n, n, "", ans);
//    return ans;
    
    vector<vector<string>> dp(n + 1);
    dp[0] = { "" };
    dp[1] = { "()" };
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            for (string p: dp[j]) {
                for (string q: dp[i - j - 1]) {
                    dp[i].emplace_back("(" + p + ")" + q);
                }
            }
        }
    }
    return dp[n];
}
