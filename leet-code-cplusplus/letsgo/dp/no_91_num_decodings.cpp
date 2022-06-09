//
//  no_91_num_decodings.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/6/9.
//

#include "no_91_num_decodings.hpp"

// 暴力递归
// [0...i]位置上, 有多少种解码方法
int No91Solution::process1(string& s, int i) {
    // base case
    if (i > s.size()) return 0;
    if (i == s.size()) return 1;
    if (s[i] == '0') return 0;
    
    // 如果当前位置字符是'1'
    int cnt = 0;
    if (s[i] == '1') {
        cnt += process1(s, i + 1);
        cnt += process1(s, i + 2);
    } else if (s[i] == '2') {
        cnt += process1(s, i + 1);
        if (i + 1 < s.size() && s[i + 1] <= '6')
            cnt += process1(s, i + 2);
    } else {
        cnt += process1(s, i + 1);
    }
    return cnt;
}

// 暴力递归+记忆化搜索
// [0...i]位置上, 有多少种解码方法
int No91Solution::process2(string& s, int i, vector<int>& dp) {
    // base case
    if (i > s.size()) return 0;
    if (i == s.size()) {
        dp[i] = 1;
        return 1;
    }
    if (s[i] == '0') {
        dp[i] = 0;
        return 0;
    }
    if (dp[i] >= 0) return dp[i];
    
    // 如果当前位置字符是'1'
    int cnt = 0;
    if (s[i] == '1') {
        cnt += process2(s, i + 1, dp);
        cnt += process2(s, i + 2, dp);
    } else if (s[i] == '2') {
        cnt += process2(s, i + 1, dp);
        if (i + 1 < s.size() && s[i + 1] <= '6')
            cnt += process2(s, i + 2, dp);
    } else {
        cnt += process2(s, i + 1, dp);
    }
    dp[i] = cnt;
    return dp[i];
}

// 动态规划
int No91Solution::process3(string s) {
    int len = (int)s.length();
    
    // 默认空字符串也可以解码, 且解码方法为1
    s = " " + s;
    
    // dp[i]: 表示前i个字符的解码方法
    // 转移方程:
    //          dp[i] = dp[i-1]; 当 '1' <= s[i] <= '9'时
    //          dp[i] = dp[i-1] + d[i-2]; 当 '10' <= s[i-1] + s[i] <= '26'
    vector<int> dp(len + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= len; i++) {
        int x = s[i] - '0';
        int y = (s[i - 1] - '0') * 10 + x;
        if (1 <= x && x <= 9)
            dp[i] = dp[i - 1];
        if (10 <= y && y <= 26)
            dp[i] = dp[i - 1] + dp[i - 2]; // 或直接有: dp[i] += dp[i - 1]
    }
    return dp[len];
}

// 动态规划+空间优化
int No91Solution::process4(string s) {
    int len = (int)s.length();
    
    // 默认空字符串也可以解码, 且解码方法为1
    s = " " + s;
    
    // dp[i]: 表示前i个字符的解码方法
    // 转移方程:
    //          dp[i] = dp[i-1]; 当 '1' <= s[i] <= '9'时
    //          dp[i] = dp[i-1] + d[i-2]; 当 '10' <= s[i-1] + s[i] <= '26'
    // 注意: 此处转移方程仅与[i-1]和[i-2]相关, 可以使用3个变量来实现
    int pre = 1, pre2 = 0, ans = 0;
    for (int i = 1; i <= len; i++) {
        ans = 0;
        int x = s[i] - '0';
        int y = (s[i - 1] - '0') * 10 + x;
        if (1 <= x && x <= 9)
            ans = pre;
        if (10 <= y && y <= 26)
            ans = pre + pre2; // 或直接有: dp[i] += dp[i - 1]
        pre2 = pre;
        pre = ans;
    }
    return ans;
}

int No91Solution::numDecodings(string s) {
    // 暴力递归
    // return process1(s, 0);
    
    // 暴力递归+记忆化搜索
    // vector<int> dp(s.size() + 1, -1);
    // return process2(s, 0, dp);
    
    // 动态规划
    // return process3(s);
    
    // 动态规划+空间优化
    return process4(s);
}
