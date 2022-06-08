//
//  no_72_min_distance.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/6/8.
//

#include <vector>
#include "no_72_min_distance.hpp"

/// 求 word1 -> word2 最小变化步数:
/// word1长度为: n
/// word2长度为: m
///
/// case1: n 或 m 中有一个是空字符串, 那么最小变化步数为 n + m
int No72Solution::minDistance(string word1, string word2) {
    int n = (int)word1.size();
    int m = (int)word2.size();
    // 如果有空字符串
    if (n == 0 || m == 0) return n + m;
    
    // 定义状态数组
    // dp[i][j]: word1 前 i 个字符转换为 word2 前 j 个字符所需最小步数.
//    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
//
//    // 先赋值边界
//    for (int i = 0; i < n + 1; i++) {
//        dp[i][0] = i;
//    }
//    for (int j = 0; j < m + 1; j++) {
//        dp[0][j] = j;
//    }
//    // 状态转换
//    for (int i = 1; i < n + 1; i++) {
//        for (int j = 1; j < m + 1; j++) {
//            int left = dp[i][j - 1];
//            int up = dp[i - 1][j];
//            int leftUp = dp[i - 1][j - 1];
//            if (word1[i - 1] != word2[j - 1])
//                leftUp += 1;
//            dp[i][j] = min(left, min(up, leftUp));
//        }
//    }
//    return dp[n][m];
    
    // 进阶
    vector<int> dp(m + 1);
    for (int j = 0; j < m + 1; j++) {
        dp[j] = j;
    }
    
    int leftUp = dp[0];
    for (int i = 1; i < n + 1; i++) {
        leftUp = dp[0];
        dp[0] = i;
        for (int j = 1; j < m + 1; j++) {
            int pre = dp[j];
            dp[j] = min((min(dp[j - 1], dp[j]) + 1), leftUp + int(word1[i - 1] != word2[j - 1]));
            leftUp = pre;
        }
    }
    return dp[m];
}
