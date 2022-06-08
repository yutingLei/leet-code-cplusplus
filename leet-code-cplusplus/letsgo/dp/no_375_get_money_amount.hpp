//
//  no_375_get_money_amount.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/6/1.
//

#ifndef no_375_get_money_amount_hpp
#define no_375_get_money_amount_hpp

#include <stdio.h>
#include <unordered_map>

using namespace std;

/**
 * 题目375: 猜数字大小 II
 *
 * 描述:
 * 我们正在玩一个猜数游戏，游戏规则如下：
 *      我从 1 到 n 之间选择一个数字。
 *      你来猜我选了哪个数字。
 *      如果你猜到正确的数字，就会 赢得游戏 。
 *      如果你猜错了，那么我会告诉你，我选的数字比你的 更大或者更小 ，并且你需要继续猜数。
 *      每当你猜了数字 x 并且猜错了的时候，你需要支付金额为 x 的现金。如果你花光了钱，就会 输掉游戏 。
 *      给你一个特定的数字 n ，返回能够 确保你获胜 的最小现金数，不管我选择那个数字 。
 */

class No375Solution {
private:
    vector<vector<int>> dp;
    int process(int L, int R, int cost);
    int process1(int L, int R);
    int process2(int n);
public:
    int getMoneyAmount(int n);
};
#endif /* no_375_get_money_amount_hpp */
