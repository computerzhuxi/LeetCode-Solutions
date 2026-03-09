# 3129. 找出所有稳定的二进制数组 I

## 题目描述

[3129-找出所有稳定的二进制数组 I](https://leetcode.cn/problems/find-all-possible-stable-binary-arrays-i/)

## 思路

采用动态规划的方式，我们定义将 $0$ 和 $1$ 填入数组的方式是插入到末尾。定义状态 $dp_0[i][j]$ 表示已经填入 $i$ 个 0，$j$ 个 1 的数组的个数，且上一次填入的数是 $0$。$dp_1[i][j]$ 表示已经填入 $i$ 个 0，$j$ 个 1 的数组的个数，且上一次填入的数是 $1$。
我们可以分析一下状态转换方程：以 $dp_0$ 为例。

- 当 $j=0$ 且 $i\in[0, min(zero, limit)]$时，$dp_0[0][j]=1$，因为只有一个数组可以填入 $0$。也就是全 $0$ 的数组。
- 当 $i = 0$ 或者 $j = 0$ 且 $i\notin[1, min(one, limit)]$时，$dp_0[i][j]=0$，因为没有数组可以填入 $0$。
- 当 $i>0$ 且 $j=0$ 时，$dp_0[i][j]$ 是由$dp_0[i-1][j]$ 和 $dp_1[i-1][j]$ 转移而来的。
  - 对于 $dp_1[i-1][j]$，我们显然可以直接加入$0$
  - 对于 $dp_0[i-1][j]$，我们可以考虑两种情况： - $i\leq limit$，则可以直接加入$0$ - $i>limit$，则需要减去末尾`limit`个数都是 $0$ 的数组，这个数组我们可以认为是由 $dp_0[i-limit-1][j]$ 转移而来的，所以我们要减去这个情况。

$dp_1$ 的状态转换方程同理。我们得到的状态转移方程如下：

$$
        dp[i][j][0] =
        \begin{cases}
        1 &  i\in[0, min(zero, limit)] , j=0 \\
        dp[i-1][j][0] + dp[i-1][j][1] - dp[i-1-limit][j][1] &  i > \text{limit},j > 0 \\
        dp[i-1][j][0] + dp[i-1][j][1] & i\in[0, min(zero, limit)], j>0 \\
        0 & \text{otherwise}
        \end{cases}
$$

$$
        dp[i][j][1] =
        \begin{cases}
        1 &  i=0 , j\in[0, min(one, limit)] \\
        dp[i-1][j][0] + dp[i-1][j][1] - dp[i-1-limit][j][1] & i > 0,j > \text{limit} \\
        dp[i-1][j][0] + dp[i-1][j][1] & i>0,j\in[0, min(one, limit)]\\
        0 & \text{otherwise}
        \end{cases}
$$

## 复杂度

- 时间复杂度：O(zero×one))
- 空间复杂度：O(zero×one))
