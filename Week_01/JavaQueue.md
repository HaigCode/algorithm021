# 1.用add first或add last这套新的API改写Deque的代码：
```
import java.util.Deque;
import java.util.LinkedList;
public class NewDeque {
    public void modifyDeque
        Deque<String> deque = new LinkedList<String>();
        deque.addFirst("1");
        deque.addFirst("2");
        deque.addFirst("3");
        deque.addFirst("4")
        deque.addFirst("5");
        System.out.println(deque);
        String str = deque.peekFirst();
        System.out.println(str);
        System.out.println(deque);
        while (deque.size() > 0){
            System.out.println(deque.removeFirst());
        }
        System.out.println(deque);
    }
}
```
# 2.2.分析Queue和Priority Queue的源码：
## Queue
- Queue是一个Interface，Queue队列继承了Collection接口，并扩展了队列相关方法。是一种为了可以优先处理先进入的数据而设计的集合。
```
boolean add(E e);
```
在不超出规定容量的情况下可以将指定的元素立刻加入到队列，成功的时候返回success，超出容量限制时返回异常。

```
boolean offer(E e);
```
前面跟add()一样，就是与add相比，在容量受限时应该使用这个。

```
E remove();
```
检索并删除此队列的首元素，队列为空则抛出异常。

```
E poll();
```
检索并删除此队列的首元素，队列为空则抛出null。

```
E element();
```
检索但并不删除此队列的首元素，队列为空则抛出异常。

```
E peek();
```
检索但并不删除此队列的首元素，队列为空则抛出null。

## PriorityQueue
PriorityQueue继承于Queue，相比于一般的队列，它的出队的时候可以按照优先级进行出队，PriorityQueue可以根据给定的优先级顺序进行出队。

- 主要属性：
```
private static final int DEFAULT_CAPACITY = 11;
```
默认的容量。

```
E[] storage;
```
元素存储的地方。

```
int used;
```
数组中的实际元素数量。

```
Comparator<? super E> comparator;
```
比较器。

```
void clear()
```
清空队列

```
Comparator<? super E> comparator()
```
比较器

```
Iterator<E> iterator()
```
迭代器

```
boolean offer(E o)
```
添加节点

```
E peek()
```
获取优先级队列头结点

```
E poll()
```
移除并获取优先级队列头节点

```
 boolean remove(Object o)
```
移除指定元素

队列中元素个数
```
int size()
```

```
 boolean addAll(Collection<? extends E> c)
```
添加所有元素

```
 330:   void resize()
 331:   {
 332:     E[] new_data = (E[]) new Object[2 * storage.length];
 333:     System.arraycopy(storage, 0, new_data, 0, storage.length);
 334:     storage = new_data;
 335:   }
 336: }
```
扩容

```
 304:   void bubbleUp(int index)
 305:   {
 306:     // The element at INDEX was inserted into a blank spot.  Now move
 307:     // it up the tree to its natural resting place.
 308:     while (index > 0)
 309:       {
 310:         // This works regardless of whether we're at 2N+1 or 2N+2.
 311:         int parent = (index - 1) / 2;
 312:         if (Collections.compare(storage[parent], storage[index], comparator)
 313:             <= 0)
 314:           {
 315:             // Parent is the same or smaller than this element, so the
 316:             // invariant is preserved.  Note that if the new element
 317:             // is smaller than the parent, then it is necessarily
 318:             // smaller than the parent's other child.
 319:             break;
 320:           }
 321:
 322:         E temp = storage[index];
 323:         storage[index] = storage[parent];
 324:         storage[parent] = temp;
 325:
 326:         index = parent;
 327:       }
 328:   }
```
冒泡排序的函数

