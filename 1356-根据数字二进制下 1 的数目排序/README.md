# 1356. 根据数字二进制下 1 的数目排序

## 题目描述

[1356-根据数字二进制下 1 的数目排序](https://leetcode.cn/problems/sort-integers-by-the-number-of-1-bits/)

## 思路

直接暴力枚举，先将所有数的二进制下的1的个数用一个数组存储下来，然后用sort方法来对数组排序

## 复杂度

- 时间复杂度：O(n log n)
- 空间复杂度：O(n)
