//
//  no_91_num_decodings.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/6/9.
//

#ifndef no_91_num_decodings_hpp
#define no_91_num_decodings_hpp

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

/**
 * 题目91: 解码方法
 *
 * 描述: 一条包含字母 A-Z 的消息通过以下映射进行了 编码 ：
 *      'A' -> "1"
 *      'B' -> "2"
 *      ...
 *      'Z' -> "26"
 *
 *      要 解码 已编码的消息，所有数字必须基于上述映射的方法，反向映射回字母（可能有多种方法）。
 *      例如，"11106" 可以映射为：
 *          "AAJF" ，将消息分组为 (1 1 10 6)
 *          "KJF" ，将消息分组为 (11 10 6)
 *      注意，消息不能分组为  (1 11 06) ，因为 "06" 不能映射为 "F" ，这是由于 "6" 和 "06" 在映射中并不等价。
 *      给你一个只含数字的 非空 字符串 s ，请计算并返回 解码 方法的 总数 。
 *      题目数据保证答案肯定是一个 32 位 的整数。
 *
 * 地址: https://leetcode.cn/problems/decode-ways/
 */

class No91Solution {
    // 暴力递归
    int process1(string& s, int index);
    // 暴力递归+记忆化搜索
    int process2(string& s, int index, vector<int>& dp);
    // 动态规划
    int process3(string s);
    // 动态规划控件优化
    int process4(string s);
public:
    int numDecodings(string s);
};
#endif /* no_91_num_decodings_hpp */
