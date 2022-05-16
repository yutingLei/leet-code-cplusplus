//
//  no_96_different_tree.cpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/16.
//

#include <vector>
#include "no_96_different_tree.hpp"
using namespace std;

/**
 * 本地考察二叉搜索树构建
 *
 * 本题思路: 已知范围[1,n], 需要知道能构建的所有二叉搜索树个数.
 *      1. 以i(1 <= i <= n)为根节点, 左子树取值范围[1,i-1], 右子树取值范围[i+1,n].
 *      2. 在取值范围[1,i-1]中构建所有的左子树可能, 在[i+1,n]中构建所有的右子树可能.
 *      3. 就将构建以i为根节点分解为构建左子树与右子树所有可能的组合.
 *      4. 同理, 构建左子树与右子树同样适用上述方法, 将一个大问题分解为两个相同的小问题.
 *
 *      进阶:
 *          设 G(n): 表示长度序列为n能构建的所有二叉搜索树可能.
 *          设 F(i,n): 表示以i为根节点, 序列长度为n能构成的二叉搜索树个数.
 *          则有: G(n) = F(1,n) + F(2,n) + F(3,n) + ... + F(n, n)
 *          由F(i,n)定义可知: F(i,n) 由左子树范围[1,i-1],右子树范围[i+1,n]所有组合构成.
 *          根据G(n)定义描述可知, [1,i-1]所有的二叉搜索树可能正是G(i-1), [i+1,n]所有的
 *          二叉搜索树可能正是G(n-i).
 *          所有又有 F(i,n) = G(i-1)*G(n-i)
 *          所以有: G(n) = G(0)*G(n-1) + G(1)*G(n-2) + ... + G(n-1)*G(0)
 *
 *      再进阶:
 *          由 "Catalan数" 定义推导式可知:
 *          G(n+1) = G(n)(2 * (2n + 1))/(n + 2) (G(0) = 1, i >= 0)
 *
 *
 * 本题有多重解法
 */

/** 枚举所有创建可能 */
int numTrees(int start, int end) {
    if (start > end) {
        return 0;
    }
    int cnt = 1;
    for (int i = start; i <= end; i++) {
        if (i - 1 <= start) {
            cnt += numTrees(i + 1, end);
        } else if (i + 1 >= end) {
            cnt += numTrees(start, i - 1);
        } else {
            cnt += numTrees(start, i - 1) * numTrees(i + 1, end);
        }
    }
    return cnt;
}

int numTrees(int n) {
    if (n <= 0) {
        return 0;
    }
    // 1. 枚举所有可能
    // return numTrees(1, n);
    
    // 2. 进阶
    //vector<int> G(n + 1);
    //G[0] = 1; G[1] = 1;
    //for (int i = 2; i <= n; i++) {
    //    for (int j = 1; j <= i; j++) {
    //        G[i] += G[j - 1] * G[i - j];
    //    }
    //}
    // return G[n];
    
    // 3. 再进阶
    int C = 1;
    for (int i = 0; i < n; i++) {
        C = C * (2 * (2 * i + 1)) / (i + 2);
    }
    return C;
}
