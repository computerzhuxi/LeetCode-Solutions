# 437. 路径总和 III

## 题目描述

[437-路径总和 III](https://leetcode.cn/problems/path-sum-iii/)

## 思路

我们定义节点的前缀和为：由根结点到当前结点的路径上所有节点的和。我们利用先序遍历二叉树，记录下根节点 root 到当前节点 p 的路径上除当前节点以外所有节点的前缀和，在已保存的路径前缀和中查找是否存在前缀和刚好等于当前节点到根节点的前缀和 curr 减去 targetSum。

- 对于空路径我们也需要保存预先处理一下，此时因为空路径不经过任何节点，因此它的前缀和为 0。

- 假设根节点为 root，我们当前刚好访问节点 node，则此时从根节点 root 到节点 node 的路径（无重复节点）刚好为 $root$ $\rightarrow$ $p_1$ $\rightarrow$ $p_2$ $\rightarrow$ …… $\rightarrow$ $p_k$ $\rightarrow$ $node$ 此时我们可以已经保存了节点 $p_1$ 、 $p_2$ 、 $p_3$ …… $p_k$的前缀和，并且计算出了节点 node 的前缀和。

- 假设当前从根节点 root 到节点 node 的前缀和为 curr，则此时我们在已保存的前缀和查找是否存在前缀和刚好等于 curr−targetSum。假设从根节点 root 到节点 node 的路径中存在节点 $p_i$ 到根节点 root 的前缀和为 curr−targetSum，则节点 $p_{i+1}$ 到 node 的路径上所有节点的和一定为 targetSum。

- 我们利用深度搜索遍历树，当我们退出当前节点时，我们需要及时更新已经保存的前缀和。


## 复杂度

- 时间复杂度：O(n)
- 空间复杂度：O(n)
