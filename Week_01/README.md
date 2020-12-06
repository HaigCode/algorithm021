学习笔记
# 1.数组、链表、跳表的基本实现和特性
## 1.1.Array时间复杂度:
	- prepend O(1),注意：正常情况下，数组prepend操作的时间复杂O(n),但是可以进行特殊优化到O(1),采用的方式是申请稍大一些一些的内存空间，然后在数组最开始预留一部分空间，然后prepend的操作则是把头下标前移一个位置即可。
	- append O(1)
	- lookup O(1)
	- insert O(n)
	- delete O(n)
## 1.2.普通链表时间复杂度：
	- prepend O(1)
	- append O(1)
	- lookup O(n)
	- insert O(1)
	- delete O(1)
## 1.3.跳表：
### 1.3.1.跳表的特点：
	- 注意：<b>只能用于元素有序的情况。</b>
	- 所以，跳表（skip list）对标的是平衡树（AVL Tree）和 二分查找，是一种插入/删除/搜索/ 都是O(log n)的数据结构。1989年出现。
	- 它最大的优势是原理简单、容易实现、方便扩展、效率更高。因此在一些热门的项目里用来代替平衡树，如redis,LevelDB等。
### 1.3.2.跳表如何进行加速（升纬）：
	- 添加第一级索引
	- 添加第二级索引
	- 添加第三级索引
	- ...
### 1.3.3.跳表查询的时间复杂度分析
	- n/2,n/4,n/8,...,第k级索引节点的个数就是n/(2^k)
	- 假设索引有h级，最高级的索引有2个节点，n/(2^h)=2,从而求得h=log2(n)-1
	- 例子：索引的高度:logn, 每层索引遍历的节点个数3，在跳表中查询任意数据的时间复杂度就是O(logn)
### 1.3.4.跳表的空间复杂度分析
	- 原始链表大小为n,每2个节点抽1个，每层索引的节点数：n/2,n/4,n/8,...,8,4,2
	- 原始链表的大小为n,每3个节点抽1个，每层索引的节点数：n/3,n/9,n/27,...,9,3,1
	- 空间复杂度是O(n)
## 1.4.小结
	- 数组、链表、跳表的原理和实现
	- 三者的时间复杂度、空间复杂度
	- 工程运用
	- 跳表：升维思想+空间换时间
