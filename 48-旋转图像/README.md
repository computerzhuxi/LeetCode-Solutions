# 48. 旋转图像

## 题目描述

[48-旋转图像](https://leetcode.cn/problems/rotate-image/)

## 思路

我们可以一圈一圈的看，可以找到每个元素对应的位置关系

$$
\begin{cases}
temp = matrix[top][i]\\
matrix[top][i] = matrix[n - i][left]\\
matrix[n - i][left] = matrix[bottom][n - i]\\
matrix[bottom][n - i] = matrix[i][right]\\
matrix[i][right] = temp\end{cases}
$$

top、bottom、left和right分别表示一圈的四个边

## 复杂度

- 时间复杂度：O( $n^2$ )
- 空间复杂度：O(1)
