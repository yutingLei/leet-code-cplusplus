//
//  no_10_is_match.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/30.
//

#include <vector>
#include "no_10_is_match.hpp"

// 从右侧开始匹配, 两个字符串是否匹配
// s[0...i]上的字符串是否与p[0...j]上的字符串相匹配
bool process(string s, string p, int i, int j) {
    // 边界条件
    if (i >= 0 && j < 0) {
        return false;
    }
    if (i < 0 && j >= 0) {
        return p[j] == '*' && j == 1;
    }
    if (i < 0 && j < 0) {
        return i == j;
    }
    // 情况1: s[i] == p[j] 或 p[j] == '.'
    if (s[i] == p[j] || p[j] == '.') {
        return process(s, p, i - 1, j - 1);
    }
    
    // 情况2: s[i] != p[j] 且 p[j] 不是 '*'
    if (p[j] != '*') {
        return false;
    }
    // s[i] != p[j], 但是 p[j] 是 '*'
    // 如果s[i] == p[j-1] 或者 p[j-1] == '.'
    if (s[i] == p[j - 1] || p[j - 1] == '.') {
        bool case1 = process(s, p, i, j - 2);
        //     2. 利用 '*' 抵消前一个字符的影响
        bool case2 = process(s, p, i - 1, j - 2);
        //     3. 可能需要 '*' 抵消多个字符影响, 那么此处我们消除s上最后一个字符的影响
        bool case3 = process(s, p, i - 1, j);
        return case1 || case2 || case3;
    }
    return process(s, p, i, j - 2);
}

bool No10Solution::isMatch(string s, string p) {
//    if (s.empty() && p.empty()) return true;
//    return process(s, p, s.size() - 1, p.size() - 1);
    
    size_t N = s.size();
    size_t M = p.size();
    // 定义dp数组
    // dp[i][j]: 描述字符串s[0...i)位置,字符串p[0...j)位置是否匹配.
    vector<vector<bool>> dp(N + 1, vector<bool>(M + 1));
    dp[0][0] = true;
    for (int j = 1; j < M; j++) {
        if (p[j - 1] == '*')
            dp[0][j] = dp[0][j - 2];
    }
    // 边界条件
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                if (s[i - 1] == p[j - 2] || p[j - 2] == '.') {
                    dp[i][j] = dp[i][j - 2] || dp[i - 1][j - 2] || dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i][j - 2];
                }
            }
        }
    }
    return dp[N][M];
}
