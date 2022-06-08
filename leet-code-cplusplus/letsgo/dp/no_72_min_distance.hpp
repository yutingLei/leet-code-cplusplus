//
//  no_72_min_distance.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/6/8.
//

#ifndef no_72_min_distance_hpp
#define no_72_min_distance_hpp

#include <stdio.h>
#include <string>

using namespace std;

/**
 * 题目72: 最小编辑距离
 *
 * 描述: 给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。
 *      你可以对一个单词进行如下三种操作：
 *          插入一个字符
 *          删除一个字符
 *          替换一个字符
 */

class No72Solution {
public:
    int minDistance(string word1, string word2);
};
#endif /* no_72_min_distance_hpp */
