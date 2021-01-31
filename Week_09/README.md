# 19.动态规划、状态转移方程串
## 1.1.感触
- 1.人肉递归低效、很累
- 2.找到最近最简方法，将其拆解成可重复解决的问题
- 3.数学归纳法思维
- 本质：寻找重复性 --> 计算机指令集
## 1.2.动态规划 Dynamic Programming
- 1."Simplifying a complicated problem by breaking it down into simpler sub-problems"(in a recursive manner)
- 2.Divide & Conquer + Optimal substructure(分治 + 最优子结构)
- 3.顺推形式：动态递归
- DP顺推模板:
```
function DP():
    dp = [][] # 二维情况 DP 状态定义复杂
    for i 0...M{
        for j=0...N{
            dp[i][j] = _Function(dp[i'][j']...) # 状态转移方程复杂
        }
    }
    return dp[M][N];
``` 
- 关键点：
动态规划和递归或者分治 没有根本上的区别（关键看有无最优的子结构）
拥有共性：找到重复子问题
差异性：最优子结构、中途可以淘汰次优解

# 20.字符串基础知识
# 20.1. 字符串遍历、比较
# 20.2..高级字符串算法
- 和动态规划结合
- 最长子串、子序列问题：最长子串、最长子序列、编辑距离
- 字符串 + DP问题：正则表达式匹配、通配符匹配、不通的子序列
# 20.3.字符串匹配算法
- 1.暴力法（brute force）
- 2.Rabin-Karp 算法
- 3.KMP算法

# 20.4.参考链接
- [Boyer-Moore 算法](https://www.ruanyifeng.com/blog/2013/05/boyer-moore_string_search_algorithm.html)
- [Sunday 算法](https://blog.csdn.net/u012505432/article/details/52210975)
- [字符串匹配暴力法代码示例](https://shimo.im/docs/8G0aJqNL86wWrPUE)
- [Rabin-Karp 代码示例](https://shimo.im/docs/1wnsM7eaZ6Ab9j9M)
- [KMP 字符串匹配算法视频](https://www.bilibili.com/video/av11866460?from=search&seid=17425875345653862171)
- [字符串匹配的 KMP 算法](http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html)


# 20.5.unique-paths-ii 状态转移方程
- 我们用 f(i, j)f(i,j) 来表示从坐标 (0, 0)(0,0) 到坐标 (i, j)(i,j) 的路径总数，u(i, j)u(i,j) 表示坐标 (i, j)(i,j) 是否可行，如果坐标 (i, j)(i,j) 有障碍物，u(i, j) = 0u(i,j)=0，否则 u(i, j) = 1u(i,j)=1。
- 因为「机器人每次只能向下或者向右移动一步」，所以从坐标 (0, 0)(0,0) 到坐标 (i, j)(i,j) 的路径总数的值只取决于从坐标 (0, 0)(0,0) 到坐标 (i - 1, j)(i−1,j) 的路径总数和从坐标 (0, 0)(0,0) 到坐标 (i, j - 1)(i,j−1) 的路径总数，即 f(i, j)f(i,j) 只能通过 f(i - 1, j)f(i−1,j) 和 f(i, j - 1)f(i,j−1) 转移得到。当坐标 (i, j)(i,j) 本身有障碍的时候，任何路径都到到不了 f(i, j)f(i,j)，此时 f(i, j) = 0f(i,j)=0；下面我们来讨论坐标 (i, j)(i,j) 没有障碍的情况：如果坐标 (i - 1, j)(i−1,j) 没有障碍，那么就意味着从坐标 (i - 1, j)(i−1,j) 可以走到 (i, j)(i,j)，即 (i - 1, j)(i−1,j) 位置对 f(i, j)f(i,j) 的贡献为 f(i - 1, j)f(i−1,j)，同理，当坐标 (i, j - 1)(i,j−1) 没有障碍的时候，(i, j - 1)(i,j−1) 位置对 f(i, j)f(i,j) 的贡献为 f(i, j - 1)f(i,j−1)。

- f(i,j) =  0, u(i,j) = 0
- f(i,j) = f(i-1,j) + f(i,j-1), u(i,j) != 0

