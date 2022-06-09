//
//  no_85_maximal_rectangle.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/6/8.
//

#include "no_85_maximal_rectangle.hpp"

int No85Solution::maxArea(vector<int> &heights) {
    if (heights.empty()) return 0;
    if (heights.size() == 1) return heights[0];
    
    int ans = 0;
    int size = (int)heights.size();
    vector<int> indexes(size);
    for (int i = 0; i < size; i++) {
        while (!indexes.empty() && heights[indexes.back()] > heights[i]) {
            int height = heights[indexes.back()];
            indexes.pop_back();
            int width = i - (indexes.empty() ? -1 : indexes.back()) - 1;
            ans = max(ans, height * width);
        }
        indexes.push_back(i);
    }
    while (!indexes.empty()) {
        int height = heights[indexes.back()];
        indexes.pop_back();
        int width = size - (indexes.empty() ? -1 : indexes.back()) - 1;
        ans = max(ans, height * width);
    }
    return ans;
}

int No85Solution::maximalRectangle(vector<vector<char>> &matrix) {
    if (matrix.empty()) return 0;
    int n = (int)matrix.size();
    int m = (int)matrix[0].size();
    
    // 求每一行的直方图
    int ans = 0;
    vector<int> heights(m + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '1') {
                heights[j] += 1;
            } else {
                heights[j] = 0;
            }
        }
        ans = max(ans, maxArea(heights));
    }
    return ans;
}
