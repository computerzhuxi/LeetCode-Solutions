# 240. 搜索二维矩阵 II

## 题目描述

[240-搜索二维矩阵 II](https://leetcode.cn/problems/search-a-2d-matrix-ii/)

## 思路

根据矩阵的特性，我们可以从右上角开始遍历

- 如果当前值为 `target` 说明搜索完成
- 如果小于 `target` 说明当前行都小于 `target` 行加一
- 如果大于 `target` 说明当前列都大于 `target` 列减一

如果超过矩阵边界，说明矩阵中不存在 `target`

## 复杂度

- 时间复杂度：O(m + n)
- 空间复杂度：O(1)
