# 108. 将有序数组转换为二叉搜索树

## 题目描述

[108-将有序数组转换为二叉搜索树](https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/)

## 思路

我们可以写一个递归，每次选取数组中间或者中间后面那个为根。依次类推，这样建的树一定是平衡二叉树

## 复杂度

- 时间复杂度：O(n)
- 空间复杂度：O(log n)
