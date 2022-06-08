//
//  no_44_is_match.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/6/2.
//

#ifndef no_44_is_match_hpp
#define no_44_is_match_hpp

#include <stdio.h>
#include <string>

using namespace std;

/**
 * 题目44: 通配符匹配
 *
 * 描述:
 *      给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。
 *      '?' 可以匹配任何单个字符。
 *      '*' 可以匹配任意字符串（包括空字符串）。
 *      两个字符串完全匹配才算匹配成功。
 *      说明:
 *          s 可能为空，且只包含从 a-z 的小写字母。
 *          p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。
 */


class No44Solution {
    bool process(string& s, string& p, int si, int pi);
    bool process1(string& s, string& p, int si, int pi, vector<vector<int>>& dp);
    bool process2(string& s, string& p);
public:
    bool isMatch(string s, string p);
};
#endif /* no_44_is_match_hpp */
