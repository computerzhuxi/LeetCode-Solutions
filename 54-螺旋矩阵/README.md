# 54. 螺旋矩阵

## 题目描述

[54-螺旋矩阵](https://leetcode.cn/problems/spiral-matrix/)

## 思路

可以将矩阵看成若干层，首先输出最外层的元素，其次输出次外层的元素，直到输出最内层的元素。

对于每层，从左上方开始以顺时针的顺序遍历所有元素。假设当前层的左上角位于 (top,left)，右下角位于 (bottom,right)，按照如下顺序遍历当前层的元素。

1. 从左到右遍历上侧元素，依次为 (top,left) 到 (top,right)。

2. 从上到下遍历右侧元素，依次为 (top+1,right) 到 (bottom,right)。

3. 如果 $left<right$ 且 $top<bottom$ ，则从右到左遍历下侧元素，依次为 (bottom,right−1) 到 (bottom,left+1)，以及从下到上遍历左侧元素，依次为 (bottom,left) 到 (top+1,left)。

遍历完当前层的元素之后，将 left 和 top 分别增加 1，将 right 和 bottom 分别减少 1，进入下一层继续遍历，直到遍历完所有元素为止。

## 复杂度

- 时间复杂度：O(mn)
- 空间复杂度：O(1)
