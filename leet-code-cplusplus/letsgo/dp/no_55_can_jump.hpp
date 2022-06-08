//
//  no_55_can_jump.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/6/6.
//

#ifndef no_55_can_jump_hpp
#define no_55_can_jump_hpp

#include <stdio.h>
#include <vector>

using namespace std;

/**
 * 题目55: 跳跃游戏
 *
 * 描述: 给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
 *      数组中的每个元素代表你在该位置可以跳跃的最大长度。
 *      判断你是否能够到达最后一个下标。
 */

class No55Solution {
private:
    bool process1(vector<int>& nums, int index);
    vector<bool> records;
    bool process2(vector<int>& nums, int index);
    bool process3(vector<int>& nums);
public:
    bool canJump(vector<int>& nums);
};
#endif /* no_55_can_jump_hpp */
