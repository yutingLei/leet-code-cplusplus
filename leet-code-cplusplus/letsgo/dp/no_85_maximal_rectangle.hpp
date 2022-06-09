//
//  no_85_maximal_rectangle.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/6/8.
//

#ifndef no_85_maximal_rectangle_hpp
#define no_85_maximal_rectangle_hpp

#include <stdio.h>
#include <vector>

using namespace std;

/**
 * 题目85: 最大矩形
 *
 * 描述: 给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
 */

class No85Solution {
private:
    int maxArea(vector<int>& heights);
public:
    int maximalRectangle(vector<vector<char>>& matrix);
};
#endif /* no_85_maximal_rectangle_hpp */
