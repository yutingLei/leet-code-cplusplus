//
//  no_198_rob.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/30.
//

#ifndef no_198_rob_hpp
#define no_198_rob_hpp

#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 题目198: 打家劫舍
 *
 * 描述: 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的
 * 唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷
 * 闯入，系统会自动报警。给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报
 * 装置的情况下 ，一夜之内能够偷窃到的最高金额。
 */

class No198Solution {
private:
    unordered_map<int, int> records;
    int process(vector<int>& nums, int index);
    int process1(vector<int>& nums, int index);
    int process2(vector<int>& nums);
public:
    int rob(vector<int>& nums);
};
#endif /* no_198_rob_hpp */
