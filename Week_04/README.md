# 9.深度优先搜索、广度优先搜索的实现和特性
## 9.1.遍历搜索
在树（图/状态集）中寻找特定节点
## 9.2.树结构定义
python:
``` 
class TreeNode:
    def __init__(self,val):
        self.val = val
        self.left,self.right = None,None
```
Java:
```
public class TreeNode{
    public int val;
    public TreeNode left,right;
    public TreeNode(int val){
        this.val = val;
        this.left = null;
        this.right = null;
    }
}
```
C++:
```
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x),left(NULL),right(NULL){}
}
```
### 9.3.搜索-遍历
- 每个节点都要访问一次
- 每个节点仅仅要访问一次
- 对于节点的访问顺序不限
    - 深度优先：depth first search
    - 广度优先：breadth first search
    - 优先级优先：极大值搜索
    
### 9.4.DFS递归写法1
```
def dfs(node):
    if node in visited:
        # already visited
        return
    visited.add(node)
    
    # process current node
    # ... # logic here
    dfs(node.left)
    dfs(node.right)
```
### 9.5.DFS递归写法2
```
visited = set()
def dfs(node,visited):
    if node in visited: # terminator
        # already visited
        return

    visited.add(node)
    # process current node here.
    ...
    for next_node in node.children():
        if not next_node in visited：
            dfs(next node,visited) 
```

### 9.6.DFS非递归写法：
```
def DFS(self, tree):
    if tree.root is None:
        return []
        
    visited, stack = [], [tree,root]
    
    while stack:
        node = stack.pop()
        visited.add(node)
        
        process(node)
        nodes = generate_related_nodes(node)
        stack.push(nodes)
    # other processing work 
```

### 9.7.BFS代码
```
def BFS(graph, start, end):
    queue = []
    queue.append(start)
    visitd.add(start)
    
    while queue:
        node = queue.popleft()
        visited.add(node)
        
        process(node)
        nodes = generate_related_nodes(node)
        queue.push(nodes)
   
   # other processing work
```


# 10.贪心算法Greedy
## 10.1.介绍
- 贪心算法是一种在每一步选择中都采取在当前状态下最好或者最优（即最有利）的选择，从而希望导致结果是全局最好或最优的算法。
- 贪心算法与动态规划的不同在于它对每个子问题的解决方案都做出选择，不能回退。动态规划则会保存以前的运算结果，并根据以前的结果对当前进行选择，有回退功能。
- 局部最优
- 贪心、回溯、动态规划区别：
    - 贪心：当下做局部最优判断
    - 回溯：能够回退
    - 动态规划：最优判断 +　回退
－　贪心法可以解决一些最优问题，如：求图中最小生成树、求哈夫曼编码等。然而对于工程和生活中的一些问题，贪心法一般不能得到我们所要求的答案。
- 一旦一个问题可以通过贪心法来解决，那么贪心法一般是解决这个问题的最好办法。由于贪心法的高效性以及其所要求的答案比较接近最优结果，贪心法也可以用作辅助算法或者直接解决一些要求结果不特别精确的问题。
## 10.2.何种情况下可以应用贪心算法，即适用贪心算法的场景
- 简单地说，问题能够分解成子问题来解决，子问题的最优解能够递推到最终问题的最优解。这种子问题最优解称为最优子结构。
- 贪心算法与动态规划的不同在于它对每个子问题的解决方案都做出选择，不能回退。动态规划则会保存以前的运算结果，并根据以前的结果对当前进行选择，有回退功能。

# 11.二分查找的实现、特性
## 11.1.二分查找的前提
- 1.目标函数单调性（单调递增或者递减）
- 2.存在上下界（bounded）
- 3.能够通过索引访问（index accessible）
## 11.2.代码模板
```
left,right = 0,len(array)-1
while left <= right:
    mid = (left+right)/2
    if array[mid] ==  target;
        # find the target!!
        break or return result
    elif array[mid] < target:
        left = mid + 1
    else:
        right = mid - 1
```

### 11.3.五毒神掌（五遍刷题） 
### 11.4.四步做题
- 1.审题，输入输出范围，边界条件
- 2.所有解法都思考一遍，时间复杂度 + 空间复杂度，得到最优解法
- 3.写
- 4.测试样例


