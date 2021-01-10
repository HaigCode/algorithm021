# 12.第五、六周 动态规划
##  12.1.动态规划的实现及其特点
### 12.1.1.总结数据结构&方法
- Array 数组 
- Linked List 链表
- Stack 栈
- Queue 队列
- HashTable 哈希表
- Set 、 Map
- Tree 二叉树
- BST 二叉搜素树
- Search 查询
- Recursion 查询
- DFS 深度优先搜索
- BFS 广度优先搜索
- Divide & Conquer 分治
- Backtracking 回溯
- Greedy 贪心
- Binary Search 二叉查找

### 12.1.2.地址
- [数据结构与算法运行流程图](visualgo.net/en)

### 12.1.2.思考纬度
- 感触
    - 1.人肉递归低效，很累
    - 2.找到最近最简单方法，将其拆解成可重复解决的问题
    - 3.数学归纳法思维（抵制人肉递归的诱惑）
- 本质：
    寻找重复性——> 计算机指令集
    
## 12.2.动态规划Dynamic Programming（动态递推）
### 12.2.1.定义：只关注　最优解，最大值，最优子结构
- 1.wiki定义
- 2.Simplifying a complicated problem by breaking it down into simpler subproblems.(in a recursive manner)
- 3.Divide & Conquer + Optimal substructure 分治 +　最优子结构

### 12.2.2.关键点
- 动态规划 和 递归或者分治 没有根本上的区别（关键看有无最优子结构）
- 共性： 找到重复子问题
- 差异性：最优子结构、中途可以淘汰次优解

## 12.3.递归代码模板
### 12.3.1.Python 代码模板
```
# Pythondef recursion(level, param1, param2, ...):
      # recursion terminator
      if level > MAX_LEVEL:
            process_result
            return
      # process logic in current level
      process(level, data...)
      # drill down
      self.recursion(level + 1, p1, ...)
      # reverse the current level status if needed
```

### 12.3.2.Java 代码模板
```
// Java
public void recur(int level, int param) {
   // terminator
   if (level > MAX_LEVEL) {
        // process result
        return;
   }
   // process current logic
   process(level, param);
   // drill down
   recur( level: level + 1, newParam);
   // restore current status
}
```

### 12.3.3.C/C++ 代码模板
```
// C/C++void recursion(int level, int param) {
   // recursion terminator
   if (level > MAX_LEVEL) {
        // process result
         return ;
   }
  // process current logic
   process(level, param);
  // drill down
   recursion(level + 1, param);
  // reverse the current level status if needed
}
```

### 12.3.4.JavaScript代码模板
```
// JavaScript
const recursion = (level, params) =>{
   // recursion terminator
    if(level > MAX_LEVEL){
         process_result
         return
    }
    // process current level
    process(level, params)
    //drill down
    recursion(level+1, params)
    //clean current level status if needed 
}
```

## 12.4.分治代码模板
### 12.4.1.python代码模板
``` 
# Pythondef divide_conquer(problem, param1, param2, ...):
   # recursion terminator
   if problem is None:
 	print_result
 	return
   # prepare data
   data = prepare_data(problem)
   subproblems = split_problem(problem, data)
   # conquer subproblems
   subresult1 = self.divide_conquer(subproblems[0], p1, ...)
   subresult2 = self.divide_conquer(subproblems[1], p1, ...)
   subresult3 = self.divide_conquer(subproblems[2], p1, ...)
   …  
   # process and generate the final result
   result = process_result(subresult1, subresult2, subresult3, …)
   # revert the current level states
```

### 12.4.2.C/C++代码模板
``` 
C/C++
int divide_conquer(Problem *problem, int params) {
  // recursion terminator
  if (problem == nullptr) {
    process_result
    return return_result;
  }
  // process current problem
  subproblems = split_problem(problem, data)
  subresult1 = divide_conquer(subproblem[0], p1)
  subresult2 = divide_conquer(subproblem[1], p1)
  subresult3 = divide_conquer(subproblem[2], p1)
  ...  
  // merge
  result = process_result(subresult1, subresult2, subresult3)
  // revert the current level status
  return 0;
}
```

### 12.4.3.Java代码模板
``` 
Java
private static int divide_conquer(Problem problem, ) {
    if (problem == NULL) {
        int res = process_last_result();
        return res;
    }
    subProblems = split_problem(problem)
    res0 = divide_conquer(subProblems[0])
    res1 = divide_conquer(subProblems[1])
    result = process_result(res0, res1);
    return result;
}
```

### 12.4.4.JavaScript 代码模板
``` 
//Javascriptconst divide_conquer = (problem, params) => {
  // recursion terminator
  if (problem == null) {
    process_result
    return
  }
  // process current problem
  subproblems = split_problem(problem, data)
  subresult1 = divide_conquer(subproblem[0], p1)
  subresult2 = divide_conquer(subproblem[1], p1)
  subresult3 = divide_conquer(subproblem[2], p1)
  ... 
  // merge 
  result = process_result(subresult1, subresult2, subresult3) 
  // revert the current level status
}
```