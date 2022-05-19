//
//  no_116_connect.hpp
//  leet-code-cplusplus
//
//  Created by admin on 2022/5/19.
//

#ifndef no_116_connect_hpp
#define no_116_connect_hpp

#include <stdio.h>
#include "node.hpp"

/**
 * 题目116: 填充每个节点的下一个右侧节点指针
 *
 * 描述:
 *      给定一个 完美二叉树. 其所有叶子节点都在同一层, 每个父节点都有两个子节点. 二叉树定义如下:
 *      填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
 *      初始状态下，所有 next 指针都被设置为 NULL。
 */
Node* connect(Node* root);
#endif /* no_116_connect_hpp */
