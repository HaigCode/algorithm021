# 16.位运算

- [如何从十进制转换为二进制](https://zh.wikihow.com/%E4%BB%8E%E5%8D%81%E8%BF%9B%E5%88%B6%E8%BD%AC%E6%8D%A2%E4%B8%BA%E4%BA%8C%E8%BF%9B%E5%88%B6)
- [N 皇后位运算代码示例](https://shimo.im/docs/YzWa5ZZrZPYWahK2/read)

``` 
# Python
def totalNQueens(self, n):
 	if n < 1: return []
 	self.count = 0
 	self.DFS(n, 0, 0, 0, 0)
 	return self.count

def DFS(self, n, row, cols, pie, na):
 	# recursion terminator
 	if row >= n:
 		self.count += 1
 		return

	bits = (~(cols | pie | na)) & ((1 << n) — 1)# 得到当前所有的空位
	
	while bits:
	 		p = bits & —bits # 取到最低位的1
			bits = bits & (bits — 1) # 表示在p位置上放入皇后
			self.DFS(n, row + 1, cols | p, (pie | p) << 1, (na | p) >> 1)
		    # 不需要revert  cols, pie, na 的状态
```

// Java
```
class Solution {
	private int size;
	private int count;
	private void solve(int row, int ld, int rd) {
 		if (row == size) {
 			count++;
 			return;
 		}
        int pos = size & (~(row | ld | rd));
        while (pos != 0) {
         	int p = pos & (-pos);
         	pos -= p; // pos &= pos - 1;
           solve(row | p, (ld | p) << 1, (rd | p) >> 1);
        } 	
	} 
	public int totalNQueens(int n) {
	 	count = 0;
	 	size = (1 << n) - 1;
	 	solve(0, 0, 0);
	 	return count;
	}
}
```

// C/C++
``` 
//C/C++class Solution {
public:
    int totalNQueens(int n) {
        dfs(n, 0, 0, 0, 0);
        return this->res;
    }
    void dfs(int n, int row, int col, int ld, int rd) {
        if (row >= n) { res++; return; }
        // 将所有能放置 Q 的位置由 0 变成 1，以便进行后续的位遍历
        int bits = ~(col | ld | rd) & ((1 << n) - 1);
        while (bits > 0) {
            int pick = bits & -bits; // 注: x & -x
            dfs(n, row + 1, col | pick, (ld | pick) << 1, (rd | pick) >> 1);
            bits &= bits - 1; // 注: x & (x - 1)
        }
    }private:
    int res = 0;
};
```

// Javascript
```
var totalNQueens = function(n) {
  let count = 0;
  void (function dfs(row = 0, cols = 0, xy_diff = 0, xy_sum = 0) {
    if (row >= n) {
      count++;
      return;
    }
    // 皇后可以放的地方
    let bits = ~(cols | xy_diff | xy_sum) & ((1 << n) - 1);
    while (bits) {
      // 保留最低位的 1
      let p = bits & -bits;
      bits &= bits - 1;
      dfs(row + 1, cols | p, (xy_diff | p) << 1, (xy_sum | p) >> 1);
    }
  })();
  return count;
};
```
# 17.布隆过滤器、LRU Cache
## 17.1.布隆过滤器
- [布隆过滤器的原理和实现](https://www.cnblogs.com/cpselvis/p/6265825.html)
- [使用布隆过滤器解决缓存击穿、垃圾邮件识别、集合判重](https://blog.csdn.net/tianyaleixiaowu/article/details/74721877)
- [布隆过滤器 Python 代码示例](https://shimo.im/docs/UITYMj1eK88JCJTH/read)
- [布隆过滤器 Python 实现示例](https://www.geeksforgeeks.org/bloom-filters-introduction-and-python-implementation/)
- [高性能布隆过滤器 Python 实现示例](https://github.com/jhgg/pybloof)
- [布隆过滤器 Java 实现示例 1](https://github.com/lovasoa/bloomfilter/blob/master/src/main/java/BloomFilter.java)
- [布隆过滤器 Java 实现示例 2](https://github.com/Baqend/Orestes-Bloomfilter)

## 17.2.LRU Cache
- [Understanding the Meltdown exploit](https://www.sqlpassion.at/archive/2018/01/06/understanding-the-meltdown-exploit-in-my-own-simple-words/)
- [替换算法总揽](https://en.wikipedia.org/wiki/Cache_replacement_policies)
-[LRU Cache Python 代码示例](https://shimo.im/docs/CoyPAyXooGcDuLQo/read)


# 18.初级排序和高级排序的实现和特性
# 18.1.排序
# 18.1.1.比较类排序
- 通过比较来决定元素间的相对次序，由于其时间复杂度不能突破O(nlogn), 因此也称为非线性时间比较类排序。
# 18.1.2.非比较类排序
- 不通过比较来决定元素间的相对次序，它可以突破基于比较排序的时间下界，以线性时间运行，因此也称为线性时间非比较类排序。
# 18.1.3.分类
- 排序算法
    - 比较类排序
        - 交换排序
            - 冒泡排序
            - 快速排序`*`
        - 插入排序
            - 简单插入排序
            - 希尔排序
        - 选择排序
            - 简单选择排序
            - 堆排序`*`
        - 归并排序`*`
            - 二路归并排序
            - 多路归并排序
    - 非比较类排序
        - 计数排序
        - 桶排序
        - 基数排序
# 18.1.4.初级排序O(n^2)
- 1.选择排序（selection sort）
    每次找最小值，然后放入到待排序数组的起始位置。
- 2.插入排序（Insrtion Sort）
    从前到后逐构建有序序列；对于为排序数据，在已排序序列中从后向前扫描，找到对应位置并插入。
- 3.冒泡排序（Bubble Sort）
    嵌套循环，每次查找相邻的元素如果逆序，则交换。
# 18.1.5.高级排序O(N*LogN)
- 1.快速排序（quick sort）
    数组取标杆pivot, 将小元素放pivot左边，大元素放右侧，然后依次对右边和右边的子数组继续快排；以达到整个序列有序。
- 2.归并排序（Merge Sort）——分治
    - 1.把长度为n的序列分成两个长度为n/2的子序列；
    - 2.对这两个子序列分别采用归并排序；
    - 3.将两个排序好的子序列合并成一个最终的排序序列。
- 3.归并和快速排序具有相似性，但步骤序列相反
    - 归并：先排序左右子序列，然后合并两个有序子序列
    - 快排：先调配出左右子序列，然后对于左右子序列数组进行排序
# 18.1.6.特殊排序O(n)
- 1.计数排序（Counting Sort）
- 2.桶排序（Bucket Sort）
- 3.基数排序（Radix Sort）

- [十大经典排序算法](https://www.cnblogs.com/onepixel/p/7674659.html)
- [快速排序代码示例](https://shimo.im/docs/TX9bDbSC7C0CR5XO/read)
- [归并排序代码示例](https://shimo.im/docs/sDXxjjiKf3gLVVAU/read)
- [堆排序代码示例](https://shimo.im/docs/M2xfacKvwzAykhz6/read)
- [9 种经典排序算法可视化动画](https://www.bilibili.com/video/av25136272)
- [6 分钟看完 15 种排序算法动画展示](https://www.bilibili.com/video/av63851336)