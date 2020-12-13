学习笔记
# 5.哈希表、映射、集合的实现与特性
## 5.1. Hash table
哈希表（Hash table）,也叫散列表，是根据关键码值（key value）而直接进行访问的数据结构。
它通过把关键码值映射到表中一个位置来访问记录，以加快查找速度。
这个映射函数叫做散列函数（Hash Function）,存放记录的数组叫做哈希表（或散列表）。
## 5.2.工程实践
- 电话号码簿
- 用户信息表
- 缓存（LRU Cache）
- 键值对存储（Redis）

## 5.3.时间复杂度
- O(1)
- 最坏：O(n):哈希碰撞


### 5.4..Java Code:
- map :key-value对，key 不重复
    -new HashMap()/new TreeMap()
    - map.set(key,value)
    - map.get(key)
    - map.has(key)
    - map.size()
    - map.clear()
- set:不重复元素的集合
    - new HashSet()/ new TreeSet()
    - set.add(value)
    - set.delete(value)
    - set.hash(value)
    

### 5.5.做题流程
- 1.clarification
- 2.possible solutions --> optimal(time & space)
- 3.code 
- 4.test cases

### 5.6.收藏优秀代码
[优秀代码示例](https://shimo.im/docs/R6g9WJV89QkHrDhr/read)


# 6.树、二叉树、二叉搜索树的实现和特性
## 6.1.简介
- 单链表Linked List --> 升维 --> 树Tree
- 树Tree:没有环的图
- 二叉树（binary tree）
- 图（graph）
- Linked List就是特殊化的Tree, Tree 就是特殊化的Graph
## 6.2.示例代码
- python:
```python
class TreeNode:
    def __init__(self,val):
        self.val = val
        self.left,self.right = None,None
```
- java:
```java
public class TreeNode{
    public int val;
    public TreeNode left,righ;
    public TreeNode(int val){
        this.val = val;
        this.left = null;
        this.right = null;
    }
}
```
- C++:
```c++
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
}
```

# 6.3.二叉树遍历Pre-order/In-order/Post-order
- 前序（pre-order）:根-左-右
- 中序（In-order）:左-根-右
- 后续（Post-order）:左-右-根

```python
def preorder(self,root):
    if root:
        self.raverse_path append(root.val)
        self.preorder(root.left)
        self.preorder(root,left)
def inorder(self, root):
    if root:
        self.inorder(root.left)
        self.traverse_path.append(root.val)
        self.inorder(root.right)
def postorder(self,root):
    if root:
        self.postorder(root.left)
        self.postorder(root.right)
        self.traverse_path.append(root.val)
```

## 6.4.二叉搜索树 Binary Search Tree
二叉搜索树，也称为二叉排序树，有序二叉树（ordered Binary Tree）, 排序二叉树（Sorted Binary Tree）,是指一棵空树或者具有下列性质的二叉树：
- 左子树上所有节点的值均小于它的根节点的值；
- 右子树上所有根节点的值均大于它的根节点的值；
- 以此类推：左、右子树也分别为二叉搜索树（重复性）。
中序遍历：升序排列

二叉搜索树常见的操作：
- 1.查询 logN
- 2.插入新节点LogN
- 3.删除

## 6.5.堆 Heap
### 6.5.1.定义
- Heap: 可以迅速找到一堆数中的最大最大或者最小值的数据结构
- 将根节点最大的堆叫做大顶堆或者大根堆，根节点最小的堆叫做小顶堆或者小跟堆。
- 常见的堆有二叉堆、斐波那契堆等。

- 假设是大顶堆，常见的操作API:
    - find-max: O(1)
    - delete-max: O(logN)
    - insert(create): O(logN) or O(1)


### 6.5.2.二叉堆性质
- 通过完全二叉树来实现（注意：不是二叉搜索火树）
- 二叉堆（大顶）它满足下列性质：
    - 1.是一棵树；
    - 2.树中任意节点的值总是 `>=` 其子节点的值。
    

### 6.5.3.二叉堆的实现细节：
- 1.二叉堆一般都是通过 “数组”来实现；
- 2.假设“第一个元素”在数组中的索引为0 的话，则父节点和子节点的位置关系如下：
    - 1.索引为i的左孩子的索引是（2*i+1）;
    - 2.索引为i的右孩子的索引是（2*i+2）;
    - 3.索引为i的父节点的索引是floor((i-1)/2);
    
### 6.5.4.二叉堆
- 0.根节点（顶堆元素）是：a[0]
- 1.索引为i的左孩子的索引是（2*i+1）
- 2.索引为i的右孩子的索引为（2*i+2）
- 3.索引为i的节点的索引是floor((i-1)/2);

### 6.5.5.Insert 插入操作--O(logN)
- 1.新元素一律插入到堆的尾部
- 2.依次向上调整整个堆的结构（一直到根即可）
- HeapifyUP

### 6.5.6.Delete Max 删除堆顶操作--O(logN)
- 1.将堆尾元素替换到堆顶（即对顶被替代删除掉）
- 2.依次从根部向下调整整个堆的结构（一直到堆尾即可）
- 3.HeapifyDown

### 6.6.7.注意：
- 二叉堆是堆（优先队列priority_queue）的一种常见且简单的实现；但是并不是最优的实现。

## 6.6.图的实现和特性
### 6.6.1.图的属性和分类
#### 6.6.1.1.图是属性
- Graph(V,E)
- V-vetex:点
    - 1.度——入度和出度
    - 2.点和点之间：连通与否
- E-edge:边
    - 1.有向和无向（单行线）
    - 2.权重（边长）
### 6.6.2图的相关的算法
- DFS 代码-递归写法：
```python
visited = self() # 和树中的DFS最大区别
def dfs(node,visited):
    if node in visited: #terminator
        # already visited
        return 
    visited.add(node)
    
    #process current node here
    
    for next_node in node.children():
        if not next_node in visited:
            dfs(next_node,visited)
```

参考链接：
- [连通图个数]( https://leetcode-cn.com/problems/number-of-islands/)
- [拓扑排序（Topological Sorting）]( https://zhuanlan.zhihu.com/p/34871092)
- [最短路径（Shortest Path）：Dijkstra]( https://www.bilibili.com/video/av25829980?from=search&seid=13391343514095937158)
- [最小生成树（Minimum Spanning Tree）]( https://www.bilibili.com/video/av84820276?from=search&seid=17476598104352152051)
