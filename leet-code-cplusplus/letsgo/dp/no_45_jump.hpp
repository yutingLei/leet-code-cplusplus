//
//  no_45_jump.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/6/2.
//

#ifndef no_45_jump_hpp
#define no_45_jump_hpp

#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 题目45: 跳跃游戏II
 */

class No45Solution {
private:
    unordered_map<int, int> dp;
    int process(vector<int>& nums, int index);
    int process1(vector<int> &nums);
public:
    int jump(vector<int>& nums);
};
#endif /* no_45_jump_hpp */