## 1.4.参考链接：
	- [LRU缓存算法](https://www.jianshu.com/p/b1ab4a170c3c)
	- [146. LRU 缓存机制](https://leetcode-cn.com/problems/lru-cache/)
	- [为啥 Redis 使用跳表（Skip List）而不是使用 Red-Black？](https://www.zhihu.com/question/20202931)
	- [Java 源码分析（ArrayList）](http://developer.classpath.org/doc/java/util/ArrayList-source.html)
	- [Linked List 的标准实现代码](https://www.geeksforgeeks.org/implementing-a-linked-list-in-java-using-class/)
	- [Java 源码分析（LinkedList）](http://developer.classpath.org/doc/java/util/LinkedList-source.html)

# 2.实战题目解析：移动零
## 2.1.练习步骤：
	- 5-10分钟：读题和思考
	- 有思路：自己开始做和写代码; 不然，马上看题解。
	- 默写背诵、熟练
	- 然后开始自己写（闭卷）
	- 复习
	- 最大误区：刷一遍；核心思想:升维+空间换时间
## 2.2.Array实战题目
	- [盛最多水的容器](https://leetcode-cn.com/problems/container-with-most-water/)
	- [移动零](https://leetcode-cn.com/problems/move-zeroes/)
	- [爬楼梯](https://leetcode.com/problems/climbing-stairs/)
	- [三数之和](https://leetcode-cn.com/problems/3sum/)
# 3.实战题目解析：
## 3.1.盛水最多容器
	- 一维数组的坐标变换:i,j
	- 1.枚举：left bar x, right bar y,(x-y)*height_diff,O(n^2)
	- 2.左右收敛（左右夹逼）： 左右边界i,j, 向中间收敛
## 3.2.爬楼梯
	- 暴力破解？基本情况？
	- 找、最近、重复子问题（找重复性）
## 3.3.3数之和
	- 2数之和，简单版，a,b a+b = target
		- 暴力
		- 哈希
	- 3数之和，a,b a+b = -c
		- 审题：
			- 1.返回不重复的三元组
			- 2.会有复数、无序
			- 3.可能不存在（实际要求返回空数组）
			- 4.a+b=-c
			- 5.数组内有重复数字，结果有可能有重复
		- 思路：
			- 1.暴力:三重循环
			- 2.hash：两重暴力+hash
			- 3.夹逼：因为不需要下标，可以排序后夹逼
		- 反馈：
			- 1.通过一些边界条件，加速代码
		- 问题：
			- 1.如何在hash很好的避免结果集重复？
		- 实现：
			- 1.暴力：超出时间限制
			- 2.hash slow
			- 3.夹逼法（双指针，左右指针）
			- 4.夹逼快速版
## 3.3.4.环形链表
	- 思路：
		- 1.暴力：遍历链表，hash
		- 2.双指针（快慢指针）
	- 题目：
		- [反转链表](https://leetcode.com/problems/reverse-linked-list/)
		- [两两交换链表中的节点](https://leetcode.com/problems/swap-nodes-in-pairs)
		- [环形链表](https://leetcode.com/problems/linked-list-cycle)
		- [环形链表 II](https://leetcode.com/problems/linked-list-cycle-ii)
		- [K 个一组翻转链表](https://leetcode.com/problems/reverse-nodes-in-k-group/)
# 4.栈和队列的实现与特性
## 4.1.Stach & Queue关键点
	- Stack: 先入后出；添加、删除皆为O(1)
	- Queue: 先入先出；添加、删除皆为O(1)
	- Deque(Double-End Queue):
		- 1.简单理解：两端可以进出的Queue，Deque-Double-ended queue
		- 2.插入和删除都是O(1)操作
## 4.2.Stach、Queue、Deque工程实现
	- Java、Python、C++等已有实现基础
	- 如何查询接口信息？如何使用？
		- stack:java 12 google 搜索
	- 示例代码
## 4.3.Priority Queue
	- 1.插入操作：O(1)
	- 2.取出操作：O(logN)——按照元素优先级取出
	- 3.底层具体实现的数据结构较为多样和复杂：heap、bst、treap
## 4.4.小结
	- 1.Stack、Queue、Deque 的原理和操作复杂度
	- 2.PriorityQueue 的特点和操作复杂度
	- 3.查询Stack、Queue、Deque、PriorityQueue 的系统接口的方法
## 4.5.参考链接
	- [Java 的 PriorityQueue 文档](http://docs.oracle.com/javase/10/docs/api/java/util/PriorityQueue.html)
	- [Java 的 Stack 源码](http://developer.classpath.org/doc/java/util/Stack-source.html)
	- [Java 的 Queue 源码](http://fuseyism.com/classpath/doc/java/util/Queue-source.html)
	- [Python 的 heapq](http://docs.python.org/2/library/heapq.html)
	- [高性能的 container 库](http://docs.python.org/2/library/collections.html)
# 5.实战题目解析：有效的括号、最小栈等问题
## 5.1.预习题目
	- [有效的括号](https://leetcode-cn.com/problems/valid-parentheses/)
	- [最小栈](https://leetcode-cn.com/problems/min-stack/)
## 5.2.实战题目
	- [柱状图中最大的矩形](https://leetcode-cn.com/problems/largest-rectangle-in-histogram)
	- [滑动窗口最大值](https://leetcode-cn.com/problems/sliding-window-maximum)
## 5.3.有效的括号
	- 可以用栈来解决的问题：最近相关性(剥洋葱)，先来后到
	- 计算机算法最后都归结于最近的重复性
	- 解决方法：
		1.暴力求解
		2.栈
## 5.3.最小栈
	- 辅助栈法
## 5.4.柱状图中最大的矩形
	- 解决方法：
		- 1.暴力求解1,枚举边界，min_height
			```
			for i->0,n-2
				for j->i+1,n-2
					(i,j) -> 最小高度，area
					update max-area
			```
		- 2. 暴力求解2，枚举高度，bounds_range
			```
			for i->0,n-1:
				找到left bound,right bound,
				area = height[i] * (right-left)
				update max-area
			```
		- 2.stack
			- 栈维护左边界，栈是从小到大排列的
## 5.5.滑动窗口
	- 用队列解决：这里的队列是双端队列
	- 解决方法：
		- 1.暴力求解O(n*k)
		- 2.deque (sliding window) O(n)
## 5.6.练习题目
	- 用 add first 或 add last 这套新的 API 改写 Deque 的代码
	- 分析 Queue 和 Priority Queue 的源码
	- [删除排序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)
	- [旋转数组](https://leetcode-cn.com/problems/rotate-array/)
	- [合并两个有序链表](https://leetcode-cn.com/problems/merge-two-sorted-lists/)
	- [合并两个有序数组](https://leetcode-cn.com/problems/merge-sorted-array/)
	- [两数之和](https://leetcode-cn.com/problems/two-sum/)
	- [移动零](https://leetcode-cn.com/problems/move-zeroes/)
	- [加一](https://leetcode-cn.com/problems/plus-one/)

	- [设计循环双端队列](https://leetcode.com/problems/design-circular-deque)

	- [接雨水](https://leetcode.com/problems/trapping-rain-water/)