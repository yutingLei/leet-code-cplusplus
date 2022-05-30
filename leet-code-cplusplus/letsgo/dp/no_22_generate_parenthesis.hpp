//
//  no_22_generate_parenthesis.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/30.
//

#ifndef no_22_generate_parenthesis_hpp
#define no_22_generate_parenthesis_hpp

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

/**
 * 题目22: 括号生成
 *
 * 描述: 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 */

class No22Solution {
private:
    void process(int N, int M, string path, vector<string>& ans);
public:
    vector<string> generateParenthesis(int n);
};
#endif /* no_22_generate_parenthesis_hpp */
