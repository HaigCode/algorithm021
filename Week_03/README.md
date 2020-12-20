学习笔记
# 7.泛型递归、树的递归
## 7.1.递归recursion
### 7.1.1.递归-循环：通过循环体来进行的循环
### 7.1.2.盗梦空间：
- 向下进入到不同梦境中，向上又回到原来的一层
- 通过声音同步回到上一层
- 每一层的环境和周围的人都是一份拷贝、主角等几个人穿越不同层级的梦境（发生和携带变化）

### 7.1.3.递归代码模板：
python代码模板：
```python
def recursion(level, param1, param2,...):
    #recursion terminator,递归终止条件
    if level > MAX_LEVEL;
        process_result:
        return
    
    # process logic in current level，进行当前层业务逻辑代码
    process(level,data,...)
    
    # drill down，下钻到下一层
    self.recursion(level+1,p1,...)
    
    # reverse the current level status if needed，清理当前层状态

```
Java代码模板：
```Java 
public void recur(int level, int param){
    //terminator
    if(level > MAX_LEVEL){
        //process result
        return;
    }
    
    //process current logic
    process(level, param);
    
    //drill down 
    recur(level:level+1, newParam);
    
    //restore current status
} 

```

### 7.1.4.思维要点：
- 不要人肉进行递归（最大误区）——抵制人肉递归
- 找到最近最简方法，将其拆解成为可重复解决的问题（重复子问题）——找最近重复性
- 数学归纳法思维

# 8.分支、回溯的实现和特性
## 8.1.分治 Divide & Conquer
- Problem --> Divide(Sub-Problem) --> Conquer(Sub-Solution) --> Merge(Solution)

## 8.2.分治代码模板
```python
def divide_conquer(problem,param1,param2,...):
    # recursion terminator
    if problem is None:
        print_result
        return
    # prepare data , 
    data = prepare_data(problem)
    subproblems = split_problem(problem, data)
    
    # conquer subproblems
    subresult1 = self.divide_conquer(subproblems[0], p1, ...)
    subresult2 = self.divide_conquer(subprobelms[1], p1, ...)
    subresult3 = self.divide_conquer(subproblems[2], p1, ...)
    
    # process and generate the final result
    result = process_result(subresult1, subresult2, subresult3,...)
```

### 8.3.回溯
- 回溯法采用的是试错的思想，它尝试分步的去解决一个问题。
- 在分步解决问题的过程中，当它通过尝试发现现有的分步答案不能得到有效正确的解答的时候，它将取消上一步甚至上几步的计算，再通过其他的可能的分步解答再次尝试寻找问题的答案。
- 回溯法通常用最简单的递归方法来实现，在反复重复上述的步骤后可能出现两种情况：
    - 寻找到一个可能的正确的答案
    - 在尝试了所有可能的分步方法后宣告该问题没有答案
- 在最坏的情况下，回溯法会导致一次复杂度为指数时间的计算。

- 参考链接：
- [牛顿迭代法原理](http://www.matrix67.com/blog/archives/361)
- [牛顿迭代法代码](http://www.voidcn.com/article/p-eudisdmk-zm.html)



