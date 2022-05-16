//
//  tree_node.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/16.
//

#ifndef tree_node_hpp
#define tree_node_hpp

#include <stdio.h>

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val): val(_val), left(nullptr), right(nullptr) {}
    TreeNode(int _val, TreeNode* _left, TreeNode* _right): val(_val), left(_left), right(_right) {}
};

#endif /* tree_node_hpp */
