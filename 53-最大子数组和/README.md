# 53. 最大子数组和

## 题目描述

[53-最大子数组和](https://leetcode.cn/problems/maximum-subarray/)

## 思路

### 方法一

动态规划，我们以 `f(i)` 表示以 `i` 结尾的最大子数组和。那么我们要求的答案就是所有 `f(i)` 的最大值。

`f(i)` 的动态规划转移方程：

$$
f(i) = \max(f(i-1) + nums[i], nums[i])
$$

我们可以发现 `f(i)` 只和上一个状态有关，所以我们可以不用数组存储所有的值，我们只需要存储一个值即可

#### 复杂度

- 时间复杂度：O(n)
- 空间复杂度：O(1)

### 方法二

分治法，我们可以将数组分成两部分，分别求出左半部分和右半部分的最大子数组和，然后再求出跨越两部分的最大子数组和。

这样我们就要求出区间 `[l,r]` 的四个变量：

- lSum 表示 [l,r] 内以 l 为左端点的最大子段和
- rSum 表示 [l,r] 内以 r 为右端点的最大子段和
- mSum 表示 [l,r] 内的最大子段和
- iSum 表示 [l,r] 的区间和

那么我们该如何去维护这些变量呢？

如果区间内就一个元素，那么 `lSum = rSum = mSum = iSum = nums[l]`。

如果区间内有多个元素，我们将区间对半分成两个部分 `R` `L`

$$
lSum = \max(L.lSum, L.iSum + R.lSum)
$$

$$
rSum = \max(R.rSum, R.iSum + L.rSum)
$$

$$
mSum = \max(L.mSum, R.mSum, L.iSum + R.iSum)
$$

$$
iSum = L.iSum + R.iSum
$$

#### 复杂度

- 时间复杂度：O(n log n)
- 空间复杂度：O(log n)
