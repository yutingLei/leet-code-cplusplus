### 二叉树知识点

1. 二叉树的遍历
   - 前序遍历
   - 中序遍历
   - 后序遍历
   - 层序遍历
   - Z字型遍历
   - 倒序遍历(自底向上遍历)

2. 二叉搜索树
   - 判断树是否合法
   - 恢复二叉搜索树
   - 构成二叉搜索树的多种可能

3. 二叉树的构建
   - 有序数组/有序链表构建平衡二叉树
   - 已知树的前序/中序或中序/后序遍历结果, 构建这棵树.

4. 二叉树的其它应用
   - 求树中最大路径和
   - 树的高度
   - 树的对称性
   - 树的深度

**感触**: 很多树相关题目, 基本上都是将问题划分为子问题方式解决，已知根节点, 求某个值, 一定可以分解为先求根节点的左子树的值，然后求根节点右子树的值，依此类推，直到某个节点左右子树为空时停止，然后回溯整个过程，基本上可以解决大多数问题。
