//
//  no_44_is_match.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/6/2.
//

#include <vector>
#include "no_44_is_match.hpp"

// 检测si与pi位置上的字符是否匹配
bool No44Solution::process(string& s, string& p, int si, int pi) {
    // base case
    if (pi < 0) return si < 0;
    if (si < 0) {
        if (p[pi] == '*')
            return process(s, p, si, pi - 1);
        return false;
    }
    // 如果匹配符为: '?'
    // 或者此时两个位置的字符相等
    if (p[pi] == '?' || s[si] == p[pi]) {
        return process(s, p, si - 1, pi - 1);
    }
    // 如果匹配符为: '*'
    if (p[pi] == '*') {
        // 抵消一个字符
        int c1 = process(s, p, si - 1, pi);
        // 直接匹配空字符
        int c2 = process(s, p, si, pi - 1);
        return c1 || c2;
    }
    return false;
}

// 检测si与pi位置上的字符是否匹配+记忆化搜索
bool No44Solution::process1(string& s, string& p, int si, int pi, vector<vector<int>>& dp) {
    // base case
    if (pi < 0) return si < 0;
    if (si < 0) {
        if (p[pi] == '*') {
            return process1(s, p, si, pi - 1, dp);
        }
        return false;
    }
    if (si >= 0 && pi >= 0 && dp[si][pi] != -1) {
        return dp[si][pi] == 1 ? true : false;
    }
    // 如果匹配符为: '?'
    // 或者此时两个位置的字符相等
    if (p[pi] == '?' || s[si] == p[pi]) {
        dp[si][pi] = process1(s, p, si - 1, pi - 1, dp) ? 1 : 0;
        return dp[si][pi];
    }
    // 如果匹配符为: '*'
    if (p[pi] == '*') {
        // 抵消一个字符
        int c1 = process1(s, p, si - 1, pi, dp);
        // 直接匹配空字符
        int c2 = process1(s, p, si, pi - 1, dp);
        dp[si][pi] = (c1 || c2) ? 1 : 0;
        return dp[si][pi];
    }
    dp[si][pi] = 0;
    return false;
}

// 记忆化搜索精细化
bool No44Solution::process2(string& s, string& p) {
    int sl = (int)s.length();
    int pl = (int)p.length();
    vector<vector<bool>> dp(sl + 1, vector<bool>(pl + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= pl; i++) {
        if (p[i - 1] == '*')
            dp[0][i] = true;
        else
            break;
    }
    for (int i = 1; i <= sl; i++) {
        for (int j = 1; j <= pl; j++) {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
        }
    }
    return dp[sl][pl];
}

bool No44Solution::isMatch(string s, string p) {
    //    int sl = (int)s.length();
    //    int pl = (int)p.length();
    //    vector<vector<int>> dp(sl, vector<bool>(pl, -1));
    //    return process1(s, p, sl - 1, pl - 1, dp);
    
    return process2(s, p);
}
